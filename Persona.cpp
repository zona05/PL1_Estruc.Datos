// persona.cpp
#include "persona.h"
using namespace std;
// Implementación del constructor de Persona
Persona::Persona(int i, const string& p, int n, int k, int h,int t)
    : id(i), pais(p), prioridad(n),inicio(k),  horario(h), tiempo(t) {}

Persona::~Persona(){}