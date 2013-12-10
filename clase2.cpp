#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char * argv[]){
	int magic, guess; bool won = false;
	srand (time(0));
	magic = rand() % 10 + 1;
	for (int t = 0; t < 3; t++){
		cout << "Su intento # " << (t + 1) << ":";
		cin >> guess;
		if (magic == guess){
			won = true;
			break;
		}
	}
	if (won){
		cout << "Gano!" << endl;
	} else {
		cout << "Perdio!" << endl;
	}
	return 0;
} 