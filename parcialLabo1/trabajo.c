#include "trabajo.h"

eFecha fechas[20]= {{13,5,2022},{11,3,2022},{01,12,2022},{30,1,2022},{22,3,2022},{9,10,2022},{11,8,2022},{6,9,2022},{12,07,2022},
    {13,5,2022},{13,5,2022},{29,02,2022},{01,04,2022},{07,11,2022},{05,5,2022},{5,03,2022},{30,10,2022},{02,8,2022},{10,5,2022},{13,10,2022}
};

int idsServicios[20]= {20000,20001,20003,20002,20003,20002, 20000,20001,20003,20000,20002,20003,20002, 20000,20003,20003,20000,20001, 20001, 20001};

int hardcodearTrabajos(eTrabajo listaTrabajos[],eAuto listaAutos[], int tamTrabajos, int tamAutos, int cant, int* nextId)
{
    int retorno=0;
    if(listaTrabajos!=NULL && listaAutos!=NULL && tamAutos>0 && tamTrabajos >0 && cant >0 && cant <=tamTrabajos && cant<=tamAutos)
    {
        for(int i=0; i<cant; i++)
        {
            listaTrabajos[i].idAuto=listaAutos[i].id;
            listaTrabajos[i].idServicio=idsServicios[i];
            listaTrabajos[i].fecha=fechas[i];
            listaTrabajos[i].isEmpty=0;
            listaTrabajos[i].id=*nextId;
            (*nextId)++;
            retorno=1;
        }
    }
    return retorno;
}

int inicializarListaTrabajos(eTrabajo listaTrabajos[], int tamTrabajos)
{
    int retorno=0;
    if(listaTrabajos!= NULL && tamTrabajos>0)
    {
        for(int i=0; i<tamTrabajos; i++)
        {
            listaTrabajos[i].isEmpty=1;
        }
        retorno=1;
    }
    return retorno;
}

int buscarPrimerTrabajoVacio(eTrabajo listaTrabajos[], int tamTrabajos)
{
    int indice=-1;
    if(listaTrabajos!=NULL && tamTrabajos>0)
    {
        for(int i=0; i<tamTrabajos; i++)
        {
            if(listaTrabajos[i].isEmpty==1)
            {
                indice=i;
                break;
            }
            else{
            }
        }
    }
    return indice;
}

int isNotEmptyTrabajo( eTrabajo listaTrabajos[], int tamTrabajos)
{
    int retorno=0;
    if(listaTrabajos!=NULL && tamTrabajos>0)
    {
        for(int i=0; i<tamTrabajos; i++)
        {
            if(listaTrabajos[i].isEmpty==0)
            {
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}


int altaTrabajo(eTrabajo listaTrabajos[], eServicio listaServicios[], eAuto listaAutos[], eColor listaColores[], eMarca listaMarcas[], eCliente listaClientes[], int tamTrabajos, int tamServicios, int tamAutos, int tamColores, int tamMarcas, int tamClientes, int* idNextTrabajo)
{
    int retorno=0;
    int indice=-1;
    int auxIdServicio;
    int auxIdAuto;
    eFecha auxfecha;
    if(listaTrabajos!=NULL && listaServicios!= NULL && tamTrabajos>0 && tamServicios>0)
    {

        indice=buscarPrimerTrabajoVacio(listaTrabajos, tamTrabajos);
        if(indice!=-1)
        {
            auxIdAuto=menuIngresarAuto(listaAutos, tamAutos, listaColores, tamColores, listaMarcas, tamMarcas, listaClientes, tamClientes);
            if(auxIdAuto > 0 && menuIngresarServicios(&auxIdServicio) && cargarFecha(&auxfecha))
            {
                listaTrabajos[indice].fecha=auxfecha;
                listaTrabajos[indice].idServicio=auxIdServicio;
                listaTrabajos[indice].idAuto= auxIdAuto;
                listaTrabajos[indice].isEmpty=0;
                listaTrabajos[indice].id=*idNextTrabajo;
                (*idNextTrabajo)++;
                retorno=1;
            }
            else
            {
                printf("\nAlta trabajo cancelada");
            }
        }
        else{
            printf("No existen trabajos cargados en el sistema!\n");
        }
    }
    system("pause");
    return retorno;
}


int listarTrabajos(eTrabajo listaTrabajos[], eServicio listaServicios[], int tamTrabajos, int tamServicios)
{
    system("cls");
    int retorno=0;
    if(listaTrabajos!=NULL && tamTrabajos>0 && listaServicios!=NULL && tamServicios>0)
    {
        printf("ID    ID-AUTO      SERVICIO       FECHA \n");
        printf("----------------------------------------\n\n");
        for(int i=0; i<tamTrabajos; i++)
        {
            if(listaTrabajos[i].isEmpty==0)
            {
                mostrarTrabajo(listaTrabajos[i], listaServicios, tamTrabajos, tamServicios);
            }
        }
        retorno=1;
    }
    return retorno;
}


void mostrarTrabajo(eTrabajo trabajo, eServicio listaServicios[], int tamTrabajos, int tamServicios)
{
    char servicio[20];
    cargarDescripcionServicioId(listaServicios, tamServicios, trabajo.idServicio,servicio);
    printf("%d    %d    %10s     %02d/%02d/%d\n", trabajo.id, trabajo.idAuto, servicio, trabajo.fecha.dia,
           trabajo.fecha.mes,
           trabajo.fecha.anio );
}

