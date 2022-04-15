/*
 * funciones.c
 *
 *  Created on: 13 abr. 2022
 *      Author: miguel
 */

#ifndef FUNCIONES_C_
#define FUNCIONES_C_

#include "Menu.h"

int calcular(float precio , float kilometros , float *tarjetaDebito , float *tarjetaCredito , float *btc_cantidadPesos );
void informar(float auxPrecio, float auxTarjetaDebito , float auxTarjetaCredito , float auxBtc_cantidadPesos );
void cargaForzada (float auxKilometros , float precioAerolineas , float PrecioLatam);

#endif /* FUNCIONES_C_ */
