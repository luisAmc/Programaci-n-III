#include <iostream>
#include <string>
using namespace std;

#include "LibroCalificaciones.h"

int main () {
	LibroCalificaciones l1 ("soy el 1");
	LibroCalificaciones l2 ("soy el 2");

	cout << "blablabla" << l1.obtenerNombreCurso() << ", " << l2.obtenerNombreCurso() << endl;
	return 0;
}