#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "controladorpersonaje.h"

class Jugador {
protected:
	ControladorPersonaje* ctrlpersonaje1;
	ControladorPersonaje* ctrlpersonaje2;
	ControladorPersonaje* ctrlpersonaje3;
	int* pos_enemigos[3];
	Jugador* oponente;

public:
	Jugador();
	void asignar_controlador(ControladorPersonaje* 1, ControladorPersonaje* 2, ControladorPersonaje* 3);
	void asignar_rival(Jugador* rival);
	void obtener_pos_enemigos();
	int ubicacion_personajes();
	~Jugador();
};



#endif /* JUGADOR_H_ */
