#include "juego.h"

Juego::Juego(){
    ifstream archivo("../res/personajes.csv");
    if(archivo.is_open()){
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
            eliminarPersonaje();
            break;
        case 3:
            mostrarPersonajes();
            break;
        case 4:
            mostrarDetalle();
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

void Juego::mostrarDetalle() {
    string nombreBuscado;
    Nodo* encontrado;
    cin.ignore();
    cout << "\tMOSTRAR DETALLE DE PERSONAJE." << endl <<
         "Ingrese el nombre del personaje a buscar en el diccionario: ";
    leerCadena(nombreBuscado);
    system("clear");
    encontrado = diccionario.buscarPersonaje(nombreBuscado);
    while(!encontrado){
        cout << "\tEl personaje que intenta buscar NO existe." << endl
             << "Estos son los personajes disponibles: " << endl;
        mostrarPersonajes();
        cout << "Ingrese el nombre del personaje a buscar en el diccionario: ";
        leerCadena(nombreBuscado);
        system("clear");
        encontrado = diccionario.buscarPersonaje(nombreBuscado);
    }
    encontrado->obtenerDato()->mostrarAtributos();
}

void Juego::mostrarPersonajes(){
    diccionario.enOrden();
}

void Juego::agregarPersonaje() {
    string elementoAgregar, nombreAgregar;
    Dato personajeAgregar;
    Nodo* encontrado;

    cout << "\tAGREGAR PERSONAJE." << endl;
    registrarElemento(elementoAgregar);

    cout << "Ingrese el nombre del nuevo personaje: " << endl;
    leerCadena(nombreAgregar);
    encontrado = diccionario.buscarPersonaje(nombreAgregar);
    while(encontrado){
            cout << "El personaje que quiere agregar ya existe. Ingrese otro nombre para un nuevo personaje." << endl;
            leerCadena(nombreAgregar);
            encontrado = diccionario.buscarPersonaje(nombreAgregar);
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
    if(elemento == "Agua")
        nuevo = new PersonajeAgua(nombre, escudo, vida);
    else if(elemento == "Aire")
        nuevo = new PersonajeAire(nombre, escudo, vida);
    else if(elemento == "Fuego")
        nuevo = new PersonajeFuego(nombre, escudo, vida);
    else
        nuevo = new PersonajeTierra(nombre, escudo, vida);
    return nuevo;
}

Dato Juego::crearPersonaje(string elemento, string nombre, int escudo, int vida){
    Dato nuevo;
    if(elemento == "Agua")
        nuevo = new PersonajeAgua(nombre, escudo, vida);
    else if(elemento == "Aire")
        nuevo = new PersonajeAire(nombre, escudo, vida);
    else if(elemento == "Fuego")
        nuevo = new PersonajeFuego(nombre, escudo, vida);
    else
        nuevo = new PersonajeTierra(nombre, escudo, vida);
    return nuevo;
}

void Juego::registrarElemento(string &elementoAgregar){
    cin.ignore();
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
        while(!archivo.eof() && archivo.peek() != EOF){
            procesarDatosPersonaje(archivo, elemento, nombre, escudo, vida, escudoEntero, vidaEntero);
            Dato nuevo = crearPersonaje(elemento, nombre, escudoEntero, vidaEntero);
            diccionario.insertarHoja(nuevo);
        }
    }
}

void Juego::procesarDatosPersonaje(ifstream &archivo, string &elemento, string &nombre, string &escudo, string &vida, int &escudoEntero, int &vidaEntero){
    getline(archivo, elemento, ',');
    getline(archivo, nombre, ',');
    getline(archivo, escudo, ',');
    getline(archivo, vida, '\n');
    nombreMayuscula(elemento);
    nombreMayuscula(nombre);
    escudoEntero = stoi(escudo);
    vidaEntero = stoi(vida);
}

void Juego::asignarPersonaje(int numJugador, Personaje* personaje){
    int tipo = personaje->devolverTipo();
    ControladorPersonaje* controlador;
    switch (tipo)
    {
    case TIPO_AGUA:
        controlador = new ControladorAgua(personaje, &tablero);
        jugadores[numJugador].asignar_controlador(controlador);
        break;
    case TIPO_TIERRA:
        controlador = new ControladorTierra(personaje, &tablero);
        jugadores[numJugador].asignar_controlador(controlador);
        break;
    case TIPO_FUEGO:
        controlador = new ControladorFuego(personaje, &tablero);
        jugadores[numJugador].asignar_controlador(controlador);
        break;
    case TIPO_AIRE:
        controlador = new ControladorAire(personaje, &tablero);
        jugadores[numJugador].asignar_controlador(controlador);
        break;
    }
}

bool Juego::seleccionarPersonaje(int numjugador){
    string nombre;
    Personaje* personaje;
    Nodo* nodo;
    bool personajeSeleccionado = false; 
    cout << "Ingrese el nombre del personaje: ";
    cin >> nombre;
    nodo = diccionario.buscarPersonaje(nombre);
    if(nodo != 0){
        personaje = nodo->obtenerDato();
        asignarPersonaje(numjugador, personaje);
        personajeSeleccionado = true;
    } else {
        cout << "No hay un personaje con ese nombre" << endl;
    }
    return personajeSeleccionado;
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
                mostrarDetalle();
                break;
            case 2:
                mostrarPersonajes();
                break;
            case 3:
                if(seleccionarPersonaje(jug)){ per++;}
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

void Juego::eliminarPersonaje() {
    string eliminar;
    cin.ignore();
    cout << "\tELIMINAR PERSONAJE DE LA LISTA." << endl
         << "Ingrese el nombre del personaje a eliminar: ";
    leerCadena(eliminar);
    diccionario.borrarNodo(eliminar);
}

void Juego::partida(){
    
}
