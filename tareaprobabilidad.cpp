#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>

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
	vector <int> v;
	for (int i = 0; i < 6; i++)
		v.push_back(0);
	
	int dado1;
	for (int i = 0; i < n; i++){
		//cout << setw(10) << tirardado() << setw(10) << tirardado() << endl;
		dado1 = tirardado();
		v[dado1]++;
	}

	cout << "    ";
	for (int i = 0; i < 6; i++) 
		cout << setw(6) << (i + 1);
	cout << endl;
 
 	cout << "    ";
	for (int i = 0; i < 6; i++) {
		cout << setw(6) << setprecision(2) << fixed << static_cast<double>(v[i]) / n;
	}
	cout << endl;
	return 0;
}

int tirardado() {
	return rand() % 6 + 1;
}