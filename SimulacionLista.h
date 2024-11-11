//
// Created by Migui on 10/11/2024.
//

#ifndef SIMULACIONLISTA_H
#define SIMULACIONLISTA_H
#include "Pila.h"
#include "Cola.h"
#include "Lista.h"


class SimulacionLista {
private:
    Pila& pilaPasajeros;
    Lista& lista;
    Pila resfinal;
    Pila aux;
    int tiemposim = 0;
    int minutos;
    int acciones = 0;
    double media = 0.0;

public:
    SimulacionLista(Pila& pilaExterna, Lista& listaExterna);
    ~SimulacionLista();



    void simularMinutosLista(int minutos);
    void mostrarBoxes();
    void simularEnteroLista();
    void Simular();
    void BoxeamientoLista();
    void FinalizarLista();
    void TraspasoLista();
    void QuitarBoxes();
    void AgregarBoxes();

};





#endif //SIMULACIONLISTA_H
