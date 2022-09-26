/*
 * Funciones.c
 *
 *  Created on: 19 sep. 2022
 *      Author: Rojas Torrilla, Lautaro
 */

#include "Funciones.h"

/// @fn void MenuPrincial(float, float, float, int, int, int, int)
/// @brief Es el menú principal que se utilizará para la función main.
///
/// @param costo1 variable utilizada para mostrar un contador.
/// @param costo2 variable utilizada para mostrar un contador.
/// @param costo3 variable utilizada para mostrar un contador.
/// @param arq variable utilizada para mostrar un contador.
/// @param def	variable utilizada para mostrar un contador.
/// @param med	variable utilizada para mostrar un contador.
/// @param del	variable utilizada para mostrar un contador.
/// @return Retorna Void, muestra las impresiones.
void MenuPrincial(float costo1, float costo2, float costo3, int arq, int def, int med, int del)
{
	puts("\t**********************");
	puts("\t* TRABAJO PRACTICO 1 *");
	puts("\t*   MENU PRINCIPAL   *");
	puts("\t**********************");
	puts("");
	puts(" 1. INGRESO DE LOS COSTOS DE MANTENIMIENTO");
	MostrarCostos(costo1, costo2, costo3);
	puts(" 2. CARGA DE JUGADORES");
	MostrarJugadores(arq, def, med, del);
	puts(" 3. REALIZAR TODOS LOS CALCULOS");
	puts(" 4. INFORMAR TODOS LOS RESULTADOS");
	puts(" 5. SALIR");
	system("pause");
}

/// @fn void MenuInformacion(float, float, float, float, float, float)
/// @brief Es el menu que se utilizará para mostrar la inforación final
///
/// @param promedio1 variable utilizada para mostrar el promedio/porcentaje
/// @param promedio2 variable utilizada para mostrar el promedio/porcentaje
/// @param promedio3 variable utilizada para mostrar el promedio/porcentaje
/// @param promedio4 variable utilizada para mostrar el promedio/porcentaje
/// @param promedio5 variable utilizada para mostrar el promedio/porcentaje
/// @param promedio6 variable utilizada para mostrar el promedio/porcentaje
/// @return Retorna Void, muestra las impresiones.
void MenuInformacion(float promedio1, float promedio2, float promedio3, float promedio4, float promedio5, float promedio6)
{
	puts("\t**********************");
	puts("\t* TRABAJO PRACTICO 1 *");
	puts("\t*  MENU INFORMACION  *");
	puts("\t**********************");
	puts("");
	printf("Porcentaje UEFA %.2f\n", promedio1);
	printf("Porcentaje CONMEBOL %.2f\n", promedio2);
	printf("Porcentaje CONCACAF %.2f\n", promedio3);
	printf("Porcentaje AFC %.2f\n", promedio4);
	printf("Porcentaje OFC %.2f\n", promedio5);
	printf("Porcentaje CAF %.2f\n", promedio6);
}

/// @fn void MostrarCostos(float, float, float)
/// @brief Es el sub menú que se utilizará para mostrar los costos.
///
/// @param costo1 variable utilizada para mostrar un contador.
/// @param costo2 variable utilizada para mostrar un contador.
/// @param costo3 variable utilizada para mostrar un contador.
/// @return Retorna Void, muestra las impresiones.
void MostrarCostos(float costo1, float costo2, float costo3)
{
	printf("  COSTO DE HOSPEDAJE -> $%.2f\n", costo1);
	printf("  COSTO DE COMIDA -> $%.2f\n", costo2);
	printf("  COSTO DE TRANSPORTE -> $%.2f\n", costo3);
}

/// @fn void MostrarJugadores(int, int, int, int)
/// @brief Es el sub menú que se utilizará para mostrar los jugadores.
///
/// @param arq variable utilizada para mostrar un contador
/// @param def variable utilizada para mostrar un contador
/// @param med variable utilizada para mostrar un contador
/// @param del variable utilizada para mostrar un contador
/// @return Retorna Void, muestra las impresiones.
void MostrarJugadores(int arq, int def, int med, int del)
{
	printf("  ARQUEROS -> %d\n", arq);
	printf("  DEFENSORES -> %d\n", def);
	printf("  MEDIOCAMPISTAS -> %d\n", med);
	printf("  DELANTEROS -> %d\n", del);
}

/// @fn int Sumar6Variables(int, int, int, int, int, int)
/// @brief Funcion utilizada para sumar 6 variables distintes.
///
/// @param contador1 operador para ser sumado.
/// @param contador2 operador para ser sumado.
/// @param contador3 operador para ser sumado.
/// @param contador4 operador para ser sumado.
/// @param contador5 operador para ser sumado.
/// @param contador6 operador para ser sumado.
/// @return retorna el int de la operación.
int Sumar6Variables(int contador1, int contador2, int contador3, int contador4, int contador5, int contador6)
{
	int operacion;

	operacion = contador1 + contador2 + contador3 + contador4 + contador5 + contador6;

	return operacion;
}

/// @fn int Sumar3Variables(int, int, int)
/// @brieffuncion para sumar 3 variables.
///
/// @param operador1 operador para ser sumado.
/// @param operador2 operador para ser sumado.
/// @param operador3 operador para ser sumado.
/// @return
int Sumar3Variables(int operador1, int operador2, int operador3)
{
	int operacion;

	operacion = operador1 + operador2 + operador3;

	return operacion;
}

/// @fn float Dividir(float*, int, int)
/// @brief La función se encarga de realizar una divisón, valida que el divisor sea distinto de 0.
///
/// @param pResultado Es un puntero para utilizar la función.
/// @param operador1 Es el numero a dividir (dividendo).
/// @param operador2 Es el número que divide (divisor).
/// @return Retorna un float con el resultado de la operación
float Dividir(float *pResultado, int operador1, int operador2)
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

/// @fn float Promediar(int, int)
/// @brief funcion para calcular el promedio
///
/// @param contador variable utilizada como contador
/// @param total variable del total, también un contador.
/// @return retorna el resultado de la operación.
float Promediar(int contador, int total)
{
	float operacion;

	Dividir(&operacion, contador, total);

	return operacion;
}
