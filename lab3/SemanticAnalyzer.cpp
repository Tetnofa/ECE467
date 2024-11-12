//
//  SemanticAnalyzer.cpp
//  ECE467 Lab 3
//
//  Created by Tarek Abdelrahman on 2023-09-13.
//  Based on code written by Ao (Dino) Li for ECE467.
//  Copyright © 2023 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#include <iostream>
using namespace std;

#include "SemanticAnalyzer.h"
#include "SymTable.h"
using namespace smallc;

VariableEntry* findVariable(std::string name, ASTNode* node);
FunctionDeclNode* findFunction(ASTNode* node);

namespace smallc {

SemaError::SemaError (ErrorEnum code_, std::pair<unsigned int, unsigned int> location_) : code(code_), location(location_), msg() { }

SemaError::SemaError(ErrorEnum code_, std::pair<unsigned int, unsigned int> location_, std::string msg_) : code(code_), location(location_), msg(msg_) { }

// Constructor
SemanticAnalyzer::SemanticAnalyzer (): ASTVisitorBase(), prog(nullptr), errors() { }

// Print all the error messages at once
void
SemanticAnalyzer::printErrorMsgs () {
    for (const auto& e : errors) {
        std::cout << "sema: " << e.location.first
                  << ":" << e.location.second << " : ";
        switch (e.code) {
            case SemaError::IdentReDefined:
                std::cout << "redefinition of";
                break;
            case SemaError::IdentUnDefined:
                std::cout << "use of undefined identifier";
                break;
            case SemaError::NoMatchingDef:
                std::cout << "no matching definition for";
                break;
            case SemaError::MisMatchedReturn:
                std::cout << "mismatched return statement";
                break;
            case SemaError::InconsistentDef:
                std::cout << "definition inconsistent with earlier definition of";
                break;
            case SemaError::InvalidCond:
                std::cout << "invalid condition in";
                break;
            case SemaError::TypeMisMatch:
                std::cout << "type mismatch";
                break;
            case SemaError::InvalidArraySize:
                std::cout << "size cannot be negative for array";
                break;
            case SemaError::InvalidAccess:
                std::cout << "invalid use of identifier";
                break;
            default:
                std::cout << "unknown error number";
                break;
        }
        std::cout << " " << e.msg << std::endl;
    }
}

// Add an error to the list of errors
void
SemanticAnalyzer::addError (const SemaError& err) {
    errors.push_back(err);
}

void SemanticAnalyzer::visitASTNode(ASTNode* node) {
    return;
}

void SemanticAnalyzer::visitArgumentNode(ArgumentNode* node) {
    node->getExpr()->visit(this);
    IntExprNode* intExpr = dynamic_cast<IntExprNode*>(node->getExpr());
    if(intExpr){
        ReferenceExprNode* refExpr = dynamic_cast<ReferenceExprNode*>(intExpr->getValue());
        if(refExpr){
            VariableEntry* varEntry = findVariable(refExpr->getIdent()->getName(), node->getParent());
            if(varEntry){
                if(varEntry->getType()->isArray()){
                    node->setArray();
                }
            }
        }
    }
    return;
}

void SemanticAnalyzer::visitDeclNode(DeclNode* node) {
    return;
}

void SemanticAnalyzer::visitArrayDeclNode(ArrayDeclNode* node) {
    SymTable<VariableEntry>* varTable;

    if (node->getParent() == prog) {
        varTable = prog->getVarTable();
    } else {
        varTable = ((ScopeNode*)node->getParent())->getVarTable();
    }
    if(varTable->contains(node->getIdent()->getName())) {
        addError(SemaError(SemaError::IdentReDefined, node->getLocation(), node->getIdent()->getName()));
    }
    else {
        if(node->getType()->getSize() <= 0){
            addError(SemaError(SemaError::InvalidArraySize, node->getLocation(), node->getIdent()->getName()));
        }
        else{
            varTable->insert(node->getIdent()->getName(), VariableEntry(node->getType()));
        }
    }

    return;
}

void SemanticAnalyzer::visitFunctionDeclNode(FunctionDeclNode* node) {
    SymTable<FunctionEntry>* funcTable;
    funcTable = prog->getFuncTable();
    // If function already exists in table
    if (funcTable->contains(node->getIdent()->getName())) {
        FunctionEntry& existingFunc = funcTable->get(node->getIdent()->getName());
        // if we have a definition, throw error
        if (!existingFunc.proto) {
            addError(SemaError(SemaError::IdentReDefined, 
                    node->getLocation(), 
                    node->getIdent()->getName()));
        }
        
        // Check if prototype matches existing definition or vice versa
        else if (node->getRetType()->getTypeEnum() != existingFunc.getReturnType()->getTypeEnum() || 
            node->getParams().size() != existingFunc.getParameterTypes().size()) {
            addError(SemaError(SemaError::InconsistentDef,
                    node->getLocation(),
                    node->getIdent()->getName()));
        }
        else{
            // Check parameter types match
            for (size_t i = 0; i < node->getParams().size(); i++) {
                if (node->getParams()[i]->getType()->getTypeEnum() != existingFunc.getParameterTypes()[i]->getTypeEnum()) {
                    addError(SemaError(SemaError::InconsistentDef,
                            node->getLocation(),
                            node->getIdent()->getName()));
                }
            }
        }
        if (!node->getProto()) {
            existingFunc.proto = false;
        }
    } else {
        // New function - add to table
        std::vector<TypeNode*> paramTypes;
        for (auto param : node->getParams()) {
            paramTypes.push_back(param->getType());
        }
        
        FunctionEntry entry(node->getRetType(), paramTypes);
        entry.proto = node->getProto();
        funcTable->insert(node->getIdent()->getName(), entry);
    }

    node->getRetType()->visit(this);
    for (auto param : node->getParams()) {
        param->visit(this);
    }
    if (node->getBody()) {
        for (auto param : node->getParams()) {
            if(param->getType()->isArray()){    
                node->getBody()->getVarTable()->insert(param->getIdent()->getName(), VariableEntry(dynamic_cast<ArrayTypeNode*>(param->getType())));
            }
            else{
                node->getBody()->getVarTable()->insert(param->getIdent()->getName(), VariableEntry(dynamic_cast<PrimitiveTypeNode*>(param->getType())));
            }
        }
        node->getBody()->visit(this);
    }
    return;
}

void SemanticAnalyzer::visitScalarDeclNode(ScalarDeclNode* node) {
    SymTable<VariableEntry>* varTable;
    if (node->getParent() == prog) {
        varTable = prog->getVarTable();
    } else {
        varTable = ((ScopeNode*)node->getParent())->getVarTable();
    }
    if(varTable->contains(node->getIdent()->getName())) {
        addError(SemaError(SemaError::IdentReDefined, node->getLocation(), node->getIdent()->getName()));
    }
    else {
        varTable->insert(node->getIdent()->getName(), VariableEntry(node->getType()));
    }

    return;
}

void SemanticAnalyzer::visitExprNode(ExprNode* node) {
    node->visit(this);
    return;
}

void SemanticAnalyzer::visitBinaryExprNode(BinaryExprNode* node) {
    node->getLeft()->visit(this);
    node->getRight()->visit(this);

    if(node->getLeft()->getType()->getTypeEnum() == TypeNode::Void || node->getRight()->getType()->getTypeEnum() == TypeNode::Void){
        addError(SemaError(SemaError::TypeMisMatch, node->getLeft()->getLocation(), ""));
        node->setTypeVoid();
    }
    else if(node->getLeft()->getType()->getTypeEnum() != node->getRight()->getType()->getTypeEnum()){
        addError(SemaError(SemaError::TypeMisMatch, node->getLeft()->getLocation(), ""));
        node->setTypeVoid();
    }
    else if(node->getOpcode() == ExprNode::Subtraction || node->getOpcode() == ExprNode::Multiplication || node->getOpcode() == ExprNode::Division || node->getOpcode() == ExprNode::Addition){
        if(node->getLeft()->getType()->getTypeEnum() == TypeNode::Bool){
            addError(SemaError(SemaError::TypeMisMatch, node->getLocation(), ""));
            node->setTypeVoid();
        }
        else{
            node->setType(node->getLeft()->getType());
        }   
    }
    else if(node->getOpcode() == ExprNode::Equal || node->getOpcode() == ExprNode::NotEqual || node->getOpcode() == ExprNode::LessThan || node->getOpcode() == ExprNode::Greater || node->getOpcode() == ExprNode::GreaterorEqual || node->getOpcode() == ExprNode::LessorEqual){
        node->setTypeBool();
    }
    else{
        if(node->getLeft()->getType()->getTypeEnum() == TypeNode::Int){
            addError(SemaError(SemaError::TypeMisMatch, node->getLocation(), ""));
            node->setTypeVoid();
        }
        else{
            node->setType(node->getLeft()->getType());
        }
    }
    return;
}

void SemanticAnalyzer::visitBoolExprNode(BoolExprNode* node) {
    node->getValue()->visit(this);
    node->setType(node->getValue()->getType());
    return;
}

void SemanticAnalyzer::visitCallExprNode(CallExprNode* node) {
    for (auto arg : node->getArguments()) {
        if(arg){
            arg->visit(this);
        }
    }
    SymTable<FunctionEntry>* funcTable;
    funcTable = prog->getFuncTable();
    // If function already exists in table
    if (funcTable->contains(node->getIdent()->getName())) {
        FunctionEntry& existingFunc = funcTable->get(node->getIdent()->getName());
        std::vector<TypeNode*> returnTypes = existingFunc.getParameterTypes();
        node->setType(existingFunc.getReturnType());

        if (returnTypes.size() != node->getArguments().size()) {
            addError(SemaError(SemaError::NoMatchingDef,
                    node->getLocation(),
                    node->getIdent()->getName()));
            node->setTypeVoid();
        }
        else{
            for (size_t i = 0; i < node->getArguments().size(); i++) {
                if (returnTypes[i]->getTypeEnum() != node->getArgument(i)->getExpr()->getType()->getTypeEnum() || node->getArgument(i)->getExpr()->getType()->getTypeEnum() == TypeNode::Void) {
                    addError(SemaError(SemaError::NoMatchingDef,
                            node->getLocation(),
                            node->getIdent()->getName()));
                    node->setTypeVoid();
                }
                else if(returnTypes[i]->isArray() != node->getArgument(i)->isArray()){
                    addError(SemaError(SemaError::NoMatchingDef,
                            node->getLocation(),
                            node->getIdent()->getName()));
                    node->setTypeVoid();
                }
            }
        }
    } else {
        addError(SemaError(SemaError::IdentUnDefined, node->getLocation(), node->getIdent()->getName()));
        node->setTypeVoid();
    }
    return;
}

void SemanticAnalyzer::visitConstantExprNode(ConstantExprNode* node) {
    return;
}

void SemanticAnalyzer::visitBoolConstantNode(BoolConstantNode* node) {
    node->setTypeBool();
    return;
}

void SemanticAnalyzer::visitIntConstantNode(IntConstantNode* node) {
    node->setTypeInt();
    return;
}

void SemanticAnalyzer::visitIntExprNode(IntExprNode* node) {
    node->getValue()->visit(this);
    node->setType(node->getValue()->getType());
    return;
}

void SemanticAnalyzer::visitReferenceExprNode(ReferenceExprNode* node) {
    
    ASTNode* current = node->getParent();
    bool found = false;
    SymTable<VariableEntry>* table = nullptr;
    
    VariableEntry* varEntry = findVariable(node->getIdent()->getName(), node->getParent());
    if(varEntry && varEntry->getType()->isArray()){
        if(node->getIndex()){
            node->getIndex()->visit(this);
            if(node->getIndex()->getType()->getTypeEnum() != TypeNode::Int){
                addError(SemaError(SemaError::TypeMisMatch, node->getIndex()->getLocation(), ""));
                node->setTypeVoid();
            }
        }
    }
    else if(varEntry){
        if(node->getIndex()){
            node->getIndex()->visit(this);
            addError(SemaError(SemaError::InvalidAccess, node->getLocation(), node->getIdent()->getName()));
            if(node->getIndex()->getType()->getTypeEnum() != TypeNode::Int){
                addError(SemaError(SemaError::TypeMisMatch, node->getIndex()->getLocation(), ""));
            }
        }
        node->setTypeVoid();
    }
    if (varEntry == nullptr) {
        addError(SemaError(SemaError::IdentUnDefined, node->getLocation(), node->getIdent()->getName()));
        node->setTypeVoid();
        if(node->getIndex()){
            node->getIndex()->visit(this);
            if(node->getIndex()->getType()->getTypeEnum() != TypeNode::Int){
                addError(SemaError(SemaError::TypeMisMatch, node->getIndex()->getLocation(), ""));
                node->setTypeVoid();
            }
        }
    }
    else{
        PrimitiveTypeNode* type = new PrimitiveTypeNode(varEntry->getType()->getTypeEnum());
        node->setType(type);
    }
    return;
}

void SemanticAnalyzer::visitUnaryExprNode(UnaryExprNode* node) {
    node->getOperand()->visit(this);
    
    if(node->getOperand()->getType()->getTypeEnum() != TypeNode::Int && node->codeToStr(node->getOpcode()) == "-"){
        addError(SemaError(SemaError::TypeMisMatch, node->getOperand()->getLocation(), ""));
        node->setTypeVoid();
    }
    else if(node->getOperand()->getType()->getTypeEnum() == TypeNode::Int && node->codeToStr(node->getOpcode()) == "-"){
        node->setTypeInt();
    }
    else if(node->getOperand()->getType()->getTypeEnum() != TypeNode::Bool && node->codeToStr(node->getOpcode()) == "!"){
        addError(SemaError(SemaError::TypeMisMatch, node->getOperand()->getLocation(), ""));
        node->setTypeVoid();
    }
    else if(node->getOperand()->getType()->getTypeEnum() == TypeNode::Bool && node->codeToStr(node->getOpcode()) == "!"){
        node->setTypeBool();
    }
    else if(node->getOperand()->getType()->getTypeEnum() == TypeNode::Void){
        addError(SemaError(SemaError::TypeMisMatch, node->getLocation(), ""));
        node->setTypeVoid();
    }
    return;
}

void SemanticAnalyzer::visitIdentifierNode(IdentifierNode* node) {
    return;
}

void SemanticAnalyzer::visitParameterNode(ParameterNode* node) {
    return;
}

void SemanticAnalyzer::visitProgramNode(ProgramNode* node) {
    prog = node;

    SymTable<FunctionEntry>* functionTable = prog->getFuncTable();
    if (node->useIo()) {
        std::vector<TypeNode*> readBoolParams;
        FunctionEntry readBoolEntry(new PrimitiveTypeNode(TypeNode::Bool), readBoolParams);
        functionTable->insert("readBool", readBoolEntry);
        
        std::vector<TypeNode*> readIntParams;
        FunctionEntry readIntEntry(new PrimitiveTypeNode(TypeNode::Int), readIntParams);
        functionTable->insert("readInt", readIntEntry);
        
        std::vector<TypeNode*> writeBoolParams;
        writeBoolParams.push_back(new PrimitiveTypeNode(TypeNode::Bool));
        FunctionEntry writeBoolEntry(new PrimitiveTypeNode(TypeNode::Void), writeBoolParams);
        functionTable->insert("writeBool", writeBoolEntry);
        
        std::vector<TypeNode*> writeIntParams;
        writeIntParams.push_back(new PrimitiveTypeNode(TypeNode::Int));
        FunctionEntry writeIntEntry(new PrimitiveTypeNode(TypeNode::Void), writeIntParams);
        functionTable->insert("writeInt", writeIntEntry);
        
        std::vector<TypeNode*> newLineParams;
        FunctionEntry newLineEntry(new PrimitiveTypeNode(TypeNode::Void), newLineParams);
        functionTable->insert("newLine", newLineEntry);
    }
    for (size_t i = 0; i < node->getNumChildren(); i++) {
        node->getChild(i)->visit(this);
    }
    return;
}

void SemanticAnalyzer::visitStmtNode(StmtNode* node) {
    return;
}

void SemanticAnalyzer::visitAssignStmtNode(AssignStmtNode* node) {
    node->getTarget()->visit(this);
    node->getValue()->visit(this);
    if(node->getTarget()->getType()->getTypeEnum() != node->getValue()->getType()->getTypeEnum() || node->getTarget()->getType()->getTypeEnum() == TypeNode::Void){
        addError(SemaError(SemaError::TypeMisMatch, node->getLocation(), ""));
    }
    return;
}

void SemanticAnalyzer::visitExprStmtNode(ExprStmtNode* node) {
    node->getExpr()->visit(this);
    return;
}

void SemanticAnalyzer::visitIfStmtNode(IfStmtNode* node) {
    node->getCondition()->visit(this);
    node->getThen()->visit(this);
    if (node->getHasElse()) {
        node->getElse()->visit(this);
    }
    if(node->getCondition()->getType()->getTypeEnum() != TypeNode::Bool){
        addError(SemaError(SemaError::InvalidCond, node->getLocation(), "if statement"));
    }
    return;
}

void SemanticAnalyzer::visitReturnStmtNode(ReturnStmtNode* node) {
    ExprNode* returnExpr = node->getReturn();
    FunctionDeclNode* funcDecl = findFunction(node->getParent());
    if (returnExpr) {
        returnExpr->visit(this);
        if (funcDecl) {
            if (funcDecl->getRetType()->getTypeEnum() != returnExpr->getType()->getTypeEnum()) {
                addError(SemaError(SemaError::MisMatchedReturn, node->getLocation(), ""));
            }
        }
    }
    else{
        if (funcDecl) {
            if (funcDecl->getRetType()->getTypeEnum() != TypeNode::Void) {
                addError(SemaError(SemaError::MisMatchedReturn, node->getLocation(), ""));
            }
        }
    }
    return;
}

void SemanticAnalyzer::visitScopeNode(ScopeNode* node) {
    for (auto decl : node->getDeclarations()) {
        decl->visit(this);
    }
    for (unsigned int i = 0; i < node->getNumChildren(); ++i){
        auto child = node->getChild(i);
        child->visit(this);
    }
    return;
}

void SemanticAnalyzer::visitWhileStmtNode(WhileStmtNode* node) {
    node->getCondition()->visit(this);
    node->getBody()->visit(this);
    if(node->getCondition()->getType()->getTypeEnum() != TypeNode::Bool){
        addError(SemaError(SemaError::InvalidCond, node->getLocation(), "while statement"));
    }
    return;
}

void SemanticAnalyzer::visitTypeNode(TypeNode* node) {
    return;
}

void SemanticAnalyzer::visitPrimitiveTypeNode(PrimitiveTypeNode* node) {
    return;
}

void SemanticAnalyzer::visitArrayTypeNode(ArrayTypeNode* node) {
    return;
}
} // namespace smallc


VariableEntry* findVariable(std::string name, ASTNode* node){
    ASTNode* current = node;
    SymTable<VariableEntry>* table = nullptr;
    while (current != nullptr) {
        if(!current->hasVarTable()){
            current = current->getParent();
            continue;
        }
        ScopeNode* scopeNode = dynamic_cast<ScopeNode*>(current);
        if (scopeNode) {
            table = scopeNode->getVarTable();
            if (table && table->contains(name)) {
                return &table->get(name);
            }
        }
        ProgramNode* progNode = dynamic_cast<ProgramNode*>(current);
        if (progNode) {
            table = progNode->getVarTable();
            if (table && table->contains(name)) {
                return &table->get(name);
            }
        }
        current = current->getParent();
    }
    return nullptr;
}

FunctionDeclNode* findFunction(ASTNode* node){
    ASTNode* current = node;
    while (current != nullptr) {
        FunctionDeclNode* temp = dynamic_cast<FunctionDeclNode*>(current);
        if(temp){
            return temp;
        }
        current = current->getParent();
    }
    return nullptr;
}