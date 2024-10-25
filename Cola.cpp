#include "Cola.h"
#include "NodoCola.h"
#include <iostream>
#include <stdexcept> // Para runtime_error

using namespace std;

Cola::Cola() {
    primero = nullptr;
    ultimo = nullptr;
    longitud = 0;
}

Cola::~Cola() {
    while (!esVacia()) {
        desencolar(); // Desencolar todos los elementos al destruir
    }
}

bool Cola::esVacia() {
    return primero == nullptr;
}

void Cola::encolar(const Persona& persona) {
    NodoCola* nuevo_nodo = new NodoCola(persona); // Asegúrate de que este constructor esté disponible
    if (esVacia()) {
        primero = nuevo_nodo; // Si la cola está vacía, primero y último apuntan al nuevo nodo
        ultimo = nuevo_nodo;
    } else {
        ultimo->siguiente = nuevo_nodo; // Enlaza el nuevo nodo al final de la cola
        ultimo = nuevo_nodo; // Actualiza el puntero del último nodo
    }
    longitud++; // Incrementa la longitud de la cola
}

Persona Cola::desencolar() {
    if (!esVacia()) {
        NodoCola* aux = primero;
        Persona p = primero->persona; // Guardar la persona que se va a desencolar

        if ((primero == ultimo) && (primero->siguiente == nullptr)) {
            primero = nullptr;
            ultimo = nullptr;
        } else {
            primero = primero->siguiente;
        }
        delete aux;
        longitud--;
        return p; // Retorna la persona desencolada
    }
    throw runtime_error("La cola está vacía."); // Manejo de error
}

void Cola::encolarprioridad(const Persona& persona) {
    // Aquí debes implementar el algoritmo para encolar según la prioridad
    // Algoritmo de ordenamiento de burbuja
    for (NodoCola* i = primero; i != nullptr; i = i->siguiente) {
        for (NodoCola* j = primero; j->siguiente != nullptr; j = j->siguiente) {
            // Intercambiar si la prioridad (número) de j es menor que la de j->siguiente
            if (j->persona.prioridad < j->siguiente->persona.prioridad) {
                swap(j->persona, j->siguiente->persona); // Intercambiar los objetos Persona
            }
        }
    }
}

Persona Cola::frente() {
    if (esVacia()) {
        throw runtime_error("La cola está vacía.");
    }
    return primero->persona;
}

void Cola::mostrar() {
    NodoCola* actual = primero;
    while (actual != nullptr) {
        cout << "ID: " << actual->persona.id
             << ", País: " << actual->persona.pais
             << ", Prioridad: " << actual->persona.prioridad
             << ", Inicio: " << actual->persona.inicio
             << ", Tiempo: " << actual->persona.tiempo << endl;
        actual = actual->siguiente;
    }
}
