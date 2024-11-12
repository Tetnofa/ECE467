
grammar smallC ;

program: (preamble)? decls* EOF ;

preamble: '#include' '"scio.h"' ;

decls:
    scalarDeclList
    | arrDeclList
    | fcnProto
    | fcnDecl ;

scalarDeclList:
    scalarDecl
    | scalarDecl scalarDeclList ;

scalarDecl: varType varName ';' ;

arrDeclList:
    arrDecl
    | arrDecl arrDeclList ;

arrDecl: varType arrName '[' intConst ']' ';' ;

fcnProto: retType fcnName '(' params ')' ';' ;

fcnDecl: retType fcnName '(' params ')' scope ;

varType: 'bool' | 'int' ;

retType: 'void' | varType ; 

constant: boolConst | intConst ;

scope: '{' (scalarDecl | arrDecl)* stmt* '}' ;

stmt: assignStmt
    | ifStmt
    | whileStmt
    | retStmt
    | expr ';'
    | scope ;

assignStmt: var '=' expr ';' ;

ifStmt: 'if' '(' expr ')' stmt ( 'else' stmt )? ;

whileStmt: 'while' '(' expr ')' stmt ;

retStmt: 'return' ';'
    | 'return' expr ';' ;

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

var: varName
    | arrName '[' intExpr ']' ;

params: paramList? ;

paramEntry: varType varName 
    | varType arrName '[]' ;

paramList: paramEntry (',' paramEntry)* ;

args: argList? ;

argEntry: expr ;

argList: argEntry (',' argEntry)* ;

varName: ID ;

arrName: ID ;

fcnName: ID ;

boolConst: BOOL ;

intConst: INT ;

fragment BOOL: 'false' | 'true' ;
fragment ID: [a-zA-Z][a-zA-Z0-9_]* ;
fragment INT: ('-'? [1-9][0-9]*) | '0' ;

WS: [ \t\r\n]+ -> skip ;
COMMENT: '//' ~[\r\n]* -> skip ;


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