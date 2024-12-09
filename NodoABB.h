#ifndef NODOABB_H
#define NODOABB_H

#include <iostream>
#include <string>
#include "Lista.h"

using namespace std;

class NodoABB {
    friend class ABB;

public:

    string nombre;
    NodoABB* hi;
    NodoABB* hd;
    Lista lista;

    NodoABB();
    NodoABB( string nombre, const Lista& lista);
    virtual ~NodoABB();
    void verNombres() const;
};

#endif // NODOABB_H