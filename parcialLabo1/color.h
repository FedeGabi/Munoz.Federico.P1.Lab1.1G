#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int id;
    char nombreColor[20];
}eColor;

int menuIngresarColor(eColor vec[], int tamColores);

int buscarColorId(eColor vec[], int tamColores, int id, int* pIndice);

int cargarDescripcionColor(eColor colores[], char descripcion[], int id, int tamColores);

int listarColores(eColor Colors[],int tamColores);

void mostrarColor(eColor color);


#endif // COLOR_H_INCLUDED
