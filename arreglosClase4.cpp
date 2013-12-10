#include <iostream>
#include <cmath>
using namespace std; 

int main (int argc, char * argv []) {
	const int N = 10;
	double data [N];

	//Leer
	for (int i = 0; i < N; i++) {
		cout << "Elemento " << (i + 1) << ": ";
		cin >> data[i];
	}

	//Calculos
	double p = 0;
	for (int i = 0; i < N; ++i)
		p += data[i];
	p /= N;

	double s = 0;
	for (int i = 0; i < count; ++i)
		s += pow(data[i] - p, 2.0);
	s /= ()
}//Final del main