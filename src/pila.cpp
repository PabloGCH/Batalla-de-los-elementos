#include "pila.h"

Pila::Pila(){
     ultimo = NULL;
}
void Pila::agregar(Dato d) {

    nodo* nuevo = new nodo;
    nuevo -> dato = d;
    nuevo -> siguiente = ultimo;
    ultimo = nuevo;
}

void Pila::eliminar(){
    if(ultimo != NULL)
    {
        nodo* temporal = ultimo;
        ultimo = ultimo -> siguiente;
        delete temporal;
    }
}

void Pila::mostrarPila()
{
    nodo* temporal = ultimo;
    while(temporal != NULL)
    {
        cout << temporal -> dato << endl;
        temporal = temporal -> siguiente;
    }
}

Dato Pila::consulta()
{
    Dato valor;
    if(ultimo != 0){
        nodo* temporal = ultimo;
        valor = temporal -> dato;
    } else{
        valor = finPila;
    }
    return valor;
}


Pila::~Pila()
{
    while(ultimo != NULL)
    {
        nodo* temporal = ultimo;
        ultimo = ultimo -> siguiente;
        delete temporal;
    }
}
