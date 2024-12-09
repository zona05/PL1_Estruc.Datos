#include "ABB.h"
#include "SimulacionLista.h"
#include <iostream>

ABB::ABB() : raiz(nullptr) {}


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
void ABB::verPais(string pais) {
    verPais2(raiz,pais);
}

void ABB::verPais2(NodoABB* arb,string pais) {
    NodoABB* actual = arb;
    if (arb != nullptr) {
        if (actual->lista.peak().frente().pais == pais) {
            actual->lista.peak().mostrar();
        }
        verPais2(arb->hi,pais);    // Recorrer subárbol izquierdo
        verPais2(arb-> hd,pais);      // Recorrer subárbol derecho
    }
}
void ABB::verDatos() {
    verPreorden2(raiz);
}

void ABB::verDatos2(NodoABB* arb) {

    if (arb != nullptr) {
        cout <<  arb->lista.peak().frente().pais <<   endl;
        arb->lista.peak().mostrar2();
        verDatos2(arb->hi);    // Recorrer subárbol izquierdo
        verDatos2(arb-> hd);      // Recorrer subárbol derecho
    }
}

void ABB::verPreorden() {
    verPreorden2(raiz);
}

void ABB::verPreorden2(NodoABB* arb) {

    if (arb != nullptr) {
        cout <<  arb->lista.peak().frente().pais <<  endl;
        verPreorden2(arb->hi);    // Recorrer subárbol izquierdo
        verPreorden2(arb-> hd);      // Recorrer subárbol derecho
    }
}
void ABB::vertmpomedio(string pais) {
    vertmpomedio2(raiz,pais);
}


void ABB::vertmpomedio2(NodoABB* arb ,string pais) {
    NodoABB* actual = arb;
    if (actual!= nullptr) {
        if (actual->lista.peak().frente().pais == pais) {
        cout << "La media de tiempo del pais" << pais << "es"<<  actual->lista.peak().tiempomedio() << endl;
        }
        vertmpomedio2(actual->hi, pais);    // Recorrer subárbol izquierdo
        vertmpomedio2(actual-> hd, pais);      // Recorrer subárbol derecho
    }
}
void ABB::vertmpomediotodos() {
    vertmpomediotodos2(raiz);
}


void ABB::vertmpomediotodos2(NodoABB* arb) {
    NodoABB* actual = arb;
    if (actual!= nullptr) {
            cout << "La media de tiempo del pais" << actual->lista.peak().frente().pais << "es"<<  actual->lista.peak().tiempomedio() << endl;
        vertmpomediotodos2(actual->hi);    // Recorrer subárbol izquierdo
        vertmpomediotodos2(actual-> hd);      // Recorrer subárbol derecho
    }
}

/*
void ABB::buscarOInsertar(Lista lista, SimulacionLista simulacion) {
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


}

 */
int ABB::comparaAlfabeto(string str1, string str2){
    for(int i = 0; i < str1.length() && i < str2.length(); i++){
        if(str1[i] == str2[i]) {

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

void ABB::mayorymenor( NodoABB* raiz,NodoABB*& nodo_max, NodoABB*& nodo_min) {
    if (raiz != nullptr) {
        int longitud_actual = raiz->lista.longitud();

        // Actualizar el nodo con la lista más larga
        if (nodo_max == nullptr || longitud_actual > nodo_max->lista.peak().longitudcola()) {
            nodo_max = raiz;
        }

        // Actualizar el nodo con la lista más corta
        if (nodo_max == nullptr || longitud_actual > nodo_min->lista.longitud()) {
            nodo_min = raiz;
        }

        // Recorrer los subárboles izquierdo y derecho
        mayorymenor(raiz->hi, nodo_max, nodo_min);
        mayorymenor(raiz->hd, nodo_max, nodo_min);
    }
}

void ABB::insertarteclado(Persona persona) {
    Cola cola;
    string pais = persona.pais;
    NodoABB* actual = raiz;
    NodoABB* padre = nullptr;

    // Buscar el nodo donde insertar
    while (actual != nullptr) {
        if (!actual->lista.peak().esVacia()) {
            // Si encontramos el nodo con el país, agregamos la persona
            if (actual->lista.peak().frente().pais == pais) {
                actual->lista.peak().encolar(persona);
                cout << "Nodo encontrado: " << actual->nombre << endl;
                return;  // Ya hemos insertado la persona, no hacemos nada más
            }

            // Decidir si ir al subárbol izquierdo o derecho
            padre = actual; // Mantener el rastro del padre
            if (actual->lista.peak().frente().pais > persona.pais) {
                actual = actual->hi;  // Ir al subárbol izquierdo
            } else {
                actual = actual->hd;  // Ir al subárbol derecho
            }
        } else {
            // Si la lista está vacía, salimos del bucle
            break;
        }
    }

    // Crear un nuevo nodo si no se encontró el país
    Lista nuevaLista;
    nuevaLista.AgregarOrdena(cola); // Se asegura de agregar una cola
    nuevaLista.peak().encolar(persona); // Encolar la persona en la lista
    NodoABB* nuevoNodo = new NodoABB();
    nuevoNodo -> nombre = persona.pais;
    nuevoNodo->lista = nuevaLista;
    cout << "Nuevo nodo creado para el país: " << persona.pais << endl;

        // Si el árbol está vacío, asignamos el nuevo nodo como la raíz
        if (raiz == nullptr) {
            raiz = nuevoNodo;
            cout << "Nuevo nodo es la raíz del árbol." << endl;
            return;
        }

        // Ahora inserta el nuevo nodo en el árbol binario
        actual = raiz;
        while (actual != nullptr) {
            padre = actual; // Mantener el rastro del padre
            if (persona.pais < actual->nombre) {
                actual = actual->hi;
            } else {
                actual = actual->hd;
            }
        }

        // Inserta el nuevo nodo en el lugar correcto
        if (persona.pais < padre->nombre) {
            padre->hi = nuevoNodo;
            cout << "Nodo insertado a la izquierda de: " << padre->nombre << endl;
        } else {
            padre->hd = nuevoNodo;
            cout << "Nodo insertado a la derecha de: " << padre->nombre << endl;
        }

}