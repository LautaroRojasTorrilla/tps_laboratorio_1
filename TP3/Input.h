/*
 * Input.h
 *
 *  Created on: 28 sep. 2022
 *      Author: Rojas Torrilla Lautar
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int utn_getInt(char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos, int *pResultado);
int utn_getShort(char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos, short *pResultado);
int getInt(int* pNumeroTomado);
int esNumerica(char cadena[]);
int myGets(char cadena[], int len);

float utn_getFloat(char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos, float *pResultado);
float getFloat(float* pFloatTomado);
float esFloat(char cadena[]);

int utn_getOnlyString(char* mensaje, char* mensajeError, int reintentos,  int len, char* pResultado);
int getNombre(char* pResultado, int len);
int getString(char* cadena, int len);
int esNombre(char* cadena,int len);

int utn_getStringAndNum(char* mensaje, char* mensajeError, int reintentos,  int len, char* pResultado);
int getNombreAndNum(char* pResultado, int len);

int utn_getChar(char* mensaje, char* mensajeError, int reintentos, char* pResultado);

int menu_confirmation(char mensaje[], char mensajeError[]);




#endif /* INPUT_H_ */
