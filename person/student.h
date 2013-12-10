#pragma once
#include "person.h"
#include <string>
using std::string;

typedef unsigned int UINT ;

class Student:public Person{
	UINT id;
	double average;
	UINT credits;
  public:
	Student(const string&, int, UINT);
	Student(const Student&);
	virtual ~Student();
	virtual string toString()const;
	void addGrade(double, UINT);
};
