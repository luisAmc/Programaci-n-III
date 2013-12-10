#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::getline;
using std::string;

int main () {
	string nombre;
	cuadrado c;
	c.imprimir(4);

	getline( cin, nombre );
	cout << "Hola " << nombre << endl;
}