#include "Simulacion.h"
#include <iostream>

using namespace std;

Simulacion::Simulacion(Pila& pilaExterna, Cola& colaExterna) : pilaPasajeros(pilaExterna), colaEspera(colaExterna) {}

Simulacion::~Simulacion() {

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
void Simulacion::Traspaso() {
    Pila aux;

    while (!pilaPasajeros.esVacia()) { //pila a cola
        if (pilaPasajeros.peek().inicio == tiemposim) {
            colaEspera.encolar(pilaPasajeros.peek());
            cout << "Pasajero " << pilaPasajeros.peek().id << " llega al aeropuerto en el minuto: " << tiemposim << endl;
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
}

void Simulacion::Boxear() {
    for (int l = 0; l < 3; ++l) { //ponerlo en las box
        if (box[l].longitud == 0 && !colaEspera.esVacia()) {
            box[l].encolar(colaEspera.frente());
            cout << "Pasajero " << colaEspera.frente().id << " Entra en el box: " << l + 1 << " a la espera de ser atendido en el minuto " << tiemposim << endl;
            colaEspera.desencolar();
        }
    }
}
void Simulacion::Boxeamiento() {
    for (int k = 0; k < 3; ++k) {
        if (box[k].longitud != 0) {
            Persona frentePersona = box[k].frente();
            frentePersona.tiempo++;
            frentePersona.horario--;
            if (frentePersona.horario == 0) {
                cout << "Pasajero " << box[k].frente().id << " Sale del box: " << k +1 << " tras ser atendido en el minuto " << tiemposim  << endl;
                media += frentePersona.tiempo;
                resfinal.apilar(frentePersona);
                box[k].desencolar();
                acciones++;
            }
            else {
                box[k].desencolar();
                box[k].encolar(frentePersona);
            }
        }
    }
    if (!colaEspera.esVacia()) {
        colaEspera.incrementartiempo();
    }

}
void Simulacion::Finalizar() {
    media = media/acciones;
    cout << "La media de tiempo de los pasajeros es " << media<< endl;
    while (!resfinal.esVacia()) {
        cout << "Pasajero " << resfinal.peek().id << ", tiempo ocupado en el aeropuerto: " << resfinal.peek().tiempo << endl;
        resfinal.desapilar();
    }
    for (int m = 0; m < 3; ++m) {
        if (box[m].longitud != 0) {
            cout << "El box " << m << " está ocupado por el pasajero: " << box[m].frente().id << endl;
        }
    }
}
void Simulacion::simularMinutos(int minutos) {
    Pila resfinal;

    for (int i = 0; i < minutos; ++i) {
        tiemposim = i;  // Actualiza el tiempo actual de la simulación

        // Paso 1: Pasar los pasajeros de la pila a la cola de espera
        Traspaso();

        // Paso 2: Asignar pasajeros de la cola de espera a los boxes
        Boxear();

        // Paso 3: Atender a los pasajeros en los boxes
        Boxeamiento();

        // Incrementa el tiempo de espera de los pasajeros en la cola
        if (!colaEspera.esVacia()) {
            colaEspera.incrementartiempo();
        }
    }

    // Paso 4: Mostrar resultados finales
    Finalizar();
}

void Simulacion::simularEntero() {
    tiemposim = 0;

    // Ejecuta el ciclo de simulación hasta que todos los pasajeros hayan sido atendidos
    while (resfinal.contar() != pilaPasajeros.contar()) {
        // Paso 1: Pasar los pasajeros de la pila a la cola de espera
        Traspaso();

        // Paso 2: Asignar pasajeros de la cola de espera a los boxes
        Boxear();

        // Paso 3: Atender a los pasajeros en los boxes
        Boxeamiento();
        if (!colaEspera.esVacia()) {
            colaEspera.incrementartiempo();
        }

        // Incrementa el tiempo de simulación
        tiemposim++;
    }

    // Paso 4: Mostrar resultados finales
    Finalizar();

    cout << "La simulación ha tardado este número de minutos: " << tiemposim << endl;
}