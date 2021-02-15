#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED

#include <string>

using namespace std;

const int MAX_ENERGIA = 20;
const int MAX_VIDA = 100;

enum jugador{
    JUGADOR1 = 1,
    JUGADOR2 = 2,
};

class Personaje{

protected:

    //Atributos.
    string nombre;
    int jugador;
    int escudo;
    int vida;
    int energia;
    bool selecionado;


public:
    //Metodos.

    Personaje(string nombre, int escudo, int vida);

    // Metodo abstracto. Cada clase hija debe implementar su metodo alimentar.
    virtual void alimentar() = 0;

    //Metodo abstracto. Cada clase hija debe implementar su metodo recibirAtaque
    virtual void recibirAtaque(string tipo, int casosTierra) = 0;

    //Metodo abstracto. Cada clase hija debe implementar su metodo defender
    virtual bool defender() = 0;

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

    //PRE: recibe un entero que representa al jugador, debe ser 1 o 2
    //POS: guarda el valor en la variable jugador
    void asignarJugador(int per);

    // PRE: -
    // POS: Devuelve 1 o 2 dependiendo de a que jugador esta asignado el personaje.
    int obtenerJugador();

    virtual ~Personaje(){};

private:

    //Pre: -
    //Post: Inicializa el atributo 'energia' en un valor aleatorio entre 0 y 20.
    void asignarEnergia();

};

#endif