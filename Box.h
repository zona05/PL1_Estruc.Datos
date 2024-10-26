#ifndef BOX_H
#define BOX_H

#include "Persona.h"

class Box {
private:
    Persona personaActual;
    int tiempoAtencion;
    int tiempoRestante;

public:
    Box();
    bool isLibre() const;
    void agregarPersona(const Persona& persona, int tiempoAtencion);
    void finalizarAtencion();
    void procesarTiempo();
};

#endif
