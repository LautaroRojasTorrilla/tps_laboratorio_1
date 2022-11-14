#include "Seleccion.h"

Seleccion* selec_new()
{
	Seleccion* pSeleccion;

	pSeleccion = (Seleccion*) malloc(sizeof(Seleccion));

	return pSeleccion;
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* pSeleccion;

	if(idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr)
	{
		//creo de manera dinamica.
		pSeleccion = selec_new();

		if(pSeleccion != NULL)
		{
			if(selec_setId(pSeleccion, atoi(idStr)) == -1
					|| selec_setPais(pSeleccion, paisStr) == -1
					|| selec_setConfederacion(pSeleccion, confederacionStr) == -1
					|| selec_setConvocados(pSeleccion, atoi(convocadosStr)) == -1)
			{
				selec_delete(pSeleccion);
				pSeleccion = NULL;
			}
		}
	}

	return pSeleccion;
}

void selec_delete(Seleccion* seleccion)
{
	if(seleccion != NULL)
	{
		free(seleccion);
	}
}

int selec_setId(Seleccion* this,int id)
{
	int retorno = -1;

	if(this != NULL && id >= 0 )
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int selec_getId(Seleccion* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id >=0 )
	{
		*id=this->id;
		retorno = 0;
	}

	return retorno;
}

int selec_setPais(Seleccion* this,char* pais)
{
	int retorno = -1;

	if(this != NULL && pais != NULL)
	{
		strncpy(this->pais, pais, 30);
		retorno = 0;
	}

	return retorno;
}

int selec_getPais(Seleccion* this,char* pais)
{
	int retorno = -1;

	if(this != NULL && pais != NULL )
	{
		strncpy(pais, this->pais, 30);
		retorno = 0;
	}

	return retorno;
}

int selec_setConfederacion(Seleccion* this,char* confederacion)
{
	int retorno = -1;

	if(this != NULL && confederacion != NULL)
	{
		strncpy(this->confederacion, confederacion, 30);
		retorno = 0;
	}

	return retorno;
}

int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno = -1;

	if(this != NULL && confederacion != NULL )
	{
		strncpy(confederacion, this->confederacion, 30);
		retorno = 0;
	}

	return retorno;
}

int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno = -1;

	if(this != NULL && convocados >= 0 )
	{
		this->convocados = convocados;
		retorno = 0;
	}

	return retorno;
}

int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno = -1;

	if(this != NULL && convocados >=0 )
	{
		*convocados=this->convocados;
		retorno = 0;
	}

	return retorno;
}

void selec_printOne(Seleccion* sel)
{

	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

	selec_getId(sel, &id);
	selec_getPais(sel, pais);
	selec_getConfederacion(sel, confederacion);
	selec_getConvocados(sel, &convocados);


	printf("|%2d|%-29s|%-29s|%2d\n",
			id, pais, confederacion, convocados);
}

int selec_sortByConfed(void* seleccion1, void* seleccion2)
{
	int retorno = 0;

	char confederacion1[30];
	char confederacion2[30];

	Seleccion* sel1;
	Seleccion* sel2;

	sel1 = (Seleccion*) seleccion1;
	sel2 = (Seleccion*) seleccion2;

	if(!selec_getConfederacion(sel1, confederacion1) && !selec_getConfederacion(sel2, confederacion2))
	{
		if(strncmp(confederacion1, confederacion2, 30) > 0)
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
