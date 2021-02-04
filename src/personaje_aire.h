#ifndef PERSONAJE_AIRE_H_INCLUDED
#define PERSONAJE_AIRE_H_INCLUDED

#include "personaje.h"

class PersonajeAire: public Personaje{

    // Atributos.

public:
    // Metodos.

    // Constructor.
    // PRE: -
    // POS: Crea un personaje de tipo Aire con herencia en la clase 'Personaje'. Con un nombre, escudo y vida asignado por el usuario, un valor de energia generado aleatoriamente y 'elemento' = Aire.
    PersonajeAire(string nombre, int escudo, int vida);


    // PRE: -
    // POS: No realiza ninguna accion ya que 'Aire' no se alimenta, pero hereda de 'Personaje' el metodo virtual 'alimentar'.
    void alimentar();

};

#endif