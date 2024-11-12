
// Generated from smallC.g4 by ANTLR 4.7.2


#include "smallCVisitor.h"

#include "smallCParser.h"


using namespace antlrcpp;
using namespace antlr4;

smallCParser::smallCParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

smallCParser::~smallCParser() {
  delete _interpreter;
}

std::string smallCParser::getGrammarFileName() const {
  return "smallC.g4";
}

const std::vector<std::string>& smallCParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& smallCParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

smallCParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smallCParser::ProgramContext::EOF() {
  return getToken(smallCParser::EOF, 0);
}

smallCParser::PreambleContext* smallCParser::ProgramContext::preamble() {
  return getRuleContext<smallCParser::PreambleContext>(0);
}

std::vector<smallCParser::DeclsContext *> smallCParser::ProgramContext::decls() {
  return getRuleContexts<smallCParser::DeclsContext>();
}

smallCParser::DeclsContext* smallCParser::ProgramContext::decls(size_t i) {
  return getRuleContext<smallCParser::DeclsContext>(i);
}


size_t smallCParser::ProgramContext::getRuleIndex() const {
  return smallCParser::RuleProgram;
}


antlrcpp::Any smallCParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ProgramContext* smallCParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, smallCParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::T__0: {
        setState(64);
        preamble();
        break;
      }

      case smallCParser::EOF:
      case smallCParser::T__7:
      case smallCParser::T__8:
      case smallCParser::T__9: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(71);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << smallCParser::T__7)
      | (1ULL << smallCParser::T__8)
      | (1ULL << smallCParser::T__9))) != 0)) {
      setState(68);
      decls();
      setState(73);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(74);
    match(smallCParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PreambleContext ------------------------------------------------------------------

smallCParser::PreambleContext::PreambleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t smallCParser::PreambleContext::getRuleIndex() const {
  return smallCParser::RulePreamble;
}


antlrcpp::Any smallCParser::PreambleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitPreamble(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::PreambleContext* smallCParser::preamble() {
  PreambleContext *_localctx = _tracker.createInstance<PreambleContext>(_ctx, getState());
  enterRule(_localctx, 2, smallCParser::RulePreamble);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    match(smallCParser::T__0);
    setState(77);
    match(smallCParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclsContext ------------------------------------------------------------------

smallCParser::DeclsContext::DeclsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ScalarDeclListContext* smallCParser::DeclsContext::scalarDeclList() {
  return getRuleContext<smallCParser::ScalarDeclListContext>(0);
}

smallCParser::ArrDeclListContext* smallCParser::DeclsContext::arrDeclList() {
  return getRuleContext<smallCParser::ArrDeclListContext>(0);
}

smallCParser::FcnProtoContext* smallCParser::DeclsContext::fcnProto() {
  return getRuleContext<smallCParser::FcnProtoContext>(0);
}

smallCParser::FcnDeclContext* smallCParser::DeclsContext::fcnDecl() {
  return getRuleContext<smallCParser::FcnDeclContext>(0);
}


size_t smallCParser::DeclsContext::getRuleIndex() const {
  return smallCParser::RuleDecls;
}


antlrcpp::Any smallCParser::DeclsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitDecls(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::DeclsContext* smallCParser::decls() {
  DeclsContext *_localctx = _tracker.createInstance<DeclsContext>(_ctx, getState());
  enterRule(_localctx, 4, smallCParser::RuleDecls);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(83);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(79);
      scalarDeclList();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(80);
      arrDeclList();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(81);
      fcnProto();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(82);
      fcnDecl();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScalarDeclListContext ------------------------------------------------------------------

smallCParser::ScalarDeclListContext::ScalarDeclListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ScalarDeclContext* smallCParser::ScalarDeclListContext::scalarDecl() {
  return getRuleContext<smallCParser::ScalarDeclContext>(0);
}

smallCParser::ScalarDeclListContext* smallCParser::ScalarDeclListContext::scalarDeclList() {
  return getRuleContext<smallCParser::ScalarDeclListContext>(0);
}


size_t smallCParser::ScalarDeclListContext::getRuleIndex() const {
  return smallCParser::RuleScalarDeclList;
}


antlrcpp::Any smallCParser::ScalarDeclListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitScalarDeclList(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ScalarDeclListContext* smallCParser::scalarDeclList() {
  ScalarDeclListContext *_localctx = _tracker.createInstance<ScalarDeclListContext>(_ctx, getState());
  enterRule(_localctx, 6, smallCParser::RuleScalarDeclList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(89);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(85);
      scalarDecl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(86);
      scalarDecl();
      setState(87);
      scalarDeclList();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScalarDeclContext ------------------------------------------------------------------

smallCParser::ScalarDeclContext::ScalarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::VarTypeContext* smallCParser::ScalarDeclContext::varType() {
  return getRuleContext<smallCParser::VarTypeContext>(0);
}

smallCParser::VarNameContext* smallCParser::ScalarDeclContext::varName() {
  return getRuleContext<smallCParser::VarNameContext>(0);
}


size_t smallCParser::ScalarDeclContext::getRuleIndex() const {
  return smallCParser::RuleScalarDecl;
}


antlrcpp::Any smallCParser::ScalarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitScalarDecl(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ScalarDeclContext* smallCParser::scalarDecl() {
  ScalarDeclContext *_localctx = _tracker.createInstance<ScalarDeclContext>(_ctx, getState());
  enterRule(_localctx, 8, smallCParser::RuleScalarDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(91);
    varType();
    setState(92);
    varName();
    setState(93);
    match(smallCParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrDeclListContext ------------------------------------------------------------------

smallCParser::ArrDeclListContext::ArrDeclListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ArrDeclContext* smallCParser::ArrDeclListContext::arrDecl() {
  return getRuleContext<smallCParser::ArrDeclContext>(0);
}

smallCParser::ArrDeclListContext* smallCParser::ArrDeclListContext::arrDeclList() {
  return getRuleContext<smallCParser::ArrDeclListContext>(0);
}


size_t smallCParser::ArrDeclListContext::getRuleIndex() const {
  return smallCParser::RuleArrDeclList;
}


antlrcpp::Any smallCParser::ArrDeclListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitArrDeclList(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ArrDeclListContext* smallCParser::arrDeclList() {
  ArrDeclListContext *_localctx = _tracker.createInstance<ArrDeclListContext>(_ctx, getState());
  enterRule(_localctx, 10, smallCParser::RuleArrDeclList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(99);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(95);
      arrDecl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(96);
      arrDecl();
      setState(97);
      arrDeclList();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrDeclContext ------------------------------------------------------------------

smallCParser::ArrDeclContext::ArrDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::VarTypeContext* smallCParser::ArrDeclContext::varType() {
  return getRuleContext<smallCParser::VarTypeContext>(0);
}

smallCParser::ArrNameContext* smallCParser::ArrDeclContext::arrName() {
  return getRuleContext<smallCParser::ArrNameContext>(0);
}

smallCParser::IntConstContext* smallCParser::ArrDeclContext::intConst() {
  return getRuleContext<smallCParser::IntConstContext>(0);
}


size_t smallCParser::ArrDeclContext::getRuleIndex() const {
  return smallCParser::RuleArrDecl;
}


antlrcpp::Any smallCParser::ArrDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitArrDecl(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ArrDeclContext* smallCParser::arrDecl() {
  ArrDeclContext *_localctx = _tracker.createInstance<ArrDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, smallCParser::RuleArrDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    varType();
    setState(102);
    arrName();
    setState(103);
    match(smallCParser::T__3);
    setState(104);
    intConst();
    setState(105);
    match(smallCParser::T__4);
    setState(106);
    match(smallCParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FcnProtoContext ------------------------------------------------------------------

smallCParser::FcnProtoContext::FcnProtoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::RetTypeContext* smallCParser::FcnProtoContext::retType() {
  return getRuleContext<smallCParser::RetTypeContext>(0);
}

smallCParser::FcnNameContext* smallCParser::FcnProtoContext::fcnName() {
  return getRuleContext<smallCParser::FcnNameContext>(0);
}

smallCParser::ParamsContext* smallCParser::FcnProtoContext::params() {
  return getRuleContext<smallCParser::ParamsContext>(0);
}


size_t smallCParser::FcnProtoContext::getRuleIndex() const {
  return smallCParser::RuleFcnProto;
}


antlrcpp::Any smallCParser::FcnProtoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitFcnProto(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::FcnProtoContext* smallCParser::fcnProto() {
  FcnProtoContext *_localctx = _tracker.createInstance<FcnProtoContext>(_ctx, getState());
  enterRule(_localctx, 14, smallCParser::RuleFcnProto);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    retType();
    setState(109);
    fcnName();
    setState(110);
    match(smallCParser::T__5);
    setState(111);
    params();
    setState(112);
    match(smallCParser::T__6);
    setState(113);
    match(smallCParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FcnDeclContext ------------------------------------------------------------------

smallCParser::FcnDeclContext::FcnDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::RetTypeContext* smallCParser::FcnDeclContext::retType() {
  return getRuleContext<smallCParser::RetTypeContext>(0);
}

smallCParser::FcnNameContext* smallCParser::FcnDeclContext::fcnName() {
  return getRuleContext<smallCParser::FcnNameContext>(0);
}

smallCParser::ParamsContext* smallCParser::FcnDeclContext::params() {
  return getRuleContext<smallCParser::ParamsContext>(0);
}

smallCParser::ScopeContext* smallCParser::FcnDeclContext::scope() {
  return getRuleContext<smallCParser::ScopeContext>(0);
}


size_t smallCParser::FcnDeclContext::getRuleIndex() const {
  return smallCParser::RuleFcnDecl;
}


antlrcpp::Any smallCParser::FcnDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitFcnDecl(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::FcnDeclContext* smallCParser::fcnDecl() {
  FcnDeclContext *_localctx = _tracker.createInstance<FcnDeclContext>(_ctx, getState());
  enterRule(_localctx, 16, smallCParser::RuleFcnDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    retType();
    setState(116);
    fcnName();
    setState(117);
    match(smallCParser::T__5);
    setState(118);
    params();
    setState(119);
    match(smallCParser::T__6);
    setState(120);
    scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarTypeContext ------------------------------------------------------------------

smallCParser::VarTypeContext::VarTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t smallCParser::VarTypeContext::getRuleIndex() const {
  return smallCParser::RuleVarType;
}


antlrcpp::Any smallCParser::VarTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitVarType(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::VarTypeContext* smallCParser::varType() {
  VarTypeContext *_localctx = _tracker.createInstance<VarTypeContext>(_ctx, getState());
  enterRule(_localctx, 18, smallCParser::RuleVarType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    _la = _input->LA(1);
    if (!(_la == smallCParser::T__7

    || _la == smallCParser::T__8)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RetTypeContext ------------------------------------------------------------------

smallCParser::RetTypeContext::RetTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::VarTypeContext* smallCParser::RetTypeContext::varType() {
  return getRuleContext<smallCParser::VarTypeContext>(0);
}


size_t smallCParser::RetTypeContext::getRuleIndex() const {
  return smallCParser::RuleRetType;
}


antlrcpp::Any smallCParser::RetTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitRetType(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::RetTypeContext* smallCParser::retType() {
  RetTypeContext *_localctx = _tracker.createInstance<RetTypeContext>(_ctx, getState());
  enterRule(_localctx, 20, smallCParser::RuleRetType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(126);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::T__9: {
        enterOuterAlt(_localctx, 1);
        setState(124);
        match(smallCParser::T__9);
        break;
      }

      case smallCParser::T__7:
      case smallCParser::T__8: {
        enterOuterAlt(_localctx, 2);
        setState(125);
        varType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

smallCParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::BoolConstContext* smallCParser::ConstantContext::boolConst() {
  return getRuleContext<smallCParser::BoolConstContext>(0);
}

smallCParser::IntConstContext* smallCParser::ConstantContext::intConst() {
  return getRuleContext<smallCParser::IntConstContext>(0);
}


size_t smallCParser::ConstantContext::getRuleIndex() const {
  return smallCParser::RuleConstant;
}


antlrcpp::Any smallCParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ConstantContext* smallCParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 22, smallCParser::RuleConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(130);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::BOOL: {
        enterOuterAlt(_localctx, 1);
        setState(128);
        boolConst();
        break;
      }

      case smallCParser::T__18:
      case smallCParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(129);
        intConst();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScopeContext ------------------------------------------------------------------

smallCParser::ScopeContext::ScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<smallCParser::ScalarDeclContext *> smallCParser::ScopeContext::scalarDecl() {
  return getRuleContexts<smallCParser::ScalarDeclContext>();
}

smallCParser::ScalarDeclContext* smallCParser::ScopeContext::scalarDecl(size_t i) {
  return getRuleContext<smallCParser::ScalarDeclContext>(i);
}

std::vector<smallCParser::ArrDeclContext *> smallCParser::ScopeContext::arrDecl() {
  return getRuleContexts<smallCParser::ArrDeclContext>();
}

smallCParser::ArrDeclContext* smallCParser::ScopeContext::arrDecl(size_t i) {
  return getRuleContext<smallCParser::ArrDeclContext>(i);
}

std::vector<smallCParser::StmtContext *> smallCParser::ScopeContext::stmt() {
  return getRuleContexts<smallCParser::StmtContext>();
}

smallCParser::StmtContext* smallCParser::ScopeContext::stmt(size_t i) {
  return getRuleContext<smallCParser::StmtContext>(i);
}


size_t smallCParser::ScopeContext::getRuleIndex() const {
  return smallCParser::RuleScope;
}


antlrcpp::Any smallCParser::ScopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitScope(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ScopeContext* smallCParser::scope() {
  ScopeContext *_localctx = _tracker.createInstance<ScopeContext>(_ctx, getState());
  enterRule(_localctx, 24, smallCParser::RuleScope);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(132);
    match(smallCParser::T__10);
    setState(137);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == smallCParser::T__7

    || _la == smallCParser::T__8) {
      setState(135);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
      case 1: {
        setState(133);
        scalarDecl();
        break;
      }

      case 2: {
        setState(134);
        arrDecl();
        break;
      }

      }
      setState(139);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(143);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << smallCParser::T__5)
      | (1ULL << smallCParser::T__10)
      | (1ULL << smallCParser::T__13)
      | (1ULL << smallCParser::T__15)
      | (1ULL << smallCParser::T__16)
      | (1ULL << smallCParser::T__17)
      | (1ULL << smallCParser::T__18)
      | (1ULL << smallCParser::BOOL)
      | (1ULL << smallCParser::ID)
      | (1ULL << smallCParser::INT))) != 0)) {
      setState(140);
      stmt();
      setState(145);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(146);
    match(smallCParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

smallCParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ExprContext* smallCParser::StmtContext::expr() {
  return getRuleContext<smallCParser::ExprContext>(0);
}

smallCParser::AssignStmtContext* smallCParser::StmtContext::assignStmt() {
  return getRuleContext<smallCParser::AssignStmtContext>(0);
}

smallCParser::IfStmtContext* smallCParser::StmtContext::ifStmt() {
  return getRuleContext<smallCParser::IfStmtContext>(0);
}

smallCParser::WhileStmtContext* smallCParser::StmtContext::whileStmt() {
  return getRuleContext<smallCParser::WhileStmtContext>(0);
}

smallCParser::RetStmtContext* smallCParser::StmtContext::retStmt() {
  return getRuleContext<smallCParser::RetStmtContext>(0);
}

smallCParser::ScopeContext* smallCParser::StmtContext::scope() {
  return getRuleContext<smallCParser::ScopeContext>(0);
}


size_t smallCParser::StmtContext::getRuleIndex() const {
  return smallCParser::RuleStmt;
}


antlrcpp::Any smallCParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::StmtContext* smallCParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 26, smallCParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(156);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(148);
      expr(0);
      setState(149);
      match(smallCParser::T__2);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(151);
      assignStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(152);
      ifStmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(153);
      whileStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(154);
      retStmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(155);
      scope();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignStmtContext ------------------------------------------------------------------

smallCParser::AssignStmtContext::AssignStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::VarContext* smallCParser::AssignStmtContext::var() {
  return getRuleContext<smallCParser::VarContext>(0);
}

smallCParser::ExprContext* smallCParser::AssignStmtContext::expr() {
  return getRuleContext<smallCParser::ExprContext>(0);
}


size_t smallCParser::AssignStmtContext::getRuleIndex() const {
  return smallCParser::RuleAssignStmt;
}


antlrcpp::Any smallCParser::AssignStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitAssignStmt(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::AssignStmtContext* smallCParser::assignStmt() {
  AssignStmtContext *_localctx = _tracker.createInstance<AssignStmtContext>(_ctx, getState());
  enterRule(_localctx, 28, smallCParser::RuleAssignStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(158);
    var();
    setState(159);
    match(smallCParser::T__12);
    setState(160);
    expr(0);
    setState(161);
    match(smallCParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

smallCParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ExprContext* smallCParser::IfStmtContext::expr() {
  return getRuleContext<smallCParser::ExprContext>(0);
}

std::vector<smallCParser::StmtContext *> smallCParser::IfStmtContext::stmt() {
  return getRuleContexts<smallCParser::StmtContext>();
}

smallCParser::StmtContext* smallCParser::IfStmtContext::stmt(size_t i) {
  return getRuleContext<smallCParser::StmtContext>(i);
}


size_t smallCParser::IfStmtContext::getRuleIndex() const {
  return smallCParser::RuleIfStmt;
}


antlrcpp::Any smallCParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::IfStmtContext* smallCParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 30, smallCParser::RuleIfStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(177);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(163);
      match(smallCParser::T__13);
      setState(164);
      match(smallCParser::T__5);
      setState(165);
      expr(0);
      setState(166);
      match(smallCParser::T__6);
      setState(167);
      stmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(169);
      match(smallCParser::T__13);
      setState(170);
      match(smallCParser::T__5);
      setState(171);
      expr(0);
      setState(172);
      match(smallCParser::T__6);
      setState(173);
      stmt();
      setState(174);
      match(smallCParser::T__14);
      setState(175);
      stmt();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStmtContext ------------------------------------------------------------------

smallCParser::WhileStmtContext::WhileStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ExprContext* smallCParser::WhileStmtContext::expr() {
  return getRuleContext<smallCParser::ExprContext>(0);
}

smallCParser::StmtContext* smallCParser::WhileStmtContext::stmt() {
  return getRuleContext<smallCParser::StmtContext>(0);
}


size_t smallCParser::WhileStmtContext::getRuleIndex() const {
  return smallCParser::RuleWhileStmt;
}


antlrcpp::Any smallCParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::WhileStmtContext* smallCParser::whileStmt() {
  WhileStmtContext *_localctx = _tracker.createInstance<WhileStmtContext>(_ctx, getState());
  enterRule(_localctx, 32, smallCParser::RuleWhileStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(179);
    match(smallCParser::T__15);
    setState(180);
    match(smallCParser::T__5);
    setState(181);
    expr(0);
    setState(182);
    match(smallCParser::T__6);
    setState(183);
    stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RetStmtContext ------------------------------------------------------------------

smallCParser::RetStmtContext::RetStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ExprContext* smallCParser::RetStmtContext::expr() {
  return getRuleContext<smallCParser::ExprContext>(0);
}


size_t smallCParser::RetStmtContext::getRuleIndex() const {
  return smallCParser::RuleRetStmt;
}


antlrcpp::Any smallCParser::RetStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitRetStmt(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::RetStmtContext* smallCParser::retStmt() {
  RetStmtContext *_localctx = _tracker.createInstance<RetStmtContext>(_ctx, getState());
  enterRule(_localctx, 34, smallCParser::RuleRetStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(191);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(185);
      match(smallCParser::T__16);
      setState(186);
      match(smallCParser::T__2);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(187);
      match(smallCParser::T__16);
      setState(188);
      expr(0);
      setState(189);
      match(smallCParser::T__2);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

smallCParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::IntExprContext* smallCParser::ExprContext::intExpr() {
  return getRuleContext<smallCParser::IntExprContext>(0);
}

std::vector<smallCParser::ExprContext *> smallCParser::ExprContext::expr() {
  return getRuleContexts<smallCParser::ExprContext>();
}

smallCParser::ExprContext* smallCParser::ExprContext::expr(size_t i) {
  return getRuleContext<smallCParser::ExprContext>(i);
}

smallCParser::FcnNameContext* smallCParser::ExprContext::fcnName() {
  return getRuleContext<smallCParser::FcnNameContext>(0);
}

smallCParser::ArgsContext* smallCParser::ExprContext::args() {
  return getRuleContext<smallCParser::ArgsContext>(0);
}


size_t smallCParser::ExprContext::getRuleIndex() const {
  return smallCParser::RuleExpr;
}


antlrcpp::Any smallCParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


smallCParser::ExprContext* smallCParser::expr() {
   return expr(0);
}

smallCParser::ExprContext* smallCParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  smallCParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  smallCParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, smallCParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(208);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(194);
      intExpr(0);
      break;
    }

    case 2: {
      setState(195);
      match(smallCParser::T__5);
      setState(196);
      expr(0);
      setState(197);
      match(smallCParser::T__6);
      break;
    }

    case 3: {
      setState(199);
      fcnName();
      setState(200);
      match(smallCParser::T__5);
      setState(201);
      args();
      setState(202);
      match(smallCParser::T__6);
      break;
    }

    case 4: {
      setState(204);
      match(smallCParser::T__17);
      setState(205);
      expr(10);
      break;
    }

    case 5: {
      setState(206);
      match(smallCParser::T__18);
      setState(207);
      expr(9);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(236);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(234);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(210);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(211);
          match(smallCParser::T__19);
          setState(212);
          expr(9);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(213);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(214);
          match(smallCParser::T__20);
          setState(215);
          expr(8);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(216);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(217);
          match(smallCParser::T__21);
          setState(218);
          expr(7);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(219);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(220);
          match(smallCParser::T__22);
          setState(221);
          expr(6);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(222);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(223);
          match(smallCParser::T__23);
          setState(224);
          expr(5);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(225);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(226);
          match(smallCParser::T__24);
          setState(227);
          expr(4);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(228);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(229);
          match(smallCParser::T__25);
          setState(230);
          expr(3);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(231);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(232);
          match(smallCParser::T__26);
          setState(233);
          expr(2);
          break;
        }

        } 
      }
      setState(238);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- IntExprContext ------------------------------------------------------------------

smallCParser::IntExprContext::IntExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ConstantContext* smallCParser::IntExprContext::constant() {
  return getRuleContext<smallCParser::ConstantContext>(0);
}

smallCParser::VarContext* smallCParser::IntExprContext::var() {
  return getRuleContext<smallCParser::VarContext>(0);
}

std::vector<smallCParser::IntExprContext *> smallCParser::IntExprContext::intExpr() {
  return getRuleContexts<smallCParser::IntExprContext>();
}

smallCParser::IntExprContext* smallCParser::IntExprContext::intExpr(size_t i) {
  return getRuleContext<smallCParser::IntExprContext>(i);
}


size_t smallCParser::IntExprContext::getRuleIndex() const {
  return smallCParser::RuleIntExpr;
}


antlrcpp::Any smallCParser::IntExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitIntExpr(this);
  else
    return visitor->visitChildren(this);
}


smallCParser::IntExprContext* smallCParser::intExpr() {
   return intExpr(0);
}

smallCParser::IntExprContext* smallCParser::intExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  smallCParser::IntExprContext *_localctx = _tracker.createInstance<IntExprContext>(_ctx, parentState);
  smallCParser::IntExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, smallCParser::RuleIntExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(246);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::T__18:
      case smallCParser::BOOL:
      case smallCParser::INT: {
        setState(240);
        constant();
        break;
      }

      case smallCParser::ID: {
        setState(241);
        var();
        break;
      }

      case smallCParser::T__5: {
        setState(242);
        match(smallCParser::T__5);
        setState(243);
        intExpr(0);
        setState(244);
        match(smallCParser::T__6);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(262);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(260);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<IntExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleIntExpr);
          setState(248);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(249);
          match(smallCParser::T__27);
          setState(250);
          intExpr(6);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<IntExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleIntExpr);
          setState(251);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(252);
          match(smallCParser::T__18);
          setState(253);
          intExpr(5);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<IntExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleIntExpr);
          setState(254);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(255);
          match(smallCParser::T__28);
          setState(256);
          intExpr(4);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<IntExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleIntExpr);
          setState(257);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(258);
          match(smallCParser::T__29);
          setState(259);
          intExpr(3);
          break;
        }

        } 
      }
      setState(264);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VarContext ------------------------------------------------------------------

smallCParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::VarNameContext* smallCParser::VarContext::varName() {
  return getRuleContext<smallCParser::VarNameContext>(0);
}

smallCParser::ArrNameContext* smallCParser::VarContext::arrName() {
  return getRuleContext<smallCParser::ArrNameContext>(0);
}

smallCParser::IntExprContext* smallCParser::VarContext::intExpr() {
  return getRuleContext<smallCParser::IntExprContext>(0);
}


size_t smallCParser::VarContext::getRuleIndex() const {
  return smallCParser::RuleVar;
}


antlrcpp::Any smallCParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::VarContext* smallCParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 40, smallCParser::RuleVar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(271);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(265);
      varName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(266);
      arrName();
      setState(267);
      match(smallCParser::T__3);
      setState(268);
      intExpr(0);
      setState(269);
      match(smallCParser::T__4);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamsContext ------------------------------------------------------------------

smallCParser::ParamsContext::ParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ParamListContext* smallCParser::ParamsContext::paramList() {
  return getRuleContext<smallCParser::ParamListContext>(0);
}


size_t smallCParser::ParamsContext::getRuleIndex() const {
  return smallCParser::RuleParams;
}


antlrcpp::Any smallCParser::ParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitParams(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ParamsContext* smallCParser::params() {
  ParamsContext *_localctx = _tracker.createInstance<ParamsContext>(_ctx, getState());
  enterRule(_localctx, 42, smallCParser::RuleParams);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(275);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::T__7:
      case smallCParser::T__8: {
        enterOuterAlt(_localctx, 1);
        setState(273);
        paramList();
        break;
      }

      case smallCParser::T__6: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamEntryContext ------------------------------------------------------------------

smallCParser::ParamEntryContext::ParamEntryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::VarTypeContext* smallCParser::ParamEntryContext::varType() {
  return getRuleContext<smallCParser::VarTypeContext>(0);
}

smallCParser::VarNameContext* smallCParser::ParamEntryContext::varName() {
  return getRuleContext<smallCParser::VarNameContext>(0);
}

smallCParser::ArrNameContext* smallCParser::ParamEntryContext::arrName() {
  return getRuleContext<smallCParser::ArrNameContext>(0);
}


size_t smallCParser::ParamEntryContext::getRuleIndex() const {
  return smallCParser::RuleParamEntry;
}


antlrcpp::Any smallCParser::ParamEntryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitParamEntry(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ParamEntryContext* smallCParser::paramEntry() {
  ParamEntryContext *_localctx = _tracker.createInstance<ParamEntryContext>(_ctx, getState());
  enterRule(_localctx, 44, smallCParser::RuleParamEntry);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(284);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(277);
      varType();
      setState(278);
      varName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(280);
      varType();
      setState(281);
      arrName();
      setState(282);
      match(smallCParser::T__30);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamListContext ------------------------------------------------------------------

smallCParser::ParamListContext::ParamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ParamEntryContext* smallCParser::ParamListContext::paramEntry() {
  return getRuleContext<smallCParser::ParamEntryContext>(0);
}

smallCParser::ParamListContext* smallCParser::ParamListContext::paramList() {
  return getRuleContext<smallCParser::ParamListContext>(0);
}


size_t smallCParser::ParamListContext::getRuleIndex() const {
  return smallCParser::RuleParamList;
}


antlrcpp::Any smallCParser::ParamListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitParamList(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ParamListContext* smallCParser::paramList() {
  ParamListContext *_localctx = _tracker.createInstance<ParamListContext>(_ctx, getState());
  enterRule(_localctx, 46, smallCParser::RuleParamList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(291);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(286);
      paramEntry();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(287);
      paramEntry();
      setState(288);
      match(smallCParser::T__31);
      setState(289);
      paramList();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgsContext ------------------------------------------------------------------

smallCParser::ArgsContext::ArgsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ArgListContext* smallCParser::ArgsContext::argList() {
  return getRuleContext<smallCParser::ArgListContext>(0);
}


size_t smallCParser::ArgsContext::getRuleIndex() const {
  return smallCParser::RuleArgs;
}


antlrcpp::Any smallCParser::ArgsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitArgs(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ArgsContext* smallCParser::args() {
  ArgsContext *_localctx = _tracker.createInstance<ArgsContext>(_ctx, getState());
  enterRule(_localctx, 48, smallCParser::RuleArgs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(295);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::T__5:
      case smallCParser::T__17:
      case smallCParser::T__18:
      case smallCParser::BOOL:
      case smallCParser::ID:
      case smallCParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(293);
        argList();
        break;
      }

      case smallCParser::T__6: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgEntryContext ------------------------------------------------------------------

smallCParser::ArgEntryContext::ArgEntryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ExprContext* smallCParser::ArgEntryContext::expr() {
  return getRuleContext<smallCParser::ExprContext>(0);
}


size_t smallCParser::ArgEntryContext::getRuleIndex() const {
  return smallCParser::RuleArgEntry;
}


antlrcpp::Any smallCParser::ArgEntryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitArgEntry(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ArgEntryContext* smallCParser::argEntry() {
  ArgEntryContext *_localctx = _tracker.createInstance<ArgEntryContext>(_ctx, getState());
  enterRule(_localctx, 50, smallCParser::RuleArgEntry);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgListContext ------------------------------------------------------------------

smallCParser::ArgListContext::ArgListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ArgEntryContext* smallCParser::ArgListContext::argEntry() {
  return getRuleContext<smallCParser::ArgEntryContext>(0);
}

smallCParser::ArgListContext* smallCParser::ArgListContext::argList() {
  return getRuleContext<smallCParser::ArgListContext>(0);
}


size_t smallCParser::ArgListContext::getRuleIndex() const {
  return smallCParser::RuleArgList;
}


antlrcpp::Any smallCParser::ArgListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitArgList(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ArgListContext* smallCParser::argList() {
  ArgListContext *_localctx = _tracker.createInstance<ArgListContext>(_ctx, getState());
  enterRule(_localctx, 52, smallCParser::RuleArgList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(304);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(299);
      argEntry();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(300);
      argEntry();
      setState(301);
      match(smallCParser::T__31);
      setState(302);
      argList();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarNameContext ------------------------------------------------------------------

smallCParser::VarNameContext::VarNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smallCParser::VarNameContext::ID() {
  return getToken(smallCParser::ID, 0);
}


size_t smallCParser::VarNameContext::getRuleIndex() const {
  return smallCParser::RuleVarName;
}


antlrcpp::Any smallCParser::VarNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitVarName(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::VarNameContext* smallCParser::varName() {
  VarNameContext *_localctx = _tracker.createInstance<VarNameContext>(_ctx, getState());
  enterRule(_localctx, 54, smallCParser::RuleVarName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    match(smallCParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrNameContext ------------------------------------------------------------------

smallCParser::ArrNameContext::ArrNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smallCParser::ArrNameContext::ID() {
  return getToken(smallCParser::ID, 0);
}


size_t smallCParser::ArrNameContext::getRuleIndex() const {
  return smallCParser::RuleArrName;
}


antlrcpp::Any smallCParser::ArrNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitArrName(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ArrNameContext* smallCParser::arrName() {
  ArrNameContext *_localctx = _tracker.createInstance<ArrNameContext>(_ctx, getState());
  enterRule(_localctx, 56, smallCParser::RuleArrName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(308);
    match(smallCParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FcnNameContext ------------------------------------------------------------------

smallCParser::FcnNameContext::FcnNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smallCParser::FcnNameContext::ID() {
  return getToken(smallCParser::ID, 0);
}


size_t smallCParser::FcnNameContext::getRuleIndex() const {
  return smallCParser::RuleFcnName;
}


antlrcpp::Any smallCParser::FcnNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitFcnName(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::FcnNameContext* smallCParser::fcnName() {
  FcnNameContext *_localctx = _tracker.createInstance<FcnNameContext>(_ctx, getState());
  enterRule(_localctx, 58, smallCParser::RuleFcnName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(310);
    match(smallCParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolConstContext ------------------------------------------------------------------

smallCParser::BoolConstContext::BoolConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smallCParser::BoolConstContext::BOOL() {
  return getToken(smallCParser::BOOL, 0);
}


size_t smallCParser::BoolConstContext::getRuleIndex() const {
  return smallCParser::RuleBoolConst;
}


antlrcpp::Any smallCParser::BoolConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitBoolConst(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::BoolConstContext* smallCParser::boolConst() {
  BoolConstContext *_localctx = _tracker.createInstance<BoolConstContext>(_ctx, getState());
  enterRule(_localctx, 60, smallCParser::RuleBoolConst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(312);
    match(smallCParser::BOOL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntConstContext ------------------------------------------------------------------

smallCParser::IntConstContext::IntConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smallCParser::IntConstContext::INT() {
  return getToken(smallCParser::INT, 0);
}


size_t smallCParser::IntConstContext::getRuleIndex() const {
  return smallCParser::RuleIntConst;
}


antlrcpp::Any smallCParser::IntConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitIntConst(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::IntConstContext* smallCParser::intConst() {
  IntConstContext *_localctx = _tracker.createInstance<IntConstContext>(_ctx, getState());
  enterRule(_localctx, 62, smallCParser::RuleIntConst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(317);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(314);
        match(smallCParser::INT);
        break;
      }

      case smallCParser::T__18: {
        enterOuterAlt(_localctx, 2);
        setState(315);
        match(smallCParser::T__18);
        setState(316);
        match(smallCParser::INT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool smallCParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 18: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);
    case 19: return intExprSempred(dynamic_cast<IntExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool smallCParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 8);
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 4);
    case 5: return precpred(_ctx, 3);
    case 6: return precpred(_ctx, 2);
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool smallCParser::intExprSempred(IntExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 5);
    case 9: return precpred(_ctx, 4);
    case 10: return precpred(_ctx, 3);
    case 11: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> smallCParser::_decisionToDFA;
atn::PredictionContextCache smallCParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN smallCParser::_atn;
std::vector<uint16_t> smallCParser::_serializedATN;

std::vector<std::string> smallCParser::_ruleNames = {
  "program", "preamble", "decls", "scalarDeclList", "scalarDecl", "arrDeclList", 
  "arrDecl", "fcnProto", "fcnDecl", "varType", "retType", "constant", "scope", 
  "stmt", "assignStmt", "ifStmt", "whileStmt", "retStmt", "expr", "intExpr", 
  "var", "params", "paramEntry", "paramList", "args", "argEntry", "argList", 
  "varName", "arrName", "fcnName", "boolConst", "intConst"
};

std::vector<std::string> smallCParser::_literalNames = {
  "", "'#include'", "'\"scio.h\"'", "';'", "'['", "']'", "'('", "')'", "'bool'", 
  "'int'", "'void'", "'{'", "'}'", "'='", "'if'", "'else'", "'while'", "'return'", 
  "'!'", "'-'", "'<'", "'<='", "'>'", "'>='", "'=='", "'!='", "'||'", "'&&'", 
  "'+'", "'*'", "'/'", "'[]'", "','"
};

std::vector<std::string> smallCParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "BOOL", "ID", 
  "INT", "WS", "COMMENT"
};

dfa::Vocabulary smallCParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> smallCParser::_tokenNames;

smallCParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x27, 0x142, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x3, 0x2, 
    0x3, 0x2, 0x5, 0x2, 0x45, 0xa, 0x2, 0x3, 0x2, 0x7, 0x2, 0x48, 0xa, 0x2, 
    0xc, 0x2, 0xe, 0x2, 0x4b, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x56, 
    0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x5c, 0xa, 
    0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x5, 0x7, 0x66, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 
    0x3, 0xc, 0x5, 0xc, 0x81, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x85, 
    0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x8a, 0xa, 0xe, 0xc, 
    0xe, 0xe, 0xe, 0x8d, 0xb, 0xe, 0x3, 0xe, 0x7, 0xe, 0x90, 0xa, 0xe, 0xc, 
    0xe, 0xe, 0xe, 0x93, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 
    0x9f, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x5, 0x11, 0xb4, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0xc2, 0xa, 0x13, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x5, 0x14, 0xd3, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x7, 0x14, 0xed, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0xf0, 0xb, 
    0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x5, 0x15, 0xf9, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0x107, 0xa, 0x15, 0xc, 0x15, 
    0xe, 0x15, 0x10a, 0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x112, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 
    0x5, 0x17, 0x116, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x11f, 0xa, 0x18, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x126, 0xa, 0x19, 
    0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x12a, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x133, 
    0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 
    0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 
    0x140, 0xa, 0x21, 0x3, 0x21, 0x2, 0x4, 0x26, 0x28, 0x22, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 
    0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x2, 0x3, 0x3, 0x2, 0xa, 0xb, 0x2, 0x14d, 
    0x2, 0x44, 0x3, 0x2, 0x2, 0x2, 0x4, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x6, 0x55, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x5b, 0x3, 0x2, 0x2, 0x2, 0xa, 0x5d, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x65, 0x3, 0x2, 0x2, 0x2, 0xe, 0x67, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x12, 0x75, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x7c, 0x3, 0x2, 0x2, 0x2, 0x16, 0x80, 0x3, 0x2, 0x2, 0x2, 0x18, 0x84, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0x86, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x9e, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x20, 0xb3, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x24, 0xc1, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0xd2, 0x3, 0x2, 0x2, 0x2, 0x28, 0xf8, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x111, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x115, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x11e, 0x3, 0x2, 0x2, 0x2, 0x30, 0x125, 0x3, 0x2, 0x2, 0x2, 0x32, 0x129, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x36, 0x132, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x134, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x136, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x138, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x13a, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x42, 0x45, 0x5, 0x4, 0x3, 0x2, 
    0x43, 0x45, 0x3, 0x2, 0x2, 0x2, 0x44, 0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 
    0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0x49, 0x3, 0x2, 0x2, 0x2, 0x46, 0x48, 
    0x5, 0x6, 0x4, 0x2, 0x47, 0x46, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x4c, 0x4d, 0x7, 0x2, 0x2, 0x3, 0x4d, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x4e, 0x4f, 0x7, 0x3, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x4, 0x2, 0x2, 0x50, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x51, 0x56, 0x5, 0x8, 0x5, 0x2, 0x52, 0x56, 
    0x5, 0xc, 0x7, 0x2, 0x53, 0x56, 0x5, 0x10, 0x9, 0x2, 0x54, 0x56, 0x5, 
    0x12, 0xa, 0x2, 0x55, 0x51, 0x3, 0x2, 0x2, 0x2, 0x55, 0x52, 0x3, 0x2, 
    0x2, 0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0x54, 0x3, 0x2, 0x2, 
    0x2, 0x56, 0x7, 0x3, 0x2, 0x2, 0x2, 0x57, 0x5c, 0x5, 0xa, 0x6, 0x2, 
    0x58, 0x59, 0x5, 0xa, 0x6, 0x2, 0x59, 0x5a, 0x5, 0x8, 0x5, 0x2, 0x5a, 
    0x5c, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x57, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x58, 
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x9, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x5, 
    0x14, 0xb, 0x2, 0x5e, 0x5f, 0x5, 0x38, 0x1d, 0x2, 0x5f, 0x60, 0x7, 0x5, 
    0x2, 0x2, 0x60, 0xb, 0x3, 0x2, 0x2, 0x2, 0x61, 0x66, 0x5, 0xe, 0x8, 
    0x2, 0x62, 0x63, 0x5, 0xe, 0x8, 0x2, 0x63, 0x64, 0x5, 0xc, 0x7, 0x2, 
    0x64, 0x66, 0x3, 0x2, 0x2, 0x2, 0x65, 0x61, 0x3, 0x2, 0x2, 0x2, 0x65, 
    0x62, 0x3, 0x2, 0x2, 0x2, 0x66, 0xd, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 
    0x5, 0x14, 0xb, 0x2, 0x68, 0x69, 0x5, 0x3a, 0x1e, 0x2, 0x69, 0x6a, 0x7, 
    0x6, 0x2, 0x2, 0x6a, 0x6b, 0x5, 0x40, 0x21, 0x2, 0x6b, 0x6c, 0x7, 0x7, 
    0x2, 0x2, 0x6c, 0x6d, 0x7, 0x5, 0x2, 0x2, 0x6d, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x6e, 0x6f, 0x5, 0x16, 0xc, 0x2, 0x6f, 0x70, 0x5, 0x3c, 0x1f, 0x2, 
    0x70, 0x71, 0x7, 0x8, 0x2, 0x2, 0x71, 0x72, 0x5, 0x2c, 0x17, 0x2, 0x72, 
    0x73, 0x7, 0x9, 0x2, 0x2, 0x73, 0x74, 0x7, 0x5, 0x2, 0x2, 0x74, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x5, 0x16, 0xc, 0x2, 0x76, 0x77, 0x5, 
    0x3c, 0x1f, 0x2, 0x77, 0x78, 0x7, 0x8, 0x2, 0x2, 0x78, 0x79, 0x5, 0x2c, 
    0x17, 0x2, 0x79, 0x7a, 0x7, 0x9, 0x2, 0x2, 0x7a, 0x7b, 0x5, 0x1a, 0xe, 
    0x2, 0x7b, 0x13, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x9, 0x2, 0x2, 0x2, 
    0x7d, 0x15, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x81, 0x7, 0xc, 0x2, 0x2, 0x7f, 
    0x81, 0x5, 0x14, 0xb, 0x2, 0x80, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7f, 
    0x3, 0x2, 0x2, 0x2, 0x81, 0x17, 0x3, 0x2, 0x2, 0x2, 0x82, 0x85, 0x5, 
    0x3e, 0x20, 0x2, 0x83, 0x85, 0x5, 0x40, 0x21, 0x2, 0x84, 0x82, 0x3, 
    0x2, 0x2, 0x2, 0x84, 0x83, 0x3, 0x2, 0x2, 0x2, 0x85, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x86, 0x8b, 0x7, 0xd, 0x2, 0x2, 0x87, 0x8a, 0x5, 0xa, 0x6, 
    0x2, 0x88, 0x8a, 0x5, 0xe, 0x8, 0x2, 0x89, 0x87, 0x3, 0x2, 0x2, 0x2, 
    0x89, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8b, 
    0x89, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x91, 
    0x3, 0x2, 0x2, 0x2, 0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x90, 0x5, 
    0x1c, 0xf, 0x2, 0x8f, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x90, 0x93, 0x3, 0x2, 
    0x2, 0x2, 0x91, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x3, 0x2, 0x2, 
    0x2, 0x92, 0x94, 0x3, 0x2, 0x2, 0x2, 0x93, 0x91, 0x3, 0x2, 0x2, 0x2, 
    0x94, 0x95, 0x7, 0xe, 0x2, 0x2, 0x95, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x96, 
    0x97, 0x5, 0x26, 0x14, 0x2, 0x97, 0x98, 0x7, 0x5, 0x2, 0x2, 0x98, 0x9f, 
    0x3, 0x2, 0x2, 0x2, 0x99, 0x9f, 0x5, 0x1e, 0x10, 0x2, 0x9a, 0x9f, 0x5, 
    0x20, 0x11, 0x2, 0x9b, 0x9f, 0x5, 0x22, 0x12, 0x2, 0x9c, 0x9f, 0x5, 
    0x24, 0x13, 0x2, 0x9d, 0x9f, 0x5, 0x1a, 0xe, 0x2, 0x9e, 0x96, 0x3, 0x2, 
    0x2, 0x2, 0x9e, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9a, 0x3, 0x2, 0x2, 
    0x2, 0x9e, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 
    0x9e, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xa0, 
    0xa1, 0x5, 0x2a, 0x16, 0x2, 0xa1, 0xa2, 0x7, 0xf, 0x2, 0x2, 0xa2, 0xa3, 
    0x5, 0x26, 0x14, 0x2, 0xa3, 0xa4, 0x7, 0x5, 0x2, 0x2, 0xa4, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0x10, 0x2, 0x2, 0xa6, 0xa7, 0x7, 0x8, 
    0x2, 0x2, 0xa7, 0xa8, 0x5, 0x26, 0x14, 0x2, 0xa8, 0xa9, 0x7, 0x9, 0x2, 
    0x2, 0xa9, 0xaa, 0x5, 0x1c, 0xf, 0x2, 0xaa, 0xb4, 0x3, 0x2, 0x2, 0x2, 
    0xab, 0xac, 0x7, 0x10, 0x2, 0x2, 0xac, 0xad, 0x7, 0x8, 0x2, 0x2, 0xad, 
    0xae, 0x5, 0x26, 0x14, 0x2, 0xae, 0xaf, 0x7, 0x9, 0x2, 0x2, 0xaf, 0xb0, 
    0x5, 0x1c, 0xf, 0x2, 0xb0, 0xb1, 0x7, 0x11, 0x2, 0x2, 0xb1, 0xb2, 0x5, 
    0x1c, 0xf, 0x2, 0xb2, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xa5, 0x3, 0x2, 
    0x2, 0x2, 0xb3, 0xab, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0xb5, 0xb6, 0x7, 0x12, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0x8, 0x2, 0x2, 
    0xb7, 0xb8, 0x5, 0x26, 0x14, 0x2, 0xb8, 0xb9, 0x7, 0x9, 0x2, 0x2, 0xb9, 
    0xba, 0x5, 0x1c, 0xf, 0x2, 0xba, 0x23, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 
    0x7, 0x13, 0x2, 0x2, 0xbc, 0xc2, 0x7, 0x5, 0x2, 0x2, 0xbd, 0xbe, 0x7, 
    0x13, 0x2, 0x2, 0xbe, 0xbf, 0x5, 0x26, 0x14, 0x2, 0xbf, 0xc0, 0x7, 0x5, 
    0x2, 0x2, 0xc0, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xbb, 0x3, 0x2, 0x2, 
    0x2, 0xc1, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc2, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0xc3, 0xc4, 0x8, 0x14, 0x1, 0x2, 0xc4, 0xd3, 0x5, 0x28, 0x15, 0x2, 0xc5, 
    0xc6, 0x7, 0x8, 0x2, 0x2, 0xc6, 0xc7, 0x5, 0x26, 0x14, 0x2, 0xc7, 0xc8, 
    0x7, 0x9, 0x2, 0x2, 0xc8, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x5, 
    0x3c, 0x1f, 0x2, 0xca, 0xcb, 0x7, 0x8, 0x2, 0x2, 0xcb, 0xcc, 0x5, 0x32, 
    0x1a, 0x2, 0xcc, 0xcd, 0x7, 0x9, 0x2, 0x2, 0xcd, 0xd3, 0x3, 0x2, 0x2, 
    0x2, 0xce, 0xcf, 0x7, 0x14, 0x2, 0x2, 0xcf, 0xd3, 0x5, 0x26, 0x14, 0xc, 
    0xd0, 0xd1, 0x7, 0x15, 0x2, 0x2, 0xd1, 0xd3, 0x5, 0x26, 0x14, 0xb, 0xd2, 
    0xc3, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xc9, 
    0x3, 0x2, 0x2, 0x2, 0xd2, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd0, 0x3, 
    0x2, 0x2, 0x2, 0xd3, 0xee, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0xc, 0xa, 
    0x2, 0x2, 0xd5, 0xd6, 0x7, 0x16, 0x2, 0x2, 0xd6, 0xed, 0x5, 0x26, 0x14, 
    0xb, 0xd7, 0xd8, 0xc, 0x9, 0x2, 0x2, 0xd8, 0xd9, 0x7, 0x17, 0x2, 0x2, 
    0xd9, 0xed, 0x5, 0x26, 0x14, 0xa, 0xda, 0xdb, 0xc, 0x8, 0x2, 0x2, 0xdb, 
    0xdc, 0x7, 0x18, 0x2, 0x2, 0xdc, 0xed, 0x5, 0x26, 0x14, 0x9, 0xdd, 0xde, 
    0xc, 0x7, 0x2, 0x2, 0xde, 0xdf, 0x7, 0x19, 0x2, 0x2, 0xdf, 0xed, 0x5, 
    0x26, 0x14, 0x8, 0xe0, 0xe1, 0xc, 0x6, 0x2, 0x2, 0xe1, 0xe2, 0x7, 0x1a, 
    0x2, 0x2, 0xe2, 0xed, 0x5, 0x26, 0x14, 0x7, 0xe3, 0xe4, 0xc, 0x5, 0x2, 
    0x2, 0xe4, 0xe5, 0x7, 0x1b, 0x2, 0x2, 0xe5, 0xed, 0x5, 0x26, 0x14, 0x6, 
    0xe6, 0xe7, 0xc, 0x4, 0x2, 0x2, 0xe7, 0xe8, 0x7, 0x1c, 0x2, 0x2, 0xe8, 
    0xed, 0x5, 0x26, 0x14, 0x5, 0xe9, 0xea, 0xc, 0x3, 0x2, 0x2, 0xea, 0xeb, 
    0x7, 0x1d, 0x2, 0x2, 0xeb, 0xed, 0x5, 0x26, 0x14, 0x4, 0xec, 0xd4, 0x3, 
    0x2, 0x2, 0x2, 0xec, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xec, 0xda, 0x3, 0x2, 
    0x2, 0x2, 0xec, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xec, 0xe0, 0x3, 0x2, 0x2, 
    0x2, 0xec, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xec, 0xe6, 0x3, 0x2, 0x2, 0x2, 
    0xec, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xed, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xee, 
    0xec, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x3, 0x2, 0x2, 0x2, 0xef, 0x27, 
    0x3, 0x2, 0x2, 0x2, 0xf0, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x8, 
    0x15, 0x1, 0x2, 0xf2, 0xf9, 0x5, 0x18, 0xd, 0x2, 0xf3, 0xf9, 0x5, 0x2a, 
    0x16, 0x2, 0xf4, 0xf5, 0x7, 0x8, 0x2, 0x2, 0xf5, 0xf6, 0x5, 0x28, 0x15, 
    0x2, 0xf6, 0xf7, 0x7, 0x9, 0x2, 0x2, 0xf7, 0xf9, 0x3, 0x2, 0x2, 0x2, 
    0xf8, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf8, 
    0xf4, 0x3, 0x2, 0x2, 0x2, 0xf9, 0x108, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 
    0xc, 0x7, 0x2, 0x2, 0xfb, 0xfc, 0x7, 0x1e, 0x2, 0x2, 0xfc, 0x107, 0x5, 
    0x28, 0x15, 0x8, 0xfd, 0xfe, 0xc, 0x6, 0x2, 0x2, 0xfe, 0xff, 0x7, 0x15, 
    0x2, 0x2, 0xff, 0x107, 0x5, 0x28, 0x15, 0x7, 0x100, 0x101, 0xc, 0x5, 
    0x2, 0x2, 0x101, 0x102, 0x7, 0x1f, 0x2, 0x2, 0x102, 0x107, 0x5, 0x28, 
    0x15, 0x6, 0x103, 0x104, 0xc, 0x4, 0x2, 0x2, 0x104, 0x105, 0x7, 0x20, 
    0x2, 0x2, 0x105, 0x107, 0x5, 0x28, 0x15, 0x5, 0x106, 0xfa, 0x3, 0x2, 
    0x2, 0x2, 0x106, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x106, 0x100, 0x3, 0x2, 0x2, 
    0x2, 0x106, 0x103, 0x3, 0x2, 0x2, 0x2, 0x107, 0x10a, 0x3, 0x2, 0x2, 
    0x2, 0x108, 0x106, 0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 0x3, 0x2, 0x2, 
    0x2, 0x109, 0x29, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x108, 0x3, 0x2, 0x2, 0x2, 
    0x10b, 0x112, 0x5, 0x38, 0x1d, 0x2, 0x10c, 0x10d, 0x5, 0x3a, 0x1e, 0x2, 
    0x10d, 0x10e, 0x7, 0x6, 0x2, 0x2, 0x10e, 0x10f, 0x5, 0x28, 0x15, 0x2, 
    0x10f, 0x110, 0x7, 0x7, 0x2, 0x2, 0x110, 0x112, 0x3, 0x2, 0x2, 0x2, 
    0x111, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x111, 0x10c, 0x3, 0x2, 0x2, 0x2, 
    0x112, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x113, 0x116, 0x5, 0x30, 0x19, 0x2, 
    0x114, 0x116, 0x3, 0x2, 0x2, 0x2, 0x115, 0x113, 0x3, 0x2, 0x2, 0x2, 
    0x115, 0x114, 0x3, 0x2, 0x2, 0x2, 0x116, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x117, 
    0x118, 0x5, 0x14, 0xb, 0x2, 0x118, 0x119, 0x5, 0x38, 0x1d, 0x2, 0x119, 
    0x11f, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 0x5, 0x14, 0xb, 0x2, 0x11b, 
    0x11c, 0x5, 0x3a, 0x1e, 0x2, 0x11c, 0x11d, 0x7, 0x21, 0x2, 0x2, 0x11d, 
    0x11f, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x117, 0x3, 0x2, 0x2, 0x2, 0x11e, 
    0x11a, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x120, 0x126, 
    0x5, 0x2e, 0x18, 0x2, 0x121, 0x122, 0x5, 0x2e, 0x18, 0x2, 0x122, 0x123, 
    0x7, 0x22, 0x2, 0x2, 0x123, 0x124, 0x5, 0x30, 0x19, 0x2, 0x124, 0x126, 
    0x3, 0x2, 0x2, 0x2, 0x125, 0x120, 0x3, 0x2, 0x2, 0x2, 0x125, 0x121, 
    0x3, 0x2, 0x2, 0x2, 0x126, 0x31, 0x3, 0x2, 0x2, 0x2, 0x127, 0x12a, 0x5, 
    0x36, 0x1c, 0x2, 0x128, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x129, 0x127, 0x3, 
    0x2, 0x2, 0x2, 0x129, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0x12b, 0x12c, 0x5, 0x26, 0x14, 0x2, 0x12c, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x12d, 0x133, 0x5, 0x34, 0x1b, 0x2, 0x12e, 0x12f, 0x5, 0x34, 
    0x1b, 0x2, 0x12f, 0x130, 0x7, 0x22, 0x2, 0x2, 0x130, 0x131, 0x5, 0x36, 
    0x1c, 0x2, 0x131, 0x133, 0x3, 0x2, 0x2, 0x2, 0x132, 0x12d, 0x3, 0x2, 
    0x2, 0x2, 0x132, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x133, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x134, 0x135, 0x7, 0x24, 0x2, 0x2, 0x135, 0x39, 0x3, 0x2, 0x2, 
    0x2, 0x136, 0x137, 0x7, 0x24, 0x2, 0x2, 0x137, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x138, 0x139, 0x7, 0x24, 0x2, 0x2, 0x139, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x13a, 0x13b, 0x7, 0x23, 0x2, 0x2, 0x13b, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x13c, 0x140, 0x7, 0x25, 0x2, 0x2, 0x13d, 0x13e, 0x7, 0x15, 0x2, 
    0x2, 0x13e, 0x140, 0x7, 0x25, 0x2, 0x2, 0x13f, 0x13c, 0x3, 0x2, 0x2, 
    0x2, 0x13f, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x140, 0x41, 0x3, 0x2, 0x2, 0x2, 
    0x1c, 0x44, 0x49, 0x55, 0x5b, 0x65, 0x80, 0x84, 0x89, 0x8b, 0x91, 0x9e, 
    0xb3, 0xc1, 0xd2, 0xec, 0xee, 0xf8, 0x106, 0x108, 0x111, 0x115, 0x11e, 
    0x125, 0x129, 0x132, 0x13f, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

smallCParser::Initializer smallCParser::_init;
