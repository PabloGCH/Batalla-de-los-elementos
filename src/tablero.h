

#ifndef TABLERO_H_
#define TABLERO_H_
#include <fstream>

#include "casillero.h"
using namespace std;

const char* const FILE_PATH = "res/mapa.txt";
const int NUM_FILAS = 8;
const int NUM_COLUMNAS = 8;

class Tablero{
	private:
		Casillero* first;
	public:
		//PRE: recibe un archivo donde se
		// especifica el tipo de cada cacillero
		//POS: crea una fila de nodos
		Casillero* createRow(ifstream &map);
		//PRE: recibe dos filas
		//POS: une las dos filas, la primera es la que esta arriba
		// y la segunda es la que esta abajo
		void linkRows(Casillero* firstPtr, Casillero* lastPtr);
		//POS: Imprime todo el tablero
		void printBoard();
		//PRE: recibe un archivo donde se
		// especifica el tipo de cada cacillero
		//POS: crea los cacilleros del tablero
		void fillBoard(ifstream &map);
		Tablero();
		~Tablero();
};



#endif /* TABLERO_H_ */
