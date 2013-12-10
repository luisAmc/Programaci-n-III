#include <cmath>
#include <string>
#include <iostream>

using namespace std;

class point3d {
public:
	//Constructores
	point3d();
	point3d(double, double, double);

	//Mutadores
	void setX();
	void setY();
	void setZ();
	double getX();
	double getY();
	double getZ();

	//Metodos de Administracion
	double calcularDistancia(point3d, point3d);
	int iguales(point3d, point3d);
	void transformacion(point3d);
	void toString();

private:
	double x;
	double y;
	double z;
};