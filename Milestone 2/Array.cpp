#include "Array.hpp"

Array::Array(Type* elemType, int elems) {
	_elemType = elemType;
	_elems = elems;
}

Type* Array::getElemType() {
	return _elemType;
}

int Array::getSize() {
	return _elems;
}

string Array::getType() {
	return "Array";
}

/*
bool Array::check() {
	if (typeid _elems.value =! elemType) {
		return false;
	} else if(_value.size() =! _elems) {
		return false;
	}

	for(int i =0; i < elems; i++){
		if(!_value[i].check()) {
			return false;
		}
		else if(typeid _value[i] != typeid _elemType) {
			return false;
		}
	}

	return true;
}
*/
