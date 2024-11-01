
#ifndef LISTA_H
#define LISTA_H



class Lista {
private:
    NodoLista* primero;
    NodoLista* ultimo;
    int cntbox;

public:
    Lista();
    ~Lista();
    Cola Peak();
    Cola Final();
    int Longitud();
    bool EsVacia();
    void AgregarOrdena(Cola cola);
    void Quitarultimo(Cola cola);
    void mostrarLista();
    void vacios();
    void todolleno();


};



#endif //LISTA_H
