#ifndef ABB_H
#define ABB_H

#include <iostream>
#include <string>
#include "NodoABB.h"
#include "Lista.h"
#include "SimulacionLista.h"
#include "Pila.h"

using namespace std;

class ABB {
public:
    ABB();
    ABB(NodoABB* r);
    ABB(string nom, NodoABB* hIz = nullptr, NodoABB* hDer = nullptr, Lista lista);

    virtual ~ABB();

    void insertar(string nom);
    void destruirArbol(NodoABB* nodo);
    int comparaAlfabeto(string str1, string str2);
    void mostrarNodo(NodoABB* nodo);
    void mayorPais2(NodoABB* nodo);
    void mayorPais();

protected:

    void verInOrden();
    void verInOrden2(NodoABB* arb);
    void buscarOInsertar( string nom, Lista lista,SimulacionLista simulacion);

private:
    NodoABB* raiz;
};

#endif // ABB_H