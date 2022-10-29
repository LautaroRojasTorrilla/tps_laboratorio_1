/*
 ============================================================================
 Name        : Pruebas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

int main(void) {
	setbuf(stdout, NULL);

	short prueba;
	short posta;

	if (utn_getInt("ingrese", "error", -500, 500, 1, &(short)prueba) == 0)
	{
		posta = prueba;
	}

	printf("%d", posta);

	return EXIT_SUCCESS;
}
