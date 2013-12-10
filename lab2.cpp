#include <iostream>
using namespace std;

int TicTacToe ();
int Reversi ();
int GanoTicTacToe (int, int, char, char**);
int CambioColor (int, int, char, char**);
int ColocarPieza (int, int, char, char, char**) ;
void ComerPieza (int, int, char, char**) ;

int main(int argc, char * argv []){
	int opcion = 1;
	while(opcion != 0){
		cout << "\nDiamond Games\n" 
		<< "1.- Tic Tac Toe\n"
		<< "2.- Reversi\n"
		<< "3.- Salir\n"
		<< "Ingrese su opcion:" << endl;
		cin >> opcion;

		switch(opcion){
			case 1:
				TicTacToe();
			break;

			case 2:
				Reversi();
				break;

			case 3:
				opcion = 0;
				break;

			default:
				cout << "\nOpcion no soportada!\n" << endl;
				break;	
		}//Final del switch

	}//Final del while
}//Final del main

int TicTacToe(){
	//Construyo la matriz
	char**mat = new char*[3];
	for(int i = 0; i < 3; ++i)
		mat[i] = new char[3];
	
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			mat[i][j] = '-';
		}
	}

	bool continuar = true;
	int jugador = 1, fila, columna;

	while(continuar){
		if(jugador == 1){
			cout << "\nTurno del jugador 1\n"
			<< "Ingrese la fila (0 - 2) y la columna (0 - 2) (separadas de un espacio):" << endl;
			cin >> fila >> columna;

			while((fila > 2) || (columna > 2)){
				cout << "\nPosicion no soportada!\n"
				<< "Vuelva a ingresar la fila y la columna (separadas de un espacio):" << endl;
				cin >> fila >> columna;
			}

			while(mat[fila][columna] != '-'){
				cout << "\nPosicion ocupada!\n"
				<< "Vuelva a ingresar la fila y la columna (separadas de un espacio):" << endl;
				cin >> fila >> columna;
			}

			mat[fila][columna] = 'x';

			cout << endl;
			for(int i = 0; i < 3; ++i){
				for(int j = 0; j < 3; ++j){
					cout << "[" << mat[i][j] << "]";
				}
				cout << endl;
			}

			if(GanoTicTacToe(fila, columna, 'x', mat)){
				continuar = false;
				cout << "\nEl jugador 1 gano!" << endl;
			}

			jugador++;
		} else {
			cout << "\nTurno del jugador 2\n"
			<< "Ingrese la fila (0 - 2) y la columna (0 - 2) (separadas de un espacio):" << endl;
			cin >> fila >> columna;

			while((fila > 2) || (columna > 2)){
				cout << "\nPosicion no soportada!\n"
				<< "Vuelva a ingresar la fila y la columna (separadas de un espacio):" << endl;
				cin >> fila >> columna;
			}

			while(mat[fila][columna] != '-'){
				cout << "\nPosicion ocupada!\n"
				<< "Vuelva a ingresar la fila y la columna (separadas de un espacio):" << endl;
				cin >> fila >> columna;
			}

			mat[fila][columna] = '0';

			cout << endl;
			for(int i = 0; i < 3; ++i){
				for(int j = 0; j < 3; ++j){
					cout << "[" << mat[i][j] << "]";
				}
				cout << endl;
			}

			if(GanoTicTacToe(fila, columna, '0', mat)){
				continuar = false;
				cout << "\nEl jugador 2 gano!" << endl;
			}

			jugador--;
		}//Final del if de los jugadores
	}//Final while de x-o	

	for(int i = 0; i < 3; ++i)
		delete[] mat[i];
	delete[] mat;

}//Final del TicTacToe

int Reversi(){
	char**mat = new char*[8];
	for(int i = 0; i < 8; ++i)
		mat[i] = new char[8];

	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 8; ++j){
			mat[i][j] = '-';
		}
	}
	/*
	for(int i = 1; i < 9; ++i){
		mat[i][0] = i;
		mat[i][8] = i;
	}

	for(int i = 1; i < 9; ++i){
		mat[0][i] = i;
		mat[8][i] = i;
	}
	*/
	mat[3][3] = 'B';
	mat[3][4] = 'N';
	mat[4][3] = 'N';
	mat[4][4] = 'B';

	bool continuar = true;
	int jugador = 1, fila, columna, fichas, blancas, negras;

	while(continuar){
		if(jugador == 1){
			cout << "\nTurno del jugador 1\n"
			<< "Ingrese la fila (0 - 7) y la columna (0 - 7) (separadas de un espacio):" << endl;
			cin >> fila >> columna;

			while((fila > 7) || (columna > 7)){
				cout << "\nPosicion no soportada!\n"
				<< "Vuelva a ingresar la fila y la columna (separadas de un espacio):" << endl;
				cin >> fila >> columna;
			}

			while(mat[fila][columna] != '-'){
				cout << "\nPosicion ocupada!\n"
				<< "Vuelva a ingresar la fila y la columna (separadas de un espacio):" << endl;
				cin >> fila >> columna;
			}

			if(ColocarPieza(fila, columna, 'N', 'B', mat)){
				ComerPieza(fila, columna, 'N', mat);
				negras++;
				fichas++;
				jugador++;
			} else {
				cout << "\nPosicion Incorrecta!" << endl;
			}
			
			cout << endl;
			for(int i = 0; i < 8; ++i){
				for(int j = 0; j < 8; ++j){
					cout << "[" << mat[i][j] << "]";
				}
				cout << endl;
			}

		} else {
			cout << "\nTurno del jugador 2\n"
			<< "Ingrese la fila (0 - 7) y la columna (0 - 7) (separadas de un espacio):" << endl;
			cin >> fila >> columna;

			while((fila > 7) || (columna > 7)){
				cout << "\nPosicion no soportada!\n"
				<< "Vuelva a ingresar la fila y la columna (separadas de un espacio):" << endl;
				cin >> fila >> columna;
			}

			while(mat[fila][columna] != '-'){
				cout << "\nPosicion ocupada!\n"
				<< "Vuelva a ingresar la fila y la columna (separadas de un espacio):" << endl;
				cin >> fila >> columna;
			}

			if(ColocarPieza(fila, columna, 'B', 'N', mat)){
				ComerPieza(fila, columna, 'B', mat);
				blancas++;
				fichas++;
				jugador--;
			} else {
				cout << "\nPosicion incorrecta!" << endl;
			}
			
			cout << endl;
			for(int i = 0; i < 8; ++i){
				for(int j = 0; j < 8; ++j){
					cout << "[" << mat[i][j] << "]";
				}
				cout << endl;
			}

		}

		if(fichas == 64){
			if(negras > blancas){
				continuar = false;
				cout << "\nGano el jugador 1!" << endl;
			} else if (blancas > negras){
				continuar = false;
				cout << "\nGano el jugador 2!" << endl;
			} else {
				continuar = false;
				cout << "\nHubo un empate!" << endl;
			}
		}

	}//Final del while de Reversi

	for(int i = 0; i < 8; ++i)
		delete[] mat[i];
	delete[] mat;

}//Final del Reversi

int GanoTicTacToe (int fila, int columna, char jugador, char** mat) {
	int gano = 0;	
	if(mat[fila][0] == jugador){
		if(mat[fila][1] == jugador){
			if(mat[fila][2] == jugador){
				gano++;
			}
		}
	}	

	if(mat[0][columna] == jugador){
		if(mat[1][columna] == jugador){
			if(mat[2][columna] == jugador){
				gano++;
			}
		}
	}	

	if(mat[0][0] == jugador){
		if(mat[1][1] == jugador){
			if(mat[2][2] == jugador){
				gano++;
			}
		}
	}

	if(mat[2][0] == jugador){
		if(mat[1][1] == jugador){
			if(mat[0][2] == jugador){
				gano++;
			}
		}
	}

	return gano;
}//Final del GanoTicTacToe

int CambioColor (int fila, int columna, char jugador, char** mat) {
}//Final del CambioColor

int ColocarPieza (int fila, int columna, char j1, char j2, char** mat) {
	int temp = 0;
	if((fila == 0) && (columna == 0)){
		if(mat[fila + 1][columna + 1] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(mat[fila][columna + 1] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(mat[fila + 1][columna] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(temp != 0)
			return 1;
		else 
			return 0;

	}
	if((fila == 0) && (columna == 7)){
		if(mat[fila + 1][columna] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(mat[fila][columna - 1] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(mat[fila + 1][columna - 1] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(temp != 0)
			return 1;
		else 
			return 0;
	}
	if((fila == 7) && (columna == 0)){
		if(mat[fila - 1][columna + 1] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(mat[fila][columna + 1] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(mat[fila - 1][columna] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(temp != 0)
			return 1;
		else 
			return 0;
	}
	if((fila == 7) && (columna == 7)){
		if(mat[fila - 1][columna - 1] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(mat[fila][columna - 1] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(mat[fila - 1][columna] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(temp != 0)
			return 1;
		else 
			return 0;
	}

	if(fila == 7){
		if(mat[fila - 1][columna] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(mat[fila][columna + 1] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(mat[fila][columna - 1] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(temp != 0)
			return 1;
		else 
			return 0;
	}
	if(fila == 0){
		if(mat[fila + 1][columna] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(mat[fila][columna + 1] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(mat[fila][columna - 1] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(temp != 0)
			return 1;
		else 
			return 0;
	}
	if(columna == 7){
		if(mat[fila][columna - 1] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(mat[fila + 1][columna] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(mat[fila - 1][columna] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(temp != 0)
			return 1;
		else 
			return 0;
	}
	if(columna == 0){
		if(mat[fila][columna + 1] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(mat[fila + 1][columna] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(mat[fila - 1][columna] == j2){
			mat[fila][columna] = j1;
			temp++;
		}
		if(temp != 0)
			return 1;
		else 
			return 0;
	}

	if(mat[fila][columna - 1] == j2){
		mat[fila][columna] = j1;
		return 1;
	}
	if(mat[fila][columna + 1] == j2){
		mat[fila][columna] = j1;
		return 1;
	}
	if(mat[fila - 1][columna] == j2){
		mat[fila][columna] = j1;
		return 1;
	}
	if(mat[fila + 1][columna] == j1){
		mat[fila][columna] = j1;
		return 1;
	}

	return 0;
}//Final del ColocarPieza

void ComerPieza (int fila, int columna, char j1, char** mat) {
	int ftemp = 0;
	int ctemp = 0;
	//////////////////////////////////////////////////////////////////////////////////////////////
	//Diagonal izquierda - derecha decreciente
	for(int f = 0; f <= fila; ++f){
		for(int c = 0; c <= columna; ++c){
			if(mat[f][c] == j1){
				ftemp = f;
				ctemp = c;
				for(int l = ftemp; l < fila; ++l){
					for(int n = ctemp; c < columna; ++c){
						mat[l][n] = j1;
					}
				}
			}//Final del if
		}//Final del for interno
	}//Final del for externo
	for(int f = fila; f < 8; ++f){
		for(int c = columna; c < 8; ++c){
			if(mat[f][c] == j1){
				ftemp = f;
				ctemp = c;
				for(int l = fila; l < ftemp; ++l){
					for(int n = columna; n < ctemp; ++n){
						mat[l][n] = j1;
					}
				}
			}//Final del if
		}//Final del for interno
	}//Final del for externo
	////////////////////////////////////////////////////////////////////////////////////////////////
	//Diagonal izquierda - derecha ascendiente
	for(int f = fila; f < 8; ++f){
		for(int c = columna; c < 8; ++c){
			if(mat[f][c] == j1){
				ftemp = f;
				ctemp = c;
				for(int l = ftemp; l < fila; ++l){
					for(int n = ctemp; n < columna; ++n){
						mat[l][n] = j1;
					}
				}
			}//Final del if
		}//Final del for interno
	}//Final del for externo
	for(int f = 7; f >= fila; --f){
		for(int c = 0; c <= columna; ++c){
			if(mat[f][c] == j1){
				ftemp = f;
				ctemp = c;
				for(int l = fila; l <= ftemp; ++l){
					for(int n = columna; n <= ctemp; ++n){
						mat[l][n] = j1;
					}
				}
			}//Final del if
		}//Final del for interno
	}//Final del for externo
	/////////////////////////////////////////////////////////////////////////////////////////////////
	//Horizontal
	for(int c = 0; c <= columna; ++c){
		if(mat[fila][c] == j1){
			ctemp = c;
			for(int n = ctemp; n <= columna; ++n){
				mat[fila][n] = j1;
			}
		}
	}
	for(int c = columna; c < 8; ++c){
		if(mat[fila][c] == j1){
			ctemp = c;
			for(int n = columna; n < ctemp; ++n){
				mat[fila][ctemp] = j1;
			}
		}
	}
	////////////////////////////////////////////////////////////////////////////////////////////////
	//Vertical
	for(int f = 0; f <= fila; ++f){
		if(mat[f][columna] == j1){
			ftemp = f;
			for(int l = ftemp; l <= fila; ++l){
				mat[l][columna] = j1;
			}
		}
	}
	for(int f = fila; f < 8; ++f){
		if(mat[f][columna] == j1){
			ftemp = f;
			for(int l = fila; l < ftemp; ++l){
				mat[l][columna] = j1;
			}
		}
	}
}//Final de ComerPieza