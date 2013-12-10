#include "quad.h"
#include "rect.h"
#include "square.h"
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

Square::Square (int l) : Rect (l, l) {}

Square::Square (const Square& s) : Rect(s) {}

Square::~Square () {
	cout << "Dtor Square" << endl;
}

string Square::toString () const {
	stringstream ss;
	ss << "Square " << Rect::toString();
	return ss.str();
}