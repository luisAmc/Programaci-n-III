#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::getline;
using std::string;

class cuadrado{
public:
	void imprimir (int x) {
		for (int i = 0; i < x; ++i){
			cout << "*";
		}
		cout << " " << endl;

		for (int i = 0; i < x - 2; ++i){
			cout << "*";
			for (int i = 0; i < x - 2; ++i){
				cout << " ";
			}
			cout << "*" << endl;
		}

		for (int i = 0; i < x; ++i){
			cout << "*";
		}
		cout << endl;
	}
};

int main () {
	string nombre;

	cout << "Ingrese su nombre: ";
	getline( cin, nombre );
	cout << "Hola " << nombre << "\nEste es su cuadrado" << endl;

	cuadrado c;
	c.imprimir(4);	
}