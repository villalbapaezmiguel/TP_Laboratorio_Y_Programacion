/*
 * funciones.c
 *
 *  Created on: 13 abr. 2022
 *      Author: miguel
 */

#include "funciones.h"
/*int calcular(float precio , float kilometros)
 * esta funcion calcula los precios de :
 * float precio , float kilometros , float tarjetaDebito , float tarjetaCredito , float btc_cantidadPesos ;
 * retorna 1 si pudo calcular de lo contrario -1
 *   */
int calcular(float auxPrecio , float auxKilometros , float *auxTarjetaDebito , float *auxTarjetaCredito , float *auxBtc_cantidadPesos )
{
	int estado =-1;
	double btc = 4606954.55;
	float tarjetaDebito ;
	float tarjetacredito ;
	float Btc_cantidadPesos ;

	if((auxPrecio > 0 && auxPrecio != 0) && (auxKilometros > 0 && auxKilometros != 0))
	{
		estado = 1;
				//Aerolíneas:
		//a) Tarjeta de débito (descuento 10%)
		tarjetaDebito = auxPrecio*10/100 ;
		tarjetaDebito = auxPrecio - tarjetaDebito;
		//printf("\n auxTarjetaDebito : %.2f", tarjetaDebito);
		*auxTarjetaDebito = tarjetaDebito;
		//b) Tarjeta de crédito (interés 25%)
				tarjetacredito = auxPrecio*25/100;
				tarjetacredito = tarjetacredito + auxPrecio;
				*auxTarjetaCredito = tarjetacredito;
		//c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
				Btc_cantidadPesos = auxPrecio/ btc;
				*auxBtc_cantidadPesos = Btc_cantidadPesos;
			//	printf("\n Btc_cantidadPesos : %f", Btc_cantidadPesos);
				//d) Mostrar precio por km (precio unitario)
	}else{
		printf("\ntiene que ingresar el precio y el kilometro para poder hacer los calculos\n");
	}

//hacer la carga forzada con punteros , y mejorar las funciones y los case
	return estado ;
}

/*esta funcion void informar:
 *informa todos los resultados de :
 *a) Precio con tarjeta de débito: r
 *b) Precio con tarjeta de crédito: r
 *c) Precio pagando con bitcoin : r
 *d) Precio unitario: r */
void informar(float auxPrecio, float auxTarjetaDebito , float auxTarjetaCredito , float auxBtc_cantidadPesos )
{
	/*“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “*/
	printf("\nPrecio de Vuelo : %f ", auxPrecio);
	printf("\nA) Precio con tarjeta de débito : $ %.2f", auxTarjetaDebito);
	printf("\nB) Precio con tarjeta de crédito : $ %.2f", auxTarjetaCredito);
	printf("\nc) Precio pagando con bitcoin : $ %.2f \n", auxBtc_cantidadPesos);

}

/*Tiene que calcular todo al momento de apretar el botón con los
siguientes datos:
Km: 7090
Aerolineas Argentinas: $162965
Latam: $ 159339
(solo mostrar los resultados ya calculados)*/
void cargaForzada (float auxKilometros , float precioAerolineas , float PrecioLatam)
{
	//Aerolineas
	float auxTarjetaDebito_Aerolineas ;
	float auxTarjetaCredito_Aerolineas ;
	float auxBtc_cantidadPesos_Aerolineas;
	//Latam
	float auxTarjetaDebito_Latam ;
	float auxTarjetaCredito_Latam ;
	float auxBtc_cantidadPesos_Latam;
	calcular(precioAerolineas, auxKilometros, &auxTarjetaDebito_Aerolineas, &auxTarjetaCredito_Aerolineas, &auxBtc_cantidadPesos_Aerolineas);
	printf("\nAerolineas : ");
	informar(auxKilometros, auxTarjetaDebito_Aerolineas, auxTarjetaCredito_Aerolineas, auxBtc_cantidadPesos_Aerolineas);

	calcular(PrecioLatam, auxKilometros, &auxTarjetaDebito_Latam, &auxTarjetaCredito_Latam, &auxBtc_cantidadPesos_Latam);
	printf("\nLatam : ");
	informar(auxKilometros, auxTarjetaDebito_Latam, auxTarjetaCredito_Latam, auxBtc_cantidadPesos_Latam);

}

