#include "Simulacion.h"
#include <iostream>

using namespace std;

// Constructor: recibe referencias a una pila y una cola externas para inicializar las estructuras.
Simulacion::Simulacion(Pila& pilaExterna, Cola& colaExterna) : pilaPasajeros(pilaExterna), colaEspera(colaExterna) {}

// Destructor: no se necesita realizar ninguna acción adicional, ya que no hay memoria dinámica.
Simulacion::~Simulacion() {}

// mostrarBoxes: muestra la información de los pasajeros en los 3 boxes si están ocupados.
void Simulacion::mostrarBoxes() {
    for (int k = 0; k < 3; ++k) {
        if (box[k].longitud != 0) {
            cout << "Pasajero ID: " << box[k].frente().id
                 << ", País: " << box[k].frente().pais
                 << ", Tiempo restante: " << box[k].frente().horario << " minutos" << endl;
        }
    }
}

// Traspaso: mueve los pasajeros de la pila a la cola de espera si su tiempo de llegada es menor o igual al tiempo actual,
// de lo contrario, los mantiene en la pila auxiliar.
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

// Boxear: asigna a los pasajeros de la cola de espera a los boxes vacíos.
void Simulacion::Boxear() {
    for (int l = 0; l < 3; ++l) {
        if (box[l].longitud == 0 && !colaEspera.esVacia()) {
            box[l].encolar(colaEspera.frente());
            cout << "Pasajero " << colaEspera.frente().id << " Entra en el box: " << l + 1 << " a la espera de ser atendido en el minuto " << tiemposim << endl;
            colaEspera.desencolar();
        }
    }
}

// Boxeamiento: procesa a los pasajeros que están siendo atendidos en los boxes, disminuyendo su tiempo restante de atención.
// Cuando un pasajero es atendido completamente, se mueve al resultado final.
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

// Finalizar: calcula y muestra la media de tiempo de atención de los pasajeros,
// luego imprime la información de todos los pasajeros atendidos y los boxes ocupados al final de la simulación.
void Simulacion::Finalizar() {
    media = media / acciones;
    cout << "La media de tiempo de los pasajeros es " << media << endl;
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

// simularMinutos: simula la operación del sistema durante un número específico de minutos, realizando traspasos, asignaciones a boxes y atendiendo a los pasajeros.
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

// simularEntero: simula la operación completa hasta que todos los pasajeros hayan sido atendidos.
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
