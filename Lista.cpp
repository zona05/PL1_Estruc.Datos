
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
Cola Lista::peak() {
    return primero -> cola;
}
Cola Lista::final() {
    return ultimo -> cola;
}
bool Lista::EsVacia() {
    return cntbox == 0;
}
int Lista::longitud() {
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
Cola Lista::obtener(int n) {

    NodoLista* actual = primero;
    int indice = 0;

    while (actual != nullptr && indice < n) {
        actual = actual->siguiente;  // Suponiendo que tienes un puntero siguiente en NodoLista
        indice++;
    }

    return actual->cola;  // Suponiendo que `dato` es el atributo que almacena la Cola en NodoLista
}
Lista::~Lista()
{
    while (!EsVacia())
    {
        Quitarultimo();
    }
}