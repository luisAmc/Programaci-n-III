#include <iostream>
using namespace std;

int main(int argc, char * argv[]){

	int opcion;
	bool continuar = true;

	int da = 0; 
	int suma_da = 0;
	int amigos1 = 0;
	int amigos2 = 0;
	int suma1 = 0; 
	int suma2 = 0;
	int perfecto = 0;
	int suma_perfecto = 0;

	while (continuar) {
		cout << "\nBienvenido Usuario\n1. Numeros Amigos\n2. Numeros Perfectos\n3. Numeros Defectivos o Abundantes\n4. Salir" << endl;
		cin >> opcion;

		switch (opcion) {
			case 1:
				
				cout << "\nIngrese el primer numero:" << endl;
				cin >> amigos1;

				while (amigos1 <= 0) {
					cout << "\nIngrese el primer numero, recuerde que tiene que ser positivo:";
					cin >> amigos1;
				}

				cout << "\nIngrese el segundo numero:" << endl;
				cin >> amigos2;
				while (amigos2 <= 0) {
					cout << "\nIngrese el segundo numero, recuerde que tiene que ser positivo:";
					cin >> amigos2;
				}

				for (int i = 1; i < amigos1; ++i){
					if ((amigos1 % i) == 0){
						suma1 += i;
					}
				}

				for (int i = 1; i < amigos2; ++i){
					if ((amigos2 % i) == 0){
						suma2 += i;
					}
				}
				

				if ((suma2 == amigos1) && (suma1 == amigos2)){
					cout << "\nSon numeros amigos" << endl;
				} else {
					cout << "\nNo son numeros amigos" << endl;
				}
				break; //Final del caso 1

			case 2:


				cout << "\nIngrese el numero:" << endl;
				cin >> perfecto;
				while (perfecto <= 0) {
					cout << "\nIngrese el numero, recuerde que tiene que ser positivo:";
					cin >> perfecto;
				}

				for (int i = 1; i < perfecto; ++i){
					if ((perfecto % i) == 0){
						suma_perfecto += i;
					}
				}

				if (suma_perfecto == perfecto){
					cout << "\nEs numero perfecto" << endl;
				} else {
					cout << "\nNo es numero perfecto" << endl;
				}
				break; //Final del caso 2

			case 3:
				cout << "\nIngrese el numero:" << endl;
				cin >> da;
				while (da <= 0) {
					cout << "\nIngrese el numero, recuerde que tiene que ser positivo:";
					cin >> da;
				}

				for (int i = 1; i < da; ++i){
					if ((da % i) == 0){
						suma_da += i;
					}
				}

				if (suma_da > da){
					cout << "\nEs un numero abundante" << endl;
				} else {
					cout << "\nEs un numero defectivo" << endl;
				}
				break;

			default:
				continuar = false;
				break;	
		}//Final del switch

		da = 0; 
		suma_da = 0;
		amigos1 = 0;
	 	amigos2 = 0;
	 	suma1 = 0; 
	 	suma2 = 0;
	 	perfecto = 0;
	 	suma_perfecto = 0;

		opcion = 0;

		cout << "\nBienvenido Usuario\n1. Numeros Amigos\n2. Numeros Perfectos\n3. Numeros Defectivos o Abundantes\n4. Salir" << endl;
		cin >> opcion;
	}//Final del while

	return 0;
}//Final de la clase