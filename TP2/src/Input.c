/*
 * Input.c
 *
 *  Created on: 28 sep. 2022
 *      Author: Rojas Torrilla Lautaro
 */

#include "Input.h"

/// @fn int utn_getInt(char[], char[], int, int, int, int*)
/// @brief Verifica que sea un número entero, devolviendo por referencia.
///
/// @param mensaje Mensaje para soliciutar dato
/// @param mensajeError Mensaje de error si no pasa las validaciones
/// @param minimo valor minimo del rango a ingresar
/// @param maximo valor maximo del rango a ingresar
/// @param reintentos cantidad permitidas de oportunidades para ingreasr el valor
/// @param pResultado puntero a analizar.
/// @return Se inicia con -1, devuelve 0 si es exitosa.
int utn_getInt(char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos, int *pResultado)
{
	int retorno = -1;
	int bufferInt;
	int retorno_getInt;

	if(mensaje != NULL && minimo < maximo && mensajeError != NULL && pResultado != NULL && reintentos > 0)
	{
		printf("\n%s",mensaje);
		fflush(stdin);
		retorno_getInt = getInt(&bufferInt);
		do
		{
			if(retorno_getInt == -1 || bufferInt > maximo || bufferInt < minimo)
			{
				printf("\n%s",mensajeError);
				reintentos--;
				printf("\nQuedan %d reintentos.",reintentos);
				printf("\n%s",mensaje);
				fflush(stdin);
				retorno_getInt = getInt(&bufferInt);
			}
			else
			{
				reintentos = 0;
				*pResultado = bufferInt;
				retorno = 0;
			}
		}while(reintentos > 0);
	}
	return retorno;
}

/// @fn int utn_getInt(char[], char[], int, int, int, int*)
/// @brief Verifica que sea un número entero short, devolviendo por referencia.
///
/// @param mensaje Mensaje para solicitar dato
/// @param mensajeError Mensaje de error si no pasa las validaciones
/// @param minimo valor minimo del rango a ingresar
/// @param maximo valor maximo del rango a ingresar
/// @param reintentos cantidad permitidas de oportunidades para ingreasr el valor
/// @param pResultado puntero a analizar.
/// @return Se inicia con -1, devuelve 0 si es exitosa.
int utn_getShort(char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos, short *pResultado)
{
	int retorno = -1;
	int bufferInt;
	int retorno_getInt;

	if(mensaje != NULL && minimo < maximo && mensajeError != NULL && pResultado != NULL && reintentos > 0)
	{
		printf("\n%s",mensaje);
		fflush(stdin);
		retorno_getInt = getInt(&bufferInt);
		do
		{
			if(retorno_getInt == -1 || bufferInt > maximo || bufferInt < minimo)
			{
				printf("\n%s",mensajeError);
				reintentos--;
				printf("\nQuedan %d reintentos.",reintentos);
				printf("\n%s",mensaje);
				fflush(stdin);
				retorno_getInt = getInt(&bufferInt);
			}
			else
			{
				reintentos = 0;
				*pResultado = bufferInt;
				retorno = 0;
			}
		}while(reintentos > 0);
	}
	return retorno;
}

/// @fn int getInt(int*)
/// @brief Analiza si lo que si ingresa es un numoer
///
/// @param pNumeroTomado puntero a analizar.
/// @return -1 si no es entero, 0 si lo es.
int getInt(int* pNumeroTomado)
{
	int retorno = -1;
	char bufferNum[200];

	if(myGets(bufferNum, sizeof(bufferNum)) == 0 && esNumerica(bufferNum) == 0)
	{
		*pNumeroTomado= atoi(bufferNum);
		retorno = 0;
	}
	return retorno;
}

/// @fn int myGets(char[], int)
/// @brief funcion para evaluar la validacion
///
/// @param cadena cadena que se ingresa por teclado
/// @param len tamaño/longitud de cadena
/// @return -1 error, 0 si pasa la validacion
int myGets(char cadena[], int len)
{
	int retorno = -1;

	if(cadena != NULL && len > 0 && fgets(cadena, len, stdin) == cadena)
	{
		retorno = 0;
	}
	return retorno;
}

/// @fn float utn_getFloat(char[], char[], float, float, int, float*)
/// @brief Verifica que sea un número flotante, devolviendo por referencia.
///
/// @param mensaje Mensaje para solicitar dato
/// @param mensajeError Mensaje de error si no pasa las validaciones
/// @param minimo valor minimo del rango a ingresar
/// @param maximo valor maximo del rango a ingresar
/// @param reintentos cantidad permitidas de oportunidades para ingreasr el valor
/// @param pResultado puntero a analizar.
/// @return Se inicia con -1 error, devuelve 0 si es exitosa.
float utn_getFloat(char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos, float *pResultado)
{
	int retorno = -1;
	float bufferFloat;
	int retorno_getFloat;

	if(mensaje != NULL && minimo < maximo && mensajeError != NULL && pResultado != NULL && reintentos > 0)
	{
		printf("\n%s",mensaje);
		retorno_getFloat = getFloat(&bufferFloat);
		do
		{
			if(retorno_getFloat == -1 || bufferFloat > maximo || bufferFloat < minimo)
			{
				printf("\n%s",mensajeError);
				retorno_getFloat = getFloat(&bufferFloat);
				reintentos--;
				printf("Quedan %d reintentos.\n",reintentos);
			}
			else
			{
				reintentos = 0;
				*pResultado = bufferFloat;
				retorno = 0;
			}
		}while(reintentos > 0);
	}
	return retorno;
}

/// @fn float getFloat(float*)
/// @brief Analiza si lo que si ingresa es un numero flotante
///
/// @param pFloatTomado puntero a analizar.
/// @return -1 si no es flotante, 0 si lo es.
float getFloat(float* pFloatTomado)
{
	int retorno = -1;
	char bufferString[200];

	if(myGets(bufferString, sizeof(bufferString)) == 0 && esFloat(bufferString) == 0)
	{
		*pFloatTomado= atof(bufferString);
		retorno = 0;
	}
	return retorno;
}

/// @fn float esFloat(char[])
/// @brief Verifica que sea flotante, contenga solamente 1 punto
///
/// @param cadena cadena a analizar.
/// @return -1 si hay más de 1 punto, 0 si pasa las validaciones
float esFloat(char cadena[])
{
	int retorno = 0; //favorable
	int i = 0;
	int contadorPuntos = 0;

	if(cadena[0]=='+' || cadena[0]=='-')
				{
					i++;
				}
	while(cadena[i]!='\0' || (cadena[i]>'9' && cadena[i]!='.')) //No hay nada menor a cero en ASCII?
	{
		i++;
		if(cadena[i]=='.')
		{
			contadorPuntos++;
		}
		if(contadorPuntos>1)
		{
			retorno = -1; //error
			puts("Error1 mas de un punto");
			break;
		}
	}
	return retorno;
}

/// @fn int esNumerica(char[])
/// @brief Analiza si tiene un número positivo y/o negativo
///
/// @param cadena cadena a analizar.
/// @return retorna -1 si no pasa las validaciones, 0 si las aprueba.
int esNumerica(char cadena[])
{
	int retorno = 0;
	int i;

	if(cadena != NULL)
	{
		i = 0;

		if(cadena[strlen(cadena)-1]=='\n')
		{
			cadena[strlen(cadena)-1]='\0'; //Porque toma el "enter" como �ltimo caracter.
		}
		if(cadena[0]=='-')
		{
			i++; // Para que empiece el while en 2da posici�n a chequear que sean todos n�meros (luego de pasar el signo menos)
		}
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = -1;
				break;
			}
			i++;
		}
	}
	else
	{
		retorno = -1 ;
	}
	return retorno;
}

/// @fn int utn_getOnlyString(char*, char*, int, int, char*)
/// @brief analiza que sea una cadena de caracteres, sin números. Incluye espacio.
///
/// @param mensaje Mensaje para solicitar dato
/// @param mensajeError Mensaje de error si no pasa las validaciones
/// @param reintentos cantidad permitidas de oportunidades para ingresar el valor
/// @param len tamaño de la cadena
/// @param pResultado puntero a analizar.
/// @return -1 si da error, 0 si es exitosa.
int utn_getOnlyString(char* mensaje, char* mensajeError, int reintentos,  int len, char* pResultado)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("\n%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 &&	strnlen(bufferString,sizeof(bufferString)) < len)
		{
			strncpy(pResultado,bufferString,len);
			retorno = 0;
			break;
		}
		printf("\n%s",mensajeError);
	}
	return retorno;
}

/// @fn int getNombre(char*, int)
/// @brief obtiene un nombre valido de string
///
/// @param pResultado puntero a analizar
/// @param len tamaño de la cadena
/// @return -1 si no pasa las validaciones, 0 si es un nombre string valido
int getNombre(char* pResultado, int len)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    			esNombre(buffer, sizeof(buffer)) &&
				strnlen(buffer,sizeof(buffer))<len)
    	{
    		strncpy(pResultado,buffer,len);
			retorno = 0;
		}
    }
    return retorno;
}

/// @fn int getString(char*, int)
/// @brief analiza que el string no supere el buffer
///
/// @param cadena puntero a analizar
/// @param len tamaño de la cadena
/// @return -1 si no pasa las validaciones y 0 si da ok.
int getString(char* cadena, int len)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && len > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= len)
			{
				strncpy(cadena,bufferString,len);
				retorno=0;
			}
		}
	}
	return retorno;
}

/// @fn int esNombre(char*, int)
/// @brief analiza si es una cadena de caracteres
///
/// @param cadena puntero a analizar
/// @param len tamaño de la cadena
/// @return 1 se inicia, 0 si es exitoso.
int esNombre(char* cadena,int len)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && len > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < len; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && cadena[i] != ' ')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


/// @fn int utn_getStringAndNum(char*, char*, int, int, char*)
/// @brief obtiene una cadena de caracteres que incluye numeros.
///
/// @param mensaje Mensaje para solicitar dato
/// @param mensajeError Mensaje de error si no pasa las validaciones
/// @param reintentos cantidad permitidas de oportunidades para ingresar el valor
/// @param len tamañan de la cadena
/// @param pResultado puntero a evaluar
/// @return -1 si no pasa las validaciones, 0 si es ok
int utn_getStringAndNum(char* mensaje, char* mensajeError, int reintentos,  int len, char* pResultado)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("\n%s",mensaje);
		if(getNombreAndNum(bufferString, sizeof(bufferString)) == 0 &&	strnlen(bufferString,sizeof(bufferString)) < len)
		{
			strncpy(pResultado,bufferString,len);
			retorno = 0;
			break;
		}
		printf("\n%s",mensajeError);
	}
	return retorno;
}


/// @fn int getNombreAndNum(char*, int)
/// @brief valida que sean cadena con numeros y no se pase del buffer
///
/// @param pResultado puntero a evaluar
/// @param len tamaño de la caden
/// @return -1 si no pas alas validaciones, 0 si esta todo ok.
int getNombreAndNum(char* pResultado, int len)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && strnlen(buffer,sizeof(buffer))<len)
    	{
    		strncpy(pResultado,buffer,len);
			retorno = 0;
		}
    }
    return retorno;
}

/// @fn int utn_getChar(char*, char*, int, char*)
/// @brief verifica que la cadena sea de letras
///
/// @param mensaje Mensaje para solicitar dato
/// @param mensajeError Mensaje de error si no pasa las validaciones
/// @param reintentos cantidad permitidas de oportunidades para ingresar el valor
/// @param pResultado puntero a analizar.
/// @return -1 si no pasa las validaciones, 0 si da ok.
int utn_getChar(char* mensaje, char* mensajeError, int reintentos, char* pResultado)
{
	char bufferString[128];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("\n%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 &&	strnlen(bufferString,sizeof(bufferString)) <= 1)
		{
			strncpy(pResultado,bufferString,1);
			retorno = 0;
			break;
		}
		printf("\n%s",mensajeError);
		printf("\nQuedan %d reintentos.",reintentos);
	}
	return retorno;
}

/// @fn int utn_getCharSinReint(char*, char*, char*)
/// @brief funcion getchar sin reintentos.
///
/// @param mensaje Mensaje para solicitar dato
/// @param mensajeError Mensaje de error si no pasa las validaciones
/// @param pResultado puntero a analizar
/// @return -1 si no pasa las validaciones, 0 si da ok.S
static int utn_getCharSinReint(char* mensaje, char* mensajeError, char* pResultado)
{
	char bufferString[128];
	int retorno = -1;

	printf("\n%s",mensaje);
	if(getNombre(bufferString,sizeof(bufferString)) == 0 &&	strnlen(bufferString,sizeof(bufferString)) <= 1)
	{
		strncpy(pResultado,bufferString,1);
		retorno = 0;
	}else{
	printf("\n%s",mensajeError);
	}

	return retorno;
}

int menu_confirmation(char mensaje[], char mensajeError[])
{
	int retorno = -1;
	char c;
	char bufferC;

	fflush(stdin);
	while (c != 'S' && c != 'N')
	{
		if(utn_getCharSinReint(mensaje, mensajeError, &bufferC)==0)
		{
			fflush(stdin);
			c=bufferC;
			c = toupper(c);
			//printf("ingresaste: %c\n", c);
		}
		else
		{
			printf("\n%s",mensajeError);
		}
	}

	if (c == 's')
	{
		retorno = 0;
	}

	return retorno;
}

