#ifndef COMPLEX_H
#define COMPLEX_H

class complex {
	double real, imag;
public:
	complex (double = 0, double = 0);
	complex suma (complex);
	complex resta (complex);
	complex assign (complex);
	void print();
};

#endif