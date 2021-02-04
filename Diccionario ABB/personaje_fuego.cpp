#include "personaje_fuego.h"
#include <iostream>

PersonajeFuego::PersonajeFuego(string nombre, int escudo, int vida): Personaje(nombre, escudo, vida) {
    cantMadera = rand() % 5;
}

void PersonajeFuego::recargarVida(){
    if(obtenerVida() + ALIMENTO_FUEGO > MAX_VIDA)
        vida = MAX_VIDA;
    else
        vida += ALIMENTO_FUEGO;
    cantMadera--;
}

void PersonajeFuego::alimentar() {
    int vidaInicial = obtenerVida();
    int vidaFinal;
    if(tieneMadera()){
        recargarVida();
        vidaFinal = obtenerVida();
        std::cout << obtenerNombre() << " se alimenta de madera. Recuperó: " << vidaFinal - vidaInicial << " puntos de vida.\nVIDA: " << obtenerVida() << std::endl;
    }else{
        std::cout << obtenerNombre() << " no tiene suficiente madera para alimentarse. Su vida es: " << obtenerVida() << std::endl;
    }

}

bool PersonajeFuego::tieneMadera() {
    return (cantMadera > 0);
}