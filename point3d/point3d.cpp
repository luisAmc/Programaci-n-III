#include <cmath>
#include <iostream>

#include "point3d.h"

using namespace std;

//Contructores
point3d::point3d() {
	setX();
	setY();
	setZ();
}

point3d::point3d(double a, double b, double c) {
	x = a;
	y = b;
	z = c;
}

//Mutadores
void point3d::setX() {
	int a;
	cout << "\nIngrese la coordenada en X del punto:" << endl;
	cin >> a;
	x = a;
}

void point3d::setY() {
	int a;
	cout << "\nIngrese la coordenada en Y del punto:" << endl;
	cin >> a;
	y = a;
}

void point3d::setZ() {
	int a;
	cout << "\nIngrese la coordenada en X del punto:" << endl;
	cin >> a;
	z = a;
}

double point3d::getX() {
	return x;
}

double point3d::getY() {
	return y;
}

double point3d::getZ() {
	return z;
}

//Metodod de administracion
double point3d::calcularDistancia(point3d A, point3d B) {
	double a = pow((A.x - B.x), 2.0);
	double b = pow((A.y - B.y), 2.0);
	double c = pow((A.z - B.z), 2.0);
	double distancia = sqrt(a + b + c);
	return distancia;
}

int point3d::iguales(point3d a, point3d b) {
	double a1 = a.getX();
	double a2 = b.getX();
	double b1 = a.getY();
	double b2 = b.getY();
	double c1 = a.getZ();
	double c2 = b.getZ();

	if ((a1 == a2) && (b1 == b2) && (c1 == c2)) {
		return 1;
	}

	return 0;
}

void point3d::transformacion(point3d a) {
	if (a.getZ() == 0) {
		cout << "\nNo se pudo hacer la transformacion." << endl;
	} else {
		double i = a.getX() / a.getZ();
		double j = a.getY() / a.getZ();

		cout << "\nEl punto transformado es [" << i << ", " << j << "]" << endl;  
	}
}

void point3d::toString() {
	cout << "[" << x << ", " << y << ", " << z <<  "]";
}