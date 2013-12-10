#include "complex.h"

int main (int argc, char * argv[]) {
	complex a, b(2), c(-1, 7), d(4, -1), e(0, 1);
	a.print();
	b.print();
	c.print();
	d.print();
	e.print();
	c.assign(a.suma(b));
	c.print();
	c.assign(b.resta(c.suma(d)));
	a.print();
	b.print();
	c.print();
	d.print();
	return 0;
}