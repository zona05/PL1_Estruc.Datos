#include <iostream>
#include "Pila.h"

using namespace std;

int main() {
    cout << "Creamos la pila vacia" << endl;
    Pila p;
    p.mostrar();

    cout << "Apilo pasajero con prioridad 6" << endl;
    p.apilar(6);
    p.mostrar();

    cout << "Apilo pasajero con prioridad 4" << endl;
    p.apilar(4);
    p.mostrar();

    cout << "Apilo pasajero con prioridad 7" << endl;
    p.apilar(7);
    p.mostrar();

    cout << "Apilo pasajero con prioridad 2" << endl;
    p.apilar(2);
    p.mostrar();

    cout << "Apilo pasajero con prioridad 3" << endl;
    p.apilar(3);
    p.mostrar();

    cout << "La pila actual tiene una longitud: " << p.contar() << endl;

    cout << "El fondo de esta pila contiene el valor: " << p.fondo() << endl;

    Pila p_aux;
    p_aux.apilar(2);

    p_aux.apilar(3);

    p_aux.apilar(5);

    Pila resultado;
    resultado.montar(p,p_aux);
    cout << "En esta pila conjunto de p y p2: " << resultado.mostrar() << endl;

    resultado.quitar(3);
    cout << "Le quitamos 3 elementos a la pila, ahora es: " << resultado.mostrar() << endl;

    resultado.apilar(2);
    resultado.apilar(3);
    resultado.apilar(4);

    Pila invertida = resultado.invertir();
    cout << "La pila invertida tiene como cima: " << invertida.mostrar() << endl;

    cout << "El que mayor prioridad tiene en la pila es el: " << p.mayor_pila() << endl;
    return 0;


}