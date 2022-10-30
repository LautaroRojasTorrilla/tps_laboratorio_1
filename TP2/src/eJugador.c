/*
 * eJugador.c
 *
 *  Created on: 19 oct. 2022
 *      Author: Rojas Torrilla Lautaro
 */

#include "eJugador.h"

static int genID(void);

/// @fn void eJugador_printOne(eJugador)
/// @brief  funcion para imprimir un jugador
///
/// @param jug tipo de dato dle jugador
/// es void, muestra una impresion
void eJugador_printOne(eJugador jug)
{
	printf("|%2d|%-29s|%-29s|%2d |%2d  |%7.2f  |%5d|%5d\n",
			jug.id, jug.nombre, jug.posicion, jug.numeroCamiseta, jug.idConfederacion, jug.salario,
			jug.aniosContrato, jug.isEmpty);
}

/// @fn int eJugador_printAll(eJugador[], int, short)
/// @brief funcion para imprimir el array de jugadoress
///
/// @param arrayJugador array a evaluar
/// @param len tamaño del array
/// @param state estado del array
/// @return -1 si no pasa las validaciones, 0 si da todo ok y muestra el listado
int eJugador_printAll(eJugador arrayJugador[], int len, short state)
{
	int retorno = -1;
	int i;

	if (arrayJugador != NULL)
	{
		if (len > 0)
		{
			retorno = 0;
			//para imprimir todos puedo cambiarle el estado a -1000 por ejemplo. Uno que no coincida.
			for (i = 0; i < len; ++i)
			{
				if (arrayJugador[i].isEmpty == state)
				{
					eJugador_printOne(arrayJugador[i]);
					//eJugador_printConConf(arrayJugador, arrayConf);
				}
			}
		}else{
			retorno = -2; // es el error del len
		}
	}else{
		retorno= -3; // error de que no es null
	}
	return retorno;
}

/// @fn int eJugador_printConConf(eJugador[], eConfederacion[], int, int, short)
/// @brief funcion para imprimir el array de jugadores por conf
///
/// @param arrayJugador  array a evaluar
/// @param arrayConf array a evaluar
/// @param lenI tamaño del array
/// @param lenJ tamaño del array
/// @param state estado del array
/// @return -1 si no pasa las validaciones, 0 si da todo ok y muestra el listado
int eJugador_printConConf(eJugador arrayJugador[], eConfederacion arrayConf[], int lenI, int lenJ, short state)
{
	int retorno = -1;
	int i;
	int j;

	if(arrayJugador != NULL && arrayConf != NULL)
	{
		if(lenI > 0 && lenJ > 0)
		{
			puts("----------------------------------------------------------------------------------------------------------------------------");
			puts("| ID |         JUGADOR             |           POSICION          |NRO|         CONFEDERACION         |SALARIO  | CONTR | ESTADO");
			puts("----------------------------------------------------------------------------------------------------------------------------");
			for(i = 0; i < lenI; i++) // jugadores aca esta le ID
			{
				for(j = 0; j < lenJ; j++) // conf aca a donde pertenece
				{
					if (arrayJugador[i].idConfederacion == arrayConf[j].id
							&& arrayJugador[i].isEmpty == state && arrayConf[j].isEmpty == state)
					{
						printf("|%2d|%-29s|%-29s|%2d |%-29s  |%7.2f  |%5d|%5d\n",
								arrayJugador[i].id, arrayJugador[i].nombre, arrayJugador[i].posicion, arrayJugador[i].numeroCamiseta,
								arrayConf[j].nombre, arrayJugador[i].salario, arrayJugador[i].aniosContrato, arrayJugador[i].isEmpty);
						break;
					}
				}
			}
		}else{
			retorno = -2; // es el error del len
		}
	}else{
		retorno= -3; // error de que no es null
	}
	return retorno;
}

/// @fn int eJugador_printJugPorConf(eJugador[], eConfederacion[], int, int, int, short)
/// @brief funcion para imprimir el array de confed con sus jugadores
///
/// @param arrayJugador array a evaluar
/// @param arrayConf array a evaluar
/// @param lenI tamaño del array
/// @param lenJ tamaño del array
/// @param idConf int par ael id
/// @param state estado del arra
/// @return -1 si no pasa las validaciones, 0 si da todo ok y muestra el listado
int eJugador_printJugPorConf(eJugador arrayJugador[], eConfederacion arrayConf[], int lenI, int lenJ, int idConf, short state)
{
	int retorno = -1;
	int i;
	int j;

	if(arrayJugador != NULL && arrayConf != NULL)
	{
		if(lenI > 0 && lenJ > 0 && idConf >= 100 && idConf <= 105)
		{
			puts("--------------------------------------------------------------------------------------------------------");
			puts("|        CONFEDERACION        | ID |            NOMBRE            |       POSICION                | NRO ");
			puts("--------------------------------------------------------------------------------------------------------");
			for(i = 0; i < lenI; i++) // jugadores aca esta le ID
			{
				for(j = 0; j < lenJ; j++) // conf aca a donde pertenece
				{
					if (arrayJugador[i].idConfederacion == arrayConf[j].id && arrayConf[j].id == idConf
							&& arrayJugador[i].isEmpty == state && arrayConf[j].isEmpty == state)
					{
						switch (idConf)
						{
						case 100:
							printf("|%-29s|%2d|%-29s |%-29s  |%5d\n",
									arrayConf[j].nombre, arrayJugador[i].id, arrayJugador[i].nombre,
									arrayJugador[i].posicion, arrayJugador[i].numeroCamiseta);
							break;
						case 101:
							printf("|%-29s|%2d|%-29s |%-29s  |%5d\n",
									arrayConf[j].nombre, arrayJugador[i].id, arrayJugador[i].nombre,
									arrayJugador[i].posicion, arrayJugador[i].numeroCamiseta);
							break;
						case 102:
							printf("|%-29s|%2d|%-29s |%-29s  |%5d\n",
									arrayConf[j].nombre, arrayJugador[i].id, arrayJugador[i].nombre,
									arrayJugador[i].posicion, arrayJugador[i].numeroCamiseta);
							break;
						case 103:
							printf("|%-29s|%2d|%-29s |%-29s  |%5d\n",
									arrayConf[j].nombre, arrayJugador[i].id, arrayJugador[i].nombre,
									arrayJugador[i].posicion, arrayJugador[i].numeroCamiseta);
							break;
						case 104:
							printf("|%-29s|%2d|%-29s |%-29s  |%5d\n",
									arrayConf[j].nombre, arrayJugador[i].id, arrayJugador[i].nombre,
									arrayJugador[i].posicion, arrayJugador[i].numeroCamiseta);
							break;
						case 105:
							printf("|%-29s|%2d|%-29s |%-29s  |%5d\n",
									arrayConf[j].nombre, arrayJugador[i].id, arrayJugador[i].nombre,
									arrayJugador[i].posicion, arrayJugador[i].numeroCamiseta);
							break;
						}//fin switch
						//break;
					}
				}
			}
		}else{
			retorno = -2; // es el error del len
		}
	}else{
		retorno= -3; // error de que no es null
	}

	return retorno;
}

short eJugador_initArray(eJugador arrayJugador[], int len)
{
	short retorno = -1;
	short i;

	if (arrayJugador != NULL)
	{
		if (len > 0)
		{
			retorno=0;
			for (i = 0; i < len; ++i)
			{
				arrayJugador[i].isEmpty = LIBRE;
			}
		}else{
			retorno = -2;
		}
	}else{
		retorno= -3;
	}
	return retorno;
}

/// @fn eJugador eJugadorLoadOne()
/// @brief funcion para cargar un jugador
///
/// @return el tipo de dato del jugador
eJugador eJugadorLoadOne()
{
	eJugador j;
	eJugador bufferJ;
	int bufferInt;

	eConfederacion arrayConfed[MAX_CONF] = {
			{100, "CONMEBOL", "SUDAMERICA", 1916, 1},
			{101, "UEFA", "EUROPA", 1954, 1},
			{102, "AFC", "ASIA", 1954, 1},
			{103, "CAF", "AFRICA", 1957, 1},
			{104, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961, 1},
			{105, "OFC", "OCEANIA", 1966, 1}
	};
	//hacer unos while con un if de que no se puede cargar. o algun tipo de mensaje.
	if(utn_getOnlyString("Ingrese el nombre del jugador: \n", "Error, debe ingresar 50 caracteres como máximo: \n", 3, MAX_CHAR, bufferJ.nombre)==0)
	{
		strncpy(j.nombre, bufferJ.nombre, sizeof(j.nombre));
		printf("Ingresaste: %s\n", j.nombre);
	}

	MenuPosicion();
	if(utn_getInt("Ingrese la posicion del jugador: \n", "Ingrese un valor entre 1 y 4\n", 1, 4, 3, &bufferInt)==0)
	{
		switch (bufferInt) {
		case 1:
			strncpy(j.posicion,"arquero",sizeof(j.posicion));
			printf("Ingresaste: %s\n", j.posicion);
			break;
		case 2:
			strncpy(j.posicion,"defensor",sizeof(j.posicion));
			printf("Ingresaste: %s\n", j.posicion);
			break;
		case 3:
			strncpy(j.posicion,"mediocampista",sizeof(j.posicion));
			printf("Ingresaste: %s\n", j.posicion);
			break;
		case 4:
			strncpy(j.posicion,"delantero",sizeof(j.posicion));
			printf("Ingresaste: %s\n", j.posicion);
			break;
		}
	}

	if(utn_getShort("Ingrese el numero de camiseta del jugador: \n", "Ingrese un valor entre 1 y 22\n", 1, MAX_CMST, 3, &bufferJ.numeroCamiseta)==0)
	{
		j.numeroCamiseta=bufferJ.numeroCamiseta;
		printf("Es: %d\n", j.numeroCamiseta);
	}

	eConfederacion_printAll(arrayConfed, MAX_CONF, OCUPADO);

	if(utn_getInt("Ingrese el ID de la confederacion del jugador: \n", "Ingrese un valor entre 100 y 106\n", 100, 106, 3, &bufferJ.idConfederacion)==0)
	{
		j.idConfederacion=bufferJ.idConfederacion;
		printf("Es: %d\n", j.idConfederacion);
	}


	if(utn_getFloat("Ingrese el salario del jugador: \n", "Error. debe ingresar un valor entre 1 y 10000\n", 1, MAX_SAL, 3, &bufferJ.salario)==0)
	{
		j.salario=bufferJ.salario;
		printf("Es: %.2f\n", j.salario);
	}


	if(utn_getShort("Ingrese los anios de contrato: \n", "Ingrese un valor entre 1 y 10\n", 1, MAX_CONT, 3, &bufferJ.aniosContrato)==0)
	{
		j.aniosContrato=bufferJ.aniosContrato;
		printf("Es: %d\n", j.aniosContrato);
	}

	return j;
}

/// @fn short eJugador_SearchEmpty(eJugador[], int)
/// @brief funcion para buscar un espacio libre
///
/// @param arrayJugador array a evaluar
/// @param len tamaño del array
/// @return -1 si no pasa las validaciones, - 2 error len, -3 error array null, la posicion I libre si da ok.
short eJugador_SearchEmpty(eJugador arrayJugador[], int len)
{
	short retorno = -1;
	short i;

	if (arrayJugador != NULL)
	{
		if (len > 0)
		{
			//retorno = 0;
			for (i = 0; i < len; i++)
			{
				if (arrayJugador[i].isEmpty == LIBRE)
				{
					retorno = i;
					break;
					//No tiene sentido seguir iterando
				}
			}
		}else{
			retorno = -2;
			//mal el len
		}
	}else{
		retorno= -3;
		//vino NULL
	}
	return retorno;
}

/// @fn short eJugador_SearchOcupado(eJugador[], int)
/// @brief funcion para buscar un espacio ocupado
///
/// @param arrayJugador array a evaluar
/// @param len tamaño del array
short eJugador_SearchOcupado(eJugador arrayJugador[], int len)
{
	short retorno = -1;
	short i;

	if (arrayJugador != NULL)
	{
		if (len > 0)
		{
			for (i = 0; i < len; i++)
			{
				if (arrayJugador[i].isEmpty == OCUPADO)
				{
					retorno = i;
					break;
					//No tiene sentido seguir iterando
				}
			}
		}else{
			retorno = -2;
			//mal el lenaño
		}
	}else{
		retorno= -3;
		//vino NULL
	}
	return retorno;
}

/// @fn int eJugador_SearchIndexByID(eJugador[], int, int)
/// @brief  busca index por ID
///
/// @param arrayJugador array a evaluar
/// @param len tamaño del array
/// @param id id a buscar
/// @return-1 si no pasa las validaciones, - 2 error len, -3 error array null, posicion I del ID  si da ok.
int eJugador_SearchIndexByID(eJugador arrayJugador[], int len, int id)
{
	int retorno = -1;
	int i;

	if (arrayJugador != NULL)
	{
		if (len > 0)
		{
			retorno = 0;
			for (i = 0; i < len; i++)
			{
				if (arrayJugador[i].isEmpty == OCUPADO)
				{
					if (arrayJugador[i].id == id)
					{
						retorno = i;
						break;
					}
				}
			}
		}else{
			retorno = -2;
			//mal el lenaño
		}
	}else{
		retorno= -3;
		//vino NULL
	}
	return retorno;
}

/// @fn short eJugador_Charge(eJugador[], int)
/// @brief uncion para alta de jugadores, verifica que haya un espacio libre y cuando carga ok le da el estado de ocupado
///
/// @param arrayJugador array a evaluar
/// @param len tamaño del array
/// @return -1 si el array es nulo, -2 si le len esta mal definido, -3 si el array esta lleno, sino retorna 0 y carga el libro
short eJugador_Charge(eJugador arrayJugador[], int len)
{
	short retorno = -1;
	short indexLibre;
	eJugador bufferJugador;

	indexLibre = eJugador_SearchEmpty(arrayJugador, len);

	if (arrayJugador != NULL)
	{
		if (len > 0)
		{
			if (indexLibre >= 0)
			{
				//CARGO DATOS NO GENERICOS
				bufferJugador = eJugadorLoadOne();

				//SI ESTA TODO BIEN - LE DOY UN ID UNICO
				bufferJugador.id = genID();
				//CAMBIO ESTADO A OCUPADO
				bufferJugador.isEmpty = OCUPADO;
				//COPIA AUXILIAR EN ARRAY EN POSICION OBTENIDA LIBRE
				arrayJugador[indexLibre] = bufferJugador;
				retorno = indexLibre;
			}else{
				//array lleno o no inicializado
				retorno = -3;
			}
		}else{
			// len mal definido
			retorno = -2;
		}
	}else{
		//array nulo
		retorno= -1;
	}
	return retorno;
}

/// @fn short eJugador_Discharge(eJugador[], int)
/// @brief funcion para dar de baja un jugador, verifica que haya cargado
///
/// @param arrayJugador array a evaluar
/// @param len tamaño del array
/// @return -1 si no pasa las validaciones, - 2 error len, -3 error array null, 0 si da baja ok
short eJugador_Discharge(eJugador arrayJugador[], int len)
{
	short retorno = -1;
	short indexOcupado;

	indexOcupado = eJugador_SearchOcupado(arrayJugador, len);

	if (arrayJugador != NULL)
	{
		if (len > 0)
		{
			eJugador_printAll(arrayJugador, len, OCUPADO);
			fflush(stdin);
			utn_getShort("Seleccione el ID que desea dar de baja: ", "Error, debe seleccionar un ID valido: ", 1000, 4000, 2, &indexOcupado);
			for (int i = 0; i < len; ++i)
			{
				if(indexOcupado == arrayJugador[i].id)
				{
					arrayJugador[i].isEmpty = BAJA;
					retorno = 0;
					break;
				}
			}
		}else{
			// len mal definido
			retorno = -2;
		}
	}else{
		//array nulo
		retorno= -1;
	}
	return retorno;
}

/// @fn int eJugador_Modify(eJugador[], int)
/// @brief  funcion para modificar un jugador cargado, valida que haya alguno cargado
///
/// @param arrayJugador array a evaluar
/// @param len tamaño del array
/// @return  -1 si no pasa las validaciones, - 2 error len, -3 error array null, 0 si modifica  ok
int eJugador_Modify(eJugador arrayJugador[], int len)
{
	int retorno = -1;;
	int bufferID;
	int bufferIndex;
	int atributoAModificar;
	eJugador bufferJ;

	eConfederacion arrayConfed[MAX_CONF] = {
			{100, "CONMEBOL", "SUDAMERICA", 1916},
			{101, "UEFA", "EUROPA", 1954},
			{102, "AFC", "ASIA", 1954},
			{103, "CAF", "AFRICA", 1957},
			{104, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961},
			{105, "OFC", "OCEANIA", 1966}
	};

	if (arrayJugador != NULL)
	{
		if (len > 0)
		{
			eJugador_printAll(arrayJugador, len, OCUPADO);
			fflush(stdin);

			if(utn_getInt("Ingrese el ID que desa modificar: \n", "Error, ingrese un ID válido. Entre 1000 y 4000: \n",1000, 4000, 2, &bufferID) == 0)
			{
				bufferIndex = eJugador_SearchIndexByID(arrayJugador, len, bufferID);

				if(bufferIndex > -1)
				{

					bufferJ = arrayJugador[bufferIndex];
					eJugador_printOne(bufferJ);
				}
			}
			do {
				MenuModificar();
				utn_getInt("Indique el campo a modificar: \n", "Error. Elija entre 1 y 7", 1, 7, 2, &atributoAModificar);

				switch (atributoAModificar)
				{
				case 1:
					if(utn_getOnlyString("Ingrese el nombre del jugador: \n", "Error, debe ingresar 50 caracteres como máximo: \n", 1, MAX_CHAR, bufferJ.nombre)==0)
					{
						strncpy(arrayJugador[bufferIndex].nombre, bufferJ.nombre, sizeof(arrayJugador[bufferIndex].nombre));
						printf("Ingresaste: %s\n", arrayJugador[bufferIndex].nombre);
					}
					else
					{
						puts("Error al modificar el nombre.\n");
					}
					break;
				case 2:
					if(utn_getOnlyString("Ingrese la posicion del jugador: \n", "Error, debe ingresar 50 caracteres como máximo: \n", 1, MAX_CHAR, bufferJ.posicion)==0)
					{
						strncpy(arrayJugador[bufferIndex].posicion, bufferJ.posicion, sizeof(arrayJugador[bufferIndex].posicion));
						printf("Ingresaste: %s\n", arrayJugador[bufferIndex].posicion);
					}
					else
					{
						puts("Error al modificar la posición.\n");
					}
					break;
				case 3:
					if(utn_getShort("Ingrese el numero de camiseta del jugador: \n", "Ingrese un valor entre 1 y 22\n", 1, MAX_CMST, 1, &bufferJ.numeroCamiseta)==0)
					{
						arrayJugador[bufferIndex].numeroCamiseta = bufferJ.numeroCamiseta;
						printf("Es: %d\n", arrayJugador[bufferIndex].numeroCamiseta);
					}
					else
					{
						puts("Error al modificar el numero de camiseta.\n");
					}
					break;
				case 4:
					eConfederacion_printAll(arrayConfed, MAX_CONF, OCUPADO);

					if(utn_getInt("Ingrese el ID de la confederacion del jugador: \n", "Ingrese un valor entre 100 y 106\n", 100, 106, 1, &bufferJ.idConfederacion)==0)
					{
						arrayJugador[bufferIndex].idConfederacion = bufferJ.idConfederacion;
						printf("Es: %d\n", arrayJugador[bufferIndex].idConfederacion);
					}
					else
					{
						puts("Error al modificar el ID de la confederacion.\n");
					}
					break;
				case 5:
					if(utn_getFloat("Ingrese el salario del jugador: \n", "Error. debe ingresar un valor entre 1 y 10000\n", 1, MAX_SAL, 1, &bufferJ.salario)==0)
					{
						arrayJugador[bufferIndex].salario = bufferJ.salario;
						printf("Es: %.2f\n", arrayJugador[bufferIndex].salario);
					}
					else
					{
						puts("Error al modificar el salario.\n");
					}
					break;
				case 6:
					if(utn_getShort("Ingrese los anios de contrato: \n", "Ingrese un valor entre 1 y 10\n", 1, MAX_CONT, 1, &bufferJ.aniosContrato)==0)
					{
						arrayJugador[bufferIndex].aniosContrato = bufferJ.aniosContrato;
						printf("Es: %d\n", arrayJugador[bufferIndex].aniosContrato);
					}
					else
					{
						puts("Error al modificar los anios de contrato.\n");
					}
					break;
				case 7:
					break;
				default:
					puts("Ingrese una opcion valida.\n");
					break;
				}//final del switch
				//}//fin del if del get
			} while (atributoAModificar != 7);
			retorno = 0;
		}else{
			// len mal definido
			retorno = -2;
		}
	}else{
		//array nulo
		retorno= -1;
	}

	return retorno;
}

/// @fn int eJugador_SortByConf(eJugador[], eConfederacion[], int, int)
/// @brief funcion que ordena los jugadores por confederacion
///
/// @param arrayJugador array a evaluar
/// @param arrayConf array a evaluar
/// @param len tamaño del array
/// @param orden orden del ordenamiento
/// @return
int eJugador_SortByConf(eJugador arrayJugador[], eConfederacion arrayConf[], int len, int orden)
{
	int retorno = -1;
	int i;
	int j;
	eJugador bufferJugador;
	char bufferNombre1[MAX_CHAR];
	char bufferNombre2[MAX_CHAR];

	if (arrayJugador != NULL && len > 0) { //Si existe array y límite es válido
		switch (orden)
		{
		case -1:
			for (i = 0; i < len - 1; i++)
			{
				for (j = i + 1; j < len; j++)
				{
					if (arrayJugador[i].isEmpty == OCUPADO // Verifico que ambos tengan estado "ocupado"
							&& arrayJugador[j].isEmpty == OCUPADO)
					{
						eConfederacion_Relacion(arrayConf, bufferNombre1, arrayJugador[i].idConfederacion, MAX_CONF);
						eConfederacion_Relacion(arrayConf, bufferNombre2, arrayJugador[j].idConfederacion, MAX_CONF);

						if (strcmp(bufferNombre1, bufferNombre2) > 0)
						{
							bufferJugador = arrayJugador[i]; //Intercambio posiciones
							arrayJugador[i] = arrayJugador[j];
							arrayJugador[j] = bufferJugador;
						}

					}
				}
			}
			retorno = 1;
			break;
		case 1:			for (i = 0; i < len - 1; i++)
		{
			for (j = i + 1; j < len; j++)
			{
				if (arrayJugador[i].isEmpty == OCUPADO // Verifico que ambos tengan estado "ocupado"
						&& arrayJugador[j].isEmpty == OCUPADO)
				{
					eConfederacion_Relacion(arrayConf, bufferNombre1, arrayJugador[i].idConfederacion, MAX_CONF);
					eConfederacion_Relacion(arrayConf, bufferNombre2, arrayJugador[j].idConfederacion, MAX_CONF);
					if (strcmp(bufferNombre1, bufferNombre2) < 0)
					{
						bufferJugador = arrayJugador[i]; //Intercambio posiciones
						arrayJugador[i] = arrayJugador[j];
						arrayJugador[j] = bufferJugador;
					}

				}
			}
		}
		retorno = 1;
		break;
		default:
			retorno = 0;
			puts("Error en criterio de ordenamiento");
			break;
		}
	}

	return retorno;
}

/// @fn int eJugador_SortByConfyNombre(eJugador[], eConfederacion[], int, int)
/// @brief ordena como primer criterio la confederacion y despues el nombre de los jugadores
///
/// @param arrayJugador array a evaluar
/// @param arrayConf array a evaluar
/// @param len tamaño del array
/// @param orden orden del ordenamiento
/// @return -1 si no pasa las validaciones si e sok 0
int eJugador_SortByConfyNombre(eJugador arrayJugador[], eConfederacion arrayConf[], int len, int orden)
{
	int retorno = -1;
	int i;
	int j;
	eJugador bufferJugador;

	if (arrayJugador != NULL && len > 0)
	{
		switch (orden) {
		case -1:
			eJugador_SortByConf(arrayJugador, arrayConf, len, -1);
			for (i = 0; i < len - 1; i++)
			{
				for (j = i + 1; j < len; j++)
				{
					if (arrayJugador[i].isEmpty == OCUPADO // Verifico que ambos tengan estado "ocupado"
							&& arrayJugador[j].isEmpty == OCUPADO)
					{
						if ((arrayJugador[i].idConfederacion == arrayJugador[j].idConfederacion &&
								strcmp(arrayJugador[i].nombre, arrayJugador[j].nombre) > 0)) //Criterio de ordenamiento ASCENDENTE
						{
							bufferJugador = arrayJugador[i]; //Intercambio posiciones
							arrayJugador[i] = arrayJugador[j];
							arrayJugador[j] = bufferJugador;
						}
					}
				}
			}
			retorno = 1;
			break;
		case 1:
			eJugador_SortByConf(arrayJugador, arrayConf, len, -1);
			for (i = 0; i < len - 1; i++)
			{
				for (j = i + 1; j < len; j++)
				{
					if (arrayJugador[i].isEmpty == OCUPADO // Verifico que ambos tengan estado "ocupado"
							&& arrayJugador[j].isEmpty == OCUPADO)
					{
						if (strcmp(arrayJugador[i].nombre, arrayJugador[j].nombre) < 0) //Criterio de ordenamiento ASCENDENTE
						{
							bufferJugador = arrayJugador[i]; //Intercambio posiciones
							arrayJugador[i] = arrayJugador[j];
							arrayJugador[j] = bufferJugador;
						}
					}
				}
				retorno = 1;
				break;
		default:
			retorno = 0;
			puts("Error en criterio de ordenamiento");
			break;
			}
		}
	}
	return retorno;
}

//int eJugador_AcumAniosContByConf(eJugador arrayJugador[], eConfederacion arrayConf[], int len1, int len2, short acum[])
//{
//	int retorno = -1;
//	int i;
//	int j;
//
//	if (arrayJugador != NULL && arrayConf != NULL && acum != NULL && len1 > 0 && len2 > 0)
//	{
//		for (i = 0; i < len1; ++i)
//		{
//			for (j = 0; j < len2; ++j)
//			{
//				if (arrayJugador[j].idConfederacion == arrayConf[i].id)
//				{
//					acum[i] += arrayJugador[j].aniosContrato;
//					retorno = 0;
//				}
//			}
//		}
//	}
//	return retorno;
//}

/// @fn int eJugador_MayorCantAnios(eJugador[], eConfederacion[], int, int)
/// @brief funcion para saber la conf con mayor cantidad de años de contrato
///
/// @param arrayJugador array a evaluar
/// @param arrayConf array a evaluar
/// @param len1 tamaño
/// @param len2 tamaño
/// @return -1 si no apsa las validaciones 0 si da ok y muestra.
int eJugador_MayorCantAnios(eJugador arrayJugador[], eConfederacion arrayConf[], int len1, int len2)
{
	int retorno = -1;
	char maxConf[50];
	int index;
	int i;
	int j;
	short acum;
	int maximoAnioos = 0;
	int flag = 0;

	if(arrayJugador != NULL && arrayConf != NULL && len1 > 0 && len2 > 0)
	{
		retorno = 0;
		printf("Los anios de contrato de confederacion son:\n");

		for(i = 0; i < len1; ++i) // confe
		{
			acum = 0;
			for(j = 0; j < len2; ++j) //jug
			{
				if(arrayConf[i].id == arrayJugador[j].idConfederacion
						&& arrayJugador[j].isEmpty == OCUPADO && arrayConf[i].isEmpty == OCUPADO)
				{
					acum += arrayJugador[j].aniosContrato;
				}
			}

			if(maximoAnioos < acum)
			{
				maximoAnioos = acum;
				index = i;
				strcpy(maxConf, arrayConf[index].nombre);

				flag=0;
			}
			else
			{
				if(maximoAnioos==acum)
				{
					flag=1;
				}
			}
			printf("%-10s  Anios de contrato: %d\n", arrayConf[i].nombre, acum);
		}

		if(flag==1)
		{
			printf("\nHay mas de confederacion con igual cantidad de anios.\n\n\n");
		}
		else
		{
			printf("\n\nLa confederacion con mas anios de contrato en total es : %s\n\n", maxConf);
		}
	}
	return retorno;
}

//int eJugador_PorcentajeByConf(eJugador arrayJugador[], eConfederacion arrayConf[], int len1, int len2)
//{
//	int retorno = -1;
//	int i;
//	int j;
//	int contTotal;
//	int contConf[MAX_CONF] = {0};
//	//float bufferPromedio[MAX_CONF] = {0};
//	float promedio[MAX_CONF] = {0};
//
//	if(arrayJugador != NULL && arrayConf != NULL && len1 > 0 && len2 > 0)
//	{
//		retorno = 0;
//		for(j = 0; j < len2; ++j) // confe
//		{
//			contTotal++;
//
//		}
//		printf("la contaidad total es: %d\n", contTotal);
//
//		for(i=0;i < len1 ; ++i) //confe
//		{
//			for(j= 0 ; j < len2 ;++j) //jug
//			{
//				if(arrayJugador[j].id == arrayConf[i].id &&
//						arrayJugador[j].isEmpty == OCUPADO && arrayConf[i].isEmpty == OCUPADO)
//				{
//					contConf[j]++;
//					promedio[i] = eAuxiliar_Dividir(promedio, contConf[j], contTotal);
//					printf("El promedio es: %.2f\n\n", promedio[i]);
//				}
//			}
//		}
//
//	}
//	return retorno;
//}

/// @fn int eJugador_CountbyConf(eJugador[], eConfederacion[], int, int, int[])
/// @brief funcion que cuenta los jugadores por cada confederacion
///
/// @param arrayJugador array a evaluar
/// @param arrayConf array a evaluar
/// @param len1 tamaño del array
/// @param len2 tamaño del array
/// @param cont
/// @return -1 si no pasa las validaciones 0 si da ok
int eJugador_CountbyConf(eJugador arrayJugador[], eConfederacion arrayConf[], int len1, int len2, int cont[])
{
	int retorno = -1;
	int i;
	int j;

	if (arrayJugador != NULL && arrayConf != NULL && cont != NULL && len1 > 0 && len2 > 0)
	{
		for (i = 0; i < len1; ++i) // conf
		{
			for (j = 0; j < len2; ++j) // jug
			{
				if (arrayJugador[j].idConfederacion == arrayConf[i].id)
				{
					cont[i]++;
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

/// @fn int eJugador_MayorCantJug(eJugador[], eConfederacion[], int, int)
/// @brief funcion que cuenta jugadores por region e informa cual es la que mas tiene
///
/// @param arrayJugador array a evaluar
/// @param arrayConf array a evaluar
/// @param len1 tamaño del array
/// @param len2 tamaño del array
/// @return -1 si no pas alas validaciones, si es ok 0  y muestra
int eJugador_MayorCantJug(eJugador arrayJugador[], eConfederacion arrayConf[], int len1, int len2)
{
	int retorno = -1;
	char maxConf[50];
	int idConf;
	int index;
	int i;
	int j;
	int maximoJug = 0;
	int flag = 0;
	int contador[MAX_CONF] = {0};

	if(arrayJugador != NULL && arrayConf != NULL && len1 > 0 && len2 > 0)
	{
		retorno = 0;
		eJugador_CountbyConf(arrayJugador, arrayConf, len1, len2, contador);

		for(i = 0; i < len1; ++i) // confe
		{
			for(j = 0; j < len2; ++j) //jug
			{
				if(arrayConf[i].id == arrayJugador[j].idConfederacion
						&& arrayJugador[j].isEmpty == OCUPADO && arrayConf[i].isEmpty == OCUPADO)
				{
					if(maximoJug < contador[i])
					{
						maximoJug = contador[i];
						index = i;
						strcpy(maxConf, arrayConf[index].nombre);
						idConf = arrayConf[index].id;
						flag = 0;
						eJugador_printJugPorConf(arrayJugador, arrayConf, MAX_JUG, MAX_CONF, idConf, OCUPADO);
					}
					else
					{
						if(maximoJug == contador[j])
						{
							flag=1;
						}
					}
				}
			}
		}
		if(flag == 1)
		{
			printf("\nHay mas de confederacion con igual cantidad de jugadores.\n\n\n");
		}
		else
		{
			printf("\n\nLa confederacion con mayor cantidad de jugadores es : %s\n\n", maxConf);
		}
	}
	return retorno;
}

static int genID(void)
{
	static int contadorAutoincremental = 1000;

	return contadorAutoincremental++;
}
