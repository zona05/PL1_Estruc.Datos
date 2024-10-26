#include "Simulacion.h"
#include <iostream>
#include <algorithm>

void Simulacion::iniciarSimulacion() {
    while (true) {
        procesarLlegadaPasajeros();
        moverAPasajeroDesdeCola();
        actualizarBoxes();
        mostrarBoxes();

        if (std::none_of(boxes.begin(), boxes.end(), [](const Persona& p) { return p.tiempo > 0; })) {
            break;
        }
    }
}

void Simulacion::procesarLlegadaPasajeros() {
    while (!pilaPasajeros.esVacia() && pilaPasajeros.peek().inicio <= tiempoActual) {
        Persona pasajero = pilaPasajeros.desapilar();
        colaEspera.encolar(pasajero);
    }
}

void Simulacion::moverAPasajeroDesdeCola() {
    for (auto& box : boxes) {
        if (box.tiempo == 0 && !colaEspera.esVacia()) {
            box = colaEspera.desencolar();
        }
    }
}

void Simulacion::actualizarBoxes() {
    for (auto& box : boxes) {
        if (box.tiempo > 0) {
            box.tiempo--;
        }
    }
}

void Simulacion::mostrarBoxes() {
    for (const auto& box : boxes) {
        if (box.tiempo > 0) {
            std::cout << "Pasajero ID: " << box.id << ", País: " << box.pais
                      << ", Tiempo restante: " << box.tiempo << " minutos" << std::endl;
        }
    }
}

void Simulacion::simularMinutos(int minutos) {
    for (int i = 0; i < minutos; ++i) {
        moverAPasajeroDesdeCola();
        actualizarBoxes();
    }
}

void Simulacion::simularCompleto() {
    iniciarSimulacion();
}
