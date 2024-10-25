/*
#ifndef BOX_H
#define BOX_H

#include "Cola.h" // Incluye la cola que contiene las personas
#include "persona.h" // Incluye la definición de Persona

class Box {
private:
    Persona personaActual; // Persona que está en el box
    int tiempoAtencion; // Tiempo que necesita la persona en el box
    int tiempoRestante; // Tiempo restante de atención

public:
    Box();
    void agregarPersona(const Persona& persona, int tiempo);
    void procesarTiempo(); // Para simular el paso del tiempo
    bool isLibre(); // Para verificar si el box está libre
    void finalizarAtencion(Cola& colaPrioridad); // Para finalizar la atención y desencolar
};

#endif // BOX_H
*/