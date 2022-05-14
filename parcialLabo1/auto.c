#include "auto.h"

int inicializarAutos(eAuto vec[], int tam)
{
    int retorno=0;
    if(vec != NULL && tam >0)
    {
        for(int i=0; i<tam ; i++)
        {
            vec[i].isEmpty=1;
        }
        retorno=1;
    }
    return retorno;
}

int validarAutoId(eAuto vec[], int tamAutos, int id)
{
    int retorno = 0;
    if( vec != NULL && tamAutos > 0 && id > 0)
    {
        for(int i=0; i < tamAutos; i++)
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
int buscarAutoId(eAuto vec[], int tam, int id, int* indice)
{

    int retorno=0;
    if( vec!= NULL && tam > 0 && id >0 )
    {
        *indice=-1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty==0  && vec[i].id == id)
            {
                *indice = i;
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}

int buscarPrimerVacio(eAuto vec[], int tam)
{
    int indice = -1;
    if( vec != NULL && tam > 0 )
    {
        for(int i=0; i < tam; i++)
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

int menuIngresarAuto(eAuto vec[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores)
{
    int opcion=0;
    int seguir=0;
    do
    {
        system("cls");
        if(listarAutos(vec,marcas,colores,tamAutos,tamMarcas,tamColores))
        {
            printf("\nIngrese ID Micro: ");
            scanf("%d", &opcion);
            if(validarAutoId(vec, tamAutos, opcion))
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
        else
        {
            printf("NO HAY AUTOS CARGADOS\n");
            system("pause");
            opcion=0;
        }
    }
    while(seguir);
    return opcion;
}

int altaAuto(eAuto vec[], int tam, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores,  int* pIdNext)
{
    int retorno=0;
    if(vec != NULL && tam>0 && marcas != NULL && tamMarcas>0 && colores != NULL && tamColores>0 && pIdNext!= NULL)
    {
        eAuto auxAuto;
        int contadorIngresos=0;
        int indice;
        int seguir=0;
        int auxInt=0;
        char auxChar;
        indice=buscarPrimerVacio(vec, tam);
        if(indice>=0)
        {
            auxAuto.idMarca=menuIngresarMarca(marcas,tamMarcas);
            if(auxAuto.idMarca)
            {
                contadorIngresos++;
                auxAuto.idColor=menuIngresarColor(colores, tamColores);
                if(auxAuto.idColor)
                {
                    contadorIngresos++;
                    do
                    {
                        if(ingresarValidarCaracter("\nIngrese caja (m o a): ", "\n Error, valor invalido...", 'a', 'm', &auxChar))
                        {
                            auxAuto.caja=auxInt;
                            auxAuto.caja=auxChar;
                            auxAuto.isEmpty=0;
                            contadorIngresos++;
                            seguir=0;
                        }
                        else
                        {

                        }
                    }
                    while(seguir);
                }
            }
            if(contadorIngresos==3)
            {
                vec[indice]=auxAuto;
                vec[indice].id=*pIdNext;
                (*pIdNext)++;
                printf("\nALTA DE AUTO EXITOSA!\n");
                retorno=1;
            }
            else
            {
                system("cls");
                printf("\nCARGA DE AUTO CANCELADA. DEBEN INGRESARSE TODOS LOS DATOS\n");
                system("pause");
            }
        }
        else
        {
            printf("\nNO HAY LUGAR...");
        }
    }
    return retorno;
}

int bajaAuto(eAuto autos[], eMarca marcas[], eColor colores[], int tamAutos, int tamMarcas, int tamColores)
{
    int retorno = 0;
    int indice;
    int id;
    char confirma;
    if( autos != NULL && tamAutos > 0 && marcas != NULL && tamMarcas > 0 && colores != NULL && tamColores >0)
    {
        listarAutos(autos,marcas, colores, tamAutos, tamMarcas,tamColores);
        printf("Ingrese id: ");
        scanf("%d", &id);
        if( buscarAutoId(autos, tamAutos, id, &indice))
        {
            if(indice == -1)
            {
                printf("NO EXISTE AUTO CON ID: %d EN EL SISTEMA\n", id);
                system("pause");
            }
            else
            {
                mostrarAuto(autos[indice],marcas, colores, tamMarcas, tamColores);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's' || confirma == 'S')
                {
                    autos[indice].isEmpty = 1;
                    printf("Baja exitosa!!!\n");
                    system("pause");
                }
                else
                {
                    printf("Baja cancelada por el usuario\n");
                    system("pause");
                }

            }

            retorno = 1;
        }
    }
    return retorno;
}


int listarAutos(eAuto autos[], eMarca marcas[], eColor colores[], int tam, int tamMarcas, int tamColores)
{
    int retorno=0;
    int flag=1;
    if(autos != NULL && marcas != NULL && colores != NULL && tam>0 && tamMarcas >0 && tamColores>0)
    {
        system("cls");
        printf("-------------------------------------------------\n");
        printf("--------------    LISTA AUTOS     --------------\n");
        printf("-------------------------------------------------\n");
        printf("ID          MARCA         COLOR         CAJA\n");
        printf("-------------------------------------------------\n\n");
        for(int i=0 ; i<tam ; i++)
        {
            if(autos[i].isEmpty==0)
            {
                mostrarAuto(autos[i], marcas, colores, tamMarcas, tamColores);
                flag=0;
                retorno=1;
            }
        }
        if(flag)
        {
            retorno=0;
        }
    }
    return retorno;
}

void mostrarAuto(eAuto autos, eMarca marcas[], eColor colores[], int tamMarcas, int tamColores)
{
    char descMarca[20];
    char descColor[20];
    cargarDescripcionMarca(marcas, descMarca, autos.idMarca, tamMarcas);
    cargarDescripcionColor(colores, descColor, autos.idColor, tamColores);
    printf("%d  |   %10s   |   %10s   |   %c  \n", autos.id, descMarca, descColor, toupper(autos.caja));
}

int buscarLleno(eAuto autos[], int tamAutos)
{
    int retorno=0;
    if(autos!=NULL && tamAutos>0)
    {
        for(int i=0; i<tamAutos;i++)
        {
            if(autos[i].isEmpty==0)
            {
                retorno=1;
                break;
            }
            retorno=0;
        }
    }
    return retorno;
}
