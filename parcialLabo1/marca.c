#include "marca.h"
int menuIngresarMarca(eMarca vec[], int tamMarcas)
{
    int opcion=0;
    int seguir=1;
    do
    {
        system("cls");
        listarMarcas(vec, tamMarcas);
        printf("\nIngrese ID Marca: ");
        scanf("%d", &opcion);
        if(validarMarcaId(vec,tamMarcas, opcion))
        {
            seguir=0;
        }
        else
        {
            system("cls");
            seguir=confirmar("\nError, ID invalido, volver a ingresar? (s o n): ");
            opcion=0;
        }
    }
    while(seguir);
    return opcion;
}


int buscarMarcaId(eMarca vec[], int tamMarcas, int id, int* pIndice)
{
    int retorno = 0;
    if( vec != NULL && pIndice != NULL && tamMarcas > 0 )
    {
        *pIndice = -1;
        for(int i=0; i < tamMarcas; i++)
        {
            if(vec[i].id == id)
            {
                *pIndice = i;
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}

int validarMarcaId(eMarca vec[], int tamMarcas, int id)
{
    int retorno = 0;
    if( vec != NULL && tamMarcas > 0 && id>0 )
    {
        for(int i=0; i < tamMarcas; i++)
        {
            if(vec[i].id == id)
            {
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}

int cargarDescripcionMarca(eMarca marcas[], char descripcion[], int id, int tamMarcas)
{
    int retorno=0;
    if(marcas != NULL && descripcion != NULL && tamMarcas>0 && id>0)
    {
        for(int i=0; i<tamMarcas; i++)
        {
            if(marcas[i].id == id)
            {
                strcpy(descripcion, marcas[i].descripcion);
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}

int listarMarcas(eMarca marcas[],int tamMarcas)
{
    int retorno=0;
    if(marcas != NULL && tamMarcas>0)
    {
        system("cls");

        printf("    LISTA MARCAS\n");
        printf("\n");
        printf("ID            MARCA\n");
        printf("-----------------------\n\n");
        for(int i=0 ; i<tamMarcas ; i++)
        {
                mostrarMarca(marcas[i]);
                retorno=1;
        }
    }
    return retorno;
}

void mostrarMarca(eMarca marca)
{
    printf("%d  |   %10s   \n", marca.id, marca.descripcion);
}
