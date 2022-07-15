#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;
int cargarFecha(eFecha* fecha);
#endif // FECHA_H_INCLUDED
