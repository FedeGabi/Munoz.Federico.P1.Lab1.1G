#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "input.h"
#include "auto.h"
#include "color.h"
#include "servicio.h"
typedef struct{
    int id;
    int idAuto;
    int idServicio;
    eFecha fechaTrabajo;
    int isEmpty;
}eTrabajo;

int inicializarTrabajos(eTrabajo vec[], int tam);

int altaTrabajo(eTrabajo vec[], int tam, eAuto autos[], int tamAutos, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarcas, eColor colores[], int tamColor,  int* pIdNext);

int buscarTrabajoId(eTrabajo vec[], int tam, int id, int* pIndice);

int buscarPrimerTrabajoVacio(eTrabajo vec[], int tamVia);

int listarTrabajos( eTrabajo trabajos[], eServicio servicios[], int tamVia, int tamServ);

void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamServ);


#endif // TRABAJO_H_INCLUDED
