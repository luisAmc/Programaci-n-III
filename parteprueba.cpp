#include <string>
#include "parteprueba.h"

parteprueba::parteprueba(string nombre){
	setNombre(nombre);
}

void parteprueba::setNombre(string nombre){
	nombreprueba = nombre;
}

string parteprueba::getNombre(){
	return nombreprueba;
}