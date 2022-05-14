#include "trabajo.h"

int inicializarTrabajos(eTrabajo vec[], int tam)
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

int altaTrabajo(eTrabajo vec[], int tam, eAuto autos[], int tamAutos, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarcas, eColor colores[], int tamColor,  int* pIdNext)
{
    int retorno=0;
    if(vec != NULL && tam>0 && autos != NULL && tamAutos>0 && marcas != NULL && tamMarcas>0 && colores != NULL && tamColor>0 && pIdNext!= NULL)
    {
        eTrabajo auxTrabajo;
        eFecha fecha;
        int contadorIngresos=0;
        int seguir=0;
        int indice;
        indice=buscarPrimerTrabajoVacio(vec, tam);
        if(indice>-1)
        {
            auxTrabajo.idAuto=menuIngresarAuto(autos, tamAutos, marcas, tamMarcas, colores, tamColor);
            if(auxTrabajo.idAuto)
            {
                contadorIngresos++;
                auxTrabajo.idServicio=menuIngresarServicio(servicios, tamServ);
                if(auxTrabajo.idServicio)
                {
                    contadorIngresos++;
                    do
                    {
                        printf("\nIngrese fecha (dd/mm/aaaaa): ");
                        scanf("%d/%d/%d",&fecha.dia,
                              &fecha.mes,
                              &fecha.anio);
                        if((fecha.dia >31 || fecha.dia <1) ||
                                (fecha.mes >12 || fecha.mes <1) ||
                                (fecha.anio >2022 || fecha.anio <2022))
                        {
                            system("pause");
                            printf("INGRESE UNA FECHA VALIDA (respete el formato: dd/mm/aaaa)\n");
                            seguir=confirmar("Desea volver a ingresar?: ");
                            retorno=0;
                        }
                        else
                        {
                            contadorIngresos++;
                        }
                    }
                    while(seguir);
                }
            }
            if(contadorIngresos==3)
            {
                vec[indice]=auxTrabajo;
                vec[indice].fechaTrabajo=fecha;
                vec[indice].isEmpty=0;
                vec[indice].id=*pIdNext;
                (*pIdNext)++;
                printf("\nALTA DE Trabajo EXITOSA!\n");
                retorno=1;
            }
            else
            {
                system("cls");
                printf("\nCARGA DE Trabajo CANCELADA. DEBEN INGRESARSE TODOS LOS DATOS\n");
            }
        }
        else
        {
            system("cls");
            printf("NO HAY LUGAR EN EL SISTEMA");
        }
    }
    system("pause");
    return retorno;
}


int buscarTrabajoId(eTrabajo vec[], int tam, int id, int* pIndice)
{
    int retorno = 0;
    if( vec != NULL && pIndice != NULL && tam > 0 )
    {
        *pIndice = -1;
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty  && vec[i].id == id)
            {
                *pIndice = i;
                break;
            }
        }
        retorno = 1;
    }
    return retorno;
}

int buscarPrimerTrabajoVacio(eTrabajo vec[], int tamVia)
{
    int indice = -1;
    if( vec != NULL && tamVia > 0 )
    {
        for(int i=0; i < tamVia; i++)
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

int listarTrabajos( eTrabajo trabajos[], eServicio servicios[], int tamVia, int tamServ)
{
    int retorno=0;
    int flag=1;
    if(trabajos != NULL && servicios != NULL && tamVia>0 && tamServ >0)
    {
        system("cls");
        printf("----------------------------------------------------\n");
        printf("--------------    LISTA trabajos     -----------------\n");
        printf("----------------------------------------------------\n");
        printf("ID         ID MICRO      DESTINO    PRECIO     FECHA\n");
        printf("----------------------------------------------------\n\n");
        for(int i=0 ; i<tamVia ; i++)
        {
            if(!trabajos[i].isEmpty)
            {
                mostrarTrabajo(trabajos[i], servicios, tamServ);
                flag=0;
                retorno=1;
            }
        }
        if(flag)
        {
            printf("NO HAY trabajos EN EL SISTEMA\n");
        }
    }
    system("pause");
    return retorno;
}

void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamServ)
{
    char descDestino[20];
    float precio;
    cargarDescripcionServicio(servicios, descDestino, trabajo.idServicio, tamServ);
    cargarPrecioServicio(servicios, &precio, trabajo.idServicio, tamServ);
    printf("%d  |   %d   |   %10s   |   %.2f   |   %d/%d/%d \n",
           trabajo.id,
           trabajo.idAuto,
           descDestino,
           precio,
           trabajo.fechaTrabajo.dia,
           trabajo.fechaTrabajo.mes,
           trabajo.fechaTrabajo.anio );
}
