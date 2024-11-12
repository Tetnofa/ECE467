// Generated from /homes/p/patraama/ECE467/lab3/smallC.g4 by ANTLR 4.13.1

#include "ASTNodes.h"
#include <iostream>
#include <string>

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class smallCParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, T__18=19, T__19=20, T__20=21, T__21=22, T__22=23, T__23=24, 
		T__24=25, T__25=26, T__26=27, T__27=28, T__28=29, T__29=30, T__30=31, 
		T__31=32, BOOL=33, ID=34, INT=35, WS=36, COMMENT=37;
	public static final int
		RULE_program = 0, RULE_preamble = 1, RULE_decls = 2, RULE_scalarDeclList = 3, 
		RULE_scalarDecl = 4, RULE_arrDeclList = 5, RULE_arrDecl = 6, RULE_fcnProtoList = 7, 
		RULE_fcnProto = 8, RULE_fcnDeclList = 9, RULE_fcnDecl = 10, RULE_varType = 11, 
		RULE_retType = 12, RULE_constant = 13, RULE_boolConst = 14, RULE_scope = 15, 
		RULE_stmt = 16, RULE_assignStmt = 17, RULE_ifStmt = 18, RULE_whileStmt = 19, 
		RULE_retStmt = 20, RULE_expr = 21, RULE_intExpr = 22, RULE_var = 23, RULE_params = 24, 
		RULE_paramEntry = 25, RULE_paramList = 26, RULE_args = 27, RULE_argEntry = 28, 
		RULE_argList = 29, RULE_varName = 30, RULE_arrName = 31, RULE_fcnName = 32, 
		RULE_intConst = 33;
	private static String[] makeRuleNames() {
		return new String[] {
			"program", "preamble", "decls", "scalarDeclList", "scalarDecl", "arrDeclList", 
			"arrDecl", "fcnProtoList", "fcnProto", "fcnDeclList", "fcnDecl", "varType", 
			"retType", "constant", "boolConst", "scope", "stmt", "assignStmt", "ifStmt", 
			"whileStmt", "retStmt", "expr", "intExpr", "var", "params", "paramEntry", 
			"paramList", "args", "argEntry", "argList", "varName", "arrName", "fcnName", 
			"intConst"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'#include'", "'\"scio.h\"'", "';'", "'['", "']'", "'('", "')'", 
			"'bool'", "'int'", "'void'", "'{'", "'}'", "'='", "'if'", "'else'", "'while'", 
			"'return'", "'!'", "'-'", "'<'", "'<='", "'>'", "'>='", "'=='", "'!='", 
			"'||'", "'&&'", "'*'", "'/'", "'+'", "'[]'", "','"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, "BOOL", "ID", "INT", 
			"WS", "COMMENT"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "smallC.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public smallCParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProgramContext extends ParserRuleContext {
		public smallc::ProgramNode * prg;
		public DeclsContext decls;
		public TerminalNode EOF() { return getToken(smallCParser.EOF, 0); }
		public PreambleContext preamble() {
			return getRuleContext(PreambleContext.class,0);
		}
		public List<DeclsContext> decls() {
			return getRuleContexts(DeclsContext.class);
		}
		public DeclsContext decls(int i) {
			return getRuleContext(DeclsContext.class,i);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);

		    ((ProgramContext)_localctx).prg =  new smallc::ProgramNode();
		    _localctx.prg->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(72);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
				{
				setState(68);
				preamble();
				_localctx.prg->setIo(true);
				}
				break;
			case EOF:
			case T__7:
			case T__8:
			case T__9:
				{
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(79);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 1792L) != 0)) {
				{
				{
				setState(74);
				((ProgramContext)_localctx).decls = decls();

				   for(unsigned int i = 0; i < ((ProgramContext)_localctx).decls.declarations.size();i++)
				   {
				    _localctx.prg->addChild(((ProgramContext)_localctx).decls.declarations[i]);
				    ((ProgramContext)_localctx).decls.declarations[i]->setParent(_localctx.prg);
				   }

				}
				}
				setState(81);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(82);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class PreambleContext extends ParserRuleContext {
		public PreambleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_preamble; }
	}

	public final PreambleContext preamble() throws RecognitionException {
		PreambleContext _localctx = new PreambleContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_preamble);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(84);
			match(T__0);
			setState(85);
			match(T__1);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class DeclsContext extends ParserRuleContext {
		public std::vector<smallc::DeclNode*> declarations;
		public ScalarDeclListContext scalarDeclList;
		public ArrDeclListContext arrDeclList;
		public FcnProtoListContext fcnProtoList;
		public FcnDeclListContext fcnDeclList;
		public ScalarDeclListContext scalarDeclList() {
			return getRuleContext(ScalarDeclListContext.class,0);
		}
		public ArrDeclListContext arrDeclList() {
			return getRuleContext(ArrDeclListContext.class,0);
		}
		public FcnProtoListContext fcnProtoList() {
			return getRuleContext(FcnProtoListContext.class,0);
		}
		public FcnDeclListContext fcnDeclList() {
			return getRuleContext(FcnDeclListContext.class,0);
		}
		public DeclsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_decls; }
	}

	public final DeclsContext decls() throws RecognitionException {
		DeclsContext _localctx = new DeclsContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_decls);

		    ((DeclsContext)_localctx).declarations =  std::vector<smallc::DeclNode*>();

		try {
			setState(99);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(87);
				((DeclsContext)_localctx).scalarDeclList = scalarDeclList();
				 
				        for(unsigned int i = 0; i < ((DeclsContext)_localctx).scalarDeclList.scalars.size(); i++) {
				            _localctx.declarations.push_back(((DeclsContext)_localctx).scalarDeclList.scalars[i]);
				        }
				       
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(90);
				((DeclsContext)_localctx).arrDeclList = arrDeclList();
				 
				        for(unsigned int i = 0; i < ((DeclsContext)_localctx).arrDeclList.arrays.size(); i++) {
				            _localctx.declarations.push_back(((DeclsContext)_localctx).arrDeclList.arrays[i]);
				        }
				       
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(93);
				((DeclsContext)_localctx).fcnProtoList = fcnProtoList();
				 
				        for(unsigned int i = 0; i < ((DeclsContext)_localctx).fcnProtoList.prototypes.size(); i++) {
				            _localctx.declarations.push_back(((DeclsContext)_localctx).fcnProtoList.prototypes[i]);
				        }
				       
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(96);
				((DeclsContext)_localctx).fcnDeclList = fcnDeclList();
				 
				        for(unsigned int i = 0; i < ((DeclsContext)_localctx).fcnDeclList.declarations.size(); i++) {
				            _localctx.declarations.push_back(((DeclsContext)_localctx).fcnDeclList.declarations[i]);
				        }
				       
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ScalarDeclListContext extends ParserRuleContext {
		public std::vector<smallc::ScalarDeclNode*> scalars;
		public ScalarDeclContext scalarDecl;
		public ScalarDeclListContext scalarDeclList;
		public ScalarDeclContext scalarDecl() {
			return getRuleContext(ScalarDeclContext.class,0);
		}
		public ScalarDeclListContext scalarDeclList() {
			return getRuleContext(ScalarDeclListContext.class,0);
		}
		public ScalarDeclListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_scalarDeclList; }
	}

	public final ScalarDeclListContext scalarDeclList() throws RecognitionException {
		ScalarDeclListContext _localctx = new ScalarDeclListContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_scalarDeclList);
		try {
			setState(108);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(101);
				((ScalarDeclListContext)_localctx).scalarDecl = scalarDecl();
				 _localctx.scalars.push_back(((ScalarDeclListContext)_localctx).scalarDecl.decl); 
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(104);
				((ScalarDeclListContext)_localctx).scalarDecl = scalarDecl();
				setState(105);
				((ScalarDeclListContext)_localctx).scalarDeclList = scalarDeclList();

				          _localctx.scalars.push_back(((ScalarDeclListContext)_localctx).scalarDecl.decl);
				          for (unsigned int i = 0; i < ((ScalarDeclListContext)_localctx).scalarDeclList.scalars.size(); i++) {
				              _localctx.scalars.push_back(((ScalarDeclListContext)_localctx).scalarDeclList.scalars[i]);
				          }
				      
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ScalarDeclContext extends ParserRuleContext {
		public smallc::ScalarDeclNode* decl;
		public VarTypeContext t;
		public VarNameContext v;
		public VarTypeContext varType() {
			return getRuleContext(VarTypeContext.class,0);
		}
		public VarNameContext varName() {
			return getRuleContext(VarNameContext.class,0);
		}
		public ScalarDeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_scalarDecl; }
	}

	public final ScalarDeclContext scalarDecl() throws RecognitionException {
		ScalarDeclContext _localctx = new ScalarDeclContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_scalarDecl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(110);
			((ScalarDeclContext)_localctx).t = varType();
			setState(111);
			((ScalarDeclContext)_localctx).v = varName();
			setState(112);
			match(T__2);
			   
			        ((ScalarDeclContext)_localctx).decl =  new smallc::ScalarDeclNode(((ScalarDeclContext)_localctx).t.type, ((ScalarDeclContext)_localctx).v.node);
			        _localctx.decl->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArrDeclListContext extends ParserRuleContext {
		public std::vector<smallc::ArrayDeclNode*> arrays;
		public ArrDeclContext arrDecl;
		public ArrDeclListContext arrDeclList;
		public ArrDeclContext arrDecl() {
			return getRuleContext(ArrDeclContext.class,0);
		}
		public ArrDeclListContext arrDeclList() {
			return getRuleContext(ArrDeclListContext.class,0);
		}
		public ArrDeclListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arrDeclList; }
	}

	public final ArrDeclListContext arrDeclList() throws RecognitionException {
		ArrDeclListContext _localctx = new ArrDeclListContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_arrDeclList);
		try {
			setState(122);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(115);
				((ArrDeclListContext)_localctx).arrDecl = arrDecl();
				 _localctx.arrays.push_back(((ArrDeclListContext)_localctx).arrDecl.decl); 
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(118);
				((ArrDeclListContext)_localctx).arrDecl = arrDecl();
				setState(119);
				((ArrDeclListContext)_localctx).arrDeclList = arrDeclList();

				          _localctx.arrays.push_back(((ArrDeclListContext)_localctx).arrDecl.decl);
				          for (unsigned int i = 0; i < ((ArrDeclListContext)_localctx).arrDeclList.arrays.size(); i++) {
				              _localctx.arrays.push_back(((ArrDeclListContext)_localctx).arrDeclList.arrays[i]);
				          }
				      
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArrDeclContext extends ParserRuleContext {
		public smallc::ArrayDeclNode* decl;
		public VarTypeContext t;
		public ArrNameContext n;
		public IntConstContext size;
		public VarTypeContext varType() {
			return getRuleContext(VarTypeContext.class,0);
		}
		public ArrNameContext arrName() {
			return getRuleContext(ArrNameContext.class,0);
		}
		public IntConstContext intConst() {
			return getRuleContext(IntConstContext.class,0);
		}
		public ArrDeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arrDecl; }
	}

	public final ArrDeclContext arrDecl() throws RecognitionException {
		ArrDeclContext _localctx = new ArrDeclContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_arrDecl);

		    ((ArrDeclContext)_localctx).decl =  nullptr;

		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(124);
			((ArrDeclContext)_localctx).t = varType();
			setState(125);
			((ArrDeclContext)_localctx).n = arrName();
			setState(126);
			match(T__3);
			setState(127);
			((ArrDeclContext)_localctx).size = intConst();
			setState(128);
			match(T__4);
			setState(129);
			match(T__2);

			        smallc::ArrayTypeNode* type = new smallc::ArrayTypeNode(((ArrDeclContext)_localctx).t.type, ((ArrDeclContext)_localctx).size.node->getVal());
			        ((ArrDeclContext)_localctx).decl =  new smallc::ArrayDeclNode(type, ((ArrDeclContext)_localctx).n.node);
			        _localctx.decl->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FcnProtoListContext extends ParserRuleContext {
		public std::vector<smallc::FunctionDeclNode*> prototypes;
		public FcnProtoContext fcnProto;
		public FcnProtoListContext fcnProtoList;
		public FcnProtoContext fcnProto() {
			return getRuleContext(FcnProtoContext.class,0);
		}
		public FcnProtoListContext fcnProtoList() {
			return getRuleContext(FcnProtoListContext.class,0);
		}
		public FcnProtoListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fcnProtoList; }
	}

	public final FcnProtoListContext fcnProtoList() throws RecognitionException {
		FcnProtoListContext _localctx = new FcnProtoListContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_fcnProtoList);
		try {
			setState(139);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(132);
				((FcnProtoListContext)_localctx).fcnProto = fcnProto();
				 _localctx.prototypes.push_back(((FcnProtoListContext)_localctx).fcnProto.proto); 
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(135);
				((FcnProtoListContext)_localctx).fcnProto = fcnProto();
				setState(136);
				((FcnProtoListContext)_localctx).fcnProtoList = fcnProtoList();

				          _localctx.prototypes.push_back(((FcnProtoListContext)_localctx).fcnProto.proto);
				          for (unsigned int i = 0; i < ((FcnProtoListContext)_localctx).fcnProtoList.prototypes.size(); i++) {
				              _localctx.prototypes.push_back(((FcnProtoListContext)_localctx).fcnProtoList.prototypes[i]);
				          }
				      
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FcnProtoContext extends ParserRuleContext {
		public smallc::FunctionDeclNode* proto;
		public RetTypeContext t;
		public FcnNameContext n;
		public ParamsContext p;
		public RetTypeContext retType() {
			return getRuleContext(RetTypeContext.class,0);
		}
		public FcnNameContext fcnName() {
			return getRuleContext(FcnNameContext.class,0);
		}
		public ParamsContext params() {
			return getRuleContext(ParamsContext.class,0);
		}
		public FcnProtoContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fcnProto; }
	}

	public final FcnProtoContext fcnProto() throws RecognitionException {
		FcnProtoContext _localctx = new FcnProtoContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_fcnProto);

		    ((FcnProtoContext)_localctx).proto =  new smallc::FunctionDeclNode();
		    _localctx.proto->setProto(true);
		    _localctx.proto->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(141);
			((FcnProtoContext)_localctx).t = retType();
			setState(142);
			((FcnProtoContext)_localctx).n = fcnName();
			setState(143);
			match(T__5);
			setState(144);
			((FcnProtoContext)_localctx).p = params();
			setState(145);
			match(T__6);
			setState(146);
			match(T__2);

			        _localctx.proto->setRetType(((FcnProtoContext)_localctx).t.type);
			        _localctx.proto->setName(((FcnProtoContext)_localctx).n.node);
			        for(auto param : ((FcnProtoContext)_localctx).p.parameters) {
			            _localctx.proto->addParameter(param);
			        }
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FcnDeclListContext extends ParserRuleContext {
		public std::vector<smallc::FunctionDeclNode*> declarations;
		public FcnDeclContext fcnDecl;
		public FcnDeclListContext fcnDeclList;
		public FcnDeclContext fcnDecl() {
			return getRuleContext(FcnDeclContext.class,0);
		}
		public FcnDeclListContext fcnDeclList() {
			return getRuleContext(FcnDeclListContext.class,0);
		}
		public FcnDeclListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fcnDeclList; }
	}

	public final FcnDeclListContext fcnDeclList() throws RecognitionException {
		FcnDeclListContext _localctx = new FcnDeclListContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_fcnDeclList);
		try {
			setState(156);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(149);
				((FcnDeclListContext)_localctx).fcnDecl = fcnDecl();
				 _localctx.declarations.push_back(((FcnDeclListContext)_localctx).fcnDecl.declaration); 
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(152);
				((FcnDeclListContext)_localctx).fcnDecl = fcnDecl();
				setState(153);
				((FcnDeclListContext)_localctx).fcnDeclList = fcnDeclList();

				          _localctx.declarations.push_back(((FcnDeclListContext)_localctx).fcnDecl.declaration);
				          for (unsigned int i = 0; i < ((FcnDeclListContext)_localctx).fcnDeclList.declarations.size(); i++) {
				              _localctx.declarations.push_back(((FcnDeclListContext)_localctx).fcnDeclList.declarations[i]);
				          }
				      
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FcnDeclContext extends ParserRuleContext {
		public smallc::FunctionDeclNode* declaration;
		public RetTypeContext t;
		public FcnNameContext n;
		public ParamsContext p;
		public ScopeContext s;
		public RetTypeContext retType() {
			return getRuleContext(RetTypeContext.class,0);
		}
		public FcnNameContext fcnName() {
			return getRuleContext(FcnNameContext.class,0);
		}
		public ParamsContext params() {
			return getRuleContext(ParamsContext.class,0);
		}
		public ScopeContext scope() {
			return getRuleContext(ScopeContext.class,0);
		}
		public FcnDeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fcnDecl; }
	}

	public final FcnDeclContext fcnDecl() throws RecognitionException {
		FcnDeclContext _localctx = new FcnDeclContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_fcnDecl);

		    ((FcnDeclContext)_localctx).declaration =  new smallc::FunctionDeclNode();
		    _localctx.declaration->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(158);
			((FcnDeclContext)_localctx).t = retType();
			setState(159);
			((FcnDeclContext)_localctx).n = fcnName();
			setState(160);
			match(T__5);
			setState(161);
			((FcnDeclContext)_localctx).p = params();
			setState(162);
			match(T__6);
			setState(163);
			((FcnDeclContext)_localctx).s = scope();

			        _localctx.declaration->setRetType(((FcnDeclContext)_localctx).t.type);
			        _localctx.declaration->setName(((FcnDeclContext)_localctx).n.node);
			        for(auto param : ((FcnDeclContext)_localctx).p.parameters) {
			            _localctx.declaration->addParameter(param);
			        }
			        _localctx.declaration->setBody(((FcnDeclContext)_localctx).s.scope_);
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VarTypeContext extends ParserRuleContext {
		public smallc::PrimitiveTypeNode* type;
		public VarTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varType; }
	}

	public final VarTypeContext varType() throws RecognitionException {
		VarTypeContext _localctx = new VarTypeContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_varType);
		try {
			setState(170);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__7:
				enterOuterAlt(_localctx, 1);
				{
				setState(166);
				match(T__7);

				        ((VarTypeContext)_localctx).type =  new smallc::PrimitiveTypeNode(smallc::TypeNode::Bool);
				        _localctx.type->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
				    
				}
				break;
			case T__8:
				enterOuterAlt(_localctx, 2);
				{
				setState(168);
				match(T__8);

				        ((VarTypeContext)_localctx).type =  new smallc::PrimitiveTypeNode(smallc::TypeNode::Int);
				        _localctx.type->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class RetTypeContext extends ParserRuleContext {
		public smallc::PrimitiveTypeNode* type;
		public VarTypeContext varType;
		public VarTypeContext varType() {
			return getRuleContext(VarTypeContext.class,0);
		}
		public RetTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_retType; }
	}

	public final RetTypeContext retType() throws RecognitionException {
		RetTypeContext _localctx = new RetTypeContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_retType);
		try {
			setState(177);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__9:
				enterOuterAlt(_localctx, 1);
				{
				setState(172);
				match(T__9);

				        ((RetTypeContext)_localctx).type =  new smallc::PrimitiveTypeNode(smallc::TypeNode::Void);
				        _localctx.type->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
				    
				}
				break;
			case T__7:
			case T__8:
				enterOuterAlt(_localctx, 2);
				{
				setState(174);
				((RetTypeContext)_localctx).varType = varType();

				        ((RetTypeContext)_localctx).type =  ((RetTypeContext)_localctx).varType.type;
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ConstantContext extends ParserRuleContext {
		public smallc::ConstantExprNode* node;
		public BoolConstContext boolConst;
		public IntConstContext intConst;
		public BoolConstContext boolConst() {
			return getRuleContext(BoolConstContext.class,0);
		}
		public IntConstContext intConst() {
			return getRuleContext(IntConstContext.class,0);
		}
		public ConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant; }
	}

	public final ConstantContext constant() throws RecognitionException {
		ConstantContext _localctx = new ConstantContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_constant);

		    ((ConstantContext)_localctx).node =  nullptr;
		    // _localctx.node->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine()); // This is Unnecessary since defined before

		try {
			setState(185);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BOOL:
				enterOuterAlt(_localctx, 1);
				{
				setState(179);
				((ConstantContext)_localctx).boolConst = boolConst();
				 
				        ((ConstantContext)_localctx).node =  ((ConstantContext)_localctx).boolConst.node;
				    
				}
				break;
			case T__18:
			case INT:
				enterOuterAlt(_localctx, 2);
				{
				setState(182);
				((ConstantContext)_localctx).intConst = intConst();
				 
				        ((ConstantContext)_localctx).node =  ((ConstantContext)_localctx).intConst.node;
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class BoolConstContext extends ParserRuleContext {
		public smallc::BoolConstantNode* node;
		public Token b;
		public TerminalNode BOOL() { return getToken(smallCParser.BOOL, 0); }
		public BoolConstContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_boolConst; }
	}

	public final BoolConstContext boolConst() throws RecognitionException {
		BoolConstContext _localctx = new BoolConstContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_boolConst);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(187);
			((BoolConstContext)_localctx).b = match(BOOL);

			        ((BoolConstContext)_localctx).node =  new smallc::BoolConstantNode((((BoolConstContext)_localctx).b!=null?((BoolConstContext)_localctx).b.getText():null));
			        _localctx.node->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ScopeContext extends ParserRuleContext {
		public smallc::ScopeNode* scope_;
		public ScalarDeclContext scalarDecl;
		public ArrDeclContext arrDecl;
		public StmtContext stmt;
		public List<ScalarDeclContext> scalarDecl() {
			return getRuleContexts(ScalarDeclContext.class);
		}
		public ScalarDeclContext scalarDecl(int i) {
			return getRuleContext(ScalarDeclContext.class,i);
		}
		public List<ArrDeclContext> arrDecl() {
			return getRuleContexts(ArrDeclContext.class);
		}
		public ArrDeclContext arrDecl(int i) {
			return getRuleContext(ArrDeclContext.class,i);
		}
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public ScopeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_scope; }
	}

	public final ScopeContext scope() throws RecognitionException {
		ScopeContext _localctx = new ScopeContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_scope);

		    ((ScopeContext)_localctx).scope_ =  new smallc::ScopeNode();
		    _localctx.scope_->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(190);
			match(T__10);
			setState(199);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__7 || _la==T__8) {
				{
				setState(197);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
				case 1:
					{
					setState(191);
					((ScopeContext)_localctx).scalarDecl = scalarDecl();
					_localctx.scope_->addDeclaration(((ScopeContext)_localctx).scalarDecl.decl);
					}
					break;
				case 2:
					{
					setState(194);
					((ScopeContext)_localctx).arrDecl = arrDecl();
					_localctx.scope_->addDeclaration(((ScopeContext)_localctx).arrDecl.decl);
					}
					break;
				}
				}
				setState(201);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(207);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 60130543680L) != 0)) {
				{
				{
				setState(202);
				((ScopeContext)_localctx).stmt = stmt();
				_localctx.scope_->addChild(((ScopeContext)_localctx).stmt.statement);
				}
				}
				setState(209);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(210);
			match(T__11);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StmtContext extends ParserRuleContext {
		public smallc::StmtNode* statement;
		public ExprContext expr;
		public AssignStmtContext assignStmt;
		public IfStmtContext ifStmt;
		public WhileStmtContext whileStmt;
		public RetStmtContext retStmt;
		public ScopeContext scope;
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public AssignStmtContext assignStmt() {
			return getRuleContext(AssignStmtContext.class,0);
		}
		public IfStmtContext ifStmt() {
			return getRuleContext(IfStmtContext.class,0);
		}
		public WhileStmtContext whileStmt() {
			return getRuleContext(WhileStmtContext.class,0);
		}
		public RetStmtContext retStmt() {
			return getRuleContext(RetStmtContext.class,0);
		}
		public ScopeContext scope() {
			return getRuleContext(ScopeContext.class,0);
		}
		public StmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmt; }
	}

	public final StmtContext stmt() throws RecognitionException {
		StmtContext _localctx = new StmtContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_stmt);
		try {
			setState(231);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(212);
				((StmtContext)_localctx).expr = expr(0);
				setState(213);
				match(T__2);

				        ((StmtContext)_localctx).statement =  new smallc::ExprStmtNode(((StmtContext)_localctx).expr.node);
				        _localctx.statement->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(216);
				((StmtContext)_localctx).assignStmt = assignStmt();

				        ((StmtContext)_localctx).statement =  ((StmtContext)_localctx).assignStmt.assignment;
				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(219);
				((StmtContext)_localctx).ifStmt = ifStmt();

				        ((StmtContext)_localctx).statement =  ((StmtContext)_localctx).ifStmt.ifNode;
				    
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(222);
				((StmtContext)_localctx).whileStmt = whileStmt();

				        ((StmtContext)_localctx).statement =  ((StmtContext)_localctx).whileStmt.whileNode;
				    
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(225);
				((StmtContext)_localctx).retStmt = retStmt();

				        ((StmtContext)_localctx).statement =  ((StmtContext)_localctx).retStmt.returnNode;
				    
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(228);
				((StmtContext)_localctx).scope = scope();

				        ((StmtContext)_localctx).statement =  ((StmtContext)_localctx).scope.scope_;
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class AssignStmtContext extends ParserRuleContext {
		public smallc::AssignStmtNode* assignment;
		public VarContext var;
		public ExprContext expr;
		public VarContext var() {
			return getRuleContext(VarContext.class,0);
		}
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public AssignStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignStmt; }
	}

	public final AssignStmtContext assignStmt() throws RecognitionException {
		AssignStmtContext _localctx = new AssignStmtContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_assignStmt);

		    ((AssignStmtContext)_localctx).assignment =  new smallc::AssignStmtNode();
		    _localctx.assignment->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(233);
			((AssignStmtContext)_localctx).var = var();
			setState(234);
			match(T__12);
			setState(235);
			((AssignStmtContext)_localctx).expr = expr(0);
			setState(236);
			match(T__2);

			        _localctx.assignment->setTarget(((AssignStmtContext)_localctx).var.node);
			        _localctx.assignment->setValue(((AssignStmtContext)_localctx).expr.node);
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class IfStmtContext extends ParserRuleContext {
		public smallc::IfStmtNode* ifNode;
		public ExprContext cond;
		public StmtContext then;
		public StmtContext else_;
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public IfStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ifStmt; }
	}

	public final IfStmtContext ifStmt() throws RecognitionException {
		IfStmtContext _localctx = new IfStmtContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_ifStmt);
		try {
			setState(255);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(239);
				match(T__13);
				setState(240);
				match(T__5);
				setState(241);
				((IfStmtContext)_localctx).cond = expr(0);
				setState(242);
				match(T__6);
				setState(243);
				((IfStmtContext)_localctx).then = stmt();

				        ((IfStmtContext)_localctx).ifNode =  new smallc::IfStmtNode(((IfStmtContext)_localctx).cond.node, ((IfStmtContext)_localctx).then.statement);
				        _localctx.ifNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(246);
				match(T__13);
				setState(247);
				match(T__5);
				setState(248);
				((IfStmtContext)_localctx).cond = expr(0);
				setState(249);
				match(T__6);
				setState(250);
				((IfStmtContext)_localctx).then = stmt();
				setState(251);
				match(T__14);
				setState(252);
				((IfStmtContext)_localctx).else_ = stmt();

				        ((IfStmtContext)_localctx).ifNode =  new smallc::IfStmtNode(((IfStmtContext)_localctx).cond.node, ((IfStmtContext)_localctx).then.statement, ((IfStmtContext)_localctx).else_.statement);
				        _localctx.ifNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
				        _localctx.ifNode->setHasElse(true);
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class WhileStmtContext extends ParserRuleContext {
		public smallc::WhileStmtNode* whileNode;
		public ExprContext cond;
		public StmtContext body;
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public StmtContext stmt() {
			return getRuleContext(StmtContext.class,0);
		}
		public WhileStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whileStmt; }
	}

	public final WhileStmtContext whileStmt() throws RecognitionException {
		WhileStmtContext _localctx = new WhileStmtContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_whileStmt);

		    ((WhileStmtContext)_localctx).whileNode =  new smallc::WhileStmtNode();
		    _localctx.whileNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(257);
			match(T__15);
			setState(258);
			match(T__5);
			setState(259);
			((WhileStmtContext)_localctx).cond = expr(0);
			setState(260);
			match(T__6);
			setState(261);
			((WhileStmtContext)_localctx).body = stmt();

			        _localctx.whileNode->setCondition(((WhileStmtContext)_localctx).cond.node);
			        _localctx.whileNode->setBody(((WhileStmtContext)_localctx).body.statement);
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class RetStmtContext extends ParserRuleContext {
		public smallc::ReturnStmtNode* returnNode;
		public ExprContext val;
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public RetStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_retStmt; }
	}

	public final RetStmtContext retStmt() throws RecognitionException {
		RetStmtContext _localctx = new RetStmtContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_retStmt);

		    ((RetStmtContext)_localctx).returnNode =  new smallc::ReturnStmtNode();
		    _localctx.returnNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

		try {
			setState(272);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(264);
				match(T__16);
				setState(265);
				((RetStmtContext)_localctx).val = expr(0);
				setState(266);
				match(T__2);

				        _localctx.returnNode->setReturn(((RetStmtContext)_localctx).val.node);
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(269);
				match(T__16);
				setState(270);
				match(T__2);

				        // Empty return - the constructor already creates a void return
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExprContext extends ParserRuleContext {
		public smallc::ExprNode* node;
		public ExprContext l;
		public IntExprContext intExpr;
		public ExprContext e;
		public FcnNameContext n;
		public ArgsContext args;
		public Token op;
		public ExprContext r;
		public IntExprContext intExpr() {
			return getRuleContext(IntExprContext.class,0);
		}
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ArgsContext args() {
			return getRuleContext(ArgsContext.class,0);
		}
		public FcnNameContext fcnName() {
			return getRuleContext(FcnNameContext.class,0);
		}
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 42;
		enterRecursionRule(_localctx, 42, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(293);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
			case 1:
				{
				setState(275);
				((ExprContext)_localctx).intExpr = intExpr(0);
				 
				        ((ExprContext)_localctx).node =  ((ExprContext)_localctx).intExpr.exprNode; 
				    
				}
				break;
			case 2:
				{
				setState(278);
				match(T__5);
				setState(279);
				((ExprContext)_localctx).e = expr(0);
				setState(280);
				match(T__6);
				 
				        ((ExprContext)_localctx).node =  ((ExprContext)_localctx).e.node;
				    
				}
				break;
			case 3:
				{
				setState(283);
				((ExprContext)_localctx).n = fcnName();
				setState(284);
				match(T__5);
				setState(285);
				((ExprContext)_localctx).args = args();
				setState(286);
				match(T__6);

				        smallc::CallExprNode* call = new smallc::CallExprNode(((ExprContext)_localctx).n.node);
				        for(auto arg : ((ExprContext)_localctx).args.arguments) {
				            call->addArgument(arg);
				        }
				        call->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
				        ((ExprContext)_localctx).node =  call;
				    
				}
				break;
			case 4:
				{
				setState(289);
				((ExprContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==T__17 || _la==T__18) ) {
					((ExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(290);
				((ExprContext)_localctx).e = expr(5);

				        smallc::UnaryExprNode* unary = new smallc::UnaryExprNode(((ExprContext)_localctx).e.node);
				        unary->setOpcode((((ExprContext)_localctx).op!=null?((ExprContext)_localctx).op.getText():null));
				        unary->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
				        ((ExprContext)_localctx).node =  unary;
				    
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(317);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,18,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(315);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
					case 1:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						_localctx.l = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(295);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(296);
						((ExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 15728640L) != 0)) ) {
							((ExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(297);
						((ExprContext)_localctx).r = expr(5);

						                  smallc::BinaryExprNode* binary = new smallc::BinaryExprNode(((ExprContext)_localctx).l.node, ((ExprContext)_localctx).r.node);
						                  binary->setOpcode((((ExprContext)_localctx).op!=null?((ExprContext)_localctx).op.getText():null));
						                  binary->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
						                  smallc::BoolExprNode* boolExpr = new smallc::BoolExprNode(binary);
						                  boolExpr->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
						                  ((ExprContext)_localctx).node =  boolExpr;   
						              
						}
						break;
					case 2:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						_localctx.l = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(300);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(301);
						((ExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__23 || _la==T__24) ) {
							((ExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(302);
						((ExprContext)_localctx).r = expr(4);

						                  smallc::BinaryExprNode* binary = new smallc::BinaryExprNode(((ExprContext)_localctx).l.node, ((ExprContext)_localctx).r.node);
						                  binary->setOpcode((((ExprContext)_localctx).op!=null?((ExprContext)_localctx).op.getText():null));
						                  binary->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
						                  smallc::BoolExprNode* boolExpr = new smallc::BoolExprNode(binary);
						                  ((ExprContext)_localctx).node =  boolExpr;
						              
						}
						break;
					case 3:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						_localctx.l = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(305);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(306);
						((ExprContext)_localctx).op = match(T__25);
						setState(307);
						((ExprContext)_localctx).r = expr(3);

						                  smallc::BinaryExprNode* binary = new smallc::BinaryExprNode(((ExprContext)_localctx).l.node, ((ExprContext)_localctx).r.node);
						                  binary->setOpcode((((ExprContext)_localctx).op!=null?((ExprContext)_localctx).op.getText():null));
						                  binary->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
						                  smallc::BoolExprNode* boolExpr = new smallc::BoolExprNode(binary);
						                  boolExpr->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
						                  ((ExprContext)_localctx).node =  boolExpr;
						              
						}
						break;
					case 4:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						_localctx.l = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(310);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(311);
						((ExprContext)_localctx).op = match(T__26);
						setState(312);
						((ExprContext)_localctx).r = expr(2);

						                  smallc::BinaryExprNode* binary = new smallc::BinaryExprNode(((ExprContext)_localctx).l.node, ((ExprContext)_localctx).r.node);
						                  binary->setOpcode((((ExprContext)_localctx).op!=null?((ExprContext)_localctx).op.getText():null));
						                  binary->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
						                  smallc::BoolExprNode* boolExpr = new smallc::BoolExprNode(binary);
						                  boolExpr->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
						                  ((ExprContext)_localctx).node =  boolExpr;
						              
						}
						break;
					}
					} 
				}
				setState(319);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,18,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class IntExprContext extends ParserRuleContext {
		public smallc::IntExprNode* exprNode;
		public IntExprContext l;
		public VarContext var;
		public ConstantContext constant;
		public IntExprContext e;
		public Token op;
		public IntExprContext r;
		public VarContext var() {
			return getRuleContext(VarContext.class,0);
		}
		public ConstantContext constant() {
			return getRuleContext(ConstantContext.class,0);
		}
		public List<IntExprContext> intExpr() {
			return getRuleContexts(IntExprContext.class);
		}
		public IntExprContext intExpr(int i) {
			return getRuleContext(IntExprContext.class,i);
		}
		public IntExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_intExpr; }
	}

	public final IntExprContext intExpr() throws RecognitionException {
		return intExpr(0);
	}

	private IntExprContext intExpr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		IntExprContext _localctx = new IntExprContext(_ctx, _parentState);
		IntExprContext _prevctx = _localctx;
		int _startState = 44;
		enterRecursionRule(_localctx, 44, RULE_intExpr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(332);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ID:
				{
				setState(321);
				((IntExprContext)_localctx).var = var();
				 
				        ((IntExprContext)_localctx).exprNode =  new smallc::IntExprNode(((IntExprContext)_localctx).var.node);
				        _localctx.exprNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
				    
				}
				break;
			case T__18:
			case BOOL:
			case INT:
				{
				setState(324);
				((IntExprContext)_localctx).constant = constant();

				        ((IntExprContext)_localctx).exprNode =  new smallc::IntExprNode(((IntExprContext)_localctx).constant.node);
				        _localctx.exprNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
				    
				}
				break;
			case T__5:
				{
				setState(327);
				match(T__5);
				setState(328);
				((IntExprContext)_localctx).e = intExpr(0);
				setState(329);
				match(T__6);

				        ((IntExprContext)_localctx).exprNode =  ((IntExprContext)_localctx).e.exprNode;
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(346);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(344);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
					case 1:
						{
						_localctx = new IntExprContext(_parentctx, _parentState);
						_localctx.l = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_intExpr);
						setState(334);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(335);
						((IntExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__27 || _la==T__28) ) {
							((IntExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(336);
						((IntExprContext)_localctx).r = intExpr(4);

						                  smallc::BinaryExprNode* binary = new smallc::BinaryExprNode(((IntExprContext)_localctx).l.exprNode, ((IntExprContext)_localctx).r.exprNode);
						                  binary->setOpcode((((IntExprContext)_localctx).op!=null?((IntExprContext)_localctx).op.getText():null));
						                  binary->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
						                  ((IntExprContext)_localctx).exprNode =  new smallc::IntExprNode();
						                  _localctx.exprNode->setValue(binary);
						                  _localctx.exprNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

						              
						}
						break;
					case 2:
						{
						_localctx = new IntExprContext(_parentctx, _parentState);
						_localctx.l = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_intExpr);
						setState(339);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(340);
						((IntExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__18 || _la==T__29) ) {
							((IntExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(341);
						((IntExprContext)_localctx).r = intExpr(3);

						                  smallc::BinaryExprNode* binary = new smallc::BinaryExprNode(((IntExprContext)_localctx).l.exprNode, ((IntExprContext)_localctx).r.exprNode);
						                  binary->setOpcode((((IntExprContext)_localctx).op!=null?((IntExprContext)_localctx).op.getText():null));
						                  binary->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
						                  ((IntExprContext)_localctx).exprNode =  new smallc::IntExprNode();
						                  _localctx.exprNode->setValue(binary);
						                  _localctx.exprNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
						              
						}
						break;
					}
					} 
				}
				setState(348);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VarContext extends ParserRuleContext {
		public smallc::ReferenceExprNode* node;
		public VarNameContext v;
		public ArrNameContext a;
		public IntExprContext idx;
		public VarNameContext varName() {
			return getRuleContext(VarNameContext.class,0);
		}
		public ArrNameContext arrName() {
			return getRuleContext(ArrNameContext.class,0);
		}
		public IntExprContext intExpr() {
			return getRuleContext(IntExprContext.class,0);
		}
		public VarContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var; }
	}

	public final VarContext var() throws RecognitionException {
		VarContext _localctx = new VarContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_var);
		try {
			setState(358);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,22,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(349);
				((VarContext)_localctx).v = varName();

				        ((VarContext)_localctx).node =  new smallc::ReferenceExprNode(((VarContext)_localctx).v.node);
				        _localctx.node->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(352);
				((VarContext)_localctx).a = arrName();
				setState(353);
				match(T__3);
				setState(354);
				((VarContext)_localctx).idx = intExpr(0);
				setState(355);
				match(T__4);

				        ((VarContext)_localctx).node =  new smallc::ReferenceExprNode(((VarContext)_localctx).a.node);
				        _localctx.node->setIndex(((VarContext)_localctx).idx.exprNode);
				        _localctx.node->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ParamsContext extends ParserRuleContext {
		public std::vector<smallc::ParameterNode*> parameters;
		public ParamListContext p;
		public ParamListContext paramList() {
			return getRuleContext(ParamListContext.class,0);
		}
		public ParamsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_params; }
	}

	public final ParamsContext params() throws RecognitionException {
		ParamsContext _localctx = new ParamsContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_params);

		    ((ParamsContext)_localctx).parameters =  std::vector<smallc::ParameterNode*>();

		try {
			setState(364);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__7:
			case T__8:
				enterOuterAlt(_localctx, 1);
				{
				setState(360);
				((ParamsContext)_localctx).p = paramList();

				        ((ParamsContext)_localctx).parameters =  ((ParamsContext)_localctx).p.parameterList;
				    
				}
				break;
			case T__6:
				enterOuterAlt(_localctx, 2);
				{

				        // Empty parameter list
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ParamEntryContext extends ParserRuleContext {
		public smallc::ParameterNode* param;
		public VarTypeContext t;
		public VarNameContext name;
		public ArrNameContext arrname;
		public VarTypeContext varType() {
			return getRuleContext(VarTypeContext.class,0);
		}
		public VarNameContext varName() {
			return getRuleContext(VarNameContext.class,0);
		}
		public ArrNameContext arrName() {
			return getRuleContext(ArrNameContext.class,0);
		}
		public ParamEntryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_paramEntry; }
	}

	public final ParamEntryContext paramEntry() throws RecognitionException {
		ParamEntryContext _localctx = new ParamEntryContext(_ctx, getState());
		enterRule(_localctx, 50, RULE_paramEntry);

		    ((ParamEntryContext)_localctx).param =  new smallc::ParameterNode();
		    _localctx.param->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

		try {
			setState(375);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,24,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(366);
				((ParamEntryContext)_localctx).t = varType();
				setState(367);
				((ParamEntryContext)_localctx).name = varName();

				        ((ParamEntryContext)_localctx).param =  new smallc::ParameterNode(((ParamEntryContext)_localctx).t.type, ((ParamEntryContext)_localctx).name.node);
				        _localctx.param->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(370);
				((ParamEntryContext)_localctx).t = varType();
				setState(371);
				((ParamEntryContext)_localctx).arrname = arrName();
				setState(372);
				match(T__30);

				        smallc::ArrayTypeNode* arrayType = new smallc::ArrayTypeNode(((ParamEntryContext)_localctx).t.type);
				        ((ParamEntryContext)_localctx).param =  new smallc::ParameterNode(arrayType, ((ParamEntryContext)_localctx).arrname.node);
				        _localctx.param->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ParamListContext extends ParserRuleContext {
		public std::vector<smallc::ParameterNode*> parameterList;
		public ParamEntryContext p;
		public ParamListContext pl;
		public ParamEntryContext paramEntry() {
			return getRuleContext(ParamEntryContext.class,0);
		}
		public ParamListContext paramList() {
			return getRuleContext(ParamListContext.class,0);
		}
		public ParamListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_paramList; }
	}

	public final ParamListContext paramList() throws RecognitionException {
		ParamListContext _localctx = new ParamListContext(_ctx, getState());
		enterRule(_localctx, 52, RULE_paramList);

		    ((ParamListContext)_localctx).parameterList =  std::vector<smallc::ParameterNode*>();

		try {
			setState(385);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,25,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(377);
				((ParamListContext)_localctx).p = paramEntry();

				        _localctx.parameterList.push_back(((ParamListContext)_localctx).p.param);
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(380);
				((ParamListContext)_localctx).p = paramEntry();
				setState(381);
				match(T__31);
				setState(382);
				((ParamListContext)_localctx).pl = paramList();

				        _localctx.parameterList.push_back(((ParamListContext)_localctx).p.param);
				        _localctx.parameterList.insert(_localctx.parameterList.end(), ((ParamListContext)_localctx).pl.parameterList.begin(), ((ParamListContext)_localctx).pl.parameterList.end());
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArgsContext extends ParserRuleContext {
		public std::vector<smallc::ArgumentNode*> arguments;
		public ArgListContext a;
		public ArgListContext argList() {
			return getRuleContext(ArgListContext.class,0);
		}
		public ArgsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_args; }
	}

	public final ArgsContext args() throws RecognitionException {
		ArgsContext _localctx = new ArgsContext(_ctx, getState());
		enterRule(_localctx, 54, RULE_args);

		    ((ArgsContext)_localctx).arguments =  std::vector<smallc::ArgumentNode*>();

		try {
			setState(391);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__5:
			case T__17:
			case T__18:
			case BOOL:
			case ID:
			case INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(387);
				((ArgsContext)_localctx).a = argList();

				        ((ArgsContext)_localctx).arguments =  ((ArgsContext)_localctx).a.argumentList;
				    
				}
				break;
			case T__6:
				enterOuterAlt(_localctx, 2);
				{

				        // Empty argument list
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArgEntryContext extends ParserRuleContext {
		public smallc::ArgumentNode* arg;
		public ExprContext e;
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ArgEntryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argEntry; }
	}

	public final ArgEntryContext argEntry() throws RecognitionException {
		ArgEntryContext _localctx = new ArgEntryContext(_ctx, getState());
		enterRule(_localctx, 56, RULE_argEntry);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(393);
			((ArgEntryContext)_localctx).e = expr(0);

			        ((ArgEntryContext)_localctx).arg =  new smallc::ArgumentNode(((ArgEntryContext)_localctx).e.node);
			        _localctx.arg->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArgListContext extends ParserRuleContext {
		public std::vector<smallc::ArgumentNode*> argumentList;
		public ArgEntryContext a;
		public ArgListContext al;
		public ArgEntryContext argEntry() {
			return getRuleContext(ArgEntryContext.class,0);
		}
		public ArgListContext argList() {
			return getRuleContext(ArgListContext.class,0);
		}
		public ArgListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argList; }
	}

	public final ArgListContext argList() throws RecognitionException {
		ArgListContext _localctx = new ArgListContext(_ctx, getState());
		enterRule(_localctx, 58, RULE_argList);

		    ((ArgListContext)_localctx).argumentList =  std::vector<smallc::ArgumentNode*>();

		try {
			setState(404);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,27,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(396);
				((ArgListContext)_localctx).a = argEntry();

				        _localctx.argumentList.push_back(((ArgListContext)_localctx).a.arg);
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(399);
				((ArgListContext)_localctx).a = argEntry();
				setState(400);
				match(T__31);
				setState(401);
				((ArgListContext)_localctx).al = argList();

				        _localctx.argumentList.push_back(((ArgListContext)_localctx).a.arg);
				        _localctx.argumentList.insert(_localctx.argumentList.end(), ((ArgListContext)_localctx).al.argumentList.begin(), ((ArgListContext)_localctx).al.argumentList.end());
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VarNameContext extends ParserRuleContext {
		public smallc::IdentifierNode* node;
		public Token id;
		public TerminalNode ID() { return getToken(smallCParser.ID, 0); }
		public VarNameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varName; }
	}

	public final VarNameContext varName() throws RecognitionException {
		VarNameContext _localctx = new VarNameContext(_ctx, getState());
		enterRule(_localctx, 60, RULE_varName);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(406);
			((VarNameContext)_localctx).id = match(ID);

			        ((VarNameContext)_localctx).node =  new smallc::IdentifierNode((((VarNameContext)_localctx).id!=null?((VarNameContext)_localctx).id.getText():null));
			        _localctx.node->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArrNameContext extends ParserRuleContext {
		public smallc::IdentifierNode* node;
		public Token id;
		public TerminalNode ID() { return getToken(smallCParser.ID, 0); }
		public ArrNameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arrName; }
	}

	public final ArrNameContext arrName() throws RecognitionException {
		ArrNameContext _localctx = new ArrNameContext(_ctx, getState());
		enterRule(_localctx, 62, RULE_arrName);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(409);
			((ArrNameContext)_localctx).id = match(ID);

			        ((ArrNameContext)_localctx).node =  new smallc::IdentifierNode((((ArrNameContext)_localctx).id!=null?((ArrNameContext)_localctx).id.getText():null));
			        _localctx.node->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FcnNameContext extends ParserRuleContext {
		public smallc::IdentifierNode* node;
		public Token id;
		public TerminalNode ID() { return getToken(smallCParser.ID, 0); }
		public FcnNameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fcnName; }
	}

	public final FcnNameContext fcnName() throws RecognitionException {
		FcnNameContext _localctx = new FcnNameContext(_ctx, getState());
		enterRule(_localctx, 64, RULE_fcnName);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(412);
			((FcnNameContext)_localctx).id = match(ID);

			        ((FcnNameContext)_localctx).node =  new smallc::IdentifierNode((((FcnNameContext)_localctx).id!=null?((FcnNameContext)_localctx).id.getText():null));
			        _localctx.node->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class IntConstContext extends ParserRuleContext {
		public smallc::IntConstantNode* node;
		public Token i;
		public TerminalNode INT() { return getToken(smallCParser.INT, 0); }
		public IntConstContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_intConst; }
	}

	public final IntConstContext intConst() throws RecognitionException {
		IntConstContext _localctx = new IntConstContext(_ctx, getState());
		enterRule(_localctx, 66, RULE_intConst);
		try {
			setState(420);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(415);
				((IntConstContext)_localctx).i = match(INT);

				        ((IntConstContext)_localctx).node =  new smallc::IntConstantNode((((IntConstContext)_localctx).i!=null?((IntConstContext)_localctx).i.getText():null));
				        _localctx.node->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
				    
				}
				break;
			case T__18:
				enterOuterAlt(_localctx, 2);
				{
				setState(417);
				match(T__18);
				setState(418);
				((IntConstContext)_localctx).i = match(INT);

				        ((IntConstContext)_localctx).node =  new smallc::IntConstantNode("-" + (((IntConstContext)_localctx).i!=null?((IntConstContext)_localctx).i.getText():null));
				        _localctx.node->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 21:
			return expr_sempred((ExprContext)_localctx, predIndex);
		case 22:
			return intExpr_sempred((IntExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 4);
		case 1:
			return precpred(_ctx, 3);
		case 2:
			return precpred(_ctx, 2);
		case 3:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean intExpr_sempred(IntExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 4:
			return precpred(_ctx, 3);
		case 5:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001%\u01a7\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002\u0018\u0007\u0018"+
		"\u0002\u0019\u0007\u0019\u0002\u001a\u0007\u001a\u0002\u001b\u0007\u001b"+
		"\u0002\u001c\u0007\u001c\u0002\u001d\u0007\u001d\u0002\u001e\u0007\u001e"+
		"\u0002\u001f\u0007\u001f\u0002 \u0007 \u0002!\u0007!\u0001\u0000\u0001"+
		"\u0000\u0001\u0000\u0001\u0000\u0003\u0000I\b\u0000\u0001\u0000\u0001"+
		"\u0000\u0001\u0000\u0005\u0000N\b\u0000\n\u0000\f\u0000Q\t\u0000\u0001"+
		"\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0003\u0002d\b"+
		"\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001"+
		"\u0003\u0001\u0003\u0003\u0003m\b\u0003\u0001\u0004\u0001\u0004\u0001"+
		"\u0004\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0003\u0005{\b\u0005\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0003\u0007\u008c\b\u0007\u0001\b\u0001"+
		"\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\t\u0001\t\u0001"+
		"\t\u0001\t\u0001\t\u0001\t\u0001\t\u0003\t\u009d\b\t\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0003\u000b\u00ab\b\u000b\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0003\f\u00b2\b\f\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0003\r\u00ba\b\r\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0005"+
		"\u000f\u00c6\b\u000f\n\u000f\f\u000f\u00c9\t\u000f\u0001\u000f\u0001\u000f"+
		"\u0001\u000f\u0005\u000f\u00ce\b\u000f\n\u000f\f\u000f\u00d1\t\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001"+
		"\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001"+
		"\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001"+
		"\u0010\u0001\u0010\u0001\u0010\u0003\u0010\u00e8\b\u0010\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0012\u0001"+
		"\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001"+
		"\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001"+
		"\u0012\u0001\u0012\u0001\u0012\u0003\u0012\u0100\b\u0012\u0001\u0013\u0001"+
		"\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0003\u0014\u0111\b\u0014\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0003\u0015\u0126"+
		"\b\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0005\u0015\u013c\b\u0015\n\u0015\f\u0015"+
		"\u013f\t\u0015\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0003\u0016\u014d\b\u0016\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0005\u0016\u0159\b\u0016\n\u0016\f\u0016\u015c\t\u0016\u0001"+
		"\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001"+
		"\u0017\u0001\u0017\u0001\u0017\u0003\u0017\u0167\b\u0017\u0001\u0018\u0001"+
		"\u0018\u0001\u0018\u0001\u0018\u0003\u0018\u016d\b\u0018\u0001\u0019\u0001"+
		"\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001"+
		"\u0019\u0001\u0019\u0003\u0019\u0178\b\u0019\u0001\u001a\u0001\u001a\u0001"+
		"\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0003"+
		"\u001a\u0182\b\u001a\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001b\u0003"+
		"\u001b\u0188\b\u001b\u0001\u001c\u0001\u001c\u0001\u001c\u0001\u001d\u0001"+
		"\u001d\u0001\u001d\u0001\u001d\u0001\u001d\u0001\u001d\u0001\u001d\u0001"+
		"\u001d\u0003\u001d\u0195\b\u001d\u0001\u001e\u0001\u001e\u0001\u001e\u0001"+
		"\u001f\u0001\u001f\u0001\u001f\u0001 \u0001 \u0001 \u0001!\u0001!\u0001"+
		"!\u0001!\u0001!\u0003!\u01a5\b!\u0001!\u0000\u0002*,\"\u0000\u0002\u0004"+
		"\u0006\b\n\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e \""+
		"$&(*,.02468:<>@B\u0000\u0005\u0001\u0000\u0012\u0013\u0001\u0000\u0014"+
		"\u0017\u0001\u0000\u0018\u0019\u0001\u0000\u001c\u001d\u0002\u0000\u0013"+
		"\u0013\u001e\u001e\u01ac\u0000H\u0001\u0000\u0000\u0000\u0002T\u0001\u0000"+
		"\u0000\u0000\u0004c\u0001\u0000\u0000\u0000\u0006l\u0001\u0000\u0000\u0000"+
		"\bn\u0001\u0000\u0000\u0000\nz\u0001\u0000\u0000\u0000\f|\u0001\u0000"+
		"\u0000\u0000\u000e\u008b\u0001\u0000\u0000\u0000\u0010\u008d\u0001\u0000"+
		"\u0000\u0000\u0012\u009c\u0001\u0000\u0000\u0000\u0014\u009e\u0001\u0000"+
		"\u0000\u0000\u0016\u00aa\u0001\u0000\u0000\u0000\u0018\u00b1\u0001\u0000"+
		"\u0000\u0000\u001a\u00b9\u0001\u0000\u0000\u0000\u001c\u00bb\u0001\u0000"+
		"\u0000\u0000\u001e\u00be\u0001\u0000\u0000\u0000 \u00e7\u0001\u0000\u0000"+
		"\u0000\"\u00e9\u0001\u0000\u0000\u0000$\u00ff\u0001\u0000\u0000\u0000"+
		"&\u0101\u0001\u0000\u0000\u0000(\u0110\u0001\u0000\u0000\u0000*\u0125"+
		"\u0001\u0000\u0000\u0000,\u014c\u0001\u0000\u0000\u0000.\u0166\u0001\u0000"+
		"\u0000\u00000\u016c\u0001\u0000\u0000\u00002\u0177\u0001\u0000\u0000\u0000"+
		"4\u0181\u0001\u0000\u0000\u00006\u0187\u0001\u0000\u0000\u00008\u0189"+
		"\u0001\u0000\u0000\u0000:\u0194\u0001\u0000\u0000\u0000<\u0196\u0001\u0000"+
		"\u0000\u0000>\u0199\u0001\u0000\u0000\u0000@\u019c\u0001\u0000\u0000\u0000"+
		"B\u01a4\u0001\u0000\u0000\u0000DE\u0003\u0002\u0001\u0000EF\u0006\u0000"+
		"\uffff\uffff\u0000FI\u0001\u0000\u0000\u0000GI\u0001\u0000\u0000\u0000"+
		"HD\u0001\u0000\u0000\u0000HG\u0001\u0000\u0000\u0000IO\u0001\u0000\u0000"+
		"\u0000JK\u0003\u0004\u0002\u0000KL\u0006\u0000\uffff\uffff\u0000LN\u0001"+
		"\u0000\u0000\u0000MJ\u0001\u0000\u0000\u0000NQ\u0001\u0000\u0000\u0000"+
		"OM\u0001\u0000\u0000\u0000OP\u0001\u0000\u0000\u0000PR\u0001\u0000\u0000"+
		"\u0000QO\u0001\u0000\u0000\u0000RS\u0005\u0000\u0000\u0001S\u0001\u0001"+
		"\u0000\u0000\u0000TU\u0005\u0001\u0000\u0000UV\u0005\u0002\u0000\u0000"+
		"V\u0003\u0001\u0000\u0000\u0000WX\u0003\u0006\u0003\u0000XY\u0006\u0002"+
		"\uffff\uffff\u0000Yd\u0001\u0000\u0000\u0000Z[\u0003\n\u0005\u0000[\\"+
		"\u0006\u0002\uffff\uffff\u0000\\d\u0001\u0000\u0000\u0000]^\u0003\u000e"+
		"\u0007\u0000^_\u0006\u0002\uffff\uffff\u0000_d\u0001\u0000\u0000\u0000"+
		"`a\u0003\u0012\t\u0000ab\u0006\u0002\uffff\uffff\u0000bd\u0001\u0000\u0000"+
		"\u0000cW\u0001\u0000\u0000\u0000cZ\u0001\u0000\u0000\u0000c]\u0001\u0000"+
		"\u0000\u0000c`\u0001\u0000\u0000\u0000d\u0005\u0001\u0000\u0000\u0000"+
		"ef\u0003\b\u0004\u0000fg\u0006\u0003\uffff\uffff\u0000gm\u0001\u0000\u0000"+
		"\u0000hi\u0003\b\u0004\u0000ij\u0003\u0006\u0003\u0000jk\u0006\u0003\uffff"+
		"\uffff\u0000km\u0001\u0000\u0000\u0000le\u0001\u0000\u0000\u0000lh\u0001"+
		"\u0000\u0000\u0000m\u0007\u0001\u0000\u0000\u0000no\u0003\u0016\u000b"+
		"\u0000op\u0003<\u001e\u0000pq\u0005\u0003\u0000\u0000qr\u0006\u0004\uffff"+
		"\uffff\u0000r\t\u0001\u0000\u0000\u0000st\u0003\f\u0006\u0000tu\u0006"+
		"\u0005\uffff\uffff\u0000u{\u0001\u0000\u0000\u0000vw\u0003\f\u0006\u0000"+
		"wx\u0003\n\u0005\u0000xy\u0006\u0005\uffff\uffff\u0000y{\u0001\u0000\u0000"+
		"\u0000zs\u0001\u0000\u0000\u0000zv\u0001\u0000\u0000\u0000{\u000b\u0001"+
		"\u0000\u0000\u0000|}\u0003\u0016\u000b\u0000}~\u0003>\u001f\u0000~\u007f"+
		"\u0005\u0004\u0000\u0000\u007f\u0080\u0003B!\u0000\u0080\u0081\u0005\u0005"+
		"\u0000\u0000\u0081\u0082\u0005\u0003\u0000\u0000\u0082\u0083\u0006\u0006"+
		"\uffff\uffff\u0000\u0083\r\u0001\u0000\u0000\u0000\u0084\u0085\u0003\u0010"+
		"\b\u0000\u0085\u0086\u0006\u0007\uffff\uffff\u0000\u0086\u008c\u0001\u0000"+
		"\u0000\u0000\u0087\u0088\u0003\u0010\b\u0000\u0088\u0089\u0003\u000e\u0007"+
		"\u0000\u0089\u008a\u0006\u0007\uffff\uffff\u0000\u008a\u008c\u0001\u0000"+
		"\u0000\u0000\u008b\u0084\u0001\u0000\u0000\u0000\u008b\u0087\u0001\u0000"+
		"\u0000\u0000\u008c\u000f\u0001\u0000\u0000\u0000\u008d\u008e\u0003\u0018"+
		"\f\u0000\u008e\u008f\u0003@ \u0000\u008f\u0090\u0005\u0006\u0000\u0000"+
		"\u0090\u0091\u00030\u0018\u0000\u0091\u0092\u0005\u0007\u0000\u0000\u0092"+
		"\u0093\u0005\u0003\u0000\u0000\u0093\u0094\u0006\b\uffff\uffff\u0000\u0094"+
		"\u0011\u0001\u0000\u0000\u0000\u0095\u0096\u0003\u0014\n\u0000\u0096\u0097"+
		"\u0006\t\uffff\uffff\u0000\u0097\u009d\u0001\u0000\u0000\u0000\u0098\u0099"+
		"\u0003\u0014\n\u0000\u0099\u009a\u0003\u0012\t\u0000\u009a\u009b\u0006"+
		"\t\uffff\uffff\u0000\u009b\u009d\u0001\u0000\u0000\u0000\u009c\u0095\u0001"+
		"\u0000\u0000\u0000\u009c\u0098\u0001\u0000\u0000\u0000\u009d\u0013\u0001"+
		"\u0000\u0000\u0000\u009e\u009f\u0003\u0018\f\u0000\u009f\u00a0\u0003@"+
		" \u0000\u00a0\u00a1\u0005\u0006\u0000\u0000\u00a1\u00a2\u00030\u0018\u0000"+
		"\u00a2\u00a3\u0005\u0007\u0000\u0000\u00a3\u00a4\u0003\u001e\u000f\u0000"+
		"\u00a4\u00a5\u0006\n\uffff\uffff\u0000\u00a5\u0015\u0001\u0000\u0000\u0000"+
		"\u00a6\u00a7\u0005\b\u0000\u0000\u00a7\u00ab\u0006\u000b\uffff\uffff\u0000"+
		"\u00a8\u00a9\u0005\t\u0000\u0000\u00a9\u00ab\u0006\u000b\uffff\uffff\u0000"+
		"\u00aa\u00a6\u0001\u0000\u0000\u0000\u00aa\u00a8\u0001\u0000\u0000\u0000"+
		"\u00ab\u0017\u0001\u0000\u0000\u0000\u00ac\u00ad\u0005\n\u0000\u0000\u00ad"+
		"\u00b2\u0006\f\uffff\uffff\u0000\u00ae\u00af\u0003\u0016\u000b\u0000\u00af"+
		"\u00b0\u0006\f\uffff\uffff\u0000\u00b0\u00b2\u0001\u0000\u0000\u0000\u00b1"+
		"\u00ac\u0001\u0000\u0000\u0000\u00b1\u00ae\u0001\u0000\u0000\u0000\u00b2"+
		"\u0019\u0001\u0000\u0000\u0000\u00b3\u00b4\u0003\u001c\u000e\u0000\u00b4"+
		"\u00b5\u0006\r\uffff\uffff\u0000\u00b5\u00ba\u0001\u0000\u0000\u0000\u00b6"+
		"\u00b7\u0003B!\u0000\u00b7\u00b8\u0006\r\uffff\uffff\u0000\u00b8\u00ba"+
		"\u0001\u0000\u0000\u0000\u00b9\u00b3\u0001\u0000\u0000\u0000\u00b9\u00b6"+
		"\u0001\u0000\u0000\u0000\u00ba\u001b\u0001\u0000\u0000\u0000\u00bb\u00bc"+
		"\u0005!\u0000\u0000\u00bc\u00bd\u0006\u000e\uffff\uffff\u0000\u00bd\u001d"+
		"\u0001\u0000\u0000\u0000\u00be\u00c7\u0005\u000b\u0000\u0000\u00bf\u00c0"+
		"\u0003\b\u0004\u0000\u00c0\u00c1\u0006\u000f\uffff\uffff\u0000\u00c1\u00c6"+
		"\u0001\u0000\u0000\u0000\u00c2\u00c3\u0003\f\u0006\u0000\u00c3\u00c4\u0006"+
		"\u000f\uffff\uffff\u0000\u00c4\u00c6\u0001\u0000\u0000\u0000\u00c5\u00bf"+
		"\u0001\u0000\u0000\u0000\u00c5\u00c2\u0001\u0000\u0000\u0000\u00c6\u00c9"+
		"\u0001\u0000\u0000\u0000\u00c7\u00c5\u0001\u0000\u0000\u0000\u00c7\u00c8"+
		"\u0001\u0000\u0000\u0000\u00c8\u00cf\u0001\u0000\u0000\u0000\u00c9\u00c7"+
		"\u0001\u0000\u0000\u0000\u00ca\u00cb\u0003 \u0010\u0000\u00cb\u00cc\u0006"+
		"\u000f\uffff\uffff\u0000\u00cc\u00ce\u0001\u0000\u0000\u0000\u00cd\u00ca"+
		"\u0001\u0000\u0000\u0000\u00ce\u00d1\u0001\u0000\u0000\u0000\u00cf\u00cd"+
		"\u0001\u0000\u0000\u0000\u00cf\u00d0\u0001\u0000\u0000\u0000\u00d0\u00d2"+
		"\u0001\u0000\u0000\u0000\u00d1\u00cf\u0001\u0000\u0000\u0000\u00d2\u00d3"+
		"\u0005\f\u0000\u0000\u00d3\u001f\u0001\u0000\u0000\u0000\u00d4\u00d5\u0003"+
		"*\u0015\u0000\u00d5\u00d6\u0005\u0003\u0000\u0000\u00d6\u00d7\u0006\u0010"+
		"\uffff\uffff\u0000\u00d7\u00e8\u0001\u0000\u0000\u0000\u00d8\u00d9\u0003"+
		"\"\u0011\u0000\u00d9\u00da\u0006\u0010\uffff\uffff\u0000\u00da\u00e8\u0001"+
		"\u0000\u0000\u0000\u00db\u00dc\u0003$\u0012\u0000\u00dc\u00dd\u0006\u0010"+
		"\uffff\uffff\u0000\u00dd\u00e8\u0001\u0000\u0000\u0000\u00de\u00df\u0003"+
		"&\u0013\u0000\u00df\u00e0\u0006\u0010\uffff\uffff\u0000\u00e0\u00e8\u0001"+
		"\u0000\u0000\u0000\u00e1\u00e2\u0003(\u0014\u0000\u00e2\u00e3\u0006\u0010"+
		"\uffff\uffff\u0000\u00e3\u00e8\u0001\u0000\u0000\u0000\u00e4\u00e5\u0003"+
		"\u001e\u000f\u0000\u00e5\u00e6\u0006\u0010\uffff\uffff\u0000\u00e6\u00e8"+
		"\u0001\u0000\u0000\u0000\u00e7\u00d4\u0001\u0000\u0000\u0000\u00e7\u00d8"+
		"\u0001\u0000\u0000\u0000\u00e7\u00db\u0001\u0000\u0000\u0000\u00e7\u00de"+
		"\u0001\u0000\u0000\u0000\u00e7\u00e1\u0001\u0000\u0000\u0000\u00e7\u00e4"+
		"\u0001\u0000\u0000\u0000\u00e8!\u0001\u0000\u0000\u0000\u00e9\u00ea\u0003"+
		".\u0017\u0000\u00ea\u00eb\u0005\r\u0000\u0000\u00eb\u00ec\u0003*\u0015"+
		"\u0000\u00ec\u00ed\u0005\u0003\u0000\u0000\u00ed\u00ee\u0006\u0011\uffff"+
		"\uffff\u0000\u00ee#\u0001\u0000\u0000\u0000\u00ef\u00f0\u0005\u000e\u0000"+
		"\u0000\u00f0\u00f1\u0005\u0006\u0000\u0000\u00f1\u00f2\u0003*\u0015\u0000"+
		"\u00f2\u00f3\u0005\u0007\u0000\u0000\u00f3\u00f4\u0003 \u0010\u0000\u00f4"+
		"\u00f5\u0006\u0012\uffff\uffff\u0000\u00f5\u0100\u0001\u0000\u0000\u0000"+
		"\u00f6\u00f7\u0005\u000e\u0000\u0000\u00f7\u00f8\u0005\u0006\u0000\u0000"+
		"\u00f8\u00f9\u0003*\u0015\u0000\u00f9\u00fa\u0005\u0007\u0000\u0000\u00fa"+
		"\u00fb\u0003 \u0010\u0000\u00fb\u00fc\u0005\u000f\u0000\u0000\u00fc\u00fd"+
		"\u0003 \u0010\u0000\u00fd\u00fe\u0006\u0012\uffff\uffff\u0000\u00fe\u0100"+
		"\u0001\u0000\u0000\u0000\u00ff\u00ef\u0001\u0000\u0000\u0000\u00ff\u00f6"+
		"\u0001\u0000\u0000\u0000\u0100%\u0001\u0000\u0000\u0000\u0101\u0102\u0005"+
		"\u0010\u0000\u0000\u0102\u0103\u0005\u0006\u0000\u0000\u0103\u0104\u0003"+
		"*\u0015\u0000\u0104\u0105\u0005\u0007\u0000\u0000\u0105\u0106\u0003 \u0010"+
		"\u0000\u0106\u0107\u0006\u0013\uffff\uffff\u0000\u0107\'\u0001\u0000\u0000"+
		"\u0000\u0108\u0109\u0005\u0011\u0000\u0000\u0109\u010a\u0003*\u0015\u0000"+
		"\u010a\u010b\u0005\u0003\u0000\u0000\u010b\u010c\u0006\u0014\uffff\uffff"+
		"\u0000\u010c\u0111\u0001\u0000\u0000\u0000\u010d\u010e\u0005\u0011\u0000"+
		"\u0000\u010e\u010f\u0005\u0003\u0000\u0000\u010f\u0111\u0006\u0014\uffff"+
		"\uffff\u0000\u0110\u0108\u0001\u0000\u0000\u0000\u0110\u010d\u0001\u0000"+
		"\u0000\u0000\u0111)\u0001\u0000\u0000\u0000\u0112\u0113\u0006\u0015\uffff"+
		"\uffff\u0000\u0113\u0114\u0003,\u0016\u0000\u0114\u0115\u0006\u0015\uffff"+
		"\uffff\u0000\u0115\u0126\u0001\u0000\u0000\u0000\u0116\u0117\u0005\u0006"+
		"\u0000\u0000\u0117\u0118\u0003*\u0015\u0000\u0118\u0119\u0005\u0007\u0000"+
		"\u0000\u0119\u011a\u0006\u0015\uffff\uffff\u0000\u011a\u0126\u0001\u0000"+
		"\u0000\u0000\u011b\u011c\u0003@ \u0000\u011c\u011d\u0005\u0006\u0000\u0000"+
		"\u011d\u011e\u00036\u001b\u0000\u011e\u011f\u0005\u0007\u0000\u0000\u011f"+
		"\u0120\u0006\u0015\uffff\uffff\u0000\u0120\u0126\u0001\u0000\u0000\u0000"+
		"\u0121\u0122\u0007\u0000\u0000\u0000\u0122\u0123\u0003*\u0015\u0005\u0123"+
		"\u0124\u0006\u0015\uffff\uffff\u0000\u0124\u0126\u0001\u0000\u0000\u0000"+
		"\u0125\u0112\u0001\u0000\u0000\u0000\u0125\u0116\u0001\u0000\u0000\u0000"+
		"\u0125\u011b\u0001\u0000\u0000\u0000\u0125\u0121\u0001\u0000\u0000\u0000"+
		"\u0126\u013d\u0001\u0000\u0000\u0000\u0127\u0128\n\u0004\u0000\u0000\u0128"+
		"\u0129\u0007\u0001\u0000\u0000\u0129\u012a\u0003*\u0015\u0005\u012a\u012b"+
		"\u0006\u0015\uffff\uffff\u0000\u012b\u013c\u0001\u0000\u0000\u0000\u012c"+
		"\u012d\n\u0003\u0000\u0000\u012d\u012e\u0007\u0002\u0000\u0000\u012e\u012f"+
		"\u0003*\u0015\u0004\u012f\u0130\u0006\u0015\uffff\uffff\u0000\u0130\u013c"+
		"\u0001\u0000\u0000\u0000\u0131\u0132\n\u0002\u0000\u0000\u0132\u0133\u0005"+
		"\u001a\u0000\u0000\u0133\u0134\u0003*\u0015\u0003\u0134\u0135\u0006\u0015"+
		"\uffff\uffff\u0000\u0135\u013c\u0001\u0000\u0000\u0000\u0136\u0137\n\u0001"+
		"\u0000\u0000\u0137\u0138\u0005\u001b\u0000\u0000\u0138\u0139\u0003*\u0015"+
		"\u0002\u0139\u013a\u0006\u0015\uffff\uffff\u0000\u013a\u013c\u0001\u0000"+
		"\u0000\u0000\u013b\u0127\u0001\u0000\u0000\u0000\u013b\u012c\u0001\u0000"+
		"\u0000\u0000\u013b\u0131\u0001\u0000\u0000\u0000\u013b\u0136\u0001\u0000"+
		"\u0000\u0000\u013c\u013f\u0001\u0000\u0000\u0000\u013d\u013b\u0001\u0000"+
		"\u0000\u0000\u013d\u013e\u0001\u0000\u0000\u0000\u013e+\u0001\u0000\u0000"+
		"\u0000\u013f\u013d\u0001\u0000\u0000\u0000\u0140\u0141\u0006\u0016\uffff"+
		"\uffff\u0000\u0141\u0142\u0003.\u0017\u0000\u0142\u0143\u0006\u0016\uffff"+
		"\uffff\u0000\u0143\u014d\u0001\u0000\u0000\u0000\u0144\u0145\u0003\u001a"+
		"\r\u0000\u0145\u0146\u0006\u0016\uffff\uffff\u0000\u0146\u014d\u0001\u0000"+
		"\u0000\u0000\u0147\u0148\u0005\u0006\u0000\u0000\u0148\u0149\u0003,\u0016"+
		"\u0000\u0149\u014a\u0005\u0007\u0000\u0000\u014a\u014b\u0006\u0016\uffff"+
		"\uffff\u0000\u014b\u014d\u0001\u0000\u0000\u0000\u014c\u0140\u0001\u0000"+
		"\u0000\u0000\u014c\u0144\u0001\u0000\u0000\u0000\u014c\u0147\u0001\u0000"+
		"\u0000\u0000\u014d\u015a\u0001\u0000\u0000\u0000\u014e\u014f\n\u0003\u0000"+
		"\u0000\u014f\u0150\u0007\u0003\u0000\u0000\u0150\u0151\u0003,\u0016\u0004"+
		"\u0151\u0152\u0006\u0016\uffff\uffff\u0000\u0152\u0159\u0001\u0000\u0000"+
		"\u0000\u0153\u0154\n\u0002\u0000\u0000\u0154\u0155\u0007\u0004\u0000\u0000"+
		"\u0155\u0156\u0003,\u0016\u0003\u0156\u0157\u0006\u0016\uffff\uffff\u0000"+
		"\u0157\u0159\u0001\u0000\u0000\u0000\u0158\u014e\u0001\u0000\u0000\u0000"+
		"\u0158\u0153\u0001\u0000\u0000\u0000\u0159\u015c\u0001\u0000\u0000\u0000"+
		"\u015a\u0158\u0001\u0000\u0000\u0000\u015a\u015b\u0001\u0000\u0000\u0000"+
		"\u015b-\u0001\u0000\u0000\u0000\u015c\u015a\u0001\u0000\u0000\u0000\u015d"+
		"\u015e\u0003<\u001e\u0000\u015e\u015f\u0006\u0017\uffff\uffff\u0000\u015f"+
		"\u0167\u0001\u0000\u0000\u0000\u0160\u0161\u0003>\u001f\u0000\u0161\u0162"+
		"\u0005\u0004\u0000\u0000\u0162\u0163\u0003,\u0016\u0000\u0163\u0164\u0005"+
		"\u0005\u0000\u0000\u0164\u0165\u0006\u0017\uffff\uffff\u0000\u0165\u0167"+
		"\u0001\u0000\u0000\u0000\u0166\u015d\u0001\u0000\u0000\u0000\u0166\u0160"+
		"\u0001\u0000\u0000\u0000\u0167/\u0001\u0000\u0000\u0000\u0168\u0169\u0003"+
		"4\u001a\u0000\u0169\u016a\u0006\u0018\uffff\uffff\u0000\u016a\u016d\u0001"+
		"\u0000\u0000\u0000\u016b\u016d\u0006\u0018\uffff\uffff\u0000\u016c\u0168"+
		"\u0001\u0000\u0000\u0000\u016c\u016b\u0001\u0000\u0000\u0000\u016d1\u0001"+
		"\u0000\u0000\u0000\u016e\u016f\u0003\u0016\u000b\u0000\u016f\u0170\u0003"+
		"<\u001e\u0000\u0170\u0171\u0006\u0019\uffff\uffff\u0000\u0171\u0178\u0001"+
		"\u0000\u0000\u0000\u0172\u0173\u0003\u0016\u000b\u0000\u0173\u0174\u0003"+
		">\u001f\u0000\u0174\u0175\u0005\u001f\u0000\u0000\u0175\u0176\u0006\u0019"+
		"\uffff\uffff\u0000\u0176\u0178\u0001\u0000\u0000\u0000\u0177\u016e\u0001"+
		"\u0000\u0000\u0000\u0177\u0172\u0001\u0000\u0000\u0000\u01783\u0001\u0000"+
		"\u0000\u0000\u0179\u017a\u00032\u0019\u0000\u017a\u017b\u0006\u001a\uffff"+
		"\uffff\u0000\u017b\u0182\u0001\u0000\u0000\u0000\u017c\u017d\u00032\u0019"+
		"\u0000\u017d\u017e\u0005 \u0000\u0000\u017e\u017f\u00034\u001a\u0000\u017f"+
		"\u0180\u0006\u001a\uffff\uffff\u0000\u0180\u0182\u0001\u0000\u0000\u0000"+
		"\u0181\u0179\u0001\u0000\u0000\u0000\u0181\u017c\u0001\u0000\u0000\u0000"+
		"\u01825\u0001\u0000\u0000\u0000\u0183\u0184\u0003:\u001d\u0000\u0184\u0185"+
		"\u0006\u001b\uffff\uffff\u0000\u0185\u0188\u0001\u0000\u0000\u0000\u0186"+
		"\u0188\u0006\u001b\uffff\uffff\u0000\u0187\u0183\u0001\u0000\u0000\u0000"+
		"\u0187\u0186\u0001\u0000\u0000\u0000\u01887\u0001\u0000\u0000\u0000\u0189"+
		"\u018a\u0003*\u0015\u0000\u018a\u018b\u0006\u001c\uffff\uffff\u0000\u018b"+
		"9\u0001\u0000\u0000\u0000\u018c\u018d\u00038\u001c\u0000\u018d\u018e\u0006"+
		"\u001d\uffff\uffff\u0000\u018e\u0195\u0001\u0000\u0000\u0000\u018f\u0190"+
		"\u00038\u001c\u0000\u0190\u0191\u0005 \u0000\u0000\u0191\u0192\u0003:"+
		"\u001d\u0000\u0192\u0193\u0006\u001d\uffff\uffff\u0000\u0193\u0195\u0001"+
		"\u0000\u0000\u0000\u0194\u018c\u0001\u0000\u0000\u0000\u0194\u018f\u0001"+
		"\u0000\u0000\u0000\u0195;\u0001\u0000\u0000\u0000\u0196\u0197\u0005\""+
		"\u0000\u0000\u0197\u0198\u0006\u001e\uffff\uffff\u0000\u0198=\u0001\u0000"+
		"\u0000\u0000\u0199\u019a\u0005\"\u0000\u0000\u019a\u019b\u0006\u001f\uffff"+
		"\uffff\u0000\u019b?\u0001\u0000\u0000\u0000\u019c\u019d\u0005\"\u0000"+
		"\u0000\u019d\u019e\u0006 \uffff\uffff\u0000\u019eA\u0001\u0000\u0000\u0000"+
		"\u019f\u01a0\u0005#\u0000\u0000\u01a0\u01a5\u0006!\uffff\uffff\u0000\u01a1"+
		"\u01a2\u0005\u0013\u0000\u0000\u01a2\u01a3\u0005#\u0000\u0000\u01a3\u01a5"+
		"\u0006!\uffff\uffff\u0000\u01a4\u019f\u0001\u0000\u0000\u0000\u01a4\u01a1"+
		"\u0001\u0000\u0000\u0000\u01a5C\u0001\u0000\u0000\u0000\u001dHOclz\u008b"+
		"\u009c\u00aa\u00b1\u00b9\u00c5\u00c7\u00cf\u00e7\u00ff\u0110\u0125\u013b"+
		"\u013d\u014c\u0158\u015a\u0166\u016c\u0177\u0181\u0187\u0194\u01a4";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}