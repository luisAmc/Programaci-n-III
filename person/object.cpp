#include "object.h"
#include <string>
#include <sstream>
#include <iostream>
#include <typeinfo>

using std::string;
using std::stringstream; 
using std::cerr;
using std::endl;

Object::Object(){
	cerr << "Constructor de Object" << endl;
}
Object::~Object(){
	cerr << "Destructor de Object" << endl;
}
string Object::toString()const{
	stringstream ss;
	ss << typeid(*this).name() << " " << this;
	return ss.str();
}
