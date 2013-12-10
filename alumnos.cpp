#include <iostream>
#include <iomanip>

using namespace std;

//Un tipo definido por el usuario: User Defined Type
struct Alumno{
	char nombre[30];
	int edad;
	int notas[3];
	double promedio;
};


void readAlumno(Alumno&);
void printAlumno(const Alumno&);
int main(int argc, char* argv[]){
	int n;
	cout << "Cuantos Alumnos";
	cin  >> n;
	Alumno* alumnos = new Alumno[n];
	for (int i=0; i<n; i++)
		readAlumno(alumnos[i]);

	// Calcular el Promedio de Cada Alumno
	double tmp;
	for (int i=0; i<n; i++){
		tmp = 0;
		for (int j=0; j<3; j++)
			tmp += alumnos[i].notas[j];
		tmp /= 3;
		alumnos[i].promedio = tmp;
}
for (int i=0; i<n; i++){
printAlumno(alumnos[i]);	
}

	delete[] alumnos;

	return 0;
}
void printAlumno(const Alumno& a){
	cout << setw(35) << a.nombre << setw(5) << a.edad;
	for (int i=0; i<3; i++)
		cout << setw(4) << a.notas[i];
	cout << setprecision(2) << fixed << setw(7) << a.promedio;
	cout << endl;
}
void readAlumno(Alumno& a){
	cout << "Nombre: ";
	cin.ignore();
	cin.getline(a.nombre, 30);
	cout << "Edad: ";
	cin >> a.edad;
	cout << "Las notas: " << endl;
	for (int i=0; i<3; i++)
		cin >> a.notas[i];
}