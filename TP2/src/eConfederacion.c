/*
 * eConfederacion.c
 *
 *  Created on: 19 oct. 2022
 *      Author: Rojas Torrilla Lautaro
 */

#include "eConfederacion.h"

void eConfederacion_printOne(eConfederacion conf)
{
	printf("|%5d|%-20s|%-20s|%5d\n",
			conf.id, conf.nombre, conf.region, conf.aniocreacion);
}

int eConfederacion_printAll(eConfederacion arrayConf[], int len)
{
	int retorno = -1;
	int i;

	if (arrayConf != NULL)
	{
		if (len > 0)
		{
			retorno = 0;
			//para imprimir todos puedo cambiarle el estado a -1000 por ejemplo. Uno que no coincida.
			for (i = 0; i < len; ++i)
			{
				eConfederacion_printOne(arrayConf[i]);
			}
		}else{
			retorno = -2; // es el error del len
		}
	}else{
		retorno= -3; // error de que no es null
	}
	return retorno;
}

eConfederacion eConfederacionLoadOne()
{
	eConfederacion c;
	eConfederacion bufferC;

	while(utn_getStringAndNum("Ingrese el nombre de la confederacion: \n", "Error, debe ingresar 50 caracteres como máximo: \n", 1, MAX_CHAR, bufferC.nombre)!=0)
	{
		strncpy(c.nombre, bufferC.nombre, sizeof(c.nombre));
		printf("Ingresaste: %s\n", c.nombre);
	}

	while(utn_getStringAndNum("Ingrese la region de la confederacion: \n", "Error, debe ingresar 50 caracteres como máximo: \n", 1, MAX_CHAR, bufferC.region)!=0)
	{
		strncpy(c.region, bufferC.region, sizeof(c.region));
		printf("Ingresaste: %s\n", c.region);
	}

	while(utn_getInt("Ingrese el anio de la confederacion: \n", "Ingrese un valor entre 1900 y 2022\n", 1, 2022, 1990, &bufferC.aniocreacion)!=0)
	{
		c.aniocreacion = bufferC.aniocreacion;
		printf("Es: %d\n", c.aniocreacion);
	}
	return c;
}

int eConfederacion_Relacion(eConfederacion arrayConf[],char bufferNombre[], int idConf, int len)
{
	int retorno = -1;
	int i;

	if(arrayConf && bufferNombre != NULL && len> 0)
	{
		for(i = 0; i < len; i++)
		{
			if (arrayConf[i].id == idConf)
			{
				strcpy(bufferNombre, arrayConf[i].nombre);
				retorno = 0;
				break;
			}
		}
	}
	else
	{
		retorno = -2;
	}
	return retorno;
}

short eConfederacion_initArray(eConfederacion arrayConf[], int len)
{
	short retorno = -1;
	short i;

	if (arrayConf != NULL)
	{
		if (len > 0)
		{
			retorno=0;
			for (i = 0; i < len; ++i)
			{
				arrayConf[i].isEmpty = LIBRE;
			}
		}else{
			retorno = -2;
		}
	}else{
		retorno= -3;
	}
	return retorno;
}

short eConfederacion_SearchEmpty(eConfederacion arrayConf[], int len)
{
	short retorno = -1;
	short i;

	if (arrayConf != NULL)
	{
		if (len > 0)
		{
			//retorno = 0;
			for (i = 0; i < len; i++)
			{
				if (arrayConf[i].isEmpty == LIBRE)
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

short eConfederacion_SearchOcupado(eConfederacion arrayConf[], int len)
{
	short retorno = -1;
	short i;

	if (arrayConf != NULL)
	{
		if (len > 0)
		{
			for (i = 0; i < len; i++)
			{
				if (arrayConf[i].isEmpty == OCUPADO)
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

int eConfederacion_SearchIndexByID(eConfederacion arrayConf[], int len, int id)
{
	int retorno = -1;
	int i;

	if (arrayConf != NULL)
	{
		if (len > 0)
		{
			retorno = 0;
			for (i = 0; i < len; i++)
			{
				if (arrayConf[i].isEmpty == OCUPADO)
				{
					if (arrayConf[i].id == id)
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

short eConfederacion_Charge(eConfederacion arrayConf[], int len)
{
	short retorno = -1;
	short indexLibre;
	eJugador bufferConf;

	indexLibre = eJugador_SearchEmpty(arrayConf, len);

	if (arrayConf != NULL)
	{
		if (len > 0)
		{
			if (indexLibre >= 0)
			{
				//CARGO DATOS NO GENERICOS
				bufferConf = eJugadorLoadOne();

				//SI ESTA TODO BIEN - LE DOY UN ID UNICO
				bufferConf.id = genID();
				//CAMBIO ESTADO A OCUPADO
				bufferConf.isEmpty = OCUPADO;
				//COPIA AUXILIAR EN ARRAY EN POSICION OBTENIDA LIBRE
				arrayConf[indexLibre] = bufferConf;
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

short eConfederacion_Discharge(eConfederacion arrayConf[], int len)
{
	short retorno = -1;
	short indexOcupado;

	indexOcupado = eJugador_SearchOcupado(arrayConf, len);

	if (arrayConf != NULL)
	{
		if (len > 0)
		{
			eJugador_printAll(arrayConf, len, OCUPADO);
			fflush(stdin);
			utn_getShort("Seleccione el ID que desea dar de baja: ", "Error, debe seleccionar un ID valido: ", 100, 199, 2, &indexOcupado);
			for (int i = 0; i < len; ++i)
			{
				if(indexOcupado == arrayConf[i].id)
				{
					arrayConf[i].isEmpty = BAJA;
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

int eConfederacion_Modify(eConfederacion arrayConf[], int len)
{
	int retorno = -1;;
	int bufferID;
	int bufferIndex;
	int atributoAModificar;
	eConfederacion bufferC;

	if (arrayConf != NULL)
	{
		if (len > 0)
		{
			eJugador_printAll(arrayConf, len, OCUPADO);
			fflush(stdin);

			if(utn_getInt("Ingrese el ID que desa modificar: \n", "Error, ingrese un ID válido. Entre 100 y 199: \n",100, 199, 2, &bufferID) == 0)
			{
				bufferIndex = eConfederacion_SearchIndexByID(arrayConf, len, bufferID);

				if(bufferIndex > -1)
				{

					bufferC = arrayConf[bufferIndex];
					eConfederacion_printOne(bufferC);
				}
			}
			do {
				MenuModificar();
				utn_getInt("Indique el campo a modificar: \n", "Error. Elija entre 1 y 2", 1, 3, 2, &atributoAModificar);

				switch (atributoAModificar)
				{
				case 1:
					if(utn_getStringAndNum("Ingrese el nombre de la confederacion: \n", "Error, debe ingresar 50 caracteres como máximo: \n", 1, MAX_CHAR, bufferC.nombre)==0)
					{
						strncpy(arrayConf[bufferIndex].nombre, bufferC.nombre, sizeof(arrayConf[bufferIndex].nombre));
						printf("Ingresaste: %s\n", arrayConf[bufferIndex].nombre);
					}
					else
					{
						puts("Error al modificar el nombre.\n");
					}
					break;
				case 2:
					if(utn_getStringAndNum("Ingrese la region de la confederacion: \n", "Error, debe ingresar 50 caracteres como máximo: \n", 1, MAX_CHAR, bufferC.region)==0)
					{
						strncpy(arrayConf[bufferIndex].region, bufferC.region, sizeof(arrayConf[bufferIndex].region));
						printf("Ingresaste: %s\n", arrayConf[bufferIndex].region);
					}
					else
					{
						puts("Error al modificar la posición.\n");
					}
					break;
				case 3:
					if(utn_getInt("Ingrese el anio de la confederacion: \n", "Ingrese un valor entre 1900 y 2022\n", 1, 2022, 1990, &bufferC.aniocreacion)==0)
					{
						arrayConf[bufferIndex].aniocreacion = bufferC.aniocreacion;
						printf("Es: %d\n", arrayConf[bufferIndex].aniocreacion);
					}
					else
					{
						puts("Error al modificar el numero de camiseta.\n");
					}
					break;

				case 4:
					break;
				default:
					puts("Ingrese una opcion valida.\n");
					break;
				}//final del switch
				//}//fin del if del get
			} while (atributoAModificar != 4);
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
