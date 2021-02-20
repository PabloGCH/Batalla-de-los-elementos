#include "personaje_agua.h"
#include <iostream>

PersonajeAgua::PersonajeAgua(string nombre, int escudo, int vida) : Personaje(nombre, escudo, vida){
    vecesAlimentado = 0;
}

bool PersonajeAgua::alimentar() {
    int energiaInicial;
    int energiaFinal;
    if(vecesAlimentado == LIMITE_ALIMENTACION){
        std::cout << "ATENCION!!!. " << obtenerNombre() << " no puede alimentarse mas.\nENERGIA: " << obtenerEnergia() << std::endl;
        return false;
    }
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
        return true;
    }else{
        std::cout << obtenerNombre() << " llego al maximo posible de energia.\nENERGIA: " << obtenerEnergia() << std::endl;
        return false;
    }

}

void PersonajeAgua::recibirAtaque(string tipo, int casosTierra) {
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
        switch(casosTierra){
            case 1: danio = 50 - (obtenerEscudo() * 500 / 100);
                break;
            case 2: danio = 40 - (obtenerEscudo() * 400 / 100);
                break;
            case 3: danio = 30 - (obtenerEscudo() * 300 / 100);
                break;
        }
    }
    vida -= danio;
    cout<<"El personaje "<< obtenerNombre() <<" recibió un daño de "<< danio <<endl;
    cout<<"VIDA: "<< obtenerVida() <<endl;
}

bool PersonajeAgua::defender(){
    if (obtenerEnergia() >= DEFENSA_AGUA && obtenerVida() <= MAX_VIDA){
        restarEnergia(DEFENSA_AGUA);
        if (obtenerVida() + 50 > MAX_VIDA){
            vida = MAX_VIDA;
        }
        else{
            vida += 50;
        }
        cout << "El personaje " << obtenerNombre() << " utilizó aumentó su vida" << endl;
        cout << "VIDA: "<< obtenerVida()  << endl;
        return true;
    }
    else if (obtenerEnergia() < DEFENSA_AGUA){
        cout << "El personaje " << obtenerNombre() << " no cuenta con la energia necesaria para defenderse" << endl;
        return false;
    }
    else{
        cout << "El personaje " << obtenerNombre ()<< " ya tiene su vida al máximo" << endl;
        return false;
    }
}

int PersonajeAgua::devolverTipo(){
    return TIPO_AGUA;
}

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
void PersonajeAgua::asignarVecesAlimentado(int veces){
    vecesAlimentado = veces;
}

>>>>>>> 5f2968f1013928c84bb219bef5d28d8a85c0733d
int PersonajeAgua::obtenerAlimentos() {
    return vecesAlimentado;
=======
void PersonajeAgua::asignarVecesAlimentado(int veces){
    vecesAlimentado = veces;
>>>>>>> 957b037... Varios cambios para reutilizar codigo de ABB, lo probe varias veces y no se rompio nada, pero habria que probar mas
=======
void PersonajeAgua::asignarVecesAlimentado(int veces){
    vecesAlimentado = veces;
}

int PersonajeAgua::obtenerAlimentos() {
    return vecesAlimentado;
>>>>>>> 03c2050... Solucionados algunos errores despues del merge
=======
void PersonajeAgua::asignarVecesAlimentado(int veces){
    vecesAlimentado = veces;
>>>>>>> parent of c7fd1b0... Merge branch 'main' of https://github.com/PabloGCH/tp3Algo into main
}