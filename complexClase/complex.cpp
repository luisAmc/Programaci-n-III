#include <iostream>

#include "complex.h"

using namespace std;

complex::complex (double r, double i) {
	real = r;
	imag = i;
}

complex complex::suma (complex r) {
	return complex(real + r.real, imag + r.imag);
} 

complex complex::resta (complex r) {
	return complex(real - r.real, imag - r.imag);
} 

complex complex::assign (complex r) {
	real = r.real;
	imag = r.imag;
}

void complex::print () {
	if ((real == 0) && (imag == 0)) {
		cout << "0" << endl;
	} else if ((real == 0) && (imag != 0)) {
		cout << imag << "i" << endl;
	} else if ((real != 0) && (imag == 0)) {
		cout << real << endl;
	} else if ((real != 0) && (imag < 0)) {
		cout << real << " - " << (imag * (-1)) << "i" << endl;
	} else if ((real != 0) && (imag > 0)) {
		cout << real << " + " << imag << "i" << endl;
	}
}