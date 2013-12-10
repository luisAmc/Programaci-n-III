#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int tirardado();

int main (int argc, char * argv[]) {
	if (argc != 2) {
		cerr << "Numero incorrecto de parametros" << endl;
		cerr << "Uso: " << endl;
		cerr << argv[0] << " n" << endl;
		cerr << "n es el numero de veces a tirar el dado" << endl;
		return 1;
	}
	int n = atoi(argv[1]);
	srand(time(0));
	int dados[6][6];
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			dados[i][j] = 0;
	
	int dado1, dado2;
	for (int i = 0; i < n; i++){
		//cout << setw(10) << tirardado() << setw(10) << tirardado() << endl;
		dado1 = tirardado();
		dado2 = tirardado();
		dados[dado1 - 1][dado2 - 1]++;
	}

	cout << "    ";
	for (int i = 0; i < 5; i++) 
		cout << setw(6) << (i + 1);
	cout << endl;
 
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++)
			cout << setw(6) << dados[i][j];
		cout << endl;
	}

	cout << endl;

	cout << "    ";
	for (int i = 0; i < 5; i++) 
		cout << setw(6) << (i + 1);
	cout << endl;
 
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++)
			cout << setw(6) << setprecision(3) << fixed << static_cast<double>(dados[i][j]) / n;
		cout << endl;
	}
	return 0;
}

int tirardado() {
	return rand() % 6 + 1;
}