#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "autos.h"
#include "menu.h"


#define TAMAUTOS 5
#define TAMMARCAS 5
#define TAMCOLORES 5
#define TAMSERV 10
#define TAMTRA 10

int main()
{

    eAutos listaAutos[50];
    eTrabajo listaTrabajos[50];
    eMarca listaMarcas[5] = {{1000,"Renault"}, {1001, "Fiat"}, {1002, "Ford"}, {1003, "Chevrolet"}, {1004, "Peugeot"}};
    eColor listaColores[6] = {{5000,"Negro"}, {5001,"Blanco"}, {5002, "Gris"}, {5003, "Gris"}, {5004, "Rojo"}, {5005, "Azul"}};
    eServicio listaServicios[4] = {{20000,"Lavado",250}, {20001, "Pulido", 300} , {20003, "Encerado", 400}, {20004, "Completo", 600}};
    int id;
    char patente[6];
    int idAuto = 0;
    int idServicio = 19999;
    int idMarca =  999;
    int idColor = 4999;
    int modelo;
    char opcion;

    do
    {
        switch(menuPrincipal())
        {
            case 'A':
                system("cls");
                printf("****Alta de autos****\n");
                printf("Ingrese el id del auto: ");
                scanf("%d", &id);
                printf("Ingrese la patente del auto: ");
                fflush(stdin);
                gets(patente);
                printf("Ingrese el id de marca ( mayor a 1000): ");
                scanf("%d", &idMarca);
                printf("Ingrese el id del color ( mayor a 5000): ");
                scanf("%d", &idColor);
                printf("Ingrese el modelo: ");
                scanf("%d", &modelo);

                altaAutos(listaAutos,id,patente,idMarca,idColor,modelo,TAMAUTOS);
                break;


            case 'B':
                printf("Ingrese la patente del auto que desea modificar: ");
                scanf("%s", patente);
                modificarAuto(listaAutos,listaColores,patente,TAMAUTOS);
                break;

            case 'C':
                printf("Ingrese la patente del auto que desea dar de baja: ");
                scanf("%s", patente);
                bajaAuto(listaAutos,patente,TAMAUTOS);
                break;

            case 'D':
                mostrarAuto(listaAutos,listaMarcas,TAMAUTOS);
                 break;
            case 'E':
                listarMarcas(listaMarcas,TAMMARCAS);
                 break;
            case 'F':
                listarColores(listaColores,TAMCOLORES);
                 break;
            case 'G':
                listarServicios(listaServicios,TAMSERV);
                 break;
            case 'H':
                system("cls");
                printf("**** Alta de trabajo ****\n\n");
                printf("Ingrese un id de auto: ");
                scanf("%d", &idAuto);
                printf("Ingrese un id de servicio: ");
                scanf("%d", &idServicio);
                altaTrabajo(listaTrabajos,listaAutos,listaServicios,idAuto,idServicio,TAMTRA);
                 break;
            case 'I':
                listarTrabajo(listaTrabajos,listaServicios,TAMTRA);
                 break;
            case 'J':
                printf("Desea salir? 's' para salir, 'n' para quedarse");
                fflush(stdin);
                scanf("%c", &opcion);

        }
        system("cls");



    }while(opcion != 's');






    return 0;
}
