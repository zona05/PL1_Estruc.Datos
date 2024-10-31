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
    int tiemposim;
    int minutos;
    int acciones = 0;
    double media = 0.0;

public:
    Simulacion(Pila& pilaExterna, Cola& colaExterna);
    ~Simulacion();

    void simularMinutos(int minutos);
    void mostrarBoxes();
    void simularEntero();
    void Simular();
    void Boxear();
    void Boxeamiento();
    void Finalizar();
    void Traspaso();


};

#endif // SIMULACION_H
