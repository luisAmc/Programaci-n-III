#include <iostream>
#include <stdlib.h> 
using namespace std;

int main (int argc, char * argv[]) {
	int n, m;
	cin >> n >> m;
	int ** a = NULL;
	a = new int *[n];
	for (int i = 0; i < n; i++)
		a[i] = new int[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			a[i][j] = rand() % 6 + 1;
		}

	for (int i = 0; i < n; i++) 	 
		delete[] a[i];
	delete[] a;

	return 0;
}