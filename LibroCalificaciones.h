#include <iostream>
#include <string>
using std::string;

class LibroCalificaciones {
public:
	LibroCalificaciones (string);
	void establecerNombreCurso (string);
	string obtenerNombreCurso ();
	void mostrarMensaje ();
private:
	string nombreCurso;
};