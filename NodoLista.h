
#ifndef NODOLISTA_H
#define NODOLISTA_H
#include <iostream>
#include "Cola.h"

class NodoLista
{
private:
    NodoLista* siguiente;
    Cola cola;

    friend class Lista;
    friend class SistemaLista;
    friend class Cola;
    friend class NodoCola;

public:
    NodoLista();
    NodoLista(Cola c, NodoLista*sig = nullptr);
    ~NodoLista();


};
#endif