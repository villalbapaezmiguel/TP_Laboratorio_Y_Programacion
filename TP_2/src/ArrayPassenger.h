/*
 * ArrayPassenger.h
 *
 *  Created on: 28 abr. 2022
 *      Author: miguel
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "UTN.h"

#define PASSANGER_LEN 100
#define VACIO 0
#define OCUPADO 1
#define NAME_LASTNAME 51
#define TURISTA 1
#define EJECUTIVO 2

struct
{
	int id;
	char name[NAME_LASTNAME];
	char lastName[NAME_LASTNAME];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;

}typedef Passenger;
//ABM
int initPassengers(Passenger* list, int len);
int addPassenger(Passenger* list, int len, int id);
int buscarPrimeraPosicionLibre(Passenger* list , int len, int* lugarLibre);
int printPassenger(Passenger* list, int length);
int modificacion (Passenger* list , int len , int idModificar);
int buscarPorId(Passenger* list , int len , int* id);
int baja (Passenger* list , int len , int idBaja );
void altaForzada(Passenger* list , int len ,int id, char* name , char* lastName , float price , int typePasssenger , char* codigoVuelo);

//MENU
void menu (Passenger* list , int len );
int ordenarPorApellido(Passenger* list , int len);
#endif /* ARRAYPASSENGER_H_ */
