#include "polynomial.h"
#include <iostream>
using namespace std;

int main (int argc, char* argv[]){
	cout << "voy a crear" << endl;
	Polynomial a(4), b(3), c(2), d;
	cout << "ya cree" << endl;
	a[0] = 2;
	a[1] = 1;
	a[2] = 0;
	a[3] = 4;
	a[4] = -3;
	b[0] = -1;
	b[1] = 0;
	b[2] = 2;
	b[3] = 7;
	c[0] = 5;
	c[1] = 4;
	c[2] = 2;
	cout << "------------------------------------------" << endl;
	cout << "a= " << a << endl
		<< "b=" << b << endl
		<< "c=" << c << endl
		<< "d=" << d << endl;
	cout << "------------------------------------------" << endl;
	cout << "El polinomio c evaluado en 5" << endl;
	double val;
	val = c(5);
	cout << val << endl;
	cout << "------------------------------------------" << endl;
	cout << "La derivada de b" << endl;
	d = b();
	cout << d << endl;
	cout << "------------------------------------------" << endl;
	cout << "La integral de c con los limites de 2 a 5" << endl;
	val = c(2,5);
	cout << val << endl;
	cout << endl << "La suma de b + a" << endl; 
	d = b + a;
	cout << d << endl;
	cout << "------------------------------------------" << endl;

}