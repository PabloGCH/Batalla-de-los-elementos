#include "personaje_tierra.h"
#include <iostream>

PersonajeTierra::PersonajeTierra(string nombre, int escudo, int vida) : Personaje(nombre, escudo, vida) {

}

void PersonajeTierra::alimentar() {
    int energiaInicial = obtenerEnergia();
    int energiaFinal;
    if(obtenerEnergia() == MAX_ENERGIA){
        std::cout << obtenerNombre() << " no puede recuperar mas energia.\nENERGIA: " << energia << endl;
    }else{

        if(obtenerEnergia() + ALIMENTO_TIERRA > MAX_ENERGIA){
            energia = MAX_ENERGIA;
            energiaFinal = obtenerEnergia();
        }
        else{
            energia += ALIMENTO_TIERRA;
            energiaFinal = obtenerEnergia();
        }
        std::cout << obtenerNombre() << " se alimenta de hierbas. Recuperó: " << energiaFinal - energiaInicial << " puntos de energia.\nENERGIA: " << obtenerEnergia() << std::endl;
    }
}