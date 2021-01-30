#include "personaje_aire.h"
#include <iostream>

PersonajeAire::PersonajeAire(string nombre, int escudo, int vida) : Personaje(nombre, escudo, vida){
    elemento = "Aire";
}

void PersonajeAire::alimentar(){
    std::cout << obtenerNombre() << " al ser de tipo " << obtenerElemento() << " no se alimenta ni recupera energia.\nENERGIA: " << obtenerEnergia() << std::endl;
}