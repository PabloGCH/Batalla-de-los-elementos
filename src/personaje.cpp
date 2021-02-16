#include "personaje.h"
#include <iostream>

using namespace std;

Personaje::Personaje(string nombre, int escudo, int vida) {
    this->nombre = nombre;
    this->escudo = escudo;
    this->vida = vida;
    seleccionado = false;
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

void Personaje::curar() {
	vida += 10;
}

void Personaje::mostrarAtributos() {
    cout << "--------------------------" << endl
         << "Nombre: " << obtenerNombre() << endl
         << "Escudo: " << obtenerEscudo() << endl
         << "Vida: " << obtenerVida() << endl
         << "Energia: " << obtenerEnergia() << endl
         << "--------------------------" << endl;
}

bool Personaje::estaSeleccionado(){
    return seleccionado;
}

void Personaje::seleccionar(){
    seleccionado = true;
}
