#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "../headers/juego.h"
using namespace std;

// hay que permitir que main reciba argumentos para poder usar SDL
int main(){
    Juego nuevo;
    nuevo.iniciar();
    return 0;
}