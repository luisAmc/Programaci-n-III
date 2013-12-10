#pragma once
#include "object.h"
#include <string>
using std::string;

class Person: public Object{
	string name;
	int age;
  public:
	Person(const string&, int);
	Person(const Person&);
	virtual ~Person();
	virtual string toString()const;
	void bday();
};

