#include <iostream>
using namespace std;

int primo (int);

int main (int argc, char * argv []) {
	int opcion = 1, numero;
	while (opcion != 0) {
		cout << "\nSeleccione una opcion\n"
		<< "1.- Verificar si un numero es primo\n"
		<< "2.- Ver los numero primos entre el 2 y el 10000\n"
		<< "3.- Salir\n"
		<< "Ingrese su seleccion:" << endl;
		cin >> opcion;

		switch (opcion) {
			case 1:
				cout << "\nIngrese un numero:" << endl;
				cin >> numero;

				if (!primo(numero))
					cout << "\nEl numero es primo!" << endl; 
				else 
					cout << "\nEl numero no es primo!" << endl;

				break;

			case 2:
				for (int n = 2; n < 10001; ++n){
					if (!primo(n))
						cout << "El numero " << n << " es primo!" << endl;
				}
				break;

			case 3:
				opcion = 0;
				break;

			default:
				cout << "\nOpcion no soportada!" << endl;
				break;			
		}//Final del switch
	}//Final del while general
}//Final del main

int primo (int num) {
	int valor = 0;
	for (int v = 2; v < num; ++v) {
		if ((num % v) == 0)
			valor++; 
	}//Final del for

	return valor; 
}//Final de primo