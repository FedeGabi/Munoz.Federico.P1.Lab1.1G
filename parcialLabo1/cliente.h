#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

typedef struct{
    int id;
    char nombre[20];
    char sexo;
    int isEmpty;
}eCliente;

int cargarDescripcionCliente(eCliente clientes[], char nombre[], int id, int tamClientes);
int menuIngresarCliente(char nombre[], char* sexo);
int buscarPrimerClienteVacio(eCliente vec[], int tamCliente);
int inicializarClientes(eCliente vec[], int tamCliente);
int buscarClienteXId(eCliente clientes[], int idCliente, int tamClientes);
#endif // CLIENTE_H_INCLUDED
