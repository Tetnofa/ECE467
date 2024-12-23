
#include "ASTNodes.h"
#include <iostream>
#include <string>


// Generated from smallC.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  smallCParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    BOOL = 33, ID = 34, INT = 35, WS = 36, COMMENT = 37
  };

  enum {
    RuleProgram = 0, RulePreamble = 1, RuleDecls = 2, RuleScalarDeclList = 3, 
    RuleScalarDecl = 4, RuleArrDeclList = 5, RuleArrDecl = 6, RuleFcnProtoList = 7, 
    RuleFcnProto = 8, RuleFcnDeclList = 9, RuleFcnDecl = 10, RuleVarType = 11, 
    RuleRetType = 12, RuleConstant = 13, RuleBoolConst = 14, RuleScope = 15, 
    RuleStmt = 16, RuleAssignStmt = 17, RuleIfStmt = 18, RuleWhileStmt = 19, 
    RuleRetStmt = 20, RuleExpr = 21, RuleIntExpr = 22, RuleVar = 23, RuleParams = 24, 
    RuleParamEntry = 25, RuleParamList = 26, RuleArgs = 27, RuleArgEntry = 28, 
    RuleArgList = 29, RuleVarName = 30, RuleArrName = 31, RuleFcnName = 32, 
    RuleIntConst = 33
  };

  smallCParser(antlr4::TokenStream *input);
  ~smallCParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class PreambleContext;
  class DeclsContext;
  class ScalarDeclListContext;
  class ScalarDeclContext;
  class ArrDeclListContext;
  class ArrDeclContext;
  class FcnProtoListContext;
  class FcnProtoContext;
  class FcnDeclListContext;
  class FcnDeclContext;
  class VarTypeContext;
  class RetTypeContext;
  class ConstantContext;
  class BoolConstContext;
  class ScopeContext;
  class StmtContext;
  class AssignStmtContext;
  class IfStmtContext;
  class WhileStmtContext;
  class RetStmtContext;
  class ExprContext;
  class IntExprContext;
  class VarContext;
  class ParamsContext;
  class ParamEntryContext;
  class ParamListContext;
  class ArgsContext;
  class ArgEntryContext;
  class ArgListContext;
  class VarNameContext;
  class ArrNameContext;
  class FcnNameContext;
  class IntConstContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    smallc::ProgramNode * prg;
    smallCParser::DeclsContext *declsContext = nullptr;;
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    PreambleContext *preamble();
    std::vector<DeclsContext *> decls();
    DeclsContext* decls(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  PreambleContext : public antlr4::ParserRuleContext {
  public:
    PreambleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PreambleContext* preamble();

  class  DeclsContext : public antlr4::ParserRuleContext {
  public:
    std::vector<smallc::DeclNode*> declarations;
    smallCParser::ScalarDeclListContext *scalarDeclListContext = nullptr;;
    smallCParser::ArrDeclListContext *arrDeclListContext = nullptr;;
    smallCParser::FcnProtoListContext *fcnProtoListContext = nullptr;;
    smallCParser::FcnDeclListContext *fcnDeclListContext = nullptr;;
    DeclsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScalarDeclListContext *scalarDeclList();
    ArrDeclListContext *arrDeclList();
    FcnProtoListContext *fcnProtoList();
    FcnDeclListContext *fcnDeclList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclsContext* decls();

  class  ScalarDeclListContext : public antlr4::ParserRuleContext {
  public:
    std::vector<smallc::ScalarDeclNode*> scalars;
    smallCParser::ScalarDeclContext *scalarDeclContext = nullptr;;
    smallCParser::ScalarDeclListContext *scalarDeclListContext = nullptr;;
    ScalarDeclListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScalarDeclContext *scalarDecl();
    ScalarDeclListContext *scalarDeclList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScalarDeclListContext* scalarDeclList();

  class  ScalarDeclContext : public antlr4::ParserRuleContext {
  public:
    smallc::ScalarDeclNode* decl;
    smallCParser::VarTypeContext *t = nullptr;;
    smallCParser::VarNameContext *v = nullptr;;
    ScalarDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarTypeContext *varType();
    VarNameContext *varName();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScalarDeclContext* scalarDecl();

  class  ArrDeclListContext : public antlr4::ParserRuleContext {
  public:
    std::vector<smallc::ArrayDeclNode*> arrays;
    smallCParser::ArrDeclContext *arrDeclContext = nullptr;;
    smallCParser::ArrDeclListContext *arrDeclListContext = nullptr;;
    ArrDeclListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArrDeclContext *arrDecl();
    ArrDeclListContext *arrDeclList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrDeclListContext* arrDeclList();

  class  ArrDeclContext : public antlr4::ParserRuleContext {
  public:
    smallc::ArrayDeclNode* decl;
    smallCParser::VarTypeContext *t = nullptr;;
    smallCParser::ArrNameContext *n = nullptr;;
    smallCParser::IntConstContext *size = nullptr;;
    ArrDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarTypeContext *varType();
    ArrNameContext *arrName();
    IntConstContext *intConst();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrDeclContext* arrDecl();

  class  FcnProtoListContext : public antlr4::ParserRuleContext {
  public:
    std::vector<smallc::FunctionDeclNode*> prototypes;
    smallCParser::FcnProtoContext *fcnProtoContext = nullptr;;
    smallCParser::FcnProtoListContext *fcnProtoListContext = nullptr;;
    FcnProtoListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FcnProtoContext *fcnProto();
    FcnProtoListContext *fcnProtoList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FcnProtoListContext* fcnProtoList();

  class  FcnProtoContext : public antlr4::ParserRuleContext {
  public:
    smallc::FunctionDeclNode* proto;
    smallCParser::RetTypeContext *t = nullptr;;
    smallCParser::FcnNameContext *n = nullptr;;
    smallCParser::ParamsContext *p = nullptr;;
    FcnProtoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RetTypeContext *retType();
    FcnNameContext *fcnName();
    ParamsContext *params();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FcnProtoContext* fcnProto();

  class  FcnDeclListContext : public antlr4::ParserRuleContext {
  public:
    std::vector<smallc::FunctionDeclNode*> declarations;
    smallCParser::FcnDeclContext *fcnDeclContext = nullptr;;
    smallCParser::FcnDeclListContext *fcnDeclListContext = nullptr;;
    FcnDeclListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FcnDeclContext *fcnDecl();
    FcnDeclListContext *fcnDeclList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FcnDeclListContext* fcnDeclList();

  class  FcnDeclContext : public antlr4::ParserRuleContext {
  public:
    smallc::FunctionDeclNode* declaration;
    smallCParser::RetTypeContext *t = nullptr;;
    smallCParser::FcnNameContext *n = nullptr;;
    smallCParser::ParamsContext *p = nullptr;;
    smallCParser::ScopeContext *s = nullptr;;
    FcnDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RetTypeContext *retType();
    FcnNameContext *fcnName();
    ParamsContext *params();
    ScopeContext *scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FcnDeclContext* fcnDecl();

  class  VarTypeContext : public antlr4::ParserRuleContext {
  public:
    smallc::PrimitiveTypeNode* type;
    VarTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarTypeContext* varType();

  class  RetTypeContext : public antlr4::ParserRuleContext {
  public:
    smallc::PrimitiveTypeNode* type;
    smallCParser::VarTypeContext *varTypeContext = nullptr;;
    RetTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarTypeContext *varType();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RetTypeContext* retType();

  class  ConstantContext : public antlr4::ParserRuleContext {
  public:
    smallc::ConstantExprNode* node;
    smallCParser::BoolConstContext *boolConstContext = nullptr;;
    smallCParser::IntConstContext *intConstContext = nullptr;;
    ConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BoolConstContext *boolConst();
    IntConstContext *intConst();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstantContext* constant();

  class  BoolConstContext : public antlr4::ParserRuleContext {
  public:
    smallc::BoolConstantNode* node;
    antlr4::Token *b = nullptr;;
    BoolConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOOL();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BoolConstContext* boolConst();

  class  ScopeContext : public antlr4::ParserRuleContext {
  public:
    smallc::ScopeNode* scope_;
    smallCParser::ScalarDeclContext *scalarDeclContext = nullptr;;
    smallCParser::ArrDeclContext *arrDeclContext = nullptr;;
    smallCParser::StmtContext *stmtContext = nullptr;;
    ScopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ScalarDeclContext *> scalarDecl();
    ScalarDeclContext* scalarDecl(size_t i);
    std::vector<ArrDeclContext *> arrDecl();
    ArrDeclContext* arrDecl(size_t i);
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScopeContext* scope();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    smallc::StmtNode* statement;
    smallCParser::ExprContext *exprContext = nullptr;;
    smallCParser::AssignStmtContext *assignStmtContext = nullptr;;
    smallCParser::IfStmtContext *ifStmtContext = nullptr;;
    smallCParser::WhileStmtContext *whileStmtContext = nullptr;;
    smallCParser::RetStmtContext *retStmtContext = nullptr;;
    smallCParser::ScopeContext *scopeContext = nullptr;;
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    AssignStmtContext *assignStmt();
    IfStmtContext *ifStmt();
    WhileStmtContext *whileStmt();
    RetStmtContext *retStmt();
    ScopeContext *scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmtContext* stmt();

  class  AssignStmtContext : public antlr4::ParserRuleContext {
  public:
    smallc::AssignStmtNode* assignment;
    smallCParser::VarContext *varContext = nullptr;;
    smallCParser::ExprContext *exprContext = nullptr;;
    AssignStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarContext *var();
    ExprContext *expr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignStmtContext* assignStmt();

  class  IfStmtContext : public antlr4::ParserRuleContext {
  public:
    smallc::IfStmtNode* ifNode;
    smallCParser::ExprContext *cond = nullptr;;
    smallCParser::StmtContext *then = nullptr;;
    smallCParser::StmtContext *else_ = nullptr;;
    IfStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfStmtContext* ifStmt();

  class  WhileStmtContext : public antlr4::ParserRuleContext {
  public:
    smallc::WhileStmtNode* whileNode;
    smallCParser::ExprContext *cond = nullptr;;
    smallCParser::StmtContext *body = nullptr;;
    WhileStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    StmtContext *stmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileStmtContext* whileStmt();

  class  RetStmtContext : public antlr4::ParserRuleContext {
  public:
    smallc::ReturnStmtNode* returnNode;
    smallCParser::ExprContext *val = nullptr;;
    RetStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RetStmtContext* retStmt();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    smallc::ExprNode* node;
    smallCParser::ExprContext *l = nullptr;;
    smallCParser::IntExprContext *intExprContext = nullptr;;
    smallCParser::ExprContext *e = nullptr;;
    smallCParser::FcnNameContext *n = nullptr;;
    smallCParser::ArgsContext *argsContext = nullptr;;
    antlr4::Token *op = nullptr;;
    smallCParser::ExprContext *r = nullptr;;
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntExprContext *intExpr();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    ArgsContext *args();
    FcnNameContext *fcnName();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  IntExprContext : public antlr4::ParserRuleContext {
  public:
    smallc::IntExprNode* exprNode;
    smallCParser::IntExprContext *l = nullptr;;
    smallCParser::VarContext *varContext = nullptr;;
    smallCParser::ConstantContext *constantContext = nullptr;;
    smallCParser::IntExprContext *e = nullptr;;
    antlr4::Token *op = nullptr;;
    smallCParser::IntExprContext *r = nullptr;;
    IntExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarContext *var();
    ConstantContext *constant();
    std::vector<IntExprContext *> intExpr();
    IntExprContext* intExpr(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntExprContext* intExpr();
  IntExprContext* intExpr(int precedence);
  class  VarContext : public antlr4::ParserRuleContext {
  public:
    smallc::ReferenceExprNode* node;
    smallCParser::VarNameContext *v = nullptr;;
    smallCParser::ArrNameContext *a = nullptr;;
    smallCParser::IntExprContext *idx = nullptr;;
    VarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarNameContext *varName();
    ArrNameContext *arrName();
    IntExprContext *intExpr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarContext* var();

  class  ParamsContext : public antlr4::ParserRuleContext {
  public:
    std::vector<smallc::ParameterNode*> parameters;
    smallCParser::ParamListContext *p = nullptr;;
    ParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParamListContext *paramList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamsContext* params();

  class  ParamEntryContext : public antlr4::ParserRuleContext {
  public:
    smallc::ParameterNode* param;
    smallCParser::VarTypeContext *t = nullptr;;
    smallCParser::VarNameContext *name = nullptr;;
    smallCParser::ArrNameContext *arrname = nullptr;;
    ParamEntryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarTypeContext *varType();
    VarNameContext *varName();
    ArrNameContext *arrName();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamEntryContext* paramEntry();

  class  ParamListContext : public antlr4::ParserRuleContext {
  public:
    std::vector<smallc::ParameterNode*> parameterList;
    smallCParser::ParamEntryContext *p = nullptr;;
    smallCParser::ParamListContext *pl = nullptr;;
    ParamListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParamEntryContext *paramEntry();
    ParamListContext *paramList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamListContext* paramList();

  class  ArgsContext : public antlr4::ParserRuleContext {
  public:
    std::vector<smallc::ArgumentNode*> arguments;
    smallCParser::ArgListContext *a = nullptr;;
    ArgsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArgListContext *argList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgsContext* args();

  class  ArgEntryContext : public antlr4::ParserRuleContext {
  public:
    smallc::ArgumentNode* arg;
    smallCParser::ExprContext *e = nullptr;;
    ArgEntryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgEntryContext* argEntry();

  class  ArgListContext : public antlr4::ParserRuleContext {
  public:
    std::vector<smallc::ArgumentNode*> argumentList;
    smallCParser::ArgEntryContext *a = nullptr;;
    smallCParser::ArgListContext *al = nullptr;;
    ArgListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArgEntryContext *argEntry();
    ArgListContext *argList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgListContext* argList();

  class  VarNameContext : public antlr4::ParserRuleContext {
  public:
    smallc::IdentifierNode* node;
    antlr4::Token *id = nullptr;;
    VarNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarNameContext* varName();

  class  ArrNameContext : public antlr4::ParserRuleContext {
  public:
    smallc::IdentifierNode* node;
    antlr4::Token *id = nullptr;;
    ArrNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrNameContext* arrName();

  class  FcnNameContext : public antlr4::ParserRuleContext {
  public:
    smallc::IdentifierNode* node;
    antlr4::Token *id = nullptr;;
    FcnNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FcnNameContext* fcnName();

  class  IntConstContext : public antlr4::ParserRuleContext {
  public:
    smallc::IntConstantNode* node;
    antlr4::Token *i = nullptr;;
    IntConstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntConstContext* intConst();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);
  bool intExprSempred(IntExprContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

