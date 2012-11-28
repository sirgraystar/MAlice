#include "ArrayDecAST.hpp"
#include "../Utils.hpp"

ArrayDecAST::ArrayDecAST(boost::shared_ptr<SymbolTable> st,
                          boost::shared_ptr<ExprAST> length, string name,
                          string typeName, boost::weak_ptr<ASTNode> parent,
                          int lineNo) : ASTNode(st, parent, lineNo) {
    _st = st;
    _name = name;
    _length = length;
    _elemType = typeName;
    _lineNo = lineNo;
    check();
}

void ArrayDecAST::check() {
    boost::shared_ptr<Identifier> type =
      _st->lookupCurrLevelAndEnclosingLevels(_elemType);
    boost::shared_ptr<Identifier> name =
      _st->lookupCurrLevelOnly(_name);

    if (!type) {
        Utils::printSemErr(_lineNo, _elemType + " is not a type!");
    } else if (type->getBaseName() != "Type") {
        Utils::printSemErr(_lineNo, _elemType + " is not a type!");
    } else if (name) {
        Utils::printSemErr(_lineNo, _name + " has already been declared in " +
                             "this scope.");
    } else if (!_length || !_length->getType()) {
        Utils::printSemErr(_lineNo, "Bad array size due to an earlier error.");
    } else if (_length->getType()->getTypeName() != "Number") {
        Utils::printSemErr(_lineNo, "Array size must be a Number, not a " +
                             _length->getType()->getTypeName());
    } else {
        boost::shared_ptr<Type> typeCasted =
          boost::shared_polymorphic_downcast<Type>(type);
        boost::shared_ptr<Array> a(new Array(typeCasted));
        _st->add(_name, a);
    }
}
