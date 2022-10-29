/*
 * eAuxiliar.c
 *
 *  Created on: 29 oct. 2022
 *      Author: Rojas Torrilla Lautaro
 */

#include "eAuxiliar.h"

int eAuxiliar_initArray(eAuxiliar arrayAux[], eJugador arrayJugador[], int len)
{
	int retorno = -1;
	int i;

	if (arrayAux != NULL)
	{
		if (len > 0)
		{
			retorno=0;
			for (i = 0; i < len; ++i)
			{
				arrayAux[i].isEmpty = arrayJugador[i].isEmpty;
				arrayAux[i].acumuladorSalario = LIBRE;
				arrayAux[i].contadorJug = LIBRE;
				arrayAux[i].contadorSupSal = LIBRE;
				//arrayAux[i].acumAnios = LIBRE;
				}
		}else{
			retorno = -2;
		}
	}else{
		retorno= -3;
	}
	return retorno;
}

float eAuxiliar_AcumSal(eAuxiliar arrayAux[], eJugador arrayJugador[], int len)
{
	int i;
	int j;

	for (i = 0; i < len; i++)
	{
		for(j = 0; j < len; j++)
		{
			if (arrayAux[i].isEmpty == OCUPADO && arrayJugador[j].isEmpty == OCUPADO)
			{
				if (arrayAux[i].isEmpty == arrayJugador[j].isEmpty)
				{
					arrayAux[i].acumuladorSalario = arrayAux[i].acumuladorSalario + arrayJugador[j].salario;
				}
			}
		}
	}
	return arrayAux[i].acumuladorSalario;
}

int eAuxiliar_Count(eAuxiliar arrayAux[], eJugador arrayJugador[], int len)
{
	int i;
	int j;

	for (i = 0; i < len; i++)
	{
		for(j = 0; j < len; j++)
		{
			if (arrayAux[i].isEmpty == OCUPADO && arrayJugador[j].isEmpty == OCUPADO)
			{
				if (arrayAux[i].isEmpty == arrayJugador[j].isEmpty)
				{
					arrayAux[i].contadorJug++;
				}
			}
		}
	}
	return arrayAux[i].contadorJug;
}

int eAuxiliar_Dividir(float *pResultado, int operador1, int operador2)
{
	float resultado;
	int retorno = -1;

	if (pResultado != NULL && operador2 != 0)
	{
		resultado = (float) operador1 / operador2;
		*pResultado = resultado;
		retorno = 0;
	}

	return retorno;
}

int eAuxiliar_CountSupSal(eAuxiliar arrayAux[], eJugador arrayJugador[], int len, float promedio)
{
	int i;
	int j;

	for (i = 0; i < len; i++)
	{
		for(j = 0; j < len; j++)
		{
			if (arrayAux[i].isEmpty == OCUPADO && arrayJugador[j].isEmpty == OCUPADO)
			{
				if ((arrayAux[i].isEmpty == arrayJugador[j].isEmpty) &&
						(promedio < arrayJugador[j].salario) )
				{
					arrayAux[i].contadorSupSal++;
				}
			}
		}
	}
	return arrayAux[i].contadorSupSal;
}
