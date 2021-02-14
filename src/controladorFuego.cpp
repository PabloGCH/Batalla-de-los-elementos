#include "controladorFuego.h"



int ControladorFuego::evaluarDir(Casillero* dir){
    int valor = 0;
    int tipo = dir->getType();
    switch(tipo){
        case MOUNTAIN:
            valor = 1;
            break;
        case VOID:
            valor = 15;
            break;
        case ROAD:
            valor = 1;
            break;
        case PRECIPICE:
            valor = 1;
            break;
        case LAKE:
            valor = 2;
            break;
        case VOLCANO:
            valor = 0;
            break;
    }
    return valor; 
}

void ControladorFuego::atacar(){
    if(personaje->obtenerEnergia() >= 5){
        personaje->restarEnergia(5);
        for(int i = (ubicacion[0]-1); i < (ubicacion[0]-1)+3; i++){
            for(int j = 1; j <= NUM_COLUMNAS; j++){
                int auxCoord[2] = {i,j};
                Personaje* enemigo = tablero->returnItem(auxCoord)->getCharacter();
                if(enemigo)
                    enemigo->recibirAtaque("fuego", 0);
            }
        }
    }
}

ControladorFuego::ControladorFuego(Personaje* personaje, Tablero* tablero) {
	this->personaje = personaje;
    this->tablero = tablero;
    for(int i = 0; i<2; i++){ubicacion[i] = 0;};
    ptrCasillero = 0;
}