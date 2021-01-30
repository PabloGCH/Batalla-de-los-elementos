#ifndef ESCRITORIO_PERSONAJE_TIERRA_H
#define ESCRITORIO_PERSONAJE_TIERRA_H

#include "personaje.h"

const int ALIMENTO_TIERRA = 8;

class PersonajeTierra : public Personaje {

    // Atributos.

public:
    // Metodos.

    // Constructor.
    // PRE: -
    // POS: Crea un personaje de tipo Tierra con herencia en la clase 'Personaje'.
    PersonajeTierra(string nombre, int escudo, int vida);

    // PRE: -
    // POS: Si 'energia' <= 12 -> 'energia' + 8. sino 'energia' = 20.
    void alimentar();
};

#endif //ESCRITORIO_PERSONAJE_TIERRA_H
