
#include "NodoCola.h"
NodoCola::NodoCola(){
    siguiente=nullptr;
    valor = valor();

}

NodoCola::NodoCola(int v, NodoCola*sig ){
    valor = v;
    siguiente = sig;
}

NodoCola::~NodoCola() {

}