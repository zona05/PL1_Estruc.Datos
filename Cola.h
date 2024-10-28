#ifndef COLA_H
#define COLA_H
#include "NodoCola.h"
#include "Persona.h"
using namespace std;

class Cola {
public:
    friend class Persona;
    friend class Simulacion;
    NodoCola *primero;
    NodoCola *ultimo;
    int longitud;

    Cola();
    ~Cola();
    bool esVacia();
    void encolar(Persona persona);
    void encolarprioridad(Persona persona);
    Persona desencolar();
    Persona frente();
    void mostrar(); // Agrega la declaración
    void incrementartiempo();

};

#endif //COLA_H
