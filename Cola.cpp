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
    return primero ==nullptr ;
}
void Cola::encolar(int v) {
    NodoCola* nuevoNodo = new NodoCola(v);  // Crear un nuevo nodo con el valor
    if (esVacia()) {
        // Si la cola está vacía, el nuevo nodo es tanto el frente como el final
        primero = nuevoNodo;
        ultimo = nuevoNodo;
    } else {
        // Si la cola no está vacía, añadir el nuevo nodo al final
        ultimo ->siguiente = nuevoNodo;
        ultimo = nuevoNodo;
    }
}
void Cola::desencolar(){
    if(!esVacia()){
        Proceso elemento = primero->proceso;
        NodoCola* aux = primero;
        if((primero == ultimo) && (primero->siguiente == NULL )){
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete(aux);}
        else{
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete(aux);}
        longitud--;
    }
}