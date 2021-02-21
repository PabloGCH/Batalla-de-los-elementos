#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "controladorPersonaje.h"
#include <cstdlib>
#include <ctime>
#include <limits>

class Jugador {
protected:
	ControladorPersonaje* controladores[3];
	Tablero* tablero;
	Jugador* oponente;

public:
	Jugador();
	//PRE: recibe el numero del jugador
    //POS: imprime la vida, el escudo y la energia de todos los personajes
    void imprimirEstados(int jug);
	// PRE: recibe un vector de punteros ControladoresPersonaje
	// POS: imprime los atributos de los persnajes de los controladores
	void imprimirPersonajes(ControladorPersonaje** cont);
	// PRE: se debe invocar cada vez que un personaje ataque
    // POS: revisa si hay personajes con 0 o menos de vida y fija el controlador
    void matarPersonajes();
	// PRE: recibe un personaje
	// POS: Devuelve la defensa a su atributo original si el
	// personaje era de tierra y se estaba defendiendo
	void detenerDefensa(ControladorPersonaje* cont);
	// PRE: recibe un personaje
	// POS: si es un personaje de aire, recupera energia
	void recuperarEnergia(Personaje* personaje);
	// PRE: recibe el controlador del personaje de agua
	// POS: cura a los personajes si un personaje de agua se defiende
	void curarPersonajes(ControladorPersonaje* cont);
	// PRE: recibe un puntero tablero
	// POS: asigna el tablero al atributo tablero de jugador
	void asignarTablero(Tablero* tablero);
	// PRE: recibe un controlador y un entero
	// POS: Asigna el controlador en el vector controladores en el
	// espacio indicado por el entero (USAR EN CARGAR PARTIDA)
	void asignar_controlador(ControladorPersonaje* controlador, int numPer);
	// PRE: recibe un controlador
	// POS: Asigna el controlador en el primer espacio
	// libre del vector controladores (USAR EN COMENZAR PARTIDA)
	void asignar_controlador(ControladorPersonaje* controlador);

    bool procesarOpcion(int opcionElegida, int etapa, int personajeActual);
    void turno(int actual);
	void asignar_rival(Jugador* rival);
	// PRE: Recibe un personaje
	// POS: Si el personaje es de fuego y no tiene energia recibe 5 de daño
	void sinEnergia(Personaje* personaje);
	ControladorPersonaje** devolverControladores();
	~Jugador();

private:
    void mostrarOpcionesPrimerEtapa(int jugadorActual, int personajeActual);
    void mostrarOpcionesSegudaEtapa(int jugadorActual, int personajeActual);
    int solicitarOpcion();
    bool verificarPosicion(int ingreso);
};



#endif /* JUGADOR_H_ */
