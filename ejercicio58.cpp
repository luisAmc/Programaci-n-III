#include <iostream>
using namespace std;

#include "plantillaEjercicio58.h"

int main (int argc, char * argv []) {
	int opcion = 1, n1, n2;
	char l1, l2;
	double d1, d2;
	while (opcion != 0) {
		cout << "\nMinimo de dos valores"
		<< "\nDeterminar el menor de dos argumentos de tipo :"
		<< "\n1.- Enteros"
		<< "\n2.- Caracter"
		<< "\n3.- Numero de tipo flotante"
		<< "\n4.- Salir"
		<< "\nIngrese su opcion:" << endl;
		cin >> opcion;

		switch (opcion) {
			case 1:
				cout << "\nIngrese los dos enteros, separados por un espacio:" << endl;
				cin >> n1 >> n2;

				cout << "\nEl valor minimo es el " << minimo(n1, n2) << endl;
				break;

			case 2:
				cout << "\nIngrese los dos caracteres, separados por un espacio:" << endl;
				cin >> l1 >> l2;

				cout << "\nEl valor minimo es el " << minimo(l1, l2) << endl;
				break;

			case 3:
				cout << "\nIngrese los dos numeros de punto flotante, separados por un espacio:" << endl;
				cin >> d1 >> d2;

				cout << "\nEl valor minimo es el " << minimo(d1, d2) << endl;
				break;		

			case 4:
				opcion = 0;
				break;	

			default:
				cout << "\nOpcion no soportada!" << endl;
				break;	
		}//Final del switch
	}//Final del while
}//Final del main