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
	float costoDeHospedaje = 0, costoDeComida = 0, costoDeTransporte = 0;
	int arqueros = 0, defensores = 0, mediocampistas = 0, delanteros = 0;
	int contadorAFC = 0, contadorCAF = 0, contadorCONCACAF = 0, contadorCONMEBOL = 0, contadorUEFA = 0, contadorOFC = 0;
	float promedioAFC, promedioCAF, promedioCONCACAF, promedioCONMEBOL, promedioUEFA, promedioOFC;
	int costoDeMantenimiento, costoDeMantenimientoAumentado, costoDeMantenimientoFinal;
	int costoAModificar;
	int jugadorACargar;
	int camiseta, confederacion;
	int subSeleccion;
	int flagPunto3 = 1, flagCostoAumentado = 1;

	// mostrar al usuario el menú en un dowhile.
	do {
		MenuPrincial(costoDeHospedaje, costoDeComida, costoDeTransporte, arqueros, defensores, mediocampistas, delanteros);
		if (GetInt("\n\nFavor de ingresar un número entre 1 y 5:\n", 3, 1, 5, "Error, ingrese entre 1 y 5.\n", &menuIngreso) == -1) {
			puts("Agotó todos los intentos. Favor de reiniciar el programa.");
			break;
		} else {
			switch (menuIngreso) {
			case 1:
				//puts("Entró 1.");
				//Seleccionar el costo que desea modificar. Mostrándolo en bucle dowhile.
				do {
					//mostrar los 3 valores actuales que tienen los costos.
					puts("\n\n");
					MostrarCostos(costoDeHospedaje, costoDeComida, costoDeTransporte);
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
						GetFloat("Favor de ingresar el costo de transporte:", 2, COSTOMIN, COSTOMAX, "Error. Ingrese un valor entre 1 y 150000", &costoDeTransporte);
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
				//puts("Entró 2.");
				do {
					//mostrar la cantidad de jugadores cargados por cada puesto.
					puts("\n\n");
					MostrarJugadores(arqueros, defensores, mediocampistas, delanteros);
					printf("\n\n AFC: %d\n CAF: %d\n CONCACAF %d\n CONMEBOL %d\n UEFA: %d\n", contadorAFC, contadorCAF, contadorCONCACAF, contadorCONMEBOL, contadorUEFA);
					puts("\n\nFavor de indicar que posición tiene el jugador que desea ingresar.");
					GetInt(" 1. Arquero.\n 2. Defensor.\n 3. Mediocampista.\n 4. Delantero.\n 5. Salir\nIngrese una opcion: ", 2, 1, 5, "Error, ingrese un valor entre 1 y 4", &jugadorACargar);
					switch (jugadorACargar) {
					case 1:
						//Mi programa únicamente permite reiniciar el contador porque no se evaluarán arrays en este trabajo.
						if (arqueros == 2)
						{
							puts("\n\nHa ocupado todos los espacios disponibles.");
							puts("¿Desea reiniciar la lista ?.");
							GetInt(" 1. Reiniciar.\n 2. No reiniciar", 2, 1, 2, "Error. Selecione 1 o 2", &subSeleccion);
							if (subSeleccion == 1) {
								arqueros = 0;
							}
						} else {
							GetInt("Favor de ingresar el número de camiseta del jugador: ", 2, 1, 22, "Error. Ingrese entre 1 y 22: ", &camiseta);
							puts("\n\nFavor de ingresar la confederacion a la cual pertenece el jugador\n");
							GetInt(" 1. AFC.\n 2. CAF.\n 3. CONCACAF\n 4. CONMEBOL.\n 5. UEFA.\n 6. OFC.\nIngrese una opcion: ", 2, 1, 7, "Error, ingrese un valor entre 1 y 7", &confederacion);
							switch (confederacion) {
							case 1:
								contadorAFC++;
								break;
							case 2:
								contadorCAF++;
								break;
							case 3:
								contadorCONCACAF++;
								break;
							case 4:
								contadorCONMEBOL++;
								break;
							case 5:
								contadorUEFA++;
								break;
							case 6:
								contadorOFC++;
								break;
							}//fin switch de confederacion
							arqueros++;
						}
						break;
					case 2:
						if (defensores == 8) {
							puts("\n\nHa ocupado todos los espacios disponibles.");
							puts("¿Desea reiniciar la lista ?.");
							GetInt(" 1. Reiniciar.\n 2. No reiniciar", 2, 1, 2, "Error. Selecione 1 o 2", &subSeleccion);
							if (subSeleccion == 1)
							{
								defensores = 0;
							}
						} else {
							GetInt("Favor de ingresar el número de camiseta del jugador: ", 2, 1, 22, "Error. Ingrese entre 1 y 22: ", &camiseta);
							puts("\n\nFavor de ingresar la confederacion a la cual pertenece el jugador\n");
							GetInt(" 1. AFC.\n 2. CAF.\n 3. CONCACAF\n 4. CONMEBOL.\n 5. UEFA.\n 6. OFC.\nIngrese una opcion: ", 2, 1, 7, "Error, ingrese un valor entre 1 y 7", &confederacion);
							switch (confederacion) {
							case 1:
								contadorAFC++;
								break;
							case 2:
								contadorCAF++;
								break;
							case 3:
								contadorCONCACAF++;
								break;
							case 4:
								contadorCONMEBOL++;
								break;
							case 5:
								contadorUEFA++;
								break;
							case 6:
								contadorOFC++;
								break;
							}
							defensores++;
						}//fin switch de confederacion
						break;
					case 3:
						if (mediocampistas == 8) {
							puts("\n\nHa ocupado todos los espacios disponibles.");
							puts("¿Desea reiniciar la lista ?.");
							GetInt(" 1. Reiniciar.\n 2. No reiniciar", 2, 1, 2, "Error. Selecione 1 o 2", &subSeleccion);
							if (subSeleccion == 1)
							{
								mediocampistas = 0;
							}
						}
						else
						{
							GetInt("Favor de ingresar el número de camiseta del jugador: ", 2, 1, 22, "Error. Ingrese entre 1 y 22: ", &camiseta);
							puts("\n\nFavor de ingresar la confederacion a la cual pertenece el jugador\n");
							GetInt(" 1. AFC.\n 2. CAF.\n 3. CONCACAF\n 4. CONMEBOL.\n 5. UEFA.\n 6. OFC.\nIngrese una opcion: ", 2, 1, 7, "Error, ingrese un valor entre 1 y 7", &confederacion);
							switch (confederacion) {
							case 1:
								contadorAFC++;
								break;
							case 2:
								contadorCAF++;
								break;
							case 3:
								contadorCONCACAF++;
								break;
							case 4:
								contadorCONMEBOL++;
								break;
							case 5:
								contadorUEFA++;
								break;
							case 6:
								contadorOFC++;
								break;
							}//fin switch de confederacion
							mediocampistas++;
						}
						break;
					case 4:
						if (delanteros == 4)
						{
							puts("\n\nHa ocupado todos los espacios disponibles.");
							puts("¿Desea reiniciar la lista ?.");
							GetInt(" 1. Reiniciar.\n 2. No reiniciar", 2, 1, 2, "Error. Selecione 1 o 2", &subSeleccion);
							if (subSeleccion == 1)
							{
								delanteros = 0;
							}
						} else {
							GetInt("Favor de ingresar el número de camiseta del jugador: ", 2, 1, 22, "Error. Ingrese entre 1 y 22: ", &camiseta);
							puts("\n\nFavor de ingresar la confederacion a la cual pertenece el jugador\n");
							GetInt(" 1. AFC.\n 2. CAF.\n 3. CONCACAF\n 4. CONMEBOL.\n 5. UEFA.\n 6. OFC.\nIngrese una opcion: ", 2, 1, 7, "Error, ingrese un valor entre 1 y 7", &confederacion);
							switch (confederacion) {
							case 1:
								contadorAFC++;
								break;
							case 2:
								contadorCAF++;
								break;
							case 3:
								contadorCONCACAF++;
								break;
							case 4:
								contadorCONMEBOL++;
								break;
							case 5:
								contadorUEFA++;
								break;
							case 6:
								contadorOFC++;
								break;
							}//fin switch de confederacion
							delanteros++;
						}
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
				//puts("Entró 3.");
				if(costoDeHospedaje == 0 || costoDeComida == 0 || costoDeTransporte == 0
						|| contadorAFC == 0 || contadorCAF == 0 || contadorCONCACAF == 0 || contadorCONMEBOL == 0 || contadorUEFA == 0 || contadorOFC == 0)
				{
					puts("Debe completar los puntos 1 y 2 previamente.");
				}
				else
				{
					promedioAFC = Promediar(contadorAFC, Sumar6Variables(contadorAFC, contadorCAF, contadorCONCACAF, contadorCONMEBOL, contadorUEFA, contadorOFC));
					promedioCAF = Promediar(contadorCAF, Sumar6Variables(contadorAFC, contadorCAF, contadorCONCACAF, contadorCONMEBOL, contadorUEFA, contadorOFC));
					promedioCONCACAF = Promediar(contadorCONCACAF, Sumar6Variables(contadorAFC, contadorCAF, contadorCONCACAF, contadorCONMEBOL, contadorUEFA, contadorOFC));
					promedioCONMEBOL = Promediar(contadorCONMEBOL, Sumar6Variables(contadorAFC, contadorCAF, contadorCONCACAF, contadorCONMEBOL, contadorUEFA, contadorOFC));
					promedioUEFA = Promediar(contadorUEFA, Sumar6Variables(contadorAFC, contadorCAF, contadorCONCACAF, contadorCONMEBOL, contadorUEFA, contadorOFC));
					promedioOFC	= Promediar(contadorOFC, Sumar6Variables(contadorAFC, contadorCAF, contadorCONCACAF, contadorCONMEBOL, contadorUEFA, contadorOFC));
					costoDeMantenimiento = Sumar3Variables(costoDeComida, costoDeTransporte, costoDeHospedaje);
					if (promedioUEFA > promedioCAF && promedioUEFA > promedioCONCACAF
							&& promedioUEFA > promedioCONMEBOL && promedioUEFA > promedioOFC)
					{
						costoDeMantenimientoAumentado = costoDeMantenimiento * 0.35;
						costoDeMantenimientoFinal = costoDeMantenimiento + costoDeMantenimientoAumentado;
						flagCostoAumentado = 0;
					}
					flagPunto3 = 0;
					puts("\n\nSE REALIZARON LOS CALCULOS CORRECTAMENTE");
				}
				break;
			case 4:
				//puts("Entró 4.");
				if(flagPunto3 == 1)
				{
					puts("Debe realizar el punto 3 previamente.");
				}
				else
				{
					MenuInformacion(promedioUEFA, promedioCONMEBOL, promedioCONCACAF, promedioAFC, promedioOFC, promedioCAF);
					if (flagCostoAumentado == 0)
					{
						printf("El costo de mantenimiento era %d, y recibió un aumento de %d, el valor final es de %d\n", costoDeMantenimiento, costoDeMantenimientoAumentado, costoDeMantenimientoFinal);
					} else
					{
						printf("El costo de mantenimiento es: %d, el mismo no ha tenido aumento\n", costoDeMantenimiento);
					}
					system("pause");
				}
				break;
			case 5:
				//puts("Entró 5.");
				exit (-1);
				break;
			default:
				//puts("\nEntro d");
				printf("Ha seleccionado una opción no válida. Favor de elegir entre 1 y 6: ");
				break;
			}
		}//fin del else.
	} while (menuContinuarFinal("\n\n¿Desea volver a visualizar el menu principal? Seleccione una opción:") == 1 || menuIngreso == 5);

	return EXIT_SUCCESS;
}//fin del programa
