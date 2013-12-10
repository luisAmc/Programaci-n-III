#include <iostream>
using namespace std;

int perfecto (int);
void imprimirDivisores (int);

int main (int argc, char * argv []) {
	int opcion = 1;
	int numero, contador = 0;
	while (opcion != 0) {
		cout << "\nSeleccione una opcion\n"
		<< "1.- Verificar si un numero es perfecto\n"
		<< "2.- Numeros perfectos entre 1 y 1000\n"
		<< "3.- Salir\n"
		<< "Ingrese su opcion:" << endl;
		cin >> opcion;

		switch (opcion) {
			case 1:
				cout << "\nIngrese un numero:" << endl;
				cin >> numero;

				cout << endl;//Salto de linea

				if (perfecto(numero)){
					cout << "\nEl numero es un numero perfecto!" << endl;
					imprimirDivisores(numero);
				}else 
					cout << "\nEl numero no es un numero perfecto!" << endl;	
				break;

			case 2:
				for (int n = 1; n < 1001; ++n) {
					cout << "\nEl numero evaluando es " << n << endl;

					if (perfecto(n)){
						cout << "\nEl numero es un numero perfecto!" << endl;
						imprimirDivisores(n);
						contador++;
					}else 
						cout << "\nEl numero no es un numero perfecto!" << endl;
				}//Final del for

				cout << "\nEl total de numeros perfectos es " << contador << endl;

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

int perfecto (int num) {
	int valor = 0;
	for (int d = 1; d < num; ++d) {
		if ((num % d) == 0) {
			valor += d;
		}//Final del if
	}//Final del for

	if (valor == num) {
		return valor;
	}//Final del if

	return 0;
}//Final de perfecto

void imprimirDivisores (int num) {
	for (int d = 1; d < num; ++d) {
		if ((num % d) == 0) 
			cout << "\nUn divisor de " << num << " es " << d << endl;
	}
}//Final del imprimirDivisores