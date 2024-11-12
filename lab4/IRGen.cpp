//
//  IRGen.cpp
//  ECE467 Lab 4
//
//  Created by Tarek Abdelrahman on 2023-10-13.
//  Based on code written by Ao (Dino) Li for ECE467.
//  Copyright © 2023 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#include <iostream>
using namespace std;

#include "IRGen.h"
#include "SymTable.h"
#include "ASTVisitorBase.h"
using namespace smallc;
using namespace llvm;

namespace smallc {

IRGen::IRGen(const std::string moduleName) : ASTVisitorBase(),
                                             prog(nullptr),
                                             TheModule(),
                                             Builder(),
                                             ModuleName(moduleName),
                                             CurValue(nullptr) {
    TheContext = std::make_unique<llvm::LLVMContext>();
}

unique_ptr<Module> 
IRGen::getModule() {
    Builder.reset();
    return std::move(TheModule);
}

llvm::Type*
IRGen::convertType(TypeNode* type){
    llvm::Type* base;
    switch(type->getTypeEnum()){
        case TypeNode::TypeEnum::Void:
            base = llvm::Type::getVoidTy(*TheContext);
            break;
        case TypeNode::TypeEnum::Int:
            base = llvm::Type::getInt32Ty(*TheContext);
            break;
        case TypeNode::TypeEnum::Bool:
            base = llvm::Type::getInt1Ty(*TheContext);
            break;
    }
    if(type->isArray()){
        ArrayTypeNode* arrType = (ArrayTypeNode*) type;
        return llvm::ArrayType::get(base, arrType->getSize());
    }
    return base;
}

SymTable<VariableEntry>*
IRGen::findTable(IdentifierNode* id){
    ASTNode* parent = id->getParent();
    bool found = false;
    SymTable<VariableEntry>* res = nullptr;
    while (parent && !found){
        if (parent->hasVarTable()){
            if (parent->getParent()){
                ScopeNode* scope = (ScopeNode*)parent;
                res = scope->getVarTable();
            }
            else {
                res = id->getRoot()->getVarTable();
            }
            if (res && res->contains(id->getName()))
                found = true;
        }
        parent = parent->getParent();
    }
    return res;
}

// ECE467 STUDENT: complete the implementation of the visitor functions

void
IRGen::visitASTNode (ASTNode* node) {
    return;
}

void 
IRGen::visitArgumentNode (ArgumentNode* arg) {
    // Visit the contained expression
    arg->getExpr()->visit(this);
    return;
}

void 
IRGen::visitDeclNode (DeclNode* decl) {
    // Visit the contained expression
    return;
}

void
IRGen::visitArrayDeclNode (ArrayDeclNode* array) {
    if (array->getParent() == prog) {
        
        // Create array type
        ArrayType* arrayType = ArrayType::get(Type::getInt32Ty(*TheContext), array->getType()->getSize());
        
        // Create global array with zeroinitializer
        GlobalVariable* global_array = new GlobalVariable(
            *TheModule,
            arrayType,
            false,  // is constant
            GlobalValue::CommonLinkage,
            ConstantAggregateZero::get(arrayType),
            array->getIdent()->getName()
        );
        
        // Store in var table
        prog->getVarTable()->setLLVMValue(array->getIdent()->getName(), global_array);
    } else {
        // Local array
        Type* arrayType = convertType(array->getType());
        Value* allocaInst = Builder->CreateAlloca(
            arrayType,
            nullptr,
            array->getIdent()->getName()
        );

        // Store in current scope's symbol table
        ScopeNode* scope = dynamic_cast<ScopeNode*>(array->getParent());
        assert(scope != nullptr);
        scope->getVarTable()->setLLVMValue(array->getIdent()->getName(), allocaInst);
    }
}

void
IRGen::visitFunctionDeclNode (FunctionDeclNode* func) {
    // Get function return type
    Type* returnType = convertType(func->getType());
    
    // Create vector of parameter types
    std::vector<Type*> paramTypes;
    for (auto param : func->getParams()) {
        paramTypes.push_back(convertType(param->getType()));
    }
    
    // Create function type
    FunctionType* funcType = FunctionType::get(returnType, paramTypes, false);
    
    // Check if function already exists in module
    Function* function = TheModule->getFunction(func->getIdent()->getName());
    if (!function) {
        // Only create if it doesn't exist
        function = Function::Create(
            funcType,
            Function::ExternalLinkage,
            func->getIdent()->getName(),
            *TheModule
        );
    }
    
    // If there's no body, this is just a prototype declaration
    if (!func->getBody()) {
        return;
    }
    
    // Create entry block
    BasicBlock* entryBlock = BasicBlock::Create(*TheContext, "entry", function);
    Builder->SetInsertPoint(entryBlock);
    
    // Set up parameters
    auto paramNodes = func->getParams();
    const auto &paramValues = function->args();  // Added 'const'
    
    for (size_t i = 0; i < paramNodes.size(); i++) {
        auto param = paramNodes[i];
        auto &paramValue = *(std::next(paramValues.begin(), i));
        

        if (param->getType()->getTypeEnum() == TypeNode::TypeEnum::Bool) {
            function->addParamAttr(i, Attribute::ZExt);
        }

        // Name the parameter
        paramValue.setName(param->getIdent()->getName());
        
        // Create alloca for this parameter
        AllocaInst* alloca = Builder->CreateAlloca(
            convertType(param->getType()),
            nullptr,
            param->getIdent()->getName()
        );
        
        // Store parameter value in alloca
        Builder->CreateStore(&paramValue, alloca);
        
        // Add to symbol table
        func->getBody()->getVarTable()->setLLVMValue(param->getIdent()->getName(), alloca);
    }
    
    // Visit function body
    func->getBody()->visit(this);
    
    // Add return void if needed
    BasicBlock* currentBB = Builder->GetInsertBlock();
    if (currentBB->getTerminator() == nullptr) {
        if (func->getType()->getTypeEnum() == TypeNode::TypeEnum::Void) {
            Builder->CreateRetVoid();
        } else {
            // For non-void functions, this would be an error
            cerr << "Error: Non-void function missing return statement" << std::endl;
        }
    }
}

void
IRGen::visitScalarDeclNode (ScalarDeclNode* scalar) {
    if (scalar->getParent() == prog) {
        // Global variable
        Type* varType = convertType(scalar->getType());
        Constant* initVal = nullptr;
        
        // Create global variable with default initialization
        GlobalVariable* global_var = new GlobalVariable(
            *TheModule,
            varType,
            false,  // is constant
            GlobalValue::CommonLinkage,
            Constant::getNullValue(varType),
            scalar->getIdent()->getName()
        );

        // Store in global symbol table
        prog->getVarTable()->setLLVMValue(scalar->getIdent()->getName(), global_var);
    } else {
        // Local variable
        Type* varType = convertType(scalar->getType());
        Value* allocaInst = Builder->CreateAlloca(
            varType, 
            nullptr, 
            scalar->getIdent()->getName()
        );

        // Store in current scope's symbol table
        ScopeNode* scope = dynamic_cast<ScopeNode*>(scalar->getParent());
        assert(scope != nullptr);
        scope->getVarTable()->setLLVMValue(scalar->getIdent()->getName(), allocaInst);
    }
}

void 
IRGen::visitExprNode (ExprNode* exp) {
    // Visit the contained expression
    CurValue = exp->getLLVMValue();
    return;
}

void 
IRGen::visitBinaryExprNode(BinaryExprNode* bin) {
    // Visit left and right operands
    bin->getLeft()->visit(this);
    Value* L = bin->getLeft()->getLLVMValue();
    bin->getRight()->visit(this);
    Value* R = bin->getRight()->getLLVMValue();
    
    Value* result = nullptr;
    switch(bin->getOpcode()) {
        // Arithmetic
        case BinaryExprNode::Opcode::Addition:
            result = Builder->CreateAdd(L, R, "");
            break;
        case BinaryExprNode::Opcode::Subtraction:
            result = Builder->CreateSub(L, R, "");
            break;
        case BinaryExprNode::Opcode::Multiplication:
            result = Builder->CreateMul(L, R, "");
            break;
        case BinaryExprNode::Opcode::Division:
            result = Builder->CreateSDiv(L, R, "");
            break;
        // Comparison
        case BinaryExprNode::Opcode::LessThan:
            // std::cout << "Debug: Less than " << L->getName().str() << " " << R->getName().str() << std::endl;
            result = Builder->CreateICmpSLT(L, R, "");
            break;
        case BinaryExprNode::Opcode::Greater:
            // std::cout << "Debug: Greater than " << L->getName().str() << " " << R->getName().str() << std::endl;
            result = Builder->CreateICmpSGT(L, R, "");
            break;
        case BinaryExprNode::Opcode::LessorEqual:
            // std::cout << "Debug: Less or equal " << L->getName().str() << " " << R->getName().str() << std::endl;
            result = Builder->CreateICmpSLE(L, R, "");
            break;
        case BinaryExprNode::Opcode::GreaterorEqual:
            // std::cout << "Debug: Greater or equal " << L->getName().str() << " " << R->getName().str() << std::endl;
            result = Builder->CreateICmpSGE(L, R, "");
            break;
        case BinaryExprNode::Opcode::Equal:
            // std::cout << "Debug: Equal " << L->getName().str() << " " << R->getName().str() << std::endl;
            result = Builder->CreateICmpEQ(L, R, "");
            break;
        case BinaryExprNode::Opcode::NotEqual:
            // std::cout << "Debug: Not equal " << L->getName().str() << " " << R->getName().str() << std::endl;
            result = Builder->CreateICmpNE(L, R, "");
            break;
        // Logical
        case BinaryExprNode::Opcode::And:
            result = Builder->CreateAnd(L, R, "");
            break;
        case BinaryExprNode::Opcode::Or:
            result = Builder->CreateOr(L, R, "");
            break;
    }
    bin->setLLVMValue(result);
    CurValue = result;
}

void 
IRGen::visitBoolExprNode (BoolExprNode* boolExpr) {
    // Visit the contained expression
    boolExpr->getValue()->visit(this);
    
    // Convert the value to a boolean (i1) if it isn't already
    llvm::Value* val = boolExpr->getValue()->getLLVMValue();
    if (val->getType() != Builder->getInt1Ty()) {
        // std::cout << "Debug: Converting to boolean " << val->getName().str() << std::endl;
        val = Builder->CreateICmpNE(val, llvm::ConstantInt::get(val->getType(), 0), "");
    }
    
    boolExpr->setLLVMValue(val);
    CurValue = boolExpr->getLLVMValue();
}

void
IRGen::visitCallExprNode (CallExprNode* call) {
    // Get function from module
    Function* callee = TheModule->getFunction(call->getIdent()->getName());
    
    // Prepare arguments vector
    std::vector<Value*> args;
    for (auto arg : call->getArguments()) {
        arg->visit(this);
        args.push_back(CurValue);
    }
    
    Value* result = Builder->CreateCall(callee, args, "");
    call->setLLVMValue(result);
    CurValue = result;
}

void 
IRGen::visitConstantExprNode(ConstantExprNode* constant) {
    return;
}

void 
IRGen::visitBoolConstantNode(BoolConstantNode* boolConst) {
    Value* val = ConstantInt::get(Type::getInt1Ty(*TheContext), boolConst->getVal());
    boolConst->setLLVMValue(val);
    CurValue = val;
}

void 
IRGen::visitIntConstantNode(IntConstantNode* intConst) {
    Value* val = ConstantInt::get(Type::getInt32Ty(*TheContext), intConst->getVal());
    intConst->setLLVMValue(val);
    CurValue = val;
}

void
IRGen::visitIntExprNode(IntExprNode* intExpr) {
    intExpr->getValue()->visit(this);
    intExpr->setLLVMValue(CurValue);
}

void
IRGen::visitReferenceExprNode(ReferenceExprNode* ref) {
    // Get the LLVM value (alloca) for this variable from symbol table
    Value* val = findTable(ref->getIdent())->get(ref->getIdent()->getName()).getValue();
    
    Value* result = nullptr;
    if (ref->getIndex()) {
        ref->getIndex()->visit(this);
        Value* idx = ref->getIndex()->getLLVMValue();
        int array_size = static_cast<ArrayTypeNode*>(findTable(ref->getIdent())->get(ref->getIdent()->getName()).getType())->getSize();
        
        if (!idx) {
            cerr << "Error: Array index is null" << std::endl;
            return;
        }
        ArrayType* arrayTy = ArrayType::get(Type::getInt32Ty(*TheContext), array_size);  // Need array size though
        std::vector<Value*> indices = {
            ConstantInt::get(Type::getInt32Ty(*TheContext), 0),
            idx
        };
        Value* gepInst = Builder->CreateGEP(arrayTy, val, indices, "");
        result = Builder->CreateLoad(Type::getInt32Ty(*TheContext), gepInst, "");
    } else {
        if (ref->getType()->getTypeEnum() == TypeNode::TypeEnum::Bool) {    
            result = Builder->CreateLoad(Type::getInt1Ty(*TheContext), val, "");
        } else {
            result = Builder->CreateLoad(Type::getInt32Ty(*TheContext), val, "");
        }
    }
    ref->setLLVMValue(result);
    CurValue = result;
}

void 
IRGen::visitUnaryExprNode(UnaryExprNode* unary) {
    unary->getOperand()->visit(this);
    Value* operand = unary->getOperand()->getLLVMValue();
    
    Value* result = nullptr;
    switch(unary->getOpcode()) {
        case UnaryExprNode::Opcode::Minus:
            result = Builder->CreateNeg(operand, "");
            break;
        case UnaryExprNode::Opcode::Not:
            result = Builder->CreateNot(operand, "");
            break;
    }
    unary->setLLVMValue(result);
    CurValue = result;
}

void 
IRGen::visitIdentifierNode(IdentifierNode* id) {
    return;
}

void
IRGen::visitParameterNode(ParameterNode* param) {
    return;
}

void
IRGen::visitProgramNode(ProgramNode* prg) {
    // Store program node for later use
    prog = prg;
    
    // Initialize the module with the given name (which will be filename.bc)
    TheModule = std::make_unique<Module>(ModuleName, *TheContext);
    
    // Initialize the IR builder
    Builder = std::make_unique<IRBuilder<>>(*TheContext);

    if(prg->useIo()){
        // void newLine()
        FunctionType *newLineTy = FunctionType::get(Type::getVoidTy(*TheContext), false);
        Function::Create(newLineTy, Function::ExternalLinkage, "newLine", TheModule.get());

        // bool readBool()
        FunctionType *readBoolTy = FunctionType::get(Type::getInt1Ty(*TheContext), false);
        Function::Create(readBoolTy, Function::ExternalLinkage, "readBool", TheModule.get());

        // int readInt()
        FunctionType *readIntTy = FunctionType::get(Type::getInt32Ty(*TheContext), false);
        Function::Create(readIntTy, Function::ExternalLinkage, "readInt", TheModule.get());

        // void writeBool(bool)
        std::vector<Type*> writeBoolParams = {Type::getInt1Ty(*TheContext)};
        FunctionType *writeBoolTy = FunctionType::get(Type::getVoidTy(*TheContext), writeBoolParams, false);
        Function *writeBoolFunc = Function::Create(writeBoolTy, Function::ExternalLinkage, "writeBool", TheModule.get());
        writeBoolFunc->addParamAttr(0, Attribute::ZExt);

        // void writeInt(int)
        std::vector<Type*> writeIntParams = {Type::getInt32Ty(*TheContext)};
        FunctionType *writeIntTy = FunctionType::get(Type::getVoidTy(*TheContext), writeIntParams, false);
        Function::Create(writeIntTy, Function::ExternalLinkage, "writeInt", TheModule.get());
    }

    // Process all global declarations and functions
    for (int child = 0; child < prog->getNumChildren(); child ++) {
        prog->getChild(child)->visit(this);
    }
}

void 
IRGen::visitStmtNode(StmtNode* stmt) {
    return;
}

void 
IRGen::visitAssignStmtNode(AssignStmtNode* assign) {
    
    // Get target variable's alloca from symbol table
    Value* target = findTable(assign->getTarget()->getIdent())->get(assign->getTarget()->getIdent()->getName()).getValue();

    // Generate value to be assigned
    assign->getValue()->visit(this);
    Value* value = assign->getValue()->getLLVMValue();
    
    // cout << "Debug: Value: " << value->getName().str() << endl;

    if (!target || !value) {
        cerr << "Error: Null operand in assignment. Target: " 
             << (target ? "not null" : "NULL") 
             << ", Value: " << (value ? "not null" : "NULL") << std::endl;
        return;
    }
    
    if (assign->getTarget()->getIndex()) {
        assign->getTarget()->getIndex()->visit(this);
        Value* idx = assign->getTarget()->getIndex()->getLLVMValue();
        int array_size = static_cast<ArrayTypeNode*>(findTable(assign->getTarget()->getIdent())->get(assign->getTarget()->getIdent()->getName()).getType())->getSize();
        // cout << "Debug: is Array Size: " << array_size << endl;
        
        if (!idx) {
            cerr << "Error: Array index is null" << std::endl;
            return;
        }
        ArrayType* arrayTy = ArrayType::get(Type::getInt32Ty(*TheContext), array_size);  // Need array size though
        std::vector<Value*> indices = {
            ConstantInt::get(Type::getInt32Ty(*TheContext), 0),
            idx
        };
        Value* gepInst = Builder->CreateGEP(arrayTy, target, indices, "");
        Builder->CreateStore(value, gepInst);
        
    } else {
        Builder->CreateStore(value, target);
    }
    
}

void 
IRGen::visitExprStmtNode(ExprStmtNode* expr) {
    // Visit the expression - result is discarded since this is a statement
    expr->getExpr()->visit(this);
}

void 
IRGen::visitIfStmtNode(IfStmtNode* ifStmt) {
    Function* function = Builder->GetInsertBlock()->getParent();
    
    // Create basic blocks - remove the separate condition block
    BasicBlock* thenBB = BasicBlock::Create(*TheContext, "then", function);
    BasicBlock* exitBB = BasicBlock::Create(*TheContext, "merge", function);
    BasicBlock* elseBB = nullptr;
    if(ifStmt->getHasElse()){
        elseBB = BasicBlock::Create(*TheContext, "else", function);
    }
    
    // Generate condition code in the current block
    ifStmt->getCondition()->visit(this);
    if(ifStmt->getHasElse()){
        Builder->CreateCondBr(CurValue, thenBB, elseBB);
    } else {
        Builder->CreateCondBr(CurValue, thenBB, exitBB);
    }
    
    // Then block
    Builder->SetInsertPoint(thenBB);
    ifStmt->getThen()->visit(this);
    Builder->CreateBr(exitBB);

    if (ifStmt->getHasElse()) {
        // Else block
        Builder->SetInsertPoint(elseBB);
        ifStmt->getElse()->visit(this);
        Builder->CreateBr(exitBB);
    }
    
    // Continue with exit block
    Builder->SetInsertPoint(exitBB);
}

void 
IRGen::visitReturnStmtNode(ReturnStmtNode* ret) {
    if (ret->getReturn()) {
        ret->getReturn()->visit(this);
        Builder->CreateRet(CurValue);
    } else {
        Builder->CreateRetVoid();
    }
}

void 
IRGen::visitScopeNode(ScopeNode* scope) {
    // Visit all statements in the scope
    for(auto decl : scope->getDeclarations()){
        decl->visit(this);
    }
    for (int i = 0; i < scope->getNumChildren(); i++) {
        scope->getChild(i)->visit(this);
    }
}

void 
IRGen::visitWhileStmtNode(WhileStmtNode* whileStmt) {
    // Get current function
    Function* function = Builder->GetInsertBlock()->getParent();
    
    // Create basic blocks
    BasicBlock* condBB = BasicBlock::Create(*TheContext, "while.cond", function);
    BasicBlock* bodyBB = BasicBlock::Create(*TheContext, "while.body", function);
    BasicBlock* exitBB = BasicBlock::Create(*TheContext, "while.exit", function);
    
    // Branch to condition block
    Builder->CreateBr(condBB);
    
    // Condition block
    Builder->SetInsertPoint(condBB);
    whileStmt->getCondition()->visit(this);
    Builder->CreateCondBr(CurValue, bodyBB, exitBB);
    
    // Body block
    Builder->SetInsertPoint(bodyBB);
    whileStmt->getBody()->visit(this);
    Builder->CreateBr(condBB);  // Loop back to condition
    
    // Continue with exit block
    Builder->SetInsertPoint(exitBB);
}

void 
IRGen::visitTypeNode(TypeNode* type) {
   return;
}

void 
IRGen::visitPrimitiveTypeNode(PrimitiveTypeNode* type) {
    return;
}

void 
IRGen::visitArrayTypeNode(ArrayTypeNode* type) {
    return;
}


} // namespace smallc
