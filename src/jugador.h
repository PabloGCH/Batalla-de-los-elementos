#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "controladorPersonaje.h"

class Jugador {
protected:
	ControladorPersonaje* ctrlpersonaje1;
	ControladorPersonaje* ctrlpersonaje2;
	ControladorPersonaje* ctrlpersonaje3;
	int* pos_enemigos[3];
	Jugador* oponente;

public:
	Jugador();
	void asignar_controlador(ControladorPersonaje* uno, ControladorPersonaje* dos, ControladorPersonaje* tres);
	void asignar_rival(Jugador* rival);
	void obtener_pos_enemigos();
	int** ubicacion_personajes();
	~Jugador();
};



#endif /* JUGADOR_H_ */
