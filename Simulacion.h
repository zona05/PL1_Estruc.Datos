#ifndef SIMULACION_H
#define SIMULACION_H

#include "Pila.h"
#include "Cola.h"
#include "Lista.h"
#include "Persona.h"
#include <array>

class Simulacion {
private:
    Pila& pilaPasajeros;
    Lista& listaBox;
    Pila resfinal;
    int tiemposim;
    int minutos;
    int acciones = 0;
    double media = 0.0;
    Cola cola;

public:
    Simulacion(Pila& pilaExterna, Lista& listaExterna);
    ~Simulacion();

    void simularMinutos(int minutos);
    void mostrarBoxes();
    void simularEntero();
    void Simular();
    void Boxear();
    void Boxeamiento();
    void Finalizar();
    void Traspaso();
    void AgregarBoxes();
    void QuitarBoxes();

};

#endif // SIMULACION_H
