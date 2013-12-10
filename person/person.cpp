#include "object.h"
#include "person.h"
#include <string>
#include <sstream>
#include <iostream>
using std::string;
using std::stringstream; 
using std::cerr;
using std::endl;

Person::Person(const string& aName, int anAge):name(aName),age(anAge){
	cerr << "Constructor Person" << endl;
}
Person::Person(const Person& p):name(p.name), age(p.age){
	cerr << "Constructor de Copia de Person" << endl;
}
Person::~Person(){
	cerr << "Destructor Person" << endl;
}
string Person::toString()const{
	stringstream ss;
	ss << "Person: " << name << ", " << age;
	return ss.str();
}
void Person::bday(){
	age++;
}

