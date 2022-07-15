#include "informes.h"


int mostrarTrabajosFecha(eTrabajo listaTrabajos[], int tamTrabajos, eServicio listaServicios[], int tamServicios)
{
    system("cls");
    int retorno=0;
    int flag=0;
    eFecha auxFecha;
    if(listaTrabajos!=NULL && tamTrabajos>0)
    {
        if(isNotEmptyTrabajo(listaTrabajos, tamTrabajos))
        {
            if(cargarFecha(&auxFecha))
            {
                printf("ID    ID-AUTO      SERVICIO       FECHA \n");
                printf("----------------------------------------\n\n");
                for(int i=0; i<tamTrabajos; i++)
                {
                    if(listaTrabajos[i].fecha.dia == auxFecha.dia &&
                            listaTrabajos[i].fecha.mes == auxFecha.mes &&
                            listaTrabajos[i].fecha.anio == auxFecha.anio)
                    {
                        mostrarTrabajo(listaTrabajos[i], listaServicios, tamTrabajos, tamServicios);
                        flag=1;
                    }
                }
                if(flag==0)
                {
                    printf("\nNo existen servicios en la fecha: %02d/%02d/%d\n\n", auxFecha.dia, auxFecha.mes, auxFecha.anio);

                }
            }
            else
            {
                printf("\nBusqueda cancelada\n");
            }
        }
        else
        {
            printf("\nNo existen trabajos cargados en el sistema\n");
        }
        system("pause");
    }
    return retorno;
}



int marcaMasElegidaCliente(eAuto listaAutos[], int tamAutos, eMarca listaMarcas[], int tamMarcas)
{
    int retorno=0;
    int contador[5]= {0,0,0,0,0};
    int auxInt=0;
    int indice=-1;
    if(listaAutos!= NULL && listaMarcas!=NULL  && tamAutos>0 && tamMarcas>0)
    {
        for(int i=0; i<tamMarcas; i++)
        {
            for(int j=0; j<tamAutos; j++)
            {
                if(listaAutos[j].idMarca == listaMarcas[i].id)
                {
                    contador[i]++;
                }
            }
        }
        for(int i=0; i<tamMarcas ; i++)
        {
            if(contador[i] > auxInt)
            {
                auxInt=contador[i];
                indice=i;
                retorno=1;
            }
        }
        if(auxInt>0)
        {
            printf("\nLa marca mas elegida es %s, con %d autos\n", strupr(listaMarcas[indice].descripcion),auxInt);
        }
        else
        {
            printf("\nNo hay autos cargados en el sistema \n");
        }

    }
    system("pause");
    return retorno;
}



int contarAutosColorMarca(eAuto listaAutos[], eColor listaColores[], eMarca listaMarcas[], eCliente listaClientes[], int tamClientes, int tamAutos, int tamColores, int tamMarcas)
{
    int retorno=0;
    int contador=0;
    int auxIdMarca;
    int auxIdColor;
    char marca[20];
    char color[20];
    if(listaAutos!=NULL && listaColores!=NULL && listaMarcas!=NULL && tamAutos>0 && tamColores>0 && tamMarcas>0)
    {
        if(menuIngresarColor(&auxIdColor) && menuIngresarMarca(&auxIdMarca))
        {
            for(int i=0; i<tamAutos; i++)
            {
                if(listaAutos[i].idColor==auxIdColor && listaAutos[i].idMarca==auxIdMarca)
                {
                    contador++;
                }
            }
            cargarDescripcionColorId(listaColores, tamColores, auxIdColor, color);
            cargarDescripcionMarcaId(listaMarcas, tamMarcas, auxIdMarca, marca);
            if(contador>0)
            {
                printf("\nHay %d autos de color %s y marca %s en el sistema\n", contador, color, marca);
                printf("\nSe detallan a continuacion: \n\n");
                printf("ID   MARCA   COLOR   CAJA   DUENIO\n");
                printf("----------------------------------\n");
                for(int i=0; i<tamAutos; i++)
                {
                    if(listaAutos[i].idColor==auxIdColor && listaAutos[i].idMarca==auxIdMarca)
                    {
                        mostrarAuto(listaAutos[i], listaMarcas, listaColores, listaClientes, tamClientes, tamColores, tamMarcas);
                    }
                }
            }
            else
            {
                printf("\n No hay autos de color %s y marca %s en el sistema\n", color, marca);
            }
            retorno=1;
        }
        else
        {
            printf("\n Ingreso cancelado\n");
        }
    }
    printf("\n");
    system("pause");
    return retorno;
}


int mostrarListaOrdenadaPorCaja(eAuto listaAutos[], int tamAutos, eMarca listaMarcas[], eColor listaColores[], eCliente listaClientes[], int tamClientes, int tamMarca, int tamColor)
{
    system("cls");
    int retorno=0;
    if(listaAutos!=NULL && tamAutos>0)
    {
        if(isNotEmpty(listaAutos, tamAutos))
        {
        printf("ID       MARCA       COLOR   CAJA    DUENIO\n");
        printf("-------------------------------------------\n\n");
            for(int i=0; i < tamAutos; i++)
            {
                if(listaAutos[i].isEmpty==0)
                {
                    if(listaAutos[i].caja=='a')
                    {
                        mostrarAuto(listaAutos[i], listaMarcas, listaColores, listaClientes, tamClientes, tamColor, tamMarca);
                    }
                    retorno=1;
                }
            }
            for(int i=0; i < tamAutos; i++)
            {
                if(listaAutos[i].isEmpty==0)
                {
                    if(listaAutos[i].caja=='m')
                    {
                        mostrarAuto(listaAutos[i], listaMarcas, listaColores, listaClientes, tamClientes, tamColor, tamMarca);
                    }
                    retorno=1;
                }
            }
        }
        else
        {
            printf("\nNo existen autos cargados en e sistema\n");
            system("pause");
        }
    }
    return retorno;
}


int calcularPorcentajeCajas(eAuto listaAutos[], int tamAutos)
{
    int retorno=0;
    int contador=0;
    int manual=0;
    int automatica=0;
    if(listaAutos!=NULL && tamAutos>0)
    {
        if(isNotEmpty(listaAutos, tamAutos))
        {
            for(int i=0; i<tamAutos; i++)
            {
                if(listaAutos[i].isEmpty==0)
                {
                    if(listaAutos[i].caja=='a')
                    {
                        contador++;
                        automatica++;
                    }
                    else if(listaAutos[i].caja=='m')
                    {
                        contador++;
                        manual++;
                    }
                }
            }
            if(manual>0)
            {
                printf("\n Porcentaje de cajas manuales: %.2f\n", 100*manual/(float)contador);
            }
            else
            {
                printf("\nNo hay autos con caja manual \n");
            }
            if(automatica>0)
            {
                printf("\n Porcentaje de cajas automaticas: %.2f\n", 100*automatica/(float)contador);
            }
            else
            {
                printf("\nNo hay autos con caja automatica \n");
            }
        }
        else
        {
            printf("\nNo existen autos cargados en el sistema\n");
            system("pause");
        }

        printf("\n");
        retorno=1;
    }
    return retorno;
}

int mostrarAutosColor(eAuto listaAutos[], int tamAutos, eColor listaColores[], eMarca listaMarcas[], eCliente listaClientes[], int tamClientes, int tamColor, int tamMarca)
{
    int retorno=0;
    int auxId;
    if(listaAutos!=NULL && tamAutos>0)
    {
        if(isNotEmpty(listaAutos, tamAutos))
        {
            if(menuIngresarColor(&auxId))
            {
                for(int i=0; i<tamAutos ; i++)
                {
                    if(listaAutos[i].isEmpty==0 && listaAutos[i].idColor==auxId)
                    {
                        mostrarAuto(listaAutos[i],listaMarcas, listaColores, listaClientes, tamClientes, tamColor, tamMarca);
                    }
                }
            }
            else
            {
                printf("\nOpcion invalida\n");
            }
        }
        else
        {
            printf("\nNo existen autos cargados en el sistema\n");
            system("pause");
        }
    }
    return retorno;
}




int mostrarAutosMarca(eAuto listaAutos[], int tamAutos, eColor listaColores[], eMarca listaMarcas[], eCliente listaClientes[], int tamClientes, int tamColor, int tamMarca)
{
    int retorno=0;
    int auxId;
    if(listaAutos!=NULL && tamAutos>0)
    {
        if(isNotEmpty(listaAutos, tamAutos))
        {
            if(menuIngresarMarca(&auxId))
            {
                for(int i=0; i<tamAutos ; i++)
                {
                    if(listaAutos[i].isEmpty==0 && listaAutos[i].idMarca==auxId)
                    {
                        mostrarAuto(listaAutos[i],listaMarcas, listaColores, listaClientes, tamClientes, tamColor, tamMarca);
                    }
                }
            }
            else
            {
                printf("\nOpcion invalida\n");
            }
        }
        else
        {
            printf("\nNo existen autos cargados en el sistema\n");
            system("pause");
        }
    }
    return retorno;
}
