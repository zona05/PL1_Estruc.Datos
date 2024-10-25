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
    void añadir(const Persona& persona);
    void apilar(const Persona& persona);
    Persona desapilar(); // Cambiado de void a Persona
    int contar();
    void mostrar(); // Declaración correcta
};

#endif // PILA_H
