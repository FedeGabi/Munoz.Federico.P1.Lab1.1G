#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"
#include "auto.h"
#include "servicio.h"

typedef struct{
    int id;
    int idAuto;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

int altaTrabajo(eTrabajo listaTrabajos[], eServicio listaServicios[], eAuto listaAutos[], eColor listaColores[], eMarca listaMarcas[], eCliente listaClientes[], int tamTrabajos, int tamServicios, int tamAutos, int tamColores, int tamMarcas, int tamClientes, int* idNextTrabajo);
void mostrarTrabajo(eTrabajo trabajo, eServicio listaServicios[], int tamTrabajos, int tamServicios);
int hardcodearTrabajos(eTrabajo listaTrabajos[],eAuto listaAutos[], int tamTrabajos, int tamAutos, int cant, int* nextId);
int inicializarListaTrabajos(eTrabajo listaTrabajos[], int tamTrabajos);
int isNotEmptyTrabajo( eTrabajo listaTrabajos[], int tamTrabajos);
int listarTrabajos(eTrabajo listaTrabajos[], eServicio listaServicios[], int tamTrabajos, int tamServicios);
#endif // TRABAJO_H_INCLUDED
