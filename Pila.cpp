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

void Pila::añadir(const Persona persona) {
    NodoPila* nuevo = new NodoPila(persona, cima); // Crear nuevo nodo con persona
    cima = nuevo; // La cima ahora apunta al nuevo nodo
}

void Pila::apilar(const Persona persona) {
    if (esVacia() || persona.inicio <= cima->persona.inicio) {
        // Insertar directamente en la cima si la pila está vacía o la persona tiene el tiempo menor
        añadir(persona);
    } else {
        Pila aux; // Pila auxiliar para ordenar los elementos

        // Mover elementos a la pila auxiliar hasta encontrar la posición de inserción
        while (!esVacia() && persona.inicio > cima->persona.inicio) {
            aux.añadir(cima->persona); // Mover el elemento actual a la auxiliar
            desapilar();                // Remover el elemento actual de la pila original
        }

        // Insertar la nueva persona en la posición correcta
        añadir(persona);

        // Regresar todos los elementos de la auxiliar a la pila original
        while (!aux.esVacia()) {
            añadir(aux.cima->persona);
            aux.desapilar();
        }
    }
}

void Pila::desapilar() {
    if (cima) {
        NodoPila* nodo = cima;
        cima = nodo->siguiente;
        delete nodo;
    }
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
