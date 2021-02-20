#include "personaje.h"
#include <iostream>

using namespace std;

Personaje::Personaje(string nombre, int escudo, int vida) {
    this->nombre = nombre;
    this->escudo = escudo;
    this->vida = vida;
    jugador = 0;
    seleccionado = false;
    asignarEnergia();
}

void Personaje::asignarJugador(int jug){
    jugador = jug;
}

int Personaje::devolverJugador(){
    return jugador;
}

void Personaje::asignarEnergia(){
    energia  = 10;
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

void Personaje::bajar_escudo() {
    esta_defendiendo = false;
	escudo -= 2;
}

void Personaje::perder_vida() {
	vida -= 5;
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

void Personaje::recuperarEnergia(){
    int cambio = energia;
    energia += 5;
    if(energia > 20){
        energia = 20;
    }
    cambio = energia - cambio;
    cout << nombre << " recupero " << cambio << " de energia." << endl;
}

bool Personaje::seEstaDefendiendo(){
    return esta_defendiendo;
}

void Personaje::asignarEstaDefendiendo(bool def){
    esta_defendiendo = def;
}

Personaje::~Personaje(){}
