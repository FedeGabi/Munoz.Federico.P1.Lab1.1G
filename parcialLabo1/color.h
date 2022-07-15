#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
typedef struct{
    int id;
    char descripcion[20];
}eColor;
int menuIngresarColor(int* id);
int cargarDescripcionColorId(eColor listaColores[], int tamColores,int id, char descripcion[]);
int hardcodearColores(eColor listaColores[], int tamColores);
int cargarDescripcionColorId(eColor listaColores[], int tamColores,int id, char descripcion[]);

#endif // COLOR_H_INCLUDED
