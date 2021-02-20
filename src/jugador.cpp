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
    cout << "Ingrese una opción: ";
    cin >> opcion;
    cout << "" << endl;
    while ( opcion < 1 or opcion > 3){
        if(!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Opción ingresada no válida" << endl;
        cout << "Ingrese una opción válida: ";
        cin >> opcion;
        cout << "" << endl;
    }
    return opcion;
};

bool Jugador::verificarPosicion(int ingreso) {
    bool correcto;
    if(!cin){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        correcto = false;
    } else if(1 <= ingreso <= 8){
        correcto = true;
    } else {
        correcto = false;
    }
    return correcto;
}

bool Jugador::procesarOpcion(int opcionElegida, int etapa, int personajeActual){
    switch (etapa) {
        case 1:
            switch (opcionElegida) {
                case 1:
                    return controladores[personajeActual]->devolverPersonaje()->alimentar();
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
                    return controladores[personajeActual]->moverse(ubicacion);
                case 3:
                    cout << "Decidiste pasar a la siquiente etapa " << endl;
                    return true;
            }
            break;
        case 2:
            bool defensa;
            switch (opcionElegida) {
                case 1:
                    return controladores[personajeActual]->atacar(oponente->devolverControladores());
                case 2:
                    defensa = controladores[personajeActual]->defensa();
                    if ( controladores[personajeActual]->devolverPersonaje()->devolverTipo() == TIPO_AGUA){
                        curarPersonajes(controladores[personajeActual]);
                    }
                    return defensa;
                case 3:
                    cout << "Usted decidió terminar el turno " << endl;
                    return true;
            }
            break;

    }

};

void Jugador::imprimirPersonajes(ControladorPersonaje** cont){
    Personaje* aux;
    for(int i = 0; i < 3; i++){
        aux = cont[i]->devolverPersonaje();
        if(aux != 0){
            cout << aux->obtenerNombre() << ", VIDA: " << aux->obtenerVida() << ", ENERGIA: " << aux->obtenerEnergia() << ", ESCUDO: " << aux->obtenerEscudo() << endl;
        }
    }
}

void Jugador::imprimirEstados(int jug){
    cout << "=================================================" << endl;
    cout << "Jugador " << jug +1 << endl;
    imprimirPersonajes(controladores);
    cout << "=================================================" << endl;
    if(jug == 0){
        cout << "Jugador 2" << endl;
    } else{
        cout << "Jugador 1" << endl;
    }
    imprimirPersonajes(oponente->devolverControladores());
    cout << "=================================================" << endl;
}



void Jugador::turno(int actual){
    int opcion;
    bool exito1 = false;
    bool exito2 = false;
    for (int i = 0; i < 3; i++){
        if (controladores[i]->devolverPersonaje() != 0){
            imprimirEstados(actual);
            tablero->printBoard();
            // chequeo si es un personaje de tierra defendiendose
            detenerDefensa(controladores[i]);
            // chequeo si es un personaje de aire y si es asi recupera energia
            recuperarEnergia(controladores[i]->devolverPersonaje());
            // Imprimir estado de los personajes (agregar)
            mostrarOpcionesPrimerEtapa(actual, i);
            opcion = solicitarOpcion();
            exito1 = procesarOpcion(opcion, 1, i);
            while ( !exito1 ){
                cout << "El proceso seleccionado no tuvo exito, por favor seleccione otra opcion o pase a la siquiente etapa" << endl;
                mostrarOpcionesPrimerEtapa(actual, i);
                opcion = solicitarOpcion();
                exito1 = procesarOpcion(opcion, 1, i);
            }
            // Verifico si hay personajes muertos y si es asi los
            // retiro del tablero
            matarPersonajes();
            tablero->printBoard();
            // Imprimir estado de los personajes (agregar)
            mostrarOpcionesSegudaEtapa(actual, i);
            opcion = solicitarOpcion();
            exito2 = procesarOpcion(opcion, 2, i);
            while ( !exito2 ){
                cout << "El proceso elegido no realizó ningún cambio, seleccione otra opcion o termine el turno" << endl;
                mostrarOpcionesSegudaEtapa(actual, i);
                opcion = solicitarOpcion();
                exito2 = procesarOpcion(opcion, 2, i);
            }
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

void Jugador::detenerDefensa(ControladorPersonaje* cont){
    if(cont->devolverPersonaje()->devolverTipo() == TIPO_TIERRA){
        cont->reiniciar_escudo();
    }
}

void Jugador::recuperarEnergia(Personaje* personaje){
    if(personaje->devolverTipo() == TIPO_AIRE){
        personaje->recuperarEnergia();
    }
}