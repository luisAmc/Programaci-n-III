#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
void llenarArreglo (T[], int);
template <class T>
void ssort(T[], int);
template <class T>
void imprimirArreglo (T[], int);
template <class T>
void ss (int);

int main (int argc, char * argv[]) {
	ss(5);
	return 0;
}

template <class T>
void llenarArreglo (T a[], int t) {
	T valor;
	for (int i = 0; i < t; i++){
		cout << "Ingrese el valor " << (i + 1) << ":" << endl;
		cin >> valor;
		a[i] = valor;
	}
}

template <class T>
void ssort (T a[], int t) {
	int minimo;
	T menor;
	if (t > 1){
		minimo = 0;
		for (int i = 0; i < t; i++){
			if (a[i] < a[minimo])
				minimo = i;
		}
		menor = a[0];
		a[0] = a[minimo];
		a[minimo] = menor;
		ssort (a + 1, t - 1);
	}
}

template <class T>
void imprimirArreglo (T a[], int t) {
	for (int i = 0; i < t; i++)
		cout << setw(4) << a[i] << endl;
}

template <class T>
void ss (int tamano) {
	T a[tamano];
	llenarArreglo(a, t);
	ssort(a, t);
	cout << "El arreglo original es:" << endl;
	imprimirArreglo(a, t);
	ssort(a, t);
	cout << "El arreglo ordenado es:" << endl;
	imprimirArreglo(a, t);
}