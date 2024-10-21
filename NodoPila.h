//
// Created by javie on 18/10/2024.
//

#ifndef NODOPILA_H
#define NODOPILA_H



class NodoPila {
public:
    int valor;
    NodoPila* siguiente;

    NodoPila(int v, NodoPila* sig = nullptr) {
        valor = v;
        siguiente = sig;
    }
};



#endif //NODOPILA_H
