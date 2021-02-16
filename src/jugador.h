#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "controladorPersonaje.h"

class Jugador {
protected:
	ControladorPersonaje* controladores[3];
	Jugador* oponente;

public:
	Jugador();
	// PRE: se debe invocar cada vez que un personaje ataque
    // POS: revisa si hay personajes con 0 o menos de vida y fija el controlador
    void matarPersonajes();
	void asignar_controlador(ControladorPersonaje* controlador);
	void asignar_rival(Jugador* rival);
	ControladorPersonaje** devolverControladores();
	~Jugador();
};



#endif /* JUGADOR_H_ */
