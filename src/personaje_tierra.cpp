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

void PersonajeTierra::recibirAtaque(string tipo) {
    int danio = 0;
    if (obtenerEscudo() > 2){
        if (tipo == "agua"){
            danio = 20 - (80 * 20 / 100);
        }
        else if (tipo == "aire"){
            danio = 15 - (80 * 15 / 100);
        }
        else if (tipo == "fuego"){
            danio = 30 - (80 * 30 / 100);
        }
        else if (tipo == "tierra"){
            //todavia no hace nada
        }

    }

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
        //por ahora no hace nada;
    }
    vida -= danio;
    cout<<"El personaje "<< obtenerNombre() <<" recibió un daño de "<< danio <<endl;
    cout<<"VIDA: "<< obtenerVida() <<endl;
}


void PersonajeTierra::defender(){
    if (obtenerEnergia() >= 5){
        energia -= 5;
        escudo += 2;
        cout <<"El personaje "<< obtenerNombre()  <<" aumentó su escudo "<< endl;
        cout <<"ESCUDO: "<< obtenerEscudo() << endl;
    }
    else{
        cout <<"El personaje "<< obtenerNombre() <<" no cuenta con la energia necesaria para defenderse"<< endl;
    }
}