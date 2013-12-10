#include <cmath>
#include <iostream>
#include <vector>

#include "point3d.h"

using namespace std;

int menu();

int main (int argc, char * argv []) {
	int continuar = 1, opcion, index = 0;
	vector <point3d> puntos;
	while (continuar) {
		opcion = menu();
		if (opcion == 1){
			cout << "\nPrimer punto 3D" << endl;
			point3d a;
			
			cout << "\nSegundo punto 3D:" << endl;
			point3d b;

			cout << "\nLa distancia entre los puntos es:" << endl;
			double distancia = a.calcularDistancia(a, b);
			cout << distancia << endl;
		} else if (opcion == 2) {	
			cout << "\nIngrese las coordenadas del punto" << endl;
			point3d a;
			a.transformacion(a);

		} else if (opcion == 3) {
			cout << "\nPrimer punto 3D" << endl;
			point3d a;
			
			cout << "\nSegundo punto 3D:" << endl;
			point3d b;

			if (a.iguales(a, b)) {
				cout << "\nEl punto " << endl;
				a.toString();
				cout << " y el punto " << endl;
				b.toString();
				cout << " son iguales!" << endl;
			} else {
				cout << "\nEl punto " << endl;
				a.toString();
				cout << " y el punto " << endl;
				b.toString();
				cout << " NO son iguales!" << endl;
			}

		} else if (opcion == 4) {
			continuar = 0;
		} else {
			cout << "\nOpcion no soportada!" << endl;
		}

	}
	return 0;
}

int menu () {
	int opcion = 0;
	cout << "\n\nSeleccione una opcion!" 
	<< "\n1. Calcular la distancia entre dos puntos"
	<< "\n2. Transformacion lineal"
	<< "\n3. Determinar si dos puntos son iguales"
	<< "\n4. Salir"
	<< "\nIngrese su opcion:" << endl;
	cin >> opcion;
	return opcion;
}

void imprimirVector(point3d puntos[], int t) {
	for (int i = 0; i < t; i++)
		puntos[i].toString();
}