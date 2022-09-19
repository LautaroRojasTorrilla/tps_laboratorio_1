/*
 ============================================================================
 Name        : TP1.c
 Author      : Rojas Torrilla, Lautaro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Input.h"

int main(void) {
	setbuf(stdout, NULL);

	int menuIngreso;

	// mostrar al usuario el menú en un dowhile.
	do {
		if (GetInt("Favor de ingresar un número entre 1 y 5:\n", 3, 1, 5, "Error, ingrese entre 1 y 5.\n", &menuIngreso) == -1) {
			puts("Agotó todo slos intentos. Favor de reiniciar el programa.");
			break;
		} else {
			switch (menuIngreso) {
			case 1:
				puts("Entró 1.");
				break;
			case 2:
				puts("Entró 2.");
				break;
			case 3:
				puts("Entró 3.");
				break;
			case 4:
				puts("Entró 4.");
				break;
			case 5:
				puts("Entró 5.");
				exit (-1);
				break;
			default:
				puts("\nEntro d");
				printf("Ha seleccionado una opción no válida. Favor de elegir entre 1 y 6: ");
				break;
			}
		}//fin del else.
	} while (menuContinuar("\n\nDesea volver a iniciar el programa? Seleccione una opción:")==1 || menuIngreso == 5);

	return EXIT_SUCCESS;
}//fin del programa
