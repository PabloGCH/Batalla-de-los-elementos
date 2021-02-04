#ifndef ABB_H
#define ABB_H

#include "nodo.h"

class ABB{
private:
    // Atributos
    Nodo* raiz;

public:
    //Metdodos

    // PRE: -
    // POS: Crea un arbol binario de busqueda vacio con 'raiz' apuntando a null.
    ABB();//Constructor

    Nodo* obtenerRaiz();

    // PRE: -
    // POS: inserta un nuevo nodo con 'nuevoPersonaje' en el arbol binario.
    void insertarHoja(Dato &nuevoPersonaje);

   Nodo* buscarPersonaje(const string& buscado);

    void enOrden();

    Dato encontrarMenor();

    Dato encontrarMayor();

    Dato encontrarSucesor(string claveActual);

    Dato encontrarPredecesor(string claveActual);

    void borrarNodo(string eliminar);

    bool arbolVacio();

    void borrarArbol();

    ~ABB();//Destructor

private:

    Nodo* agregarNodo(Nodo* actual, Dato &nuevoPersonaje);

    Nodo* consultarPersonaje(Nodo* actual, const string& buscado);

    void imprimirEnOrden(Nodo* actual);

    Dato menor(Nodo* actual);

    Dato mayor(Nodo* actual);

    Dato sucesor(Nodo* actual);

    Dato predecesor(Nodo* actual);

    Nodo* eliminarNodo(Nodo* actual, string eliminar);

    void eliminarRaiz();

    void borrarTodo(Nodo* actual);
};

#endif // ABB_H
