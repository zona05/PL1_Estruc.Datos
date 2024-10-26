#ifndef COLA_H
#define COLA_H
#include "NodoCola.h"
#include "Persona.h"
using namespace std;

class Cola {
public:
    friend class Persona;
    NodoCola *primero;
    NodoCola *ultimo;
    int longitud;

    Cola();
    ~Cola();
    bool esVacia();
    void encolar(const Persona& persona);
    void encolarprioridad(const Persona& persona);
    Persona desencolar();
    Persona frente();
    void mostrar(); // Agrega la declaración
};

#endif //COLA_H
