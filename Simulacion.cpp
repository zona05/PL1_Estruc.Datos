#include "Simulacion.h"
#include <iostream>

using namespace std;

Simulacion::Simulacion(Pila& pilaExterna, Cola& colaExterna) : pilaPasajeros(pilaExterna), colaEspera(colaExterna) {}

Simulacion::~Simulacion() {
    // Destructor si es necesario
}

void Simulacion::mostrarBoxes() {
    for (int k = 0; k < 3; ++k) {
        if (box[k].longitud != 0) {
            cout << "Pasajero ID: " << box[k].frente().id
                 << ", País: " << box[k].frente().pais
                 << ", Tiempo restante: " << box[k].frente().horario << " minutos" << endl;
        }
    }
}

void Simulacion::simularMinutos(int minutos) {
    for (int i = 0; i < minutos; ++i) {
        Pila aux;  // Pila auxiliar temporal
        while (!pilaPasajeros.esVacia()) {
            if (pilaPasajeros.peek().inicio == i) {
                colaEspera.encolar(pilaPasajeros.peek());
                colaEspera.encolarprioridad(pilaPasajeros.peek());
                aux.apilar(pilaPasajeros.peek());
                pilaPasajeros.desapilar();
            } else {
                aux.apilar(pilaPasajeros.peek());
                pilaPasajeros.desapilar();
            }
        }
        while (!aux.esVacia()) {
            pilaPasajeros.apilar(aux.peek());
            aux.desapilar();
        }
        for (int l = 0; l < 3; ++l) {
            if (box[l].longitud == 0 && !colaEspera.esVacia()) {
                box[l].encolar(colaEspera.frente());
                colaEspera.desencolar();
            }
        }
        for (int k = 0; k < 3; ++k) {
            if (box[k].longitud == 1) {
                Persona frentePersona = box[k].frente();
                frentePersona.tiempo++;
                frentePersona.horario--;
                if (frentePersona.horario == 0) {
                    media += frentePersona.tiempo;
                    box[k].desencolar();
                    acciones++;
                }
            }
        }
    }
}
