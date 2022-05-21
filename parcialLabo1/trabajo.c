#include "trabajo.h"

int servicios[20]={20001, 20001,20002,20003, 20001,20001,20003,20002,20001,20001,20002,20002,20003, 20004,20001,20002,20001,20001,20002, 20001};
int autos[20]={30000,30001, 30002,30003,30004, 30005,30006,30007,30008,30009,30010,30011,30012,30013, 30014,30015,30016,30017,30018,30019};
eFecha fechas[20]={{11,05,2022}, {22,8,2022},{5,1,2022}, {30,010,2022},{1,11,2022}, {3,4,2022},{27,6,2022}, {14,2,2022},
                     {20,9,2022}, {1,8,2022},{7,3,2022}, {5,12,2022}, {26,05,2022}, {12,8,2022},{31,7,2022}, {11,04,2022},
                     {1,4,2022}, {13,8,2022},{05,9,2022}, {30,12,2022}};

int hardcodearTrabajos(eTrabajo trabajos[], int tamTrabajos, int* pidNext, int cant)
{
    int retorno=0;
    if(trabajos!= NULL && tamTrabajos>0 && cant<=tamTrabajos)
    {
        for(int i=0; i<cant; i++)
        {
            trabajos[i].idAuto=autos[i];
            trabajos[i].idServicio=servicios[i];
            trabajos[i].fechaTrabajo=fechas[i];
            trabajos[i].id=*pidNext;
            trabajos[i].isEmpty=0;
            (*pidNext)++;
        }
        retorno=1;
    }
    return retorno;
}


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

int altaTrabajo(eTrabajo vec[], int tam, eAuto autos[], int tamAutos, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarcas, eColor colores[], int tamColor, eCliente clientes[], int tamClientes, int* pIdNext)
{
    int retorno=0;
    if(vec != NULL && tam>0 && autos != NULL && tamAutos>0 && marcas != NULL && tamMarcas>0 && colores != NULL && tamColor>0 && pIdNext!= NULL)
    {
        eTrabajo auxTrabajo;
        eFecha fecha;
        int contadorIngresos=0;
        int seguir=1;
        int indice;
        indice=buscarPrimerTrabajoVacio(vec, tam);
        if(indice>-1)
        {
            auxTrabajo.idAuto=menuIngresarAuto(autos, tamAutos, marcas, tamMarcas, colores, tamColor, clientes, tamClientes);
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
                        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
                        if((fecha.dia >31 || fecha.dia <1) ||
                            (fecha.mes >12 || fecha.mes <1) ||
                            (fecha.anio >2022 || fecha.anio <2022))
                        {

                            printf("INGRESE UNA FECHA VALIDA (respete el formato: dd/mm/aaaa)\n");
                            seguir=confirmar("Desea volver a ingresar?: ");
                            retorno=0;
                        }
                        else
                        {
                            contadorIngresos++;
                            seguir=0;
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
                printf("\nALTA DE TRABAJO EXITOSA!\n");
                retorno=1;
            }
            else
            {
                system("cls");
                printf("\nCARGA DE TRABAJO CANCELADA.\n");
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

int listarTrabajos(eTrabajo trabajos[], eServicio servicios[], int tamVia, int tamServ)
{
    int retorno=0;
    int flag=1;
    if(trabajos != NULL && servicios != NULL && tamVia>0 && tamServ >0)
    {
        system("cls");
        printf("------------------------------------------------------------------\n");
        printf("--------------------    LISTA TRABAJOS     -----------------------\n");
        printf("------------------------------------------------------------------\n");
        printf("ID         ID AUTO       SERVICIO       PRECIO         FECHA      \n");
        printf("------------------------------------------------------------------\n\n");
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
            printf("NO HAY TRABAJOS EN EL SISTEMA\n");
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
    printf("%d  |   %d   |   %10s   |   %.2f   |   %02d/%02d/%d \n",
           trabajo.id,
           trabajo.idAuto,
           descDestino,
           precio,
           trabajo.fechaTrabajo.dia,
           trabajo.fechaTrabajo.mes,
           trabajo.fechaTrabajo.anio );
}

int listarTrabajosxServicios(eTrabajo trabajos[], eServicio servicios[], int tamVia, int tamServ, int idServicio)
{
    int retorno=0;
    int flag=1;
    if(trabajos != NULL && servicios != NULL && tamVia>0 && tamServ >0 && idServicio>0)
    {
        char auxCadena[20];
        system("cls");
        printf("------------------------------------------------------------------\n");
        printf("--------------------    LISTA TRABAJOS     -----------------------\n");
        printf("------------------------------------------------------------------\n");
        printf("ID         ID AUTO       SERVICIO       PRECIO         FECHA      \n");
        printf("------------------------------------------------------------------\n\n");
        for(int i=0 ; i<tamVia ; i++)
        {
            if(!trabajos[i].isEmpty && trabajos[i].idServicio == idServicio)
            {
                mostrarTrabajo(trabajos[i], servicios, tamServ);
                flag=0;
                retorno=1;
            }
        }
        if(flag)
        {
            cargarDescripcionServicio(servicios, auxCadena, idServicio, tamServ);
            printf("NO HAY TRABAJOS CON EL SERVICIO %s CARGADOS EN EL SISTEMA\n", auxCadena);
        }
    }
    return retorno;
}
