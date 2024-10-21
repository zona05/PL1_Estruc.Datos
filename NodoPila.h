//
// Created by javie on 18/10/2024.
//

#ifndef NODOPILA_H
#define NODOPILA_H
#include <iostream>


class NodoPila {


    private:
    int valor;
    NodoPila* siguiente;
    friend class Pila;
    public:
    NodoPila();
    NodoPila(int v, NodoPila* sig = nullptr);
    ~NodoPila();
};



#endif //NODOPILA_H
