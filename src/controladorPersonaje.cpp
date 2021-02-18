#include "controladorPersonaje.h"

ControladorPersonaje::ControladorPersonaje(){
    personaje = 0;
    ptrCasillero = 0;
    tablero = 0;
    esta_defendiendo = false;
}

void ControladorPersonaje::encontrarCaminos(){
    Casillero* current = ptrCasillero;
    bool visto[64];
    int currentID = coordToId(ubicacion);
    int currentCoord[2] = {0,0};
    int cantVistos = 0;
    for(int i = 0; i < 64; i++){
        costo[i] = 1000;
        visto[i] = false;
    }
    //inicializo
    anterior[currentID] = currentID;
    costo[currentID] = 0;
    visto[currentID] = true;
    evaluarNodos(currentID, visto, current);
    cantVistos++;
    while(cantVistos < 64){
        currentID = buscarMinimo(visto);
        idToCoord(currentID, currentCoord);
        current = tablero->returnItem(currentCoord);
        evaluarNodos(currentID, visto, current);
        visto[currentID] = true;
        cantVistos++;
    }
}

int* ControladorPersonaje::devolverUbicacion(){
    int* auxUbicacion;
    auxUbicacion = ubicacion;
    return auxUbicacion;
}

Personaje* ControladorPersonaje::devolverPersonaje(){
    return personaje;
}

int ControladorPersonaje::coordToId(int *coord){
    int ID = (((coord[0] - 1) * 8) + coord[1]) -1;
    return ID;
}

void ControladorPersonaje::reiniciar_escudo() {
	if(esta_defendiendo) {
		personaje->bajar_escudo();
		esta_defendiendo = false;
	}
}

void ControladorPersonaje::idToCoord(int ID, int* coord){
    coord[0] = (ID / 8) + 1;
    coord[1] = (ID % 8) + 1;
}

int ControladorPersonaje::buscarMinimo(bool* visto){
    int minimo = 1000;
    int minPos = 0;
    for(int i = 0; i < 64 ; i++){
        if((costo[i] < minimo) && (visto[i] == false)){
            minimo = costo[i];
            minPos = i;
        }
    }
    return minPos;
}

void ControladorPersonaje::evaluarNodos(int currentID, bool* visto, Casillero* current){
    int auxID = 0;
    int auxCosto = 0;
    for(int i = 1; i <= 4; i++){
        bool basura = true;
        switch(i){
            case ARRIBA:
                if(current->getUp() != 0){
                    //consigo valor del nodo de arriba
                    auxID = currentID -8;
                    auxCosto = evaluarDir(current->getUp());
                    basura = false;
                }
                break;
            case DERECHA:
                if(current->getRight() != 0){
                    //consigo valor del nodo a la derecha
                    auxID = currentID +1;
                    auxCosto = evaluarDir(current->getRight());
                    basura = false;
                }
                break;
            case ABAJO:
                if(current->getDown() != 0){
                    // consigo valor del nodo de abajo
                    auxID = currentID +8;
                    auxCosto = evaluarDir(current->getDown());
                    basura = false;
                }
                break;
            case IZQUIERDA:
                if(current->getLeft() != 0){
                    //consigo valor del nodo a la izquierda
                    auxID = currentID -1;
                    auxCosto = evaluarDir(current->getLeft());
                    basura = false;
                }
                break;
        }
        auxCosto += costo[currentID];
        if((auxCosto < costo[auxID]) && (visto[auxID] == false) && (basura == false)){
            costo[auxID] = auxCosto;
            anterior[auxID] = currentID;
        }
    }
}

void ControladorPersonaje::ubicarPersonaje(int* destino){
    ptrCasillero = tablero->returnItem(destino);
    if(ptrCasillero->getCharacter() == 0){
        ptrCasillero->setCharacter(personaje);
        for(int i = 0; i < 2; i++){ubicacion[i] = destino[i];}
    } else{
        cout << "Ya hay un personaje en esa ubicacion" << endl;
    }
}

void ControladorPersonaje::se_curo() {
	personaje->curar();
}

void ControladorPersonaje::moverse(int* destino){
    Pila path;
    Casillero* auxCasillero = ptrCasillero;
    int actualID = coordToId(ubicacion);
    int aux = coordToId(destino);
    int auxCoord[2] = {0,0};
    
    if(costo[coordToId(destino)] < personaje->obtenerEnergia()){
        //inicializo
        for(int i = 0; i < 2; i++){ubicacion[i] = destino[i];}
        while(aux != actualID){
            path.agregar(aux);
            aux = anterior[aux];
        }
        aux = path.consulta();
        while(aux != finPila){
            if(auxCasillero->getCharacter() == personaje){
                auxCasillero->setCharacter(0);
            }
            idToCoord(aux, auxCoord);
            auxCasillero = tablero->returnItem(auxCoord);
            if(auxCasillero->getCharacter() == 0){
                auxCasillero->setCharacter(personaje);
            }
            //imprimo tablero
            system("clear");
            tablero->printBoard();
            sleep(2);
            path.eliminar();
            aux = path.consulta();
        }
        ptrCasillero = auxCasillero;
    } else{
        cout << "\nNo hay energia suficiente para moverse a esa posicion.\n";
    }
}

void ControladorPersonaje::morir(){
    tablero->returnItem(ubicacion)->setCharacter(0);
    personaje = 0;
}


ControladorPersonaje::~ControladorPersonaje(){}
