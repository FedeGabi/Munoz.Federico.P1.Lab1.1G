#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "marca.h"
#include "color.h"
typedef struct{
    int id;
    int idMarca;
    int idColor;
    char caja;
    int isEmpty;
}eAuto;
int inicializarAutos(eAuto vec[], int tam);
int bajaAuto(eAuto autos[], eMarca marcas[], eColor colores[], int tamAutos, int tamMarcas, int tamColores);
int validarAutosId(eAuto vec[], int tamAutos, int id);
int buscarAutoId(eAuto vec[], int tam, int id, int* indice);

int buscarPrimerVacio(eAuto vec[], int tam);

int buscarLleno(eAuto autos[], int tamAutos);

int menuIngresarAuto(eAuto vec[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores);

int altaAuto(eAuto vec[], int tam, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores,  int* pIdNext);

int listarAutos(eAuto autos[], eMarca marcas[], eColor colores[], int tam, int tamMarcas, int tamColores);

void mostrarAuto(eAuto autos, eMarca empresa[], eColor tipo[], int tamMarcas, int tamColores);

#endif // AUTO_H_INCLUDED
