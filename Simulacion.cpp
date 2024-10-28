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

void Simulacion::simularMinutos(int minutos) {
    Pila resfinal;
    for (int i = 0; i < minutos; ++i) {
        Pila aux;

        while (!pilaPasajeros.esVacia()) { //pila a cola
            if (pilaPasajeros.peek().inicio == i) {
                colaEspera.encolar(pilaPasajeros.peek());
                cout << "Pasajero " << pilaPasajeros.peek().id << " llega al aeropuerto en el minuto: " << i << endl;
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
        for (int l = 0; l < 3; ++l) { //ponerlo en las box
            if (box[l].longitud == 0 && !colaEspera.esVacia()) {
                box[l].encolar(colaEspera.frente());
                cout << "Pasajero " << pilaPasajeros.peek().id << " Entra en el box: " << l + 1 << " a la espera de ser atendido en el minuto " << i << endl;
                colaEspera.desencolar();
            }
        }
        for (int k = 0; k < 3; ++k) {
            if (box[k].longitud != 0) {
                Persona frentePersona = box[k].frente();
                frentePersona.tiempo++;
                frentePersona.horario--;
                if (frentePersona.horario == 0) {
                    cout << "Pasajero " << pilaPasajeros.peek().id << " Sale del box: " << k +1 << " tras ser atendido en el minuto " << i  << endl;
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

void Simulacion::simularEntero() {
    int minuto = 0;
    Pila resfinal;
    while (resfinal.contar() != pilaPasajeros.contar() ) {
        Pila aux;

            while (!pilaPasajeros.esVacia()) { //pila a cola
                if (pilaPasajeros.peek().inicio == minuto) {
                    colaEspera.encolar(pilaPasajeros.peek());
                    cout << "Pasajero " << pilaPasajeros.peek().id << " llega al aeropuerto en el minuto: " << minuto << endl;
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
            for (int l = 0; l < 3; ++l) { //ponerlo en las box
                if (box[l].longitud == 0 && !colaEspera.esVacia()) {
                    box[l].encolar(colaEspera.frente());
                    cout << "Pasajero " << pilaPasajeros.peek().id << " Entra en el box: " << l + 1 << " a la espera de ser atendido en el minuto " << minuto  << endl;
                    colaEspera.desencolar();
                }
            }
            for (int k = 0; k < 3; ++k) {
                if (box[k].longitud != 0) {
                    Persona frentePersona = box[k].frente();
                    frentePersona.tiempo++;
                    frentePersona.horario--;

                    if (frentePersona.horario == 0) {
                        cout << "Pasajero " << pilaPasajeros.peek().id << " Sale del box: " << k + 1 << " tras ser atendido, en el minuto " << minuto << endl;
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

        minuto ++;
    }
    media = media/acciones;
        cout << "La media de tiempo de los pasajeros es " << media<< endl;
    while (!resfinal.esVacia()) {
        cout << "Pasajero " << resfinal.peek().id << " ,tiempo ocupado en el aeropuerto: " << resfinal.peek().tiempo << endl;
        resfinal.desapilar();
    }
    for (int m = 0; m < 3; ++m) {
        if (box[m].longitud != 0) {
            cout << "El box " << m << " está ocupado por el pasajero: " << box[m].frente().id << endl;
        }
    }
    cout << "La simulacion ha tardado este numero de minutos: " << minuto<< endl;
}
