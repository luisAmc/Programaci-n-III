#pragma once
#include <string>
using std::string;

class Object{
  public:
	Object();
	virtual ~Object();
	virtual string toString()const;
};
