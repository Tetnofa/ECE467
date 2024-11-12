//
//  printSummary.h
//  ECE467 Lab 1
//
//  Created by Tarek Abdelrahman on 2023-07-19.
//  Modified by Tarek Abdelrahman on 2024-08-19.
//  Copyright © 2023-2024 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#pragma once

#include <iostream>
#include "antlr4-runtime.h"
#include "A1.h"

using namespace antlrcpp;
using namespace antlr4;
using namespace std;

// A function that prints token summary
void printSummary(A1* lexer, CommonTokenStream& tokens);
