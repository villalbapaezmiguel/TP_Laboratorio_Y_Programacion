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
	int precioVueloAerolineas ;
	int precioVueloLatam ;
	char caracterOpcionPrecioVuelo ;
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
				scanf("%d", &precioVueloAerolineas);
				printf("\nIngrese precio vuelo Latam : ");
				scanf("%d", &precioVueloLatam);//podemos hacer una funcion para controlar los precio y no pongan numeros negativos

				printf("\n----------Listo ya se integraron los precios (Aerolíneas y Latam)-----------\n");

				break ;
			case 3:
				/*3. Calcular todos los costos:
a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)*/
				printf("\n3) Calcular todos los costos: ");

				int estadoCalcular = -1;
				float auxTarjetaDebito;
				float auxTarjetaCredito;
				float auxBtc_cantidadPesos;

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
				break ;
		}
	} while (opcion != 5);

}
