#include <iostream>
#include <math.h>
using namespace std;

double redondearAEntero (double);
double redondearADecimas (double);
double redondearACentesimas (double);
double redondearAMilesimas (double);

int main(int argc, char * argv []){
	double x = 3.4412566, y;
	y = floor(x * 10 + 0.5) / 10;
	cout << y << endl;
	return 0;
}//Final del main

double redondearAEntero (double x) {
	return floor(x);
}//Final del redondearAEntero

double redondearADecimas (double x) {
	return (floor(x * 10) / 10);
}//Final del redondearADecimas

double redondearACentesimas (double x) {
	return (floor(x * 100) / 100);
}//Final del redondearACentesimas

double redondearAMilesimas (double x) {
	return (floor(x * 1000) / 1000);
}//Final del redondearAMilesimas