#include "cliente.h"

int inicializarClientes(eCliente vec[], int tamCliente)
{
    int retorno=0;
    if(vec != NULL && tamCliente >0)
    {
        for(int i=0; i<tamCliente ; i++)
        {
            vec[i].isEmpty=1;
        }
        retorno=1;
    }
    return retorno;
}


int cargarDescripcionCliente(eCliente clientes[], char nombre[], int id, int tamClientes)
{
    int retorno=0;
    if(clientes != NULL && nombre != NULL && tamClientes>0 && id>0)
    {
        for(int i=0; i<tamClientes; i++)
        {
            if(clientes[i].id == id)
            {
                strcpy(nombre, clientes[i].nombre);
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}

int menuIngresarCliente(char nombre[], char* sexo)
{
    int retorno=0;
    char auxNombre[20];
    char auxSexo;
    int contador=0;
    int seguir=1;
    do
    {
        system("cls");
        if(ingresarValidarNombre(auxNombre, 3, 20, "\nIngrese nombre cliente ", "\nError, reingrese nombre"))
        {
            contador++;
            if(contador==1 && ingresarValidarCaracter("\nIngrese sexo: ", "\nError, caracter invalido", 'm', 'f', &auxSexo))
            {
                contador++;
                retorno=1;
            }
            if(contador==2)
            {
                strcpy(nombre, auxNombre);
                *sexo=auxSexo;
                retorno=1;
                seguir=0;
            }
            else
            {
                system("cls");
                printf("\ndeben ingresarse todos los valores");
                seguir=confirmar("\nvolver a ingresar? (s o n): ");
                retorno=0;
            }
        }
        else
        {
            system("cls");
            seguir=confirmar("\ndeben ingresarse todos los valores, volver a ingresar? (s o n): ");
            retorno=0;
        }
    }
    while(seguir);
    return retorno;
}


int buscarPrimerClienteVacio(eCliente vec[], int tamCliente)
{
    int indice = -1;
    if( vec != NULL && tamCliente > 0 )
    {
        for(int i=0; i < tamCliente; i++)
        {
            if(vec[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int buscarClienteXId(eCliente clientes[], int idCliente, int tamClientes)
{
    int indice=-1;
    if(clientes!= NULL && tamClientes>0)
    {
        for(int i=0; i<tamClientes; i++)
        {
            if(clientes[i].id == idCliente)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}
