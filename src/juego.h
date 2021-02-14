#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include "jugador.h"
#include "tablero.h"
#include "ABB.h"
using namespace std;

class Juego{
    public:
        void iniciar();
        Juego();
    private:
        void opcionesPersonaje();
        void comenzarJuego();
        void partida();
        void imprimirOpcionesPersonajes();
        void imprimirOpcionesComenzar();
        int recibirOpcion();
        void pedirOpcionJugador(int i);
        ABB diccionario;
        Jugador jugadores[2];
        Tablero tablero;
};

#endif