//
//  A1.g
//  ECE467 Lab 1
//
//  Created by Tarek Abdelrahman on 2023-07-19.
//  Modified by Tarek Abdelrahman on 2024-08-19.
//  Copyright © 2023-2024 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

lexer grammar A1;   // NOTE the keyword lexer

// ECE467 Student: add token expressions below
// Be mindful of the order of the tokens

KYWD : 'begin' | 'end' ;
BOOL : 'true' | 'false' ;
NUM : '0' | ([1-9] [0-9]*) ;
ID : [a-zA-Z] [a-zA-Z0-9_]* ;
WS : [ \t\r\n]+ -> skip ;


