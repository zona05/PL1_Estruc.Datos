#include "Simulacion.h"
#include <iostream>

using namespace std;

Simulacion::Simulacion(Pila& pilaExterna, Lista& listaExterna): pilaPasajeros(pilaExterna), listaBox(listaExterna){}

Simulacion::~Simulacion() {
    // Aquí puedes liberar recursos si es necesario.
}

void Simulacion::Traspaso() {
    Pila aux;

    while (!pilaPasajeros.esVacia()) { // Pila a cola
        if (pilaPasajeros.peek().inicio == tiemposim) {
            Cola colabox = listaBox.peak(); // Usar referencia
            colabox.encolar(pilaPasajeros.peek());
            cout << "Pasajero " << pilaPasajeros.peek().id << " llega al aeropuerto en el minuto: " << tiemposim << endl;
            aux.apilar(pilaPasajeros.peek());
            pilaPasajeros.desapilar();
            listaBox.OrdenaLista();
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

void Simulacion::Boxeamiento() {
    for (int k = 1; k < listaBox.longitud(); ++k) {
        Cola colabox = listaBox.obtener(k);
        if (colabox.longitud != 0) { // Asegurarse de que la cola no esté vacía
            Persona frentePersona = colabox.frente();
            frentePersona.tiempo++;
            frentePersona.horario--;

            if (frentePersona.horario == 0) {
                cout << "Pasajero " << frentePersona.id << " Sale del box: " << k + 1
                     << " tras ser atendido en el minuto " << tiemposim << endl;
                media += frentePersona.tiempo;
                resfinal.apilar(frentePersona);
                colabox.desencolar();
                acciones++;
            } else {
                colabox.desencolar();
                colabox.encolar(frentePersona);
            }
        }
    }
}

void Simulacion::AgregarBoxes() {
    if (listaBox.todolleno()) {
        listaBox.AgregarOrdena(cola);
    }
}

void Simulacion::QuitarBoxes() {
    if (listaBox.vacios() >= 2) {
        for (int k = 0; k < listaBox.vacios(); ++k) {
            if (listaBox.longitud() > 1) {
                listaBox.Quitarultimo(); // Asegúrate de que Quitarultimo esté implementado
            }
        }
    }
}

void Simulacion::Finalizar() {
    if (acciones > 0) { // Para evitar división por cero
        media /= acciones;
        cout << "La media de tiempo de los pasajeros es " << media << endl;
    }
    while (!resfinal.esVacia()) {
        cout << "Pasajero " << resfinal.peek().id << ", tiempo ocupado en el aeropuerto: " << resfinal.peek().tiempo << endl;
        resfinal.desapilar();
    }
}

void Simulacion::simularMinutos(int minutos) {
    for (int i = 0; i < minutos; ++i) {
        tiemposim = i;
        Traspaso();
        Boxeamiento();
        AgregarBoxes();
        listaBox.OrdenaLista();
        QuitarBoxes();
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

        // Paso 3: Atender a los pasajeros en los boxes
        Boxeamiento();

        // Incrementa el tiempo de simulación
        tiemposim++;
    }

    // Paso 4: Mostrar resultados finales
    Finalizar();

    cout << "La simulación ha tardado este número de minutos: " << tiemposim << endl;
}