#include <iostream>
#include <string>
using namespace std;

#include "LibroCalificaciones.h"

LibroCalificaciones::LibroCalificaciones (string nombre) {
	establecerNombreCurso (nombre);
}

void LibroCalificaciones::establecerNombreCurso (string nombre) {
	nombreCurso = nombre;
}

string LibroCalificaciones::obtenerNombreCurso () {
	return nombreCurso;
}

void LibroCalificaciones::mostrarMensaje () {
	cout << "Ingrese: " << obtenerNombreCurso() << "!" << endl;
}
