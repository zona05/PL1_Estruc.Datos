
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
Cola& Lista::peak() {
    if (primero == nullptr) {
        cout << "Error: Intento de acceso a cola en lista vacía (peak)." << endl;
        throw std::runtime_error("Acceso a cola en lista vacía.");
    }
    return primero->cola; // Retorna la referencia a `cola` de `primero`
}

Cola& Lista::final() {
    if (ultimo == nullptr) {
        cout << "Error: Intento de acceso a cola en lista vacía (final)." << endl;
        throw std::runtime_error("Acceso a cola en lista vacía.");
    }
    return ultimo->cola; // Retorna la referencia a `cola` de `ultimo`
}
bool Lista::EsVacia() {
    return cntbox == 0;
}
int Lista::longitud() {
    return cntbox;
}
void Lista::AgregarOrdena(Cola cola) {


    NodoLista* aux = new NodoLista(cola);
    if (EsVacia()) {

        primero = aux;
        ultimo = primero;

    }
    else {
        aux -> siguiente = primero;
        primero = aux;
    }
    cntbox++;
}
void Lista::Quitarultimo() {
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
        int numerobox = 1;
        while(aux  !=nullptr) {
            cout << "--- Box ---" << endl;
            cout << "Box: "<< numerobox  << endl;
            aux -> cola.mostrar();
            aux = aux -> siguiente;
            numerobox++;
        }

    }
}
int Lista::vacios() {
    int boxesvacios = 0;
    if (!EsVacia()) {
        NodoLista* aux = primero;

        while(aux  !=nullptr) {

            if(aux -> cola.esVacia()) {
                boxesvacios--;
            }
            aux = aux -> siguiente;

        }

    }
    return boxesvacios;
}
bool Lista::todolleno() {
    int boxesllenos = 0;
    if (!EsVacia()) {
        NodoLista* aux = primero;

        while(aux  !=nullptr) {

            if(aux -> cola.longitud > 2) {
                boxesllenos++;
            }
            aux = aux -> siguiente;

        }

    }

    return boxesllenos == cntbox;
}

void Lista::OrdenaLista() {
    if (EsVacia() || primero->siguiente == nullptr) {

        return;
    }
    NodoLista* aux = primero;
    while (aux != nullptr) {
        NodoLista* aux2 = primero;
        while(aux2 -> siguiente != nullptr) {
            if (aux2 ->cola.longitud < aux2->siguiente -> cola.longitud) {
                Cola temporal = aux2 -> cola;
                aux2->cola = aux2 ->siguiente -> cola;
                aux2 -> siguiente -> cola = temporal;
            }
            aux2 = aux2 -> siguiente;
        }
        aux = aux -> siguiente;
    }
}
Cola& Lista::obtener(int n) {
    NodoLista* actual = primero;
    int indice = 1; // Cambiar a 1 para que coincida con tu índice basado en 1

    while (actual != nullptr && indice < n) {
        actual = actual->siguiente; // Suponiendo que tienes un puntero siguiente en NodoLista
        indice++;
    }

    if (actual != nullptr) {
        return actual->cola; // Devolver la cola correspondiente
    }
}
Lista::~Lista()
{
    while (!EsVacia())
    {
        Quitarultimo();
    }
}