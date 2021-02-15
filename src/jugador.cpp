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
	while(i < 3 && controladores[i] != 0){
		if(controladores[i] != 0){
			i++;
		} else{
			controladores[i] = controlador;
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

