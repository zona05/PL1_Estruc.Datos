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

    while (!pilaPasajeros.esVacia()) {
        Persona pasajero = pilaPasajeros.peek();

        if (pasajero.inicio <= tiemposim) {
            colaEspera.encolar_ordenado(pasajero);
            cout << "Pasajero " << pasajero.id << " llega al aeropuerto en el minuto: " << tiemposim << endl;
        } else {
            aux.apilar(pasajero);
        }
        pilaPasajeros.desapilar();
    }
    while (!aux.esVacia()) {
        pilaPasajeros.apilar(aux.peek());
        aux.desapilar();
    }
}


void Simulacion::Boxear() {
    for (int l = 0; l < 3; ++l) {
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
                cout << "Pasajero " << box[k].frente().id << " Sale del box: " << k + 1 << " tras ser atendido en el minuto " << tiemposim << endl;
                media += frentePersona.tiempo;
                resfinal.apilar(frentePersona);
                box[k].desencolar();
                acciones++;
            } else {
                box[k].desencolar();
                box[k].encolar(frentePersona);
            }
        }
    }
}

void Simulacion::Finalizar() {
    media=media/acciones;
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
    for (int i = 0; i < minutos; ++i) {
        cout << "Simulando minuto: " << tiemposim << endl;
        Traspaso();
        Boxear();
        Boxeamiento();
        if (!colaEspera.esVacia()) {
            colaEspera.incrementartiempo();
        }
        tiemposim++;
    }
    Finalizar();
}



void Simulacion::simularEntero() {
    tiemposim = 0;
    int a = pilaPasajeros.contar();
    while (resfinal.contar() != a) {
        Traspaso();
        Boxear();
        Boxeamiento();
        if (!colaEspera.esVacia()) {
            colaEspera.incrementartiempo();
        }
        tiemposim++;
    }
    Finalizar();

    cout << "La simulación ha tardado este número de minutos: " << tiemposim << endl;
}