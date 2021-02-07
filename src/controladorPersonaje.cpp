#include "controladorPersonaje.h"

ControladorPersonaje::ControladorPersonaje() {
	personaje = 0;
    ptrCasillero = 0;
}

void ControladorPersonaje::etapa1() {
    bool salir = false;
    int opcion;
	imprimirOpciones1();
    cin >> opcion;
    while (!salir)
    {
        switch (opcion)
        {
            case ALIMENTARSE:
                personaje->alimentar();
                salir = true;
                break;
            case MOVERSE:
                moverse();
                salir = true;
                break;
            case PASAR:
                salir = true;
                break;
            default:
                cout << "\nIngrese una opcion valida: ";
                cin >> opcion;
                break;
        }
    }
}

void ControladorPersonaje::etapa2() {
	bool salir = false;
    int opcion;
	imprimirOpciones1();
    cin >> opcion;
    while (!salir)
    {
        switch (opcion)
        {
            case ATACAR:
                atacar();
                salir = true;
                break;
            case DEFENDERSE:
                // personaje.defenderse();
                salir = true;
                break;
            case PASAR:
                salir = true;
                break;
            default:
                cout << "\nIngrese una opcion valida: ";
                cin >> opcion;
                break;
        }
    }
}

void ControladorPersonaje::imprimirOpciones1() {
	
}

void ControladorPersonaje::imprimirOpciones2() {
	
}

