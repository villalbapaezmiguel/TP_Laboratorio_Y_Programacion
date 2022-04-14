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
	float auxTarjetaDebito = 0;
	float auxTarjetaCredito= 0;
	float auxBtc_cantidadPesos= 0;

	do {
		printf("\n1) Ingresar Kilometros: ( km=x) ");
		printf("\n2) Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z) ");
		printf("\n3) Calcular todos los costos: ");
		printf("\n4) Informar Resultados ");
		printf("\n5) Salir ");
		printf("\nIngrese opcion :");
		scanf("%d",&opcion);
		switch(opcion)
		{
			case 1:
				printf("\n1) Ingresar Kilómetros: ( km=x) : ");
				scanf("%f", &kilometrosIngresados);
				printf("\n------------Kilómetros ingresados---------------- ");
				break ;
			case 2:
				printf("\n2) Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z) ");
				__fpurge(stdin);
				scanf("%c", &caracterOpcionPrecioVuelo);
				/*2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
					- Precio vuelo Aerolíneas:
					- Precio vuelo Latam:*/
				while(caracterOpcionPrecioVuelo != 'y' && caracterOpcionPrecioVuelo != 'z')
				{
					printf("\nERROR");
					printf("\n2) Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z) ");
					scanf("%c",&caracterOpcionPrecioVuelo);
				}

				printf("\nIngrese precio vuelo Aereolineas : ");
				scanf("%f", &precioVueloAerolineas);
				printf("\nIngrese precio vuelo Latam : ");
				scanf("%f", &precioVueloLatam);//podemos hacer una funcion para controlar los precio y no pongan numeros negativos

				printf("\n----------Listo ya se integraron los precios (Aerolíneas y Latam)-----------\n");

				break ;
			case 3:
				/*3. Calcular todos los costos:*/
				printf("\n3) Calcular todos los costos: ");

				estadoCalcular = calcular(precioVueloAerolineas, kilometrosIngresados, auxTarjetaDebito, auxTarjetaCredito, auxBtc_cantidadPesos);
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
				informar(auxTarjetaDebito, auxTarjetaCredito, auxBtc_cantidadPesos);
				printf("\nLatam :");
				informar(auxTarjetaDebito, auxTarjetaCredito, auxBtc_cantidadPesos);
				break ;
		}
	} while (opcion != 5);

}
