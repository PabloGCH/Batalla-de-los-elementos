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

void Jugador::asignar_controlador(ControladorPersonaje* uno, ControladorPersonaje* dos, ControladorPersonaje* tres) {
	controladores[0] = uno;
	controladores[1] = dos;
	controladores[2] = tres;
}

ControladorPersonaje** Jugador::devolverControladores(){
	return controladores;
}



Jugador::~Jugador() {
	for(int i = 0; i < 3; i++){
		delete controladores[i];
	}
}
