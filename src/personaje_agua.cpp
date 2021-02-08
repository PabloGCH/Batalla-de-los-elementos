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

void PersonajeAgua::recibirAtaque(string tipo) {
    int danio;
    if (tipo == "agua"){
        danio = 20 - (obtenerEscudo() * 200 / 100);
    }
    else if (tipo == "aire"){
        danio = 15 - (obtenerEscudo() * 150 / 100);
    }
    else if (tipo == "fuego"){
        danio = 10 - (obtenerEscudo() * 100 / 100);
    }
    else if (tipo == "tierra"){
        //todavia no hace nada;
    }
    vida -= danio;
    cout<<"El personaje "<< obtenerNombre() <<" recibió un daño de "<< danio <<endl;
    cout<<"VIDA: "<< obtenerVida() <<endl;
}

void PersonajeAgua::defender(){
    if (obtenerEnergia() >= 12){
        energia -= 12;
        vida += 50;
        cout<<"El personaje "<< obtenerNombre() <<" utilizó aumentó su vida"<<endl;
        cout<< "VIDA: "<< obtenerVida()  <<endl;
    }
    else{
        cout<<"El personaje "<< obtenerNombre() << "no cuenta con la energia necesaria para defenderse"<<endl;
    }
}
