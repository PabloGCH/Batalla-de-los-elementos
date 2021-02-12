#include "personaje.h"
#include <iostream>

using namespace std;

Personaje::Personaje(string nombre, int escudo, int vida) {
    this->nombre = nombre;
    this->escudo = escudo;
    this->vida = vida;
    jugador = 0;
    asignarEnergia();
}

void Personaje::asignarEnergia(){
    energia  = 100;
}

string Personaje::obtenerNombre(){
    return nombre;
}

int Personaje::obtenerEscudo() {
    return escudo;
}

int Personaje::obtenerVida() {
    return vida;
}

int Personaje::obtenerEnergia() {
    return energia;
}

void Personaje::restarEnergia(int puntos) {
    energia -= puntos;
}

void Personaje::mostrarAtributos() {
    cout << "--------------------------" << endl
         << "Nombre: " << obtenerNombre() << endl
         << "Escudo: " << obtenerEscudo() << endl
         << "Vida: " << obtenerVida() << endl
         << "Energia: " << obtenerEnergia() << endl
         << "--------------------------" << endl;
}

void Personaje::asignarJugador(int per){
    jugador = per;
}

int Personaje::obtenerJugador() {
    return jugador;
}