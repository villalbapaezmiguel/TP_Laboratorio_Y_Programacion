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

	int estadoCalcularAerolineas = -1;
	int estadoCalcularLatam = -1;
	float auxTarjetaDebito_Aerolineas ;
	float auxTarjetaCredito_Aerolineas;
	float auxBtc_cantidadPesos_Aerolineas;
	float auxTarjetaDebito_Latam ;
	float auxTarjetaCredito_Latam;
	float auxBtc_cantidadPesos_Latam;
	int banderaPreciosVuelos = -1;
	int banderaAerolineas = -1;
	int banderaLatam = -1;
	int banderaCalculado= -1;
	do {
		printf("\n1) Ingresar Kilometros:");
		printf("\n2) Ingresar Precio de Vuelos:");
		printf("\n3) Calcular todos los costos: ");
		printf("\n4) Informar Resultados ");
		printf("\n5) Carga forzada");
		printf("\n6) Salir");
		printf("\nIngrese opcion :");
		scanf("%d",&opcion);
	//me genera un loop si en opciones ponemos una letra
		switch(opcion)
		{
			case 1://ingresa los kilometros
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
			case 2://2) Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
				/*2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
					- Precio vuelo Aerolíneas:
					- Precio vuelo Latam:*/
				printf("\n2) Ingresar Precio de Vuelos");
				do{
					printf("\nPrecio de Vuelos");
					printf("\nAerolíneas = %.2f\nLatam = %.2f  ", precioVueloAerolineas ,precioVueloLatam );
					printf("\n2) Ingresar opcion (Aerolíneas=y ||  Latam=z || Salir= 's'): ");
					__fpurge(stdin);
					scanf("%c",&caracterOpcionPrecioVuelo);

					while(caracterOpcionPrecioVuelo != 'y' && caracterOpcionPrecioVuelo != 'z' && caracterOpcionPrecioVuelo != 's')
					{
						printf("\nERROR");
						printf("\n2) Ingresar Precio de Vuelos (Aerolíneas=y ||  Latam=z || Salir= 's'): ");
						__fpurge(stdin);
						scanf("%c",&caracterOpcionPrecioVuelo);
					}

					switch(caracterOpcionPrecioVuelo )
					{
					case 'y':
						printf("\nIngrese precio vuelo Aereolineas : ");
						scanf("%f", &precioVueloAerolineas);
						while(precioVueloAerolineas <= 0)
						{
							printf("\n el precio tiene que ser mayor a cero ");
							printf("\nIngrese precio vuelo Aereolineas : ");
							scanf("%f", &precioVueloAerolineas);
						}
						banderaAerolineas = 1;
						printf("\n----------Listo ya se integraron los precios Aerolíneas-----------\n");

						break;
					case 'z':
						printf("\nIngrese precio vuelo Latam : ");
						scanf("%f", &precioVueloLatam);
						while(precioVueloLatam <= 0)
						{
							printf("\n el precio tiene que ser mayor a cero ");
							printf("\nIngrese precio vuelo Latam : ");
							scanf("%f", &precioVueloLatam);
						}
						banderaLatam = 1;
							printf("\n----------Listo ya se integraron los precios Latam-----------\n");
						break;
					case 's':
						banderaPreciosVuelos = 1;
						break;
					}
					//informa si se ingresaron los precios de (Aerolíneas y Latam)
				}while(banderaPreciosVuelos != 1);
				if(banderaAerolineas == 1 && banderaLatam == 1)
				{
					printf("\n----------Listo ya se integraron los precios (Aerolíneas y Latam)-----------\n");
				}else if(banderaAerolineas == 1 && banderaLatam != 1){
					printf("\n---------Solo se ingreso Aerolíneas--------------\n");
				}else if(banderaLatam == 1 && banderaAerolineas != 1){
					printf("\n---------Solo se ingreso Latam--------------\n");
				}
				break ;
			case 3://3) Calcular todos los costos
				/*3. Calcular todos los costos:*/
				printf("\n3) Calcular todos los costos: ");

				estadoCalcularAerolineas = calcular(precioVueloAerolineas, kilometrosIngresados, &auxTarjetaDebito_Aerolineas, &auxTarjetaCredito_Aerolineas, &auxBtc_cantidadPesos_Aerolineas);
				estadoCalcularLatam = calcular(precioVueloLatam, kilometrosIngresados, &auxTarjetaDebito_Latam, &auxTarjetaCredito_Latam, &auxBtc_cantidadPesos_Latam);

				//tiene un error, entra igual aunque uno de los dos este en estado -1
				if((estadoCalcularAerolineas == 1) && (estadoCalcularLatam == 1))
				{
					banderaCalculado = 1;
					printf("\n--------------Ya se calculo---------");
				}else if(estadoCalcularAerolineas == 1 && estadoCalcularLatam != 1){
					printf("\nSolo se pudo calcular Aerolineas");
				}else if(estadoCalcularLatam == 1 && estadoCalcularAerolineas != 1)
				{
					printf("\nSolo se pudo calcular Latam");
				}else{
					printf("\n--------------------No se pudo calcular--------------------");
				}

				break ;
			case 4://4) Informar Resultados
				//si la bandera da 1 significa que fue calculado , de lo contrario le va a tirar un mensaje de
				//debe calcular primero para mostrar
				if(banderaCalculado == 1)
				{
					printf("\n4) Informar Resultados ");
					printf("\nAereolineas :");
					informar(precioVueloAerolineas ,auxTarjetaDebito_Aerolineas, auxTarjetaCredito_Aerolineas, auxBtc_cantidadPesos_Aerolineas);
					printf("\nLatam :");
					informar(precioVueloLatam, auxTarjetaDebito_Latam, auxTarjetaCredito_Latam, auxBtc_cantidadPesos_Latam);
				}else{
					printf("\nNo se puede informar porque todavia no se calculo");
				}
				break ;
			case 5 ://5) Carga forzada de datos
				printf("\n5) carga forzada");
				printf("\nKMs ingresados : %d km\n", 7090);
				cargaForzada(7090, 162965, 159339);
				break;

		}
	} while (opcion != 6);//6) Salir

}
