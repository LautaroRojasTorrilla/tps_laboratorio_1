/*
 * eAuxiliar.c
 *
 *  Created on: 29 oct. 2022
 *      Author: Rojas Torrilla Lautaro
 */

#include "eAuxiliar.h"

/// @fn int eAuxiliar_initArray(eAuxiliar[], eJugador[], int)
/// @brief Inicializa el array auxiliar
///
/// @param arrayAux array a evaluar
/// @param arrayJugador array a evaluar
/// @param len tamaño del array
/// @return -1 si no pasa las validaciones, - 2 error len, -3 error array null, 0 si inicializa ok
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

/// @fn float eAuxiliar_AcumSal(eAuxiliar[], eJugador[], int)
/// @brief funcion que acumula el total de salarios
///
/// @param arrayAux array a evaluar
/// @param arrayJugador array a evaluar
/// @param len tamaño del array
/// @return el acumulador de los salarios
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

/// @fn int eAuxiliar_Count(eAuxiliar[], eJugador[], int)
/// @brief funcion que cuenta el total de los jugadores
///
/// @param arrayAux array a evaluar
/// @param arrayJugador array a evaluar
/// @param len tamaño del array
/// @return el contador d elos jugadores
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

/// @fn int eAuxiliar_Dividir(float*, int, int)
/// @brief realiza una operacion de divicion
///
/// @param pResultado puntero a evaluar
/// @param operador1 variable
/// @param operador2 variable
/// @return retorno -1 si no pasa la validacion, 0 si divide ok
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

/// @fn int eAuxiliar_CountSupSal(eAuxiliar[], eJugador[], int, float)
/// @brief funcion que verifica si el salario es mayor al promedio
///
/// @param arrayAux array a evaluar
/// @param arrayJugador array a evaluar
/// @param len tamaño del array
/// @param promedio promedio a evaluar
/// @return la cantidad de jugadores que superan el promedio
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

/// @fn int eAuxiliar_Dividir(float*, int, int)
/// @brief realiza una operacion de promediar
///
/// @param pResultado puntero a evaluar
/// @param operador1 variable
/// @param operador2 variable
/// @return retorno -1 si no pasa la validacion, 0 si promedia ok
int eAuxiliar_Promedio(float *pResultado, int operador1, int operador2)
{
	float resultado;
	int retorno = -1;

	if (pResultado != NULL && operador2 != 0)
	{
		resultado = ((float) operador1 / operador2) * 100;
		*pResultado = resultado;
		retorno = 0;
	}

	return retorno;
}
