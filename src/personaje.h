#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED

#include <string>

using namespace std;

const int MAX_ENERGIA = 20;
const int MAX_VIDA = 100;

class Personaje{

protected:

    //Atributos.
    string nombre;
    int escudo;
    int vida;
    int energia;

public:
    //Metodos.

    Personaje(string nombre, int escudo, int vida);

    // Metodo abstracto. Cada clase hija debe implementar su metodo alimentar.
    virtual void alimentar() = 0;

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

    // PRE: -
    // POS: Muestra por pantalla los atributos del personaje en fila.
    void mostrarAtributos();

    virtual ~Personaje(){};

private:

    //Pre: -
    //Post: Inicializa el atributo 'energia' en un valor aleatorio entre 0 y 20.
    void asignarEnergia();

};

#endif