#ifndef QUAD_H
#define QUAD_H

#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Quad {
	int a, b, c, d;
protected:
	int getA() const;
	int getB() const;
	int getC() const;
	int getD() const;
public:
	Quad(int, int, int, int);
	Quad(const Quad&);
	virtual ~Quad();
	virtual string toString() const;
	virtual int area() const = 0;
	int perimeter() const;
};

#endif