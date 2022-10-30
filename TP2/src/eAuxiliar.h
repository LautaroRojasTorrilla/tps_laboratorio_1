/*
 * eAuxiliar.h
 *
 *  Created on: 22 oct. 2022
 *      Author: Rojas Torrilla
 */

#ifndef EAUXILIAR_H_
#define EAUXILIAR_H_

#include "eJugador.h"
#include "eConfederacion.h"

typedef struct{
	float acumuladorSalario;
	int contadorJug;
	int contadorSupSal;
	int isEmpty;
}eAuxiliar;

#endif /* EAUXILIAR_H_ */

int eAuxiliar_initArray(eAuxiliar arrayAux[], eJugador arrayJugador[], int len);
float eAuxiliar_AcumSal(eAuxiliar arrayAux[], eJugador arrayJugador[], int len);
int eAuxiliar_Count(eAuxiliar arrayAux[], eJugador arrayJugador[], int len);
int eAuxiliar_Dividir(float *pResultado, int operador1, int operador2);
int eAuxiliar_CountSupSal(eAuxiliar arrayAux[], eJugador arrayJugador[], int len, float promedio);
int eAuxiliar_Promedio(float *pResultado, int operador1, int operador2);




