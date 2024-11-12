//
//  SymTable.h
//  ECE467 Lab 3
//
//  Created by Tarek Abdelrahman on 2023-09-13.
//  Based on code written by Ao (Dino) Li for ECE467.
//  Copyright © 2023 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#ifndef SYMTABLE_H
#define SYMTABLE_H

#include "ASTNodes.h"
#include <map>
#include <string>

namespace smallc {

// Must implement in cpp cuz headers have circle refernce
// A variable entry in the table
class VariableEntry {
private:
    TypeNode* type;
    bool isArray;
public:
    VariableEntry();
    explicit VariableEntry(PrimitiveTypeNode* p);
    explicit VariableEntry(ArrayTypeNode* arr);
    TypeNode* getType();
};

// Must implement in cpp cuz headers have circle refernce
// A function entry in the table
class FunctionEntry {
public:
    PrimitiveTypeNode* returnType;
    std::vector<TypeNode*> parameterTypes;
    bool proto;
public:
    FunctionEntry();
    FunctionEntry(PrimitiveTypeNode* retType, std::vector<TypeNode*> paraTypes);
    PrimitiveTypeNode* getReturnType();
    std::vector<TypeNode*> getParameterTypes();
};

// Symbol table class
// Must implement in h file cuz templated 
template<class T>
class SymTable {
private:
    std::map<std::string, T> table;
public:
    bool contains(const std::string &name) {
        return table.find(name) != table.end();
    }
    
    T& get(const std::string &name) {
        return table[name];
    }
    
    void insert(const std::string& name, T ent) {
        table[name] = ent;
    }
};

} // namspace smallc
#endif //SYMTABLE_H

