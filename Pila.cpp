//
// Created by javie on 18/10/2024.
//

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

void Pila::apilar(int v) {
    NodoPila* nuevo = new NodoPila(v, cima);
    cima = nuevo;
}

void Pila::desapilar() {
    if(cima) {
        NodoPila* nodo = cima;
        cima = nodo->siguiente;
        delete nodo;
    }
}

int Pila::mostrar() {
    if(esVacia()) {
        cout << "La Pila esta vacia." << endl;
        return -1;
    }
    else {
        cout << "La cima de la pila es: " << cima->valor << endl;
    }
    return 0;
}

int Pila::contar() {
    int contador = 0;
    NodoPila* actual = cima;

    while(actual != nullptr) {
        contador ++;
        actual = actual->siguiente;
    }
    return contador;
}

int Pila::fondo() {
    NodoPila* actual = cima;
    while(actual->siguiente != nullptr) {
        actual = actual->siguiente;
    }
    return actual->valor;
}

void Pila::montar(Pila a, Pila b) {

    while (!esVacia()) {
        desapilar();
    }


    Pila aux;


    while (!a.esVacia()) {
        aux.apilar(a.cima->valor);
        a.desapilar();
    }


    while (!aux.esVacia()) {
        apilar(aux.cima->valor);
        aux.desapilar();
    }

    while (!b.esVacia()) {
        aux.apilar(b.cima->valor);
        b.desapilar();
    }


    while (!aux.esVacia()) {
        apilar(aux.cima->valor);
        aux.desapilar();
    }
}

void Pila::quitar(int c) {
    while(c!=0) {
        desapilar();
        c--;
    }
}

Pila Pila::invertir() {
    Pila aux;

    while(!esVacia()) {
        int valor = cima->valor;
        desapilar();
        aux.apilar(valor);
    }
    return aux;
}

int Pila::mayor_pila() {
    Pila aux;
    int maximo= cima->valor;
    aux.apilar(maximo);
    desapilar();

    while(!esVacia()) {
        int arriba = cima->valor;

        if(arriba > maximo) {
            maximo = arriba;
        }
        aux.apilar(arriba);
        desapilar();
    }

    while(!aux.esVacia()) {
        int arriba_aux = aux.cima->valor;
        aux.desapilar();

        if (arriba_aux != maximo) {
            apilar(arriba_aux);
        }
    }
    return maximo;
}
