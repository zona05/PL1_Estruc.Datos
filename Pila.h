//
// Created by javie on 18/10/2024.
//

#ifndef PILA_H
#define PILA_H
#include "NodoPila.h"

class Pila {
private:
    NodoPila* cima;

public:
    Pila();
    ~Pila();
    bool esVacia();
    void apilar(int v);
    void desapilar();
    int mostrar();
    int contar();
    int fondo();
    void montar(Pila a, Pila b);
    void quitar(int c);
    Pila invertir();
    int mayor_pila();
};



#endif //PILA_H
