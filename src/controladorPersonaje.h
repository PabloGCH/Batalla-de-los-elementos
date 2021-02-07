#ifndef CONTROLADORPERSONAJE_H
#define CONTROLADORPERSONAJE_H
#include "tablero.h"

enum opciones1{
    //etapa 1
    ALIMENTARSE = 1,
    MOVERSE = 2,
    //etapa 2
    ATACAR = 1,
    DEFENDERSE = 2,
    // en ambas
    PASAR = 3,
};

class ControladorPersonaje
{
    protected:
        Personaje* personaje;
        Casillero* ptrCasillero;
        int ubicacion[2] = {1, 2};
    public:
        ControladorPersonaje();
        // Da a elegir Alimentarse, Moverse, Pasar Opcion
        void etapa1();
        // Da a elegir Defenderse, Atacar, Pasar Opcion
        void etapa2();

        // POS: imprime las opciones para la primera etapa
        void imprimirOpciones1();
        // POS: imprime las opciones para la primera etapa
        void imprimirOpciones2();


        virtual void moverse() = 0;
        virtual void atacar() = 0;
};

#endif