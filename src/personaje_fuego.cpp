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


bool PersonajeFuego::alimentar() {
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
        std::cout << obtenerNombre() << " Recuperó: " << energiaFinal - energiaInicial  << " puntos de energía.\nENERGIA: " << obtenerEnergia() << std::endl;
        return true;
    }else{
        std::cout << obtenerNombre() << " no tiene suficiente madera para alimentarse. Su vida es: " << obtenerVida() << " y su energía es: "<< obtenerEnergia() <<std::endl;
        return false;
    }
}

bool PersonajeFuego::tieneMadera() {
    return (cantMadera > 0);
}

void PersonajeFuego::recibirAtaque(string tipo, int casosTierra) {
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
        switch(casosTierra){
            case 1: danio = 30 - (obtenerEscudo() * 300 / 100);
                break;
            case 2: danio = 20 - (obtenerEscudo() * 200 / 100);
                break;
            case 3: danio = 10 - (obtenerEscudo() * 100 / 100);
                break;
        }
    }
    vida -= danio;
    cout<<"El personaje "<< obtenerNombre() <<" recibió un daño de "<< danio <<endl;
    cout<<"VIDA: "<< obtenerVida()<<endl;

}

bool PersonajeFuego::defender(){
    if (obtenerEnergia() >= 10){
        energia -= 10;
        vida += 10;
        cout<<"El personaje "<< obtenerNombre() <<" aumentó su vida"<<endl;
        cout<<"VIDA: "<< obtenerVida() <<endl;
        return true;
    }
    else{
        cout<<"El personaje "<< obtenerNombre() <<" no cuenta con la energía suficiente para utilizar su defensa"<<endl;
        return false;
    }
}

int PersonajeFuego::devolverTipo(){
    return TIPO_FUEGO;
}