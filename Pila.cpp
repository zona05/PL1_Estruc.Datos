#include "Pila.h"
#include <iostream>

using namespace std;

// Constructor: inicializa la pila con cima en nullptr.
Pila::Pila() {
    cima = nullptr;
}

// Destructor: elimina todos los elementos de la pila llamando a desapilar hasta que esté vacía.
Pila::~Pila() {
    while (cima) {
        desapilar();
    }
}

// esVacia: verifica si la pila está vacía, devolviendo true si cima es nullptr.
bool Pila::esVacia() {
    return cima == nullptr;
}

// añadir: agrega una Persona en la cima de la pila.
void Pila::añadir(Persona persona) {
    NodoPila* nuevo = new NodoPila(persona, cima);
    cima = nuevo;
}

// apilar: inserta una Persona en la pila de forma ordenada según el atributo inicio.
void Pila::apilar(Persona persona) {
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

// desapilar: elimina y devuelve la Persona en la cima de la pila. Lanza un error si la pila está vacía.
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

// contar: cuenta y devuelve la cantidad de elementos en la pila.
int Pila::contar() {
    int contador = 0;
    NodoPila* actual = cima;
    while (actual != nullptr) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

// mostrar: muestra por consola los datos de cada Persona en la pila.
void Pila::mostrar() {
    NodoPila* actual = cima;
    while (actual != nullptr) {
        cout << "ID: " << actual->persona.id
             << ", País: " << actual->persona.pais
             << ", Prioridad: " << actual->persona.prioridad
             << ", Inicio: " << actual->persona.inicio
             << ", Tiempo: " << actual->persona.tiempo
             << ", Horario: " << actual->persona.horario << endl;
        actual = actual->siguiente;
    }
}

// peek: devuelve la Persona en la cima de la pila sin eliminarla. Lanza un error si la pila está vacía.
Persona Pila::peek() {
    if (esVacia()) {
        throw runtime_error("La pila está vacía.");
    }
    return cima->persona;
}
