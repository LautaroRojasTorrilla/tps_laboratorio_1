/*
 ============================================================================
 Name        : TP2.c
 Author      : Rojas Torrilla Lautaro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "eJugador.h"
#include "eConfederacion.h"
#include "eAuxiliar.h"
#include "Menu.h"

int main(void) {
	setbuf(stdout, NULL);

	eConfederacion arrayConfed[MAX_CONF] = {
			{100, "CONMEBOL", "SUDAMERICA", 1916, 1},
			{101, "UEFA", "EUROPA", 1954, 1},
			{102, "AFC", "ASIA", 1954, 1},
			{103, "CAF", "AFRICA", 1957, 1},
			{104, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961, 1},
			{105, "OFC", "OCEANIA", 1966, 1}
	};

	eJugador arrayJugadores[MAX_JUG] = {
			{1000, "Palermo", "delantero", 9, 100, 5000, 2, 1},
			{1001, "Materazzi", "defensor", 2, 101, 9000, 5, 1},
			{1002, "Blanco", "delantero", 11, 104, 4000, 5, 1},
			{1003, "Alonso", "mediocampista", 5, 101, 9000, 6, 1},
			{1004, "Okocha", "mediocampista", 8, 103, 5000, 2, 1},
			{1005, "Lee", "arquero", 12, 102, 3500, 1, 1},
			{1006, "Rojo", "defensor", 6, 100, 9500, 7, 1},
			{1007, "Rossi", "arquero", 1, 100, 8500, 4, 1},
			{1008, "Lukaku", "delantero", 7, 101, 4000, 3, 1},
			{1009, "Riquelme", "mediocampista", 10, 100, 9500, 8, 1}
	};

	eAuxiliar arrayAux[MAX_JUG];

	int seleccion;
	short indexLibre;
	float bufferPromedio;
	float promedio;
	short acumulador;

	//eJugador_initArray(arrayJugadores, MAX_JUG);
	eAuxiliar_initArray(arrayAux, arrayJugadores, MAX_JUG);

	do {
		MenuPrincipal();
		utn_getInt("Elija una opción: \n", "Error. Elija entre 1 y 5: \n", 1, 5, 2, &seleccion);
		switch (seleccion) {
		case 1:
			indexLibre = eJugador_SearchEmpty(arrayJugadores, MAX_JUG);
			if (indexLibre >= 0) {
				printf("El index libre es %d\n",indexLibre);
				eJugador_Charge(arrayJugadores, MAX_JUG);
			}
			else
			{
				puts("No hay espacios libres o no se inicializo el array");
			}
			break;
		case 2:
			if (eJugador_SearchOcupado(arrayJugadores, MAX_JUG) < 0)
			{
				puts("PARA PODER REALIZAR UNA BAJA DEBE HABER ALGO CARGADO.\n\n");
			}
			else
			{
				eJugador_Discharge(arrayJugadores, MAX_JUG);
			}
			break;
		case 3:
			if (eJugador_SearchOcupado(arrayJugadores, MAX_JUG) < 0)
			{
				puts("PARA PODER REALIZAR UNA MODIFICACION DEBE HABER ALGO CARGADO.\n\n");
			}
			else
			{
				eJugador_Modify(arrayJugadores, MAX_JUG);
			}
			break;
		case 4:
			do {
				MenuInformar();
				utn_getInt("Elija una opción: \n", "Error. Elija entre 1 y 7: \n", 1, 7, 2, &seleccion);
				switch (seleccion) {
				case 1:
					eJugador_printAll(arrayJugadores, MAX_JUG, OCUPADO);
					puts("\n\n\n");
					eJugador_printConConf(arrayJugadores, arrayConfed, MAX_JUG, MAX_CONF, OCUPADO);
					puts("\n\n\n");
					eJugador_SortByConfyNombre(arrayJugadores, arrayConfed, MAX_JUG, -1);
					puts("\n\n\n");
					eJugador_printConConf(arrayJugadores, arrayConfed, MAX_JUG, MAX_CONF, OCUPADO);
					break;
				case 2:
					eJugador_printJugPorConf(arrayJugadores, arrayConfed, MAX_JUG, MAX_CONF, 100, OCUPADO);
					puts("\n\n");
					eJugador_printJugPorConf(arrayJugadores, arrayConfed, MAX_JUG, MAX_CONF, 101, OCUPADO);
					puts("\n\n");
					eJugador_printJugPorConf(arrayJugadores, arrayConfed, MAX_JUG, MAX_CONF, 102, OCUPADO);
					puts("\n\n");
					eJugador_printJugPorConf(arrayJugadores, arrayConfed, MAX_JUG, MAX_CONF, 103, OCUPADO);
					puts("\n\n");
					eJugador_printJugPorConf(arrayJugadores, arrayConfed, MAX_JUG, MAX_CONF, 104, OCUPADO);
					puts("\n\n");
					eJugador_printJugPorConf(arrayJugadores, arrayConfed, MAX_JUG, MAX_CONF, 105, OCUPADO);
					puts("\n\n");
					break;
				case 3:
					eAuxiliar_AcumSal(arrayAux, arrayJugadores, MAX_JUG);
					printf("La suma de salarios es: %.2f\n\n", arrayAux->acumuladorSalario);
					eAuxiliar_Count(arrayAux, arrayJugadores, MAX_JUG);
					if (eAuxiliar_Dividir(&bufferPromedio, arrayAux->acumuladorSalario, arrayAux->contadorJug) == 0)
					{
						promedio = bufferPromedio;
					}
					else
					{
						puts("No se puede realizar el calculo.");
					}
					printf("El promedio de salarios es: %.2f\n", promedio);
					eAuxiliar_CountSupSal(arrayAux, arrayJugadores, MAX_JUG, promedio);
					printf("La cantidad de jugadores que superan el salario promedio es: %d\n\n\n", arrayAux->contadorSupSal);

					eAuxiliar_initArray(arrayAux, arrayJugadores, MAX_JUG);
					break;
				case 4:

					break;
				case 5:

					break;
				case 6:

					break;
				case 7:

					break;
				default:
					break;
				}
			} while (seleccion != 7);

			break;
		default:
			break;
		}//fin del switch
	} while (seleccion != 5);

	return EXIT_SUCCESS;
}
