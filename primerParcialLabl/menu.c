#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "autos.h"
#include "menu.h"




char menuPrincipal()
{
    char opcion;


    printf("A. Dar de alta a un auto.\n");
    printf("B. Modificar auto.\n");
    printf("C. Dar de baja a un auto.\n");
    printf("D. Listar autos.\n");
    printf("E. Listar marcas.\n");
    printf("F. Listar colores.\n");
    printf("G. Listar servicios.\n");
    printf("H. Dar de alta trabajo.\n");
    printf("I. Listar trabajos.\n");

    printf("Ingrese la opcion que desea: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;


}


int menuModificarAuto()
{
    int opcion;

    printf("\n\nQue desea modificar?:\n");
    printf("1. Color\n");
    printf("2.Modelo\n");
    printf("3.Ya modifique lo que queria/No quiero modificar nada\n");
    printf("Ingrese la opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
