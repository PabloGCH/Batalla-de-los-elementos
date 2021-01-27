
#ifndef CASILLERO_H_
#define CASILLERO_H_
#include<iostream>
#include<string>
#include "character.h"
using namespace std;

const int MOUNTAIN = 1;
const int PRECIPICE = 2;
const int VOLCANO = 3;
const int LAKE = 4;
const int ROAD = 5;
const int VOID = 6;

class Casillero{
	protected:
		Casillero* up;
		Casillero* right;
		Casillero* down;
		Casillero* left;
		Character* character;
		int type;
	public:
		//PRE: recibe un puntero a un cacillero
		//POS: asigna ptr a up
		void setUp(Casillero* ptr);
		//PRE: recibe un puntero a un cacillero
		//POS: asigna ptr a right
		void setRight(Casillero* ptr);
		//PRE: recibe un puntero a un cacillero
		//POS: asigna ptr a down
		void setDown(Casillero* ptr);
		//PRE: recibe un puntero a un cacillero
		//POS: asigna ptr a left
		void setLeft(Casillero* ptr);
		//PRE: recibe un puntero a un personaje
		//POS: asigna ptr a character
		void setCharacter(Character* ptr);
		//POS: devuelve up
		Casillero* getUp();
		//POS: devuelve right
		Casillero* getRight();
		//POS: devuelve down
		Casillero* getDown();
		//POS: devuelve left
		Casillero* getLeft();
		//POS: devuelve character
		Character* getCharacter();
		//PRE: recibe el tipo de casillero el cual debe ser un
		// numero entero entre 1 y 6 inclusives
		//POS: Construye un objeto casillero
		Casillero(int type);
		//POS: imprime el caracter asociado al casillero
		void printCasillero();
};



#endif /* CASILLERO_H_ */
