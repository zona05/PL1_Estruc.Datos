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
}
bool Cola::esVacia() {
    return frente ==nullptr ;
}
void Cola::encolar(int v) {
    NodoCola* nuevoNodo = new NodoCola(v);  // Crear un nuevo nodo con el valor
    if (esVacia()) {
        // Si la cola está vacía, el nuevo nodo es tanto el frente como el final
        frente = nuevoNodo;
        final = nuevoNodo;
    } else {
        // Si la cola no está vacía, añadir el nuevo nodo al final
        final->siguiente = nuevoNodo;
        final = nuevoNodo;
    }
}
