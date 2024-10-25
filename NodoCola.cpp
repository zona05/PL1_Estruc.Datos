#include "NodoCola.h"

NodoCola::NodoCola() {
    siguiente = nullptr;
    valor = 0;  // Valor por defecto
}

NodoCola::NodoCola(int v, NodoCola* sig) {
    valor = v;
    siguiente = sig;
}

NodoCola::~NodoCola() {
    // Destructor si es necesario
}
