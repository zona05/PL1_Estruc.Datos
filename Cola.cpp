#include "Cola.h"
#include "NodoCola.h"
#include <iostream>
using namespace std;

Cola::Cola() {
    primero = nullptr;
    ultimo = nullptr;
    longitud = 0;
}

Cola::~Cola() {
    // Destructor si es necesario
}

bool Cola::esVacia() {
    return primero == nullptr;
}

void Cola::encolar(int v) {
    NodoCola* nuevoNodo = new NodoCola(v);
    if (esVacia()) {
        primero = nuevoNodo;
        ultimo = nuevoNodo;
    } else {
        ultimo->siguiente = nuevoNodo;
        ultimo = nuevoNodo;
    }
}

void Cola::desencolar() {
    if (!esVacia()) {
        NodoCola* aux = primero;
        primero = primero->siguiente;
        delete aux;
        longitud--;
    }
}
