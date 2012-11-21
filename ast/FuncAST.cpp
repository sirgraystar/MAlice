#include "FuncAST.hpp"

FuncAST::FuncAST(boost::shared_ptr<SymbolTable> st, string name, boost::shared_ptr<CallParamsAST> params) : ASTNode(st) {
	_st = st;
	_name = name;
	_params = params;
	check();
}

void FuncAST::check() {
	boost::shared_ptr<Identifier> function = _st->lookupCurrLevelAndEnclosingLevels(_name);
	
	if (!function) {
		cerr << "Function " << _name << " not in scope" << endl;
	} else if (function->getBaseName() != "Function") {

	} else {
		boost::shared_ptr<Function> funcCasted = boost::shared_polymorphic_downcast<Function>(function);
		
		if (!parametersTypeCheck(funcCasted)) {

		}
	}
}

bool FuncAST::parametersTypeCheck(boost::shared_ptr<Function> function) {
	vector< boost::shared_ptr<Param> > params = function->getParams();
	vector< boost::shared_ptr<Param> >::iterator i = params.begin();
	
	vector< boost::shared_ptr<Type> > paramTypes = _params->getTypes();
	vector< boost::shared_ptr<Type> >::iterator j = paramTypes.begin();
	
	if (params.size() != paramTypes.size()) {
		cerr << "Invalid number of arguments for " << _name << " (expected " << paramTypes.size()
		<< ", got " << params.size() << ")" << endl;
		return false;
	}

	for (; j != paramTypes.end(); ++j) {
		if ((*i)->getTypeName()->getBaseName() != (*j)->getBaseName()) {
			cerr << "Type mismatch for " << _name << endl;
			return false;
		} else {
			++i;
		}
	}
}
