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

void PersonajeFuego::recargarEnergia() {
    if(obtenerEnergia() + ALIMENTO_FUEGO_ENERGIA > MAX_ENERGIA){
        energia = MAX_ENERGIA;
    }
    else{
        energia += ALIMENTO_FUEGO_ENERGIA;
    }
}


void PersonajeFuego::alimentar() {
    int vidaInicial = obtenerVida();
    int vidaFinal;
    int energiaInicial = obtenerEnergia();
    int energiaFinal;
    if(tieneMadera()){
        recargarVida();
        vidaFinal = obtenerVida();
        recargarEnergia();
        energiaFinal = obtenerEnergia();
        std::cout << obtenerNombre() << " se alimenta de madera. Recuperó: " << vidaFinal - vidaInicial << " puntos de vida.\nVIDA: " << obtenerVida() << std::endl;
        std::cout << obtenerNombre() << " Recuperó: " << energiaInicial - energiaFinal << " puntos de energía.\nENERGIA: " << obtenerEnergia() << std::endl;
    }else{
        std::cout << obtenerNombre() << " no tiene suficiente madera para alimentarse. Su vida es: " << obtenerVida() << " y su energía es: "<< obtenerEnergia() <<std::endl;
    }
}

bool PersonajeFuego::tieneMadera() {
    return (cantMadera > 0);
}

void PersonajeFuego::recibirAtaque(string tipo) {
    int danio = 0;
    if (tipo == "agua"){
        danio = 30 - (obtenerEscudo() * 300 / 100);
    }
    else if (tipo == "aire"){
        danio = 15 - (obtenerEscudo() * 150 / 100);
    }
    else if (tipo == "fuego"){
        danio = 20 - (obtenerEscudo() * 200 / 100);
    }
    else if (tipo == "tierra"){
        //por ahora no hace nada;
    }
    vida -= danio;
    cout<<"El personaje "<< obtenerNombre() <<" recibió un daño de "<< danio <<endl;
    cout<<"VIDA: "<< obtenerVida()<<endl;

}

void PersonajeFuego::defender(){
    if (obtenerEnergia() >= 10){
        energia -= 10;
        vida += 10;
        cout<<"El personaje "<< obtenerNombre() <<" aumentó su vida"<<endl;
        cout<<"VIDA: "<< obtenerVida() <<endl;
    }
    else{
        cout<<"El personaje "<< obtenerNombre() <<" no cuenta con la energía suficiente para utilizar su defensa"<<endl;
    }
}