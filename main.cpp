#include <iostream>
#include "Pila.h"


using namespace std;


int main() {
   bool start = false;
   Pila p;
   int opcion =9;
   while (!start) {
       switch (opcion) {
           case 1:
               cout << "1. Añadir un pasajero" << endl ;
               cin >> opcion;
               break ;
           case 2:
               cin >> opcion;
               cout << "2. Mostrar la pila de pasajeros" << endl ;
               if (!p.esVacia()) {
                   cout << p.mostrar() << endl ;
               }
               else {
                   cout <<"La pila esta vacia" << endl ;
               }
               opcion = 9;
               break ;
           case 3:
               cout << "3. Borrar la pila de pasajeros" << endl ;
               while (!p.esVacia()) {
                   p.desapilar();
               }
           cout << "La pila de pasajeros ha sido borrada" << endl ;
               opcion = 9;
               break ;
           case 4:
               cout << "4. Mostrar la cola de espera de pasajeros" << endl ;
               break ;
           case 5:
                cout << "5. Mostrar los datos de los pasajeros en los boxes" << endl ;
                break ;
           case 6:
               cout << "6. Simular N minutos " << endl ;
               break ;
           case 7:
               cout << "7. Simular todo el funcionamiento" << endl ;
               break ;
           case 8:
               cout << "8. No deseo realizar mas acciones" << endl ;
               start = true ;
               break ;
           case 9:
               cout << "Introduce un numero dependiendo de la acción que quieras realizar" << endl ;
           cout << "1. Añadir un pasajero" << endl ;
           cout << "2. Mostrar la pila de pasajeros" << endl ;
           cout << "3. Borrar la pila de pasajeros" << endl ;
           cout << "4. Mostrar la cola de espera de pasajeros" << endl ;
           cout << "5. Mostrar los datos de los pasajeros en los boxes" << endl ;
           cout << "6. Simular N minutos " << endl ;
           cout << "7. Simular todo el funcionamiento" << endl ;
           cout << "8. No deseo realizar mas acciones" << endl ;
           cout << "9. Quiero repetir las opciones" << endl ;
           cin >> opcion;
           break ;








       }






















   }


   cout << "Creamos la pila vacia" << endl;
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

