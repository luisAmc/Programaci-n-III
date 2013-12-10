#pragma once
#include "person.h"
#include "string"
using std::string;

class Employee: public Person{
	string company;
	double salary;
  public:
	Employee(const string&, int, double);
	Employee(const string&, int, double, const string&);
	Employee(const Employee&);
	virtual ~Employee();
	virtual string toString()const;
	void promote(double);
	void demote(double);
};
