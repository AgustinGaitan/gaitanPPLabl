#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED

typedef struct
{
    int id;
    char patente[5];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;

}eAutos;

typedef struct
{
    int id;
    char descripcion[20];

}eMarca;

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int id;
    char nombreColor[20];

}eColor;

typedef struct
{
    int id;
    char descripcion[25];
    float precio;

}eServicio;

typedef struct
{
    int id;
    char patente[5];
    int idServicio;
    int fecha;

}eTrabajo;



#endif // AUTOS_H_INCLUDED



int inicializarAutos(eAutos* lista, int tamAutos);


void altaAutos(eAutos* lista, int id, char patente[], int idMarca, int idColor,  int modelo, int tamAutos);



void modificarAuto(eAutos* lista, eColor color[], char patente[], int tamAutos);


void bajaAuto(eAutos* lista, char patente[],int tamAutos);

void mostrarAuto(eAutos* lista,eMarca x[], int tamAutos);

void ordenarAutos(eAutos* lista, int tamAutos);

void listarMarcas(eMarca* lista, int tamMarcas);

void listarColores(eColor* lista, int tamColor);

void listarServicios(eServicio* lista, int tamServicio);

void altaTrabajo(eTrabajo* lista, eAutos* listaAutos, eServicio* listaServicio, int idAuto, int idServicio, int tamTrabajo);

void listarTrabajo(eTrabajo* lista, eServicio*  listaServicio,int tamTrabajo);
