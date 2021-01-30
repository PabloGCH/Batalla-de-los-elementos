#include "ABB.h"
#include <iostream>

using namespace std;

ABB::ABB(){
    raiz = nullptr;
}

Nodo* ABB::obtenerRaiz(){
    return this->raiz;
}

void ABB::insertarHoja(Dato &nuevoPersonaje){
    this->raiz = agregarNodo(this->raiz, nuevoPersonaje);
}

Nodo* ABB::agregarNodo(Nodo* actual, Dato &nuevoPersonaje){
    if(!actual){
      actual  = new Nodo(nuevoPersonaje);
    }else if(nuevoPersonaje->obtenerNombre() > actual->obtenerClave()){
        actual->cambiarDerecho(agregarNodo((actual->obtenerDerecho()), nuevoPersonaje));
        (actual->obtenerDerecho())->cambiarPadre(actual);
        this->raiz->cambiarPadre(nullptr);
    }else {
        actual->cambiarIzquierdo(agregarNodo(actual->obtenerIzquierdo(), nuevoPersonaje));
        (actual->obtenerIzquierdo())->cambiarPadre(actual);
        this->raiz->cambiarPadre(nullptr);
    }
    return actual;
}

Nodo* ABB::buscarPersonaje(const string& buscado){
    return consultarPersonaje(this->raiz, buscado);
}

Nodo* ABB::consultarPersonaje(Nodo* actual, const string& buscado){
    if(!actual || (buscado == actual->obtenerClave()))
        return actual;

    if(buscado > actual->obtenerClave())
        return consultarPersonaje(actual->obtenerDerecho(), buscado);

    return consultarPersonaje(actual->obtenerIzquierdo(), buscado);
}

Dato ABB::encontrarMenor() {
    return menor(this->raiz);
}

Dato ABB::menor(Nodo *actual) {
    if(!actual)
        return nullptr;
    else if(!(actual->obtenerIzquierdo()))
        return actual->obtenerDato();
    else
        return menor(actual->obtenerIzquierdo());
}

Dato ABB::encontrarMayor() {
    return mayor(this->raiz);
}

Dato ABB::mayor(Nodo *actual) {
    if(!actual)
        return nullptr;
    else if(!(actual->obtenerDerecho()))
        return actual->obtenerDato();
    else
        return mayor(actual->obtenerDerecho());
}

void ABB::enOrden() {
    imprimirEnOrden(this->raiz);
}

void ABB::imprimirEnOrden(Nodo* actual) {
    if(actual){
        imprimirEnOrden(actual->obtenerIzquierdo());
        std::cout <<  actual->obtenerClave() << std::endl;
        imprimirEnOrden(actual->obtenerDerecho());
    }
}

Dato ABB::encontrarSucesor(string claveActual) {
    Nodo* dato = consultarPersonaje(this->raiz, claveActual);
    if(!dato)
        return nullptr;
    else
        return sucesor(dato);
}

Dato ABB::sucesor(Nodo *actual) {
    if(actual->obtenerDerecho())
        return menor(actual->obtenerDerecho());
    Nodo* sucesor = nullptr;
    Nodo* ancestro = this->raiz;
    while( ancestro != actual){
        if(actual->obtenerClave() < ancestro->obtenerClave()){
            sucesor = ancestro;
            ancestro = ancestro->obtenerIzquierdo();
        }else
            ancestro = ancestro->obtenerDerecho();
    }
    return sucesor->obtenerDato();
}

Dato ABB::encontrarPredecesor(string claveActual) {
    Nodo* dato = consultarPersonaje(this->raiz, claveActual);
    if(!dato)
        return nullptr;
    else
        return predecesor(dato);
}

Dato ABB::predecesor(Nodo *actual) {
    if(actual->obtenerIzquierdo())
        return mayor(actual->obtenerIzquierdo());
    Nodo* sucesor = nullptr;
    Nodo* ancestro = this->raiz;
    while(ancestro != actual){
        if(actual->obtenerClave() > ancestro->obtenerClave()){
            sucesor = ancestro;
            ancestro = ancestro->obtenerDerecho();
        }else
            ancestro = ancestro->obtenerIzquierdo();
    }
    return sucesor->obtenerDato();
}

bool ABB::arbolVacio() {
    return (this->raiz == nullptr);
}

void ABB::borrarNodo(string eliminar){
    if(eliminar == raiz->obtenerClave())
        eliminarRaiz(eliminar);
    else
        this->raiz = eliminarNodo(this->raiz, eliminar);
}

Nodo* ABB::eliminarNodo(Nodo* actual, string eliminar){
    if(!actual)
        return nullptr;
    if(actual->obtenerClave() == eliminar){
        if(actual->esHoja()){
            delete actual;
        }else if(actual->soloHijoDerecho()){
            actual->obtenerDerecho()->cambiarPadre(actual->obtenerPadre());
            Nodo* aux = actual;
            actual = actual->obtenerDerecho();
            delete aux;
        }else if(actual->soloHijoIzquierdo()){
            actual->obtenerIzquierdo()->cambiarPadre(actual->obtenerPadre());
            Nodo* aux = actual;
            actual = actual->obtenerIzquierdo();
            delete aux;
        }else{
            Nodo* aux;
            Nodo* sucesor = consultarPersonaje(actual, this->sucesor(actual)->obtenerNombre());
            sucesor->cambiarIzquierdo(actual->obtenerIzquierdo(), sucesor);
            sucesor->cambiarPadre(actual->obtenerPadre());
            aux = actual;
            actual = sucesor;// Aca pierdo a gimeno
            delete aux;
            actual->cambiarDerecho(eliminarNodo(actual->obtenerDerecho(),sucesor->obtenerClave()));
        }
    }else if(actual->obtenerClave() < eliminar)
        actual->cambiarDerecho(eliminarNodo(actual->obtenerDerecho(), eliminar));

    else
        actual->cambiarIzquierdo(eliminarNodo(actual->obtenerIzquierdo(), eliminar));
    return actual;
}

void ABB::eliminarRaiz(string eliminar) {
    if(raiz->esHoja())
        delete raiz;
    else if(raiz->soloHijoDerecho()){
        Nodo* eliminarN = raiz;
        raiz = raiz->obtenerDerecho();
        raiz->cambiarPadre(nullptr);
        delete eliminarN;
    }else if(raiz->soloHijoIzquierdo()){
        Nodo* eliminarN = raiz;
        raiz = raiz->obtenerIzquierdo();
        raiz->cambiarPadre(nullptr);
        delete eliminarN;
    }else{
        Nodo* eliminarN = raiz;
        Nodo* predecesor = consultarPersonaje(raiz, this->predecesor(raiz)->obtenerNombre());
        raiz = predecesor;
        if(predecesor->esHoja()){
            (predecesor->obtenerPadre())->cambiarDerecho(nullptr);
            raiz->cambiarDerecho(eliminarN->obtenerDerecho(), raiz);
            raiz->cambiarIzquierdo(eliminarN->obtenerIzquierdo(), raiz);
        }else{
            raiz->cambiarDerecho(eliminarN->obtenerDerecho(), raiz);
        }
        raiz->cambiarPadre(nullptr);
        delete eliminarN;
    }
}

ABB::~ABB(){
    borrarArbol();
}

void ABB::borrarArbol() {
    borrarTodo(this->raiz);
}

void ABB::borrarTodo(Nodo* actual) {
    if(!actual)
        return;
    borrarTodo(actual->obtenerIzquierdo());
    borrarTodo(actual->obtenerDerecho());
    delete actual;

}