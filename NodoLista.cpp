#include "Cola.h"
#include "NodoLista.h"

// Constructor por defecto: inicializa una Cola vacía y el puntero siguiente en nullptr.
NodoLista::NodoLista() {
    cola = Cola();
    siguiente = nullptr;
}

// Constructor con parámetros: inicializa el nodo con una Cola y el puntero al siguiente nodo.
NodoLista::NodoLista(Cola c, NodoLista* sig) {
    cola = c;
    siguiente = sig;
}

// Destructor: no realiza ninguna acción específica.
NodoLista::~NodoLista() {
}
