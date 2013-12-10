#include "quad.h"
#include "rect.h"
#include "square.h"
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

void f(Quad&);
//void g(Quad q);
void h(Quad* q);

int main (int argc, char * argv[]) {
	// Quad qu(1, 1, 5, 2);
	// Rect r(2, 5);
	// Square s(4);

	// cout << endl
	// 	<< "*******toString()********" << endl;
	// cout << qu.toString() << endl
	// 	<< r.toString() << endl
	// 	<< s.toString() << endl;

	// cout << endl
	// 	<< "*******area()********" << endl;
	// cout << qu.area() << endl
	// 	<< r.area() << endl
	// 	<< s.area() << endl;

	// cout << endl
	// 	<< "*******perimeter()********" << endl;
	// cout << qu.perimeter() << endl
	// 	<< r.perimeter() << endl
	// 	<< s.perimeter() << endl;

	// cout << endl
	// 	<< "*******f()********" << endl;
	// f(qu);
	// f(r);
	// f(s);

	// cout << endl
	// 	<< "*******g()********" << endl;
	// g(qu);
	// g(r);
	// g(s);

	// cout << endl
	// 	<< "*******h()********" << endl;
	// h(&qu);
	// h(&r);
	// h(&s);

	// cout << endl
	// 	<< "*******Destructores********" << endl;

	//Rect m[5];
	Quad* q[4];
	q[0] = new Rect(1, 2);
	q[1] = new Square(4);
	q[2] = new Square(3);
	q[3] = new Rect(2, 4);
	for (int i = 0; i < 4; i++)
		cout << q[i]->toString() << endl;

	for (int i = 0; i < 4; i++)
		delete q[i];

	return 0;
}

void f(Quad& q) {
	cout << q.toString() << endl
		<< q.area() << endl
		<< q.perimeter() << endl;
}

//void g(Quad q) {
//	cout << q.toString() << endl
//		<< q.area() << endl
//		<< q.perimeter() << endl;
//}

void h(Quad* q) {
	cout << q->toString() << endl
		<< q->area() << endl
		<< q->perimeter() << endl;
}