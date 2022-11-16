#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Menu.h"

int main()
{
	setbuf(stdout,NULL);
	int option = 0;
	char optionListado;
	char optionConvocar;
	int optionOrdenar = 0;
	LinkedList* listaJugadores = ll_newLinkedList();
	LinkedList* listaSelecciones = ll_newLinkedList();
	int flag = 0;
	int flagbin = 0;
	int retorno;

	do{
		MenuPrincipal();
		utn_getInt("Favor de ingresar una opción: \n", "Error ingrese entre 1 y 11\n", 1, 11, 2, &option);
		switch(option)
		{
		case 1:
			if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores) == 0 &&
					controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones) == 0)
			{
				puts("\nCarga de archivos texto OK\n");
				flag = 1;
			}
//			controller_listarJugadores(listaJugadores);
//			controller_listarSelecciones(listaSelecciones);
			break;
		case 2:
			if (flag == 1)
			{
				controller_agregarJugador(listaJugadores);
			}
			else
			{
				puts("Debe haber ingresado la opción 1 previamente. \n");
			}
			break;
		case 3:
			if (flag == 1)
			{
				controller_listarJugadores(listaJugadores);
				if(controller_editarJugador(listaJugadores) == 1)
				{
					printf("Indice no encontrado\n");
				}
			}
			else
			{
				puts("Debe haber ingresado la opción 1 previamente. \n");
			}
			break;
		case 4:
			if (flag == 1)
			{
				controller_listarJugadores(listaJugadores);
				controller_removerJugador(listaJugadores, listaSelecciones);
			}
			else
			{
				puts("Debe haber ingresado la opción 1 previamente. \n");
			}
			break;
		case 5:
			if(flag == 1)
			{
				do {
					MenuListado();
					utn_getChar("Ingrese una opción: \n", "Error, ingrese una opcion valida: \n", 2, &optionListado);
					switch (optionListado) {
					case 'a':
						controller_listarJugadoresConPais(listaJugadores, listaSelecciones);
						break;
					case 'b':
						controller_listarSelecciones(listaSelecciones);
						break;
					case 'c':
						if(controller_listarJugadoresConvocadosConPais(listaJugadores, listaSelecciones) == -1)
						{
							puts("No hay jugadores convocados");
							puts("\n\n");
						}
						break;
					case 's':
						break;
					default:
						puts("Ha ingresado una opcion incorrecta");
						break;
					}
				} while (optionListado != 's');
			}
			break;
		case 6:
			if (flag == 1)
			{
				do {
					MenuConvocar();
					utn_getChar("Ingrese una opción: \n", "Error, ingrese una opcion valida: \n", 2, &optionConvocar);
					switch (optionConvocar) {
					case 'a':
						controller_convocarJugador(listaJugadores, listaSelecciones);
						break;
					case 'b':
						controller_editarSeleccion(listaSelecciones, listaJugadores);
						break;
					case 's':
						break;
					default:
						puts("Ha ingresado una opcion incorrecta");
						break;
					}
				} while (optionConvocar != 's');
			}
			else
			{
				puts("Debe haber ingresado la opción 1 previamente. \n");
			}
			break;
		case 7:
			if (flag == 1)
			{
				do {
					puts("1. Jugadores\n2. Selecciones por Conf\n3. Salir\n");
					utn_getInt("Favor de ingresar una opción: \n", "Error ingrese entre 1 y 3\n", 1, 3, 2, &optionOrdenar);
					switch (optionOrdenar) {
					case 1:
						controller_listarJugadores(listaJugadores);
						puts("\n\n");
						controller_ordenarJugadores(listaJugadores);
						break;
					case 2:
						controller_listarSelecciones(listaSelecciones);
						puts("\n\n");
						controller_ordenarSelecciones(listaSelecciones);
						puts("\n\n");
						controller_listarSelecciones(listaSelecciones);
						break;
					default:
						break;
					}
				} while (optionOrdenar != 3);
			}
			else
			{
				puts("Debe haber ingresado la opción 1 previamente. \n");
			}
			break;
		case 8:
			if (flag == 1)
			{
				controller_guardarJugadoresModoBinario("jugadoresCon.bin", listaJugadores, listaSelecciones);
				flagbin = 1;
			}
			else
			{
				puts("Debe haber ingresado la opción 1 previamente. \n");
			}
			break;
		case 9:
			if (flag == 1 && flagbin == 1)
			{
				controller_cargarJugadoresDesdeBinario("jugadoresCon.bin", listaJugadores);
			}
			else
			{
				puts("Debe haber ingresado la opción 1 previamente. \n");
			}
			break;
		case 10:
			if (flag == 1)
			{
				controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores);
			}
			else
			{
				puts("Debe haber ingresado la opción 1 previamente. \n");
			}
			break;
		case 11:
			ll_deleteLinkedList(listaJugadores);
			ll_deleteLinkedList(listaSelecciones);
			puts("Gracias por utilizar el programa desarrollado por Lautaro Rojas Torrilla");
			break;
		default:
			puts("Ha ingresado una opcion incorrecta");
			break;
		}
	}while(option != 11);

	return 0;
}

