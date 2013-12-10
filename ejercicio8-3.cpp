#include <iostream>
#include <iomanip>
using namespace std;

int main (int argc, char * argv []) {
	const int tamanio = 10;
	double numeros[tamanio] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
	double *nPtr = NULL;

	cout << "\nCon el arreglo" << endl;
	for (int i = 0; i < tamanio; i++)
		cout << setprecision(1) << fixed << numeros[i] << setw(5);
	cout << endl;

	nPtr = numeros;//El identificador de un arreglo es un puntero al primer elemento del arreglo
	nPtr = &numeros[0];//La direccion del primer elemento del arreglo

	cout << "\nCon el apuntador" << endl;
	for (int i = 0; i < tamanio; i++) {
		cout << setprecision(1) << fixed << *nPtr << setw(5);
		nPtr++;
	}
	nPtr = numeros;
	cout << endl;

	cout << "\nCon el nombre del arreglo como apuntador" << endl;
	for (int i = 0; i < tamanio; i++) 
		cout << setprecision(1) << fixed << numeros[i] << setw(5);
	cout << endl;

	cout << "\nUsando el arreglo con la notacion apuntador/subindice con nPtr" << endl;
	for (int i = 0; i < tamanio; i++) 
		cout << setprecision(1) << showpoint << fixed << nPtr[i] << setw(5);////////////
	cout << "\n" << endl;

	//Haciendo referencia al cuarto elemento
	cout << numeros[3] << endl;//Usando la notacion de subindice de arreglo
	cout << *(numeros + 3) << endl;//Notacion apuntador/desplazamiento con el nombre del arreglo como apuntador
	cout << nPtr[3] << endl;//Notacion de subindice de apuntador con nPtr////////////
	cout << *(nPtr + 3) << endl;//Notacion apuntador/desplazamiento con nPtr

	/*
	i) 	Los numeros de punto flotante con precision doble se almacenan el 8 bytes
	   	Posicion inicial = 1002500 en la memoria
		Que direccion de desreferencia mediante nPtr + 8?
		Cual es el valor almacenado en esa ubucacion?

		-> Si corremos el apuntador 8 posiciones (los cuales son numeros de punto flotante, c/u con 8 bytes)
			entonces: (8 * 8) + 1002500
					   = 64 + 1002500
					   = 1002564 -> direccion
					   8.8 -> valor que almacena la direccion



   	j)	Los numeros de punto flotante con precision doble se almacenan el 8 bytes
	   	Posicion inicial = 1002500 en la memoria
	   	Que direccion se desrefencia mediante nPtr -= 4?
	   	Cual es el valor almacenado en esa ubucacion?

	   	-> Si corremos el apuntador 5 posiciones (los cuales son numeros de punto flotante, c/u con 8 bytes)
	   		entonces:  (5 * 8) + 1002500 - (4 * 8)
	   				   = 40 + 1002500 - (4 * 8)
	   				   = 1002540 - 32
					   = 1002508 -> direccion de referencia despues de nPtr -= 4
			
			1002508 - 1002500 = 8 -> la cantidad de bytes de un numero de punto flotante
			entonces el valor de la dirreccion es 1.1
	*/

}//Final del main