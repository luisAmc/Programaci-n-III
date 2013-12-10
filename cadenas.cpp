#include <iostream>
#include <iomanip>

using namespace std;

int main (int argc, char * argv[]) {

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////
	char a[20];
	char b[20];

	//cout << "Ingrese la palabra: " << endl;
	//cin >> setw(20) >> a >> setw(20) >>b;

	*************************************************************************
	Lee unicamente 19 caracteres (el #20 lo deja para el caracter nulo)
	si hay mas caracteres despues los puede ingresar en otro arreglo de caracteres
	*************************************************************************

	//cout << "soy a: " << a << ", soy b: " << b <<  endl;
*///////////////////////////////////////////////////////////////////////////////////////////////////////////


	char a[80];
	cout << "Ingrese la palabra: " << endl;
	cin.getline(a, 20, '-');

	/*************************************************************************
	Lee los 19 caracteres (el #20 siempre lo deja para el caracter nulo)
	los caracteres restantes no son leidos, o bien lee los caracteres hasta
	al caracter especificado en el tercer argumento (indicador de fin de archivo).

	El tercer argumento predeterminado es el '\n'
	*************************************************************************/

	cout << "La palabra es: " << a << endl;

	return 0;
}