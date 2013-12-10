#include "polynomial.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <math.h>
using namespace std;

Polynomial::Polynomial(int d){
	degree = d;
	coef = new double[degree + 1];
	if (!coef) {
		cerr << "Ocupo memoria!" << endl;
		exit(1);
	}
}
Polynomial::Polynomial(const Polynomial& p){
	degree = p.degree;
	coef = new double[degree + 1];
	if (!coef) {
		cerr << "Ocupo memoria!" << endl;
		exit(1);
	}
	for (int i = 0; i < degree + 1; i++)
		coef[i] = p.coef[i];
}
Polynomial::~Polynomial(){
	if (coef)
		delete[] coef;
}
const Polynomial& Polynomial::operator=(const Polynomial& p){
	if (degree != p.degree){
		degree = p.degree;
		delete[] coef;
		coef = new double[degree + 1];
		if (!coef) {
			cerr << "Ocupo memoria!" << endl;
			exit(1);
		}
	}
	for (int i = 0; i < degree + 1; i++)
		coef[i] = p.coef[i];
	return *this;
}
const Polynomial Polynomial::operator+(const Polynomial& p){
	if(degree < p.degree){
		Polynomial poly(p.degree);
		for (int i = 0; i < p.degree + 1; i++)
			poly.coef[i] = p.coef[i];
		for (int i = 0; i < degree + 1; i++)
			poly.coef[i] += coef[i];
		return poly;
	} else {
		Polynomial poly(degree);
		for (int i = 0; i < degree + 1; i++)
			poly.coef[i] = coef[i];
		for (int i = 0; i < p.degree + 1; i++)
			poly.coef[i] += p.coef[i];
		return poly;
	}
	return *this;
}
const Polynomial& Polynomial::operator+=(const Polynomial& p){
	if (p.degree < degree) {
		for (int i = 0; i < p.degree + 1; i++)
			coef[i] += p.coef[i];
	} else if (degree < p.degree) {
		double* auxiliar = new double[p.degree + 1];
		if (!auxiliar) {
			cerr << "Ocupo memoria!" << endl;
			exit(1);
		}
		for (int i = 0; i < p.degree + 1; i++)
			auxiliar[i] = p.coef[i];
		for (int i = 0; i < degree + 1; i++)
			auxiliar[i] += coef[i];
		delete[] coef;
		coef = auxiliar;
		degree = p.degree;
	} 
	return *this;
}
const Polynomial Polynomial::operator-(const Polynomial& p){
	double* auxiliar;
	if (degree < p.degree){
		auxiliar = new double[p.degree + 1];
		for (int i = 0; i < p.degree + 1; i++)
			auxiliar[i] = p.coef[i];
		for (int i = 0; i < degree + 1; i++)
			auxiliar[i] -= coef[i];
	} else if (degree > p.degree){
		auxiliar = new double[degree + 1];
		for (int i = 0; i < degree + 1; i++)
			auxiliar[i] = coef[i];
		for (int i = 0; i < p.degree + 1; i++)
			auxiliar[i] -= p.coef[i];
	}
	Polynomial poly;
	poly.coef = auxiliar;
	return poly;
}
const Polynomial& Polynomial::operator-=(const Polynomial& p){
	if (p.degree < degree) {
		for (int i = 0; i < p.degree + 1; i++)
			coef[i] -= p.coef[i];
	} else if (degree < p.degree) {
		double* auxiliar = new double[p.degree + 1];
		if (!auxiliar) {
			cerr << "Ocupo memoria!" << endl;
			exit(1);
		}
		for (int i = 0; i < p.degree + 1; i++)
			auxiliar[i] = p.coef[i];
		for (int i = 0; i < degree + 1; i++)
			auxiliar[i] -= coef[i];
		delete[] coef;
		coef = auxiliar;
		degree = p.degree;
	}
	return *this;
}
const Polynomial Polynomial::operator-()const{
	Polynomial poly(*this);
	for (int i = 0; poly.degree + 1; i++)
		poly.coef[i] *= -1;
	return poly;
}
const Polynomial Polynomial::operator*(const Polynomial& p){
	double* auxiliar = new double[degree + p.degree];
	for (int i = 0; i < degree + 1; i++)
		for (int j = 0; j < p.degree + 1; j++)
			auxiliar[i + j] += coef[i] * p.coef[j];
	Polynomial poly;
	delete[] poly.coef;
	poly.coef = auxiliar;
	return poly;
}
const Polynomial& Polynomial::operator*=(const Polynomial& p){
	double* auxiliar = new double[degree + p.degree + 1];
	if (!auxiliar){
		cerr << "Ocupo memoria" << endl;
		exit(1);
	}
	for (int i = 0; i < degree + 1; i++)
		for (int j = 0; j < p.degree + 1; j++)
			auxiliar[i+j] += coef[i] * p.coef[j];
	delete[] coef;
	coef = auxiliar;
	degree += p.degree;
	return *this;
}
const Polynomial Polynomial::operator/(const Polynomial&){

}
const Polynomial& Polynomial::operator/=(const Polynomial&){
	
}
bool Polynomial::operator==(const Polynomial& p)const{
	if (degree != p.degree)
		return false;
	for (int i = 0; i < degree + 1; i++)
		if(coef[i] != p.coef[i]){
			return false;
		}
	return true;
}
bool Polynomial::operator!=(const Polynomial& p)const{
	return !(*this == p);
}
double Polynomial::operator()(double value)const{
	double retval = 0;
	for (int i = 0; i < degree + 1; i++)
		retval += (coef[i] * pow(value, static_cast<double>(i)));
	return retval;
}
double Polynomial::operator()(double a, double b)const{
	Polynomial p(degree + 1);
	for (int i = degree; i >= 0; i--)
		p.coef[i + 1] = coef[i] / (i + 1);
	return p(b) - p(a);
}
const Polynomial Polynomial::operator()()const{
	Polynomial retVal(degree - 1);
	for (int i = degree; i > 0; i--){
		retVal.coef[i - 1] = coef[i] * i;
	}
	return retVal;
}
double& Polynomial::operator[](int index){
	if(degree + 1 < index){
		cerr << "El grado del polinomio no permite esta asignacion!" << endl;
	} else {
		//coef[index] = value;
	}
	return coef[index];
}
ostream& operator<<(ostream& output, const Polynomial& p){
	for (int i=p.degree; i >= 0; i--)
		output <<showpos << p.coef[i] << "X^" << i << " ";
	return output;
}
istream& operator>>(istream&, Polynomial&){

}
const Polynomial operator+(const Polynomial& l, const Polynomial& r){
	return Polynomial(l) += r;
}
const Polynomial operator-(const Polynomial& l, const Polynomial& r){
	return Polynomial(l) -= r;
}

const Polynomial operator*(const Polynomial& l, const Polynomial& r){
	return Polynomial(l) *= r;
}