#include <iostream>
#include "Pila.h"
#include "Cola.h"

using namespace std;

int main() {
    bool start = false;
    Pila pila;
    Cola cola;
    int opcion = 9;
    const int MAX_PASAJEROS = 10; // Límite de pasajeros en la pila

    while (!start) {
        switch (opcion) {
            case 1: { // Añadir un pasajero
                int id, prioridad, inicio;
                double tiempo;
                string pais;

                cout << "Introduce el ID del pasajero: ";
                cin >> id;
                cout << "Introduce el país del pasajero: ";
                cin >> pais;
                cout << "Introduce la prioridad del pasajero: ";
                cin >> prioridad;
                cout << "Introduce el inicio del pasajero (1-10): ";
                cin >> inicio;
                cout << "Introduce el tiempo del pasajero: ";
                cin >> tiempo;

                // Crear un objeto Persona y añadirlo a la pila
                pila.apilar(Persona(id, pais, prioridad, inicio, tiempo));
                cout << "Pasajero añadido a la pila." << endl;

                // Si la pila alcanza el máximo, mover pasajeros a la cola
                if (pila.contar() >= MAX_PASAJEROS) {
                    cout << "La pila está llena, comenzando a encolar pasajeros." << endl;
                    while (!pila.esVacia()) {
                        cola.encolar(pila.desapilar()); // Encolar pasajeros desde la pila
                    }
                }
                opcion = 9; // Reiniciar a la opción de menú
                break;
            }
            case 2: // Mostrar la pila de pasajeros
                cout << "Pila de pasajeros:" << endl;
                if (!pila.esVacia()) {
                    pila.mostrar();
                } else {
                    cout << "La pila está vacía." << endl;
                }
                opcion = 9; // Volver al menú
                break;
            case 3: // Borrar la pila de pasajeros
                cout << "Borrando la pila de pasajeros." << endl;
                while (!pila.esVacia()) {
                    pila.desapilar();
                }
                cout << "La pila de pasajeros ha sido borrada." << endl;
                opcion = 9; // Volver al menú
                break;
            case 4: // Mostrar la cola de espera de pasajeros
                cout << "Cola de espera de pasajeros:" << endl;
                if (!cola.esVacia()) {
                    cola.mostrar(); // Implementar mostrar en Cola.h
                } else {
                    cout << "La cola está vacía." << endl;
                }
                opcion = 9; // Volver al menú
                break;
            case 5: // Mostrar los datos de los pasajeros en los boxes
                // Implementar lógica si es necesario
                opcion = 9; // Volver al menú
                break;
            case 6: // Simular N minutos
                cout << "Simulando N minutos." << endl;
                // Implementar lógica si es necesario
                opcion = 9; // Volver al menú
                break;
            case 7: // Simular
                cout << "Simulando todo el funcionamiento." << endl;
                // Implementar lógica si es necesario
                opcion = 9; // Volver al menú
                break;
            case 8: // No deseo realizar más acciones
                cout << "No deseo realizar más acciones." << endl;
                start = true;
                break;
            case 9: // Mostrar opciones
                cout << "Introduce un número dependiendo de la acción que quieras realizar:" << endl;
                cout << "1. Añadir un pasajero" << endl;
                cout << "2. Mostrar la pila de pasajeros" << endl;
                cout << "3. Borrar la pila de pasajeros" << endl;
                cout << "4. Mostrar la cola de espera de pasajeros" << endl;
                cout << "5. Mostrar los datos de los pasajeros en los boxes" << endl;
                cout << "6. Simular N minutos" << endl;
                cout << "7. Simular todo el funcionamiento" << endl;
                cout << "8. No deseo realizar más acciones" << endl;
                cout << "9. Quiero repetir las opciones" << endl;
                cin >> opcion;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
                opcion = 9; // Volver al menú en caso de opción no válida
                break;
        }
    }
    return 0;
}
