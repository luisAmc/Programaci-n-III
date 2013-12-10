#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

void imprimirTablero (string**, int);
void inicializarTablero (string**, int);
string movida ();
string split (string, int);
int identificarPieza (string**, string, int);
int moverPeon (int, int, int, int, string**, int);
int moverTorre (int, int, int, int, string**);
int moverAlfil (int, int, int, int, string**);
int moverCaballo (int, int, int, int);
int moverReina (int, int, int, int, string**);
int moverRey (int, int, int, int);
int sePuedeMover (int, int, int, int, int, string**);
int filanumero (string);
int columnanumero (string);
int cualPieza (int, int, string**);
void moverPieza (int, int, int, int, string**); 
int jaque(int, string**);

int main (int argc, char * argv []) {
	int continuar = 1, jugador = 1, turno = 0, movimientoInvalido;

	//Creo el tablero
	string ** tablero = new string * [8];
	for (int i = 0; i < 8; i++)
		tablero[i] = new string [8]; 
	inicializarTablero(tablero, 8);

	imprimirTablero(tablero, 8);

	string j1;
	string j2;
	cout << "\nCual es el nombre del primer jugador?" << endl;
	getline(cin, j1);
	cout << "\nCual es el nombre del segundo jugador?" << endl;
	getline(cin, j2);

	while (continuar) {
		if (jugador == 1) {//Inicio de la jugada del j1
			movimientoInvalido = 1;
			do {
				cout << "\nEs su turno " << j1 << ", recuerda que las piezas blancas son tuyas!" << endl;
				string m1 = movida();

				while (m1.length() != 5) {
					cout << "\nMovimiento no soportado!" << endl;
					m1 = movida();
				}//Final del while validador del tamano del movimiento

				int filai = filanumero(split(m1, 1));
				int columnai = columnanumero(split(m1, 1));
				int filaf = filanumero(split(m1, 2));
				int columnaf = columnanumero(split(m1, 2));

				//Verifico si la casilla inicial contiene una pieza del jugador
				while (tablero[filai][columnai].substr(1, 2).compare("B") != 0) {
					cout << "\nLa casilla inicial no le pertenece!" << endl;
					m1 = movida();
					while (m1.length() != 5) {
						cout << "\nMovimiento no soportado!" << endl;
						m1 = movida();
					}

					filai = filanumero(split(m1, 1));
					columnai = columnanumero(split(m1, 1));
					filaf = filanumero(split(m1, 2));
					columnaf = columnanumero(split(m1, 2));
				}//Final del while que verifica la casilla incial 


				//Miro si las filas o las columnas ingresadas se salen de los limites
				if ((filai >= 0 && filai <= 7) && (columnai >= 0 && columnai <= 7) && 
					(filaf >= 0 && filaf <= 7) && (columnaf >= 0 && columnaf <= 7)) {
					if (sePuedeMover(filai, columnai, filaf, columnaf, jugador, tablero)) {
						if (cualPieza(filai, columnai, tablero) == 1) {//Peon
							if (moverPeon(filai, columnai, filaf, columnaf, tablero, jugador)) {
								moverPieza(filai, columnai, filaf, columnaf, tablero);
							} else {
								movimientoInvalido = 1;
							}
						} else if (cualPieza(filai, columnai, tablero) == 2) {//Torre
							if (moverTorre(filai, columnai, filaf, columnaf, tablero)) {
								moverPieza(filai, columnai, filaf, columnaf, tablero);
							} else {
								movimientoInvalido = 1;
							}
						} else if (cualPieza(filai, columnai, tablero) == 3) {//Caballo
							if (moverCaballo(filai, columnai, filaf, columnaf)) {
								moverPieza(filai, columnai,filaf, columnaf, tablero);
							} else {
								movimientoInvalido = 1;
							}
						} else if (cualPieza(filai, columnai, tablero) == 4) {//Alfil
							if (moverAlfil(filai, columnai, filaf, columnaf, tablero)) {
								moverPieza(filai, columnai, filaf, columnaf, tablero);
							} else {
								movimientoInvalido = 1;
							}
						} else if (cualPieza(filai, columnai, tablero) == 5) {//Dama
							if (moverReina(filai, columnai, filaf, columnaf, tablero)) {
								moverPieza(filai, columnai, filaf, columnaf, tablero);
							} else {
								movimientoInvalido = 1;
							}
						} else if (cualPieza(filai, columnai, tablero) == 6) {//Rey
							if (moverRey(filai, columnai, filaf, columnaf)) {
								moverPieza(filai, columnai, filaf, columnaf, tablero);
							} else {
								movimientoInvalido = 1;
							} 
						}//Final del realizar los movimientos
					}//Final del if por si se puede mover
					movimientoInvalido = 0;
				} else {
					movimientoInvalido = 1;
				}//Final del if mostruo 

				//if (jaque(jugador, tablero)) {
				//	movimientoInvalido = 1;
				//}

			} while (movimientoInvalido);
			imprimirTablero(tablero, 8);
			jugador++;
		} else {//Inicio de la jugada de j2
			movimientoInvalido = 1;
			do {
				cout << "\nEs su turno " << j2 << ", recuerda que las piezas negras son tuyas!" << endl;
				string m1 = movida();

				while (m1.length() != 5) {
					cout << "\nMovimiento no soportado!" << endl;
					m1 = movida();
				}//Final del while validador del tamano del movimiento

				int filai = filanumero(split(m1, 1));
				int columnai = columnanumero(split(m1, 1));
				int filaf = filanumero(split(m1, 2));
				int columnaf = columnanumero(split(m1, 2));

				//Verifico si la casilla inicial contiene una pieza del jugador
				while (tablero[filai][columnai].substr(1, 2).compare("N") != 0) {
					cout << "\nLa casilla inicial no le pertenece!" << endl;
					m1 = movida();
					while (m1.length() != 5) {
						cout << "\nMovimiento no soportado!" << endl;
						m1 = movida();
					}

					filai = filanumero(split(m1, 1));
					columnai = columnanumero(split(m1, 1));
					filaf = filanumero(split(m1, 2));
					columnaf = columnanumero(split(m1, 2));
				}//Final del while que verifica la casilla incial 


				//Miro si las filas o las columnas ingresadas se salen de los limites
				if ((filai >= 0 && filai <= 7) && (columnai >= 0 && columnai <= 7) && 
					(filaf >= 0 && filaf <= 7) && (columnaf >= 0 && columnaf <= 7)) {
					if (sePuedeMover(filai, columnai, filaf, columnaf, jugador, tablero)) {
						if (cualPieza(filai, columnai, tablero) == 1) {//Peon
							if (moverPeon(filai, columnai, filaf, columnaf, tablero, jugador)) {
								moverPieza(filai, columnai, filaf, columnaf, tablero);
							} else {
								movimientoInvalido = 1;
							}
						} else if (cualPieza(filai, columnai, tablero) == 2) {//Torre
							if (moverTorre(filai, columnai, filaf, columnaf, tablero)) {
								moverPieza(filai, columnai, filaf, columnaf, tablero);
							} else {
								movimientoInvalido = 1;
							}
						} else if (cualPieza(filai, columnai, tablero) == 3) {//Caballo
							if (moverCaballo(filai, columnai, filaf, columnaf)) {
								moverPieza(filai, columnai,filaf, columnaf, tablero);
							} else {
								movimientoInvalido = 1;
							}
						} else if (cualPieza(filai, columnai, tablero) == 4) {//Alfil
							if (moverAlfil(filai, columnai, filaf, columnaf, tablero)) {
								moverPieza(filai, columnai, filaf, columnaf, tablero);
							} else {
								movimientoInvalido = 1;
							}
						} else if (cualPieza(filai, columnai, tablero) == 5) {//Dama
							if (moverReina(filai, columnai, filaf, columnaf, tablero)) {
								moverPieza(filai, columnai, filaf, columnaf, tablero);
							} else {
								movimientoInvalido = 1;
							}
						} else if (cualPieza(filai, columnai, tablero) == 6) {//Rey
							if (moverRey(filai, columnai, filaf, columnaf)) {
								moverPieza(filai, columnai, filaf, columnaf, tablero);
							} else {
								movimientoInvalido = 1;
							} 
						}//Final del realizar los movimientos
					}//Final del if por si se puede mover
					movimientoInvalido = 0;
				} else {
					movimientoInvalido = 1;
				}//Final del if mostruo 

				//if (jaque(jugador, tablero)) {
				//	movimientoInvalido = 1;
				//}

			} while (movimientoInvalido);
			imprimirTablero(tablero, 8);
			jugador--;
		}//Final del if de control de los turnos de los jugadores
	}//Final del while general

	//Elimino el tablero
	for (int i = 0; i < 8; i++)
		delete[] tablero[i];
	delete[] tablero;
}//Final del main

void imprimirTablero (string ** tablero, int t) {
	cout << endl;
	for (int i = 0; i < t; i++){
		cout << setw(4);
		switch (i) {
			case 0: cout << "A"; break;
			case 1: cout << "B"; break;
			case 2: cout << "C"; break;
			case 3: cout << "D"; break;
			case 4: cout << "E"; break;
			case 5: cout << "F"; break;
			case 6: cout << "G"; break;
			case 7: cout << "H"; break;
		}//Final de la impresion del nombre de la fila 
	}

	cout << endl;
	for (int i = 0; i < t; i++){
		 switch (i) {
			case 0: cout << "0"; break;
			case 1: cout << "1"; break;
			case 2: cout << "2"; break;
			case 3: cout << "3"; break;
			case 4: cout << "4"; break;
			case 5: cout << "5"; break;
			case 6: cout << "6"; break;
			case 7: cout << "7"; break;
		}//Final de la impresion del nombre de la fila 
		for (int j = 0; j < t; j++)
			cout << setw(1) << "[" << tablero[i][j] << "]";
		cout << endl;
	}//Final del for externo
}//Final de la funcion imprimirTablero

void inicializarTablero (string ** tablero, int t) {
	//Dejando pinta el tablero
	for (int i = 0; i < t; i++)
		for (int j = 0; j < t; j++)
			tablero[i][j] = "  ";

	for (int i = 0; i < t; i++)
		for (int j = 0; j < t; j++){
			//Colocando piezas negras
			if (((i == 0) && (j == 0)) || ((i == 0) && (j == 7))) {
				tablero[i][j] = "TN";
			} else if (((i == 0) && (j == 1)) || ((i == 0) && (j == 6))) {
				tablero[i][j] = "CN";
			} else if (((i == 0) && (j == 2)) || ((i == 0) && (j == 5))) {
				tablero[i][j] = "AN";
			} else if ((i == 0) && (j == 3)) {
				tablero[i][j] = "DN";
			} else if ((i == 0) && (j == 4)) {
				tablero[i][j] = "RN";
			} else if ((i == 1) && ((j == 0)||(j == 1)||(j == 2)||(j == 3)||(j == 4)||(j == 5)||(j == 6)||(j == 7))) {
				tablero[i][j] = "PN";
			}//Final de los ifs anidados que colocan las piezas negras

			//Colocando piezas blancas
			if (((i == 7) && (j == 0)) || ((i == 7) && (j == 7))) {
				tablero[i][j] = "TB";
			} else if (((i == 7) && (j == 1)) || ((i == 7) && (j == 6))) {
				tablero[i][j] = "CB";
			} else if (((i == 7) && (j == 2)) || ((i == 7) && (j == 5))) {
				tablero[i][j] = "AB";
			} else if ((i == 7) && (j == 3)) {
				tablero[i][j] = "DB";
			} else if ((i == 7) && (j == 4)) {
				tablero[i][j] = "RB";
			} else if ((i == 6) && ((j == 0)||(j == 1)||(j == 2)||(j == 3)||(j == 4)||(j == 5)||(j == 6)||(j == 7))) {
				tablero[i][j] = "PB";
			}//Final de los ifs anidados que colocan las piezas blancas
		}//Final del for interno
}

string movida () {
	cout << endl;
	string movimiento;
	cout << "Ingrese su jugada de la forma filaInicial_columnaInicial-filaFinal_columnaFinal"
	<< "\nEjemplo: 1a-2a" << endl;
	getline(cin, movimiento);
	return movimiento;
}

string split (string movimiento, int casilla) {
	int guionIndex = movimiento.find('-');
	if (casilla == 1) {
		string part1 = movimiento.substr (0, guionIndex);
		return part1;
	} else {
		string part2 = movimiento.substr (guionIndex + 1, movimiento.length());
		return part2;
	}
}

int moverPeon (int filai, int columnai, int filaf, int columnaf, string **tablero, int jugador) {
	if (tablero[filaf][columnaf].compare("  ") == 0) {//Verifica si la casilla objetivo esta vacia
		if (columnai == columnaf) {
			if (jugador == 1) {
				if (filai == filaf + 1) {
					return 1;
				}
			} else if (jugador == 2) {
				if (filai == filaf - 1) {
					return 1;
				}
			}
		}
	} else {//La casilla objetivo tiene una pieza
		if ((columnai == columnaf + 1) || (columnai == columnaf - 1)) {
			if (jugador == 1) {
				if (filai == filaf + 1) {
					return 1;
				}
			} else if (jugador == 2) {
				if (filai == filaf - 1) {
					return 1;
				} 	
			}
		}
	}
	return 0;
}

int moverCaballo (int filai, int columnai, int filaf, int columnaf) {
	if (((columnai == columnaf + 1) || (columnai == columnaf - 1)) && ((filai == filaf + 2) || (filai == filaf - 2))) {
		return 1;
	} else if (((columnai == columnaf + 2) || (columnai == columnaf - 2)) && ((filai == filaf + 1) || (filai == filaf - 2))) {
		return 1;
	}
	return 0;
}

int moverAlfil (int filai, int columnai, int filaf, int columnaf, string **tablero) {
	if ((columnaf - columnai == filaf - filai) || (columnaf - columnai == filai - filaf)) {//Compruebo si se mueve en diagonal
		
		int fauxiliar = ((filaf - filai > 0) ? 1 : -1); 
		int cauxiliar = ((columnaf - columnai > 0) ? 1 : -1);

		for (int i = filai + fauxiliar; i != filaf; i += (fauxiliar)) {
			for (int j = columnai + cauxiliar; j != columnaf; j += (cauxiliar)) {
				if (tablero[i][j].compare("  ") != 0) {
					return 0;
				}
			}
		}

		return 1;
	}
	return 0;
}

int moverTorre (int filai, int columnai, int filaf, int columnaf, string **tablero) {
	if (filai == filaf) {//Se mueve horizontalmente
		int cauxiliar = ((columnaf - columnai > 0) ? 1 : -1);
		for (int i = columnai + cauxiliar; i != columnaf; i += cauxiliar) {
			if (tablero[filai][i].compare("  ") != 0) {
				return 0;
			}
		}
		return 1;
	} else if (columnai == columnaf) {//Se mueve verticalmente
		int fauxiliar = ((filaf - filai > 0) ? 1 : -1);
		for (int i = filai + fauxiliar; i != filaf; i += fauxiliar) {
			if (tablero[i][columnai].compare("  ") != 0) {
				return 0;
			}
		}
		return 1;
	} 
	return 0;
}

int moverReina (int filai, int columnai, int filaf, int columnaf, string **tablero) {
	if (filai == filaf) {
		int cauxiliar = ((columnaf - columnai > 0) ? 1 : -1);
		for (int i = columnai + cauxiliar; i != columnaf; i += cauxiliar) {
			if (tablero[filai][i].compare("  ") != 0) {
				return 0;
			}
		}
		return 1;
	} else if (columnai == columnaf) {
		int fauxiliar = ((filaf - filai > 0) ? 1 : -1);
		for (int i = filai + fauxiliar; i != filaf; i += fauxiliar) {
			if (tablero[i][columnai].compare("  ") != 0) {
				return 0;
			}
		}
		return 1;
	} else if (((columnaf - columnai) == (filaf - filai)) || ((columnaf - columnai) == (filai - filaf))) {
		int fauxiliar = ((filaf - filai > 0) ? 1 : -1);
		int cauxiliar = ((columnaf - columnai > 0) ? 1 : -1);
		for (int i = filai + fauxiliar; i != filaf; i += fauxiliar) {
			for (int j = columnai += cauxiliar; j != columnaf; j += cauxiliar) {
				if (tablero[i][j].compare("  ") != 0) {
					return 0;
				}
			}
		}
		return 1;
	}
	return 0;
} 

int moverRey (int filai, int columnai, int filaf, int columnaf) {
	int diferenciafilas = filaf - filai;
	int diferenciacolumnas = columnaf - columnai;
	if ((diferenciafilas >= -1) && (diferenciafilas <= 1) && (diferenciacolumnas >= -1) && (diferenciacolumnas <= 1)) {
		return 1;
	}
	return 0;
}

int sePuedeMover (int filai, int columnai, int filaf, int columnaf, int jugador, string **tablero) {
	if (jugador == 1) {
		if ((tablero[filaf][columnaf].compare("  ") == 0) || (tablero[filaf][columnaf].substr(1, 2).compare("N") == 0)) {
			return 1;
		}
	} else if (jugador == 2) {
		if ((tablero[filaf][columnaf].compare("  ") == 0) || (tablero[filaf][columnaf].substr(1, 2).compare("B") == 0)) {
			return 1; 
		}
	}
	return 0;
}

int columnanumero (string c) {
	int columna;
	if (c.substr(1,2) == "a") {
		columna = 0;
	} else if (c.substr(1,2) == "b") {
		columna = 1;
	} else if (c.substr(1,2) == "c") {
		columna = 2;
	} else if (c.substr(1,2) == "d") {
		columna = 3;
	} else if (c.substr(1,2) == "e") {
		columna = 4;
	} else if (c.substr(1,2) == "f") {
		columna = 5;
	} else if (c.substr(1,2) == "g") {
		columna = 6;
	} else if (c.substr(1,2) == "h") {
		columna = 7;
	} else if (c.substr(1,2) == "i") {
		columna = 8;
	} else if (c.substr(1,2) == "j") {
		columna = 9;
	}
	return columna;
}	

int filanumero (string c) {
	int fila = atoi((c.substr(0, 1)).c_str());
	return fila;
}

int cualPieza (int fila, int columna, string **tablero) {
	if (tablero[fila][columna].substr(0, 1).compare("P") == 0) {
		return 1;
	} else if (tablero[fila][columna].substr(0, 1).compare("T") == 0) {
		return 2;
	} else if (tablero[fila][columna].substr(0, 1).compare("C") == 0) {
		return 3;
	} else if (tablero[fila][columna].substr(0, 1).compare("A") == 0) {
		return 4;
	} else if (tablero[fila][columna].substr(0, 1).compare("D") == 0) {
		return 5;
	} else if (tablero[fila][columna].substr(0, 1).compare("R") == 0) {
		return 6;
	}
	return 0;
}

void moverPieza (int filai, int columnai, int filaf, int columnaf, string  **tablero) {
	string pieza = tablero[filai][columnai];
	tablero[filai][columnai] = "  ";
	tablero[filaf][columnaf] = pieza;
}

int jaque (int jugador, string**tablero) {
	if (jugador == 1) {
		int fila;
		int columna;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (tablero[i][j].compare("  ") != 0) {
					if (tablero[i][j].compare("KB") == 0) {
						fila = i;
						columna = j;
					}
				}
			}
		}

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (tablero[i][j].compare("  ") != 0) {
					if (cualPieza(i, j, tablero) == 1) {
						if (moverPeon(i, j, fila, columna, tablero, jugador)) {//Peon
							return 1;
						} else if (cualPieza(i, j, tablero) == 2) {//Torre
							if (moverTorre(i, j, fila, columna, tablero)) {
								return 1;
							}
						} else if (cualPieza(i, j, tablero) == 3) {//Caballo
							if (moverCaballo(i, j, fila, columna)) {
								return 1;
							}
						} else if (cualPieza(i, j, tablero) == 4) {//Alfil
							if (moverAlfil(i, j, fila, columna, tablero)) {
								return 1;
							}
						} else if (cualPieza(i, j, tablero) == 5) {//Dama
							if (moverReina(i, j, fila, columna, tablero)) {
								return 1;
							}	
						} else if (cualPieza(i, j, tablero) == 6) {//Rey
							if (moverRey(i, j, fila, columna)) {
								return 1;
							}
						}//Final del realizar los movimientos                                                                                                                                                                                                                                                                                                                                                                                   
					}
				}
			}
		}
		return 0;
	} else if (jugador == 2) {
		int fila;
		int columna;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (tablero[i][j].compare("  ") != 0) {
					if (tablero[i][j].compare("KN") == 0) {
						fila = i;
						columna = j;
					}
				}
			}
		}

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (tablero[i][j].compare("  ") != 0) {
					if (cualPieza(i, j, tablero) == 1) {
							if (moverPeon(i, j, fila, columna, tablero, jugador)) {//Peon
								return 1;
						} else if (cualPieza(i, j, tablero) == 2) {//Torre
							if (moverTorre(i, j, fila, columna, tablero)) {
								return 1;
							}
						} else if (cualPieza(i, j, tablero) == 3) {//Caballo
							if (moverCaballo(i, j, fila, columna)) {
								return 1;
							}
						} else if (cualPieza(i, j, tablero) == 4) {//Alfil
							if (moverAlfil(i, j, fila, columna, tablero)) {
								return 1;
							}
						} else if (cualPieza(i, j, tablero) == 5) {//Dama
							if (moverReina(i, j, fila, columna, tablero)) {
								return 1;
							}	
						} else if (cualPieza(i, j, tablero) == 6) {//Rey
							if (moverRey(i, j, fila, columna)) {
								return 1;
							}
						}//Final del realizar los movimientos                                                                                                                                                                                                                                                                                                                                                                                   
					}
				}
			}
		}
		return 0;
	}
}