
#include "SimulacionLista.h"
#include <iostream>

using namespace std;

SimulacionLista::SimulacionLista(Pila& pilaExterna, Lista& listaExterna) : pilaPasajeros(pilaExterna), lista(listaExterna) {}

SimulacionLista::~SimulacionLista() {

}
void SimulacionLista::TraspasoLista() {


    while (!pilaPasajeros.esVacia()) { //pila a cola
        if (pilaPasajeros.peek().inicio == tiemposim) {
            int destinacion;
            destinacion = lista.encontrarMenor(&lista);
            Cola& colabox = lista.obtener(destinacion + 1);
            colabox.encolar(pilaPasajeros.peek());
            cout << "Pasajero " << pilaPasajeros.peek().id << " llega al aeropuerto en el minuto: " << tiemposim << endl;
        } else {
            aux.apilar(pilaPasajeros.peek());

        }
        pilaPasajeros.desapilar();
    }
    while (!aux.esVacia()) {
        pilaPasajeros.apilar(aux.peek());
        aux.desapilar();
    }
}
void SimulacionLista::BoxeamientoLista() {
    for (int k = 1; k < lista.longitud() +1 ; ++k) {  // Asumiendo que los índices comienzan en 1
        Cola& colabox = lista.obtener(k);  // Obtener la cola actual

        // Aumentar el tiempo para todas las personas en la cola.
        int totalPersonas = colabox.longitud;  // Obtener el número de personas en la cola

        // Aumentar el tiempo de todas las personas en la cola
        if (!colabox.esVacia()) {
            for (int i = 0; i < totalPersonas ; ++i) {
                Persona& persona = colabox.obtenerPersona(i);  // Obtener persona por índice
                persona.tiempo++;  // Aumenta el tiempo de cada persona
            }
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
    for (int m = 1; m < lista.longitud() +1 ; ++m) {
        if (lista.obtener(m).longitud != 0) {
            cout << "El box " << m << " está ocupado por el pasajero: " << lista.obtener(m).frente().id << endl;
        }
    }
}
void SimulacionLista::QuitarBoxes() {
    if (lista.vacios() > 2) {
        for (int k = 0; k < lista.vacios(); ++k) {
            if (lista.longitud() > 1) {
                int menor = lista.encontrarMayor(&lista);
                lista.eliminarPos(menor);
                 // Asegúrate de que Quitarultimo esté implementado
            }
        }
    }
}
void SimulacionLista::AgregarBoxes() {
    if (lista.todolleno()) {
        Cola colatest;
        lista.AgregarOrdena(colatest);
    }
}
void SimulacionLista::simularMinutosLista(int minutos) {
    for (int i = 0; i < minutos; ++i) {
        cout << "Simulando minuto: " << tiemposim << endl;
        TraspasoLista();
        BoxeamientoLista();
        QuitarBoxes();
        AgregarBoxes();
        tiemposim++;
    }
    FinalizarLista();
}



void SimulacionLista::simularEnteroLista() {
    tiemposim = 0;
    int a = pilaPasajeros.contar();
    while (resfinal.contar() != a) {
        TraspasoLista();
        BoxeamientoLista();
        QuitarBoxes();
        AgregarBoxes();
        tiemposim++;
    }
    FinalizarLista();

    cout << "La simulación ha tardado este número de minutos: " << tiemposim << endl;
}