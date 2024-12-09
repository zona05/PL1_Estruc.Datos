// persona.cpp
#include "persona.h"
using namespace std;

// Constructor con parámetros: inicializa una Persona con id, país, prioridad, inicio, horario y tiempo.
Persona::Persona(int i,  std::string p, int n, int k, int h, int t)
    : id(i), pais(p), prioridad(n), inicio(k), horario(h), tiempo(t) {}

// Destructor: no realiza ninguna acción específica.
Persona::~Persona() {}
