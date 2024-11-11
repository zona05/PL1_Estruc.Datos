
#include "SimulacionLista.h"
#include <iostream>

using namespace std;

SimulacionLista::SimulacionLista(Pila& pilaExterna, Lista& listaExterna) : pilaPasajeros(pilaExterna), lista(listaExterna) {}

SimulacionLista::~SimulacionLista() {

}
void SimulacionLista::TraspasoLista() {
    Pila aux;

    while (!pilaPasajeros.esVacia()) { //pila a cola
        if (pilaPasajeros.peek().inicio == tiemposim) {
            int destinacion;
            destinacion = lista.encontrarMenor(&lista);
            Cola& colabox = lista.obtener(destinacion);
            colabox.encolar(pilaPasajeros.peek());
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
void SimulacionLista::BoxeamientoLista() {
    for (int k = 0; k < lista.longitud() +1; ++k) {  // Asumiendo que los índices comienzan en 1
        Cola& colabox = lista.obtener(k);  // Obtener la cola actual

        // Aumentar el tiempo para todas las personas en la cola.
        int totalPersonas = colabox.longitud;  // Obtener el número de personas en la cola

        // Aumentar el tiempo de todas las personas en la cola
        for (int i = 0; i < totalPersonas +1; ++i) {
            Persona& persona = colabox.obtenerPersona(i);  // Obtener persona por índice
            persona.tiempo++;  // Aumenta el tiempo de cada persona
        }

        // Disminuir el horario solo para la persona al frente (primer elemento)
        if (totalPersonas > 0) {
            Persona& frentePersona = colabox.frente();  // Obtener la persona al frente como referencia
            frentePersona.horario--;  // Disminuir el horario

            // Comprobar si la persona ha terminado
            if (frentePersona.horario == 0) {
                cout << "Pasajero " << frentePersona.id << " Sale del box: " << k
                     << " tras ser atendido en el minuto " << tiemposim + 1 << endl;
                media += frentePersona.tiempo;
                resfinal.apilar(frentePersona);
                colabox.desencolar();  // Desencolar a la persona que terminó
                acciones++;
            }
            // Si no ha terminado, no hacemos nada (la dejamos en el frente)
        }
    }
}
void SimulacionLista::FinalizarLista() {
    media = media/acciones;
    cout << "La media de tiempo de los pasajeros es " << media<< endl;
    while (!resfinal.esVacia()) {
        cout << "Pasajero " << resfinal.peek().id << ", tiempo ocupado en el aeropuerto: " << resfinal.peek().tiempo << endl;
        resfinal.desapilar();
    }
    for (int m = 0; m < lista.longitud() +1 ; ++m) {
        if (lista.obtener(m).longitud != 0) {
            cout << "El box " << m << " está ocupado por el pasajero: " << lista.obtener(m).frente().id << endl;
        }
    }
}
void SimulacionLista::simularMinutosLista(int minutos) {
    Pila resfinal;

    for (int i = 0; i < minutos; ++i) {
        tiemposim = i;  // Actualiza el tiempo actual de la simulación

        // Paso 1: Pasar los pasajeros de la pila a la cola de espera
        TraspasoLista();

        // Paso 2: Asignar pasajeros de la cola de espera a los boxes

        // Paso 3: Atender a los pasajeros en los boxes
        BoxeamientoLista();


    }

    // Paso 4: Mostrar resultados finales
    FinalizarLista();
}