#include "controladorTierra.h"



int ControladorTierra::evaluarDir(Casillero* dir){
    int valor = 0;
    int tipo = dir->getType();
    switch(tipo){
        case MOUNTAIN:
            valor = 0;
            break;
        case VOID:
            valor = 15;
            break;
        case ROAD:
            valor = 1;
            break;
        case PRECIPICE:
            valor = 2;
            break;
        case LAKE:
            valor = 1;
            break;
        case VOLCANO:
            valor = 0;
            break;
    }
    return valor; 
}

void ControladorTierra::atacar(){
    
}

ControladorTierra::ControladorTierra(Personaje* personaje, Tablero* tablero) {
	this->personaje = personaje;
    this->tablero = tablero;
    for(int i = 0; i<2; i++){ubicacion[i] = 0;};
    ptrCasillero = 0;
}