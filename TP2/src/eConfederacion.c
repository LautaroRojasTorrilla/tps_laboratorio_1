/*
 * eConfederacion.c
 *
 *  Created on: 19 oct. 2022
 *      Author: Rojas Torrilla Lautaro
 */

#include "eConfederacion.h"

static int genID(void);

/// @fn void eFecha_printOne(eFecha)
/// @brief funcion para imprimir una confederacion
///
/// @param  es void, muestra una impresion
void eConfederacion_printOne(eConfederacion conf)
{
	printf("|%5d|%-20s|%-20s|%5d\n",
			conf.id, conf.nombre, conf.region, conf.aniocreacion);
}

/// @fn int eConfederacion_printAll(eConfederacion[], int, short)
/// @brief funcion para imprimir el array de confederacion
///
/// @param arrayConf array a evaluar
/// @param len	tamaño del array
/// @param state  estado del array
/// @return -1 si no pasa las validaciones, 0 si da todo ok y muestra el listado
int eConfederacion_printAll(eConfederacion arrayConf[], int len, short state)
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
				if (arrayConf[i].isEmpty == state)
				{
					eConfederacion_printOne(arrayConf[i]);
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

/// @fn eConfederacion eConfederacionLoadOne()
/// @brief funcion para cargar 1 confederacion, evalua con los get
///
/// @return la confederacion cargada
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

/// @fn int eConfederacion_Relacion(eConfederacion[], char[], int, int)
/// @brief funcion que se utiliza para sacar el id de una conf en una variable
///
/// @param arrayConf array a evaluar
/// @param bufferNombre array a evaluar
/// @param idConf variable
/// @param len tamaño del array
/// @return -1 si hay problema, si esta ok  0
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

/// @fn short eConfederacion_initArray(eConfederacion[], int)
/// @brief Iniciliza el array
///
/// @param arrayConf array a evaluar
/// @param len len tamaño del array
/// @return -1 si no pasa las validaciones, - 2 error len, -3 error array null, 0 si inicializa ok
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

/// @fn short eConfederacion_SearchEmpty(eConfederacion[], int)
/// @brief funcion para buscar un espacio libre
///
/// @param arrayConf array a evaluar
/// @param len tamaño
/// @return -1 si no pasa las validaciones, - 2 error len, -3 error array null, la posicion I libre si da ok.
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

/// @fn int eLibro_SearchOcupado(eLibro[], int)
/// @brief funcion para buscar un espacio ocupado
///
/// @param arrayLibro array a evaluar
/// @param len tamaño del array
/// @return -1 si no pasa las validaciones, - 2 error len, -3 error array null, la posicion I ocupada si da ok.
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

/// @fn int eLibro_SearchIndexByID(eLibro[], int, int)
/// @brief busca index por ID
///
/// @param arrayConf array a evaluar
/// @param len tamaño del array
/// @param id id a buscar
/// @return -1 si no pasa las validaciones, - 2 error len, -3 error array null, posicion I del ID  si da ok.
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

/// @fn int eLibro_Charge(eLibro[], int)
/// @brief funcion para alta de confederaciones, verifica que haya un espacio libre y cuando carga ok le da el estado de ocupado
///
/// @param arrayConf array a evaluar
/// @param len tamaño del array
/// @return -1 si el array es nulo, -2 si le len esta mal definido, -3 si el array esta lleno, sino retorna 0 y carga el libro
short eConfederacion_Charge(eConfederacion arrayConf[], int len)
{
	short retorno = -1;
	short indexLibre;
	eConfederacion bufferConf;

	indexLibre = eConfederacion_SearchEmpty(arrayConf, len);

	if (arrayConf != NULL)
	{
		if (len > 0)
		{
			if (indexLibre >= 0)
			{
				//CARGO DATOS NO GENERICOS
				bufferConf = eConfederacionLoadOne();

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

/// @fn short eConfederacion_Discharge(eConfederacion[], int)
/// @brief funcion para dar de baja un libro, verifica que haya cargado
///
/// @param arrayConf array a evaluar
/// @param len tamaño del array
short eConfederacion_Discharge(eConfederacion arrayConf[], int len)
{
	short retorno = -1;
	short indexOcupado;

	indexOcupado = eConfederacion_SearchOcupado(arrayConf, len);

	if (arrayConf != NULL)
	{
		if (len > 0)
		{
			eConfederacion_printAll(arrayConf, len, OCUPADO);
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

/// @fn int eConfederacion_Modify(eConfederacion[], int)
/// @brief funcion para modificar un libro cargado, valida que haya alguno cargado
///
/// @param arrayConf array a evaluar
/// @param len tamaño del array
/// @return -1 si no pasa las validaciones, - 2 error len, -3 error array null, 0 si modifica  ok
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
			eConfederacion_printAll(arrayConf, len, OCUPADO);
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

static int genID(void)
{
	static int contadorAutoincremental = 1000;

	return contadorAutoincremental++;
}
