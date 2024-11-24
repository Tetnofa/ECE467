//
//  A5Dom.cpp
//  ECE467 Lab 5
//
//  Created by Tarek Abdelrahman on 2023-11-18.
//  Copyright © 2023 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//

#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/raw_ostream.h"

#include <string>
#include <map>
#include <vector>
#include <set>

using namespace llvm;
using namespace std;

namespace {

// This method implements what the pass does
void processFunction(Function &F) {
    // Step 1: Initialize data structures
    std::map<BasicBlock*, std::set<BasicBlock*>> dominators;
    std::map<BasicBlock*, std::set<BasicBlock*>> postDominators;
    BasicBlock* entryBlock = &F.getEntryBlock();
    BasicBlock* exitBlock = nullptr;

    // Step 2: Identify the exit block (assuming single exit)
    for (BasicBlock &BB : F) {
        if (succ_begin(&BB) == succ_end(&BB)) { // No successors means it's an exit block
            exitBlock = &BB;
            break;
        }
    }

    // Step 3: Initialize dominator sets
    for (BasicBlock &BB : F) {
        if (&BB == entryBlock) {
            dominators[&BB].insert(&BB); // Entry block only dominates itself
        } else {
            for (BasicBlock &OtherBB : F) {
                dominators[&BB].insert(&OtherBB); // Initially, all blocks dominate others
            }
        }
    }

    // Step 4: Compute dominators
    bool changed;
    do {
        changed = false;
        for (BasicBlock &BB : F) {
            if (&BB == entryBlock) continue; // Skip entry block
            std::set<BasicBlock*> newDoms;
            for (BasicBlock *Pred : predecessors(&BB)) {
                if (newDoms.empty()) {
                    newDoms = dominators[Pred]; // Start with the first predecessor's dominators
                } else {
                    std::set<BasicBlock*> intersection;
                    std::set_intersection(newDoms.begin(), newDoms.end(),
                                          dominators[Pred].begin(), dominators[Pred].end(),
                                          std::inserter(intersection, intersection.begin()));
                    newDoms = intersection; // Keep only common dominators
                }
            }
            newDoms.insert(&BB); // A block always dominates itself
            if (newDoms != dominators[&BB]) {
                dominators[&BB] = newDoms;
                changed = true;
            }
        }
    } while (changed);

    // Step 5: Initialize post-dominator sets
    for (BasicBlock &BB : F) {
        if (&BB == exitBlock) {
            postDominators[&BB].insert(&BB); // Exit block only post-dominates itself
        } else {
            for (BasicBlock &OtherBB : F) {
                postDominators[&BB].insert(&OtherBB); // Initially, all blocks post-dominate others
            }
        }
    }

    // Step 6: Compute post-dominators
    do {
        changed = false;
        for (BasicBlock &BB : F) {
            if (&BB == exitBlock) continue; // Skip exit block
            std::set<BasicBlock*> newPostDoms;
            for (BasicBlock *Succ : successors(&BB)) {
                if (newPostDoms.empty()) {
                    newPostDoms = postDominators[Succ]; // Start with the first successor's post-dominators
                } else {
                    std::set<BasicBlock*> intersection;
                    std::set_intersection(newPostDoms.begin(), newPostDoms.end(),
                                          postDominators[Succ].begin(), postDominators[Succ].end(),
                                          std::inserter(intersection, intersection.begin()));
                    newPostDoms = intersection; // Keep only common post-dominators
                }
            }
            newPostDoms.insert(&BB); // A block always post-dominates itself
            if (newPostDoms != postDominators[&BB]) {
                postDominators[&BB] = newPostDoms;
                changed = true;
            }
        }
    } while (changed);

    // Step 7: Output the results
    std::vector<BasicBlock*> blocks;
    for (BasicBlock &BB : F) {
        blocks.push_back(&BB);
    }
    std::sort(blocks.begin(), blocks.end(), [](BasicBlock* a, BasicBlock* b) {
        return a->getName() < b->getName();
    });

    for (BasicBlock* BB : blocks) {
        // Print the block name
        llvm::outs() << BB->getName() << ": \n";

        // Print dominators
        std::vector<std::string> domNames;
        for (BasicBlock* dom : dominators[BB]) {
            domNames.push_back(dom->getName().str());
        }
        std::sort(domNames.begin(), domNames.end());

        // Print all dominators in one line
        llvm::outs() << "    ";
        for (size_t i = 0; i < domNames.size(); ++i) {
            llvm::outs() << domNames[i];
            if (i < domNames.size() - 1) {
                llvm::outs() << " "; // Space between dominators
            }
        }
        llvm::outs() << " \n"; // New line after dominators

        // Print immediate dominator
        if (domNames.size() > 1) {
            llvm::outs() << "    " << domNames[1] << "\n"; // Immediate dominator (first after itself)
        } else {
            llvm::outs() << "    X\n"; // No immediate dominator
        }

        // Print post-dominators
        std::vector<std::string> postDomNames;
        for (BasicBlock* postDom : postDominators[BB]) {
            postDomNames.push_back(postDom->getName().str());
        }
        std::sort(postDomNames.begin(), postDomNames.end());

        // Print all post-dominators in one line
        llvm::outs() << "    ";
        for (size_t i = 0; i < postDomNames.size(); ++i) {
            llvm::outs() << postDomNames[i];
            if (i < postDomNames.size() - 1) {
                llvm::outs() << " "; // Space between post-dominators
            }
        }
        llvm::outs() << " \n"; // New line after post-dominators

        // Print immediate post-dominator
        if (postDomNames.size() > 1) {
            llvm::outs() << "    " << postDomNames[1] << "\n"; // Immediate post-dominator (first after itself)
        } else {
            llvm::outs() << "    X\n"; // No immediate post-dominator
        }
    }
}

struct A5Dom : PassInfoMixin<A5Dom> {
  // This is the main entry point for processing the IR of a function
  // It simply calls the function that has your code
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &) {
    processFunction(F);
    return PreservedAnalyses::all();
  }

  // This makes sure that the pass is executed, even when functions are
  // decorated with the optnone attribute; this is the case when using
  // clang without -O flags
  static bool isRequired() { return true; }
};
} // namespace

// Register the pass with the pass manager as a function pass
llvm::PassPluginLibraryInfo getA5DomPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, "A5Dom", LLVM_VERSION_STRING,
          [](PassBuilder &PB) {
            PB.registerPipelineParsingCallback(
                [](StringRef Name, FunctionPassManager &FPM,
                   ArrayRef<PassBuilder::PipelineElement>) {
                  if (Name == "A5Dom") {
                    FPM.addPass(A5Dom());
                    return true;
                  }
                  return false;
                });
          }};
}

// This ensures that opt recognizes A5Dom when specified on the
// command line by -passes="A5Dom"
extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo
llvmGetPassPluginInfo() {
  return getA5DomPluginInfo();
}
