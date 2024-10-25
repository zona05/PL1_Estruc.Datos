// persona.h
#ifndef PERSONA_H  // Directiva para evitar inclusiones múltiples
#define PERSONA_H

#include <string>

struct Persona {
    int id;                  // ID único para cada persona
    std::string pais;        // País de la persona
    int prioridad;
    int inicio; // Un número del 1 al 10
    double tiempo;

    // Constructor por defecto
    Persona() : id(0), pais(""), prioridad(0), inicio(0), tiempo(0.0) {}

    // Declaración del constructor
    Persona(int i, const std::string& p, int n, int k, double t);
    ~Persona();
};

#endif  // PERSONA_H
