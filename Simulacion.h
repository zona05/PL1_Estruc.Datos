#ifndef SIMULACION_H
#define SIMULACION_H

#include "Pila.h"
#include "Cola.h"
#include "Persona.h"
#include <vector>

class Simulacion {
private:
    Pila& pilaPasajeros;
    Cola& colaEspera;
    int tiempoActual;
    std::vector<Persona> boxes;

public:
    Simulacion(Pila& pila, Cola& cola) : pilaPasajeros(pila), colaEspera(cola), tiempoActual(0), boxes(3) {}

    void procesarLlegadaPasajeros();
    void iniciarSimulacion();
    void simularMinutos(int minutos);
    void simularCompleto();
    void mostrarBoxes();

private:
    void moverAPasajeroDesdeCola();
    void actualizarBoxes();
};

#endif // SIMULACION_H
