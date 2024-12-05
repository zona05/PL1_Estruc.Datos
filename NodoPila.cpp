// NodoPila.cpp
#include "NodoPila.h"

// Constructor con parámetros: inicializa el nodo con una Persona y el puntero al siguiente nodo.
NodoPila::NodoPila(const Persona& persona, NodoPila* sig)
    : persona(persona), siguiente(sig) {
}

// Destructor: no realiza ninguna acción específica.
NodoPila::~NodoPila() {}
