#ifndef CONTROLADORTIERRA_H
#define CONTROLADORTIERRA_H
#include "controladorPersonaje.h"

class ControladorTierra : public ControladorPersonaje{
    private:
    public:
        void atacar();
        int evaluarDir(Casillero* dir);
        ControladorTierra(Personaje* personaje, Tablero* tablero);
};

#endif