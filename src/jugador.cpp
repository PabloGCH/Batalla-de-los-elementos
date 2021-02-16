#include "jugador.h"

Jugador::Jugador() {
	oponente = 0;
	for(int i = 0; i < 3; i++){
		controladores[i] = 0;
	}
}

void Jugador::asignar_rival(Jugador* rival) {
	oponente = rival;
}

ControladorPersonaje** Jugador::devolverControladores(){
	return controladores;
}

void Jugador::asignar_controlador(ControladorPersonaje* controlador){
	int i = 0;
	bool salir = false;
	while(i < 3 && !salir){
		if(controladores[i] != 0){
			i++;
		} else{
			controladores[i] = controlador;
			salir = true;
		}
	}
	if(i = 3){
		cout << "Ya se asignaron todos los controladores(de personajes)" << endl;
	}
}

Jugador::~Jugador() {
	for(int i = 0; i < 3; i++){
		delete controladores[i];
	}
}

void Jugador::matarPersonajes(){
	ControladorPersonaje** controladoresOponente;
	Personaje* personaje;
	for(int i = 0; i < 3; i++){
		personaje = controladoresOponente[i]->devolverPersonaje();
		if(personaje != 0){
			if(personaje->obtenerVida() <= 0){
				controladoresOponente[i]->morir();
			}
		}
	}
}

void Jugador::curarPersonajes(ControladorPersonaje* cont){
	for (int i = 0; i < 3; i++) {
		if (controladores[i] != cont) {
			controladores[i]->se_curo();
		}
	}
}