#ifndef ESCRITORIO_PERSONAJE_FUEGO_H
#define ESCRITORIO_PERSONAJE_FUEGO_H

#include "personaje.h"

const int ALIMENTO_FUEGO = 15;

class PersonajeFuego : public Personaje {
private:

    int cantMadera;

public:
    // Metodos.

    // Constructor.
    // PRE: -
    // POS: Crea un personaje de tipo Fuego con herencia en la clase 'Personaje'. Con un nombre, escudo y vida asignado por el usuario y un valor de energia, cantMadera generados aleatoriamente y 'elemento' = Fuego.
    PersonajeFuego(string nombre, int escudo, int vida);

    // PRE: -
    // POS: Si tiene madera le recarga la vida el valor que determina el metodo 'recargarVida', si no tiene madera no hace nada.
    void alimentar();

private:

    // PRE: -
    // POS: Retorna 'True' si 'cantMadera' > 0, 'False' si es = 0 o menor.
    bool tieneMadera();

    // PRE: -
    // POS: le aumenta 15 puntos de vida si 'vida' <= 85, sino aumenta la vida a 100.
    void recargarVida();

};


#endif //ESCRITORIO_PERSONAJE_FUEGO_H
