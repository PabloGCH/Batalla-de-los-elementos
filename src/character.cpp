#include "character.h"
using namespace std;


Character::Character(){
	shield = rand () % 3;
	life = rand () % 91 + 10;
	energy = rand () % 21;
}

Character::~Character(){
}

string Character::getName(){
	return name;
}

int Character::getEnergy(){
	return energy;
}

int Character::getLife(){
	return life;
}

int Character::getShield(){
	return shield;
}

void Character::setEnergy(int newEnergy){
	energy = newEnergy;
}

void Character::setLife(int newLife){
	life = newLife;
}

void Character::setShield(int newShield){
	shield = newShield;
}

void Character::setName(string newName){
	name = newName;
}



