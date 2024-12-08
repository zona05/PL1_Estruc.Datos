#include "ABB.h"
#include "SimulacionLista.h"
#include <iostream>

using namespace std;

// Constructor: inicializa la simulación con las referencias a la pila de pasajeros y la lista de colas.
SimulacionLista::SimulacionLista(Pila& pilaExterna, Lista& listaExterna, ABB& abbExterna) : pilaPasajeros(pilaExterna), lista(listaExterna), abb2(abbExterna) {}

// Destructor: no se realiza ninguna acción adicional ya que no hay memoria dinámica.
SimulacionLista::~SimulacionLista() {}
Pila SimulacionLista::SacarResfinal() {
    return resfinal;
}
// TraspasoLista: mueve los pasajeros de la pila hacia las colas en la lista,
// dependiendo del tiempo de llegada del pasajero, y ordena la pila auxiliar.
void SimulacionLista::TraspasoLista() {
    while (!pilaPasajeros.esVacia()) {
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

// BoxeamientoLista: atiende a los pasajeros en las colas de la lista,
// decrementando su tiempo de atención y moviéndolos a la lista de resultados cuando son atendidos.
void SimulacionLista::BoxeamientoLista() {
    for (int k = 1; k < lista.longitud() + 1; ++k) {
        Cola& colabox = lista.obtener(k);

        int totalPersonas = colabox.longitud;

        if (!colabox.esVacia()) {
            for (int i = 0; i < totalPersonas; ++i) {
                Persona& persona = colabox.obtenerPersona(i);
                persona.tiempo++;
            }
        }

        if (totalPersonas > 0) {
            Persona& frentePersona = colabox.frente();
            frentePersona.horario--;

            if (frentePersona.horario == 0) {
                cout << "Pasajero " << frentePersona.id << " Sale del box: " << k
                     << " tras ser atendido en el minuto " << tiemposim + 1 << endl;
                media += frentePersona.tiempo;
                resfinal.apilar(frentePersona);
                colabox.desencolar();
                acciones++;
                abb2.insertarteclado(frentePersona);

            }
        }
    }
}

// FinalizarLista: calcula la media de tiempo de los pasajeros, muestra el resultado de la simulación y
// imprime el estado de las colas en los boxes al final.
void SimulacionLista::FinalizarLista() {
    media = media / acciones;
    cout << "La media de tiempo de los pasajeros es " << media << endl;
    while (!resfinal.esVacia()) {
        cout << "Pasajero " << resfinal.peek().id << ", tiempo ocupado en el aeropuerto: " << resfinal.peek().tiempo << endl;
        resfinal.desapilar();
    }
    for (int m = 1; m < lista.longitud() + 1; ++m) {
        if (lista.obtener(m).longitud != 0) {
            cout << "El box " << m << " está ocupado por el pasajero: " << lista.obtener(m).frente().id << endl;
        }
    }
}

// QuitarBoxes: elimina los boxes que están vacíos si hay más de 2, buscando el box con mayor longitud.
void SimulacionLista::QuitarBoxes() {
    if (lista.vacios() > 2) {
        for (int k = 0; k < lista.vacios(); ++k) {
            if (lista.longitud() > 1) {
                int menor = lista.encontrarMenor(&lista);
                lista.eliminarPos(menor);
            }
        }
    }
}

// AgregarBoxes: agrega un nuevo box a la lista si todos los boxes están llenos.
void SimulacionLista::AgregarBoxes() {
    if (lista.todolleno()) {
        Cola colatest;
        lista.AgregarOrdena(colatest);
    }
}

// simularMinutosLista: simula el funcionamiento del sistema durante un número específico de minutos,
// realizando los traspasos, atendiendo a los pasajeros y ajustando el número de boxes disponibles.
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

// simularEnteroLista: simula la operación completa hasta que todos los pasajeros hayan sido atendidos,
// ajustando la cantidad de boxes disponibles según sea necesario.
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
