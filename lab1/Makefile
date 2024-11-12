# Makefile 
# ECE467 Lab 1
#
#  Created by Tarek Abdelrahman on 2023-07-19.
#  Modified by Tarek Abdelrahman on 2024-08-19.
#  Copyright © 2023-2024 Tarek Abdelrahman. All rights reserved.
#
#  Permission is hereby granted to use this code in ECE467 at
#  the University of Toronto. It is prohibited to distribute
#  this code, either publicly or to third parties.

SHELL := /bin/bash

ANTLR_VER     = 4.7.2
ECE467_ROOT   = /cad2/ece467f
ANTLR_INC_DIR = $(ECE467_ROOT)/ANTLR-$(ANTLR_VER)/include/antlr4-runtime/
ANTLR_LIB_DIR = $(ECE467_ROOT)/ANTLR-$(ANTLR_VER)/lib

CC            = g++ 
CC_OPT        = -std=c++17 -w

ANTLR         = java -jar $(ECE467_ROOT)/ANTLR-$(ANTLR_VER)/antlr-$(ANTLR_VER)-complete.jar
ANTLR_OPTS    = -no-listener -no-visitor -Dlanguage=Cpp

TARGET        = A1
EXE           = A1Scanner

GEN_SRCS      = $(TARGET).cpp 

GEN_OBJS      = $(patsubst %.cpp,%.o,$(GEN_SRCS))

GEN_INCS      = $(patsubst %.cpp,%.h,$(GEN_SRCS))

GEN_OTHR      = $(TARGET).interp $(TARGET).tokens $(TARGET)Lexer.interp $(TARGET)Lexer.tokens

SRCS          = $(EXE).cpp printSummary.cpp
OBJS          = $(patsubst %.cpp,%.o,$(SRCS))
INCS          = $(patsubst %.cpp,%.h,$(SRCS))

$(EXE):	$(OBJS) $(GEN_OBJS)
	$(CC) $(CC_OPT) -I$(ANTLR_INC_DIR) -L$(ANTLR_LIB_DIR) $(OBJS) \
	          $(GEN_OBJS) -o $(EXE) -lantlr4-runtime

$(OBJS):	%.o:	%.cpp $(GEN_INCS)
	$(CC) $(CC_OPT) -c -I$(ANTLR_INC_DIR) -o $@ $<
	
$(GEN_OBJS):	%.o:	%.cpp %.h
	$(CC) $(CC_OPT) -c -I$(ANTLR_INC_DIR) -o $@ $<

$(GEN_INCS):	$(TARGET).g4
	$(ANTLR) $(ANTLR_OPTS)  $(TARGET).g4

$(GEN_SRCS):	$(TARGET).g4
	$(ANTLR) $(ANTLR_OPTS)  $(TARGET).g4

depend:
	@makedepend -- $(CC_OPT) -I$(ANTLR_INC_DIR) -L$(ANTLR_LIB_DIR) -- \
		                               $(SRCS) $(GEN_SRCS) >& /dev/null

.PHONY: clean
clean:
	@rm -f $(GEN_SRCS) $(GEN_INCS) $(GEN_OBJS) $(GEN_OTHR) $(OBJS) $(EXE) Makefile.bak

