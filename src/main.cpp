#include "ABB.h"
#include "personaje_fuego.h"
#include "nodo.h"
#include <iostream>

using namespace std;

int main(){
    Dato Jugador1 = new PersonajeFuego("Lucio", 1, 76);
    Dato Jugador2 = new PersonajeFuego("Maria", 1, 76);
    Dato Jugador3 = new PersonajeFuego("Gimeno", 1, 76);
    Dato Jugador4 = new PersonajeFuego("Albert", 1, 76);
    Dato Jugador5 = new PersonajeFuego("Carlos", 0, 21);
    Dato Jugador6 = new PersonajeFuego("Karlos", 0, 21);
    Dato Jugador7 = new PersonajeFuego("Beatriz", 0, 21);
    Dato Jugador8 = new PersonajeFuego("Tamara", 0, 21);
    Dato Jugador9 = new PersonajeFuego("Patricia", 0, 21);
    Dato Jugador10 = new PersonajeFuego("Samantha", 0, 21);
    Dato Jugador11 = new PersonajeFuego("Omar", 0, 21);


    ABB diccionario;
    diccionario.insertarHoja(Jugador1);
    diccionario.insertarHoja(Jugador2);
    diccionario.insertarHoja(Jugador3);
    diccionario.insertarHoja(Jugador4);
    diccionario.insertarHoja(Jugador5);
    diccionario.insertarHoja(Jugador6);
    diccionario.insertarHoja(Jugador7);
    diccionario.insertarHoja(Jugador8);
    diccionario.insertarHoja(Jugador9);
    diccionario.insertarHoja(Jugador10);
    diccionario.insertarHoja(Jugador11);
    diccionario.enOrden();
    cout << endl << "-------------------------------" << endl;
   // Nodo* encontrado = diccionario.buscarPersonaje(Jugador4->obtenerNombre());
   // Dato pers = encontrado->obtenerDato();
   // pers->mostrarAtributos();
   // Dato menor = diccionario.encontrarMenor();
   diccionario.borrarNodo("Maria");
    diccionario.borrarNodo("Albert");
    //diccionario.borrarNodo("Karlos");
    //diccionario.borrarNodo("Beatriz");
    //diccionario.borrarNodo("Carlos");
    //diccionario.borrarNodo("Gimeno");
    //diccionario.borrarNodo("Tamara");
    diccionario.borrarNodo("Patricia");
    //diccionario.borrarNodo("Omar");
    // diccionario.borrarNodo("Samantha");
    //diccionario.borrarNodo("Lucio");
    diccionario.enOrden();

    return 0;
}