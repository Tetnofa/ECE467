//
//  printSummary.cpp
//  ECE467 Lab 1
//
//  Created by Tarek Abdelrahman on 2023-07-19.
//  Modified by Tarek Abdelrahman on 2024-08-19.
//  Copyright © 2023-2024 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#include <iostream>
#include <string>
#include <map>

#include "antlr4-runtime.h"
#include "A1.h"
#include "printSummary.h"

using namespace antlrcpp;
using namespace antlr4;
using namespace std;

// This function prints the count of each token occurrence. It is only
// used for exercise and autotesting 
void printSummary(A1* lexer, CommonTokenStream& tokens) {
    map<string, int>  tokenCount;
    tokenCount["KYWD"] = 0;
    tokenCount["BOOL"] = 0;
    tokenCount["NUM"] = 0;
    tokenCount["ID"] = 0;
    tokenCount["WS"] = 0;
    tokenCount["EOF"] = 0;

    for (Token *token : tokens.getTokens()) {
        string token_name = lexer->getVocabulary().getSymbolicName(token->getType());
        if (token_name != "KYWD" && token_name != "BOOL" && token_name != "NUM" 
            && token_name != "ID" && token_name != "WS" && token_name != "EOF") {
           std::cerr << "fatal: token name " << token_name << " is not valid" << std::endl;
           return;
        }
        ++tokenCount[token_name];
    }

    std::cout << "KYWD " << tokenCount["KYWD"] << std::endl;
    std::cout << "BOOL " << tokenCount["BOOL"] << std::endl;
    std::cout << "NUM  " << tokenCount["NUM"] << std::endl;
    std::cout << "ID   " << tokenCount["ID"] << std::endl;
    std::cout << "WS   " << tokenCount["WS"] << std::endl;
    std::cout << "EOF  " << tokenCount["EOF"] << std::endl;

    return;
}
