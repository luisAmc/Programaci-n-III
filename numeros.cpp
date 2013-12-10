#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

using namespace std; 

int pideNumero ();

int main (int argc, char * argv[]) {
	int numero;
	do {
		cout << "\nIngrese un entero:" << endl;
		numero = pideNumero();
	} while (numero == -1);
	cout << "-> El entero es " << numero << endl;
	return 0;
}

int pideNumero () {
	string x;
	int cont = 0, numero, puntos;
	cin >> x;

	if (x.find("-") == 0) 
		cont--;

	for (int i = 0; i < x.length(); i++) {
		if (!isdigit(x[i]))
			cont++;
	}

	if (cont != 0) {
		cout << "\nTiene que ingresar un entero!" << endl;
		return -1;
	}

	numero = atoi(x.c_str());
	return numero;
}