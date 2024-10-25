#ifndef NODOPILA_H
#define NODOPILA_H

#include "persona.h"

class NodoPila {
public:
    Persona persona;
    NodoPila* siguiente;

    NodoPila(const Persona& persona, NodoPila* siguiente = nullptr);
    ~NodoPila();
};

#endif // NODOPILA_H
