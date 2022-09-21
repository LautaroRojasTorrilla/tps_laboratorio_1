/*
 ============================================================================
 Name        : TP1.c
 Author      : Rojas Torrilla, Lautaro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Funciones.h"

int main(void) {
	setbuf(stdout, NULL);

	int menuIngreso;
	float costoDeHospedaje = 0, costoDeComida = 0, costodeTransporte = 0;
	int arqueros = 0, defensores = 0, mediocampistas = 0, delanteros = 0;
	int costoAModificar;
	int jugadorACargar;
	int camiseta, confederacion;
	//en el bucle do while voy a tener que poner un contador por cada confederacion.

	// mostrar al usuario el menú en un dowhile.
	do {
		MenuPrincial(costoDeHospedaje, costoDeComida, costodeTransporte, arqueros, defensores, mediocampistas, delanteros);
		if (GetInt("\n\nFavor de ingresar un número entre 1 y 5:\n", 3, 1, 5, "Error, ingrese entre 1 y 5.\n", &menuIngreso) == -1) {
			puts("Agotó todos los intentos. Favor de reiniciar el programa.");
			break;
		} else {
			switch (menuIngreso) {
			case 1:
				puts("Entró 1.");
				//Seleccionar el costo que desea modificar. Mostrándolo en bucle dowhile.
				do {
					//mostrar los 3 valores actuales que tienen los costos.
					puts("\n\n");
					MostrarCostos(costoDeHospedaje, costoDeComida, costodeTransporte);
					puts("\n\nFavor de indicar que costo desea ingresar.");
					GetInt(" 1. Modificar costo de hospedaje.\n 2. Modificar costo de comida.\n 3. Modificar costo de transporte.\n 4. Salir.\nIngrese una opcion: ", 2, 1, 4, "Error, ingrese un valor entre 1 y 4", &costoAModificar);
					switch (costoAModificar) {
					case 1:
						GetFloat("Favor de ingresar el costo de hospedaje:", 2, COSTOMIN, COSTOMAX, "Error. Ingrese un valor entre 1 y 150000", &costoDeHospedaje);
						break;
					case 2:
						GetFloat("Favor de ingresar el costo de comida:", 2, COSTOMIN, COSTOMAX, "Error. Ingrese un valor entre 1 y 150000", &costoDeComida);
						break;
					case 3:
						GetFloat("Favor de ingresar el costo de transporte:", 2, COSTOMIN, COSTOMAX, "Error. Ingrese un valor entre 1 y 150000", &costodeTransporte);
						break;
					case 4:
						puts("Entró 4.");
						break;
					default:
						puts("\nEntro d");
						printf("Ha seleccionado una opción no válida. Favor de elegir entre 1 y 6: ");
						break;
					}//fin switch costo a modificar.
				} while (costoAModificar != 4);// fin bucle dowhile punto 1
				break;
			case 2:
				puts("Entró 2.");
				do {
					//mostrar la cantidad de jugadores cargados por cada puesto.
					puts("\n\n");
					MostrarJugadores(arqueros, defensores, mediocampistas, delanteros);
					puts("\n\nFavor de indicar que posición tiene el jugador que desea ingresar.");
					GetInt(" 1. Arquero.\n 2. Defensor.\n 3. Mediocampista.\n 4. Delantero.\n 5. Salir\nIngrese una opcion: ", 2, 1, 5, "Error, ingrese un valor entre 1 y 4", &jugadorACargar);
					switch (jugadorACargar) {
					case 1:
						GetInt("Favor de ingresar el número de camiseta del jugador: ", 2, 1, 22, "Error. Ingrese entre 1 y 22: ", &camiseta);
						puts("\n\nFavor de ingresar la confederacion a la cual pertenece el jugador\n");
						GetInt(" 1. AFC.\n 2. CAF.\n 3. CONCACAF\n 4. CONMEBOL.\n 5. UEFA.\n 6. OFC.\n 7. Salir\nIngrese una opcion:", 2, 1, 7, "Error, ingrese un valor entre 1 y 7", &confederacion);
						arqueros++;
						break;
					case 2:
						GetInt("Favor de ingresar el número de camiseta del jugador: ", 2, 1, 22, "Error. Ingrese entre 1 y 22: ", &camiseta);
						puts("\n\nFavor de ingresar la confederacion a la cual pertenece el jugador\n");
						GetInt(" 1. AFC.\n 2. CAF.\n 3. CONCACAF\n 4. CONMEBOL.\n 5. UEFA.\n 6. OFC.\n 7. Salir\nIngrese una opcion:", 2, 1, 7, "Error, ingrese un valor entre 1 y 7", &confederacion);
						defensores++;
						break;
					case 3:
						GetInt("Favor de ingresar el número de camiseta del jugador: ", 2, 1, 22, "Error. Ingrese entre 1 y 22: ", &camiseta);
						puts("\n\nFavor de ingresar la confederacion a la cual pertenece el jugador\n");
						GetInt(" 1. AFC.\n 2. CAF.\n 3. CONCACAF\n 4. CONMEBOL.\n 5. UEFA.\n 6. OFC.\n 7. Salir\nIngrese una opcion:", 2, 1, 7, "Error, ingrese un valor entre 1 y 7", &confederacion);
						mediocampistas++;
						break;
					case 4:
						GetInt("Favor de ingresar el número de camiseta del jugador: ", 2, 1, 22, "Error. Ingrese entre 1 y 22: ", &camiseta);
						puts("\n\nFavor de ingresar la confederacion a la cual pertenece el jugador\n");
						GetInt(" 1. AFC.\n 2. CAF.\n 3. CONCACAF\n 4. CONMEBOL.\n 5. UEFA.\n 6. OFC.\n 7. Salir\nIngrese una opcion:", 2, 1, 7, "Error, ingrese un valor entre 1 y 7", &confederacion);
						delanteros++;
						break;
					case 5:
						break;
					default:
						puts("\nEntro d");
						printf("Ha seleccionado una opción no válida. Favor de elegir entre 1 y 6: ");
						break;
					}//fin switch jugador.
				} while (jugadorACargar != 5);// fin bucle dowhile punto 2
				break;
			case 3:
				puts("Entró 3.");
				break;
			case 4:
				puts("Entró 4.");
				break;
			case 5:
				puts("Entró 5.");
				exit (-1);
				break;
			default:
				puts("\nEntro d");
				printf("Ha seleccionado una opción no válida. Favor de elegir entre 1 y 6: ");
				break;
			}
		}//fin del else.
	} while (menuContinuarFinal("\n\n¿Desea volver a visualizar el menu principal? Seleccione una opción:") == 1 || menuIngreso == 5);

	return EXIT_SUCCESS;
}//fin del programa
