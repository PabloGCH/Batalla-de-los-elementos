#include "personaje_aire.h"
#include <iostream>

PersonajeAire::PersonajeAire(string nombre, int escudo, int vida) : Personaje(nombre, escudo, vida){

}

void PersonajeAire::alimentar(){
    std::cout << obtenerNombre() << " no se alimenta ni recupera energia.\nENERGIA: " << obtenerEnergia() << std::endl;
}