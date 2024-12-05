#include "ABB.h"
#include "SimulacionLista.h"

ABB::ABB() : raiz(nullptr) {}

ABB::ABB(NodoABB* r) : raiz(r) {}

ABB::ABB(string nom, NodoABB* hIz, NodoABB* hDer, Lista lista) {
    raiz = new NodoABB(nom, lista);
    raiz->hi = hIz;
    raiz->hd = hDer;
}

ABB::~ABB() {
    destruirArbol(raiz);
}

void ABB::destruirArbol(NodoABB* nodo) {
    if (nodo != nullptr) {
        destruirArbol(nodo->hi);
        destruirArbol(nodo->hd);
        delete nodo;
    }
}

void ABB::verInOrden() {
    verInOrden2(raiz);
}

void ABB::verInOrden2(NodoABB* arb) {
    NodoABB* actual = arb;

    while (actual != nullptr) {
        if (actual->hi == nullptr) {
            // Si no hay hijo izquierdo, procesamos el nodo y vamos al derecho.
            mostrarNodo(actual);
            actual = actual->hd;
        } else {
            // Encontramos el predecesor en el subárbol izquierdo.
            NodoABB* predecesor = actual->hi;
            while (predecesor->hd != nullptr && predecesor->hd != actual) {
                predecesor = predecesor->hd;
            }

            if (predecesor->hd == nullptr) {
                // Hacemos un enlace temporal al nodo actual.
                predecesor->hd = actual;
                actual = actual->hi;
            } else {
                // Eliminamos el enlace temporal y procesamos el nodo.
                predecesor->hd = nullptr;
                mostrarNodo(actual);
                actual = actual->hd;
            }
        }
    }
}


void ABB::buscarOInsertar(string nom, Lista lista, SimulacionLista simulacion) {
    if (simulacion.SacarResfinal().esVacia()) {
        cout << "Simulación vacía, no se puede procesar." << endl;
        return;
    }

    Persona personamid = simulacion.SacarResfinal().peek();
    string str2 = personamid.pais;

    NodoABB* actual = raiz;
    NodoABB* padre = nullptr;

    // Buscar el nodo con el ID correspondiente
    while (actual != nullptr) {
        if (!actual->lista.peak().esVacia() &&  comparaAlfabeto( actual->lista.peak().frente().pais,str2)== 0) {
            actual->lista.peak().encolar(personamid);
            cout << "Nodo encontrado: " << actual->nombre << endl;
            return;
        }
        padre = actual;
        padre->lista.peak().encolar(personamid);
        if (comparaAlfabeto( actual->lista.peak().frente().pais,str2)== 1) {
            actual = actual->hi;
        } else {
            actual = actual->hd;
        }
    }

    // Crear un nuevo nodo si no se encontró el ID
    NodoABB* nuevoNodo = new NodoABB(personamid.pais, lista);
    nuevoNodo->lista.peak().encolar(personamid);

    if (padre == nullptr) {
        raiz = nuevoNodo;
    } else if (comparaAlfabeto( actual->lista.peak().frente().pais,str2)== 1) {
        padre->hi = nuevoNodo;
    } else if (comparaAlfabeto( actual->lista.peak().frente().pais,str2)== 2) {
        padre->hd = nuevoNodo;
    }

    cout << "Nuevo nodo creado: " << nom << endl;
}


int ABB::comparaAlfabeto(string str1, string str2){
    for(int i = 0; i < str1.length() && i < str2.length(); i++){
        if(str1[i] == str2[i]) {
            i++;
        }
        else if(str1[i] > str2[i]){
            return 1;
        }
        else{
            return 2;
        }
    }
    return 0;
}

void ABB::mostrarNodo(NodoABB* nodo) {

    cout << "Pais: " << nodo->lista.peak().frente().pais << endl;
    nodo->lista.mostrarLista();
}

void ABB::mayorPais2(NodoABB* arb) {
    NodoABB* nodoMayor = arb;
    NodoABB* nodoMenor = arb;
    if (arb != nullptr) {
        verInOrden2(arb->hi);
        mostrarNodo(arb);
        verInOrden2(arb->hd);
    }
}

void ABB::mayorPais() {
    mayorPais2(raiz);
}
