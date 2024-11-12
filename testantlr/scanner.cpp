#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "ExprLexer.h"
#include "ExprParser.h"
#include <string>

using namespace antlrcpp;
using namespace antlr4;
using namespace std;

int main(int argc, const char *args[]) {

    // Create the input stream

    ANTLRInputStream input("120 + 38\n");
   
    // Create a lexer which scans the input stream
    // to create a token stream.
    ExprLexer *lexer = new ExprLexer(&input);
    CommonTokenStream tokens(lexer);

    // Print the token stream.
    cout << "Tokens:" << endl;
    tokens.fill();
    for (Token *token : tokens.getTokens()) std::cout << token->toString() << std::endl;

    // Create a parser 
    ExprParser parser(&tokens);
    tree::ParseTree* tree = parser.prog();

    // Print the parse tree in Lisp format.
    cout << endl << "Parse tree (Lisp format):" << endl; 
    std::cout << tree->toStringTree(&parser) << endl;

    return 0;
}

