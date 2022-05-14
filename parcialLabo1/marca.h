#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int id;
    char descripcion[20];
}eMarca;


int menuIngresarMarca(eMarca vec[], int tamMarcas);


int buscarMarcaId(eMarca vec[], int tamMarcas, int id, int* pIndice);

int validarMarcaId(eMarca vec[], int tamMarcas, int id);
int cargarDescripcionMarca(eMarca marcas[], char descripcion[], int id, int tamMarcas);

int listarMarcas(eMarca marcas[],int tamMarcas);

void mostrarMarca(eMarca marca);
#endif // MARCA_H_INCLUDED
