#include "personaje_aire.h"
#include <iostream>

PersonajeAire::PersonajeAire(string nombre, int escudo, int vida) : Personaje(nombre, escudo, vida){

}

void PersonajeAire::alimentar(){
    std::cout << obtenerNombre() << " no se alimenta.\nENERGIA: " << obtenerEnergia() << std::endl;
}

void PersonajeAire::recibirAtaque(string tipo, int casosTierra) {

    int danio = 0;
    if (tipo == "agua"){
        danio = 20 - (obtenerEscudo() * 200 / 100);
    }
    else if (tipo == "aire"){
        danio = 15 - (obtenerEscudo() * 150 / 100);
    }
    else if (tipo == "fuego"){
        danio = 30 - (obtenerEscudo() * 300 / 100);
    }
    else if (tipo == "tierra"){
        danio = 10 - (obtenerEscudo() * 100 / 100);
    }
    vida -= danio;
    cout << "El personaje "<< obtenerNombre() <<" recibió un daño de " << danio << endl;
    cout <<"VIDA: "<< obtenerVida() << endl ;
}

bool PersonajeAire::defender() {
    if (obtenerEnergia() >= 15){
        energia -= 15;
        cout<<"El personaje "<< obtenerNombre() <<" cambió su posición"<<endl;
        return true;
    }
    else{
        cout<<"El personaje "<< obtenerNombre() <<" no cuenta con la energía necesaria para defenderse"<<endl;
        return false;
    }
}
