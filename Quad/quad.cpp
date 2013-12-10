#include "quad.h"
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

Quad::Quad(int A, int B, int C, int D) :
a(A), b(B), c(C), d(D) {}

Quad::Quad(const Quad& q) {
	a = q.a;
	b = q.b;
	c = q.c;
	d = q.d;
}

Quad::~Quad() {
	cout << "Dtor Quad" << endl;
}

string Quad::toString() const {
	stringstream ss;
	ss << "Quad (" << a << ", " << b << ", " << c << ", " << d << ")";
	return ss.str();
}

int Quad::area() const {
	return -1;
}

int Quad::perimeter() const {
	return a + b + c + d;
}

int Quad::getA() const {
	return a;
}

int Quad::getB() const {
	return b;
}

int Quad::getC() const {
	return c;
}

int Quad::getD() const {
	return d;
}