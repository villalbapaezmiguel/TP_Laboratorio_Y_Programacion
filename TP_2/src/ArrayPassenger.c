/*
 * ArrayPassenger.c
 *
 *  Created on: 28 abr. 2022
 *      Author: miguel
 */

#include "ArrayPassenger.h"
static int nuevoId(void);
/*
 * int initPassengers(Passenger* list, int len)
 *parametros Passenger* list = es la estructa
 *parametros int len  =  longitud del tamnio de la estructura
 *return =  retorna 1 si todo salio bien , de lo contraio -1
 *se encanga de inicializar el en los campos isEmpty de la estructura Passenger en VACIO
*/
int initPassengers(Passenger* list, int len)
{
	int estado = -1;
	int i ;

	if(list != NULL && len > 0)
	{
		estado = 1;
		for (i = 0; i < len; ++i) {

			list[i].isEmpty = VACIO;
		}
	}

	return estado;
}

/*Agrega en un array de pasajeros existente los valores recibidos como parámetro en la primer
posición libre.*/
int addPassenger(Passenger* list, int len, int id)
{
	int estado = -1;
	int auxEstado ;
	Passenger auxPassanger ;

	if(list != NULL && len > 0)
	{
		if(list[id].isEmpty == VACIO)
		{

			auxEstado = utn_getNombre(auxPassanger.name, NAME_LASTNAME, "\nIngrese su nombre : ", "\nERROR ", 2);
			while(auxEstado != 0)
			{
				auxEstado = utn_getNombre(auxPassanger.name, NAME_LASTNAME, "\nERROR Ingrese su nombre : ", "\nERROR ", 2);
			}

			auxEstado = utn_getNombre(auxPassanger.lastName, NAME_LASTNAME, "\nIngrese su apellido : ", "\nERROR ", 2);
			while(auxEstado != 0)
			{
				auxEstado = utn_getNombre(auxPassanger.lastName, NAME_LASTNAME, "\nERROR Ingrese su apellido : ", "\nERROR ", 2);
			}


			auxEstado = utn_pedirFloat(&auxPassanger.price, "\nIngrese el precio : ", "\nERROR ", 1, 18000, 2);
			while(auxEstado != 0)
			{
				auxEstado = utn_pedirFloat(&auxPassanger.price, "\nERROR Ingrese el precio : ", "\nERROR ", 1, 18000, 2);
			}

			auxEstado = utn_getNumero(&auxPassanger.typePassenger,"\n1)TURISTA \n2)EJECUTIVO \nIngrese tipo de pasajero :", "\nERROR ", 1, 2, 2);
			while(auxEstado != 0)
			{
				auxEstado = utn_getNumero(&auxPassanger.typePassenger,"\nERROR \n1)TURISTA \n2)EJECUTIVO \nIngrese tipo de pasajero :", "\nERROR ", 1, 2, 2);
			}

			auxEstado = utn_pedirChar(auxPassanger.flycode, "\nIngrese codigo de vuelo : ", "\nERROR", 500, 2);
			while(auxEstado != 0)
			{
				auxEstado = utn_pedirChar(auxPassanger.flycode, "\nnERROR Ingrese codigo de vuelo : ", "\nERROR", 500, 2);
			}

			auxPassanger.id = nuevoId();
			list[id] = auxPassanger;
			list[id].isEmpty = OCUPADO;
			estado = 1;
		}
	}

	return estado;
}

/*int buscarPrimeraPosicionLibre(Passenger* list , int len, int* lugarLibre)
 *parametro  Passenger* list = es la estructa
 *parametro  int len = longitud del tamnio de la estructura
 *parametro  int* lugarLibre = es el lugar libre que se encontro
 *return = retorna 1 si salio todo bien , de lo contrario -1
 *se encanga de recorrer la estructura y buscar un lugar vacio ,osea con el isEmpty VACIO
 * */
int buscarPrimeraPosicionLibre(Passenger* list , int len, int* lugarLibre)
{
	int retorno = -1;
	int i ;

	if(list != NULL && len > 0)
	{
		for (i = 0; i < len; ++i) {

			if(list[i].isEmpty == VACIO)
			{
				*lugarLibre = i ;
				retorno = 1;
				break;
			}

		}
	}

	return retorno;
}

/*static int nuevoId()
 *int contador = es el contador y va agregando +1  cada vez que se lo llame
 *se encangar de generar un nuevo id*/
static int nuevoId()
{
	static int contador =0;

	return (contador++);
}

/*int removePassenger(Passenger* list, int len, int id)
 *parametro  Passenger* list = es la estructa
 *parametro  int len = longitud del tamnio de la estructura
 *parametro  int id = el indice o la posicion
 *return = retorna 1 si salio todo bien , de lo contrario -1
 *se encanga de dar una baja logica , osea pone el isEmpty en VACIO
 * */
int removePassenger(Passenger* list, int len, int id)
{
	int retorno = -1;
	int i ;
	if((list != NULL && len > 0) && id != -1 )
	{
		for (i = 0; i < len; ++i) {

			if(list[i].isEmpty == id)
			{
				retorno = 1;
				list[i].isEmpty = VACIO;
				break;

			}
		}

	}

	return retorno;
}


int ordenarPorApellido(Passenger* list , int len)
{
	int retorno = -1;
	int flagSwap;
	Passenger buffer ;

	if(list != NULL && len > 0)
	{
		retorno= 1;
		do
		{
			flagSwap = 0;
			for (int i = 0; i < len; ++i) {

				if(list[i].isEmpty || list[i+1].isEmpty)
				{
					continue ;
				}
				if(strncmp(list[i].lastName ,list[i+1].lastName , NAME_LASTNAME) > 0)
				{
					flagSwap = 1;
					buffer = list[i];
					list[i] = list[i+1];
					list[i+1] = buffer ;
				}
			}
			len--;
		}while(flagSwap);
	}

	return retorno;
}

int printPassenger(Passenger* list, int length)
{
	int estado = -1;
	int i ;

	for (i = 0; i < length; ++i) {

		if(list[i].isEmpty == OCUPADO)
		{
			if(list[i].typePassenger == 1)
			{
				printf("\nId : %d || Name : %s|| LasName : %s ||  Price : %2f || Flycode : %s || Type Passanger : TURISTA ",
						list[i].id , list[i].name , list[i].lastName , list[i].price , list[i].flycode );

			}else if(list[i].typePassenger == 2){

				printf("\nId : %d || Name : %s|| LasName : %s ||  Price : %2f || Flycode : %s || Type Passanger : EJECUTIVO ",
				list[i].id , list[i].name , list[i].lastName , list[i].price , list[i].flycode );

			}else{
				printf("\nERROR");
				printf("\nId : %d || Name : %s|| LasName : %s ||  Price : %2f || Flycode : %s || Type Passanger : %d ",
				list[i].id , list[i].name , list[i].lastName , list[i].price , list[i].flycode , list[i].typePassenger);

			}
		}
	}

	return estado;
}


void menu (Passenger* list , int len )
{
	int opcion ;
	int auxLugarLibre ;
	int auxLugarLibreModificar ;
	int auxIdBaja ;

	if(initPassengers(list, PASSANGER_LEN) == 1)
	{
		printf("\nya se inicializaron correctamente");
	}

	altaForzada(list, len, 0, "Miguel", "Villalba", 2000, 1, "buenass");
	altaForzada(list, len, 1, "Pepe", "Argento", 350, 2, "boludoooo");
	altaForzada(list, len, 2, "Alex", "El leon", 1200, 1, "GUAUUUU");
	altaForzada(list, len, 3, "Thor", "Pe", 100, 2, "rayo");

	do {
		printf("\n1) ALTA \n2)MODIFICACION \n3)BAJA \n4)INFORMAR \nSALIR ");
		utn_pedirInt(&opcion, "\nIngrese una opcion : ","\nERROR",1, 5, 2);
		switch(opcion)
		{
		case 1:
			printf("\nALTA");
				if(buscarPrimeraPosicionLibre(list, len, &auxLugarLibre) == 1)
				{
					printf("\nLugar libre encontrado : %d", auxLugarLibre);
					if(addPassenger(list, len, *&auxLugarLibre) == 1)
					{
						printf("\nAlta finalizada ");
					}
				}
			break ;
		case 2:
			printf("\nMODIFICACION");
				utn_pedirInt(&auxLugarLibreModificar, "\nIngrese el Id al modificar :", "\nERROR ", 0, len, 2);

				if(buscarPorId(list, len, &auxLugarLibreModificar) == 1)
				{
					if(modificacion(list, len, auxLugarLibreModificar) == 1)
					{
						printf("\nFin de la modificacion");
					}
				}
			break ;
		case 3:
			printf("\nBAJA");
			utn_pedirInt(&auxIdBaja, "\nIngrese el Id para dar de baja :", "\nERROR ", 0, len, 2);
			if(buscarPorId(list, len, &auxIdBaja) == 1)
			{
				if(baja(list, len, auxIdBaja) == 1)
				{
					printf("\nFin de la Baja");
				}
			}


			break ;
		case 4:
			printf("\nINFORMAR");
			printPassenger(list, len);
			break ;
		case 5:
			printf("\nSaliste del programa ");
			break ;
		default : printf("\nERROR opcion invalida ");

		}


	} while (opcion != 5);


}

int modificacion (Passenger* list , int len , int idModificar)
{
	int retorno = -1;
	Passenger auxPassenger ;
	int opcion ;

	int auxEstado = -1;
	auxPassenger = list[idModificar];

	if(list != NULL && len > 0)
	{
		if(list[idModificar].isEmpty == OCUPADO)
		{
			do {
				printf("\nPuede modificar :");
				printf("\n1)Nombre  \n2)Apellidoo \n3)Precio  \n4)Tipo de pasajero  \n5)Código de vuelo \n6)Salir de la modificacion ");

				utn_pedirInt(&opcion, "\nIngrese una opcion : ", "\nERROR ", 1, 6, 2);

				switch(opcion)
				{
				case 1:
					printf("\nModificar nombre ");
					auxEstado = utn_getNombre(auxPassenger.name, NAME_LASTNAME, "\nIngrese su nombre : ", "\nERROR ", 2);
					while(auxEstado != 0)
					{
						auxEstado = utn_getNombre(auxPassenger.name, NAME_LASTNAME, "\nERROR Ingrese su nombre : ", "\nERROR ", 2);
					}

					break;
				case 2:
					printf("\nModificar apellido ");
					auxEstado = utn_getNombre(auxPassenger.lastName, NAME_LASTNAME, "\nIngrese su apellido : ", "\nERROR ", 2);
					while(auxEstado != 0)
					{
						auxEstado = utn_getNombre(auxPassenger.lastName, NAME_LASTNAME, "\nERROR Ingrese su apellido : ", "\nERROR ", 2);
					}
					break;
				case 3:
					printf("\nModificar precio ");
					auxEstado = utn_pedirFloat(&auxPassenger.price, "\nIngrese el precio : ", "\nERROR ", 1, 18000, 2);
					while(auxEstado != 0)
					{
						auxEstado = utn_pedirFloat(&auxPassenger.price, "\nERROR Ingrese el precio : ", "\nERROR ", 1, 18000, 2);
					}
					break;
				case 4:
					printf("\nModificar tipoPasajero ");
					auxEstado = utn_getNumero(&auxPassenger.typePassenger,"\n1)TURISTA \n2)EJECUTIVO \nIngrese tipo de pasajero :", "\nERROR ", 1, 2, 2);
					while(auxEstado != 0)
					{
						auxEstado = utn_getNumero(&auxPassenger.typePassenger,"\nERROR \n1)TURISTA \n2)EJECUTIVO \nIngrese tipo de pasajero :", "\nERROR ", 1, 2, 2);
					}
					break;
				case 5:
					printf("\nModificar Codigo de vuelo ");
					auxEstado = utn_pedirChar(auxPassenger.flycode, "\nIngrese codigo de vuelo : ", "\nERROR", 500, 2);
					while(auxEstado != 0)
					{
						auxEstado = utn_pedirChar(auxPassenger.flycode, "\nnERROR Ingrese codigo de vuelo : ", "\nERROR", 500, 2);
					}
					break;
				case 6:
					printf("\nSalio de la modificacion");
					break;
				default : printf("\nERROR opcion invalida ");
				}

			} while (opcion != 6);
			auxPassenger.id = list[idModificar].id;
			auxPassenger.isEmpty = OCUPADO;
			list[idModificar] = auxPassenger;
			retorno = 1;
		}


	}

	return retorno;
}

int buscarPorId(Passenger* list , int len , int* id)
{
	int retorno = -1;
	int i ;

	if((list != NULL && len > 0) && *id > -1)
	{
		for (i = 0; i < len; ++i) {

			if(list[i].isEmpty == OCUPADO)
			{
				*id = i;
				retorno = 1;
				break;
			}
		}
	}


	return retorno;
}


int baja (Passenger* list , int len , int idBaja )
{
	int retorno = -1;

	if(list != NULL && len > 0)
	{

		list[idBaja].isEmpty = VACIO;
		retorno = 1;
	}

	return retorno;
}

void altaForzada(Passenger* list , int len ,int id, char* name , char* lastName , float price , int typePasssenger , char* codigoVuelo)
{
	Passenger auxPassenger ;
	auxPassenger = list[id];
	nuevoId();
	strncpy(auxPassenger.name , name , sizeof(auxPassenger.name));
	strncpy(auxPassenger.lastName ,lastName , sizeof(auxPassenger.lastName));
	auxPassenger.id = id ;
	auxPassenger.price = price;
	auxPassenger.typePassenger = typePasssenger;
	strncpy(auxPassenger.flycode ,codigoVuelo , sizeof(auxPassenger.flycode));
	auxPassenger.isEmpty = OCUPADO;

	list[id] = auxPassenger;

}





