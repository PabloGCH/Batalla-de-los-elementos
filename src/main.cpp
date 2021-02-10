#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "controladorAgua.h"
using namespace std;

int main(){
    int ubicacionInicial[2] = {2, 3};
    Tablero* tablero = new Tablero;
    Personaje* poseidon = new PersonajeAgua("poseidon", 4, 30);
    ControladorPersonaje* contPoseidon = new ControladorAgua(poseidon, tablero);
    contPoseidon->ubicarPersonaje(ubicacionInicial);
    int opcion = 0;
    int destino[2];
    bool salir = false;
    while(salir == false){
        system("clear");
        tablero->printBoard();
        contPoseidon->pathfind();
        cout << "1. Moverse\n";
        cout << "2. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "\n\n";
            cout << "Ingrese una fila: ";
            cin >> destino[0];
            cout << "Ingrese una columna: ";
            cin >> destino[1];
            system("clear");
            contPoseidon->moverse(destino);
            break;
        case 2:
            salir = true;
            break;
        default:
            system("clear");
            cout << "\ningresa algo valido boludo.";
            break;
        }
        
    }
    delete tablero;
    return 0;
}