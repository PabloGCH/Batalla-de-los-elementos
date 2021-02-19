#include "juego.h"

Juego::Juego(){
    ifstream archivo("../res/personajes.csv");
    for(int i = 0; i < 2; i++){
        jugadores[i].asignarTablero(&tablero);
    }
    if(archivo.is_open()){
        procesarArchivo(archivo);
        archivo.close();
    } else {
        cout << "fallo al abrir archivo de personajes";
    }
    jugadores[0].asignar_rival(&jugadores[1]);
    jugadores[1].asignar_rival(&jugadores[0]);
}

void Juego::iniciar(){
    // si hay partida guardada

    // si no hay partida guardada
    opcionesPersonaje();
}

char Juego::recibirOpcion(char maxOpciones){
    char opcion;
    bool salir = false;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(opcion < '1' || opcion > maxOpciones){
        cout << "Ingrese una opcion valida: ";
        cin >> opcion;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
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
    char opcion;
    while(!salir){
        imprimirOpcionesPersonajes();
        opcion = recibirOpcion('6');
        switch (opcion)
        {
        case '1':
            agregarPersonaje();
            break;
        case '2':
            eliminarPersonaje();
            break;
        case '3':
            mostrarPersonajes();
            break;
        case '4':
            mostrarDetalle();
            break;
        case '5':
            comenzarJuego();
            salir = true;
            break;
        case '6':
            salir = true;
            break;
        }
        cin.ignore();
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
    personaje->seleccionar();
}

bool Juego::seleccionarPersonaje(int numjugador){
    string nombre;
    Personaje* personaje;
    Nodo* nodo;
    bool personajeSeleccionado = false; 
    cout << "Ingrese el nombre del personaje: ";
    cin >> nombre;
    nombreMayuscula(nombre);
    nodo = diccionario.buscarPersonaje(nombre);
    if(nodo != 0){
        personaje = nodo->obtenerDato();
        if(personaje->estaSeleccionado() == false){
            asignarPersonaje(numjugador, personaje);
            personaje->asignarJugador(numjugador + 1);
            personajeSeleccionado = true;
        }
        else{
            cout << "Ese personaje ya fue seleccionado" << endl;
        }
    } else {
        cout << "No hay un personaje con ese nombre" << endl;
    }
    return personajeSeleccionado;
}

void Juego::comenzarJuego(){
    bool salir = false;
    char opcion;
    int per = 0;
    int jug = 0;
    while(!salir && jug < 2){
        while(!salir && per < 3){
            imprimirOpcionesComenzar();
            cout << endl << "Jugador " << jug + 1 << endl;
            opcion = recibirOpcion('4');
            switch (opcion)
            {
            case '1':
                mostrarDetalle();
                break;
            case '2':
                mostrarPersonajes();
                break;
            case '3':
                if(seleccionarPersonaje(jug)){ per++;}
                break;
            case '4':
                salir = true;
                break;
            }
        }
        per = 0;
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

int Juego::finPartida(){
    int ganador = 0;
    int personajesPerdidos;
    for(int i = 0; i < 2; i++){
        personajesPerdidos = 0;
        ControladorPersonaje** controladores = jugadores[i].devolverControladores();
        for(int j = 0; j < 3; j++){
            if(controladores[j]->devolverPersonaje() == 0){
                personajesPerdidos++;
            }
        }
        if(personajesPerdidos == 3){
            if(i == 0){
                ganador = 2;
            } else if(i == 1){
                ganador = 1;
            }
        }
    }
    return ganador;
}
void Juego::ubicarPersonajes(int jugador){
    int ubicacion[2];
    ControladorPersonaje** controladores = jugadores[jugador].devolverControladores();
    cout << "Ubicando los personajes del jugador: " << endl;
    for (int i = 0; i < 3 ; i++){
        tablero.printBoard();
        bool ubicar = false;
        while ( !ubicar ) {
            cout << "Ingrese la ubicacion donde iniciara: " << controladores[i]->devolverPersonaje()->obtenerNombre() << endl;
            cout << "Fila: " ;
            cin >> ubicacion[0];
            cout << "" << endl;
            while (ubicacion[0] > 8 || ubicacion[0] < 1  ){
                cout << "Ingrese la ubicacion donde iniciara: " << endl;
                cout << "Fila: " ;
                cin >> ubicacion[0];
                cout << "" << endl;
            }
            cout << "Columna: ";
            cin >> ubicacion[1];
            cout << "" << endl;
            while (ubicacion[1] > 8 || ubicacion[1] < 1  ){
                cout << "Ingrese la ubicacion donde iniciara: " << endl;
                cout << "Fila: " ;
                cin >> ubicacion[1];
                cout << "" << endl;
            }
            ubicar = controladores[i]->ubicarPersonaje(ubicacion);
        }
    }
}

void Juego::partida() {
    int actual = rand() % 2;
    int segundo;
    int terminar = 0;
    int opcion = 0;
    bool guardado = false;
    if(actual == 0){
        segundo = 1;
    }
    else{
        segundo = 0;
    }
    cout << "Comenzará el jugador " << actual + 1 << endl;
    ubicarPersonajes(actual);
    ubicarPersonajes(segundo);
    while (terminar == 0) {
        //preguntar guardado jugador 1
        if (guardado){
            //guardar
            terminar = 3;
        }
        else{
            jugadores[actual].turno(actual);
            //jugador2 preguntar guardado
            if (guardado){
                terminar = 3;
            }
            else{
                jugadores[segundo].turno(segundo);
            }
        }
        terminar = finPartida();
    }
    if(terminar = 1){
        cout << endl << endl << "EL GANADOR ES EL JUGADOR 1";
    }
    if(terminar = 2){
        cout << endl << endl << "EL GANADOR ES EL JUGADOR 2";
    }
}