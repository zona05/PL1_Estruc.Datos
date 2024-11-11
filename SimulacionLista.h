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
    int tiemposim;
    int minutos;
    int acciones = 0;
    double media = 0.0;

public:
    SimulacionLista(Pila& pilaExterna, Lista& listaExterna);
    ~SimulacionLista();



    void simularMinutosLista(int minutos);
    void mostrarBoxes();
    void simularEntero();
    void Simular();
    void BoxeamientoLista();
    void FinalizarLista();
    void TraspasoLista();


};





#endif //SIMULACIONLISTA_H
