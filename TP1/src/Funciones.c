/*
 * Funciones.c
 *
 *  Created on: 19 sep. 2022
 *      Author: Rojas Torrilla, Lautaro
 */

#include "Funciones.h"

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
	puts(" 3. INFORMAR TODOS LOS RESULTADOS");
	puts(" 5. SALIR");
	system("pause");
}

void MostrarCostos(float costo1, float costo2, float costo3)
{
	printf("  COSTO DE HOSPEDAJE -> $%.2f\n", costo1);
	printf("  COSTO DE COMIDA -> $%.2f\n", costo2);
	printf("  COSTO DE TRANSPORTE -> $%.2f\n", costo3);
}

void MostrarJugadores(int arq, int def, int med, int del)
{
	printf("  ARQUEROS -> %d\n", arq);
	printf("  DEFENSORES -> %d\n", def);
	printf("  MEDIOCAMPISTAS -> %d\n", med);
	printf("  DELANTEROS -> %d\n", del);
}

