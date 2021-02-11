#include "controladorAire.h"



int ControladorAire::evaluarDir(Casillero* dir){
    int valor = 0;
    int tipo = dir->getType();
    switch(tipo){
        case MOUNTAIN:
            valor = 2;
            break;
        case VOID:
            valor = 15;
            break;
        case ROAD:
            valor = 1;
            break;
        case PRECIPICE:
            valor = 0;
            break;
        case LAKE:
            valor = 1;
            break;
        case VOLCANO:
            valor = 1;
            break;
    }
    return valor; 
}

void ControladorAire::atacar(){
    
}

ControladorAire::ControladorAire(Personaje* personaje, Tablero* tablero) {
	this->personaje = personaje;
    this->tablero = tablero;
    for(int i = 0; i<2; i++){ubicacion[i] = 0;};
    ptrCasillero = 0;
}