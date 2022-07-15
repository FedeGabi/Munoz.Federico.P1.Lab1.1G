#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
typedef struct{
    int id;
    char descripcion[20];
    float precio;
}eServicio;

int hardcodearServicios(eServicio listaServicios[], int tamServicio);
int menuIngresarServicios(int* id);
int cargarDescripcionServicioId(eServicio listaServicios[], int tamServicio,int id, char descripcion[]);

#endif // SERVICIO_H_INCLUDED
