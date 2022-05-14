#include "servicio.h"


int menuIngresarServicio(eServicio vec[], int tamServ)
{
    int opcion=0;
    int seguir=1;
    do
    {
        system("cls");
        for(int i=0; i<tamServ; i++)
        {
            listarServicios(vec, tamServ);
        }
        printf("\nIngrese ID Servicio: ");
        scanf("%d", &opcion);
        if(validarServicioId(vec, tamServ, opcion))
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

int cargarDescripcionServicio(eServicio servicios[], char descripcion[], int id, int tamServ)
{
    int retorno=0;
    if(servicios != NULL && descripcion != NULL && tamServ>0 && id>0)
    {
        for(int i=0; i<tamServ; i++)
        {
            if(servicios[i].id == id)
            {
                strcpy(descripcion, servicios[i].descripcion);
                retorno=1;
                break;
            }
        }
        retorno=1;
    }
    return retorno;
}

int validarServicioId(eServicio vec[], int tamServ, int id)
{
    int retorno = 0;
    if( vec != NULL && tamServ > 0 && id>0 )
    {
        for(int i=0; i < tamServ; i++)
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

int cargarPrecioServicio(eServicio servicios[], float* precio, int id, int tamServ)
{
    int retorno=0;
    if(servicios != NULL && precio>0 && tamServ>0 && id>0)
    {
        for(int i=0; i<tamServ; i++)
        {
            if(servicios[i].id == id)
            {
                *precio=servicios[i].precio;
                retorno=1;
                break;
            }
        }
        retorno=1;
    }
    return retorno;
}

int listarServicios(eServicio servicios[],int tamServ)
{
    int retorno=0;
    if(servicios != NULL && tamServ>0)
    {
        system("cls");
        printf("------------------------------------\n");
        printf("------------LISTA SERVICIOS----------\n");
        printf("------------------------------------\n");
        printf("ID            SERVICIO         PRECIO\n");
        printf("------------------------------------\n\n");
        for(int i=0 ; i<tamServ ; i++)
        {
                mostrarServicio(servicios[i]);
                retorno=1;
        }
    }
    system("pause");
    return retorno;
}

void mostrarServicio(eServicio servicio)
{
    printf("%d  |   %10s   |   %.2f   |\n", servicio.id, servicio.descripcion, servicio.precio );
}
