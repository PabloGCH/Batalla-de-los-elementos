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

void ControladorTierra::atacar(ControladorPersonaje* personajeVictima){
    if (personaje -> obtenerEnergia() >= 6 ) {
        personaje->restarEnergia(6);
        int distanciaFila = ubicacion[0] - personajeVictima -> devolverUbicacion()[0];
        int distanciaColumna = ubicacion[1] - personajeVictima -> devolverUbicacion()[1];
        if (distanciaFila <= 2 && distanciaColumna <= 2){
            personajeVictima -> devolverPersonaje() -> recibirAtaque( "tierra", 1);
        }
        else if (2 <= distanciaFila <= 4 && 2 <= distanciaColumna <= 4){
            personajeVictima -> devolverPersonaje() -> recibirAtaque( "tierra", 2);
        }
        else{
            personajeVictima -> devolverPersonaje() -> recibirAtaque( "tierra", 3);
        }
    }
    else{
        cout << "El personaje " << personaje -> obtenerNombre() << " no cuenta con la energía necesaria para atacar" << endl;
    }
    
}

ControladorTierra::ControladorTierra(Personaje* personaje, Tablero* tablero) {
	this->personaje = personaje;
    this->tablero = tablero;
    for(int i = 0; i<2; i++){ubicacion[i] = 0;};
    ptrCasillero = 0;
}