#ifndef SIMULACION_H
#define SIMULACION_H

#include "Pila.h"
#include "Cola.h"
#include "Persona.h"
#include <array>

class Simulacion {
private:
    Pila& pilaPasajeros;  // Referencia a la pila externa
    Cola& colaEspera;
    Cola box[3];
    int minutos;
    int acciones = 0;
    double media = 0.0;

public:
    Simulacion(Pila& pilaExterna, Cola& colaExterna);  // Constructor con referencia a Pila
    ~Simulacion();

    void iniciarSimulacion();
    void simularMinutos(int minutos);
    void mostrarBoxes();
};

#endif // SIMULACION_H
