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

void ControladorAire::atacar(ControladorPersonaje** ControladoresEnemigo){
    if(personaje->obtenerEnergia() >= ATAQUE_AIRE){
        personaje->restarEnergia(ATAQUE_AIRE);
        for(int i = 0; i < 3; i++){
            if(ControladoresEnemigo[i]->devolverPersonaje() != 0){
                (ControladoresEnemigo[i]->devolverPersonaje())->recibirAtaque("aire",0);
            }
        }
    }else{
        cout << "No posee suficiente energia para atacar." << endl;
    }
}

void ControladorAire::defensa() {
	bool seDefiende = personaje->defender();
	if (seDefiende) {
		int aux[2];
		for(int i = 0; i < 2; i++){ubicacion[i] = 0;}
		cout << "ingrese la ubicacion a donde desea moverse" << endl;
		cin >> aux[0] >> aux[1];
		ubicarPersonaje(aux);
	}
}

ControladorAire::ControladorAire(Personaje* personaje, Tablero* tablero) {
	this->personaje = personaje;
    this->tablero = tablero;
    for(int i = 0; i<2; i++){ubicacion[i] = 0;};
    ptrCasillero = 0;
}
