/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN.h"
#include "ArrayPassenger.h"

int main(void) {

	setbuf(stdin, NULL);
	Passenger pPasajeros [PASSANGER_LEN];

	menu(pPasajeros, PASSANGER_LEN);

	return EXIT_SUCCESS;
}
