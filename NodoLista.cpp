#include "Cola.h"
#include "NodoLista.h"

NodoLista :: NodoLista() {
    cola = Cola();
    siguiente = nullptr;
}

NodoLista::NodoLista(Cola c,NodoLista*sig) {
    cola = c;
    siguiente = sig;
}
NodoLista::~NodoLista() {

}