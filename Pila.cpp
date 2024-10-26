#include "Pila.h"
#include <iostream>

using namespace std;

Pila::Pila() {
    cima = nullptr;
}

Pila::~Pila() {
    while (cima) {
        desapilar();
    }
}

bool Pila::esVacia() {
    return cima == nullptr;
}

void Pila::añadir(const Persona& persona) {
    NodoPila* nuevo = new NodoPila(persona, cima);
    cima = nuevo;
}

void Pila::apilar(const Persona& persona) {
    if (esVacia() || persona.inicio <= cima->persona.inicio) {
        añadir(persona);
    } else {
        Pila aux;

        while (!esVacia() && persona.inicio > cima->persona.inicio) {
            aux.añadir(cima->persona);
            desapilar();
        }

        añadir(persona);

        while (!aux.esVacia()) {
            añadir(aux.cima->persona);
            aux.desapilar();
        }
    }
}

Persona Pila::desapilar() {
    if (esVacia()) {
        throw runtime_error("La pila está vacía.");
    }
    NodoPila* nodo = cima;
    Persona persona = nodo->persona;
    cima = nodo->siguiente;
    delete nodo;
    return persona;
}

int Pila::contar() {
    int contador = 0;
    NodoPila* actual = cima;
    while (actual != nullptr) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

void Pila::mostrar() {
    NodoPila* actual = cima;
    while (actual != nullptr) {
        cout << "ID: " << actual->persona.id
             << ", País: " << actual->persona.pais
             << ", Prioridad: " << actual->persona.prioridad
             << ", Inicio: " << actual->persona.inicio
             << ", Tiempo: " << actual->persona.tiempo << endl;
        actual = actual->siguiente;
    }
}

Persona Pila::peek(){
    if (esVacia()) {
        throw runtime_error("La pila está vacía.");
    }
    return cima->persona;
}
