#include <iostream>
#include <string>
#include "parteprueba.h"

int main (int argc, char * argv []) {
	string nombre;
	cout << "Ingrese: " << endl;
	getline(cin, nombre);
	parteprueba pp(nombre);
	cout << "hola " << pp.getNombre() << endl;
	return 0;
} 