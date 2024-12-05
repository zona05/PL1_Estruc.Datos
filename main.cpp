#include <iostream>
#include "Pila.h"
#include "Cola.h"
#include "Simulacion.h"
#include "SimulacionLista.h"
#include "Lista.h"

using namespace std;

int main() {
    int opcionMenu;
    bool start = false;

    cout << "Seleccione la parte que desea ejecutar:" << endl;
    cout << "1. Parte 1" << endl;
    cout << "2. Parte 2" << endl;
    cout << "Ingrese su opcion: ";
    cin >> opcionMenu;

    if (opcionMenu == 1) {

        Pila pila;
        Cola cola;
        Simulacion simulacion(pila, cola);
        pila.apilar(Persona(1, "Indonesia", 6, 0, 10, 0));
        pila.apilar(Persona(2, "Portugal", 1, 0, 15, 0));
        pila.apilar(Persona(3, "Australia", 7, 5, 29, 0));
        pila.apilar(Persona(4, "Sudafrica", 5, 7, 8, 0));
        pila.apilar(Persona(5, "Australia", 7, 9, 16, 0));
        pila.apilar(Persona(6, "Indonesia", 6, 9, 13, 0));
        pila.apilar(Persona(7, "Indonesia",6,10,10,0));
        pila.apilar(Persona(8, "Portugal",1,10,15,0));
        pila.apilar(Persona(9, "Australia",7,15,29,0));
        pila.apilar(Persona(10, "Sudafrica",5,17,8,0));
        pila.apilar(Persona(11, "Australia",7,19,16,0));
        pila.apilar(Persona(12, "Indonesia",6,19,13,0));
        int opcion = 9;
        int id, prioridad, inicio, horario;
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

                    pila.apilar(Persona(id, pais, prioridad, inicio, horario, tiempo));
                    cout << "Pasajero anadido a la pila." << endl;

                    opcion = 9;
                    break;
                }
                case 2:
                    cout << "Pila de pasajeros:" << endl;
                    if (!pila.esVacia()) {
                        pila.mostrar();
                    } else {
                        cout << "La pila esta vacia." << endl;
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
                        cout << "La cola esta vacia." << endl;
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
                    cout << "Introduce el numero de minutos a simular: ";
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
                    cout << "No deseo realizar mas acciones." << endl;
                    start = true;
                    break;
                case 9:
                    cout << "Introduce un numero dependiendo de la accion que quieras realizar:" << endl;
                    cout << "1. Anadir un pasajero" << endl;
                    cout << "2. Mostrar la pila de pasajeros" << endl;
                    cout << "3. Borrar la pila de pasajeros" << endl;
                    cout << "4. Mostrar la cola de espera de pasajeros" << endl;
                    cout << "5. Mostrar los datos de los boxes" << endl;
                    cout << "6. Simular N minutos" << endl;
                    cout << "7. Simular todo el funcionamiento" << endl;
                    cout << "8. No deseo realizar más acciones" << endl;
                    cout << "9. Quiero repetir las opciones" << endl;
                    cin >> opcion;
                    break;
                default:
                    cout << "Opcion no válida. Intente nuevamente." << endl;
                    opcion = 9;
                    break;
            }
        }
    }
    else if (opcionMenu == 2) {

        Pila pila;
        Lista lista;
        Cola colainicio;
        lista.AgregarOrdena(colainicio);
        lista.AgregarOrdena(colainicio);
        lista.AgregarOrdena(colainicio);
        SimulacionLista simulacionlista(pila, lista);
        pila.apilar(Persona(1, "Indonesia", 6, 0, 10, 0));
        pila.apilar(Persona(2, "Portugal", 1, 0, 15, 0));
        pila.apilar(Persona(3, "Australia", 7, 5, 29, 0));
        pila.apilar(Persona(4, "Sudafrica", 5, 7, 8, 0));
        pila.apilar(Persona(5, "Australia", 7, 9, 16, 0));
        pila.apilar(Persona(6, "Indonesia", 6, 9, 13, 0));
        pila.apilar(Persona(7, "Indonesia",6,10,10,0));
        pila.apilar(Persona(8, "Portugal",1,10,15,0));
        pila.apilar(Persona(9, "Australia",7,15,29,0));
        pila.apilar(Persona(10, "Sudafrica",5,17,8,0));
        pila.apilar(Persona(11, "Australia",7,19,16,0));
        pila.apilar(Persona(12, "Indonesia",6,19,13,0));

        int opcion = 9;
        int id, prioridad, inicio, horario;
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

                    pila.apilar(Persona(id, pais, prioridad, inicio, horario, tiempo));
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
                    cout << "Box más ocupado: " << endl;
                    int mayor;
                    mayor = lista.encontrarMayor(&lista);
                    lista.obtener(mayor).mostrar();
                    cout << "Box menos ocupado: " << endl;
                    int menor;
                    menor = lista.encontrarMayor(&lista);
                    lista.obtener(menor).mostrar();
                    opcion = 9;
                    break;
                case 5:
                    cout << "Datos de los boxes: " << endl;
                    lista.mostrarLista();
                    opcion = 9;
                    break;
                case 4: {
                    int minutos;
                    cout << "Introduce el número de minutos a simular: ";
                    cin >> minutos;
                    simulacionlista.simularMinutosLista(minutos);
                    opcion = 9;
                    break;
                }
                case 8:
                    cout << "Simulando todo el funcionamiento hasta que no haya pasajeros." << endl;
                    simulacionlista.simularEnteroLista();
                    opcion = 9;
                    break;
                case 7:
                    cout << "Número de boxes de atención operativos: " << lista.longitud() + 1 << endl;
                    start = true;
                    opcion = 9;
                    break;
                case 9:
                    cout << "Introduce un número dependiendo de la acción que quieras realizar:" << endl;
                    cout << "1. Añadir un pasajero" << endl;
                    cout << "2. Mostrar la pila de pasajeros" << endl;
                    cout << "3. Borrar la pila de pasajeros" << endl;
                    cout << "4. Simular N minutos" << endl;
                    cout << "5. Mostrar los datos de los boxes" << endl;
                    cout << "6. Consultar qué box tiene más pasajeros y cuál tiene menos" << endl;
                    cout << "7. Consultar número de boxes activos" << endl;
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
    else {
        cout << "Opción no válida, el programa terminará." << endl;
    }

    return 0;
}