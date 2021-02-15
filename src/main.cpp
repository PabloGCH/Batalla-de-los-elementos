#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "controladorAgua.h"
#include "controladorFuego.h"
#include "juego.h"
using namespace std;

int main(){
    /*int ubicacionInicial[2] = {2, 3};
    int ubicacionApolo[2] = {4,4};
    Tablero* tablero = new Tablero;
    Personaje* poseidon = new PersonajeAgua("poseidon", 4, 30);
    Personaje* apolo = new PersonajeFuego("apolo", 4, 30);
    ControladorPersonaje* contPoseidon = new ControladorAgua(poseidon, tablero);
    ControladorPersonaje* contApolo = new ControladorFuego(apolo, tablero);
    contPoseidon->ubicarPersonaje(ubicacionInicial);
    contApolo->ubicarPersonaje(ubicacionApolo);
    int opcion = 0;
    int destino[2];
    bool salir = false;
    while(salir == false){
        system("clear");
        tablero->printBoard();
        contPoseidon->encontrarCaminos();
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
            cout << "\ningresa algo valido";
            break;
        }
    }
    delete contPoseidon;
    delete tablero;*/
    Juego nuevo;
    //nuevo.mostrarPersonajes();
    //nuevo.mostrarDetalle();
    //nuevo.eliminarPersonaje();
    return 0;
}