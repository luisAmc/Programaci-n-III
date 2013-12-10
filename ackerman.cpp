#include <iostream>
using namespace std;

int Ackerman (int, int);

int main (int argc, char * argv []) {
	int opcion = 1, num1, num2;
	while (opcion != 0) {
		cout << "\nIngrese dos numero, separados por un espacio:" << endl;
		cin >> num1 >> num2;

		cout << "\nEl resultado de la funcion de Ackerman es " << Ackerman(num1, num2) << endl;
	}
}

int Ackerman (int m, int n) {
	if (m == 0) {
		return n + 1;
	} else if ((m > 0) && (n == 0)) {
		return Ackerman (m - 1, 1);
	} else {
		return Ackerman (m - 1, (Ackerman(m, n - 1)));
	}
}