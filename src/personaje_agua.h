#ifndef ESCRITORIO_PERSONAJE_AGUA_H
#define ESCRITORIO_PERSONAJE_AGUA_H

#include "personaje.h"

const int ALIMENTO_AGUA = 10;
const int LIMITE_ALIMENTACION = 3;

class PersonajeAgua : public Personaje{

private:
    // Atributos.
    int vecesAlimentado;

public:
    // Metodos.

    // Constructor.
    // PRE: -
    // POS: Crea un personaje de tipo Agua con herencia en la clase 'Personaje'. Con un nombre, escudo y vida asignado por el usuario, un valor de energia generado aleatoriamente, 'vecesAlimentado = 0 y 'elemento' = Agua.
    PersonajeAgua(string nombre, int escudo, int vida);

    // PRE: -
    // POS: aumenta el valor del atributo 'energia' en 10 puntos si 'energia' <= 10 ó deja 'energia' = 20 si 'energia' > 10.
    void alimentar();


    //PRE: -
    //POS: resta vida
    void recibirAtaque(string tipo);

    //PRE: -
    //POS: energia - 12 & vida + 50 (los otros personajes del jugador tambien recibiran 10 de vida)
    bool defender();

};


#endif //ESCRITORIO_PERSONAJE_AGUA_H
