#ifndef CONTROLADORAIRE_H
#define CONTROLADORAIRE_H
#include "controladorPersonaje.h"

class ControladorAire : public ControladorPersonaje{
    private:
    public:

    // PRE: ControladoresEnemigos debe tener 3 controladorPersonajes*
    // POS: Ataca a los personajes* de cada controlador que este en tablero
        bool atacar(ControladorPersonaje** ControladoresEnemigo);
        int evaluarDir(Casillero* dir);
        // Constructor
        ControladorAire(Personaje* personaje, Tablero* tablero);
        bool defensa();
};

#endif
