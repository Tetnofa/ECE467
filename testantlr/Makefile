#SHELL := /bin/bash

ANTLR_INC_DIR = /cad2/ece467f/ANTLR-4.7.2/include/antlr4-runtime/
ANTLR_LIB_DIR = /cad2/ece467f/ANTLR-4.7.2/lib

CC            = g++ 
CC_OPT        = -std=c++17 -w

ANTLR         = java -jar /cad2/ece467f/ANTLR-4.7.2/antlr-4.7.2-complete.jar
ANTLR_OPTS    = -no-listener -no-visitor -Dlanguage=Cpp

TARGET        = Expr
EXE           = scanner

GEN_SRCS      = $(TARGET)Lexer.cpp  $(TARGET)Parser.cpp 

GEN_OBJS      = $(patsubst %.cpp,%.o,$(GEN_SRCS))

GEN_INCS      = $(patsubst %.cpp,%.h,$(GEN_SRCS))

GEN_OTHR      = $(TARGET).interp $(TARGET).tokens $(TARGET)Lexer.interp $(TARGET)Lexer.tokens

SRCS          = $(EXE).cpp 
OBJS          = $(patsubst %.cpp,%.o,$(SRCS))
INCS          = $(patsubst %.cpp,%.h,$(SRCS))

EXE:	$(OBJS) $(GEN_OBJS)
	$(CC) $(CC_OPT) -I$(ANTLR_INC_DIR) -L$(ANTLR_LIB_DIR) $(OBJS) \
	          $(GEN_OBJS) -o $(EXE) -lantlr4-runtime

$(OBJS):	%.o:	%.cpp %.h $(GEN_INCS)
	$(CC) $(CC_OPT) -c -I$(ANTLR_INC_DIR) -o $@ $<
	
$(GEN_OBJS):	%.o:	%.cpp %.h
	$(CC) $(CC_OPT) -c -I$(ANTLR_INC_DIR) -o $@ $<

$(GEN_INCS):	$(TARGET).g4
	$(ANTLR) $(ANTLR_OPTS)  $(TARGET).g4

$(GEN_SRCS):	$(TARGET).g4
	$(ANTLR) $(ANTLR_OPTS)  $(TARGET).g4

depend:
	makedepend $(SRCS) $(GEN_SRCS)

clean:
	rm -f $(GEN_SRCS) $(GEN_INCS) $(GEN_OBJS) $(GEN_OTHR) $(OBJS) $(EXE) 

