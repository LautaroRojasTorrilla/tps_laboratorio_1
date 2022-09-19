/*
 * Input.h
 *
 *  Created on: 18 sep. 2022
 *      Author: Rojas Torrilla, Lautaro
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int GetInt(char mensaje[],int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado);
int GetFloat(char mensaje[],int reintentos, int minimo, int maximo, char mensajeError[], float *pNumeroIngresadoF);
int GetChar(char *pResultado, char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos);
int GetCharSinReintentos(char *pResultado, char *mensaje, char *mensajeError, char minimo, char maximo);
int menuContinuar(char* mensaje);

#endif /* INPUT_H_ */
