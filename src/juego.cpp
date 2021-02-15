#include "juego.h"

Juego::Juego(){
    ifstream archivo("../res/personajes.csv");
    if(archivo.is_open()){
        //Lleno diccionario con archivo
        procesarArchivo(archivo);
        archivo.close();
    } else {
        cout << "fallo al abrir archivo de personajes";
    }
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
            agregarPersonaje();
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

void Juego::agregarPersonaje() {
    string elementoAgregar, nombreAgregar;
    Dato personajeAgregar;

    cout << "\tAGREGAR PERSONAJE." << endl;
    cin.ignore();
    registrarElemento(elementoAgregar);

    cout << "Ingrese el nombre del nuevo personaje: ";
    leerCadena(nombreAgregar);
    while(nombreAgregar == (diccionario.buscarPersonaje(nombreAgregar))->obtenerClave()){
        cout << "El personaje que quiere agregar ya existe. Ingrese otro nombre para un nuevo personaje." << endl;
        leerCadena(nombreAgregar);
    }
    personajeAgregar = crearPersonaje(elementoAgregar, nombreAgregar);
    diccionario.insertarHoja(personajeAgregar);
}

void Juego::leerCadena(string &cadena){
    getline(cin, cadena);
    nombreMayuscula(cadena);
}

void Juego::nombreMayuscula(string &nombre){
    for(int i = 0; i < (int)nombre.length(); i++){
        if(i == 0)
            nombre[i] = toupper(nombre[i]);
        else if(nombre[i-1] != ' ')
            nombre[i] = tolower(nombre[i]);
        if(nombre[i] == ' ')
            nombre[i+1] = toupper(nombre[i+1]);
    }
}

Dato Juego::crearPersonaje(string elemento, string nombre){
    Dato nuevo;
    int escudo = rand() % 3;
    int vida = rand() % 91 + 10;
    if(elemento == "AGUA")
        nuevo = new PersonajeAgua(nombre, escudo, vida);
    else if(elemento == "AIRE")
        nuevo = new PersonajeAire(nombre, escudo, vida);
    else if(elemento == "FUEGO")
        nuevo = new PersonajeFuego(nombre, escudo, vida);
    else
        nuevo = new PersonajeTierra(nombre, escudo, vida);
    return nuevo;
}

Dato Juego::crearPersonaje(string elemento, string nombre, int escudo, int vida){
    Dato nuevo;
    if(elemento == "AGUA")
        nuevo = new PersonajeAgua(nombre, escudo, vida);
    else if(elemento == "AIRE")
        nuevo = new PersonajeAire(nombre, escudo, vida);
    else if(elemento == "FUEGO")
        nuevo = new PersonajeFuego(nombre, escudo, vida);
    else
        nuevo = new PersonajeTierra(nombre, escudo, vida);
    return nuevo;
}

void Juego::registrarElemento(string &elementoAgregar){
    cout << "Ingrese el elemento del nuevo personaje ( AGUA, AIRE, TIERRA, FUEGO ): ";
    leerCadena(elementoAgregar);
    while(elementoAgregar != "Agua" && elementoAgregar != "Aire" && elementoAgregar != "Tierra" && elementoAgregar != "Fuego") {
        cout << "\tERROR. Ingrese un elemento válido ( AGUA, AIRE, TIERRA, FUEGO ): ";
        leerCadena(elementoAgregar);
    }
}

void Juego::procesarArchivo(ifstream &archivo){
    if (archivo.is_open()){
        string elemento, nombre, escudo, vida;
        int escudoEntero, vidaEntero;
        bool salir = false;
        while(!salir){
            string elemento, nombre, escudo, vida;
            int escudoEntero, vidaEntero;
            if(archivo.peek() != EOF){
                procesarDatosPersonaje(archivo, elemento, nombre, escudo, vida, escudoEntero, vidaEntero);
                Dato nuevo = crearPersonaje(elemento, nombre, escudoEntero, vidaEntero);
                diccionario.insertarHoja(nuevo);
            } else {
                salir = true;
            }
        }
    }
}

void Juego::procesarDatosPersonaje(ifstream &archivo, string &elemento, string &nombre, string &escudo, string &vida, int &escudoEntero, int &vidaEntero){
    getline(archivo, elemento, ',');
    getline(archivo, nombre, ',');
    getline(archivo, escudo, ',');
    getline(archivo, vida, '\n');
    escudoEntero = stoi(escudo);
    vidaEntero = stoi(vida);
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
