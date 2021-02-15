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

        // POS: agrega un nuevo personaje al diccionario.
        void agregarPersonaje();

        // PRE: el diccionario no debe estar vacio.
        // POS: elimina el nodo del ABB que coincida la clave del nodo con el nombre ingresado por teclado.
        // EN ABB 'eliminarRaiz' genera un error - Chequear -
        void eliminarPersonaje();

        void mostrarPersonajes();

        void mostrarDetalle();

        Juego();
    private:
        void opcionesPersonaje();
        void comenzarJuego();
        void partida();
        void imprimirOpcionesPersonajes();
        void imprimirOpcionesComenzar();
        int recibirOpcion();
        void pedirOpcionJugador(int i);

        //POS: Registra un elemento valido para la creacion de un personaje ( AIRE, AGUA, FUEGO, TIERRA )
        void registrarElemento(string &elementoAgregar);

        // POS: Devuelve un puntero al nuevo personaje.
        Dato  crearPersonaje(string elemento, string nombre);

        // Metodo sobrecargado para crear personajes desde archivo con valores de escudo y vida ya dterminados.
        // POS: Devuelve un puntero al nuevo personaje.
        Dato crearPersonaje(string elemento, string nombre, int escudo, int vida);

        //POS: lee una cadena ingresada por teclado y la deja con la primer letra de cada palabra en mayusculas.
        void leerCadena(string &cadena);

        //POS: Deja la 1° letra de cada palabra en mayuscula.
        void nombreMayuscula(string &nombre);

        // PRE: El archivo debe pasarse abierto.
        // POS carga todos los personajes en el archivo en el diccionario.
        void procesarArchivo(ifstream &archivo);

        // PRE: el archivo se debe pasar abierto.
        // POS: Almacena 'elemento', 'nombre', 'escudo', y 'vida' en variables y convierte estas ultimas 2 a INT.
        void procesarDatosPersonaje(ifstream &archivo, string &elemento, string &nombre, string &escudo, string &vida, int &escudoEntero, int &vidaEntero);

        ABB diccionario;
        Jugador jugadores[2];
        Tablero tablero;
};

#endif