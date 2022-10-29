/*
 * eJugador.c
 *
 *  Created on: 19 oct. 2022
 *      Author: Rojas Torrilla Lautaro
 */

#include "eJugador.h"

static int genID(void);


void eJugador_printOne(eJugador jug)
{
	printf("|%2d|%-29s|%-29s|%2d |%2d  |%7.2f  |%5d|%5d\n",
			jug.id, jug.nombre, jug.posicion, jug.numeroCamiseta, jug.idConfederacion, jug.salario,
			jug.aniosContrato, jug.isEmpty);
}


int eJugador_printAll(eJugador arrayJugador[], int len, int state)
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

int eJugador_printConConf(eJugador arrayJugador[], eConfederacion arrayConf[], int lenI, int lenJ, short state)
{
	int retorno = -1;
	int i;
	int j;

	if(arrayJugador != NULL && arrayConf != NULL)
	{
		if(lenI > 0 && lenJ > 0)
		{
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

int eJugador_printJugPorConf(eJugador arrayJugador[], eConfederacion arrayConf[], int lenI, int lenJ, int idConf, short state)
{
	int retorno = -1;
	int i;
	int j;

	if(arrayJugador != NULL && arrayConf != NULL)
	{
		if(lenI > 0 && lenJ > 0 && idConf >= 100 && idConf <= 105)
		{
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

eJugador eJugadorLoadOne()
{
	eJugador j;
	eJugador bufferJ;

	eConfederacion arrayConfed[MAX_CONF] = {
			{100, "CONMEBOL", "SUDAMERICA", 1916},
			{101, "UEFA", "EUROPA", 1954},
			{102, "AFC", "ASIA", 1954},
			{103, "CAF", "AFRICA", 1957},
			{104, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961},
			{105, "OFC", "OCEANIA", 1966}
	};
	//hacer unos while con un if de que no se puede cargar. o algun tipo de mensaje.
	while(utn_getOnlyString("Ingrese el nombre del jugador: \n", "Error, debe ingresar 50 caracteres como máximo: \n", 1, MAX_CHAR, bufferJ.nombre)!=0)
	{
		strncpy(j.nombre, bufferJ.nombre, sizeof(j.nombre));
		printf("Ingresaste: %s\n", j.nombre);
	}


	while(utn_getOnlyString("Ingrese la posicion del jugador: \n", "Error, debe ingresar 50 caracteres como máximo: \n", 1, MAX_CHAR, bufferJ.posicion)!=0)
	{
		strncpy(j.posicion, bufferJ.posicion, sizeof(j.posicion));
		printf("Ingresaste: %s\n", j.posicion);
	}


	while(utn_getShort("Ingrese el numero de camiseta del jugador: \n", "Ingrese un valor entre 1 y 22\n", 1, MAX_CMST, 1, &bufferJ.numeroCamiseta)!=0)
	{
		j.numeroCamiseta=bufferJ.numeroCamiseta;
		printf("Es: %d\n", j.numeroCamiseta);
	}


	eConfederacion_printAll(arrayConfed, MAX_CONF);

	while(utn_getInt("Ingrese el ID de la confederacion del jugador: \n", "Ingrese un valor entre 100 y 106\n", 100, 106, 1, &bufferJ.idConfederacion)!=0)
	{
		j.idConfederacion=bufferJ.idConfederacion;
		printf("Es: %d\n", j.idConfederacion);
	}


	while(utn_getFloat("Ingrese el salario del jugador: \n", "Error. debe ingresar un valor entre 1 y 10000\n", 1, MAX_SAL, 1, &bufferJ.salario)!=0)
	{
		j.salario=bufferJ.salario;
		printf("Es: %.2f\n", j.salario);
	}


	while(utn_getShort("Ingrese los anios de contrato: \n", "Ingrese un valor entre 1 y 10\n", 1, MAX_CONT, 1, &bufferJ.aniosContrato)!=0)
	{
		j.aniosContrato=bufferJ.aniosContrato;
		printf("Es: %d\n", j.aniosContrato);
	}

	return j;
}

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
			utn_getShort("Seleccione el ID que desea dar de baja: ", "Error, debe seleccionar un ID valido: ", 100, 199, 2, &indexOcupado);
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

			if(utn_getInt("Ingrese el ID que desa modificar: \n", "Error, ingrese un ID válido. Entre 100 y 199: \n",100, 199, 2, &bufferID) == 0)
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
					eConfederacion_printAll(arrayConfed, MAX_CONF);

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

int eJugador_AcumAniosContByConf(eJugador arrayJugador[], eConfederacion arrayConf[], int len1, int len2, short acum[])
{
	int retorno = -1;
	int i;
	int j;

	if (arrayJugador != NULL && arrayConf != NULL && acum != NULL && len1 > 0 && len2 > 0)
	{
		for (i = 0; i < len1; ++i) //confed
		{
			for (j = 0; j < len2; ++j) //jug
			{
				if (arrayJugador[j].idConfederacion == arrayConf[i].id)
				{
					acum[i] += arrayJugador[j].aniosContrato;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

static int genID(void)
{
	static int contadorAutoincremental = 100;

	return contadorAutoincremental++;
}
