#include <iostream>
using namespace std;

int MCD (int, int);

int main (int argc, char * argv []) {
	int opcion = 1, num1, num2;
	while (opcion != 0) {
		cout << "\nMaximo Comun Divisor\n"
		<< "Ingrese los dos numeros separados por un espacio:" << endl;
		cin >> num1 >> num2;

		cout << "El maximo comun divisor entre " << num1 << " y " << num2 << " es el " << MCD(num1, num2) << endl;
	}//Final del while general
}//Final del main

int MCD (int num1, int num2) {
	int mcd = 1;
	if (num1 == num2) {
		for (int e = 2; e <= num1; ++e) {
			if ((num1 % e) == 0)
				mcd = e;
		}
	} else if (num1 > num2) {
		for (int e = 2; e <= num2; ++e) {
			if (((num1 % e) == 0) && (num2 % e) == 0) 
				mcd = e;
		}
	} else if (num2 > num1) {
		for (int e = 2; e <= num1; ++e) {
			if (((num1 % e) == 0) && (num2 % e) == 0)
				mcd = e;
		}
	}

	return mcd;
}//Final del mcd