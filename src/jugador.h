#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "controladorPersonaje.h"

class Jugador {
protected:
	ControladorPersonaje* controladores[3];
	int* pos_enemigos[3];
	Jugador* oponente;

public:
	Jugador();
	void asignar_controlador(ControladorPersonaje* uno, ControladorPersonaje* dos, ControladorPersonaje* tres);
	void asignar_rival(Jugador* rival);
	~Jugador();
};



#endif /* JUGADOR_H_ */
