#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nombre[20];
    char sexo;
}eCliente;

int cargarDescripcionCliente(eCliente clientes[], char nombre[], int id, int tamClientes);
int menuIngresarCliente(eCliente vec, int tamCliente);
#endif // CLIENTE_H_INCLUDED
