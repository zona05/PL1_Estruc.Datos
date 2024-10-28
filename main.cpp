#include <iostream>
#include "Pila.h"
#include "Cola.h"
#include "Simulacion.h"

using namespace std;

int main() {
    bool start = false;
    Pila pila;
    Cola cola;
    Simulacion simulacion(pila, cola);
    int opcion = 9;
    int id, prioridad, inicio,horario;
    int tiempo = 0;
    while (!start) {
        switch (opcion) {
            case 1: {

                string pais;

                cout << "Introduce el ID del pasajero: ";
                cin >> id;
                cout << "Introduce el país del pasajero: ";
                cin >> pais;
                cout << "Introduce la prioridad del pasajero: ";
                cin >> prioridad;
                cout << "Introduce el minuto de llegada al aeropuerto: ";
                cin >> inicio;
                cout << "Introduce el tiempo de peaje del pasajero: ";
                cin >> horario;

                pila.apilar(Persona(id, pais, prioridad, inicio,horario, tiempo));
                cout << "Pasajero añadido a la pila." << endl;

                opcion = 9;
                break;
            }
            case 2:
                cout << "Pila de pasajeros:" << endl;
                if (!pila.esVacia()) {
                    pila.mostrar();
                } else {
                    cout << "La pila está vacía." << endl;
                }
                opcion = 9;
                break;
            case 3:
                cout << "Borrando la pila de pasajeros." << endl;
                while (!pila.esVacia()) {
                    pila.desapilar();
                }
                cout << "La pila de pasajeros ha sido borrada." << endl;
                opcion = 9;
                break;
            case 4:
                cout << "Cola de espera de pasajeros:" << endl;
                if (!cola.esVacia()) {
                    cola.mostrar();
                } else {
                    cout << "La cola está vacía." << endl;
                }
                opcion = 9;
                break;
            case 5:
                cout << "Datos de los pasajeros en los boxes:" << endl;
                simulacion.mostrarBoxes();
                opcion = 9;
                break;
            case 6: {
                int minutos;
                cout << "Introduce el número de minutos a simular: ";
                cin >> minutos;

                simulacion.simularMinutos(minutos);
                opcion = 9;
                break;
            }
            case 7:
                cout << "Simulando todo el funcionamiento hasta que no haya pasajeros." << endl;
                simulacion.simularEntero();
                opcion = 9;
                break;
            case 8:
                cout << "No deseo realizar más acciones." << endl;
                start = true;
                break;
            case 9:
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
                opcion = 9;
                break;
        }
    }
    return 0;
}
