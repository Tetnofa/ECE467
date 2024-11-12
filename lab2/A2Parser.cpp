//
//  A2Parser.cpp
//  ECE467 Lab 1
//
//  Created by Tarek Abdelrahman on 2023-07-31.
//  Modified by Tarek Abdelrahman on 2024-09-21.
//  Copyright © 2023-2024 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "antlr4-runtime.h"
#include "smallCLexer.h"
#include "smallCParser.h"
#include "printSummary.h"

using namespace antlrcpp;
using namespace antlr4;
using namespace std;

int main(int argc, const char *argv[]) {
    // Check for the number of arguments
    if (argc != 2) {
	cerr << "Usage: " << argv[0] << " filename" << std::endl;
	return -1;
    }

    // Input stream handler
    ifstream inputStream;

    // Open the input file
    inputStream.open(argv[1]);
    if (!inputStream) {
    	cerr << "fatal: " << argv[1] << " not found or cannot be opened" << std::endl;
	return -1;
    }

    // Create the input stream to the lexer
    ANTLRInputStream input(inputStream);
   
    // Create a lexer which scans the input stream
    // to create a token stream.
    smallCLexer* lexer = new smallCLexer(&input);
    CommonTokenStream tokens(lexer);

    // Get the tokens
    tokens.fill();

    // Uncomment these lines to see the tokens printed out
    //cout << "Tokens:" << endl;
    //for (Token *token : tokens.getTokens()) std::cout << token->toString() << std::endl;

    // Create a parser 
    smallCParser* parser = new smallCParser(&tokens);
    tree::ParseTree* tree = parser->program();

    // Uncomment these line to print the parse tree in Lisp format.
    //cout << "Parse tree (Lisp format):" << endl; 
    //std::cout << tree->toStringTree(parser) << endl;

    // Print a summary of the parse tree  non-terminals counts counts (for autotesting and exercise)
    printSummary(tree);

    return 0;
}

