#ifndef CONTROLADORAIRE_H
#define CONTROLADORAIRE_H
#include "controladorPersonaje.h"

class ControladorAire : public ControladorPersonaje{
    private:
    public:
        void atacar(ControladorPersonaje* personajesEnemigos);
        int evaluarDir(Casillero* dir);
        ControladorAire(Personaje* personaje, Tablero* tablero);
};

#endif