/*
 * funciones.c
 *
 *  Created on: 13 abr. 2022
 *      Author: miguel
 */

#include "funciones.h"
//
//void cargaForzada(int preciokilimetros , int precioTDebito , int precioTCredito , int Preciobitcoin)
//{
//	int tarjetaDebito ;
//	int tarjetaCredito ;
//	//a) Tarjeta de débito (descuento 10%)
//	tarjetaDebito = precioTDebito*10/100 ;
//	tarjetaDebito = tarjetaDebito- precioTDebito;
//
//	//b) Tarjeta de crédito (interés 25%)
//	tarjetaCredito = precioTCredito*25/100;
//	tarjetaCredito = tarjetaCredito + precioTCredito;
//
//	//c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
//
//}

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
				auxTarjetaDebito = auxTarjetaDebito- auxPrecio;
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


}
