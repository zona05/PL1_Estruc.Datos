#include "NodoABB.h"


NodoABB::NodoABB( string nombre, Lista lista)
    : nombre(nombre), lista(lista), hi(nullptr), hd(nullptr) {}

NodoABB::~NodoABB() {}

void NodoABB::verNombres() const {
    cout << "Nombre: " << nombre << endl;
}