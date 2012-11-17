#include <iostream>
#include "SymbolTable.hpp"
#include "objs/Scalar.hpp"
#include "ast/AST.hpp"
#include "TreeWalker.hpp"
// The ANTLR includes have to be BELOW the boost includes
#include "MAliceLexer.h"
#include "MAliceParser.h"

using namespace std;

void print(pANTLR3_BASE_TREE tree, int level) {
	for (int i = 0; i < level; ++i) {
		cout << "--";
	}

	cout << " " << tree->getText(tree)->chars << endl;

	int childCount = tree->getChildCount(tree);
	for (int i = 0; i < childCount; ++i) {
		print((pANTLR3_BASE_TREE) tree->getChild(tree, i), level + 1);
	}
}

void printTree(pANTLR3_BASE_TREE ast) {
	print(ast, 0);
}

void printError(string message) {
	cerr << message << endl << endl;
	exit(1);
}

void initST(SymbolTable top) {
	Scalar intScalar(-(2^31), (2^31 - 1)); // Remove Magic numbers 
	top.add("int", &intScalar);
}

void parseFile(pANTLR3_UINT8 filename, bool doPrintTree) {
	cout << endl << "Parsing File " << filename << "..." << endl << endl;

	pANTLR3_INPUT_STREAM input;
	pMAliceLexer lex;
	pANTLR3_COMMON_TOKEN_STREAM tokens;
	pMAliceParser parser;

	input = antlr3AsciiFileStreamNew(filename);
	if (input == NULL) printError("Unable to open file.");

	lex = MAliceLexerNew(input);
	if (lex == NULL) printError("Unable to create lexer.");

	tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lex));
	if (tokens == NULL) printError("Unable to create tokenstream.");

	parser = MAliceParserNew(tokens);
	if (parser == NULL) printError("Unable to create parser.");

	MAliceParser_program_return r = parser->program(parser);
	pANTLR3_BASE_TREE tree = r.tree;

	if (parser->pParser->rec->getNumberOfSyntaxErrors(parser->pParser->rec) > 0) {
		printError("Syntax errors found. Stopping.");
	}

	if (doPrintTree) {
		printTree(tree);
	}

	SymbolTable top;
	initST(top);
	AST semanticTree;

	TreeWalker walker(&top, tree, &semanticTree);

	parser->free(parser);
	tokens->free(tokens);
	lex->free(lex);
	input->close(input);

	cout << "Done." << endl;
}

int main(int argc, char* argv[]) {
	for (int i = 1; i < argc; i++) {
		parseFile((pANTLR3_UINT8) argv[i], false);
		cout << endl;
	}

	return 0;
}