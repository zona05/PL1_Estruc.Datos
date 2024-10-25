#ifndef PILA_H
#define PILA_H
#include "NodoPila.h"

#include "persona.h"

class Pila {
private:
    NodoPila* cima;

public:
    Pila();
    ~Pila();
    bool esVacia();
    void añadir(Persona persona);
    void apilar(Persona persona);
    void desapilar();
    int contar();
    void mostrar();
};

#endif // PILA_H
