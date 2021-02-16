#ifndef CONTROLADORFUEGO_H
#define CONTROLADORFUEGO_H
#include "controladorPersonaje.h"

class ControladorFuego : public ControladorPersonaje{
    private:
    public:

        // PRE: ControladoresEnemigos debe tener 3 controladorPersonajes*
        // POS: Ataca a los personajes* de cada controlador que este en el rango de ataque
        //      ( misma fila, fila de arriba y  fila de abajo)
        void atacar(ControladorPersonaje** ControladoresEnemigos);

        bool defensa();
        int evaluarDir(Casillero* dir);

        // Constructor
        ControladorFuego(Personaje* personaje, Tablero* tablero);
};

#endif