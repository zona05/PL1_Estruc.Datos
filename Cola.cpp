#include "Cola.h"
#include "NodoCola.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// Constructor: inicializa la cola vacía con primero, ultimo como nullptr y longitud en 0.
Cola::Cola() {
    primero = nullptr;
    ultimo = nullptr;
    longitud = 0;
}

// Destructor: elimina todos los elementos de la cola, desencolando hasta vaciarla.
Cola::~Cola() {
    while (!esVacia()) {
        desencolar();
    }
}

// esVacia: retorna true si la cola está vacía, es decir, si primero es nullptr.
bool Cola::esVacia() {
    return primero == nullptr;
}

// encolar: añade un nuevo elemento (persona) al final de la cola.
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

// encolar_ordenado: agrega una persona a la cola y luego ordena la cola por la prioridad de la persona (de mayor a menor).
void Cola::encolar_ordenado(Persona persona) {
    NodoCola* nuevo_nodo = new NodoCola(persona);
    if (esVacia()) {
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;
    } else {
        ultimo->siguiente = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    longitud++;

    // Ordena la cola según la prioridad de la persona (orden descendente).
    for (NodoCola* i = primero; i != nullptr; i = i->siguiente) {
        for (NodoCola* j = primero; j->siguiente != nullptr; j = j->siguiente) {
            if (j->persona.prioridad < j->siguiente->persona.prioridad) {
                swap(j->persona, j->siguiente->persona);
            }
        }
    }
}

// desencolar: elimina y devuelve el primer elemento de la cola.
Persona Cola::desencolar() {
    if (!esVacia()) {
        NodoCola* aux = primero;
        Persona p = primero->persona;

        // Si la cola tiene un solo elemento, resetea ambos punteros a nullptr.
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

// frente: devuelve el primer elemento de la cola sin eliminarlo.
Persona &Cola::frente() {
    if (esVacia()) {
        throw runtime_error("La cola está vacía.");
    }
    return primero->persona;
}

// mostrar: muestra todos los elementos de la cola, incluyendo la información de cada persona.
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
void Cola::mostrar2() {
    NodoCola* actual = primero;
    while (actual != nullptr) {
        cout << "ID: " << actual->persona.id << ", Tiempo: " << actual->persona.tiempo<< endl;
        actual = actual->siguiente;
    }
}
// incrementartiempo: aumenta el tiempo de cada persona en la cola en 1 minuto.
void Cola::incrementartiempo() {
    NodoCola* actual = primero;
    while (actual != nullptr) {
        actual->persona.tiempo += 1;
        actual = actual->siguiente;
    }
}

int Cola::longitudcola () {
    int contador = 0;
    NodoCola* actual = primero;
    while (actual != nullptr) {
        contador = contador + 1;
        actual = actual->siguiente;
    }
    return contador;

}
float Cola::tiempomedio() {
    if (primero == nullptr) { // Si la cola está vacía
        return 0.0; // Tiempo medio es 0
    }
    int sumaTiempo = 0;  // Acumulador para los tiempos
    NodoCola* actual = primero; // Comenzar desde el primer nodo
    while (actual != nullptr) {
        sumaTiempo += actual->persona.tiempo; // Sumar el tiempo del nodo actual
        actual = actual->siguiente;  // Avanzar al siguiente nodo
    }

    // Calcular la media dividiendo la suma total entre el número de nodos
    return sumaTiempo / longitudcola();

}

// obtenerPersona: devuelve una referencia a la persona en una posición dada de la cola (por índice).
Persona& Cola::obtenerPersona(int posicion) {
    if (esVacia()) {
        throw std::out_of_range("No se puede obtener la persona, la cola está vacía.");
    }
    if (posicion < 0 || posicion >= longitud) {
        throw std::out_of_range("Índice fuera de rango.");
    }

    NodoCola* actual = primero;
    for (int index = 0; index < posicion; ++index) {
        actual = actual->siguiente;
    }

    return actual->persona;
}
