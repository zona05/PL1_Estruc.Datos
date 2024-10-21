
#include "NodoPila.h"

NodoPila::NodoPila(){
    valor=valor();
    siguiente=nullptr;
}

NodoPila::NodoPila(int v, NodoPila *sig){
    valor = v;
    siguiente = sig;
}


NodoPila::~NodoPila(){
}