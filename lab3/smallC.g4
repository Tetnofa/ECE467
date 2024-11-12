//
//  smallC.g4
//  ECE467 Lab 3
//
//  Created by Tarek Abdelrahman on 2023-09-13.
//  Based on code written by Ao (Dino) Li for ECE467.
//  Copyright © 2023 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

grammar smallC;

@header {
#include "ASTNodes.h"
#include <iostream>
#include <string>
}

program
returns [smallc::ProgramNode *prg]
@init {
    $prg = new smallc::ProgramNode();
    $prg->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
: (preamble {$prg->setIo(true);}
| ) (decls
{
   for(unsigned int i = 0; i < $decls.declarations.size();i++)
   {
    $prg->addChild($decls.declarations[i]);
    $decls.declarations[i]->setParent($prg);
   }
}
)* EOF ;

preamble:  '#include' '"scio.h"';

decls
returns [std::vector<smallc::DeclNode*> declarations]
@init {
    $declarations = std::vector<smallc::DeclNode*>();
}
    : scalarDeclList
      { 
        for(unsigned int i = 0; i < $scalarDeclList.scalars.size(); i++) {
            $declarations.push_back($scalarDeclList.scalars[i]);
        }
       }
    | arrDeclList
      { 
        for(unsigned int i = 0; i < $arrDeclList.arrays.size(); i++) {
            $declarations.push_back($arrDeclList.arrays[i]);
        }
       }
    | fcnProtoList
      { 
        for(unsigned int i = 0; i < $fcnProtoList.prototypes.size(); i++) {
            $declarations.push_back($fcnProtoList.prototypes[i]);
        }
       }
    | fcnDeclList
      { 
        for(unsigned int i = 0; i < $fcnDeclList.declarations.size(); i++) {
            $declarations.push_back($fcnDeclList.declarations[i]);
        }
       }
;

scalarDeclList
returns [std::vector<smallc::ScalarDeclNode*> scalars]
    : scalarDecl
      { $scalars.push_back($scalarDecl.decl); }
    | scalarDecl scalarDeclList
      {
          $scalars.push_back($scalarDecl.decl);
          for (unsigned int i = 0; i < $scalarDeclList.scalars.size(); i++) {
              $scalars.push_back($scalarDeclList.scalars[i]);
          }
      }
;

scalarDecl
returns [smallc::ScalarDeclNode* decl]
    : t=varType v=varName ';'
    {   
        $decl = new smallc::ScalarDeclNode($t.type, $v.node);
        $decl->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

arrDeclList
returns [std::vector<smallc::ArrayDeclNode*> arrays]
    : arrDecl
      { $arrays.push_back($arrDecl.decl); }
    | arrDecl arrDeclList
      {
          $arrays.push_back($arrDecl.decl);
          for (unsigned int i = 0; i < $arrDeclList.arrays.size(); i++) {
              $arrays.push_back($arrDeclList.arrays[i]);
          }
      }
;

arrDecl
returns [smallc::ArrayDeclNode* decl]
@init {
    $decl = nullptr;
}
    : t=varType n=arrName '[' size=intConst ']' ';'
    {
        smallc::ArrayTypeNode* type = new smallc::ArrayTypeNode($t.type, $size.node->getVal());
        $decl = new smallc::ArrayDeclNode(type, $n.node);
        $decl->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;


fcnProtoList
returns [std::vector<smallc::FunctionDeclNode*> prototypes]
    : fcnProto { $prototypes.push_back($fcnProto.proto); }
    | fcnProto fcnProtoList
      {
          $prototypes.push_back($fcnProto.proto);
          for (unsigned int i = 0; i < $fcnProtoList.prototypes.size(); i++) {
              $prototypes.push_back($fcnProtoList.prototypes[i]);
          }
      }
;

fcnProto
returns [smallc::FunctionDeclNode* proto]
@init {
    $proto = new smallc::FunctionDeclNode();
    $proto->setProto(true);
    $proto->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
    : t=retType n=fcnName '(' p=params ')' ';'
    {
        $proto->setRetType($t.type);
        $proto->setName($n.node);
        for(auto param : $p.parameters) {
            $proto->addParameter(param);
        }
    }
;


fcnDeclList
returns [std::vector<smallc::FunctionDeclNode*> declarations]
    : fcnDecl { $declarations.push_back($fcnDecl.declaration); }
    | fcnDecl fcnDeclList
      {
          $declarations.push_back($fcnDecl.declaration);
          for (unsigned int i = 0; i < $fcnDeclList.declarations.size(); i++) {
              $declarations.push_back($fcnDeclList.declarations[i]);
          }
      }
;

fcnDecl
returns [smallc::FunctionDeclNode* declaration]
@init {
    $declaration = new smallc::FunctionDeclNode();
    $declaration->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
    : t=retType n=fcnName '(' p=params ')' s=scope
    {
        $declaration->setRetType($t.type);
        $declaration->setName($n.node);
        for(auto param : $p.parameters) {
            $declaration->addParameter(param);
        }
        $declaration->setBody($s.scope_);
    }
;

varType
returns [smallc::PrimitiveTypeNode* type]
    : 'bool'{
        $type = new smallc::PrimitiveTypeNode(smallc::TypeNode::Bool);
        $type->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | 'int'{
        $type = new smallc::PrimitiveTypeNode(smallc::TypeNode::Int);
        $type->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;


retType
returns [smallc::PrimitiveTypeNode* type]
    : 'void'{
        $type = new smallc::PrimitiveTypeNode(smallc::TypeNode::Void);
        $type->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | varType{
        $type = $varType.type;
    }
;

constant
returns [smallc::ConstantExprNode* node]
@init {
    $node = nullptr;
    // $node->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine()); // This is Unnecessary since defined before
}
    : boolConst { 
        $node = $boolConst.node;
    }
    | intConst { 
        $node = $intConst.node;
    }
;

boolConst
returns [smallc::BoolConstantNode* node]

    : b=BOOL {
        $node = new smallc::BoolConstantNode($b.text);
        $node->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

scope
returns[smallc::ScopeNode* scope_]
@init{
    $scope_ = new smallc::ScopeNode();
    $scope_->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
:
    '{' (scalarDecl
    {$scope_->addDeclaration($scalarDecl.decl);}
    |arrDecl
    {$scope_->addDeclaration($arrDecl.decl);}
    )* (stmt
    {$scope_->addChild($stmt.statement);}
    )* '}'
;

stmt
returns [smallc::StmtNode* statement]
    : expr ';'
    {
        $statement = new smallc::ExprStmtNode($expr.node);
        $statement->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | assignStmt
    {
        $statement = $assignStmt.assignment;
    }
    | ifStmt
    {
        $statement = $ifStmt.ifNode;
    }
    | whileStmt
    {
        $statement = $whileStmt.whileNode;
    }
    | retStmt
    {
        $statement = $retStmt.returnNode;
    }
    | scope
    {
        $statement = $scope.scope_;
    }
;

assignStmt 
returns [smallc::AssignStmtNode* assignment]
@init {
    $assignment = new smallc::AssignStmtNode();
    $assignment->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
    : var '=' expr ';'
    {
        $assignment->setTarget($var.node);
        $assignment->setValue($expr.node);
    }
;
//use constructor cuz fred found the .h file is cursed
ifStmt 
returns [smallc::IfStmtNode* ifNode]
    : 'if' '(' cond=expr ')' then=stmt
    {
        $ifNode = new smallc::IfStmtNode($cond.node, $then.statement);
        $ifNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | 'if' '(' cond=expr ')' then=stmt 'else' else_=stmt
    {
        $ifNode = new smallc::IfStmtNode($cond.node, $then.statement, $else_.statement);
        $ifNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $ifNode->setHasElse(true);
    }
;

whileStmt 
returns [smallc::WhileStmtNode* whileNode]
@init {
    $whileNode = new smallc::WhileStmtNode();
    $whileNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
    : 'while' '(' cond=expr ')' body=stmt
    {
        $whileNode->setCondition($cond.node);
        $whileNode->setBody($body.statement);
    }
;

retStmt 
returns [smallc::ReturnStmtNode* returnNode]
@init {
    $returnNode = new smallc::ReturnStmtNode();
    $returnNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
    : 'return' val=expr ';'
    {
        $returnNode->setReturn($val.node);
    }
    | 'return' ';'
    {
        // Empty return - the constructor already creates a void return
    }
;

expr
returns [smallc::ExprNode* node]
    : intExpr 
    { 
        $node = $intExpr.exprNode; 
    }
    | '(' e=expr ')'
    { 
        $node = $e.node;
    }
    | n=fcnName '(' args ')'
    {
        smallc::CallExprNode* call = new smallc::CallExprNode($n.node);
        for(auto arg : $args.arguments) {
            call->addArgument(arg);
        }
        call->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $node = call;
    }
    | op=('!' | '-') e=expr
    {
        smallc::UnaryExprNode* unary = new smallc::UnaryExprNode($e.node);
        unary->setOpcode($op.text);
        unary->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $node = unary;
    }
    | l=expr op=('<' | '<=' | '>' | '>=') r=expr
    {
        smallc::BinaryExprNode* binary = new smallc::BinaryExprNode($l.node, $r.node);
        binary->setOpcode($op.text);
        binary->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        smallc::BoolExprNode* boolExpr = new smallc::BoolExprNode(binary);
        boolExpr->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $node = boolExpr;   
    }
    | l=expr op=('==' | '!=') r=expr
    {
        smallc::BinaryExprNode* binary = new smallc::BinaryExprNode($l.node, $r.node);
        binary->setOpcode($op.text);
        binary->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        smallc::BoolExprNode* boolExpr = new smallc::BoolExprNode(binary);
        $node = boolExpr;
    }
    | l=expr op='||' r=expr
    {
        smallc::BinaryExprNode* binary = new smallc::BinaryExprNode($l.node, $r.node);
        binary->setOpcode($op.text);
        binary->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        smallc::BoolExprNode* boolExpr = new smallc::BoolExprNode(binary);
        boolExpr->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $node = boolExpr;
    }
    | l=expr op='&&' r=expr
    {
        smallc::BinaryExprNode* binary = new smallc::BinaryExprNode($l.node, $r.node);
        binary->setOpcode($op.text);
        binary->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        smallc::BoolExprNode* boolExpr = new smallc::BoolExprNode(binary);
        boolExpr->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $node = boolExpr;
    }
;

intExpr
returns [smallc::IntExprNode* exprNode]
    : var 
    { 
        $exprNode = new smallc::IntExprNode($var.node);
        $exprNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | constant
    {
        $exprNode = new smallc::IntExprNode($constant.node);
        $exprNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | l=intExpr op=('*' | '/') r=intExpr
    {
        smallc::BinaryExprNode* binary = new smallc::BinaryExprNode($l.exprNode, $r.exprNode);
        binary->setOpcode($op.text);
        binary->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $exprNode = new smallc::IntExprNode();
        $exprNode->setValue(binary);
        $exprNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());

    }
    | l=intExpr op=('+' | '-') r=intExpr
    {
        smallc::BinaryExprNode* binary = new smallc::BinaryExprNode($l.exprNode, $r.exprNode);
        binary->setOpcode($op.text);
        binary->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $exprNode = new smallc::IntExprNode();
        $exprNode->setValue(binary);
        $exprNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | '(' e=intExpr ')'
    {
        $exprNode = $e.exprNode;
    }
;

var
returns [smallc::ReferenceExprNode* node]
    : v=varName 
    {
        $node = new smallc::ReferenceExprNode($v.node);
        $node->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | a=arrName '[' idx=intExpr ']'
    {
        $node = new smallc::ReferenceExprNode($a.node);
        $node->setIndex($idx.exprNode);
        $node->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

params
returns [std::vector<smallc::ParameterNode*> parameters]
@init {
    $parameters = std::vector<smallc::ParameterNode*>();
}
    : p=paramList 
    {
        $parameters = $p.parameterList;
    }
    | 
    {
        // Empty parameter list
    }
;

paramEntry
returns [smallc::ParameterNode* param]
@init {
    $param = new smallc::ParameterNode();
    $param->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
    : t=varType name=varName
    {
        $param = new smallc::ParameterNode($t.type, $name.node);
        $param->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | t=varType arrname=arrName '[]'
    {
        smallc::ArrayTypeNode* arrayType = new smallc::ArrayTypeNode($t.type);
        $param = new smallc::ParameterNode(arrayType, $arrname.node);
        $param->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

paramList
returns [std::vector<smallc::ParameterNode*> parameterList]
@init {
    $parameterList = std::vector<smallc::ParameterNode*>();
}
    : p=paramEntry
    {
        $parameterList.push_back($p.param);
    }
    | p=paramEntry ',' pl=paramList
    {
        $parameterList.push_back($p.param);
        $parameterList.insert($parameterList.end(), $pl.parameterList.begin(), $pl.parameterList.end());
    }
;

args
returns [std::vector<smallc::ArgumentNode*> arguments]
@init {
    $arguments = std::vector<smallc::ArgumentNode*>();
}
    : a=argList
    {
        $arguments = $a.argumentList;
    }
    |
    {
        // Empty argument list
    }
;

argEntry
returns [smallc::ArgumentNode* arg]
    : e=expr
    {
        $arg = new smallc::ArgumentNode($e.node);
        $arg->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

argList
returns [std::vector<smallc::ArgumentNode*> argumentList]
@init {
    $argumentList = std::vector<smallc::ArgumentNode*>();
}
    : a=argEntry
    {
        $argumentList.push_back($a.arg);
    }
    | a=argEntry ',' al=argList
    {
        $argumentList.push_back($a.arg);
        $argumentList.insert($argumentList.end(), $al.argumentList.begin(), $al.argumentList.end());
    }
;

varName
returns [smallc::IdentifierNode* node]
    : id=ID {
        $node = new smallc::IdentifierNode($id.text);
        $node->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

arrName
returns [smallc::IdentifierNode* node]
    : id=ID {
        $node = new smallc::IdentifierNode($id.text);
        $node->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

fcnName
returns [smallc::IdentifierNode* node]
    : id=ID {
        $node = new smallc::IdentifierNode($id.text);
        $node->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

intConst
returns [smallc::IntConstantNode* node]

    : i=INT 
    {
        $node = new smallc::IntConstantNode($i.text);
        $node->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | '-' i=INT 
    {
        $node = new smallc::IntConstantNode("-" + $i.text);
        $node->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

BOOL: 'true' | 'false';
ID: [a-zA-Z][a-zA-Z0-9_]* ;
INT:    [0] | ([1-9][0-9]*);
WS:     [ \t\r\n]+ -> skip;
COMMENT: '//' (~[\r\n])* -> skip;
