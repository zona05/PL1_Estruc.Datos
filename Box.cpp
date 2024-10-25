/*
// Box.cpp
#include "Box.h"

Box::Box() : personaActual(), tiempoAtencion(0), tiempoRestante(0) {}

void Box::agregarPersona(const Persona& persona, int tiempo) {
    personaActual = persona; // Asigna la persona actual al box
    tiempoAtencion = tiempo; // Asigna el tiempo de atención requerido
    tiempoRestante = tiempo; // Inicializa el tiempo restante
}

void Box::procesarTiempo() {
    if (tiempoRestante > 0) {
        tiempoRestante--; // Decrementa el tiempo restante
    }
}

bool Box::isLibre() {
    return tiempoRestante <= 0; // Devuelve true si el box está libre
}

void Box::finalizarAtencion(Cola& colaPrioridad) {
    if (isLibre()) {
        // Aquí podrías imprimir o registrar que la atención ha terminado
        // Desencolar la siguiente persona de la cola de prioridad
        if (!colaPrioridad.esVacia()) {
            Persona siguientePersona = colaPrioridad.desencolar(); // Desencola la siguiente persona
            // Aquí puedes definir el tiempo que necesita la nueva persona en el box
            agregarPersona(siguientePersona, siguientePersona.tiempo); // Asigna la nueva persona al box
        }
    }
}
*/
