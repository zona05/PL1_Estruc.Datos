// NodoPila.cpp
#include "NodoPila.h"


NodoPila::NodoPila(const Persona& persona, NodoPila* sig)
    : persona(persona), siguiente(sig) {
}

NodoPila::~NodoPila() {}
