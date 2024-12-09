#include "NodoABB.h"

NodoABB::NodoABB() {
    nombre = "";
    lista = Lista();
    hi = nullptr;
    hd = nullptr;
}
NodoABB::NodoABB( string nombre, const Lista& lista)
    : nombre(nombre), lista(lista), hi(nullptr), hd(nullptr) {
    cout << "Nodo creado: " << nombre << endl;
}

NodoABB::~NodoABB() {}

void NodoABB::verNombres() const {
    cout << "Nombre: " << nombre << endl;
}