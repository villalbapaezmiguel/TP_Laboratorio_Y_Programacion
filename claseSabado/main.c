#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "UTN.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout, NULL);

    int option = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	printf("\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)"
    			"\n2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)."
    			"\n3. Alta de pasajero"
    			"\n4. Modificar datos de pasajero"
    			"\n5. Baja de pasajero"
    			"\n6. Listar pasajeros"
    			"\n7. Ordenar pasajeros"
    			"\n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)."
    			"\n9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)."
    			"\n10. Salir");
    	utn_getNumero(&option, "\nIngrese opcion : ", "\nERROR", 1, 10, 2);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaPasajeros);
                break;
            case 2:
            	break;
            case 3:
            	break;
            case 4:
            	break;
            case 5:
            	break;
            case 6:
            	break;
            case 7:
            	break;
            case 8:
            	break;
            case 9:
            	break;
            case 10:
            	break;

        }
    }while(option != 10);
    return 0;
}

