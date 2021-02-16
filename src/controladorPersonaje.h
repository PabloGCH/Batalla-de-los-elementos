#ifndef CONTROLADORPERSONAJE_H
#define CONTROLADORPERSONAJE_H
#include <cstdlib>
#include <unistd.h>
#include "pila.h"
#include "tablero.h"
#include "personaje_agua.h"
#include "personaje_fuego.h"
#include "personaje_aire.h"
#include "personaje_tierra.h"

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

enum direcciones{
    ARRIBA = 1,
    DERECHA = 2,
    ABAJO = 3,
    IZQUIERDA = 4,
};

class ControladorPersonaje
{
    protected:
        Personaje* personaje;
        Casillero* ptrCasillero;
        Tablero* tablero;
        int ubicacion[2];
        int costo[64];
        int anterior[64];
        // PRE: Recibe un puntero casillero
        // POS: Devuelve el coste que supondria moverse a ese casillero
        virtual int evaluarDir(Casillero* dir) = 0;
        void reiniciar_escudo();
    public:
        ControladorPersonaje();
        // PRE:
        // POS: Busca los caminos minimos
        void encontrarCaminos();
        //PRE:
        //POS: devuelve un ptr con la ubicacion del personaje
        int* devolverUbicacion();
        //PRE:
        //POS: devuelve puntero a personaje
        Personaje* devolverPersonaje();
        // PRE: recibe las coordenadas del destino
        // POS: lo mueve a esa posicion si tiene la energia suficiente
        void moverse(int *destino);
        // PRE: recibe una posicion del tablero (fila/columna)
        // POS: ubica el personaje en la posicion indicada 
        // (SOLO USAR AL PRINCIPIO DE LA PARTIDA)
        void ubicarPersonaje(int* destino);
        // POS: fija personaje y el casillero en el que esta en 0
        void morir();
        // PRE:
        // POS: Ataca
        virtual void atacar(ControladorPersonaje** ControladoresEnemigo) = 0;
        //POS: el personaje se defiende
        virtual bool defensa() = 0;
        //POS: cura al personaje
        void se_curo();
        virtual ~ControladorPersonaje();
    private:
        // POS: Evalua el coste de los nodos circundantes y guarda su en costo[]
        // y su identificador anterior[]
        void evaluarNodos(int currentID, bool* visto, Casillero* current);
        // PRE: Recibe una coordenada
        // POS: Devuelve un identificador
        int coordToId(int *coord);
        // PRE: Recibe un identificador y una cordenada
        // POS: Crea una coordenada a partir del identificador
        // y la guarda en la coordenada ingresada
        void idToCoord(int ID, int* coord);
        // PRE: Recibe un vector de booleanos que indique por que nodos ya se paso
        // POS: Devuelve el identificador del grafo con menor coste y que no haya sido
        // visitado
        int buscarMinimo(bool* visto);

};

#endif
