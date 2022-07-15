#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"

typedef struct{
    int id;
    char descripcion[20];
}eMarca;
int menuIngresarMarca(int* id);
int cargarDescripcionMarcaId(eMarca listaMarcas[], int tamMarcas,int id, char descripcion[]);
int hardcodearMarcas(eMarca listaMarcas[], int tamMarcas);

#endif // MARCA_H_INCLUDED
