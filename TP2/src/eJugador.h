/*
 * eJugador.h
 *
 *  Created on: 19 oct. 2022
 *      Author: Rojas Torrilla Lautaro
 */

#ifndef EJUGADOR_H_
#define EJUGADOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "eConfederacion.h"
#include "Menu.h"

typedef struct{
    int id;
    char nombre[MAX_CHAR];
    char posicion[MAX_CHAR];
    short numeroCamiseta;
    int idConfederacion;
    float salario;
    short aniosContrato;
    short isEmpty;
}eJugador;


void eJugador_printOne(eJugador jug);
int eJugador_printAll(eJugador arrayJugador[], int len, int state);
int eJugador_printConConf(eJugador arrayJugador[], eConfederacion arrayConf[], int lenI, int lenJ, short state);
int eJugador_printJugPorConf(eJugador arrayJugador[], eConfederacion arrayConf[], int lenI, int lenJ, int idConf, short state);

eJugador eJugadorLoadOne();
short eJugador_initArray(eJugador arrayJugador[], int len);
short eJugador_SearchEmpty(eJugador arrayJugador[], int len);
short eJugador_SearchOcupado(eJugador arrayJugador[], int len);
int eJugador_SearchIndexByID(eJugador arrayJugador[], int len, int id);
short eJugador_Charge(eJugador arrayJugador[], int len);
short eJugador_Discharge(eJugador arrayJugador[], int len);
int eJugador_Modify(eJugador arrayJugador[], int len);
int eJugador_SortByConf(eJugador arrayJugador[], eConfederacion arrayConf[], int len, int orden);
int eJugador_SortByConfyNombre(eJugador arrayJugador[], eConfederacion arrayConf[], int len, int orden);

//int eJugador_AcumAniosCont(eJugador arrayJugador[], int len, short *acum);//acumulador individual
int eJugador_AcumAniosContByConf(eJugador arrayJugador[], eConfederacion arrayConf[], int len1, int len2, short acum[]);
//en cada posicion de ese array guada un valor que va a cambiar a medida que se levayan pasando los jugadores




#endif /* EJUGADOR_H_ */
