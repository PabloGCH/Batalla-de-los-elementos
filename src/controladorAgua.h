#ifndef CONTROLADORAGUA_H
#define CONTROLADORAGUA_H
#include "controladorPersonaje.h"

class ControladorAgua : public ControladorPersonaje{
    public:
    private:
        void atacar();
        int evaluarDir(Casillero* dir);
};

#endif