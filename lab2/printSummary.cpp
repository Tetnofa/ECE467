//
//  printSummary.cpp
//  ECE467 Lab 2
//
//  Created by Tarek Abdelrahman on 2023-07-19.
//  Modified by Tarek Abdelrahman on 2023-07-19.
//  Copyright © 2023 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#include <iostream>
#include <string>
#include <map>

#include "antlr4-runtime.h"
#include "smallCLexer.h"
#include "smallCLexer.h"
#include "smallCParser.h"
#include "smallCBaseVisitor.h"
#include "printSummary.h"

using namespace antlrcpp;
using namespace antlr4;
using namespace std;

// Constructor
smallCTreeSummary::smallCTreeSummary(tree::ParseTree* t) {
 
  // Pointer to the parse tree
  tree = t;

  // Clear the map
  nonterminalsMap.clear();

  // Initialize the map entries
  nonterminalsMap["program"] = 0;
  nonterminalsMap["preamble"] = 0;
  nonterminalsMap["decls"] = 0;
  nonterminalsMap["scalardecllist"] = 0;
  nonterminalsMap["scalardecl"] = 0;
  nonterminalsMap["arraydecllist"] = 0;
  nonterminalsMap["arraydecl"] = 0;
  nonterminalsMap["fcnproto"] = 0;
  nonterminalsMap["fcndecl"] = 0;
  nonterminalsMap["vartype"] = 0;
  nonterminalsMap["rettype"] = 0;
  nonterminalsMap["constant"] = 0;
  nonterminalsMap["boolconstant"] = 0;
  nonterminalsMap["scope"] = 0;
  nonterminalsMap["stmt"] = 0;
  nonterminalsMap["assignstmt"] = 0;
  nonterminalsMap["ifstmt"] = 0;
  nonterminalsMap["whilestmt"] = 0;
  nonterminalsMap["retstmt"] = 0;
  nonterminalsMap["expr"] = 0;
  nonterminalsMap["intexpr"] = 0;
  nonterminalsMap["var"] = 0;
  nonterminalsMap["params"] = 0;
  nonterminalsMap["paramentry"] = 0;
  nonterminalsMap["paramlist"] = 0;
  nonterminalsMap["args"] = 0;
  nonterminalsMap["argentry"] = 0;
  nonterminalsMap["arglist"] = 0;
  nonterminalsMap["varname"] = 0;
  nonterminalsMap["arrname"] = 0;
  nonterminalsMap["fcnname"] = 0;
  nonterminalsMap["intconst"] = 0;
}

// Visitors
antlrcpp::Any 
smallCTreeSummary::visitProgram(smallCParser::ProgramContext *ctx) {
  ++nonterminalsMap["program"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitPreamble(smallCParser::PreambleContext *ctx) {
  ++nonterminalsMap["preamble"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitDecls(smallCParser::DeclsContext *ctx) {
  ++nonterminalsMap["decls"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitScalarDeclList(smallCParser::ScalarDeclListContext *ctx) {
  ++nonterminalsMap["scalardecllist"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitScalarDecl(smallCParser::ScalarDeclContext *ctx) {
  ++nonterminalsMap["scalardecl"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitArrDeclList(smallCParser::ArrDeclListContext *ctx) {
  ++nonterminalsMap["arraydecllist"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitArrDecl(smallCParser::ArrDeclContext *ctx) {
  ++nonterminalsMap["arraydecl"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitFcnProto(smallCParser::FcnProtoContext *ctx) {
  ++nonterminalsMap["fcnproto"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitFcnDecl(smallCParser::FcnDeclContext *ctx) {
  ++nonterminalsMap["fcndecl"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitVarType(smallCParser::VarTypeContext *ctx) {
  ++nonterminalsMap["vartype"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitRetType(smallCParser::RetTypeContext *ctx) {
  ++nonterminalsMap["rettype"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitConstant(smallCParser::ConstantContext *ctx) {
  ++nonterminalsMap["constant"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitBoolConst(smallCParser::BoolConstContext *ctx) {
  ++nonterminalsMap["boolconstant"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitScope(smallCParser::ScopeContext *ctx) {
  ++nonterminalsMap["scope"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitStmt(smallCParser::StmtContext *ctx) {
  ++nonterminalsMap["stmt"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitAssignStmt(smallCParser::AssignStmtContext *ctx) {
  ++nonterminalsMap["assignstmt"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitIfStmt(smallCParser::IfStmtContext *ctx) {
  ++nonterminalsMap["ifstmt"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitWhileStmt(smallCParser::WhileStmtContext *ctx) {
  ++nonterminalsMap["whilestmt"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitRetStmt(smallCParser::RetStmtContext *ctx) {
  ++nonterminalsMap["retstmt"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitExpr(smallCParser::ExprContext *ctx) {
  ++nonterminalsMap["expr"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitIntExpr(smallCParser::IntExprContext *ctx) {
  ++nonterminalsMap["intexpr"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitVar(smallCParser::VarContext *ctx) {
  ++nonterminalsMap["var"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitParams(smallCParser::ParamsContext *ctx) {
  ++nonterminalsMap["params"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitParamEntry(smallCParser::ParamEntryContext *ctx) {
  ++nonterminalsMap["paramentry"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitParamList(smallCParser::ParamListContext *ctx) {
  ++nonterminalsMap["paramlist"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitArgs(smallCParser::ArgsContext *ctx) {
  ++nonterminalsMap["args"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitArgEntry(smallCParser::ArgEntryContext *ctx) {
  ++nonterminalsMap["argentry"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitArgList(smallCParser::ArgListContext *ctx) {
  ++nonterminalsMap["arglist"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitVarName(smallCParser::VarNameContext *ctx) {
  ++nonterminalsMap["varname"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitArrName(smallCParser::ArrNameContext *ctx) {
  ++nonterminalsMap["arrname"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitFcnName(smallCParser::FcnNameContext *ctx) {
  ++nonterminalsMap["fcnname"];
  return visitChildren(ctx);
}

antlrcpp::Any 
smallCTreeSummary::visitIntConst(smallCParser::IntConstContext *ctx) {
  ++nonterminalsMap["intconst"];
  return visitChildren(ctx);
}

// Print the summary
void
smallCTreeSummary::print() {
  std::cout << "program = " << nonterminalsMap["program"] << std::endl;
  std::cout << "preamble = " << nonterminalsMap["preamble"] << std::endl;
  std::cout << "decls = " << nonterminalsMap["decls"] << std::endl;
  std::cout << "scalardecllist = " << nonterminalsMap["scalardecllist"] << std::endl;
  std::cout << "scalardecl = " << nonterminalsMap["scalardecl"] << std::endl;
  std::cout << "arraydecllist = " << nonterminalsMap["arraydecllist"] << std::endl;
  std::cout << "arraydecl = " << nonterminalsMap["arraydecl"] << std::endl;
  std::cout << "fcnproto = " << nonterminalsMap["fcnproto"] << std::endl;
  std::cout << "fcndecl = " << nonterminalsMap["fcndecl"] << std::endl;
  std::cout << "vartype = " << nonterminalsMap["vartype"] << std::endl;
  std::cout << "rettype = " << nonterminalsMap["rettype"] << std::endl;
  std::cout << "constant = " << nonterminalsMap["constant"] << std::endl;
  std::cout << "boolconstant = " << nonterminalsMap["boolconstant"] << std::endl;
  std::cout << "scope = " << nonterminalsMap["scope"] << std::endl;
  std::cout << "stmt = " << nonterminalsMap["stmt"] << std::endl;
  std::cout << "assignstmt = " << nonterminalsMap["assignstmt"] << std::endl;
  std::cout << "ifstmt = " << nonterminalsMap["ifstmt"] << std::endl;
  std::cout << "whilestmt = " << nonterminalsMap["whilestmt"] << std::endl;
  std::cout << "retstmt = " << nonterminalsMap["retstmt"] << std::endl;
  std::cout << "expr = " << nonterminalsMap["expr"] << std::endl;
  std::cout << "intexpr = " << nonterminalsMap["intexpr"] << std::endl;
  std::cout << "var = " << nonterminalsMap["var"] << std::endl;
  std::cout << "params = " << nonterminalsMap["params"] << std::endl;
  std::cout << "paramentry = " << nonterminalsMap["paramentry"] << std::endl;
  std::cout << "paramlist = " << nonterminalsMap["paramlist"] << std::endl;
  std::cout << "args = " << nonterminalsMap["args"] << std::endl;
  std::cout << "argentry = " << nonterminalsMap["argentry"] << std::endl;
  std::cout << "arglist = " << nonterminalsMap["arglist"] << std::endl;
  std::cout << "varname = " << nonterminalsMap["varname"] << std::endl;
  std::cout << "arrname = " << nonterminalsMap["arrname"] << std::endl;
  std::cout << "fcnname = " << nonterminalsMap["fcnname"] << std::endl;
  std::cout << "intconst = " << nonterminalsMap["intconst"] << std::endl;
}

// This function prints key stats count of the parse tree. It is only
// used for exercise and autotesting 
void printSummary(tree::ParseTree* tree) {

    // Create summary visitor
    smallCBaseVisitor* countVisitor = new smallCTreeSummary(tree);

    // Visit the tree
    countVisitor->visit(tree);

    // Print the summary
    ((smallCTreeSummary *)countVisitor)->print();

    // Delete the summary visitor
    delete countVisitor;

    return;
}
