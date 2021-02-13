#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include "ABB.h"
using namespace std;

class Juego{
    public:
        void iniciar();
        void opcionesPersonaje();
        void comenzarJuego();
        void partida();
        Juego();
    private:
        void imprimirOpcionesPersonajes();
        void imprimirOpcionesComenzar();
        int recibirOpcion();
        ABB diccionario;
};

#endif