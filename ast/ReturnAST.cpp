#include "ReturnAST.hpp"

ReturnAST::ReturnAST(boost::shared_ptr<SymbolTable> st, boost::shared_ptr<ExprAST> expr, boost::shared_ptr<ASTNode> parent) : ASTNode(st, parent) {
	_st = st;
	_expr = expr;
}
