#include "cliente.h"


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

int menuIngresarCliente(eCliente vec, int tamClientet)
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
                seguir=0;
                retorno=1;
            }
            if(contador==2)
            {
                strcpy(vec.nombre, auxNombre);
                vec.sexo=auxSexo;
                retorno=1;
                seguir=0;
            }
            else{
                printf("\ndeben ingresarse todos los valores");
                system("cls");
                seguir=confirmar("\nError, ID invalido, volver a ingresar? (s o n): ");
                retorno=0;
            }
        }
        else{
            system("cls");
            seguir=confirmar("\nError, ID invalido, volver a ingresar? (s o n): ");
            retorno=0;
        }
    }
    while(seguir);
    return retorno;
}

