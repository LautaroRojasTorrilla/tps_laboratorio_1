/*
 * Funciones.h
 *
 *  Created on: 19 sep. 2022
 *      Author: Rojas Torrilla, Lautaro
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Input.h"

void MenuPrincial(float costo1, float costo2, float costo3, int arq, int def, int med, int del);
void MenuInformacion(float promedio1, float promedio2, float promedio3, float promedio4, float promedio5, float promedio6);
void MostrarCostos(float costo1, float costo2, float costo3);
void MostrarJugadores(int arq, int def, int med, int del);
int Sumar6Variables(int contador1, int contador2, int contador3, int contador4, int contador5, int contador6);
int Sumar3Variables(int operador1, int operador2, int operador3);
float Dividir(float *pResultado, int operador1, int operador2);
float Promediar(int contador, int total);

#endif /* FUNCIONES_H_ */
