/*
 * Menu.c
 *
 *  Created on: 13 abr. 2022
 *      Author: miguel
 */

#include "Menu.h"


void menu(void)
{
	setbuf(stdin, NULL);

	int opcion ;
	float kilometrosIngresados ;
	float precioVueloAerolineas ;
	float precioVueloLatam ;
	char caracterOpcionPrecioVuelo ;

	int estadoCalcular = -1;
	float auxTarjetaDebito_Aerolineas ;
	float auxTarjetaCredito_Aerolineas;
	float auxBtc_cantidadPesos_Aerolineas;
	float auxTarjetaDebito_Latam ;
	float auxTarjetaCredito_Latam;
	float auxBtc_cantidadPesos_Latam;

	do {
		printf("\n1) Ingresar Kilometros:");
		printf("\n2) Ingresar Precio de Vuelos:");
		printf("\n3) Calcular todos los costos: ");
		printf("\n4) Informar Resultados ");
		printf("\n5) Salir ");
		printf("\nIngrese opcion :");
		scanf("%d",&opcion);
	//me genera un loop si en opciones ponemos una letra
		switch(opcion)
		{
			case 1:
				printf("\n1) Ingresar Kilómetros: ( km=x) : ");
				scanf("%f", &kilometrosIngresados);
				while(kilometrosIngresados <= 0 )
				{
					printf("\nERROR ");
					printf("\n1) Ingresar Kilómetros : ");
					scanf("%f", &kilometrosIngresados);

				}
				printf("\n------------Kilómetros ingresados---------------- ");
				break ;
			case 2:
				/*2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
					- Precio vuelo Aerolíneas:
					- Precio vuelo Latam:*/
				printf("\n2) Ingresar Precio de Vuelos");
				printf("\n selecciona (Aerolíneas=y, Latam=z) : ");
				__fpurge(stdin);
				scanf("%c", &caracterOpcionPrecioVuelo);

				while(caracterOpcionPrecioVuelo != 'y' && caracterOpcionPrecioVuelo != 'z')
				{
					printf("\nERROR");
					printf("\n2) Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z) ");
					scanf("%c",&caracterOpcionPrecioVuelo);
				}
				if(caracterOpcionPrecioVuelo == 'y')
				{
					printf("\nIngrese precio vuelo Aereolineas : ");
					scanf("%f", &precioVueloAerolineas);
					while(precioVueloAerolineas <= 0)
					{
						printf("\n el precio tiene que ser mayor a cero ");
						printf("\nIngrese precio vuelo Aereolineas : ");
						scanf("%f", &precioVueloAerolineas);
					}
					printf("\n----------Listo ya se integraron los precios Aerolíneas-----------\n");

				}else if(caracterOpcionPrecioVuelo == 'z'){
					printf("\nIngrese precio vuelo Latam : ");
					scanf("%f", &precioVueloLatam);
					while(precioVueloLatam <= 0)
					{
						printf("\n el precio tiene que ser mayor a cero ");
						printf("\nIngrese precio vuelo Latam : ");
						scanf("%f", &precioVueloLatam);
						printf("\n----------Listo ya se integraron los precios Latam-----------\n");

					}
				}
				printf("\n----------Listo ya se integraron los precios (Aerolíneas y Latam)-----------\n");

				break ;
			case 3:
				/*3. Calcular todos los costos:*/
				printf("\n3) Calcular todos los costos: ");

				estadoCalcular = calcular(precioVueloAerolineas, kilometrosIngresados, &auxTarjetaDebito_Aerolineas, &auxTarjetaCredito_Aerolineas, &auxBtc_cantidadPesos_Aerolineas);
				printf("\n tarjeta de debito : %f", auxTarjetaDebito_Aerolineas);
				estadoCalcular = calcular(precioVueloLatam, kilometrosIngresados, &auxTarjetaDebito_Latam, &auxTarjetaCredito_Latam, &auxBtc_cantidadPesos_Latam);

				if(estadoCalcular == 1)
				{
					printf("\n--------------Ya se calculo---------");
				}else{
					printf("\n--------------------No se pudo calcular--------------------");
				}

				break ;
			case 4:
				printf("\n4) Informar Resultados ");
				printf("\nAereolineas :");
				informar(precioVueloAerolineas ,auxTarjetaDebito_Aerolineas, auxTarjetaCredito_Aerolineas, auxBtc_cantidadPesos_Aerolineas);
				printf("\nLatam :");
				informar(precioVueloLatam, auxTarjetaDebito_Latam, auxTarjetaCredito_Latam, auxBtc_cantidadPesos_Latam);
				break ;
			case 5 :
				printf("\n5) carga forzada");
				printf("\nKMs ingresados : %d km\n", 7090);
				cargaForzada(7090, 162965, 159339);
				break;

		}
	} while (opcion != 5);

}
