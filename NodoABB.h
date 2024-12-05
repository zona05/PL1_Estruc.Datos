#ifndef NODOABB_H
#define NODOABB_H

#include <iostream>
#include <string>
#include "Lista.h"

using namespace std;

class NodoABB {
    friend class ABB;

public:
    NodoABB( string nombre, Lista lista = Lista());
    virtual ~NodoABB();
    void verNombres() const;

private:
    string nombre;
    NodoABB* hi;
    NodoABB* hd;
    Lista lista;
};

#endif // NODOABB_H