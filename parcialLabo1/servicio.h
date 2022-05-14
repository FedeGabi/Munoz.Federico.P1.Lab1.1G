#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int id;
    char descripcion[25];
    float precio;
}eServicio;


int menuIngresarServicio(eServicio vec[], int tamServ);
int cargarDescripcionServicio(eServicio servicios[], char descripcion[], int id, int tamServ);

int validarServicioId(eServicio vec[], int tamServ, int id);

int cargarPrecioServicio(eServicio servicios[], float* precio, int id, int tamServ);

int listarServicios(eServicio servicios[],int tamServ);

void mostrarServicio(eServicio servicio);
#endif // SERVICIO_H_INCLUDED
