#include "controladorAgua.h"



int ControladorAgua::evaluarDir(Casillero* dir){
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
            valor = 0;
            break;
        case VOLCANO:
            valor = 2;
            break;
    }
    return valor; 
}

void ControladorAgua::atacar(){
    
}