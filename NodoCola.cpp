#include "NodoCola.h"

// Constructor por defecto: inicializa el puntero siguiente a nullptr y crea un objeto Persona vacío.
NodoCola::NodoCola() {
    siguiente = nullptr;
    persona = Persona();
}

// Constructor con parámetros: inicializa el nodo con una Persona y el puntero al siguiente nodo.
NodoCola::NodoCola(Persona p, NodoCola* sig) {
    persona = p;
    siguiente = sig;
}

// Destructor: no realiza ninguna acción específica.
NodoCola::~NodoCola() {
}
