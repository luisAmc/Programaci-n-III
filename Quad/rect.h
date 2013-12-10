#ifndef RECT_H
#define RECT_H

#include "quad.h"
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Rect : public Quad {
public:
	Rect(int, int);
	Rect(const Rect&);
	virtual ~Rect();
	virtual string toString() const;
	virtual int area() const;
};

#endif