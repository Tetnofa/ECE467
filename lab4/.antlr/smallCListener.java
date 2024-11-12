// Generated from /homes/p/patraama/ECE467/lab4/smallC.g4 by ANTLR 4.13.1

#include "ASTNodes.h"
#include <iostream>
#include <string>

import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link smallCParser}.
 */
public interface smallCListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link smallCParser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(smallCParser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(smallCParser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#preamble}.
	 * @param ctx the parse tree
	 */
	void enterPreamble(smallCParser.PreambleContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#preamble}.
	 * @param ctx the parse tree
	 */
	void exitPreamble(smallCParser.PreambleContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#decls}.
	 * @param ctx the parse tree
	 */
	void enterDecls(smallCParser.DeclsContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#decls}.
	 * @param ctx the parse tree
	 */
	void exitDecls(smallCParser.DeclsContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#scalarDeclList}.
	 * @param ctx the parse tree
	 */
	void enterScalarDeclList(smallCParser.ScalarDeclListContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#scalarDeclList}.
	 * @param ctx the parse tree
	 */
	void exitScalarDeclList(smallCParser.ScalarDeclListContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#scalarDecl}.
	 * @param ctx the parse tree
	 */
	void enterScalarDecl(smallCParser.ScalarDeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#scalarDecl}.
	 * @param ctx the parse tree
	 */
	void exitScalarDecl(smallCParser.ScalarDeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#arrDeclList}.
	 * @param ctx the parse tree
	 */
	void enterArrDeclList(smallCParser.ArrDeclListContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#arrDeclList}.
	 * @param ctx the parse tree
	 */
	void exitArrDeclList(smallCParser.ArrDeclListContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#arrDecl}.
	 * @param ctx the parse tree
	 */
	void enterArrDecl(smallCParser.ArrDeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#arrDecl}.
	 * @param ctx the parse tree
	 */
	void exitArrDecl(smallCParser.ArrDeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#fcnProto}.
	 * @param ctx the parse tree
	 */
	void enterFcnProto(smallCParser.FcnProtoContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#fcnProto}.
	 * @param ctx the parse tree
	 */
	void exitFcnProto(smallCParser.FcnProtoContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#fcnDecl}.
	 * @param ctx the parse tree
	 */
	void enterFcnDecl(smallCParser.FcnDeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#fcnDecl}.
	 * @param ctx the parse tree
	 */
	void exitFcnDecl(smallCParser.FcnDeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#varType}.
	 * @param ctx the parse tree
	 */
	void enterVarType(smallCParser.VarTypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#varType}.
	 * @param ctx the parse tree
	 */
	void exitVarType(smallCParser.VarTypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#retType}.
	 * @param ctx the parse tree
	 */
	void enterRetType(smallCParser.RetTypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#retType}.
	 * @param ctx the parse tree
	 */
	void exitRetType(smallCParser.RetTypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#constant}.
	 * @param ctx the parse tree
	 */
	void enterConstant(smallCParser.ConstantContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#constant}.
	 * @param ctx the parse tree
	 */
	void exitConstant(smallCParser.ConstantContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#boolConst}.
	 * @param ctx the parse tree
	 */
	void enterBoolConst(smallCParser.BoolConstContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#boolConst}.
	 * @param ctx the parse tree
	 */
	void exitBoolConst(smallCParser.BoolConstContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#scope}.
	 * @param ctx the parse tree
	 */
	void enterScope(smallCParser.ScopeContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#scope}.
	 * @param ctx the parse tree
	 */
	void exitScope(smallCParser.ScopeContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#stmt}.
	 * @param ctx the parse tree
	 */
	void enterStmt(smallCParser.StmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#stmt}.
	 * @param ctx the parse tree
	 */
	void exitStmt(smallCParser.StmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#assignStmt}.
	 * @param ctx the parse tree
	 */
	void enterAssignStmt(smallCParser.AssignStmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#assignStmt}.
	 * @param ctx the parse tree
	 */
	void exitAssignStmt(smallCParser.AssignStmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#ifStmt}.
	 * @param ctx the parse tree
	 */
	void enterIfStmt(smallCParser.IfStmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#ifStmt}.
	 * @param ctx the parse tree
	 */
	void exitIfStmt(smallCParser.IfStmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#whileStmt}.
	 * @param ctx the parse tree
	 */
	void enterWhileStmt(smallCParser.WhileStmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#whileStmt}.
	 * @param ctx the parse tree
	 */
	void exitWhileStmt(smallCParser.WhileStmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#retStmt}.
	 * @param ctx the parse tree
	 */
	void enterRetStmt(smallCParser.RetStmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#retStmt}.
	 * @param ctx the parse tree
	 */
	void exitRetStmt(smallCParser.RetStmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr(smallCParser.ExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr(smallCParser.ExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#intExpr}.
	 * @param ctx the parse tree
	 */
	void enterIntExpr(smallCParser.IntExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#intExpr}.
	 * @param ctx the parse tree
	 */
	void exitIntExpr(smallCParser.IntExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#var}.
	 * @param ctx the parse tree
	 */
	void enterVar(smallCParser.VarContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#var}.
	 * @param ctx the parse tree
	 */
	void exitVar(smallCParser.VarContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#params}.
	 * @param ctx the parse tree
	 */
	void enterParams(smallCParser.ParamsContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#params}.
	 * @param ctx the parse tree
	 */
	void exitParams(smallCParser.ParamsContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#paramEntry}.
	 * @param ctx the parse tree
	 */
	void enterParamEntry(smallCParser.ParamEntryContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#paramEntry}.
	 * @param ctx the parse tree
	 */
	void exitParamEntry(smallCParser.ParamEntryContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#paramList}.
	 * @param ctx the parse tree
	 */
	void enterParamList(smallCParser.ParamListContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#paramList}.
	 * @param ctx the parse tree
	 */
	void exitParamList(smallCParser.ParamListContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#args}.
	 * @param ctx the parse tree
	 */
	void enterArgs(smallCParser.ArgsContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#args}.
	 * @param ctx the parse tree
	 */
	void exitArgs(smallCParser.ArgsContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#argEntry}.
	 * @param ctx the parse tree
	 */
	void enterArgEntry(smallCParser.ArgEntryContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#argEntry}.
	 * @param ctx the parse tree
	 */
	void exitArgEntry(smallCParser.ArgEntryContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#argList}.
	 * @param ctx the parse tree
	 */
	void enterArgList(smallCParser.ArgListContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#argList}.
	 * @param ctx the parse tree
	 */
	void exitArgList(smallCParser.ArgListContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#varName}.
	 * @param ctx the parse tree
	 */
	void enterVarName(smallCParser.VarNameContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#varName}.
	 * @param ctx the parse tree
	 */
	void exitVarName(smallCParser.VarNameContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#arrName}.
	 * @param ctx the parse tree
	 */
	void enterArrName(smallCParser.ArrNameContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#arrName}.
	 * @param ctx the parse tree
	 */
	void exitArrName(smallCParser.ArrNameContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#fcnName}.
	 * @param ctx the parse tree
	 */
	void enterFcnName(smallCParser.FcnNameContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#fcnName}.
	 * @param ctx the parse tree
	 */
	void exitFcnName(smallCParser.FcnNameContext ctx);
	/**
	 * Enter a parse tree produced by {@link smallCParser#intConst}.
	 * @param ctx the parse tree
	 */
	void enterIntConst(smallCParser.IntConstContext ctx);
	/**
	 * Exit a parse tree produced by {@link smallCParser#intConst}.
	 * @param ctx the parse tree
	 */
	void exitIntConst(smallCParser.IntConstContext ctx);
}