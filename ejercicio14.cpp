#include <iostream>
#include <math.h>
using namespace std;

double redondearAEntero (double);
double redondearADecimas (double);
double redondearACentesimas (double);
double redondearAMilesimas (double);

int main(int argc, char * argv []){
	int opcion = 1;
	double valor;
	while (opcion != 0) {
		cout << "\nIngrese un valor:" << endl;
		cin >> valor;
		cout << "\nEl valor original es: " << valor << endl;
		cout << "El numero redondeado al entero mas cercano es: " << redondearAEntero(valor) << endl;
		cout << "El numero redondeado a la decima mas cercana es: " << redondearADecimas(valor) << endl;
		cout << "El numero redondeado a la centecima mas cercana es: " << redondearACentesimas(valor) << endl;
		cout << "El numero redondeado a la milesima mas cercana es: " << redondearAMilesimas(valor) << endl; 
	}//Final del while general
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