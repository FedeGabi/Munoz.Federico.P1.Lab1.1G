#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#define IMPUT_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "marca.h"
#include "color.h"
#include "auto.h"
#include "servicio.h"
#include <stdio.h>
#include <stdlib.h>
int mostrarMenuPrincipal();
int menuModificarAutos();



int ingresarFloat(float *pFloat, char msj [], char msjError[], int intentos);
int ingresarInt(int *pInt, char msj [], char msjError[]);
int ingresarValidarCadena(char cadena[],int tamMin ,int tamMax, char msj[], char msjError[], int intentos);
int ingresarValidarCaracter(char msj[], char msjError[], char char1, char char2, char* pResultado);
int confirmar(char msj[]);


#endif // INPUT_H_INCLUDED
