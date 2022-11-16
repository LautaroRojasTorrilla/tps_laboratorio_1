#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "Input.h"
#include "Menu.h"

/*
int controller_buscaMaxId(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int flagMaxId = 1;
	int maxId;
	int id;
	int i;
	Jugador* jug;

	if(pArrayListJugador!=NULL && ll_len(pArrayListJugador)>0)//len mayor a 0 porque sino tiene el id 1
	{
		for(i = 0; i < ll_len((pArrayListJugador)); i++)
		{
			if((jug = ll_get(pArrayListJugador, i)) != NULL)
			{
				if(!jug_getId(jug, &id))
				{
					if(flagMaxId || id > maxId)
					{
						flagMaxId = 0;
						maxId = id;
						retorno = maxId;
					}
				}
			}
		}
	}
	return retorno;
}
 */


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;

	if(path != NULL && pArrayListJugador != NULL)
	{
		if(ll_len(pArrayListJugador)>0)
		{
			puts("Archivo cargado previamente o ya hay ingresos en la linkedList");
		}
		else
		{
			FILE* pFile=fopen(path ,"r");
			if(parser_JugadorFromText(pFile, pArrayListJugador)==1)
			{
				printf("No se pudo cargar el archivo en controller\n");
			}
			retorno = 0;
			fclose(pFile);
		}
	}
	return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;

	if(path != NULL && pArrayListJugador != NULL)
	{
		FILE* pFile = fopen("data.dat","rb");

		if(parser_JugadorFromBinary(pFile, pArrayListJugador)==1)
		{
			printf("No se pudo cargar el archivo en controller\n");
		}
		retorno = 0;
		fclose(pFile);
	}

	return retorno;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int retorno = -1;

	Jugador* unJugador = NULL;
	int opcion;
	int auxInt;
	int auxEdadInt;

	char auxId[10];
	char auxNombre[MAX_NOMBRE];
	char auxEdad[10];
	char auxPosicion[MAX_POSYNAC];
	char auxNacionalidad[MAX_POSYNAC];
	char auxIDSeleccion[10];

	if(pArrayListJugador != NULL)
	{
		//reservo espacio en memoria dinamica
		unJugador = jug_new();
		//id en archivo. Está seteado para que arranque en 371
		if(controller_cargarJugIDModoTexto("JugID.csv", auxId))
		{
			auxInt= atoi(auxId);
			auxInt++;
			sprintf(auxId,"%d",auxInt);
		}

		//alta de los demas datos

		utn_getOnlyString("Ingrese el nombre:\n", "Error, ingrese un nombre valido.\n", 2, MAX_NOMBRE, auxNombre);
		fflush(stdin);

		utn_getInt("Ingrese la edad del jugador: \n", "Error, ingrese entre 15 y 45: \n", 15, 45, 2, &auxEdadInt);
		sprintf(auxEdad, "%d", auxEdadInt);

		MenuPosiciones();

		utn_getInt("Seleccione la posicion: \n", "Error. Ingrese entre 1 y 13: \n", 1, 13, 2, &opcion);
		switch (opcion) {
		case 1:
			strncpy(auxPosicion, "Portero", sizeof(auxPosicion));
			break;
		case 2:
			strncpy(auxPosicion, "Defensa central", sizeof(auxPosicion));
			break;
		case 3:
			strncpy(auxPosicion, "Lateral izquierdo", sizeof(auxPosicion));
			break;
		case 4:
			strncpy(auxPosicion, "Lateral derecho", sizeof(auxPosicion));
			break;
		case 5:
			strncpy(auxPosicion, "Pivote", sizeof(auxPosicion));
			break;
		case 6:
			strncpy(auxPosicion, "Interior derecho", sizeof(auxPosicion));
			break;
		case 7:
			strncpy(auxPosicion, "Interior izquierdo", sizeof(auxPosicion));
			break;
		case 8:
			strncpy(auxPosicion, "Mediocentro", sizeof(auxPosicion));
			break;
		case 9:
			strncpy(auxPosicion, "Mediocentro ofensivo", sizeof(auxPosicion));
			break;
		case 10:
			strncpy(auxPosicion, "Mediapunta", sizeof(auxPosicion));
			break;
		case 11:
			strncpy(auxPosicion, "Extremo derecho", sizeof(auxPosicion));
			break;
		case 12:
			strncpy(auxPosicion, "Extremo izquierdo", sizeof(auxPosicion));
			break;
		case 13:
			strncpy(auxPosicion, "Delantero Centro", sizeof(auxPosicion));
			break;
		}

		utn_getOnlyString("Ingrese la nacionalidad:\n", "Error, ingrese nuevamente.\n", 2, MAX_POSYNAC, auxNacionalidad);
		fflush(stdin);

		strncpy(auxIDSeleccion, "0", sizeof(auxIDSeleccion));

		unJugador = jug_newParametros(auxId, auxNombre, auxEdad, auxPosicion, auxNacionalidad, auxIDSeleccion);

		if(unJugador != NULL)
		{
			controller_guardarIDJugadoresModoTexto("JugID.csv", auxId);
			ll_add(pArrayListJugador, unJugador);
			puts("Se cargo el jugador correctamente");
		}

	}

	return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int retorno = 1;
	int i;
	int auxId;
	int opc;
	int idIngresado;

	char nombreCompleto[MAX_NOMBRE];
	int edad;
	char posicion[MAX_POSYNAC];
	char nacionalidad[MAX_POSYNAC];


	Jugador* unJugador = NULL;

	if (pArrayListJugador != NULL)
	{
		if(!utn_getInt("Ingrese el ID a modificar", "Ingrese un ID válido", 0, 9999, 2, &auxId))
		{
			int cantidad = ll_len(pArrayListJugador);

			for (i=0; i< cantidad; i++)
			{
				unJugador = (Jugador*) ll_get(pArrayListJugador, i);

				if( (jug_getId(unJugador, &idIngresado) == 0) &&
						idIngresado == auxId)
				{
					printf("%-10s|%-20s|%-10s|%-20s|%-20s|%-10s|\n",
							"ID","Nombre Completo","Edad","Posicion","Nacionalidad","ID Selec");
					ll_get(pArrayListJugador, i);

					jug_printOne(unJugador);

					do{
						if(!utn_getInt("DATO A MODIF:\n1: NOMBRE\n2: EDAD\n3: POSICION\n4: NACIONALIDAD\n5: SALIR\n", "Ingrese entre 1 y 5", 1, 5, 2, &opc))
						{
							switch(opc)
							{
							case 1:
								if(!utn_getOnlyString("Ingrese el nombre\n", "Error\n", 2, MAX_NOMBRE, nombreCompleto))
								{
									if(jug_setNombreCompleto(unJugador, nombreCompleto)==-1)
									{
										printf("ERROR \nNo se pudo editar el campo\n");
									}
								}
								break;
							case 2:
								if(utn_getInt("Ingrese la edad\n", "Error\n", 0, 50, 2, &edad))
								{
									if(jug_setEdad(unJugador, edad)==-1)
									{
										printf("ERROR \nNo se pudo editar el campo\n");
									}
								}
								break;
							case 3:
								if(!!utn_getOnlyString("Ingrese posicion\n", "Error\n", 2, MAX_POSYNAC, posicion))
								{
									if(jug_setPosicion(unJugador, posicion)==-1)
									{
										printf("ERROR \nNo se pudo editar el campo\n");
									}
								}
								break;
							case 4:
								if(utn_getOnlyString("Ingrese nacionalidad\n", "Error\n", 2, MAX_POSYNAC, nacionalidad))
								{
									if(jug_setNacionalidad(unJugador, nacionalidad)==-1)
									{
										printf("ERROR \nNo se pudo editar el campo\n");
									}
								}
								break;
							case 5:
								break;
							}
						}
					}while(opc != 5);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 1;

	Jugador* unJugador = NULL;
	Seleccion* unaSeleccion = NULL;
	int i, j;

	int idElim;
	int id;
	int idSelec;
	int idSeleccion;
	int confirmacion;
	int convocados;


	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		controller_listarJugadoresConPais(pArrayListJugador, pArrayListSeleccion);
		utn_getInt("Ingresar el ID a eliminar: \n", "Error, ingrese un ID valido: \n", 0, 9999, 2, &idElim);

		for (i = 0; i < ll_len(pArrayListJugador); i++) // jugadores
		{

			unJugador = (Jugador*) ll_get(pArrayListJugador,i);
			jug_getId(unJugador, &id);

			for (j = 0; j < ll_len(pArrayListSeleccion); j++) // selec
			{
				unaSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, j);
				selec_getId(unaSeleccion, &idSelec);
				selec_getConvocados(unaSeleccion, &convocados);

				jug_getSIdSeleccion(unJugador, &idSeleccion);

				if(id == idElim && idSeleccion == idSelec)
				{
					puts("El jugador a dar de baja: \n");
					jug_printOne(unJugador);
					utn_getInt("Confirma?\n 1. SI\n 2. NO", "Error. Ingrese 1 o 2\n", 0, 2, 2, &confirmacion);

					if(confirmacion == 1)
					{
						puts("Se eliminó correctamente.\n");
						convocados--;
						selec_setConvocados(unaSeleccion, convocados);

						//elimino de la ll
						ll_remove(pArrayListJugador, i);
						//elimino de la memoria dinamica.
						jug_delete(unJugador);
						retorno = 0;
						break;
					}
				}
			}
		}
	}
	return retorno;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int i;
	int cantidad;
	Jugador* pJugador = NULL;

	if (pArrayListJugador != NULL)
	{
		cantidad = ll_len(pArrayListJugador);

		puts("\n");
		puts("--------------------------------------------------------------------------------------------------------------");
		puts("|ID|           NOMBRE            |ED|          POSICION            |        NACIONALIDAD         | ID SELEC   ");
		puts("--------------------------------------------------------------------------------------------------------------");

		for (i=0; i< cantidad; i++)
		{
			pJugador = (Jugador*) ll_get(pArrayListJugador, i);
			jug_printOne(pJugador);
		}
		retorno = 0;
	}
	return retorno;
}

/// @fn int controller_listarJugadoresConNacionalidad(LinkedList*, LinkedList*)
/// @brief funcion que se encarga de listar todos los jugadores indicando si esta o no convoado. Si lo está muestra el pais
///
/// @param pArrayListJugador ll de los jugadores
/// @param pArrayListSeleccion ll de las selecciones
/// @return -1 si no pasa las validaciones, 0 si esta todo ok.
int controller_listarJugadoresConPais(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	Jugador* pJugador = NULL;
	Seleccion* pSeleccion = NULL;
	int i, j;

	int idJug;
	char nombreCompleto[MAX_NOMBRE];
	int edad;
	char posicion[MAX_POSYNAC];
	char nacionalidad[MAX_POSYNAC];
	int idSeleccion;
	int cantidadJug;

	int idSel;
	char pais[30];
	char confederacion[30];
	int convocados;
	int cantidadSel;

	if (pArrayListJugador != NULL && pArrayListSeleccion!= NULL)
	{
		retorno = 0;
		//		pJugador = (Jugador*) ll_get(pArrayListJugador, 0);
		//		pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, 0);

		cantidadJug = ll_len(pArrayListJugador);
		cantidadSel = ll_len(pArrayListSeleccion);

		puts("\n");
		puts("--------------------------------------------------------------------------------------------------------------");
		puts("|ID|           NOMBRE            |ED|          POSICION            |        NACIONALIDAD         | SELECCION  ");
		puts("--------------------------------------------------------------------------------------------------------------");

		for (i = 0; i < cantidadJug; i++)//jugadores
		{
			pJugador = (Jugador*) ll_get(pArrayListJugador, i);

			jug_getId(pJugador, &idJug);
			jug_getNombreCompleto(pJugador, nombreCompleto);
			jug_getEdad(pJugador, &edad);
			jug_getPosicion(pJugador, posicion);
			jug_getNacionalidad(pJugador, nacionalidad);
			jug_getSIdSeleccion(pJugador, &idSeleccion);

			if(idSeleccion == 0)
			{
				printf("|%2d|%-29s|%2d|%-29s |%-29s|%-29s\n",
						idJug, nombreCompleto, edad, posicion, nacionalidad, "NO CONVOCAOD");
			}
			//se puede hacer un else.
			for (j = 0; j < cantidadSel; j++)//selecciones
			{
				pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, j);

				selec_getId(pSeleccion, &idSel);
				selec_getPais(pSeleccion, pais);
				selec_getConfederacion(pSeleccion, confederacion);
				selec_getConvocados(pSeleccion, &convocados);

				if(jug_getSIdSeleccion(pJugador, &idSeleccion) == 0 && selec_getId(pSeleccion, &idSel) == 0 &&
						idSeleccion == idSel)
				{
					printf("|%2d|%-29s|%2d|%-29s |%-29s|%-29s\n",
							idJug, nombreCompleto, edad, posicion, nacionalidad, pais);

				}

			}
		}
		puts("\n");
	}

	return retorno;
}

/// @fn int controller_listarJugadoresConvocadosConNacionalidad(LinkedList*, LinkedList*)
/// @brief lista los jugadores convocados y muestra el pais que los convoca
///
/// @param pArrayListJugador ll del jugador
/// @param pArrayListSeleccion ll de la seleccion
/// @return -1 si no pasa las validacoines, o si pasa ok y printea.
int controller_listarJugadoresConvocadosConPais(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	Jugador* pJugador = NULL;
	Seleccion* pSeleccion = NULL;
	int i, j;

	int idJug;
	char nombreCompleto[MAX_NOMBRE];
	int edad;
	char posicion[MAX_POSYNAC];
	char nacionalidad[MAX_POSYNAC];
	int idSeleccion;
	int cantidadJug;

	int idSel;
	char pais[30];
	char confederacion[30];
	int convocados;
	int cantidadSel;

	if (pArrayListJugador != NULL && pArrayListSeleccion!= NULL)
	{

		cantidadJug = ll_len(pArrayListJugador);
		cantidadSel = ll_len(pArrayListSeleccion);

		puts("\n");
		puts("--------------------------------------------------------------------------------------------------------------");
		puts("|ID|           NOMBRE            |ED|          POSICION            |        NACIONALIDAD         | SELECCION  ");
		puts("--------------------------------------------------------------------------------------------------------------");

		for (i = 0; i < cantidadJug; i++)//jugadores
		{
			pJugador = (Jugador*) ll_get(pArrayListJugador, i);

			jug_getId(pJugador, &idJug);
			jug_getNombreCompleto(pJugador, nombreCompleto);
			jug_getEdad(pJugador, &edad);
			jug_getPosicion(pJugador, posicion);
			jug_getNacionalidad(pJugador, nacionalidad);
			jug_getSIdSeleccion(pJugador, &idSeleccion);

			for (j = 0; j < cantidadSel; j++)//selecciones
			{
				pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, j);

				selec_getId(pSeleccion, &idSel);
				selec_getPais(pSeleccion, pais);
				selec_getConfederacion(pSeleccion, confederacion);
				selec_getConvocados(pSeleccion, &convocados);

				if(jug_getSIdSeleccion(pJugador, &idSeleccion) == 0 && selec_getId(pSeleccion, &idSel) == 0 &&
						idSeleccion == idSel)
				{
					printf("|%2d|%-29s|%2d|%-29s |%-29s|%-29s\n",
							idJug, nombreCompleto, edad, posicion, nacionalidad, pais);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = 0;
	int opcion;
	LinkedList* listaJugadores = NULL;

	if(pArrayListJugador != NULL)
	{
		utn_getInt("\nSeleccion el criterio de ordenamiento de los jugadores:\n1. NACIONALIDAD\n2. EDAD\n3. NOMBRE\n",
				"Error. Ingrese entre 1 y 3.\n", 1, 3, 2, &opcion);

		switch (opcion) {
		case 1:
			listaJugadores = ll_clone(pArrayListJugador);
			ll_sort(listaJugadores, jug_sortByNacionalidad, 0);
			controller_listarJugadores(listaJugadores);
			ll_clear(listaJugadores);
			break;
		case 2:
			listaJugadores = ll_clone(pArrayListJugador);
			ll_sort(listaJugadores, jug_sortByEdad, 0);
			controller_listarJugadores(listaJugadores);
			ll_clear(listaJugadores);
			break;
		case 3:
			listaJugadores = ll_clone(pArrayListJugador);
			ll_sort(listaJugadores, jug_sortByNombre, 0);
			controller_listarJugadores(listaJugadores);
			ll_clear(listaJugadores);
			break;
		case 4:
			break;
		default:
			break;
		}

	}

	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 1;
	int ejecutado;

	FILE* pFile;

	if(path != NULL && pArrayListJugador != NULL)
	{

		pFile = fopen(path, "wb");

		ejecutado = parser_JugadorToText(pFile, pArrayListJugador);

		if(ejecutado == 0)
		{
			fclose(pFile);
			retorno = 0;
		}
	}

	return retorno;
}

int controller_guardarIDJugadoresModoTexto(char* path , char* id)
{
	int retorno = 1;
	FILE* pArchivo;

	if (path != NULL && id != NULL)
	{
		pArchivo = fopen(path,"w");

		if (pArchivo != NULL)
		{
			fputs(id, pArchivo);
		}
		if(!fclose(pArchivo))
		{
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 1;
	int ejecutado;

	FILE* pFile;

	if(path != NULL && pArrayListJugador != NULL)
	{

		pFile = fopen(path, "wb");

		ejecutado = parser_JugadorToBinary(pFile, pArrayListJugador, pArrayListSeleccion);

		if(ejecutado == 0)
		{
			fclose(pFile);
			retorno = 0;
		}
	}

	return retorno;
}

/// @fn int controller_convocarJugador(LinkedList*, LinkedList*)
/// @brief Se encarga de convocar jugadores y aumentar el contador de cada seleccion
///
/// @param pArrayListJugador ll del jugador
/// @param pArrayListSeleccion ll de la seleccion
/// @return retorna 1
int controller_convocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 1;

	Jugador* unJugador = NULL;
	Seleccion* UnaSeleccion = NULL;
	int i, j;
	int flag = 0;

	int idIngresado;
	int idSeleccionJug;
	int auxid;

	int idSeleccion;
	int idSelec;
	int convocados;

	int cantidadJug;
	int cantidadSel;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		cantidadJug = ll_len(pArrayListJugador);
		cantidadSel = ll_len(pArrayListSeleccion);

		//pido el jugador y valido que exista el ID.
		controller_listarJugadores(pArrayListJugador);
		idIngresado = controller_buscarJugID(pArrayListJugador, "Ingrese el ID del jugador: \n", "Debe ingresar un ID valido.\n");

		for(i=0; i<cantidadJug; i++)
		{
			unJugador = (Jugador*) ll_get(pArrayListJugador,i);

			jug_getSIdSeleccion(unJugador, &idSeleccionJug);
			jug_getId(unJugador, &auxid);

			if(idSeleccionJug == 0 && auxid == idIngresado )
			{
				//pido id de seleccion y valido
				controller_listarSelecciones(pArrayListSeleccion);
				idSeleccion = controller_buscarSelID(pArrayListSeleccion, "Ingrese la selección\n", "Ingrese una seleccion valida.\n");

				for(j = 0; j < cantidadSel; j++) // sel
				{
					UnaSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, j);

					selec_getConvocados(UnaSeleccion, &convocados);
					selec_getId(UnaSeleccion, &idSelec);

					if(idSeleccion == idSelec && convocados < 22)
					{

						jug_setIdSeleccion(unJugador, idSeleccion);
						puts("El jugador fue convocado correctamente.\n");
						puts("\n");
						convocados ++;
						selec_setConvocados(UnaSeleccion, convocados);
						//jug_printOne(unJugador);
						controller_listarJugadoresConvocadosConPais(pArrayListJugador, pArrayListSeleccion);
						flag = 1;
						break;
					}
				}//fin del for de selecciones
			}
		}//fin del for de jugadores
	}

	if(auxid != idIngresado && flag == 0)
	{
		puts("El jugador no está dentro de la lista o ya esta convocado a una seleccion.\n");
	}


	return retorno;
}

/// @fn int controller_buscarJugID(LinkedList*, char*, char*)
/// @brief funcion para verificar que el id que se pasa este dentro de la ll
///
/// @param pArrayListJugador ll del jugador
/// @param mensaje puntero a char
/// @param mensajeError puntero a char
/// @return el id validado
int controller_buscarJugID(LinkedList* pArrayListJugador, char* mensaje, char* mensajeError)
{
	Jugador* unJugador = NULL;
	int retorno = -1;
	int i;
	int cantidad;
	int auxId;
	int id;

	if(pArrayListJugador != NULL && mensaje != NULL && mensajeError != NULL)
	{
		cantidad = ll_len(pArrayListJugador);
		utn_getInt(mensaje, mensajeError, 0, 9999, 2, &auxId);

		for (i = 0; i < cantidad; i++)
		{
			unJugador = (Jugador*) ll_get(pArrayListJugador, i);
			jug_getId(unJugador, &id);

			if(id == auxId)
			{
				printf("El jugador ingresado es: \n");
				jug_printOne(unJugador);
				retorno = auxId;
			}
		}
	}
	return retorno;
}

int controller_cargarJugIDModoTexto(char* path, char* id)
{
	int retorno = 0;
	FILE* pArchivo;

	if((pArchivo=fopen(path,"r"))!=NULL)
	{
		parser_JugIDFromText(pArchivo,id);
		retorno=1;
	}
	return retorno;
}

/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;

	if(path != NULL && pArrayListSeleccion != NULL)
	{
		if(ll_len(pArrayListSeleccion)>0)
		{
			puts("Archivo cargado previamente");
		}
		else
		{
			FILE* pFile=fopen(path ,"r");
			if(parser_SeleccionFromText(pFile, pArrayListSeleccion)==1)
			{
				printf("No se pudo cargar el archivo en controller\n");
			}
			retorno = 0;
			fclose(pFile);
		}
	}
	return retorno;
}


/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador)
{
	int retorno = 1;

	Jugador* unJugador = NULL;
	Seleccion* UnaSeleccion = NULL;
	int i, j;

	int idIngresado;
	int idSeleccionJug;
	int auxid;

	int idSelec;
	int convocados;

	int cantidadJug;
	int cantidadSel;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		cantidadJug = ll_len(pArrayListJugador);
		cantidadSel = ll_len(pArrayListSeleccion);

		controller_listarJugadoresConvocadosConPais(pArrayListJugador, pArrayListSeleccion);
		idIngresado = controller_buscarJugID(pArrayListJugador, "Ingrese el ID del jugador: \n", "Debe ingresar un ID valido.\n");

		for(i=0; i <cantidadJug; i++) // jug
		{
			unJugador = ll_get(pArrayListJugador,i);

			jug_getSIdSeleccion(unJugador, &idSeleccionJug);
			jug_getId(unJugador, &auxid);

			for(j = 0; j < cantidadSel; j++) // sel
			{
				UnaSeleccion = ll_get(pArrayListSeleccion, j);
				selec_getConvocados(UnaSeleccion, &convocados);
				selec_getId(UnaSeleccion, &idSelec);

				if(idSeleccionJug > 0 && auxid == idIngresado &&
						idSelec == idSeleccionJug && convocados <= 22)
				{

					jug_setIdSeleccion(unJugador, 0);
					printf("El jugador fue quitado correctamente.\n");
					convocados --;
					selec_setConvocados(UnaSeleccion, convocados);
					jug_printOne(unJugador);
					break;
				}
			}
		}
	}
	return retorno;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int i;
	int cantidad;
	Seleccion* pSeleccion = NULL;

	if (pArrayListSeleccion != NULL)
	{
		cantidad = ll_len(pArrayListSeleccion);

		puts("-------------------------------------------------------------------");
		puts("|ID|       SELLECCION            |         CONFEDERACION       |CON");
		puts("-------------------------------------------------------------------");


		for (i=0; i < cantidad; i++)
		{
			pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
			selec_printOne(pSeleccion);
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = -1;

	if(pArrayListSeleccion != NULL)
	{
		ll_sort(pArrayListSeleccion, selec_sortByConfed, 0);

		retorno = 0;
	}
	return retorno;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	return 1;
}

/// @fn int controller_buscarSelID(LinkedList*, char*, char*)
/// @brief funcion para verificar que el id que se pasa este dentro de la ll
///
/// @param pArrayListSeleccion ll de la seleccion
/// @param mensaje puntero a char
/// @param mensajeError puntero a char
/// @return el id validado.
int controller_buscarSelID(LinkedList* pArrayListSeleccion, char* mensaje, char* mensajeError)
{
	Seleccion* unaSeleccion = NULL;
	int retorno = -1;
	int i;
	int cantidad;
	int auxId;
	int id;

	if(pArrayListSeleccion != NULL && mensaje != NULL && mensajeError != NULL)
	{
		cantidad = ll_len(pArrayListSeleccion);
		utn_getInt(mensaje, mensajeError, 0, 32, 2, &auxId);

		for (i = 0; i < cantidad; i++)
		{
			unaSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
			selec_getId(unaSeleccion, &id);

			if(id == auxId)
			{
				printf("La seleccion ingresada es: \n");
				selec_printOne(unaSeleccion);
				retorno = auxId;
			}
		}
	}

	return retorno;
}
