/*
 * eConfederacion.h
 *
 *  Created on: 19 oct. 2022
 *      Author: soporte
 */

#ifndef ECONFEDERACION_H_
#define ECONFEDERACION_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "Input.h"

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

#define MAX_CHAR 50
#define MAX_CONF 6
#define MAX_CMST 22
#define MAX_SAL 10000
#define MAX_CONT 10
#define MAX_JUG 11

typedef struct{
    int id;
    char nombre[MAX_CHAR];
    char region[MAX_CHAR];
    int aniocreacion;
    short isEmpty;
}eConfederacion;

void eConfederacion_printOne(eConfederacion conf);
int eConfederacion_printAll(eConfederacion arrayConf[], int len);
eConfederacion eConfederacionLoadOne();
int eConfederacion_Relacion(eConfederacion arrayConf[], char bufferNombre[], int idConf, int len);

short eConfederacion_initArray(eConfederacion arrayConf[], int len);
short eConfederacion_SearchEmpty(eConfederacion arrayConf[], int len);
short eConfederacion_SearchOcupado(eConfederacion arrayConf[], int len);
int eConfederacion_SearchIndexByID(eConfederacion arrayConf[], int len, int id);
short eConfederacion_Charge(eConfederacion arrayConf[], int len);
short eConfederacion_Discharge(eConfederacion arrayConf[], int len);
int eConfederacion_Modify(eConfederacion arrayConf[], int len);


#endif /* ECONFEDERACION_H_ */
