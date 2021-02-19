#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED

#include <string>

using namespace std;

const int MAX_ENERGIA = 20;
const int MAX_VIDA = 100;

enum tipo{
    TIPO_AGUA = 1,
    TIPO_TIERRA = 2,
    TIPO_AIRE = 3,
    TIPO_FUEGO = 4,
};

class Personaje{

protected:

    //Atributos.
    string nombre;
    int escudo;
    int vida;
    int energia;
    int jugador;
    bool seleccionado;


public:
    //Metodos.

    Personaje(string nombre, int escudo, int vida);

    // PRE: recibe un numero entero
    // POS: asigna el entero recibido a atributo jugador
    void asignarJugador(int jug);

    //POS: retorna el jugador
    int devolverJugador();

    // Metodo abstracto. Cada clase hija debe implementar su metodo alimentar.
    virtual void alimentar() = 0;

    //Metodo abstracto. Cada clase hija debe implementar su metodo recibirAtaque
    virtual void recibirAtaque(string tipo, int casosTierra) = 0;

    //Metodo abstracto. Cada clase hija debe implementar su metodo defender
    virtual bool defender() = 0;

    //POS: Retorna un entero que indica el tipo
    virtual int devolverTipo() = 0;

    // POS: Retorna true si el personaje esta seleccionado
    bool estaSeleccionado();
    // POS: Asigna true a asignado
    void seleccionar();
    
    // PRE: -
    // POS: Retorna el nombre el personaje.
    string obtenerNombre();

    // PRE: -
    // POS: Rerorna el valor del escudo del personaje.
    int obtenerEscudo();

    // PRE: -
    // POS: Retorna el valor de vida del personaje.
    int obtenerVida();

    // PRE: -
    // POS: Retorna el valor de energia del personaje.
    int obtenerEnergia();

    //PRE: -
    //POS: Resta la cantidad de energia ingresada(esto se determinara al momento de implementarla, ya que será para un ataque, defensa o movimiento)
    void restarEnergia(int puntos);

    // PRE: -
    // POS: Muestra por pantalla los atributos del personaje en fila.
    void mostrarAtributos();
    
    //POS: El personaje recupera 10 de vida
    void curar();
    
    //Pos: disminuye el escudo en 2 unidades
    void bajar_escudo();
    
    // POS: recupera 5 de energia
    void recuperarEnergia();

    //Pos: el personaje pierde 5 de vida
    void perder_vida();

    virtual ~Personaje();

private:

    //Pre: -
    //Post: Inicializa el atributo 'energia' en un valor aleatorio entre 0 y 20.
    void asignarEnergia();

};

#endif
