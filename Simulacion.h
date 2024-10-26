#ifndef SIMULACION_H
#define SIMULACION_H

#include "Pila.h"
#include "Cola.h"
#include "Persona.h"
#include <array>

class Simulacion {
private:
    Pila pilaPasajeros;
    Cola colaEspera;
    Cola box[3];
    Pila auxPila;
    int minutos;
    int acciones = 0;
    double media = 0.0;

public:
    Simulacion();
    ~Simulacion();


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
