#include "person.h"
#include "employee.h"
#include <string>
#include <sstream>
#include <iostream>
using std::string;
using std::stringstream; 
using std::cerr;
using std::endl;

using std::string;

Employee::Employee(const string& name, int age, double aSalary):
	Person(name, age), salary(aSalary){
	
	cerr << "Constructor Employee" << endl;
}
Employee::Employee(const string& name, int age, double aSalary, const string& aCia):
	Person(name,age),salary(aSalary),company(aCia){ 
	
	cerr << "Constructor Employee" << endl;
}
Employee::Employee(const Employee& e):Person(e),company(e.company),salary(e.salary){
	cerr << "Constructor de Copia Employee" << endl;
}
Employee::~Employee(){
	cerr << "Destructor Employee" << endl;
}
string Employee::toString()const{
	stringstream ss;
	ss << "Employee: " << company << " Salary: " << salary;
	return ss.str();
}
void Employee::promote(double p){
	if (p > 1)
		p /= 100.0;
	salary *= (1+p);
}

void Employee::demote(double p){
	if (p > 1)
		p /= 100.0;
	salary *= (1-p);
}
