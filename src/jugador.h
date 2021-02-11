#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "ControladorPersonaje.h"

class Jugador {
public:
	ControladorPersonaje* ctrlpersonaje1;
	ControladorPersonaje* ctrlpersonaje2;
	ControladorPersonaje* ctrlpersonaje3;
	int* pos_enemigos[3];
	Jugador* oponente;
	Jugador(ControladorPersonaje* 1, ControladorPersonaje* 2, ControladorPersonaje* 3);
	void asignar_rival(Jugador* rival);
	void obtener_pos_enemigos();
	int ubicacion_personajes();
};



#endif /* JUGADOR_H_ */
