#include "quad.h"
#include "rect.h"
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

Rect::Rect (int b, int h) : Quad (b, h, b, h) {}

Rect::Rect(const Rect& r) : Quad (r) {}

Rect::~Rect (){
	cout << "Dtor Rect" << endl;
}

string Rect::toString() const {
	stringstream ss;
	ss << "Rect " << Quad::toString();
	return ss.str();
}

int Rect::area() const {
	return getA() * getB();
}