#include "person.h"
#include "student.h"
#include <string>
#include <sstream>
#include <iostream>
using std::string;
using std::stringstream; 
using std::cerr;
using std::endl;

Student::Student(const string& name, int age, UINT anID):Person(name, age), id(anID){
	cerr << "Constructor Student" <<endl;
}
Student::Student(const Student& s):
	Person(s), id(s.id), average(s.average), credits(s.credits){
	
	cerr << "Constructor de Copia Student" <<endl;
}
Student::~Student(){
	cerr << "Destructor Student" <<endl;
}
string Student::toString()const{
	stringstream ss;
	ss << "Student, Average = " << average << " Credits = " << credits;
	return ss.str();
}
void Student::addGrade(double grade, UINT uv){
	average = (average * credits + grade * uv) / (credits + uv);
	credits += uv;
}
