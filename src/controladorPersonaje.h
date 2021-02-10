#ifndef CONTROLADORPERSONAJE_H
#define CONTROLADORPERSONAJE_H
#include <cstdlib>
#include <unistd.h>
#include "pila.h"
#include "tablero.h"
#include "personaje_agua.h"

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
    public:
        //ControladorPersonaje(Personaje* personaje, Tablero* tablero);
        // Da a elegir Alimentarse, Moverse, Pasar Opcion
        void etapa1();
        // Da a elegir Defenderse, Atacar, Pasar Opcion
        void etapa2();

        // POS: imprime las opciones para la primera etapa
        void imprimirOpciones1();
        // POS: imprime las opciones para la primera etapa
        void imprimirOpciones2();


        virtual void atacar() = 0;
        // evalue coste de caminos
        virtual int evaluarDir(Casillero* dir) = 0;
        // busca camino minimo
        void encontrarCaminos();
        // evaluo Distancia, Nodos circundantes
        void evaluarNodos(int currentID, bool* visto, Casillero* current);
        // convierte coordenadas en numero de elemento
        int coordToId(int *coord);
        // convierte ID en coordenadas
        void idToCoord(int ID, int* coord);
        // convierte numero en coordenadas
        int buscarMinimo(int* vector, bool* visto);
        // PRE: recibe las coordenadas del destino
        // POS: lo mueve a esa posicion si tiene la energia suficiente
        void moverse(int *destino);
        // PRE: recibe una posicion del tablero (fila/columna)
        // POS: ubica el personaje en la posicion indicada 
        // (SOLO USAR AL PRINCIPIO DE LA PARTIDA)
        void ubicarPersonaje(int* destino);
        virtual ~ControladorPersonaje();

};

#endif