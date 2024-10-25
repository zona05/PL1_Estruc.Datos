#include <iostream>
#include "Pila.h"

using namespace std;

int main() {
    bool start = false;
    Pila p;
    int opcion = 9;

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
                p.apilar(Persona(id, pais, prioridad, inicio, tiempo));
                cout << "Pasajero añadido." << endl;
                opcion = 9; // Reiniciar a la opción de menú
                break;
            }
            case 2: // Mostrar la pila de pasajeros
                cout << "2. Mostrar la pila de pasajeros" << endl;
                if (!p.esVacia()) {
                    p.mostrar();
                } else {
                    cout << "La pila está vacía." << endl;
                }
                opcion = 9; // Volver al menú
                break;
            case 3: // Borrar la pila de pasajeros
                cout << "3. Borrar la pila de pasajeros" << endl;
                while (!p.esVacia()) {
                    p.desapilar();
                }
                cout << "La pila de pasajeros ha sido borrada." << endl;
                opcion = 9; // Volver al menú
                break;
            case 4: // Mostrar la cola de espera de pasajeros
                cout << "4. Mostrar la cola de espera de pasajeros" << endl;
                // Implementar lógica para mostrar cola de espera si es necesario
                opcion = 9; // Volver al menú
                break;
            case 5: // Mostrar los datos de los pasajeros en los boxes
                cout << "5. Mostrar los datos de los pasajeros en los boxes" << endl;
                // Implementar lógica si es necesario
                opcion = 9; // Volver al menú
                break;
            case 6: // Simular N minutos
                cout << "6. Simular N minutos" << endl;
                // Implementar lógica si es necesario
                opcion = 9; // Volver al menú
                break;
            case 7: // Simular
                cout << "7. Simular todo el funcionamiento" << endl;
                // Implementar lógica si es necesario
                opcion = 9; // Volver al menú
                break;
            case 8: // No deseo realizar más acciones
                cout << "8. No deseo realizar más acciones." << endl;
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
