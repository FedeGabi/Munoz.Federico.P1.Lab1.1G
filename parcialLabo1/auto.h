#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "marca.h"
#include "color.h"
#include "cliente.h"
typedef struct{
    int id;
    int idMarca;
    int idColor;
    int idCliente;
    char caja;
    int isEmpty;
}eAuto;

int hardcodearAutos(eAuto listaAutos[], int tamAutos, eCliente listaClientes[],int tamClientes, int cant, int* nextId);

int inicializarListaAutos(eAuto listaAutos[],int tamAutos);

int ingresarCaja(char* caja);

int buscarPrimerVacio(eAuto listaAutos[], int tamAutos);

int buscarAutoId(eAuto listaAutos[], int tamAutos, int id);

int altaAuto(eAuto listaAutos[], int tamAutos, eMarca listaMarcas[], int tamMarcas, eColor listaColores[], int tamColores, eCliente listaClientes[], int tamClientes, int* idNext, int* idNextCliente);

int listarAutos(eAuto listaAutos[], int tamAutos, eMarca listaMarcas[], eColor listaColores[], eCliente listaClientes[], int tamClientes, int tamColores, int tamMarcas);

void mostrarAuto(eAuto vehiculo, eMarca listaMarcas[], eColor listaColores[], eCliente listaCliente[], int tamClientes, int tamColores, int tamMarcas);

int eliminarAuto(eAuto listaAutos[], int tamAutos, eMarca listaMarcas[], int tamMarcas, eColor listaColores[], int tamColores, eCliente listaClientes[], int tamClientes);


int modificarAuto(eAuto listaAutos[], eMarca listaMarcas[], eColor listaColores[], eCliente listaClientes[], int tamClientes, int tamAutos, int tamMarcas, int tamColores);

int isNotEmpty( eAuto listaAutos[], int tamAutos);


int menuIngresarAuto(eAuto listaAutos[], int tamAutos, eColor listaColores[], int tamColores, eMarca listaMarcas[], int tamMarcas, eCliente listaClientes[], int tamClientes);


#endif // AUTO_H_INCLUDED
