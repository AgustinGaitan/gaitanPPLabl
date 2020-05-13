#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "autos.h"
#include "menu.h"


int inicializarAutos(eAutos lista[], int tamAutos)
{
    int todoOk = -1;

            for(int i = 0; i < tamAutos; i++)
            {
                lista[i].isEmpty = 1;

                todoOk = 0;

            }

    return todoOk;
}




void altaAutos(eAutos* lista, int id, char patente[], int idMarca, int idColor,  int modelo, int tamAutos)
{
    eAutos auxAutos;

            for(int i = 0; i < tamAutos; i++)
            {

                if(lista[i].isEmpty)
                {
                    auxAutos.id = id;
                    strcpy(auxAutos.patente, patente);
                    auxAutos.modelo = modelo;
                    auxAutos.idColor = idColor;
                    auxAutos.idMarca = idMarca;
                    lista[i].isEmpty = 0;
                    lista[i] = auxAutos;
                    break;

                }


            }

}



void modificarAuto(eAutos* lista, eColor* color, char patente[], int tamAutos)
{

    char opcionSalir;
    eColor auxColor;
    eAutos auxAutos;


            printf("**** Modificacion de auto****\n\n");



            for(int i = 0; i < tamAutos; i++)
            {

                if(strcmp(lista[i].patente,patente) == 0)
                {

                    do
                    {
                           switch(menuModificarAuto())
                        {
                        case 1:
                            printf("Ingrese el nuevo color: ");
                            scanf("%s", auxColor.nombreColor);
                            break;
                        case 2:
                            printf("Ingrese el nuevo modelo: ");
                            scanf("%d", &auxAutos.modelo);
                            break;
                        case 3:
                            printf("Quiere salir? 's' para salir 'n' para quedarse: ");
                            fflush(stdin);
                            scanf("%c", &opcionSalir);
                            break;
                        }


                    }while(opcionSalir != 's');
                   strcpy(color[i].nombreColor, auxColor.nombreColor);
                   lista[i].modelo = auxAutos.modelo;
                   break;
                }
                else
                {
                    printf("No se encontro la patente buscada");
                    break;

                }

            }
        system("pause");





}



void bajaAuto(eAutos* lista, char patente[],int tamAutos)
{
    for(int i = 0; i < tamAutos; i++)
    {
        if(strcmp(lista[i].patente, patente) == 0)
        {
            lista[i].isEmpty = 1;
            break;
        }

    }
}


void mostrarAuto(eAutos* lista, eMarca* x, int tamAutos)
{

    printf("**** Listado de autos ****\n\n");
    printf(" Id                      Marca            Patente     \n\n");

    for(int i = 0; i < tamAutos; i++)
    {
        printf("%d     %10s         %10s  \n", lista[i].id, x[i].descripcion, lista[i].patente);
    }
    system("pause");
}


void ordenarAutos(eAutos* lista, int tamAutos)
{
    eAutos aux;

            for(int i = 0; i < tamAutos-1; i++)
            {
                for(int j = i + 1; j < tamAutos; i++)
                {

                    if(lista[i].idMarca > lista[j].idMarca)
						{
								aux = lista[i];
								lista[i] = lista[j];
								lista[j] = aux;
						}
                    else if(lista[i].idMarca == lista[j].idMarca  && (strcmp(lista[i].patente, lista[j].patente) > 0))
						{
								aux = lista[i];
								lista[i] = lista[j];
								lista[j] = aux;

						}




                }
            }

}

void listarMarcas(eMarca* lista, int tamMarcas)
{
    printf("**** Listado de Marcas ****\n\n");
    printf(" Id          Descripcion    \n\n");

    for(int i = 0; i < tamMarcas; i++)
    {
        printf("%d     %10s     \n", lista[i].id, lista[i].descripcion);
    }
    system("pause");
}


void listarColores(eColor* lista, int tamColor)
{
    printf("**** Listado de Colores ****\n\n");
    printf(" Id          Descripcion    \n\n");

    for(int i = 0; i < tamColor; i++)
    {
        printf("%d     %10s     \n", lista[i].id , lista[i].nombreColor);
    }
    system("pause");
}

void listarServicios(eServicio* lista, int tamServicio)
{
     printf("**** Listado de servicios ****\n\n");
    printf(" Id          Descripcion     Precio  \n\n");

    for(int i = 0; i < tamServicio; i++)
    {
        printf("%d     %10s        %2.f \n", lista[i].id , lista[i].descripcion, lista[i].precio);
    }
    system("pause");
}


void altaTrabajo(eTrabajo* lista, eAutos* listaAutos, eServicio* listaServicio, int idAuto, int idServicio, int tamTrabajo)
{



    for(int i = 0; i < tamTrabajo; i++)
    {
        if(lista[i].idServicio == idServicio && listaAutos[i].id == idAuto)
        {
            printf("El servicio que eligio fue: %s", listaServicio[i].descripcion);
            printf("El auto que eligio fue : %s", listaAutos[i].patente);
            lista[i].idServicio = idServicio;
            strcpy(lista[i].patente, listaAutos[i].patente);

        }
    }

}

void listarTrabajo(eTrabajo* lista, eServicio* listaServicio,int tamTrabajo)
{
    printf("**** Listado de trabajos ****\n\n");
    printf(" Servicio      Patente \n\n");
    for(int i = 0; i < tamTrabajo; i++)
    {
        printf("%s      %s \n", listaServicio[i].descripcion, lista[i].patente );
    }
    system("pause");
}
