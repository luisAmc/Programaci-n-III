#include <iostream>
#include <vector>
using namespace std;

void ordenamientoSeleccion (double [], int);
void leerArreglo (double [], int);
void imprimirArreglo (double [], int);

int main (int argc, char * argv []) {
	int tamano;
	cout << "Ingrese el tamano del arreglo: " << endl;
	cin >> tamano;
	double arreglo [tamano];
	leerArreglo(arreglo, tamano);
	cout << "El arreglo original es: "; 
	imprimirArreglo(arreglo, tamano);
	ordenamientoSeleccion(arreglo, tamano);
	cout << "El arreglo ordenado es: "; 
	imprimirArreglo(arreglo, tamano);
	return 0;
}//Final del main

void ordenamientoSeleccion (double arreglo[], int t) {
	int minimo;
	double menor;
	if (t > 1){
		minimo = 0;
		for (int i = 0; i < t; i++){
			if (arreglo[i] < arreglo[minimo])
				minimo = i;
		}
		menor = arreglo[0];
		arreglo[0] = arreglo[minimo];
		arreglo[minimo] = menor;
		ordenamientoSeleccion (arreglo + 1, t - 1);//Marcador
	}
}

void leerArreglo (double arreglo [], int t) {
	for (int i = 0; i < t; i++){
		cout << "Ingrese el elemento " << (i + 1) << ": " << endl;
		cin >> arreglo[i];
	}
}

void imprimirArreglo (double arreglo [], int t) {
	for (int i = 0; i < t; i++)
		cout << arreglo[i] << " ";
	cout << endl;
}