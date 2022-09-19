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
#include <ctype.h>

int GetInt(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado);

int main(void) {
	setbuf(stdout, NULL);

	int numero;

	numero =  GetInt("favor de ingresar ", 3, 0, 100, "error", &numero);

	printf("%d", numero);



	return EXIT_SUCCESS;
}

int GetInt(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado)
{
	int retorno = -1;
	// la función no pudo tomar el dato correcto. Salió mal (Se inicia con eso).
	int auxiliarInt;
	// se guarda la variable que la persona nos ingrese, pero no sabemos si está bien.
	int retornoScanF;

	if (mensaje != NULL && reintentos > 0 && minimo < maximo && mensajeError != NULL && pNumeroIngresado != NULL)
	{
		printf("%s", mensaje);
		retornoScanF = scanf("%d",&auxiliarInt);
		do {
			//printf("\t\n este es el reintento %d", reintentos);
			if (retornoScanF != 1 || auxiliarInt > maximo || auxiliarInt < minimo || isdigit(auxiliarInt))
				// Si no se hace la validación, se pide que ingrese de nuevo
			{
				printf("%s", mensajeError);
				fflush(stdin);
				retornoScanF = scanf("%d", &auxiliarInt);
				reintentos--;
			} else {
				reintentos = 0;
				*pNumeroIngresado = auxiliarInt;
				// como todas las validaciones dieron ok. Guardo el número
				retorno = 0;
			}
		} while (reintentos > 0);
	}
	return retorno;
}
