
//  printSummary.h
//  ECE467 Lab 2
//
//  Created by Tarek Abdelrahman on 2023-07-19.
//  Modified by Tarek Abdelrahman on 2023-07-19.
//  Copyright © 2023 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#pragma once

#include <iostream>
#include <map>
#include <string>

#include "antlr4-runtime.h"
#include "smallCLexer.h"
#include "smallCParser.h"
#include "smallCBaseVisitor.h"

using namespace antlrcpp;
using namespace antlr4;
using namespace std;

class  smallCTreeSummary : public smallCBaseVisitor {
    private:
        smallCLexer* lexer;
        smallCParser* parser;
        CommonTokenStream* tokens;
        tree::ParseTree* tree;

        // Map to contain the counts of non-terminal symbols
        std::map<string,int> nonterminalsMap;

    public:
        // Constructor
        smallCTreeSummary(tree::ParseTree* t);

        // Visitors
        virtual antlrcpp::Any visitProgram(smallCParser::ProgramContext *ctx) override;
        virtual antlrcpp::Any visitPreamble(smallCParser::PreambleContext *ctx) override;
        virtual antlrcpp::Any visitDecls(smallCParser::DeclsContext *ctx) override;
        virtual antlrcpp::Any visitScalarDeclList(smallCParser::ScalarDeclListContext *ctx) override;
        virtual antlrcpp::Any visitScalarDecl(smallCParser::ScalarDeclContext *ctx) override;
        virtual antlrcpp::Any visitArrDeclList(smallCParser::ArrDeclListContext *ctx) override;
        virtual antlrcpp::Any visitArrDecl(smallCParser::ArrDeclContext *ctx) override;
        virtual antlrcpp::Any visitFcnProto(smallCParser::FcnProtoContext *ctx) override;
        virtual antlrcpp::Any visitFcnDecl(smallCParser::FcnDeclContext *ctx) override;
        virtual antlrcpp::Any visitVarType(smallCParser::VarTypeContext *ctx) override;
        virtual antlrcpp::Any visitRetType(smallCParser::RetTypeContext *ctx) override;
        virtual antlrcpp::Any visitConstant(smallCParser::ConstantContext *ctx) override;
        virtual antlrcpp::Any visitBoolConst(smallCParser::BoolConstContext *ctx) override;
        virtual antlrcpp::Any visitScope(smallCParser::ScopeContext *ctx) override;
        virtual antlrcpp::Any visitStmt(smallCParser::StmtContext *ctx) override;
        virtual antlrcpp::Any visitAssignStmt(smallCParser::AssignStmtContext *ctx) override;
        virtual antlrcpp::Any visitIfStmt(smallCParser::IfStmtContext *ctx) override;
        virtual antlrcpp::Any visitWhileStmt(smallCParser::WhileStmtContext *ctx) override;
        virtual antlrcpp::Any visitRetStmt(smallCParser::RetStmtContext *ctx) override;
        virtual antlrcpp::Any visitExpr(smallCParser::ExprContext *ctx) override;
        virtual antlrcpp::Any visitIntExpr(smallCParser::IntExprContext *ctx) override;
        virtual antlrcpp::Any visitVar(smallCParser::VarContext *ctx) override;
        virtual antlrcpp::Any visitParams(smallCParser::ParamsContext *ctx) override;
        virtual antlrcpp::Any visitParamEntry(smallCParser::ParamEntryContext *ctx) override;
        virtual antlrcpp::Any visitParamList(smallCParser::ParamListContext *ctx) override;
        virtual antlrcpp::Any visitArgs(smallCParser::ArgsContext *ctx) override;
        virtual antlrcpp::Any visitArgEntry(smallCParser::ArgEntryContext *ctx) override;
        virtual antlrcpp::Any visitArgList(smallCParser::ArgListContext *ctx) override;
        virtual antlrcpp::Any visitVarName(smallCParser::VarNameContext *ctx) override;
        virtual antlrcpp::Any visitArrName(smallCParser::ArrNameContext *ctx) override;
        virtual antlrcpp::Any visitFcnName(smallCParser::FcnNameContext *ctx) override;
        virtual antlrcpp::Any visitIntConst(smallCParser::IntConstContext *ctx) override;

        // Print the summary
        void print();
};

void printSummary(tree::ParseTree* tree);

