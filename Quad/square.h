#ifndef SQUARE_H
#define SQUARE_H

#include "quad.h"
#include "rect.h"
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Square : public Rect {
public:
	Square(int);
	Square(const Square&);
	virtual ~Square();
	virtual string toString() const;
};

#endif