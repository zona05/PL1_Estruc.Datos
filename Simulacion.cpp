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
            if (listaBox.EsVacia() || listaBox.todolleno()) {
                Cola colatest;
                listaBox.AgregarOrdena(colatest);
                listaBox.OrdenaLista();
            }

            Cola& colabox = (listaBox.todolleno())
                            ? listaBox.peak()
                            : listaBox.final();

            // Imprimir antes de encolar
            cout << "Encolando persona: " << pilaPasajeros.peek().id << endl;
            colabox.encolar(pilaPasajeros.peek()); // Agrega la persona a la cola
            cout << "Pasajero " << pilaPasajeros.peek().id
                 << " llega al aeropuerto en el minuto: " << tiemposim << endl;

            pilaPasajeros.desapilar();

        } else {
            aux.apilar(pilaPasajeros.peek());
            pilaPasajeros.desapilar();
        }
}

    // Restaurar los pasajeros que no se encolaron a pilaPasajeros
        while (!aux.esVacia()) {
            pilaPasajeros.apilar(aux.peek());
            aux.desapilar();
        }

    // Ordenar listaBox después de terminar (esto podría ser redundante)
    // listaBox.OrdenaLista();  // Si es necesario solo en el contexto apropiado
}
void Simulacion::Boxeamiento() {
    for (int k = 1; k < listaBox.longitud() +1; ++k) {  // Asumiendo que los índices comienzan en 1
        Cola& colabox = listaBox.obtener(k);  // Obtener la cola actual

        // Aumentar el tiempo para todas las personas en la cola.
        int totalPersonas = colabox.longitud;  // Obtener el número de personas en la cola

        // Aumentar el tiempo de todas las personas en la cola
        for (int i = 0; i < totalPersonas; ++i) {
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
void Simulacion::AgregarBoxes() {
    if (listaBox.todolleno()) {
        Cola colatest;
        listaBox.AgregarOrdena(colatest);
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
    listaBox.AgregarOrdena(cola);
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
    listaBox.mostrarLista();
}

void Simulacion::simularEntero() {
    tiemposim = 0;

    // Ejecuta el ciclo de simulación hasta que todos los pasajeros hayan sido atendidos
    while (resfinal.contar() != pilaPasajeros.contar()) {
        // Paso 1: Pasar los pasajeros de la pila a la cola de espera
        Traspaso();
        Boxeamiento();
        AgregarBoxes();
        listaBox.OrdenaLista();
        QuitarBoxes();

    }

    // Paso 4: Mostrar resultados finales
    Finalizar();

    cout << "La simulacion ha tardado este numero de minutos: " << tiemposim << endl;
}