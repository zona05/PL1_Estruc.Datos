// persona.h
#ifndef PERSONA_H
#define PERSONA_H

#include <string>

struct Persona {
    int id;
    std::string pais;
    int prioridad;
    int inicio;
    int horario;
    int tiempo;

    Persona() : id(0), pais(""), prioridad(0), inicio(0),  horario (0),tiempo(0) {}

    Persona(int i, const std::string& p, int n, int k, int h,int t);
    ~Persona();
};

#endif  // PERSONA_H
