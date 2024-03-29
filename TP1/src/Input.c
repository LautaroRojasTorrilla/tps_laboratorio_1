/*
 * Input.c
 *
 *  Created on: 18 sep. 2022
 *      Author: Rojas Torrilla, Lautaro
 */

#include "Input.h"

/// @fn int getInt(char[], int, int, int, char[], int*)
/// @brief Solicita un entero realizando validaciones.
///
/// @param mensaje Es el mensaje editable que muestra qué se está ingresando (previo a scanf).
/// @param reintentos Es la cantidad de reintentos tras fallar la validación.
/// @param minimo Es el valor mínimo que tolera la función.
/// @param maximo Es el valor máximo que tolera la función.
/// @param mensajeError Es el mensaje que brindará tras fallar la validación.
/// @param pNumeroIngresado Puntero de la dirección del entero.
/// @return Retorna -1 si no pasa la validación y 0 si el entero ingresado aprueba la validación.
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

/// @fn float getFloat(char[], int, int, int, char[], float*)
/// @brief Solicita un flotante realizando validaciones.
///
/// @param mensaje Es el mensaje editable que muestra qué se está ingresando (previo a scanf).
/// @param reintentos Es la cantidad de reintentos tras fallar la validación.
/// @param minimo Es el valor mínimo que tolera la función.
/// @param maximo Es el valor máximo que tolera la función.
/// @param mensajeError Es el mensaje que brindará tras fallar la validación.
/// @param pNumeroIngresado Puntero de la dirección del entero.
/// @return Retorna -1 si no pasa la validación y 0 si el entero ingresado aprueba la validación.
int GetFloat(char mensaje[],int reintentos, int minimo, int maximo, char mensajeError[], float *pNumeroIngresadoF)
{
	int retorno = -1;
	// la función no pudo tomar el dato correcto. Salió mal (Se inicia con eso).
	float auxiliarFloat;
	// se guarda la variable que la persona nos ingrese, pero no sabemos si está bien.
	float retornoScanF;

	if (mensaje != NULL && reintentos > 0 && minimo < maximo && mensajeError != NULL && pNumeroIngresadoF != NULL)
	{
		printf("%s", mensaje);
		retornoScanF = scanf("%f",&auxiliarFloat);
		do {
			//printf("\t este es el reintento %d", reintentos);
			if (retornoScanF != 1 || auxiliarFloat > maximo || auxiliarFloat < minimo)
				// Si no se hace la validación, se pide que ingrese de nuevo
			{
				printf("%s", mensajeError);
				fflush(stdin);
				retornoScanF = scanf("%f", &auxiliarFloat);
				reintentos--;
			} else {
				reintentos = 0;
				*pNumeroIngresadoF = auxiliarFloat;
				// como todas las validaciones dieron ok. Guardo el número
				retorno = 0;
			}
		} while (reintentos > 0);
	}
	return retorno;
}

int GetChar(char *pResultado, char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos)
{
	char bufferChar; // espacio de almacenamiento intermedio
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > -1)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);
			bufferChar = tolower(bufferChar);
			if (bufferChar >= minimo && bufferChar <= maximo)
			{
				*pResultado = bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		} while (reintentos >= 0);
	}
	return retorno;
}

int GetCharSinReintentos(char *pResultado, char *mensaje, char *mensajeError, char minimo, char maximo)
{
	char bufferChar; // espacio de almacenamiento intermedio
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%c", &bufferChar);
		bufferChar = tolower(bufferChar);
		if (bufferChar >= minimo && bufferChar <= maximo)
		{
			*pResultado = bufferChar;
			retorno = 0;
		}
		else
		{
			printf("%s", mensajeError);
		}
	}
	return retorno;
}

/// @fn int menuContinuarFinal(char*)
/// @brief Menu utilizado para continuar o no la iteración.
///
/// @param mensaje Es el mensaje editable que muestra qué se está ingresando (previo a scanf).
/// @return muestra el printeo
int menuContinuarFinal(char* mensaje)
{
	int seleccion;

	printf("%s", mensaje);
	printf("\n1. Sí\n2. No\n");
	fflush(stdin);
	scanf("%d", &seleccion);
	if (seleccion==2)
	{
		printf("\n\tGracias por utilizar este programa desarrollado por Lautaro Rojas Torrilla, estudiante UTN.");
	}

	return seleccion;
}

/// @fn int menuContinuarFinal(char*)
/// @brief Menu utilizado para continuar o no la iteración.
///
/// @param mensaje Es el mensaje editable que muestra qué se está ingresando (previo a scanf).
/// @return muestra el printeo
int menuContinuar(char* mensaje)
{
	int seleccion;

	printf("%s", mensaje);
	printf("\n1. Sí\n2. No\n");
	fflush(stdin);
	scanf("%d", &seleccion);

	return seleccion;
}
