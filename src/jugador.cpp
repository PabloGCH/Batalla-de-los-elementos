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
	ControladorPersonaje** controladoresOponente = oponente->devolverControladores();
	Personaje* personajeEnemigo;
    Personaje* personaje;
	for(int i = 0; i < 3; i++){
		personajeEnemigo = controladoresOponente[i]->devolverPersonaje();
        personaje = controladores[i]->devolverPersonaje();
		if(personaje != 0){
			if(personaje->obtenerVida() <= 0){
				controladores[i]->morir();
			}
		}
        if(personajeEnemigo != 0){
			if(personajeEnemigo->obtenerVida() <= 0){
				controladoresOponente[i]->morir();
			}
		}
	}
}
void Jugador::mostrarOpcionesPrimerEtapa(int jugadorActual, int personajeActual){
    cout << "Jugador " << jugadorActual + 1 << " qué deseas que haga " << controladores[personajeActual]->devolverPersonaje()->obtenerNombre() << " en esta etapa? " << endl;
    cout << "1. Alimentarse " << endl;
    cout << "2. Moverse " << endl;
    cout << "3. Pasar siguiente etapa " << endl;
};

void Jugador::mostrarOpcionesSegudaEtapa(int jugadorActual, int personajeActual){
    cout << "Jugador " << jugadorActual + 1 << " qué deseas que haga " << controladores[personajeActual]->devolverPersonaje()->obtenerNombre() << " en esta etapa? " << endl;
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
                    controladores[personajeActual]->encontrarCaminos();
                    int ubicacion[2];
                    cout << "Ingrese una fila: ";
                    cin >> ubicacion[0];
                    cout << "" << endl;
                    while( !verificarPosicion(ubicacion[0]) ){
                        cout << "Fila ingresada fuera de rango " << endl;
                        cout << "Ingrese una fila: ";
                        cin >> ubicacion[0];
                        cout << "" << endl;
                    }
                    cout << "Ingrese una columna: ";
                    cin >> ubicacion[1];
                    cout << "" << endl;
                    while(!verificarPosicion(ubicacion[1])){
                        cout << "Columna ingresada fuera de rango " << endl;
                        cout << "Ingrese una columna: ";
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
                    controladores[personajeActual]->atacar(oponente->devolverControladores());
                    break;
                case 2:
                    controladores[personajeActual]->defensa();
                    if ( controladores[personajeActual]->devolverPersonaje()->devolverTipo() == TIPO_AGUA){
                        curarPersonajes(controladores[personajeActual]);
                    }
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
            tablero->printBoard();
            // chequeo si es un personaje de tierra defendiendose
            if(controladores[i]->devolverPersonaje()->devolverTipo() == TIPO_TIERRA){
                controladores[i]->reiniciar_escudo();
            }
            // Imprimir estado de los personajes
            mostrarOpcionesPrimerEtapa(actual, i);
            opcion = solicitarOpcion();
            procesarOpcion(opcion, 1, i);
            // Verifico si hay personajes muertos y si es asi los
            // retiro del tablero
            matarPersonajes();
            tablero->printBoard();
            // Imprimir estado de los personajes
            mostrarOpcionesSegudaEtapa(actual, i);
            opcion = solicitarOpcion();
            procesarOpcion(opcion, 2, i);
            //reviso si es un personaje de fuego sin energia
            // y si es asi pierde vida
            sinEnergia(controladores[i]->devolverPersonaje());
            matarPersonajes();
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

void Jugador::sinEnergia (Personaje* personaje) {
	if (personaje->devolverTipo() == TIPO_FUEGO && personaje->obtenerEnergia() <= 0) {
		personaje->perder_vida();
	}
}
