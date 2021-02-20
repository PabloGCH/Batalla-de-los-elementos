#include "personaje_tierra.h"
#include <iostream>

PersonajeTierra::PersonajeTierra(string nombre, int escudo, int vida) : Personaje(nombre, escudo, vida) {

}

bool PersonajeTierra::alimentar() {
    int energiaInicial = obtenerEnergia();
    int energiaFinal;
    if(obtenerEnergia() == MAX_ENERGIA){
        std::cout << obtenerNombre() << " no puede recuperar mas energia.\nENERGIA: " << energia << endl;
        return false;
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
        return true;
    }
}

void PersonajeTierra::recibirAtaque(string tipo, int casosTierra) {
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
            switch(casosTierra){
                case 1: danio = 30 - (80 * 300 / 100);
                    break;
                case 2: danio = 20 - (80 * 200 / 100);
                    break;
                case 3: danio = 10 - (80 * 100 / 100);
                    break;
            }
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
    cout<<"VIDA: "<< obtenerVida() <<endl;
}


bool PersonajeTierra::defender(){
    if (obtenerEnergia() >= 5){
        energia -= 5;
        escudo += 2;
        cout <<"El personaje "<< obtenerNombre()  <<" aumentó su escudo " << endl;
        cout <<"ESCUDO: "<< obtenerEscudo() << endl;
        estaDefendiendo = true;
        return true;
    }
    else{
        cout <<"El personaje "<< obtenerNombre() <<" no cuenta con la energia necesaria para defenderse" << endl;
        return false;
    }
}

int PersonajeTierra::devolverTipo(){
    return TIPO_TIERRA;
}

int PersonajeTierra::obtenerAlimentos() {
    return 0;
}

void PersonajeTierra::asignarAlimentos(int cant){}