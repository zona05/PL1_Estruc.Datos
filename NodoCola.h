#ifndef NODOCOLA_H
#define NODOCOLA_H

#include "Persona.h" // Asegúrate de incluir la cabecera de Persona

class NodoCola {
public:
    Persona persona;      // Objeto Persona en el nodo
    NodoCola* siguiente;  // Puntero al siguiente nodo

    // Constructor para inicializar un NodoCola con una Persona
    NodoCola(Persona p , NodoCola*sig = nullptr );
    NodoCola();
    ~NodoCola();


};

#endif