#ifndef PILA_H
#define PILA_H

#include "NodoPila.h"
#include "Persona.h"

class Pila {
private:
    NodoPila* cima;

public:
    Pila();
    ~Pila();
    bool esVacia();
    void añadir(const Persona& persona);
    void apilar(const Persona& persona);
    Persona desapilar();
    int contar();
    void mostrar();
    Persona peek();

};

#endif // PILA_H
