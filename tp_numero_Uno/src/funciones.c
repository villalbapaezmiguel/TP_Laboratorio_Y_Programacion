/*
 * funciones.c
 *
 *  Created on: 13 abr. 2022
 *      Author: miguel
 */

#include "funciones.h"

void cargaForzada(int preciokilimetros , int precioTDebito , int precioTCredito , int Preciobitcoin)
{
	preciokilimetros = 700;
	precioTDebito = 250 ;
	precioTCredito = 150 ;
	Preciobitcoin = 33.66;

}

/*int calcular(float precio , float kilometros)
 * esta funcion calcula los precios de :
 * float precio , float kilometros , float tarjetaDebito , float tarjetaCredito , float btc_cantidadPesos ;
 * retorna 1 si pudo calcular de lo contrario -1
 *   */
int calcular(float auxPrecio , float auxKilometros , float auxTarjetaDebito , float auxTarjetaCredito , float auxBtc_cantidadPesos )
{
	int estado =-1;
	double btc = 4606954.55;

	if(auxPrecio > 0 && auxKilometros > 0)
	{
		estado = 1;
				//Aerolíneas:
		//a) Tarjeta de débito (descuento 10%)
				auxTarjetaDebito = auxPrecio*10/100 ;
				auxTarjetaDebito = auxPrecio- auxTarjetaDebito;
				printf("\nauxTarjetaDebito : %.2f", auxTarjetaDebito);
		//b) Tarjeta de crédito (interés 25%)
				auxTarjetaCredito = auxPrecio*25/100;
				auxTarjetaCredito = auxTarjetaCredito + auxPrecio;
		//c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
				auxBtc_cantidadPesos = auxPrecio/ btc;
		//d) Mostrar precio por km (precio unitario)
	}


	return estado ;
}

void informar(float auxTarjetaDebito , float auxTarjetaCredito , float auxBtc_cantidadPesos )
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

	printf("\nA) Precio con tarjeta de débito: %.2f", auxTarjetaDebito);
	printf("\nB) Precio con tarjeta de crédito: %.2f", auxTarjetaCredito);
	printf("\nc) Precio pagando con bitcoin : %.2f", auxBtc_cantidadPesos);

}
