#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "inputs.h"
#include <string.h>
typedef struct{
    int id;
    char nombre[20];
    char sexo;
    int isEmpty;
}eCliente;

int hardcodearClientes(eCliente listaClientes[], int tamClientes, int cant, int* nextId);
int inicializarListaCLientes(eCliente listaClientes[],int tamClientes);
int ingresarCliente(eCliente listaClientes[], int tamClientes, int* idNext);
int ingresarSexo(char* sexo);
int buscarPrimerClienteVacio(eCliente listaClientes[], int tamClientes);
int cargarNombreClienteId(eCliente listaClientes[], int tamClientes,int id, char nombre[]);
#endif // CLIENTE_H_INCLUDED
