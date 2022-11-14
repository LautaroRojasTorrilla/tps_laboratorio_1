#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Jugador.h"


#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
	//int isEmpty;
}Seleccion;

Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
void selec_delete(Seleccion* jugador);

int selec_setId(Seleccion* this,int id);
int selec_getId(Seleccion* this,int* id);

int selec_setPais(Seleccion* this,char* pais);
int selec_getPais(Seleccion* this,char* pais);

int selec_setConfederacion(Seleccion* this,char* confederacion);
int selec_getConfederacion(Seleccion* this,char* confederacion);
//int selec_getIsEmpty(Seleccion* this,int* isEmpty);

int selec_setConvocados(Seleccion* this,int convocados);
int selec_getConvocados(Seleccion* this,int* convocados);

void selec_printOne(Seleccion* sel);

int selec_sortByConfed(void* seleccion1, void* seleccion2);


#endif // selec_H_INCLUDED
