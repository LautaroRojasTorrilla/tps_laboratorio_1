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

void MenuPosiciones()
{
	puts("\n");
	puts(" 1.Portero\n");
	puts(" 2.Defensa central\n");
	puts(" 3.Lateral izquierdo\n");
	puts(" 4.Lateral derecho\n");
	puts(" 5.Pivote\n");
	puts(" 6.Interior derecho\n");
	puts(" 7.Interior izquierdo\n");
	puts(" 8.Mediocentro\n");
	puts(" 9.Mediocentro ofensivo\n");
	puts(" 10.Mediapunta\n");
	puts(" 11.Extremo derecho\n");
	puts(" 12.Extremo izquierdo\n");
	puts(" 13.Delantero Centro\n");
}
