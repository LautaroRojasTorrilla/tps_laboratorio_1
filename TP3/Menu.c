#include "Menu.h"

void MenuPrincipal()
{
	puts("\t**********************");
	puts("\t**       TP3        **");
	puts("\t**********************");
	puts("\t**  MENU PRINCIPAL  **");
	puts("\t**********************");
	puts("");
	puts(" 1.CARGA DE ARCHIVOS\n");
	puts(" 2.ALTA\n");
	puts(" 3.MODIFICACION\n");
	puts(" 4.BAJA\n");
	puts(" 5.LISTADO\n");
	MenuListado();
	puts(" 6.CONVOCAR JUGADORES\n");
	puts(" 7.ORDENAR Y LISTAR\n");
	MenuOrdenar();
	puts(" 8.GENERAR ARCHIVO BINARIO\n");
	puts(" 9.CARGAR ARCHIVO BINARIO\n");
	puts(" 10.GUARDAR ARCHIVOS .CSV\n");
	puts("11.SALIR\n");
}

void MenuListado()
{
	puts("   A.LISTADO DE TODOS LOS JUGADORES");
	puts("   B.LISTADO DE TODAS LAS SELECCIONES");
	puts("   C.LISTADO DE JUGADORES CONVOCADOS");
	puts("   S.SALIR\n");
}

void MenuConvocar()
{
	puts("   A.CONVOCAR");
	puts("   B.QUITAR DE SELECCION");
	puts("   S.SALIR\n");
}

void MenuOrdenar()
{
	puts("   A.JUGADORES POR NACIONALIDAD.");
	puts("   B.SELECCIONES POR CONFEDERACIÓN.");
	puts("   C.JUGADORES POR EDAD.");
	puts("   D.JUGADORES POR NOMBRE.");
	puts("   S.SALIR\n");
}

void MenuConfed()
{
	puts("AFC\n");
	puts("CAF\n");
	puts("CONCACAF\n");
	puts("CONMEBOL\n");
	puts("UEFA\n");
}
