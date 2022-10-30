/*
 * Menu.c
 *
 *  Created on: 19 oct. 2022
 *      Author: Rojas Torrilla Lautaro
 */

#include "Menu.h"

/// @fn void MenuPrincipal()
/// @brief menu principal del programa
///
void MenuPrincipal()
{
	puts("\t**********************");
	puts("\t**       TP2        **");
	puts("\t**********************");
	puts("\t**  MENU PRINCIPAL  **");
	puts("\t**********************");
	puts("");
	puts(" 1.ALTA\n");
	puts(" 2.BAJA\n");
	puts(" 3.MODIFICACION\n");
	puts(" 4.INFORMES");
	MenuInformar();
	puts(" 5.SALIR\n");
}

/// @fn void MenuInformar()
/// @brief menu de informes del programa
///
void MenuInformar()
{
	puts("   1.LISTADO ORDENADO");
	puts("   2.LISTADO DE CONFEDERACIONES CON SUS JUGADORES");
	puts("   3.TOTAL Y PROMEDIO DE SALARIOS Y CUANTOS COBRAN MAS DEL PROMEDIO");
	puts("   4.CONFEDERACION CON MAYOR CANTIDAD DE AÑOS DE CONTRATOS TOTAL");
	puts("   5.PORCENTAJE DE JUGADORES POR CADA CONFEDERACION");
	puts("   6.REGION CON MAS JUGADORES Y LISTADO DE ELLOS");
	puts("   7.SALIR\n");
}

/// @fn void MenuModificar()
/// @brief menu para modificar en el programa
///
void MenuModificar()
{
	puts(" 1.NOMBRE\n");
	puts(" 2.POSICION\n");
	puts(" 3.NUMERO CAMISETA\n");
	puts(" 4.ID CONFEDERACION\n");
	puts(" 5.SALARIO\n");
	puts(" 6.ANIOS CONTRATO\n");
	puts(" 7.SALIR\n");
}

/// @fn void MenuPosicion()
/// @brief menu para seleccionar la posicion del jugador
///
void MenuPosicion()
{
	puts(" 1.ARQUERO\n");
	puts(" 2.DEFENSOR\n");
	puts(" 3.MEDIOCAMPISTA\n");
	puts(" 4.DELANTERO\n");
}
