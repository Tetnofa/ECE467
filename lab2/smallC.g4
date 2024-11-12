//
//  smallC.g4
//  ECE467 Lab 2
//
//  Created by Tarek Abdelrahman on 2023-08-21.
//  Modified by Tarek Abdelrahman on 2024-09-21.
//  Copyright © 2023-2024 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

// This file contains the skeltal code for the smallC grammar

// ECE467 student: please 
//    1. complete the rules as indicated,
//    2. do NOT change the name of grammar
//    3. do NOT change the names of the non-terminals
//    4. do NOT change the order of the rules 
//    5. do NOT change the names of the takens


grammar smallC ;

program: (preamble | ) decls* EOF ;

preamble:  '#include' '"scio.h"' ;

decls:
    scalarDeclList
    | arrDeclList
    | fcnProto
    | fcnDecl ;

scalarDeclList:
    scalarDecl|
    scalarDecl scalarDeclList ;

scalarDecl: varType varName ';' ;

arrDeclList:
    arrDecl|
    arrDecl arrDeclList ;

arrDecl: varType arrName '[' intConst ']' ';' ;

fcnProto: retType fcnName '(' params ')' ';' ;

fcnDecl: retType fcnName '(' params ')' scope ;

varType: 'bool' | 'int' ;

retType: 'void' | varType ; 

constant: boolConst | intConst ;

scope: '{' (scalarDecl | arrDecl)* stmt* '}' ;

stmt: expr ';'
    | assignStmt
    | ifStmt
    | whileStmt
    | retStmt
    | scope ;

assignStmt: var '=' expr ';' ; 

ifStmt: 'if' '(' expr ')' stmt | 'if' '(' expr ')' stmt 'else' stmt ;

whileStmt: 'while' '(' expr ')' stmt ;

retStmt: 'return' ';' | 'return' expr ';' ;

expr: intExpr
    | '(' expr ')'
    | fcnName '(' args ')'
    | '!' expr
    | '-' expr
    | expr '<' expr
    | expr '<=' expr
    | expr '>' expr
    | expr '>=' expr
    | expr '==' expr
    | expr '!=' expr
    | expr '||' expr
    | expr '&&' expr;                           

intExpr: constant
    | var
    | intExpr '+' intExpr 
    | intExpr '-' intExpr 
    | intExpr '*' intExpr 
    | intExpr '/' intExpr 
    | '(' intExpr ')' ;

    

var: varName | arrName '[' intExpr ']' ;

params: paramList | ;

paramEntry: varType varName | varType arrName '[]' ;

paramList: paramEntry | (paramEntry ',' paramList) ;

args: argList | ;

argEntry: expr ;

argList: argEntry | (argEntry ',' argList) ;

varName: ID ;

arrName: ID ;

fcnName: ID ;

boolConst: BOOL ;

intConst: INT | '-' INT ;

BOOL: 'false' | 'true' ;
ID: [a-zA-Z][a-zA-Z0-9_]* ;
INT: '0' 
    | [1-9][0-9]*;
WS : [ \t\r\n]+ -> skip ;
COMMENT: '//' (~[\r\n])* -> skip ;
