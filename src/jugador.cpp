#include "jugador.h"

Jugador::Jugador() {
	ctrlpersonaje1 = 0;
	ctrlpersonaje2 = 0;
	ctrlpersonaje3 = 0;
	oponente = 0;
	for(int i = 0; i < 3; i++){
		pos_enemigos[i] = 0;
	}
}

void Jugador::asignar_rival(Jugador* rival) {
	oponente = rival;
}

void Jugador::asignar_controlador(ControladorPersonaje* uno, ControladorPersonaje* dos, ControladorPersonaje* tres) {
	ctrlpersonaje1 = uno;
	ctrlpersonaje2 = dos;
	ctrlpersonaje3 = tres;
}

int** Jugador::ubicacion_personajes() {
	int* aux[3];
	aux[0] = ctrlpersonaje1->devolverUbicacion();
	aux[1] = ctrlpersonaje2->devolverUbicacion();
	aux[2] = ctrlpersonaje3->devolverUbicacion();
	return aux;
}

void Jugador::obtener_pos_enemigos() {
	// lo comente porque no lo pude solucionar
	// pos_enemigos = oponente->ubicacion_personajes();
}

Jugador::~Jugador() {
	delete (ctrlpersonaje1);
	delete (ctrlpersonaje2);
	delete (ctrlpersonaje3);
}
