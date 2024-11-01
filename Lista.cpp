
#include "NodoLista.h"
#include "Lista.h"
#include "Cola.h"
#include "NodoCola.h"
#include <iostream>
using namespace std;

Lista::Lista() {

    primero = nullptr;
    ultimo = nullptr;
    cntbox = 0;
}
Lista::Lista(Cola c)
{
    primero = new NodoLista(c);
    ultimo = primero;
    cntbox = 1;
}
Cola Lista::Peak() {
    return primero -> cola;
}
Cola Lista::Final() {
    return ultimo -> cola;
}
bool Lista::EsVacia() {
    return cntbox == 0;
}
int Lista::Longitud() {
    return cntbox;
}
void Lista::AgregarOrdena(Cola cola) {

    cntbox++;
    NodoLista* aux = new NodoLista(cola);
    if (EsVacia()) {

        primero = aux;
        ultimo = primero;

    }
    else {
        aux -> siguiente = primero;
        primero = aux;
    }
}
void Lista::Quitarultimo(Cola cola) {
    NodoLista* aux ;
    if(cntbox>=2) {
        aux = primero;
        while(aux -> siguiente-> siguiente !=nullptr) {
            aux = aux -> siguiente;
        }
        ultimo = aux;
        ultimo -> siguiente = nullptr;
        cntbox--;
    }
}
void Lista::mostrarLista() {
    if (!EsVacia()) {
        NodoLista* aux = primero;
        int numerobox = cntbox;
        while(aux  !=nullptr) {
            cout << "--- Box ---" << endl;
            cout << "Box: "<< numerobox <<": "  << endl;
            aux -> cola.mostrar();
            aux = aux -> siguiente;
            numerobox--;
        }

    }
}
int Lista::vacios() {
    if (!EsVacia()) {
        NodoLista* aux = primero;
        int boxesvacios = 0;
        while(aux  !=nullptr) {

            if(aux -> cola.esVacia()) {
                boxesvacios--;
            }
            aux = aux -> siguiente;

        }
        return boxesvacios;
    }

}
bool Lista::todolleno() {
    if (!EsVacia()) {
        NodoLista* aux = primero;
        int boxesllenos = 0;
        while(aux  !=nullptr) {

            if(aux -> cola.longitud > 2) {
                boxesllenos++;
            }
            aux = aux -> siguiente;

        }
        return boxesllenos == cntbox;
    }

}
