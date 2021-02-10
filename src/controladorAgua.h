#ifndef CONTROLADORAGUA_H
#define CONTROLADORAGUA_H
#include "controladorPersonaje.h"

class ControladorAgua : public ControladorPersonaje{
    private:
    public:
        void atacar();
        int evaluarDir(Casillero* dir);
        ControladorAgua(Personaje* personaje, Tablero* tablero);
};

#endif