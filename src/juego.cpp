#include "juego.h"

Juego::Juego(){
    //Lleno diccionario con archivo
}

void Juego::iniciar(){
    // si hay partida guardada

    // si no hay partida guardada
    opcionesPersonaje();
}


int Juego::recibirOpcion(){
    int opcion;
    cout << "\nIngrese una opcion: ";
    cin >> opcion;
    return opcion;
}


void Juego::imprimirOpcionesPersonajes(){
    cout << "----------BATALLA DE LOS ELEMENTOS----------" << endl;
    cout <<"Bienvenido al juego" << endl;
    cout << "Opciones: " << endl;
    cout << "1. Agregar nuevo personaje" << endl;
    cout << "2. Eliminar personaje" << endl;
    cout << "3. Mostrar todos los personajes" << endl;
    cout << "4. Buscar detalles de un personaje" << endl;
    cout << "5. Comenzar Juego" << endl;
    cout << "6. Salir" << endl;
}

void Juego::imprimirOpcionesComenzar(){
    cout << "----------BATALLA DE LOS ELEMENTOS----------" << endl;
    cout <<"Bienvenido al juego" << endl;
    cout << "Opciones: " << endl;
    cout << "1. Buscar personaje en particular" << endl;
    cout << "2. Mostrar los nombres de todos los personajes" << endl;
    cout << "3. Seleccionar personaje" << endl;
    cout << "4. Salir " << endl;
};

void Juego::opcionesPersonaje(){
    bool salir = false;
    int opcion;
    while(!salir){
        imprimirOpcionesPersonajes();
        opcion = recibirOpcion();
        switch (opcion)
        {
        case 1:
            // agregar personaje
            break;
        case 2:
            // eliminar personaje
            break;
        case 3:
            // mostrar nombre personajes
            break;
        case 4:
            // buscar detalles personaje
        case 5:
            comenzarJuego();
            salir = true;
        case 6:
            salir = true;
            break;
        default:
            cout << "\nIngrese una opcion valida\n";
            break;
        }
    }
}


void Juego::comenzarJuego(){
    bool salir = false;
    int opcion;
    int per = 0;
    int jug = 0;
    while(!salir && jug < 2){
        while(!salir && per < 3){
            imprimirOpcionesComenzar();
            opcion = recibirOpcion();
            switch (opcion)
            {
            case 1:
                // buscar detalles personaje
                break;
            case 2:
                // mostrar nombre personajes
                break;
            case 3:
                per += 0;// seleccionar personaje
                break;
            case 4:
                salir = true;
                break;
            default:
                cout << "\nIngrese una opcion valida\n";
                break;
            }
        }
        jug++;
    }
    if(!salir){
        partida();
    }
}


void Juego::partida(){
    
}
