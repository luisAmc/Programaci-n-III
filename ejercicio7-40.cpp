#include <iostream>
#include <vector>
using namespace std;

void leerVector (vector<int>);
int minimoVector (vector<int>, int, int);
void imprimirArreglo (vector<int>, int);

int main (int argc, char * argv []) {
	vector <int> v;
	int contador = leerVector(v);
	cout << "El vector original es " << endl;
	imprimirArreglo(v, contador);
	cout << "El valor minimo dentro del vector es " << minimoVector(v, v.size(), v[0]);
	return 0;
} 

int leerVector (vector <int> v) {
	int n, contador;
	while (1) {
		cout << "n = ";
		cin >> n;
		if (n < 0)
			break;
		v.push_back(n);
		contador++;	 
	}
	return contador;
}

int minimoVector (vector<int> v, int i, int minimo) {
	if (i == 0) {
		return minimo;
	} else {
		if (v[i] < minimo)
			minimo = v[i];
		return minimoVector(v, i - 1, minimo);
	}
}

void imprimirArreglo (vector<int> arreglo, int cont) {
	for (int i = 0; i < cont; i++)
		cout << arreglo[i] << " ";
	cout << endl;
}