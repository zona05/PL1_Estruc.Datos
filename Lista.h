#ifndef LISTA_H
#define LISTA_H
#include "Cola.h"
#include "NodoLista.h"

class Lista {
    friend class Cola;

private:
    NodoLista* primero;
    NodoLista* ultimo;
    int cntbox;

public:
    Lista();
    Lista(Cola c);
    ~Lista();
    Cola& peak();
    Cola& final();
    Cola& obtener(int n);
    int longitud();
    bool EsVacia();
    void AgregarOrdena(Cola cola);
    void Quitarultimo();
    void mostrarLista();
    int vacios();
    bool todolleno();
    void OrdenaLista();
    int encontrarMenor(Lista *lista);
    int encontrarMayor(Lista* lista);
    void eliminarPos(int n);
    void Quitar();

};



#endif //LISTA_H