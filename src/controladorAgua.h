#ifndef CONTROLADORAGUA_H
#define CONTROLADORAGUA_H
#include "controladorPersonaje.h"

class ControladorAgua : public ControladorPersonaje{
    private:
        //PRE: -
        //POS: devuelve un bool dependiendo de si existe un personaje oara atacar o no
        bool comprobarPosicon(int posicionAtacada[2]);
    public:
        bool defensa();
        void atacar(ControladorPersonaje** ControladoresEnemigo);
        int evaluarDir(Casillero* dir);
        ControladorAgua(Personaje* personaje, Tablero* tablero);
        void defensa();
};

#endif
