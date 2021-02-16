#include "jugador.h"

Jugador::Jugador() {
    tablero = 0;
	oponente = 0;
	for(int i = 0; i < 3; i++){
		controladores[i] = 0;
	}
}

void Jugador::asignarTablero(Tablero* tablero){
    this->tablero = tablero;
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
	if(i == 3){
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
void Jugador::mostrarOpcionesPrimerEtapa(int jugadorActual, int personajeActual){
    cout << "Jugador " << jugadorActual << " qué deseas que haga " << controladores[personajeActual]->devolverPersonaje()->obtenerNombre() << " en esta etapa? " << endl;
    cout << "1. Alimentarse " << endl;
    cout << "2. Moverse " << endl;
    cout << "3. Pasar siguiente etapa " << endl;
};

void Jugador::mostrarOpcionesSegudaEtapa(int jugadorActual, int personajeActual){
    cout << "Jugador " << jugadorActual << " qué deseas que haga " << controladores[personajeActual]->devolverPersonaje()->obtenerNombre() << " en esta etapa? " << endl;
    cout << "1. Atacar " << endl;
    cout << "2. Defenderse " << endl;
    cout << "3. Pasar opción" << endl;
};

int Jugador::solicitarOpcion(){
    int opcion;
    cout << "Ingrese una opción válida: ";
    cin >> opcion;
    cout << "" << endl;
    while ( opcion < 1 or opcion > 3){
        cout << "Opción ingresada no válida" << endl;
        cout << "Ingrese una opción válida: ";
        cin >> opcion;
        cout << "" << endl;
    }
    return opcion;
};

bool Jugador::verificarPosicion(int ingreso) {
    return(1 <= ingreso <= 8);
}

void Jugador::procesarOpcion(int opcionElegida, int etapa, int personajeActual){
    switch (etapa) {
        case 1:
            switch (opcionElegida) {
                case 1:
                    controladores[personajeActual]->devolverPersonaje()->alimentar();
                    break;
                case 2:
                    int ubicacion[2];
                    cout << "Ingrese una fila: ";
                    cin >> ubicacion[0];
                    cout << "" << endl;
                    while(bool verificado = verificarPosicion(ubicacion[0])){
                        cout << "Ingrese una fila: ";
                        cin >> ubicacion[0];
                        cout << "" << endl;
                    }
                    cout << "Ingrese una fila: ";
                    cin >> ubicacion[1];
                    cout << "" << endl;
                    while(bool verificado = verificarPosicion(ubicacion[1])){
                        cout << "Ingrese una fila: ";
                        cin >> ubicacion[1];
                        cout << "" << endl;
                    }
                    controladores[personajeActual]->moverse(ubicacion);
                    break;
                case 3:
                    cout << "Decidiste pasar a la siquiente etapa " << endl;
                    break;

            }
            break;
        case 2:
            switch (opcionElegida) {
                case 1:
                    //controladores[personajeActual]->atacar(oponente);
                    break;
                case 2:
                    controladores[personajeActual]->devolverPersonaje()->defender();
                    break;
                case 3:
                    cout << "Usted decidió terminar el turno " << endl;
                    break;
            }
            break;

    }

};

void Jugador::turno(int actual){
    int opcion;
    for (int i = 0; i < 3; i++){
        if (controladores[i]->devolverPersonaje() != 0){
            mostrarOpcionesPrimerEtapa(actual, i);
            opcion = solicitarOpcion();
            procesarOpcion(opcion, 1, i);
            mostrarOpcionesSegudaEtapa(actual, i);
            opcion = solicitarOpcion();
            procesarOpcion(opcion, 2, i);
        }
    }
    cout << "Turno finalizado "<< endl;

};

void Jugador::curarPersonajes(ControladorPersonaje* cont){
	for (int i = 0; i < 3; i++) {
		if (controladores[i] != cont) {
			controladores[i]->se_curo();
		}
	}
}

void Jugador::sinEnergia () {
	for (int i = 0; i < 3; i++) {
		if (controladores[i]->devolverPersonaje()->devolverTipo() == 4 && controladores[i]->devolverPersonaje()->obtenerEnergia() == 0) {
			controladores[i]->devolverPersonaje()->perder_vida();
		}
	}
}
