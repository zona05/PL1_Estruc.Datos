#include <iostream>
#include "Pila.h"
#include "Cola.h"
#include "Simulacion.h"

using namespace std;

int main() {
    bool start = false;
    Pila pila;
    Lista lista;
    Cola colainicio;
    Cola boxocupado;
    Cola boxmenosoc;
    lista.AgregarOrdena(colainicio);
    lista.AgregarOrdena(colainicio);
    Simulacion simulacion(pila, lista);
    pila.apilar(Persona(1, "Indonesia", 6, 0, 20, 0));
    pila.apilar(Persona(2, "Portugal", 1, 0, 15, 0));
    pila.apilar(Persona(3, "Australia", 7, 5, 39, 0));
    pila.apilar(Persona(4, "Sudafrica", 5, 7, 23, 0));
    pila.apilar(Persona(5, "Indonesia", 6, 10, 16, 0));
    pila.apilar(Persona(6, "Noruega", 4, 11, 23, 0));
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
            case 6:
                boxocupado = lista.peak();
                 boxmenosoc = lista.final();
                cout << "Box mas ocupado: "  << endl;
                boxocupado.mostrar();
                cout << "Box menos ocupado: "  << endl;
                boxmenosoc.mostrar();
                opcion = 9;
                break;
            case 5:
                cout << "Datos de  los boxes: " << endl;
                lista.mostrarLista();
                opcion = 9;
                break;
            case 4: {
                int minutos;
                cout << "Introduce el número de minutos a simular: ";
                cin >> minutos;
                simulacion.simularMinutos(minutos);
                opcion = 9;
                break;
            }
            case 8:
                cout << "Simulando todo el funcionamiento hasta que no haya pasajeros." << endl;
                simulacion.simularEntero();
                opcion = 9;
                break;
            case 7:
                cout << "Numero de boxes de atencion operativos: " << lista.longitud() +1 << endl;
                start = true;
                break;
            case 9:
                cout << "Introduce un numero dependiendo de la accion que quieras realizar:" << endl;
                cout << "1. Anadir un pasajero" << endl;
                cout << "2. Mostrar la pila de pasajeros" << endl;
                cout << "3. Borrar la pila de pasajeros" << endl;
                cout << "4. Simular N minutos" << endl;
                cout << "5. Mostrar los datos de los boxes" << endl;
                cout << "6. Consultar que box tiene mas pasajeros y cual tiene menos " << endl;
                cout << "7. Consultar numero de boxes activos" << endl;
                cout << "8. Simular todo el funcionamiento" << endl;
                cout << "9. Quiero repetir las opciones" << endl;
                cout << "10. No deseo realizar más acciones" << endl;
                cin >> opcion;
                break;
            case 10:
                cout << "No deseo realizar más acciones." << endl;
            start = true;
            break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
                opcion = 9;
                break;
        }
    }

}
