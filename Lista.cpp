#include "NodoLista.h"
#include "Lista.h"
#include "Cola.h"
#include "NodoCola.h"
#include <iostream>
#include <algorithm>
using namespace std;

// Constructor: inicializa una lista vacía.
Lista::Lista() {
    primero = nullptr;
    ultimo = nullptr;
    cntbox = 0;
}

// Constructor que toma una cola (c), crea un nodo con esa cola y la coloca en la lista.
Lista::Lista(Cola c) {
    primero = new NodoLista(c);
    ultimo = primero;
    cntbox = 1;
}

// peak: devuelve la cola en el primer nodo de la lista (sin eliminarla).
Cola& Lista::peak() {
    if (primero == nullptr) {
        cout << "Error: Intento de acceso a cola en lista vacía (peak)." << endl;
        throw std::runtime_error("Acceso a cola en lista vacía.");
    }
    return primero->cola;
}

// final: devuelve la cola en el último nodo de la lista (sin eliminarla).
Cola& Lista::final() {
    if (ultimo == nullptr) {
        cout << "Error: Intento de acceso a cola en lista vacía (final)." << endl;
        throw std::runtime_error("Acceso a cola en lista vacía.");
    }
    return ultimo->cola;
}

// EsVacia: verifica si la lista está vacía, basada en el contador de boxes.
bool Lista::EsVacia() {
    return cntbox == 0;
}

// longitud: devuelve el número de elementos (boxes) en la lista.
int Lista::longitud() {
    return cntbox;
}

// AgregarOrdena: agrega un nuevo nodo con una cola al principio de la lista y aumenta el contador de boxes.
void Lista::AgregarOrdena(Cola cola) {
    NodoLista* aux = new NodoLista(cola);
    if (EsVacia()) {
        primero = aux;
        ultimo = primero;
    } else {
        aux->siguiente = primero;
        primero = aux;
    }
    cntbox++;
}

// Quitarultimo: elimina el último nodo de la lista.
void Lista::Quitarultimo() {
    NodoLista* aux;
    if (cntbox >= 2) {
        aux = primero;
        while (aux->siguiente->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        ultimo = aux;
        ultimo->siguiente = nullptr;
        cntbox--;
    }
}

// mostrarLista: muestra todas las colas de los nodos en la lista, indicando cuál box corresponde a cada una.
void Lista::mostrarLista() {
    if (!EsVacia()) {
        NodoLista* aux = primero;
        int numerobox = 1;
        while (aux != nullptr) {
            cout << "--- Box ---" << endl;
            cout << "Box: " << numerobox << endl;
            aux->cola.mostrar();
            aux = aux->siguiente;
            numerobox++;
        }
    }
}

// vacios: cuenta y devuelve la cantidad de boxes vacíos en la lista.
int Lista::vacios() {
    int boxesvacios = 0;
    if (!EsVacia()) {
        NodoLista* aux = primero;
        while (aux != nullptr) {
            if (aux->cola.esVacia()) {
                boxesvacios++;
            }
            aux = aux->siguiente;
        }
    }
    return boxesvacios;
}

// todolleno: verifica si todos los boxes están llenos (más de 2 elementos).
bool Lista::todolleno() {
    int boxesllenos = 0;
    if (!EsVacia()) {
        NodoLista* aux = primero;
        while (aux != nullptr) {
            if (aux->cola.longitud > 2) {
                boxesllenos++;
            }
            aux = aux->siguiente;
        }
    }
    return boxesllenos == cntbox;
}

// encontrarMenor: encuentra el box con la cola de menor longitud y retorna su posición.
int Lista::encontrarMenor(Lista* lista) {
    if (lista->EsVacia()) {
        return -1;
    }

    int posicion_menor = 0;
    int posicion_actual = 0;
    int longitud_menor = lista->primero->cola.longitud;

    NodoLista* actual = lista->primero;

    while (actual != nullptr) {
        if (actual->cola.longitud < longitud_menor) {
            longitud_menor = actual->cola.longitud;
            posicion_menor = posicion_actual;
        }
        actual = actual->siguiente;
        posicion_actual++;
    }

    return posicion_menor;
}

// encontrarMayor: encuentra el box con la cola de mayor longitud y retorna su posición.
int Lista::encontrarMayor(Lista* lista) {
    if (lista->EsVacia()) {
        return -1;
    }

    int posicion_mayor = 0;
    int posicion_actual = 0;
    int longitud_mayor = lista->primero->cola.longitud;

    NodoLista* actual = lista->primero;

    while (actual != nullptr) {
        if (actual->cola.longitud > longitud_mayor) {
            longitud_mayor = actual->cola.longitud;
            posicion_mayor = posicion_actual;
        }
        actual = actual->siguiente;
        posicion_actual++;
    }

    return posicion_mayor;
}

// OrdenaLista: ordena la lista de boxes de mayor a menor según la longitud de las colas.
void Lista::OrdenaLista() {
    if (EsVacia() || primero->siguiente == nullptr) {
        return;
    }
    NodoLista* aux = primero;
    while (aux != nullptr) {
        NodoLista* aux2 = primero;
        while (aux2->siguiente != nullptr) {
            if (aux2->cola.longitud < aux2->siguiente->cola.longitud) {
                std::swap(aux2->cola, aux2->siguiente->cola);
            }
            aux2 = aux2->siguiente;
        }
        aux = aux->siguiente;
    }
}

// obtener: devuelve la cola en la posición n de la lista.
Cola& Lista::obtener(int n) {
    NodoLista* actual = primero;
    int indice = 1;

    while (actual != nullptr && indice < n) {
        actual = actual->siguiente;
        indice++;
    }

    if (actual != nullptr) {
        return actual->cola;
    }
}

// eliminarPos: elimina el nodo en la posición n de la lista.
void Lista::eliminarPos(int n) {
    if (n < 0 || n >= cntbox) {
        cout << "Posición inválida." << std::endl;
        return;
    }

    NodoLista* temp = primero;

    if (n == 0) {
        primero = primero->siguiente;
        delete temp;
    } else {
        for (int i = 0; i < n - 1; i++) {
            temp = temp->siguiente;
        }

        NodoLista* nodoAEliminar = temp->siguiente;
        temp->siguiente = nodoAEliminar->siguiente;

        if (nodoAEliminar == ultimo) {
            ultimo = temp;
        }

        delete nodoAEliminar;
    }

    cntbox--;
}

// Destructor: elimina todos los nodos de la lista y libera la memoria.
Lista::~Lista() {
    while (!EsVacia()) {
        Quitarultimo();
    }
}
