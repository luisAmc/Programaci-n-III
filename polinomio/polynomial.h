#pragma once
#include <iostream>
#include <fstream>
using std::ostream;
using std::istream;

class Polynomial{
	double* coef;
	int degree;
public:
	Polynomial(int = 0);
	Polynomial(const Polynomial&);
	~Polynomial();
	const Polynomial& operator=(const Polynomial&);
	const Polynomial operator+(const Polynomial&);
	const Polynomial& operator+=(const Polynomial&);
	const Polynomial operator-(const Polynomial&);
	const Polynomial& operator-=(const Polynomial&);
	const Polynomial operator-()const;
	const Polynomial operator*(const Polynomial&);
	const Polynomial& operator*=(const Polynomial&);
	const Polynomial operator/(const Polynomial&);
	const Polynomial& operator/=(const Polynomial&);
	bool operator==(const Polynomial&)const;
	bool operator!=(const Polynomial&)const;
	double operator()(double)const;
	double operator()(double, double)const;
	const Polynomial operator()()const;
	double& operator[](int);
	void setCoeficient(int, double);
	friend ostream& operator<<(ostream&, const Polynomial&);
	friend istream& operator>>(istream&, Polynomial&);
};

const Polynomial operator+(const Polynomial&, const Polynomial&);
const Polynomial operator-(const Polynomial&, const Polynomial&);
const Polynomial operator*(const Polynomial&, const Polynomial&);