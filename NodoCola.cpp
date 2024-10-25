#include "NodoCola.h"
NodoCola::NodoCola(){
    siguiente=nullptr;
    persona = Persona();

}

NodoCola::NodoCola(Persona p , NodoCola*sig ){
    persona = p;
    siguiente = sig;
}

NodoCola::~NodoCola() {

}
