#include "controladorPersonaje.h"

ControladorPersonaje::ControladorPersonaje() {
	personaje = 0;
    for(int i = 0; i<2; i++){ubicacion[i] = 0;};
    ptrCasillero = 0;
}

void ControladorPersonaje::etapa1() {
    bool salir = false;
    int opcion;
	imprimirOpciones1();
    cin >> opcion;
    while (!salir)
    {
        switch (opcion)
        {
            case ALIMENTARSE:
                personaje->alimentar();
                salir = true;
                break;
            case MOVERSE:
                salir = true;
                break;
            case PASAR:
                salir = true;
                break;
            default:
                cout << "\nIngrese una opcion valida: ";
                cin >> opcion;
                break;
        }
    }
}

void ControladorPersonaje::etapa2() {
	bool salir = false;
    int opcion;
	imprimirOpciones1();
    cin >> opcion;
    while (!salir)
    {
        switch (opcion)
        {
            case ATACAR:
                atacar();
                salir = true;
                break;
            case DEFENDERSE:
                // personaje.defenderse();
                salir = true;
                break;
            case PASAR:
                salir = true;
                break;
            default:
                cout << "\nIngrese una opcion valida: ";
                cin >> opcion;
                break;
        }
    }
}

void ControladorPersonaje::imprimirOpciones1() {
	
}

void ControladorPersonaje::imprimirOpciones2() {
	
}


void ControladorPersonaje::pathfind(int *actualCoord, Casillero* actualPtr){
    Casillero* current = actualPtr;
    bool visto[64];
    int currentID = coordToId(actualCoord);
    int currentCoord[2] = {0,0};
    int cantVistos = 0;
    for(int i = 0; i < 64; i++){
        costo[i] = 1000;
        visto[i] = false;
    }
    //inicializo
    evaluarNodos(currentID, visto, current);
    anterior[0] = 0;
    costo[currentID] = 0;
    visto[currentID] = true;
    cantVistos++;
    while(cantVistos < 64){
        currentID = buscarMinimo(costo, visto);
        idToCoord(currentID, currentCoord);
        current = tablero->returnItem(currentCoord);
        evaluarNodos(currentID, visto, current);
        cantVistos++;
    }
}

int ControladorPersonaje::coordToId(int *coord){
    int ID = (((coord[0] - 1) * 8) + coord[1]) -1;
    return ID;
}

void ControladorPersonaje::idToCoord(int ID, int* coord){
    coord[0] = (ID / 8) + 1;
    coord[1] = (ID % 8);
}

int ControladorPersonaje::buscarMinimo(int* vector, bool* visto){
    int minimo = 1000;
    int minPos = 0;
    for(int i = 0; i < 64 ; i++){
        if((vector[i] < minimo) && (visto[i] == false)){
            minimo = vector[i];
            minPos = i;
        }
    }
    return minPos;
}

void ControladorPersonaje::evaluarNodos(int currentID, bool* visto, Casillero* current){
    int auxID = 0;
    int auxCosto = 0;
    for(int i = 1; i <= 4; i++){
        switch(i){
            case ARRIBA:
                //consigo valor del nodo de arriba
                auxID = currentID -8;
                auxCosto = evaluarDir(current->getUp());
                break;
            case DERECHA:
                //consigo valor del nodo a la derecha
                auxID = currentID +1;
                auxCosto = evaluarDir(current->getRight());
                break;
            case ABAJO:
                // consigo valor del nodo de abajo
                auxID = currentID +8;
                auxCosto = evaluarDir(current->getDown());
                break;
            case IZQUIERDA:
                //consigo valor del nodo a la izquierda
                auxID = currentID -1;
                auxCosto = evaluarDir(current->getLeft());
                break;
        }
        if((auxCosto < costo[auxID]) && (visto[auxID] == false)){
            costo[auxID] = auxCosto;
            anterior[auxID] = currentID;
        }
    }
}





//============================================================
//============================================================
//============================================================
//============================================================
void ControladorPersonaje::moverse(){

}
