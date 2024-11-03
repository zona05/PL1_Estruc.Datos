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
        desencolar();
    }
}

bool Cola::esVacia() {
    return primero == nullptr;
}

void Cola::encolar(Persona persona) {
    NodoCola* nuevo_nodo = new NodoCola(persona);
    if (esVacia()) {
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;
    } else {
        ultimo->siguiente = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    longitud++;

}

Persona Cola::desencolar() {
    if (!esVacia()) {
        NodoCola* aux = primero;
        Persona p = primero->persona;

        if ((primero == ultimo) && (primero->siguiente == nullptr)) {
            primero = nullptr;
            ultimo = nullptr;
        } else {
            primero = primero->siguiente;
        }
        delete aux;
        longitud--;
        return p;
    }
    throw runtime_error("La cola está vacía.");
}

Persona &Cola::frente() {
    if (esVacia()) {
        throw runtime_error("La cola está vacía.");
    }
    return primero->persona;
}

void Cola::mostrar() {
    NodoCola* actual = primero;
    while (actual != nullptr) {
        cout << "ID: " << actual->persona.id
             << ", Pais: " << actual->persona.pais
             << ", Prioridad: " << actual->persona.prioridad
             << ", Inicio: " << actual->persona.inicio
             << ", Tiempo: " << actual->persona.tiempo
             << ", Horario: " << actual->persona.horario << endl;
        actual = actual->siguiente;
    }
}
void Cola:: incrementartiempo() {
    NodoCola* actual = primero;
    while (actual != nullptr) {
        actual ->persona.tiempo +=1;
        actual= actual -> siguiente;
    }
}

Persona& Cola::obtenerPersona(int posicion) {
    if (esVacia()) {
        throw std::out_of_range("No se puede obtener la persona, la cola está vacía.");
    }
    if (posicion < 0 || posicion >= longitud) {
        throw std::out_of_range("Índice fuera de rango.");
    }

    NodoCola* actual = primero; // Comenzar desde el frente de la cola
    for (int index = 0; index < posicion; ++index) {
        actual = actual->siguiente; // Avanzar al siguiente nodo
    }

    return actual->persona; // Retornar la referencia a la Persona en la posición 'posicion'
}


