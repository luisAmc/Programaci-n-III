#include <iostream>
using namespace std;

int main (int argc, char * argv[]) {
	int opcion = 1, tam;
	while (opcion != 0) {
		cout << "\nSeleccione una figura:\n"
			<< "1) Figura 1\n"
			<< "2) Figura 2\n"
			<< "3) Figura 3\n"
			<< "4) Salir\n"
			<< "Ingrese su opcion:" << endl;
		cin >> opcion;
		cout << endl;

		switch(opcion){
			case 1:
				cout << "Ingrese el tamano de la figura:" << endl;
				cin >> tam;
				cout << endl;
				for(int i = 0; i < tam; i++){
					for(int j = 0; j < i + 1; j++){
						cout << "* ";
					}
					cout << endl;
				}
				break;

			case 2:
				cout << "Ingrese el tamano de la figura:" << endl;
				cin >> tam;
				cout << endl;
				for(int i = 1; i <= tam; i++){
					for(int j = 0; j < tam - i; j++){
						cout << "  ";
					}
					for(int k = 0; k < i; k++){
						cout << "* ";
					}
					cout << endl;
				}
				break;

			case 3:
				cout << "Ingrese el tamano de la figura:" << endl;
				cin >> tam;
				cout << endl;
				for(int i = 0; i < tam; i++){
					if(((i - 1) % 2) == 0){
						cout << " ";
					} 
					for(int j = tam - i; j > 0; j--){
						cout << "* ";
					}
					cout << endl;
				}
				break;

			case 4:
				opcion = 0;
				break;

			default:
				cout << "\nOpcion no soportada." << endl;
				break;				
		}
	}
}