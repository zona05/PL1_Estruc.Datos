#include "Box.h"

Box::Box() : tiempoAtencion(0), tiempoRestante(0) {}

bool Box::isLibre() const {
    return tiempoRestante <= 0;
}

void Box::agregarPersona(const Persona& persona, int tiempoAtencion) {
    personaActual = persona;
    this->tiempoAtencion = tiempoAtencion;
    this->tiempoRestante = tiempoAtencion;
}

void Box::finalizarAtencion() {
    if (isLibre()) {
        personaActual = Persona();
        tiempoAtencion = tiempoRestante = 0;
    }
}

void Box::procesarTiempo() {
    if (!isLibre()) {
        tiempoRestante--;
        if (isLibre()) {
            finalizarAtencion();
        }
    }
}
