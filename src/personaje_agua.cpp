#include "personaje_agua.h"
#include <iostream>

PersonajeAgua::PersonajeAgua(string nombre, int escudo, int vida) : Personaje(nombre, escudo, vida){
    vecesAlimentado = 0;
}

void PersonajeAgua::alimentar() {
    int energiaInicial;
    int energiaFinal;
    if(vecesAlimentado == LIMITE_ALIMENTACION)
        std::cout << "ATENCION!!!. " << obtenerNombre() << " no puede alimentarse mas.\nENERGIA: " << obtenerEnergia() << std::endl;
    if(vecesAlimentado < LIMITE_ALIMENTACION && energia < MAX_ENERGIA) {
        energiaInicial = obtenerEnergia();
        if(energia + ALIMENTO_AGUA > MAX_ENERGIA){
            energia = MAX_ENERGIA;
            energiaFinal = obtenerEnergia();
        }else{
            energia += ALIMENTO_AGUA;
            energiaFinal = obtenerEnergia();
        }
        vecesAlimentado++;
        std::cout << obtenerNombre() << " se alimenta de Plancton. Recuperó: " << energiaFinal - energiaInicial << " puntos de energia.\nENERGIA: " << obtenerEnergia() << std::endl;
    }else{
        std::cout << obtenerNombre() << " llego al maximo posible de energia.\nENERGIA: " << obtenerEnergia() << std::endl;
    }

}
