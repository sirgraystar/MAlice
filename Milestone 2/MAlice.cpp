#include "MAliceLexer.h"
#include "MAliceParser.h"
#include <iostream>

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

void parseFile(pANTLR3_UINT8 filename, bool doPrintTree) {
	cout << "Parsing File " << filename << "..." << endl;

	pANTLR3_INPUT_STREAM input;
	pMAliceLexer lex;
	pANTLR3_COMMON_TOKEN_STREAM tokens;
	pMAliceParser parser;

	input = antlr3AsciiFileStreamNew(filename);
	if (input == NULL) {
		cerr << "Unable to open file " << filename << endl;
		exit(ANTLR3_ERR_NOFILE);
	}

	lex = MAliceLexerNew(input);
	if (lex == NULL) {
		cerr << "Unable to create lexer." << endl;
		exit(ANTLR3_ERR_NOMEM);
	}

	tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lex));
	if (tokens == NULL) {
		cerr << "Unable to create tokenstream." << endl;
		exit(ANTLR3_ERR_NOMEM);
	}

	parser = MAliceParserNew(tokens);
	if (parser == NULL) {
		cerr << "Unable to create parser." << endl;
		exit(ANTLR3_ERR_NOMEM);
	}

	MAliceParser_program_return r = parser->program(parser);
	if (doPrintTree) {
		pANTLR3_BASE_TREE tree = r.tree;
		printTree(tree);
	}

	parser->free(parser);
	tokens->free(tokens);
	lex->free(lex);
	input->close(input);

	cout << "Done." << endl;
}

int main(int argc, char* argv[]) {
	for (int i = 1; i < argc; i++) {
		parseFile((pANTLR3_UINT8) argv[i], true);
		cout << endl;
	}

	return 0;
}