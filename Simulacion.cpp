#include "Simulacion.h"
#include <iostream>
#include <algorithm>
Simulacion::Simulacion(){
    Pila pilaPasajeros;
    Cola colaEspera;
    Cola box[3];
    Pila auxPila;
}



Simulacion::~Simulacion(){
    //Destructor
}
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
    Cola Box[3] ;
    for (int i = 0; i < minutos; ++i) {
        Pila aux;
        while (!pilaPasajeros.esVacia()) {
            if(pilaPasajeros.peek().horario == i) {
                colaEspera.encolar(pilaPasajeros.peek());
                colaEspera.encolarprioridad(pilaPasajeros.peek());
                aux.apilar(pilaPasajeros.peek());
                pilaPasajeros.desapilar();
            }
            else {
                aux.apilar(pilaPasajeros.peek());
                pilaPasajeros.desapilar();

            }
        }
        while (!aux.esVacia()) {
            pilaPasajeros.apilar(aux.peek());
            aux.desapilar();
        }
        for (int l = 0; l < 3; ++l) {
            if (box[l].longitud == 0 && !colaEspera.esVacia()) {
            box[l].encolar(colaEspera.frente());
            colaEspera.desencolar();
            }
        }
        for (int k = 0; k < 3; ++k) {
            if (box[k].longitud == 1) {
                Persona frentePersona = box[k].frente();
                frentePersona.tiempo ++;
                frentePersona.horario --;
                if (frentePersona.horario == 0) {
                    media = media + frentePersona.tiempo;
                    box[k].desencolar();
                    acciones ++;
                }
            }




    }
}

void Simulacion::simularCompleto() {
    iniciarSimulacion();
}
