#include <iostream>
using namespace std;

long int enteroPotencia (int, int);

int main (int argc, char * argv []) {
	int opcion = 1;
	int base, exponente;
	while (opcion != 0) {
		cout << "\nIngrese la base (un numero entero) y el exponente (un numero entero distinto de cero):" << endl;
		cin >> base >> exponente;
			
		cout << "\nEl resultado es " << enteroPotencia(base, exponente) << endl;
	}//Final del while general
}//Final del main

long int enteroPotencia (int base, int exponente) {
	long int valor = 1;
	for (int veces = 0; veces < exponente; ++veces) {
		valor *= base;
	}//Final del for
	return valor;
}//Final del enteroPotencia