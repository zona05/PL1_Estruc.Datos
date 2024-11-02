#ifndef NODOCOLA_H
#define NODOCOLA_H

#include "Persona.h"

class NodoCola {
public:
    Persona persona;
    NodoCola* siguiente;


    NodoCola(Persona p , NodoCola*sig = nullptr );
    NodoCola();
    ~NodoCola();


};

#endif