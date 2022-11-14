#include "Jugador.h"

Jugador* jug_new()
{
	Jugador* pJugador;

	pJugador = (Jugador*) calloc(sizeof(Jugador), 1);

	return pJugador;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* pJugador;

	if(idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSelccionStr != NULL)
	{
		//creo de manera dinamica.
		pJugador = jug_new();

		if(pJugador != NULL)
		{
			if(jug_setId(pJugador, atoi(idStr)) == -1
					|| jug_setNombreCompleto(pJugador, nombreCompletoStr) == -1
					|| jug_setEdad(pJugador, atoi(edadStr)) == -1
					|| jug_setPosicion(pJugador, posicionStr) == -1
					|| jug_setNacionalidad(pJugador, nacionalidadStr) == -1
					|| jug_setIdSeleccion(pJugador, atoi(idSelccionStr)) == -1)
			{
				jug_delete(pJugador);
				pJugador = NULL;
			}
		}
	}

	return pJugador;
}

void jug_delete(Jugador* jugador)
{
	if(jugador != NULL)
	{
		free(jugador);
	}
}

int jug_setId(Jugador* this, int id)
{
	int retorno = -1;

	if(this != NULL && id >= 0 )
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int jug_getId(Jugador* this, int* id)
{
	int retorno = -1;

	if(this != NULL && id >=0 )
	{
		*id=this->id;
		retorno = 0;
	}

	return retorno;
}

int jug_getIdTXT(Jugador* this, char* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL )
	{
		sprintf(id,"%d",this->id);
		retorno = 0;
	}

	return retorno;
}

int jug_setNombreCompleto(Jugador* this, char* nombreCompleto)
{
	int retorno = -1;

	if(this != NULL && nombreCompleto != NULL)
	{
		strncpy(this->nombreCompleto, nombreCompleto, MAX_NOMBRE);
		retorno = 0;
	}

	return retorno;
}

int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = -1;

	if(this != NULL && nombreCompleto != NULL )
	{
		strncpy(nombreCompleto, this->nombreCompleto, MAX_POSYNAC);
		retorno = 0;
	}

	return retorno;
}

int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno = -1;

	if(this != NULL && posicion != NULL)
	{
		strncpy(this->posicion, posicion, MAX_POSYNAC);
		retorno = 0;
	}

	return retorno;
}

int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno = -1;

	if(this != NULL && posicion != NULL )
	{
		strncpy(posicion, this->posicion, MAX_POSYNAC);
		retorno = 0;
	}

	return retorno;
}

int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;

	if(this != NULL && nacionalidad != NULL)
	{
		strncpy(this->nacionalidad, nacionalidad, MAX_POSYNAC);
		retorno = 0;
	}

	return retorno;
}

int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;

	if(this != NULL && nacionalidad != NULL )
	{
		strncpy(nacionalidad, this->nacionalidad, MAX_POSYNAC);
		retorno = 0;
	}

	return retorno;
}

int jug_setEdad(Jugador* this,int edad)
{
	int retorno = -1;

	if (this != NULL && edad >= 0 )
	{
		this->edad = edad;
		retorno = 0;
	}

	return retorno;
}

int jug_getEdad(Jugador* this,int* edad)
{
	int retorno = -1;

	if(this != NULL && edad != NULL )
	{
		*edad = this->edad;
		retorno = 0;
	}

	return retorno;
}

int jug_getEdadTXT(Jugador* this,char* edad)
{
	int retorno = -1;

	if(this != NULL && edad != NULL )
	{
		sprintf(edad,"%d",this->edad);
		retorno = 0;
	}

	return retorno;
}

int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno = -1;

	if (this != NULL && idSeleccion >= 0 )
	{
		this->idSeleccion = idSeleccion;
		retorno = 0;
	}

	return retorno;
}

int jug_getSIdSeleccion(Jugador* this, int* idSeleccion)
{
	int retorno = -1;

	if(this != NULL && idSeleccion != NULL )
	{
		*idSeleccion = this->idSeleccion;
		retorno = 0;
	}

	return retorno;
}

int jug_getSIdSeleccionTXT(Jugador* this,char* idSeleccion)
{
	int retorno = -1;

	if(this != NULL && idSeleccion != NULL )
	{
		sprintf(idSeleccion,"%d",this->idSeleccion);
		retorno = 0;
	}

	return retorno;
}

//int jug_setIsEmpty(Jugador* this,int isEmpty)
//{
//	int retorno = -1;
//
//	if (this != NULL && isEmpty >= 0 )
//	{
//		this->isEmpty = isEmpty;
//		retorno = 0;
//	}
//
//	return retorno;
//}
//int jug_getIsEmpty(Jugador* this,int* isEmpty)
//{
//	int retorno = -1;
//
//	if(this != NULL && isEmpty != NULL )
//	{
//		*isEmpty = this->isEmpty;
//		retorno = 0;
//	}
//
//	return retorno;
//}

void jug_printOne(Jugador* jug)
{
	int id;
	char nombreCompleto[MAX_NOMBRE];
	int edad;
	char posicion[MAX_POSYNAC];
	char nacionalidad[MAX_POSYNAC];
	int idSeleccion;

	jug_getId(jug, &id);
	jug_getNombreCompleto(jug, nombreCompleto);
	jug_getEdad(jug, &edad);
	jug_getPosicion(jug, posicion);
	jug_getNacionalidad(jug, nacionalidad);
	jug_getSIdSeleccion(jug, &idSeleccion);


	printf("|%2d|%-29s|%2d|%-29s |%-29s|%2d\n",
			id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
}

int jug_printOneFile(FILE* archivo, Jugador* jugador)
{
	int retorno = -1;

	char id[10];
	char nombreCompleto[MAX_NOMBRE];
	char edad[10];
	char posicion[MAX_POSYNAC];
	char nacionalidad[MAX_POSYNAC];
	char idSeleccion[10];

	//int auxTipo;

	if (archivo != NULL && jugador != NULL)
	{
		if(!(jug_getIdTXT(jugador, id)) &&
				!(jug_getNombreCompleto(jugador, nombreCompleto)) &&
				!(jug_getEdadTXT(jugador, edad)) &&
				!(jug_getPosicion(jugador, posicion)) &&
				!(jug_getNacionalidad(jugador, nacionalidad)) &&
				!(jug_getSIdSeleccionTXT(jugador, idSeleccion)))
		{
			fprintf(archivo,"%s,%s,%s,%s,%s,%s\n",id, nombreCompleto,edad,
					posicion, nacionalidad, idSeleccion);
		}
		retorno = 0;
	}
	return retorno;
}

int jug_sortByNacionalidad(void* jugador1, void* jugador2)
{
	int retorno = 0;

	char nacionalidad1[MAX_POSYNAC];
	char nacionalidad2[MAX_POSYNAC];

	Jugador* jug1;
	Jugador* jug2;

	jug1 = (Jugador*) jugador1;
	jug2 = (Jugador*) jugador2;

	if(!jug_getNacionalidad(jug1, nacionalidad1) && !jug_getNacionalidad(jug2, nacionalidad2))
	{
		if(strncmp(nacionalidad1, nacionalidad2, MAX_POSYNAC) > 0)
		{
			retorno = -1;
		}
		else
		{
			retorno = 1;
		}
	}

	return retorno;
}

int jug_sortByEdad(void* jugador1, void* jugador2)
{
	int retorno = 0;

	int edad1;
	int edad2;

	Jugador* jug1;
	Jugador* jug2;

	jug1 = (Jugador*) jugador1;
	jug2 = (Jugador*) jugador2;

	if(!jug_getEdad(jug1, &edad1) && !jug_getEdad(jug2, &edad2))
	{
		if(edad1 > edad2)
		{
			retorno = -1;
		}
		else
		{
			retorno = 1;
		}
	}

	return retorno;
}

int jug_sortByNombre(void* jugador1, void* jugador2)
{
	int retorno = 0;

	char nombreCompleto1[MAX_NOMBRE];
	char nombreCompleto2[MAX_NOMBRE];

	Jugador* jug1;
	Jugador* jug2;

	jug1 = (Jugador*) jugador1;
	jug2 = (Jugador*) jugador2;

	if(!jug_getNombreCompleto(jug1, nombreCompleto1) && !jug_getNombreCompleto(jug2, nombreCompleto2))
	{
		if(strncmp(nombreCompleto1, nombreCompleto2, MAX_NOMBRE) > 0)
		{
			retorno = -1;
		}
		else
		{
			retorno = 1;
		}
	}

	return retorno;
}

