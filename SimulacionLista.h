#ifndef SIMULACIONLISTA_H
#define SIMULACIONLISTA_H
#include "Pila.h"
#include "Cola.h"
#include "ABB.h"

class SimulacionLista {
public:
    Pila& pilaPasajeros;
    Lista& lista;
    ABB abb2;
    Pila resfinal;
    Pila aux;
    int tiemposim = 0;
    int minutos;
    int acciones = 0;
    double media = 0.0;


    SimulacionLista(Pila& pilaExterna, Lista& listaExterna, ABB& abbExterna);
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
    Pila SacarResfinal();

};





#endif //SIMULACIONLISTA_H