#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"
#include "Seleccion.h"
#include "Controller.h"


#define MAX_NOMBRE 100
#define MAX_POSYNAC 30

typedef struct
{
	int id;
	char nombreCompleto[MAX_NOMBRE];
	int edad;
	char posicion[MAX_POSYNAC];
	char nacionalidad[MAX_POSYNAC];
	int idSeleccion;
	//int isEmpty;
}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

void jug_delete(Jugador* jugador);

int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);
//le doy el formato para el txt
int jug_getIdTXT(Jugador* this, char* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);
int jug_getEdadTXT(Jugador* this,char* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);
int jug_getSIdSeleccionTXT(Jugador* this,char* idSeleccion);

int jug_setIsEmpty(Jugador* this,int isEmpty);
int jug_getIsEmpty(Jugador* this,int* isEmpty);

void jug_printOne(Jugador* jug);
int jug_printOneFile(FILE* archivo, Jugador* jugador);

int jug_sortByNacionalidad(void* jugador1, void* jugador2);
int jug_sortByEdad(void* jugador1, void* jugador2);
int jug_sortByNombre(void* jugador1, void* jugador2);

#endif // jug_H_INCLUDED
