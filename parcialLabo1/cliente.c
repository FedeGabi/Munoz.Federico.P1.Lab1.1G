#include "cliente.h"


char nombres[20][20]= {"roberta", "pablito", "noemi", "marcos", "ruben", "facundo", "melisa", "carla", "hector", "silvana",
                        "estefania", "pedrito", "noelia", "marcos", "ruben", "facundo", "melisa", "carla", "hector", "silvana"};

char sexos[20]= {'f','m','f','m','m','m','f','f','m','f','f','m','f','m','m','m','f','f','m','f'};

int hardcodearClientes(eCliente listaClientes[], int tamClientes, int cant, int* nextId)
{
    if(listaClientes!=NULL && tamClientes >0 && cant >0 && cant <=tamClientes)
    {
        for(int i=0; i<cant; i++)
        {
            strcpy(listaClientes[i].nombre, nombres[i]);
            listaClientes[i].sexo=sexos[i];
            listaClientes[i].id=*nextId;
            (*nextId)++;
            listaClientes[i].isEmpty=0;
        }
    }
    return 0;
}



int inicializarListaCLientes(eCliente listaClientes[],int tamClientes)
{
    int retorno=0;
    if(listaClientes!=NULL)
    {
        for(int i=0; i<tamClientes; i++)
        {
            listaClientes[i].isEmpty=1;
        }
        retorno=1;
    }
    return retorno;
}



int ingresarCliente(eCliente listaClientes[], int tamClientes, int* idNext)
{
    int retorno=0;
    char auxNombre[20];
    char auxSexo;
    int indice=-1;
    if(listaClientes!=NULL && tamClientes>0)
    {
        indice=buscarPrimerClienteVacio(listaClientes, tamClientes);
        if(indice!=-1)
        {
            if(ingresarValidarNombre(auxNombre, 3, 19, "\nIngrese nombre: ") &&
                    ingresarSexo(&auxSexo))
            {
                strcpy(listaClientes[indice].nombre, auxNombre);
                listaClientes[indice].sexo=auxSexo;
                listaClientes[indice].id=*idNext;
                (*idNext)++;
                listaClientes[indice].isEmpty=0;
                retorno=1;
            }
        }
        else
        {
            printf("\nNo hay espacio en lista cliente\n");
            system("pause");
        }
    }
    return retorno;
}

int ingresarSexo(char* sexo)
{
    int seguir=1;
    int retorno=0;
    char auxSexo;
    if(sexo!=NULL)
    {
        do
        {
            printf("ingresar sexo: ");
            auxSexo=getchar();
            if(tolower(auxSexo)== 'm' || tolower(auxSexo)== 'f')
            {
                *sexo=auxSexo;
                seguir=0;
                retorno=1;
            }
        }
        while(seguir==1);
    }
    return retorno;
}

int buscarPrimerClienteVacio(eCliente listaClientes[], int tamClientes)
{
    int indice=-1;
    if(listaClientes!=NULL && tamClientes>0)
    {
        for(int i=0; i<tamClientes; i++)
        {
            if(listaClientes[i].isEmpty==1)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}


int cargarNombreClienteId(eCliente listaClientes[], int tamClientes,int id, char nombre[])
{
    int retorno=0;
    if(listaClientes!=NULL && tamClientes>0 && nombre!=NULL)
    {
        for(int i=0; i<tamClientes; i++)
        {
            if(listaClientes[i].id== id)
            {
                strcpy(nombre, listaClientes[i].nombre);
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}

void mostrarCliente(eCliente cliente)
{
    printf("%d %10s %5c  %d\n", cliente.id, cliente.nombre, cliente.sexo, cliente.isEmpty);
}
