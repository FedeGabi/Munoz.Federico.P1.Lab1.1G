#include "color.h"

int menuIngresarColor(eColor vec[], int tamColores)
{
    int opcion=0;
    int seguir=1;
    do
    {
        system("cls");
        listarColores(vec, tamColores);
        printf("\nIngrese ID Color: ");
        scanf("%d", &opcion);
        if(validarColorId(vec,tamColores, opcion))
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



int buscarColorId(eColor vec[], int tamColores, int id, int* pIndice)
{
    int retorno = 0;
    if( vec != NULL && pIndice != NULL && tamColores > 0 )
    {
        *pIndice = -1;
        for(int i=0; i < tamColores; i++)
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

int validarColorId(eColor vec[], int tamColores, int id)
{
    int retorno = 0;
    if( vec != NULL && tamColores > 0 && id>0 )
    {
        for(int i=0; i < tamColores; i++)
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

int cargarDescripcionColor(eColor colores[], char descripcion[], int id, int tamColores)
{
    int retorno=0;
    if(colores != NULL && descripcion != NULL && tamColores>0 && id>0)
    {
        for(int i=0; i<tamColores; i++)
        {
            if(colores[i].id == id)
            {
                strcpy(descripcion, colores[i].nombreColor);
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}

int listarColores(eColor Colors[],int tamColores)
{
    int retorno=0;
    if(Colors != NULL && tamColores>0)
    {
        system("cls");
        printf("     LISTA COLORES\n");
        printf("\n");
        printf("ID            COLOR\n");
        printf("-----------------------\n\n");
        for(int i=0 ; i<tamColores ; i++)
        {
                mostrarColor(Colors[i]);
                retorno=1;
        }
    }
    return retorno;
}

void mostrarColor(eColor color)
{
    printf("%d  |   %10s   \n", color.id, color.nombreColor);
}





