#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "Menu.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = -1;

	char id[10];
	char nombreCompleto[MAX_NOMBRE];
	char edad[10];
	char posicion[MAX_POSYNAC];
	char nacionalidad[MAX_POSYNAC];
	char idSeleccion[10];

	Jugador* unJugador;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		retorno = 1;
		//lectura fantasma
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);

			unJugador = jug_newParametros(id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);

			if(unJugador != NULL)
			{
				ll_add(pArrayListJugador, unJugador);
				retorno=0;
			}
		}
	}
	return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = -1;

	Jugador* unJugador;

	if(pFile != NULL && pArrayListJugador !=NULL)
	{
		while(!feof(pFile))
		{
			unJugador = jug_new();

			if(unJugador !=NULL)
			{
				if(fread(unJugador, sizeof(unJugador),1,pFile) != 1)
				{
					free(unJugador);
					break;
				}
				else
				{
					if(ll_add(pArrayListJugador, unJugador) == 0)
					{
						retorno = 0;
					}
				}
			}// fin while feof
		}
	}

	return retorno;
}

/// @fn int parser_JugadorToText(FILE*, LinkedList*)
/// @brief parsea los datos de jugadores para texto
///
/// @param pFile puntero tipo file
/// @param pArrayListJugador puntero ll
/// @return 0 da todo ok, se inicializa en 1
int parser_JugadorToText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = 1;
	int i;

	Jugador* unJugador = NULL;

	if (pFile != NULL && pArrayListJugador != NULL)
	{

			int cantidad = ll_len(pArrayListJugador);

			fprintf(pFile,"%s,%s,%s,%s,%s,%s\n","id","nombreCompleto","edad","posicion","nacionalidad","idSeleccion");

			for (i=0; i< cantidad; i++)
			{
				unJugador = (Jugador*) ll_get(pArrayListJugador, i);

				jug_printOneFile(pFile, unJugador);
			}
			retorno = 0;
	}
	return retorno;
}

/// @fn int parser_JugadorToBinary(FILE*, LinkedList*, LinkedList*)
/// @brief pasea jugadores para binario, seleccionando confederacion
///
/// @param pFile puntero a file
/// @param pArrayListJugador puntero a ll
/// @param pArrayListSeleccion puntero a ll
/// @return se inicializa en 1, 0 si da todo ok
///
int parser_JugadorToBinary(FILE* pFile , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{

	int retorno = 1;

	Jugador* pJugador = NULL;
	Seleccion* pSeleccion = NULL;

	char confed[30];
	char auxConfed[30];
	int idSeleccion;
	int idSelec;

	LinkedList* auxListaSelecciones;
	LinkedList* auxListaJugadores;

	//trabajo con LL auxiliares
	auxListaSelecciones = ll_clone(pArrayListSeleccion);
	auxListaJugadores = ll_clone(pArrayListJugador);

	MenuConfed();
	utn_getOnlyString("Ingrese confederacion.", "Error.", 2, 30, auxConfed);

	if(pFile != NULL && pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		for(int i = 0; i < ll_len(auxListaSelecciones); i++)
		{
			pSeleccion = (Seleccion*)ll_get(auxListaSelecciones, i);
			selec_getConfederacion(pSeleccion, confed);
			selec_getId(pSeleccion, &idSelec);

			if(strcmp(confed, auxConfed) == 0) // verifico que ambas sean iguales
			{
				for(int j=0; j<ll_len(auxListaJugadores); j++) // si lo son entra en el bucle de jugadores
				{
					pJugador = (Jugador*)ll_get(auxListaJugadores, j);
					jug_getSIdSeleccion(pJugador, &idSeleccion);

					if(idSeleccion == idSelec)//relaciono las ID
					{
						controller_listarJugadoresConvocadosConPais(auxListaJugadores,  auxListaSelecciones);
						fwrite(pJugador, sizeof(Jugador), 1, pFile);
						retorno = 0;
						break;
					}
				}
			}
		}
	}

	return retorno;
}

/// @fn int parser_JugIDFromText(FILE*, char*)
/// @brief almacena 4 espacios para el id
///
/// @param pFile puntero a FILE
/// @param id puntero
/// @return se inicializa con 0, 1 si pasa la val ok.
int parser_JugIDFromText(FILE* pFile, char* id)
{
    int retorno =0;

	do{
		fflush(stdin);
		if(fgets(id,4,pFile)!=NULL)
		{
			retorno=1;
		}
	}while(!feof(pFile));

	fclose(pFile);

	return retorno;
}

/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;

	char id[10];
	char pais[MAX_POSYNAC];
	char confederacion[MAX_POSYNAC];
	char convocados[10];

	Seleccion* unaSeleccion;

	if(pFile != NULL && pArrayListSeleccion != NULL)
	{
		retorno = 1;
		//lectura fantasma
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, pais, confederacion, convocados);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, pais, confederacion, convocados);

			unaSeleccion = selec_newParametros(id, pais, confederacion, convocados);

			if(unaSeleccion != NULL)
			{
				ll_add(pArrayListSeleccion, unaSeleccion);
				retorno=0;
			}
		}
	}
	return retorno;
}

