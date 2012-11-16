CPP = g++ -I . -I libantlr3c
C   = gcc -I libantlr3c

all: antlr grammar compile

antlr:
	cd libantlr3c_build/; ./configure --enable-64bit; \
	rm config.log config.status Makefile stamp-h1; rm -r .deps ; cd ../; \
	mv libantlr3c_build/antlr3config.h libantlr3c/antlr3config.h;

grammar:
	java -jar ANTLR3/antlr-3.2.jar MAlice.g

compile: ast/AST.o ast/ASTNode.o objs/Type.o ast/ExprAST.o ast/VarAssignAST.o objs/Array.o objs/Function.o objs/Param.o objs/Scalar.o SymbolTable.o objs/Variable.o ast/VariableDecAST.o MAlice.o MAliceLexer.o MAliceParser.o libantlr3c/antlr3baserecognizer.o libantlr3c/antlr3convertutf.o libantlr3c/antlr3parser.o libantlr3c/antlr3basetree.o libantlr3c/antlr3cyclicdfa.o libantlr3c/antlr3rewritestreams.o libantlr3c/antlr3basetreeadaptor.o libantlr3c/antlr3debughandlers.o libantlr3c/antlr3string.o libantlr3c/antlr3bitset.o libantlr3c/antlr3encodings.o libantlr3c/antlr3stringstream.o libantlr3c/antlr3collections.o libantlr3c/antlr3exception.o libantlr3c/antlr3tokenstream.o libantlr3c/antlr3commontoken.o libantlr3c/antlr3filestream.o libantlr3c/antlr3treeparser.o libantlr3c/antlr3commontree.o libantlr3c/antlr3inputstream.o libantlr3c/antlr3ucs2inputstream.o libantlr3c/antlr3commontreeadaptor.o libantlr3c/antlr3intstream.o libantlr3c/antlr3commontreenodestream.o libantlr3c/antlr3lexer.o
	$(CPP) -o $@ $^

.cpp.o:
	$(CPP) -c -o $*.o $<

.c.o:
	$(C) -c -o $*.o $<

clean:
	rm -rf compile *.o libantlr3c/*.o ast/*.o objs/*.o

.phony: all clean antlr grammar
