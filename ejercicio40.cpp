#include <iostream>
using namespace std;

long int potencia (int, int);

int main (int argc, char * argv []) {
	int opcion = 1, numero, exponente;
	while (opcion != 0) {
		cout << "\nPotencia\n"
		<< "Ingrese la base y exponente separados por un espacio: " << endl;
		cin >> numero >> exponente;

		cout << "El resultado es " << potencia(numero, exponente) << endl;
	}
}//Final del main

long int potencia (int num, int expo) {
	if (expo == 1)
		return num;
	else 
		return num * potencia(num, expo - 1); 
}//Final de potencia