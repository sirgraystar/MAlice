#ifndef PAUSE_AST
#define PAUSE_AST

#include "ExprAST.hpp"
#include "../ASTVisitor.hpp"

class PauseAST : public ASTNode {
    boost::shared_ptr<SymbolTable> _st;
    boost::shared_ptr<ExprAST> _expr;
    int _lineNo;
    void check();
public:
    PauseAST(boost::shared_ptr<SymbolTable> st, boost::shared_ptr<ExprAST> expr,
    	     boost::weak_ptr<ASTNode> parent, int lineNo);
    void print();
    string getNodeName();
    void accept(boost::shared_ptr<ASTVisitor> v, boost::shared_ptr<AssemFunc> func);
};

#endif
