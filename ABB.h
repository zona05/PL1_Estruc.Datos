#ifndef ABB_H
#define ABB_H

#include <iostream>
#include <string>
#include "NodoABB.h"
#include "Lista.h"

#include "Pila.h"

using namespace std;

class ABB {
public:
    ABB();
    ABB(NodoABB* r);


    virtual ~ABB();

    void insertar(string nom);
    void destruirArbol(NodoABB* nodo);
    int comparaAlfabeto(string str1, string str2);
    void mostrarNodo(NodoABB* nodo);
    void mayorymenor(NodoABB* raiz,NodoABB*& nodo_max, NodoABB*& nodo_min);



    void verPreorden();
    void verPreorden2(NodoABB* arb);
/*    void buscarOInsertar(Lista lista,SimulacionLista simulacion); */
    void vertmpomedio(string pais);
    void vertmpomedio2(NodoABB* arb ,string pais);
    void vertmpomediotodos();
    void vertmpomediotodos2(NodoABB* arb);
    void verPais(string pais);
    void verPais2(NodoABB* arb, string pais);
    void verDatos();
    void verDatos2(NodoABB* arb);
    void insertarteclado(Persona persona);



    NodoABB* raiz;
};

#endif // ABB_H