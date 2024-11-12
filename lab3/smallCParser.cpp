
#include "ASTNodes.h"
#include <iostream>
#include <string>


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

      dynamic_cast<ProgramContext *>(_localctx)->prg =  new smallc::ProgramNode();
      _localctx->prg->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(72);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::T__0: {
        setState(68);
        preamble();
        _localctx->prg->setIo(true);
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
    setState(79);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << smallCParser::T__7)
      | (1ULL << smallCParser::T__8)
      | (1ULL << smallCParser::T__9))) != 0)) {
      setState(74);
      dynamic_cast<ProgramContext *>(_localctx)->declsContext = decls();

         for(unsigned int i = 0; i < dynamic_cast<ProgramContext *>(_localctx)->declsContext->declarations.size();i++)
         {
          _localctx->prg->addChild(dynamic_cast<ProgramContext *>(_localctx)->declsContext->declarations[i]);
          dynamic_cast<ProgramContext *>(_localctx)->declsContext->declarations[i]->setParent(_localctx->prg);
         }

      setState(81);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(82);
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
    setState(84);
    match(smallCParser::T__0);
    setState(85);
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

smallCParser::FcnProtoListContext* smallCParser::DeclsContext::fcnProtoList() {
  return getRuleContext<smallCParser::FcnProtoListContext>(0);
}

smallCParser::FcnDeclListContext* smallCParser::DeclsContext::fcnDeclList() {
  return getRuleContext<smallCParser::FcnDeclListContext>(0);
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

      dynamic_cast<DeclsContext *>(_localctx)->declarations =  std::vector<smallc::DeclNode*>();


  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(99);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(87);
      dynamic_cast<DeclsContext *>(_localctx)->scalarDeclListContext = scalarDeclList();
       
              for(unsigned int i = 0; i < dynamic_cast<DeclsContext *>(_localctx)->scalarDeclListContext->scalars.size(); i++) {
                  _localctx->declarations.push_back(dynamic_cast<DeclsContext *>(_localctx)->scalarDeclListContext->scalars[i]);
              }
             
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(90);
      dynamic_cast<DeclsContext *>(_localctx)->arrDeclListContext = arrDeclList();
       
              for(unsigned int i = 0; i < dynamic_cast<DeclsContext *>(_localctx)->arrDeclListContext->arrays.size(); i++) {
                  _localctx->declarations.push_back(dynamic_cast<DeclsContext *>(_localctx)->arrDeclListContext->arrays[i]);
              }
             
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(93);
      dynamic_cast<DeclsContext *>(_localctx)->fcnProtoListContext = fcnProtoList();
       
              for(unsigned int i = 0; i < dynamic_cast<DeclsContext *>(_localctx)->fcnProtoListContext->prototypes.size(); i++) {
                  _localctx->declarations.push_back(dynamic_cast<DeclsContext *>(_localctx)->fcnProtoListContext->prototypes[i]);
              }
             
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(96);
      dynamic_cast<DeclsContext *>(_localctx)->fcnDeclListContext = fcnDeclList();
       
              for(unsigned int i = 0; i < dynamic_cast<DeclsContext *>(_localctx)->fcnDeclListContext->declarations.size(); i++) {
                  _localctx->declarations.push_back(dynamic_cast<DeclsContext *>(_localctx)->fcnDeclListContext->declarations[i]);
              }
             
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
    setState(108);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(101);
      dynamic_cast<ScalarDeclListContext *>(_localctx)->scalarDeclContext = scalarDecl();
       _localctx->scalars.push_back(dynamic_cast<ScalarDeclListContext *>(_localctx)->scalarDeclContext->decl); 
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(104);
      dynamic_cast<ScalarDeclListContext *>(_localctx)->scalarDeclContext = scalarDecl();
      setState(105);
      dynamic_cast<ScalarDeclListContext *>(_localctx)->scalarDeclListContext = scalarDeclList();

                _localctx->scalars.push_back(dynamic_cast<ScalarDeclListContext *>(_localctx)->scalarDeclContext->decl);
                for (unsigned int i = 0; i < dynamic_cast<ScalarDeclListContext *>(_localctx)->scalarDeclListContext->scalars.size(); i++) {
                    _localctx->scalars.push_back(dynamic_cast<ScalarDeclListContext *>(_localctx)->scalarDeclListContext->scalars[i]);
                }
            
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
    setState(110);
    dynamic_cast<ScalarDeclContext *>(_localctx)->t = varType();
    setState(111);
    dynamic_cast<ScalarDeclContext *>(_localctx)->v = varName();
    setState(112);
    match(smallCParser::T__2);
       
            dynamic_cast<ScalarDeclContext *>(_localctx)->decl =  new smallc::ScalarDeclNode(dynamic_cast<ScalarDeclContext *>(_localctx)->t->type, dynamic_cast<ScalarDeclContext *>(_localctx)->v->node);
            _localctx->decl->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
        
   
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
    setState(122);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(115);
      dynamic_cast<ArrDeclListContext *>(_localctx)->arrDeclContext = arrDecl();
       _localctx->arrays.push_back(dynamic_cast<ArrDeclListContext *>(_localctx)->arrDeclContext->decl); 
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(118);
      dynamic_cast<ArrDeclListContext *>(_localctx)->arrDeclContext = arrDecl();
      setState(119);
      dynamic_cast<ArrDeclListContext *>(_localctx)->arrDeclListContext = arrDeclList();

                _localctx->arrays.push_back(dynamic_cast<ArrDeclListContext *>(_localctx)->arrDeclContext->decl);
                for (unsigned int i = 0; i < dynamic_cast<ArrDeclListContext *>(_localctx)->arrDeclListContext->arrays.size(); i++) {
                    _localctx->arrays.push_back(dynamic_cast<ArrDeclListContext *>(_localctx)->arrDeclListContext->arrays[i]);
                }
            
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

      dynamic_cast<ArrDeclContext *>(_localctx)->decl =  nullptr;


  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    dynamic_cast<ArrDeclContext *>(_localctx)->t = varType();
    setState(125);
    dynamic_cast<ArrDeclContext *>(_localctx)->n = arrName();
    setState(126);
    match(smallCParser::T__3);
    setState(127);
    dynamic_cast<ArrDeclContext *>(_localctx)->size = intConst();
    setState(128);
    match(smallCParser::T__4);
    setState(129);
    match(smallCParser::T__2);

            smallc::ArrayTypeNode* type = new smallc::ArrayTypeNode(dynamic_cast<ArrDeclContext *>(_localctx)->t->type, dynamic_cast<ArrDeclContext *>(_localctx)->size->node->getVal());
            dynamic_cast<ArrDeclContext *>(_localctx)->decl =  new smallc::ArrayDeclNode(type, dynamic_cast<ArrDeclContext *>(_localctx)->n->node);
            _localctx->decl->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FcnProtoListContext ------------------------------------------------------------------

smallCParser::FcnProtoListContext::FcnProtoListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::FcnProtoContext* smallCParser::FcnProtoListContext::fcnProto() {
  return getRuleContext<smallCParser::FcnProtoContext>(0);
}

smallCParser::FcnProtoListContext* smallCParser::FcnProtoListContext::fcnProtoList() {
  return getRuleContext<smallCParser::FcnProtoListContext>(0);
}


size_t smallCParser::FcnProtoListContext::getRuleIndex() const {
  return smallCParser::RuleFcnProtoList;
}


antlrcpp::Any smallCParser::FcnProtoListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitFcnProtoList(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::FcnProtoListContext* smallCParser::fcnProtoList() {
  FcnProtoListContext *_localctx = _tracker.createInstance<FcnProtoListContext>(_ctx, getState());
  enterRule(_localctx, 14, smallCParser::RuleFcnProtoList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(139);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(132);
      dynamic_cast<FcnProtoListContext *>(_localctx)->fcnProtoContext = fcnProto();
       _localctx->prototypes.push_back(dynamic_cast<FcnProtoListContext *>(_localctx)->fcnProtoContext->proto); 
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(135);
      dynamic_cast<FcnProtoListContext *>(_localctx)->fcnProtoContext = fcnProto();
      setState(136);
      dynamic_cast<FcnProtoListContext *>(_localctx)->fcnProtoListContext = fcnProtoList();

                _localctx->prototypes.push_back(dynamic_cast<FcnProtoListContext *>(_localctx)->fcnProtoContext->proto);
                for (unsigned int i = 0; i < dynamic_cast<FcnProtoListContext *>(_localctx)->fcnProtoListContext->prototypes.size(); i++) {
                    _localctx->prototypes.push_back(dynamic_cast<FcnProtoListContext *>(_localctx)->fcnProtoListContext->prototypes[i]);
                }
            
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
  enterRule(_localctx, 16, smallCParser::RuleFcnProto);

      dynamic_cast<FcnProtoContext *>(_localctx)->proto =  new smallc::FunctionDeclNode();
      _localctx->proto->setProto(true);
      _localctx->proto->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());


  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    dynamic_cast<FcnProtoContext *>(_localctx)->t = retType();
    setState(142);
    dynamic_cast<FcnProtoContext *>(_localctx)->n = fcnName();
    setState(143);
    match(smallCParser::T__5);
    setState(144);
    dynamic_cast<FcnProtoContext *>(_localctx)->p = params();
    setState(145);
    match(smallCParser::T__6);
    setState(146);
    match(smallCParser::T__2);

            _localctx->proto->setRetType(dynamic_cast<FcnProtoContext *>(_localctx)->t->type);
            _localctx->proto->setName(dynamic_cast<FcnProtoContext *>(_localctx)->n->node);
            for(auto param : dynamic_cast<FcnProtoContext *>(_localctx)->p->parameters) {
                _localctx->proto->addParameter(param);
            }
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FcnDeclListContext ------------------------------------------------------------------

smallCParser::FcnDeclListContext::FcnDeclListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::FcnDeclContext* smallCParser::FcnDeclListContext::fcnDecl() {
  return getRuleContext<smallCParser::FcnDeclContext>(0);
}

smallCParser::FcnDeclListContext* smallCParser::FcnDeclListContext::fcnDeclList() {
  return getRuleContext<smallCParser::FcnDeclListContext>(0);
}


size_t smallCParser::FcnDeclListContext::getRuleIndex() const {
  return smallCParser::RuleFcnDeclList;
}


antlrcpp::Any smallCParser::FcnDeclListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitFcnDeclList(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::FcnDeclListContext* smallCParser::fcnDeclList() {
  FcnDeclListContext *_localctx = _tracker.createInstance<FcnDeclListContext>(_ctx, getState());
  enterRule(_localctx, 18, smallCParser::RuleFcnDeclList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(156);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(149);
      dynamic_cast<FcnDeclListContext *>(_localctx)->fcnDeclContext = fcnDecl();
       _localctx->declarations.push_back(dynamic_cast<FcnDeclListContext *>(_localctx)->fcnDeclContext->declaration); 
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(152);
      dynamic_cast<FcnDeclListContext *>(_localctx)->fcnDeclContext = fcnDecl();
      setState(153);
      dynamic_cast<FcnDeclListContext *>(_localctx)->fcnDeclListContext = fcnDeclList();

                _localctx->declarations.push_back(dynamic_cast<FcnDeclListContext *>(_localctx)->fcnDeclContext->declaration);
                for (unsigned int i = 0; i < dynamic_cast<FcnDeclListContext *>(_localctx)->fcnDeclListContext->declarations.size(); i++) {
                    _localctx->declarations.push_back(dynamic_cast<FcnDeclListContext *>(_localctx)->fcnDeclListContext->declarations[i]);
                }
            
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
  enterRule(_localctx, 20, smallCParser::RuleFcnDecl);

      dynamic_cast<FcnDeclContext *>(_localctx)->declaration =  new smallc::FunctionDeclNode();
      _localctx->declaration->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());


  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(158);
    dynamic_cast<FcnDeclContext *>(_localctx)->t = retType();
    setState(159);
    dynamic_cast<FcnDeclContext *>(_localctx)->n = fcnName();
    setState(160);
    match(smallCParser::T__5);
    setState(161);
    dynamic_cast<FcnDeclContext *>(_localctx)->p = params();
    setState(162);
    match(smallCParser::T__6);
    setState(163);
    dynamic_cast<FcnDeclContext *>(_localctx)->s = scope();

            _localctx->declaration->setRetType(dynamic_cast<FcnDeclContext *>(_localctx)->t->type);
            _localctx->declaration->setName(dynamic_cast<FcnDeclContext *>(_localctx)->n->node);
            for(auto param : dynamic_cast<FcnDeclContext *>(_localctx)->p->parameters) {
                _localctx->declaration->addParameter(param);
            }
            _localctx->declaration->setBody(dynamic_cast<FcnDeclContext *>(_localctx)->s->scope_);
        
   
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
  enterRule(_localctx, 22, smallCParser::RuleVarType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(170);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::T__7: {
        enterOuterAlt(_localctx, 1);
        setState(166);
        match(smallCParser::T__7);

                dynamic_cast<VarTypeContext *>(_localctx)->type =  new smallc::PrimitiveTypeNode(smallc::TypeNode::Bool);
                _localctx->type->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            
        break;
      }

      case smallCParser::T__8: {
        enterOuterAlt(_localctx, 2);
        setState(168);
        match(smallCParser::T__8);

                dynamic_cast<VarTypeContext *>(_localctx)->type =  new smallc::PrimitiveTypeNode(smallc::TypeNode::Int);
                _localctx->type->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            
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
  enterRule(_localctx, 24, smallCParser::RuleRetType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(177);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::T__9: {
        enterOuterAlt(_localctx, 1);
        setState(172);
        match(smallCParser::T__9);

                dynamic_cast<RetTypeContext *>(_localctx)->type =  new smallc::PrimitiveTypeNode(smallc::TypeNode::Void);
                _localctx->type->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            
        break;
      }

      case smallCParser::T__7:
      case smallCParser::T__8: {
        enterOuterAlt(_localctx, 2);
        setState(174);
        dynamic_cast<RetTypeContext *>(_localctx)->varTypeContext = varType();

                dynamic_cast<RetTypeContext *>(_localctx)->type =  dynamic_cast<RetTypeContext *>(_localctx)->varTypeContext->type;
            
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
  enterRule(_localctx, 26, smallCParser::RuleConstant);

      dynamic_cast<ConstantContext *>(_localctx)->node =  nullptr;
      // _localctx->node->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine()); // This is Unnecessary since defined before


  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(185);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::BOOL: {
        enterOuterAlt(_localctx, 1);
        setState(179);
        dynamic_cast<ConstantContext *>(_localctx)->boolConstContext = boolConst();
         
                dynamic_cast<ConstantContext *>(_localctx)->node =  dynamic_cast<ConstantContext *>(_localctx)->boolConstContext->node;
            
        break;
      }

      case smallCParser::T__18:
      case smallCParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(182);
        dynamic_cast<ConstantContext *>(_localctx)->intConstContext = intConst();
         
                dynamic_cast<ConstantContext *>(_localctx)->node =  dynamic_cast<ConstantContext *>(_localctx)->intConstContext->node;
            
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
  enterRule(_localctx, 28, smallCParser::RuleBoolConst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(187);
    dynamic_cast<BoolConstContext *>(_localctx)->b = match(smallCParser::BOOL);

            dynamic_cast<BoolConstContext *>(_localctx)->node =  new smallc::BoolConstantNode((dynamic_cast<BoolConstContext *>(_localctx)->b != nullptr ? dynamic_cast<BoolConstContext *>(_localctx)->b->getText() : ""));
            _localctx->node->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
        
   
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
  enterRule(_localctx, 30, smallCParser::RuleScope);

      dynamic_cast<ScopeContext *>(_localctx)->scope_ =  new smallc::ScopeNode();
      _localctx->scope_->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(190);
    match(smallCParser::T__10);
    setState(199);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == smallCParser::T__7

    || _la == smallCParser::T__8) {
      setState(197);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
      case 1: {
        setState(191);
        dynamic_cast<ScopeContext *>(_localctx)->scalarDeclContext = scalarDecl();
        _localctx->scope_->addDeclaration(dynamic_cast<ScopeContext *>(_localctx)->scalarDeclContext->decl);
        break;
      }

      case 2: {
        setState(194);
        dynamic_cast<ScopeContext *>(_localctx)->arrDeclContext = arrDecl();
        _localctx->scope_->addDeclaration(dynamic_cast<ScopeContext *>(_localctx)->arrDeclContext->decl);
        break;
      }

      }
      setState(201);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(207);
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
      setState(202);
      dynamic_cast<ScopeContext *>(_localctx)->stmtContext = stmt();
      _localctx->scope_->addChild(dynamic_cast<ScopeContext *>(_localctx)->stmtContext->statement);
      setState(209);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(210);
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
  enterRule(_localctx, 32, smallCParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(231);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(212);
      dynamic_cast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(213);
      match(smallCParser::T__2);

              dynamic_cast<StmtContext *>(_localctx)->statement =  new smallc::ExprStmtNode(dynamic_cast<StmtContext *>(_localctx)->exprContext->node);
              _localctx->statement->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(216);
      dynamic_cast<StmtContext *>(_localctx)->assignStmtContext = assignStmt();

              dynamic_cast<StmtContext *>(_localctx)->statement =  dynamic_cast<StmtContext *>(_localctx)->assignStmtContext->assignment;
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(219);
      dynamic_cast<StmtContext *>(_localctx)->ifStmtContext = ifStmt();

              dynamic_cast<StmtContext *>(_localctx)->statement =  dynamic_cast<StmtContext *>(_localctx)->ifStmtContext->ifNode;
          
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(222);
      dynamic_cast<StmtContext *>(_localctx)->whileStmtContext = whileStmt();

              dynamic_cast<StmtContext *>(_localctx)->statement =  dynamic_cast<StmtContext *>(_localctx)->whileStmtContext->whileNode;
          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(225);
      dynamic_cast<StmtContext *>(_localctx)->retStmtContext = retStmt();

              dynamic_cast<StmtContext *>(_localctx)->statement =  dynamic_cast<StmtContext *>(_localctx)->retStmtContext->returnNode;
          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(228);
      dynamic_cast<StmtContext *>(_localctx)->scopeContext = scope();

              dynamic_cast<StmtContext *>(_localctx)->statement =  dynamic_cast<StmtContext *>(_localctx)->scopeContext->scope_;
          
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
  enterRule(_localctx, 34, smallCParser::RuleAssignStmt);

      dynamic_cast<AssignStmtContext *>(_localctx)->assignment =  new smallc::AssignStmtNode();
      _localctx->assignment->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());


  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(233);
    dynamic_cast<AssignStmtContext *>(_localctx)->varContext = var();
    setState(234);
    match(smallCParser::T__12);
    setState(235);
    dynamic_cast<AssignStmtContext *>(_localctx)->exprContext = expr(0);
    setState(236);
    match(smallCParser::T__2);

            _localctx->assignment->setTarget(dynamic_cast<AssignStmtContext *>(_localctx)->varContext->node);
            _localctx->assignment->setValue(dynamic_cast<AssignStmtContext *>(_localctx)->exprContext->node);
        
   
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
  enterRule(_localctx, 36, smallCParser::RuleIfStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(255);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(239);
      match(smallCParser::T__13);
      setState(240);
      match(smallCParser::T__5);
      setState(241);
      dynamic_cast<IfStmtContext *>(_localctx)->cond = expr(0);
      setState(242);
      match(smallCParser::T__6);
      setState(243);
      dynamic_cast<IfStmtContext *>(_localctx)->then = stmt();

              dynamic_cast<IfStmtContext *>(_localctx)->ifNode =  new smallc::IfStmtNode(dynamic_cast<IfStmtContext *>(_localctx)->cond->node, dynamic_cast<IfStmtContext *>(_localctx)->then->statement);
              _localctx->ifNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(246);
      match(smallCParser::T__13);
      setState(247);
      match(smallCParser::T__5);
      setState(248);
      dynamic_cast<IfStmtContext *>(_localctx)->cond = expr(0);
      setState(249);
      match(smallCParser::T__6);
      setState(250);
      dynamic_cast<IfStmtContext *>(_localctx)->then = stmt();
      setState(251);
      match(smallCParser::T__14);
      setState(252);
      dynamic_cast<IfStmtContext *>(_localctx)->else_ = stmt();

              dynamic_cast<IfStmtContext *>(_localctx)->ifNode =  new smallc::IfStmtNode(dynamic_cast<IfStmtContext *>(_localctx)->cond->node, dynamic_cast<IfStmtContext *>(_localctx)->then->statement, dynamic_cast<IfStmtContext *>(_localctx)->else_->statement);
              _localctx->ifNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->ifNode->setHasElse(true);
          
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
  enterRule(_localctx, 38, smallCParser::RuleWhileStmt);

      dynamic_cast<WhileStmtContext *>(_localctx)->whileNode =  new smallc::WhileStmtNode();
      _localctx->whileNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());


  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    match(smallCParser::T__15);
    setState(258);
    match(smallCParser::T__5);
    setState(259);
    dynamic_cast<WhileStmtContext *>(_localctx)->cond = expr(0);
    setState(260);
    match(smallCParser::T__6);
    setState(261);
    dynamic_cast<WhileStmtContext *>(_localctx)->body = stmt();

            _localctx->whileNode->setCondition(dynamic_cast<WhileStmtContext *>(_localctx)->cond->node);
            _localctx->whileNode->setBody(dynamic_cast<WhileStmtContext *>(_localctx)->body->statement);
        
   
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
  enterRule(_localctx, 40, smallCParser::RuleRetStmt);

      dynamic_cast<RetStmtContext *>(_localctx)->returnNode =  new smallc::ReturnStmtNode();
      _localctx->returnNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());


  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(272);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(264);
      match(smallCParser::T__16);
      setState(265);
      dynamic_cast<RetStmtContext *>(_localctx)->val = expr(0);
      setState(266);
      match(smallCParser::T__2);

              _localctx->returnNode->setReturn(dynamic_cast<RetStmtContext *>(_localctx)->val->node);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(269);
      match(smallCParser::T__16);
      setState(270);
      match(smallCParser::T__2);

              // Empty return - the constructor already creates a void return
          
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

smallCParser::ArgsContext* smallCParser::ExprContext::args() {
  return getRuleContext<smallCParser::ArgsContext>(0);
}

smallCParser::FcnNameContext* smallCParser::ExprContext::fcnName() {
  return getRuleContext<smallCParser::FcnNameContext>(0);
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
  size_t startState = 42;
  enterRecursionRule(_localctx, 42, smallCParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(293);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(275);
      dynamic_cast<ExprContext *>(_localctx)->intExprContext = intExpr(0);
       
              dynamic_cast<ExprContext *>(_localctx)->node =  dynamic_cast<ExprContext *>(_localctx)->intExprContext->exprNode; 
          
      break;
    }

    case 2: {
      setState(278);
      match(smallCParser::T__5);
      setState(279);
      dynamic_cast<ExprContext *>(_localctx)->e = expr(0);
      setState(280);
      match(smallCParser::T__6);
       
              dynamic_cast<ExprContext *>(_localctx)->node =  dynamic_cast<ExprContext *>(_localctx)->e->node;
          
      break;
    }

    case 3: {
      setState(283);
      dynamic_cast<ExprContext *>(_localctx)->n = fcnName();
      setState(284);
      match(smallCParser::T__5);
      setState(285);
      dynamic_cast<ExprContext *>(_localctx)->argsContext = args();
      setState(286);
      match(smallCParser::T__6);

              smallc::CallExprNode* call = new smallc::CallExprNode(dynamic_cast<ExprContext *>(_localctx)->n->node);
              for(auto arg : dynamic_cast<ExprContext *>(_localctx)->argsContext->arguments) {
                  call->addArgument(arg);
              }
              call->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              dynamic_cast<ExprContext *>(_localctx)->node =  call;
          
      break;
    }

    case 4: {
      setState(289);
      dynamic_cast<ExprContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == smallCParser::T__17

      || _la == smallCParser::T__18)) {
        dynamic_cast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(290);
      dynamic_cast<ExprContext *>(_localctx)->e = expr(5);

              smallc::UnaryExprNode* unary = new smallc::UnaryExprNode(dynamic_cast<ExprContext *>(_localctx)->e->node);
              unary->setOpcode((dynamic_cast<ExprContext *>(_localctx)->op != nullptr ? dynamic_cast<ExprContext *>(_localctx)->op->getText() : ""));
              unary->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              dynamic_cast<ExprContext *>(_localctx)->node =  unary;
          
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(317);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(315);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->l = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(295);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(296);
          dynamic_cast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << smallCParser::T__19)
            | (1ULL << smallCParser::T__20)
            | (1ULL << smallCParser::T__21)
            | (1ULL << smallCParser::T__22))) != 0))) {
            dynamic_cast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(297);
          dynamic_cast<ExprContext *>(_localctx)->r = expr(5);

                            smallc::BinaryExprNode* binary = new smallc::BinaryExprNode(dynamic_cast<ExprContext *>(_localctx)->l->node, dynamic_cast<ExprContext *>(_localctx)->r->node);
                            binary->setOpcode((dynamic_cast<ExprContext *>(_localctx)->op != nullptr ? dynamic_cast<ExprContext *>(_localctx)->op->getText() : ""));
                            binary->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            smallc::BoolExprNode* boolExpr = new smallc::BoolExprNode(binary);
                            boolExpr->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            dynamic_cast<ExprContext *>(_localctx)->node =  boolExpr;   
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->l = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(300);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(301);
          dynamic_cast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == smallCParser::T__23

          || _la == smallCParser::T__24)) {
            dynamic_cast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(302);
          dynamic_cast<ExprContext *>(_localctx)->r = expr(4);

                            smallc::BinaryExprNode* binary = new smallc::BinaryExprNode(dynamic_cast<ExprContext *>(_localctx)->l->node, dynamic_cast<ExprContext *>(_localctx)->r->node);
                            binary->setOpcode((dynamic_cast<ExprContext *>(_localctx)->op != nullptr ? dynamic_cast<ExprContext *>(_localctx)->op->getText() : ""));
                            binary->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            smallc::BoolExprNode* boolExpr = new smallc::BoolExprNode(binary);
                            dynamic_cast<ExprContext *>(_localctx)->node =  boolExpr;
                        
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->l = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(305);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(306);
          dynamic_cast<ExprContext *>(_localctx)->op = match(smallCParser::T__25);
          setState(307);
          dynamic_cast<ExprContext *>(_localctx)->r = expr(3);

                            smallc::BinaryExprNode* binary = new smallc::BinaryExprNode(dynamic_cast<ExprContext *>(_localctx)->l->node, dynamic_cast<ExprContext *>(_localctx)->r->node);
                            binary->setOpcode((dynamic_cast<ExprContext *>(_localctx)->op != nullptr ? dynamic_cast<ExprContext *>(_localctx)->op->getText() : ""));
                            binary->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            smallc::BoolExprNode* boolExpr = new smallc::BoolExprNode(binary);
                            boolExpr->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            dynamic_cast<ExprContext *>(_localctx)->node =  boolExpr;
                        
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->l = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(310);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(311);
          dynamic_cast<ExprContext *>(_localctx)->op = match(smallCParser::T__26);
          setState(312);
          dynamic_cast<ExprContext *>(_localctx)->r = expr(2);

                            smallc::BinaryExprNode* binary = new smallc::BinaryExprNode(dynamic_cast<ExprContext *>(_localctx)->l->node, dynamic_cast<ExprContext *>(_localctx)->r->node);
                            binary->setOpcode((dynamic_cast<ExprContext *>(_localctx)->op != nullptr ? dynamic_cast<ExprContext *>(_localctx)->op->getText() : ""));
                            binary->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            smallc::BoolExprNode* boolExpr = new smallc::BoolExprNode(binary);
                            boolExpr->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            dynamic_cast<ExprContext *>(_localctx)->node =  boolExpr;
                        
          break;
        }

        } 
      }
      setState(319);
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

//----------------- IntExprContext ------------------------------------------------------------------

smallCParser::IntExprContext::IntExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::VarContext* smallCParser::IntExprContext::var() {
  return getRuleContext<smallCParser::VarContext>(0);
}

smallCParser::ConstantContext* smallCParser::IntExprContext::constant() {
  return getRuleContext<smallCParser::ConstantContext>(0);
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
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, smallCParser::RuleIntExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(332);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::ID: {
        setState(321);
        dynamic_cast<IntExprContext *>(_localctx)->varContext = var();
         
                dynamic_cast<IntExprContext *>(_localctx)->exprNode =  new smallc::IntExprNode(dynamic_cast<IntExprContext *>(_localctx)->varContext->node);
                _localctx->exprNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            
        break;
      }

      case smallCParser::T__18:
      case smallCParser::BOOL:
      case smallCParser::INT: {
        setState(324);
        dynamic_cast<IntExprContext *>(_localctx)->constantContext = constant();

                dynamic_cast<IntExprContext *>(_localctx)->exprNode =  new smallc::IntExprNode(dynamic_cast<IntExprContext *>(_localctx)->constantContext->node);
                _localctx->exprNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            
        break;
      }

      case smallCParser::T__5: {
        setState(327);
        match(smallCParser::T__5);
        setState(328);
        dynamic_cast<IntExprContext *>(_localctx)->e = intExpr(0);
        setState(329);
        match(smallCParser::T__6);

                dynamic_cast<IntExprContext *>(_localctx)->exprNode =  dynamic_cast<IntExprContext *>(_localctx)->e->exprNode;
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(346);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(344);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<IntExprContext>(parentContext, parentState);
          _localctx->l = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleIntExpr);
          setState(334);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(335);
          dynamic_cast<IntExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == smallCParser::T__27

          || _la == smallCParser::T__28)) {
            dynamic_cast<IntExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(336);
          dynamic_cast<IntExprContext *>(_localctx)->r = intExpr(4);

                            smallc::BinaryExprNode* binary = new smallc::BinaryExprNode(dynamic_cast<IntExprContext *>(_localctx)->l->exprNode, dynamic_cast<IntExprContext *>(_localctx)->r->exprNode);
                            binary->setOpcode((dynamic_cast<IntExprContext *>(_localctx)->op != nullptr ? dynamic_cast<IntExprContext *>(_localctx)->op->getText() : ""));
                            binary->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            dynamic_cast<IntExprContext *>(_localctx)->exprNode =  new smallc::IntExprNode();
                            _localctx->exprNode->setValue(binary);
                            _localctx->exprNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<IntExprContext>(parentContext, parentState);
          _localctx->l = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleIntExpr);
          setState(339);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(340);
          dynamic_cast<IntExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == smallCParser::T__18

          || _la == smallCParser::T__29)) {
            dynamic_cast<IntExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(341);
          dynamic_cast<IntExprContext *>(_localctx)->r = intExpr(3);

                            smallc::BinaryExprNode* binary = new smallc::BinaryExprNode(dynamic_cast<IntExprContext *>(_localctx)->l->exprNode, dynamic_cast<IntExprContext *>(_localctx)->r->exprNode);
                            binary->setOpcode((dynamic_cast<IntExprContext *>(_localctx)->op != nullptr ? dynamic_cast<IntExprContext *>(_localctx)->op->getText() : ""));
                            binary->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            dynamic_cast<IntExprContext *>(_localctx)->exprNode =  new smallc::IntExprNode();
                            _localctx->exprNode->setValue(binary);
                            _localctx->exprNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                        
          break;
        }

        } 
      }
      setState(348);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
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
  enterRule(_localctx, 46, smallCParser::RuleVar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(358);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(349);
      dynamic_cast<VarContext *>(_localctx)->v = varName();

              dynamic_cast<VarContext *>(_localctx)->node =  new smallc::ReferenceExprNode(dynamic_cast<VarContext *>(_localctx)->v->node);
              _localctx->node->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(352);
      dynamic_cast<VarContext *>(_localctx)->a = arrName();
      setState(353);
      match(smallCParser::T__3);
      setState(354);
      dynamic_cast<VarContext *>(_localctx)->idx = intExpr(0);
      setState(355);
      match(smallCParser::T__4);

              dynamic_cast<VarContext *>(_localctx)->node =  new smallc::ReferenceExprNode(dynamic_cast<VarContext *>(_localctx)->a->node);
              _localctx->node->setIndex(dynamic_cast<VarContext *>(_localctx)->idx->exprNode);
              _localctx->node->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
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
  enterRule(_localctx, 48, smallCParser::RuleParams);

      dynamic_cast<ParamsContext *>(_localctx)->parameters =  std::vector<smallc::ParameterNode*>();


  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(364);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::T__7:
      case smallCParser::T__8: {
        enterOuterAlt(_localctx, 1);
        setState(360);
        dynamic_cast<ParamsContext *>(_localctx)->p = paramList();

                dynamic_cast<ParamsContext *>(_localctx)->parameters =  dynamic_cast<ParamsContext *>(_localctx)->p->parameterList;
            
        break;
      }

      case smallCParser::T__6: {
        enterOuterAlt(_localctx, 2);

                // Empty parameter list
            
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
  enterRule(_localctx, 50, smallCParser::RuleParamEntry);

      dynamic_cast<ParamEntryContext *>(_localctx)->param =  new smallc::ParameterNode();
      _localctx->param->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());


  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(375);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(366);
      dynamic_cast<ParamEntryContext *>(_localctx)->t = varType();
      setState(367);
      dynamic_cast<ParamEntryContext *>(_localctx)->name = varName();

              dynamic_cast<ParamEntryContext *>(_localctx)->param =  new smallc::ParameterNode(dynamic_cast<ParamEntryContext *>(_localctx)->t->type, dynamic_cast<ParamEntryContext *>(_localctx)->name->node);
              _localctx->param->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(370);
      dynamic_cast<ParamEntryContext *>(_localctx)->t = varType();
      setState(371);
      dynamic_cast<ParamEntryContext *>(_localctx)->arrname = arrName();
      setState(372);
      match(smallCParser::T__30);

              smallc::ArrayTypeNode* arrayType = new smallc::ArrayTypeNode(dynamic_cast<ParamEntryContext *>(_localctx)->t->type);
              dynamic_cast<ParamEntryContext *>(_localctx)->param =  new smallc::ParameterNode(arrayType, dynamic_cast<ParamEntryContext *>(_localctx)->arrname->node);
              _localctx->param->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
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
  enterRule(_localctx, 52, smallCParser::RuleParamList);

      dynamic_cast<ParamListContext *>(_localctx)->parameterList =  std::vector<smallc::ParameterNode*>();


  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(385);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(377);
      dynamic_cast<ParamListContext *>(_localctx)->p = paramEntry();

              _localctx->parameterList.push_back(dynamic_cast<ParamListContext *>(_localctx)->p->param);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(380);
      dynamic_cast<ParamListContext *>(_localctx)->p = paramEntry();
      setState(381);
      match(smallCParser::T__31);
      setState(382);
      dynamic_cast<ParamListContext *>(_localctx)->pl = paramList();

              _localctx->parameterList.push_back(dynamic_cast<ParamListContext *>(_localctx)->p->param);
              _localctx->parameterList.insert(_localctx->parameterList.end(), dynamic_cast<ParamListContext *>(_localctx)->pl->parameterList.begin(), dynamic_cast<ParamListContext *>(_localctx)->pl->parameterList.end());
          
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
  enterRule(_localctx, 54, smallCParser::RuleArgs);

      dynamic_cast<ArgsContext *>(_localctx)->arguments =  std::vector<smallc::ArgumentNode*>();


  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(391);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::T__5:
      case smallCParser::T__17:
      case smallCParser::T__18:
      case smallCParser::BOOL:
      case smallCParser::ID:
      case smallCParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(387);
        dynamic_cast<ArgsContext *>(_localctx)->a = argList();

                dynamic_cast<ArgsContext *>(_localctx)->arguments =  dynamic_cast<ArgsContext *>(_localctx)->a->argumentList;
            
        break;
      }

      case smallCParser::T__6: {
        enterOuterAlt(_localctx, 2);

                // Empty argument list
            
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
  enterRule(_localctx, 56, smallCParser::RuleArgEntry);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(393);
    dynamic_cast<ArgEntryContext *>(_localctx)->e = expr(0);

            dynamic_cast<ArgEntryContext *>(_localctx)->arg =  new smallc::ArgumentNode(dynamic_cast<ArgEntryContext *>(_localctx)->e->node);
            _localctx->arg->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
        
   
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
  enterRule(_localctx, 58, smallCParser::RuleArgList);

      dynamic_cast<ArgListContext *>(_localctx)->argumentList =  std::vector<smallc::ArgumentNode*>();


  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(404);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(396);
      dynamic_cast<ArgListContext *>(_localctx)->a = argEntry();

              _localctx->argumentList.push_back(dynamic_cast<ArgListContext *>(_localctx)->a->arg);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(399);
      dynamic_cast<ArgListContext *>(_localctx)->a = argEntry();
      setState(400);
      match(smallCParser::T__31);
      setState(401);
      dynamic_cast<ArgListContext *>(_localctx)->al = argList();

              _localctx->argumentList.push_back(dynamic_cast<ArgListContext *>(_localctx)->a->arg);
              _localctx->argumentList.insert(_localctx->argumentList.end(), dynamic_cast<ArgListContext *>(_localctx)->al->argumentList.begin(), dynamic_cast<ArgListContext *>(_localctx)->al->argumentList.end());
          
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
  enterRule(_localctx, 60, smallCParser::RuleVarName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(406);
    dynamic_cast<VarNameContext *>(_localctx)->id = match(smallCParser::ID);

            dynamic_cast<VarNameContext *>(_localctx)->node =  new smallc::IdentifierNode((dynamic_cast<VarNameContext *>(_localctx)->id != nullptr ? dynamic_cast<VarNameContext *>(_localctx)->id->getText() : ""));
            _localctx->node->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
        
   
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
  enterRule(_localctx, 62, smallCParser::RuleArrName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(409);
    dynamic_cast<ArrNameContext *>(_localctx)->id = match(smallCParser::ID);

            dynamic_cast<ArrNameContext *>(_localctx)->node =  new smallc::IdentifierNode((dynamic_cast<ArrNameContext *>(_localctx)->id != nullptr ? dynamic_cast<ArrNameContext *>(_localctx)->id->getText() : ""));
            _localctx->node->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
        
   
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
  enterRule(_localctx, 64, smallCParser::RuleFcnName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(412);
    dynamic_cast<FcnNameContext *>(_localctx)->id = match(smallCParser::ID);

            dynamic_cast<FcnNameContext *>(_localctx)->node =  new smallc::IdentifierNode((dynamic_cast<FcnNameContext *>(_localctx)->id != nullptr ? dynamic_cast<FcnNameContext *>(_localctx)->id->getText() : ""));
            _localctx->node->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
        
   
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
  enterRule(_localctx, 66, smallCParser::RuleIntConst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(420);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(415);
        dynamic_cast<IntConstContext *>(_localctx)->i = match(smallCParser::INT);

                dynamic_cast<IntConstContext *>(_localctx)->node =  new smallc::IntConstantNode((dynamic_cast<IntConstContext *>(_localctx)->i != nullptr ? dynamic_cast<IntConstContext *>(_localctx)->i->getText() : ""));
                _localctx->node->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            
        break;
      }

      case smallCParser::T__18: {
        enterOuterAlt(_localctx, 2);
        setState(417);
        match(smallCParser::T__18);
        setState(418);
        dynamic_cast<IntConstContext *>(_localctx)->i = match(smallCParser::INT);

                dynamic_cast<IntConstContext *>(_localctx)->node =  new smallc::IntConstantNode("-" + (dynamic_cast<IntConstContext *>(_localctx)->i != nullptr ? dynamic_cast<IntConstContext *>(_localctx)->i->getText() : ""));
                _localctx->node->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            
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
    case 21: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);
    case 22: return intExprSempred(dynamic_cast<IntExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool smallCParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);
    case 2: return precpred(_ctx, 2);
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool smallCParser::intExprSempred(IntExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 3);
    case 5: return precpred(_ctx, 2);

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
  "arrDecl", "fcnProtoList", "fcnProto", "fcnDeclList", "fcnDecl", "varType", 
  "retType", "constant", "boolConst", "scope", "stmt", "assignStmt", "ifStmt", 
  "whileStmt", "retStmt", "expr", "intExpr", "var", "params", "paramEntry", 
  "paramList", "args", "argEntry", "argList", "varName", "arrName", "fcnName", 
  "intConst"
};

std::vector<std::string> smallCParser::_literalNames = {
  "", "'#include'", "'\"scio.h\"'", "';'", "'['", "']'", "'('", "')'", "'bool'", 
  "'int'", "'void'", "'{'", "'}'", "'='", "'if'", "'else'", "'while'", "'return'", 
  "'!'", "'-'", "'<'", "'<='", "'>'", "'>='", "'=='", "'!='", "'||'", "'&&'", 
  "'*'", "'/'", "'+'", "'[]'", "','"
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
    0x3, 0x27, 0x1a9, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x5, 0x2, 0x4b, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 
    0x50, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x53, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x5, 0x4, 0x66, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x6f, 0xa, 0x5, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x7d, 0xa, 0x7, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x5, 0x9, 0x8e, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x9f, 0xa, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xad, 0xa, 0xd, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xb4, 0xa, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 
    0xf, 0xbc, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 
    0xc8, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0xcb, 0xb, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x7, 0x11, 0xd0, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0xd3, 
    0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xea, 0xa, 0x12, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x5, 0x14, 0x102, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 
    0x113, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x5, 0x17, 0x128, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x13e, 0xa, 0x17, 
    0xc, 0x17, 0xe, 0x17, 0x141, 0xb, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x14f, 0xa, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x15b, 0xa, 0x18, 0xc, 0x18, 
    0xe, 0x18, 0x15e, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x169, 
    0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x16f, 
    0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x17a, 0xa, 0x1b, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x184, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x18a, 0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x197, 0xa, 0x1f, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x5, 0x23, 0x1a7, 0xa, 0x23, 0x3, 0x23, 0x2, 0x4, 0x2c, 0x2e, 0x24, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 
    0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x2, 0x7, 0x3, 
    0x2, 0x14, 0x15, 0x3, 0x2, 0x16, 0x19, 0x3, 0x2, 0x1a, 0x1b, 0x3, 0x2, 
    0x1e, 0x1f, 0x4, 0x2, 0x15, 0x15, 0x20, 0x20, 0x2, 0x1ae, 0x2, 0x4a, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x56, 0x3, 0x2, 0x2, 0x2, 0x6, 0x65, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0x6e, 0x3, 0x2, 0x2, 0x2, 0xa, 0x70, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x7c, 0x3, 0x2, 0x2, 0x2, 0xe, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x8d, 0x3, 0x2, 0x2, 0x2, 0x12, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x14, 0x9e, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x18, 0xac, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xbb, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x20, 0xc0, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x24, 0xeb, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x101, 0x3, 0x2, 0x2, 0x2, 0x28, 0x103, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x112, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x127, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x14e, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0x168, 0x3, 0x2, 0x2, 0x2, 0x32, 0x16e, 0x3, 
    0x2, 0x2, 0x2, 0x34, 0x179, 0x3, 0x2, 0x2, 0x2, 0x36, 0x183, 0x3, 0x2, 
    0x2, 0x2, 0x38, 0x189, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x18b, 0x3, 0x2, 0x2, 
    0x2, 0x3c, 0x196, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x198, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x42, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x44, 
    0x1a6, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x5, 0x4, 0x3, 0x2, 0x47, 0x48, 
    0x8, 0x2, 0x1, 0x2, 0x48, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x46, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x49, 0x3, 0x2, 
    0x2, 0x2, 0x4b, 0x51, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x5, 0x6, 0x4, 
    0x2, 0x4d, 0x4e, 0x8, 0x2, 0x1, 0x2, 0x4e, 0x50, 0x3, 0x2, 0x2, 0x2, 
    0x4f, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x50, 0x53, 0x3, 0x2, 0x2, 0x2, 0x51, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x3, 0x2, 0x2, 0x2, 0x52, 0x54, 
    0x3, 0x2, 0x2, 0x2, 0x53, 0x51, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x7, 
    0x2, 0x2, 0x3, 0x55, 0x3, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x7, 0x3, 
    0x2, 0x2, 0x57, 0x58, 0x7, 0x4, 0x2, 0x2, 0x58, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x59, 0x5a, 0x5, 0x8, 0x5, 0x2, 0x5a, 0x5b, 0x8, 0x4, 0x1, 0x2, 
    0x5b, 0x66, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x5, 0xc, 0x7, 0x2, 0x5d, 
    0x5e, 0x8, 0x4, 0x1, 0x2, 0x5e, 0x66, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 
    0x5, 0x10, 0x9, 0x2, 0x60, 0x61, 0x8, 0x4, 0x1, 0x2, 0x61, 0x66, 0x3, 
    0x2, 0x2, 0x2, 0x62, 0x63, 0x5, 0x14, 0xb, 0x2, 0x63, 0x64, 0x8, 0x4, 
    0x1, 0x2, 0x64, 0x66, 0x3, 0x2, 0x2, 0x2, 0x65, 0x59, 0x3, 0x2, 0x2, 
    0x2, 0x65, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x65, 0x5f, 0x3, 0x2, 0x2, 0x2, 
    0x65, 0x62, 0x3, 0x2, 0x2, 0x2, 0x66, 0x7, 0x3, 0x2, 0x2, 0x2, 0x67, 
    0x68, 0x5, 0xa, 0x6, 0x2, 0x68, 0x69, 0x8, 0x5, 0x1, 0x2, 0x69, 0x6f, 
    0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x5, 0xa, 0x6, 0x2, 0x6b, 0x6c, 0x5, 
    0x8, 0x5, 0x2, 0x6c, 0x6d, 0x8, 0x5, 0x1, 0x2, 0x6d, 0x6f, 0x3, 0x2, 
    0x2, 0x2, 0x6e, 0x67, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6a, 0x3, 0x2, 0x2, 
    0x2, 0x6f, 0x9, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x5, 0x18, 0xd, 0x2, 
    0x71, 0x72, 0x5, 0x3e, 0x20, 0x2, 0x72, 0x73, 0x7, 0x5, 0x2, 0x2, 0x73, 
    0x74, 0x8, 0x6, 0x1, 0x2, 0x74, 0xb, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 
    0x5, 0xe, 0x8, 0x2, 0x76, 0x77, 0x8, 0x7, 0x1, 0x2, 0x77, 0x7d, 0x3, 
    0x2, 0x2, 0x2, 0x78, 0x79, 0x5, 0xe, 0x8, 0x2, 0x79, 0x7a, 0x5, 0xc, 
    0x7, 0x2, 0x7a, 0x7b, 0x8, 0x7, 0x1, 0x2, 0x7b, 0x7d, 0x3, 0x2, 0x2, 
    0x2, 0x7c, 0x75, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x78, 0x3, 0x2, 0x2, 0x2, 
    0x7d, 0xd, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x5, 0x18, 0xd, 0x2, 0x7f, 
    0x80, 0x5, 0x40, 0x21, 0x2, 0x80, 0x81, 0x7, 0x6, 0x2, 0x2, 0x81, 0x82, 
    0x5, 0x44, 0x23, 0x2, 0x82, 0x83, 0x7, 0x7, 0x2, 0x2, 0x83, 0x84, 0x7, 
    0x5, 0x2, 0x2, 0x84, 0x85, 0x8, 0x8, 0x1, 0x2, 0x85, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x86, 0x87, 0x5, 0x12, 0xa, 0x2, 0x87, 0x88, 0x8, 0x9, 0x1, 
    0x2, 0x88, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x5, 0x12, 0xa, 0x2, 
    0x8a, 0x8b, 0x5, 0x10, 0x9, 0x2, 0x8b, 0x8c, 0x8, 0x9, 0x1, 0x2, 0x8c, 
    0x8e, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x86, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x89, 
    0x3, 0x2, 0x2, 0x2, 0x8e, 0x11, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x5, 
    0x1a, 0xe, 0x2, 0x90, 0x91, 0x5, 0x42, 0x22, 0x2, 0x91, 0x92, 0x7, 0x8, 
    0x2, 0x2, 0x92, 0x93, 0x5, 0x32, 0x1a, 0x2, 0x93, 0x94, 0x7, 0x9, 0x2, 
    0x2, 0x94, 0x95, 0x7, 0x5, 0x2, 0x2, 0x95, 0x96, 0x8, 0xa, 0x1, 0x2, 
    0x96, 0x13, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 0x5, 0x16, 0xc, 0x2, 0x98, 
    0x99, 0x8, 0xb, 0x1, 0x2, 0x99, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 
    0x5, 0x16, 0xc, 0x2, 0x9b, 0x9c, 0x5, 0x14, 0xb, 0x2, 0x9c, 0x9d, 0x8, 
    0xb, 0x1, 0x2, 0x9d, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x97, 0x3, 0x2, 
    0x2, 0x2, 0x9e, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0xa0, 0xa1, 0x5, 0x1a, 0xe, 0x2, 0xa1, 0xa2, 0x5, 0x42, 0x22, 0x2, 
    0xa2, 0xa3, 0x7, 0x8, 0x2, 0x2, 0xa3, 0xa4, 0x5, 0x32, 0x1a, 0x2, 0xa4, 
    0xa5, 0x7, 0x9, 0x2, 0x2, 0xa5, 0xa6, 0x5, 0x20, 0x11, 0x2, 0xa6, 0xa7, 
    0x8, 0xc, 0x1, 0x2, 0xa7, 0x17, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x7, 
    0xa, 0x2, 0x2, 0xa9, 0xad, 0x8, 0xd, 0x1, 0x2, 0xaa, 0xab, 0x7, 0xb, 
    0x2, 0x2, 0xab, 0xad, 0x8, 0xd, 0x1, 0x2, 0xac, 0xa8, 0x3, 0x2, 0x2, 
    0x2, 0xac, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xad, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0xae, 0xaf, 0x7, 0xc, 0x2, 0x2, 0xaf, 0xb4, 0x8, 0xe, 0x1, 0x2, 0xb0, 
    0xb1, 0x5, 0x18, 0xd, 0x2, 0xb1, 0xb2, 0x8, 0xe, 0x1, 0x2, 0xb2, 0xb4, 
    0x3, 0x2, 0x2, 0x2, 0xb3, 0xae, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb0, 0x3, 
    0x2, 0x2, 0x2, 0xb4, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x5, 0x1e, 
    0x10, 0x2, 0xb6, 0xb7, 0x8, 0xf, 0x1, 0x2, 0xb7, 0xbc, 0x3, 0x2, 0x2, 
    0x2, 0xb8, 0xb9, 0x5, 0x44, 0x23, 0x2, 0xb9, 0xba, 0x8, 0xf, 0x1, 0x2, 
    0xba, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xbb, 
    0xb8, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 
    0x7, 0x23, 0x2, 0x2, 0xbe, 0xbf, 0x8, 0x10, 0x1, 0x2, 0xbf, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0xc0, 0xc9, 0x7, 0xd, 0x2, 0x2, 0xc1, 0xc2, 0x5, 0xa, 
    0x6, 0x2, 0xc2, 0xc3, 0x8, 0x11, 0x1, 0x2, 0xc3, 0xc8, 0x3, 0x2, 0x2, 
    0x2, 0xc4, 0xc5, 0x5, 0xe, 0x8, 0x2, 0xc5, 0xc6, 0x8, 0x11, 0x1, 0x2, 
    0xc6, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc7, 
    0xc4, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc7, 
    0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x3, 0x2, 0x2, 0x2, 0xca, 0xd1, 0x3, 
    0x2, 0x2, 0x2, 0xcb, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x5, 0x22, 
    0x12, 0x2, 0xcd, 0xce, 0x8, 0x11, 0x1, 0x2, 0xce, 0xd0, 0x3, 0x2, 0x2, 
    0x2, 0xcf, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd3, 0x3, 0x2, 0x2, 0x2, 
    0xd1, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd2, 
    0xd4, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 
    0x7, 0xe, 0x2, 0x2, 0xd5, 0x21, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x5, 
    0x2c, 0x17, 0x2, 0xd7, 0xd8, 0x7, 0x5, 0x2, 0x2, 0xd8, 0xd9, 0x8, 0x12, 
    0x1, 0x2, 0xd9, 0xea, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdb, 0x5, 0x24, 0x13, 
    0x2, 0xdb, 0xdc, 0x8, 0x12, 0x1, 0x2, 0xdc, 0xea, 0x3, 0x2, 0x2, 0x2, 
    0xdd, 0xde, 0x5, 0x26, 0x14, 0x2, 0xde, 0xdf, 0x8, 0x12, 0x1, 0x2, 0xdf, 
    0xea, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x5, 0x28, 0x15, 0x2, 0xe1, 0xe2, 
    0x8, 0x12, 0x1, 0x2, 0xe2, 0xea, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x5, 
    0x2a, 0x16, 0x2, 0xe4, 0xe5, 0x8, 0x12, 0x1, 0x2, 0xe5, 0xea, 0x3, 0x2, 
    0x2, 0x2, 0xe6, 0xe7, 0x5, 0x20, 0x11, 0x2, 0xe7, 0xe8, 0x8, 0x12, 0x1, 
    0x2, 0xe8, 0xea, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xd6, 0x3, 0x2, 0x2, 0x2, 
    0xe9, 0xda, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xe9, 
    0xe0, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe6, 
    0x3, 0x2, 0x2, 0x2, 0xea, 0x23, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x5, 
    0x30, 0x19, 0x2, 0xec, 0xed, 0x7, 0xf, 0x2, 0x2, 0xed, 0xee, 0x5, 0x2c, 
    0x17, 0x2, 0xee, 0xef, 0x7, 0x5, 0x2, 0x2, 0xef, 0xf0, 0x8, 0x13, 0x1, 
    0x2, 0xf0, 0x25, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x7, 0x10, 0x2, 0x2, 
    0xf2, 0xf3, 0x7, 0x8, 0x2, 0x2, 0xf3, 0xf4, 0x5, 0x2c, 0x17, 0x2, 0xf4, 
    0xf5, 0x7, 0x9, 0x2, 0x2, 0xf5, 0xf6, 0x5, 0x22, 0x12, 0x2, 0xf6, 0xf7, 
    0x8, 0x14, 0x1, 0x2, 0xf7, 0x102, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x7, 
    0x10, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0x8, 0x2, 0x2, 0xfa, 0xfb, 0x5, 0x2c, 
    0x17, 0x2, 0xfb, 0xfc, 0x7, 0x9, 0x2, 0x2, 0xfc, 0xfd, 0x5, 0x22, 0x12, 
    0x2, 0xfd, 0xfe, 0x7, 0x11, 0x2, 0x2, 0xfe, 0xff, 0x5, 0x22, 0x12, 0x2, 
    0xff, 0x100, 0x8, 0x14, 0x1, 0x2, 0x100, 0x102, 0x3, 0x2, 0x2, 0x2, 
    0x101, 0xf1, 0x3, 0x2, 0x2, 0x2, 0x101, 0xf8, 0x3, 0x2, 0x2, 0x2, 0x102, 
    0x27, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 0x7, 0x12, 0x2, 0x2, 0x104, 
    0x105, 0x7, 0x8, 0x2, 0x2, 0x105, 0x106, 0x5, 0x2c, 0x17, 0x2, 0x106, 
    0x107, 0x7, 0x9, 0x2, 0x2, 0x107, 0x108, 0x5, 0x22, 0x12, 0x2, 0x108, 
    0x109, 0x8, 0x15, 0x1, 0x2, 0x109, 0x29, 0x3, 0x2, 0x2, 0x2, 0x10a, 
    0x10b, 0x7, 0x13, 0x2, 0x2, 0x10b, 0x10c, 0x5, 0x2c, 0x17, 0x2, 0x10c, 
    0x10d, 0x7, 0x5, 0x2, 0x2, 0x10d, 0x10e, 0x8, 0x16, 0x1, 0x2, 0x10e, 
    0x113, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 0x7, 0x13, 0x2, 0x2, 0x110, 
    0x111, 0x7, 0x5, 0x2, 0x2, 0x111, 0x113, 0x8, 0x16, 0x1, 0x2, 0x112, 
    0x10a, 0x3, 0x2, 0x2, 0x2, 0x112, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x113, 
    0x2b, 0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 0x8, 0x17, 0x1, 0x2, 0x115, 
    0x116, 0x5, 0x2e, 0x18, 0x2, 0x116, 0x117, 0x8, 0x17, 0x1, 0x2, 0x117, 
    0x128, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x7, 0x8, 0x2, 0x2, 0x119, 
    0x11a, 0x5, 0x2c, 0x17, 0x2, 0x11a, 0x11b, 0x7, 0x9, 0x2, 0x2, 0x11b, 
    0x11c, 0x8, 0x17, 0x1, 0x2, 0x11c, 0x128, 0x3, 0x2, 0x2, 0x2, 0x11d, 
    0x11e, 0x5, 0x42, 0x22, 0x2, 0x11e, 0x11f, 0x7, 0x8, 0x2, 0x2, 0x11f, 
    0x120, 0x5, 0x38, 0x1d, 0x2, 0x120, 0x121, 0x7, 0x9, 0x2, 0x2, 0x121, 
    0x122, 0x8, 0x17, 0x1, 0x2, 0x122, 0x128, 0x3, 0x2, 0x2, 0x2, 0x123, 
    0x124, 0x9, 0x2, 0x2, 0x2, 0x124, 0x125, 0x5, 0x2c, 0x17, 0x7, 0x125, 
    0x126, 0x8, 0x17, 0x1, 0x2, 0x126, 0x128, 0x3, 0x2, 0x2, 0x2, 0x127, 
    0x114, 0x3, 0x2, 0x2, 0x2, 0x127, 0x118, 0x3, 0x2, 0x2, 0x2, 0x127, 
    0x11d, 0x3, 0x2, 0x2, 0x2, 0x127, 0x123, 0x3, 0x2, 0x2, 0x2, 0x128, 
    0x13f, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 0xc, 0x6, 0x2, 0x2, 0x12a, 
    0x12b, 0x9, 0x3, 0x2, 0x2, 0x12b, 0x12c, 0x5, 0x2c, 0x17, 0x7, 0x12c, 
    0x12d, 0x8, 0x17, 0x1, 0x2, 0x12d, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x12e, 
    0x12f, 0xc, 0x5, 0x2, 0x2, 0x12f, 0x130, 0x9, 0x4, 0x2, 0x2, 0x130, 
    0x131, 0x5, 0x2c, 0x17, 0x6, 0x131, 0x132, 0x8, 0x17, 0x1, 0x2, 0x132, 
    0x13e, 0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 0xc, 0x4, 0x2, 0x2, 0x134, 
    0x135, 0x7, 0x1c, 0x2, 0x2, 0x135, 0x136, 0x5, 0x2c, 0x17, 0x5, 0x136, 
    0x137, 0x8, 0x17, 0x1, 0x2, 0x137, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x138, 
    0x139, 0xc, 0x3, 0x2, 0x2, 0x139, 0x13a, 0x7, 0x1d, 0x2, 0x2, 0x13a, 
    0x13b, 0x5, 0x2c, 0x17, 0x4, 0x13b, 0x13c, 0x8, 0x17, 0x1, 0x2, 0x13c, 
    0x13e, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x129, 0x3, 0x2, 0x2, 0x2, 0x13d, 
    0x12e, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x133, 0x3, 0x2, 0x2, 0x2, 0x13d, 
    0x138, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x141, 0x3, 0x2, 0x2, 0x2, 0x13f, 
    0x13d, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 0x3, 0x2, 0x2, 0x2, 0x140, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x141, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 
    0x8, 0x18, 0x1, 0x2, 0x143, 0x144, 0x5, 0x30, 0x19, 0x2, 0x144, 0x145, 
    0x8, 0x18, 0x1, 0x2, 0x145, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 
    0x5, 0x1c, 0xf, 0x2, 0x147, 0x148, 0x8, 0x18, 0x1, 0x2, 0x148, 0x14f, 
    0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x7, 0x8, 0x2, 0x2, 0x14a, 0x14b, 
    0x5, 0x2e, 0x18, 0x2, 0x14b, 0x14c, 0x7, 0x9, 0x2, 0x2, 0x14c, 0x14d, 
    0x8, 0x18, 0x1, 0x2, 0x14d, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x142, 
    0x3, 0x2, 0x2, 0x2, 0x14e, 0x146, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x149, 
    0x3, 0x2, 0x2, 0x2, 0x14f, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x150, 0x151, 
    0xc, 0x5, 0x2, 0x2, 0x151, 0x152, 0x9, 0x5, 0x2, 0x2, 0x152, 0x153, 
    0x5, 0x2e, 0x18, 0x6, 0x153, 0x154, 0x8, 0x18, 0x1, 0x2, 0x154, 0x15b, 
    0x3, 0x2, 0x2, 0x2, 0x155, 0x156, 0xc, 0x4, 0x2, 0x2, 0x156, 0x157, 
    0x9, 0x6, 0x2, 0x2, 0x157, 0x158, 0x5, 0x2e, 0x18, 0x5, 0x158, 0x159, 
    0x8, 0x18, 0x1, 0x2, 0x159, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x150, 
    0x3, 0x2, 0x2, 0x2, 0x15a, 0x155, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15e, 
    0x3, 0x2, 0x2, 0x2, 0x15c, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15d, 
    0x3, 0x2, 0x2, 0x2, 0x15d, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15c, 0x3, 
    0x2, 0x2, 0x2, 0x15f, 0x160, 0x5, 0x3e, 0x20, 0x2, 0x160, 0x161, 0x8, 
    0x19, 0x1, 0x2, 0x161, 0x169, 0x3, 0x2, 0x2, 0x2, 0x162, 0x163, 0x5, 
    0x40, 0x21, 0x2, 0x163, 0x164, 0x7, 0x6, 0x2, 0x2, 0x164, 0x165, 0x5, 
    0x2e, 0x18, 0x2, 0x165, 0x166, 0x7, 0x7, 0x2, 0x2, 0x166, 0x167, 0x8, 
    0x19, 0x1, 0x2, 0x167, 0x169, 0x3, 0x2, 0x2, 0x2, 0x168, 0x15f, 0x3, 
    0x2, 0x2, 0x2, 0x168, 0x162, 0x3, 0x2, 0x2, 0x2, 0x169, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x16a, 0x16b, 0x5, 0x36, 0x1c, 0x2, 0x16b, 0x16c, 0x8, 0x1a, 
    0x1, 0x2, 0x16c, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16f, 0x8, 0x1a, 
    0x1, 0x2, 0x16e, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16d, 0x3, 0x2, 
    0x2, 0x2, 0x16f, 0x33, 0x3, 0x2, 0x2, 0x2, 0x170, 0x171, 0x5, 0x18, 
    0xd, 0x2, 0x171, 0x172, 0x5, 0x3e, 0x20, 0x2, 0x172, 0x173, 0x8, 0x1b, 
    0x1, 0x2, 0x173, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x174, 0x175, 0x5, 0x18, 
    0xd, 0x2, 0x175, 0x176, 0x5, 0x40, 0x21, 0x2, 0x176, 0x177, 0x7, 0x21, 
    0x2, 0x2, 0x177, 0x178, 0x8, 0x1b, 0x1, 0x2, 0x178, 0x17a, 0x3, 0x2, 
    0x2, 0x2, 0x179, 0x170, 0x3, 0x2, 0x2, 0x2, 0x179, 0x174, 0x3, 0x2, 
    0x2, 0x2, 0x17a, 0x35, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17c, 0x5, 0x34, 
    0x1b, 0x2, 0x17c, 0x17d, 0x8, 0x1c, 0x1, 0x2, 0x17d, 0x184, 0x3, 0x2, 
    0x2, 0x2, 0x17e, 0x17f, 0x5, 0x34, 0x1b, 0x2, 0x17f, 0x180, 0x7, 0x22, 
    0x2, 0x2, 0x180, 0x181, 0x5, 0x36, 0x1c, 0x2, 0x181, 0x182, 0x8, 0x1c, 
    0x1, 0x2, 0x182, 0x184, 0x3, 0x2, 0x2, 0x2, 0x183, 0x17b, 0x3, 0x2, 
    0x2, 0x2, 0x183, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x184, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x185, 0x186, 0x5, 0x3c, 0x1f, 0x2, 0x186, 0x187, 0x8, 0x1d, 0x1, 
    0x2, 0x187, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x188, 0x18a, 0x8, 0x1d, 0x1, 
    0x2, 0x189, 0x185, 0x3, 0x2, 0x2, 0x2, 0x189, 0x188, 0x3, 0x2, 0x2, 
    0x2, 0x18a, 0x39, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x18c, 0x5, 0x2c, 0x17, 
    0x2, 0x18c, 0x18d, 0x8, 0x1e, 0x1, 0x2, 0x18d, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x18e, 0x18f, 0x5, 0x3a, 0x1e, 0x2, 0x18f, 0x190, 0x8, 0x1f, 0x1, 
    0x2, 0x190, 0x197, 0x3, 0x2, 0x2, 0x2, 0x191, 0x192, 0x5, 0x3a, 0x1e, 
    0x2, 0x192, 0x193, 0x7, 0x22, 0x2, 0x2, 0x193, 0x194, 0x5, 0x3c, 0x1f, 
    0x2, 0x194, 0x195, 0x8, 0x1f, 0x1, 0x2, 0x195, 0x197, 0x3, 0x2, 0x2, 
    0x2, 0x196, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x196, 0x191, 0x3, 0x2, 0x2, 
    0x2, 0x197, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x198, 0x199, 0x7, 0x24, 0x2, 
    0x2, 0x199, 0x19a, 0x8, 0x20, 0x1, 0x2, 0x19a, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x19b, 0x19c, 0x7, 0x24, 0x2, 0x2, 0x19c, 0x19d, 0x8, 0x21, 0x1, 
    0x2, 0x19d, 0x41, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19f, 0x7, 0x24, 0x2, 
    0x2, 0x19f, 0x1a0, 0x8, 0x22, 0x1, 0x2, 0x1a0, 0x43, 0x3, 0x2, 0x2, 
    0x2, 0x1a1, 0x1a2, 0x7, 0x25, 0x2, 0x2, 0x1a2, 0x1a7, 0x8, 0x23, 0x1, 
    0x2, 0x1a3, 0x1a4, 0x7, 0x15, 0x2, 0x2, 0x1a4, 0x1a5, 0x7, 0x25, 0x2, 
    0x2, 0x1a5, 0x1a7, 0x8, 0x23, 0x1, 0x2, 0x1a6, 0x1a1, 0x3, 0x2, 0x2, 
    0x2, 0x1a6, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x45, 0x3, 0x2, 0x2, 0x2, 
    0x1f, 0x4a, 0x51, 0x65, 0x6e, 0x7c, 0x8d, 0x9e, 0xac, 0xb3, 0xbb, 0xc7, 
    0xc9, 0xd1, 0xe9, 0x101, 0x112, 0x127, 0x13d, 0x13f, 0x14e, 0x15a, 0x15c, 
    0x168, 0x16e, 0x179, 0x183, 0x189, 0x196, 0x1a6, 
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
