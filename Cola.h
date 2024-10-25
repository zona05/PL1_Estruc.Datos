#ifndef COLA_H
#define COLA_H
#include "NodoCola.h"

class Cola {
private:
    NodoCola* primero;
    NodoCola* ultimo;
    int longitud;
public:
    Cola();
    ~Cola();
    bool esVacia();
    void encolar(int v);
    void desencolar();  // Asegúrate de declarar esto
};

#endif //COLA_H
