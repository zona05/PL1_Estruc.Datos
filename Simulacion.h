#ifndef SIMULACION_H
#define SIMULACION_H

#include "Pila.h"
#include "Cola.h"
#include "Persona.h"
#include <array>

class Simulacion {
private:
    Pila& pilaPasajeros;
    Cola& colaEspera;
    Cola box[3];
    Pila resfinal;
    int minutos;
    int acciones = 0;
    double media = 0.0;

public:
    Simulacion(Pila& pilaExterna, Cola& colaExterna);
    ~Simulacion();

    void iniciarSimulacion();
    void simularMinutos(int minutos);
    void mostrarBoxes();
    void simularEntero();
};

#endif // SIMULACION_H
