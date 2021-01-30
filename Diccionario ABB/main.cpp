#include "ABB.h"
#include "personaje_fuego.h"
#include "nodo.h"

using namespace std;

int main(){
    Dato Jugador1 = new PersonajeFuego("Lucio", 1, 76);
    Dato Jugador2 = new PersonajeFuego("Maria", 1, 76);
    Dato Jugador3 = new PersonajeFuego("Gimeno", 1, 76);
    Dato Jugador4 = new PersonajeFuego("Albert", 1, 76);
    Dato Jugador5 = new PersonajeFuego("Carlos", 0, 21);
   // Dato Jugador6 = new PersonajeFuego("Karlos", 0, 21);


    ABB diccionario;
    diccionario.insertarHoja(Jugador1);
    diccionario.insertarHoja(Jugador2);
    diccionario.insertarHoja(Jugador3);
    diccionario.insertarHoja(Jugador4);
    diccionario.insertarHoja(Jugador5);
    //diccionario.insertarHoja(Jugador6);
    diccionario.enOrden();
   // Nodo* encontrado = diccionario.buscarPersonaje(Jugador4->obtenerNombre());
   // Dato pers = encontrado->obtenerDato();
   // pers->mostrarAtributos();
   // Dato menor = diccionario.encontrarMenor();
    diccionario.borrarNodo("Gimeno");
    diccionario.enOrden();

    return 0;
}