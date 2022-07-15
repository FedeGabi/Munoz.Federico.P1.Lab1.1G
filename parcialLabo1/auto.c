
#include "auto.h"

int idsMarcas[20]= {1001,1002,1001,1001,1000,1000,1004,1003,1004,
                    1001,1000,1003,1001,1004,1003,1002,1002,1004,1000,1002
                   };
int idsColores[20]= {5002,5000,5001,5001,5000,5000,5004,5003,5001,
                     5002,5000,5003,5001,5003,5004,5002,5002,5003,5001,5002
                    };
char cajas[20]= {'m','a','m', 'a', 'm', 'a', 'm', 'a', 'a', 'm', 'm', 'a', 'm', 'a', 'm', 'm', 'a', 'm', 'm', 'a'};


int hardcodearAutos(eAuto listaAutos[], int tamAutos, eCliente listaClientes[],int tamClientes, int cant, int* nextId)
{
    if(listaAutos!=NULL && nextId!=NULL && listaClientes!=NULL && tamAutos >0 && cant >0 && cant <tamAutos && tamClientes>0)
    {
        for(int i=0; i<cant; i++)
        {
            listaAutos[i].idMarca=idsMarcas[i];
            listaAutos[i].idColor=idsColores[i];
            listaAutos[i].idCliente=listaClientes[i].id;
            listaAutos[i].caja=cajas[i];
            listaAutos[i].id=*nextId;
            (*nextId)++;
            listaAutos[i].isEmpty=0;
        }
    }
    return 0;
}





int inicializarListaAutos(eAuto listaAutos[],int tamAutos)
{
    int retorno=0;
    if(listaAutos!=NULL)
    {
        for(int i=0; i<tamAutos; i++)
        {
            listaAutos[i].isEmpty=1;
        }
        retorno=1;
    }
    return retorno;
}

int ingresarCaja(char* caja)
{
    int seguir=1;
    int retorno=0;
    char auxCaja;
    if(caja!=NULL)
    {
        do
        {
            system("cls");
            printf("ingresar caja: ");
            auxCaja=getchar();
            if(tolower(auxCaja)== 'm' || tolower(auxCaja)== 'a')
            {
                *caja=auxCaja;
                seguir=0;
                retorno=1;
            }
        }
        while(seguir==1);
    }
    return retorno;
}

int buscarPrimerVacio(eAuto listaAutos[], int tamAutos)
{
    int indice=-1;
    if(listaAutos!=NULL && tamAutos>0)
    {
        for(int i=0; i<tamAutos; i++)
        {
            if(listaAutos[i].isEmpty==1)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int buscarAutoId(eAuto listaAutos[], int tamAutos, int id)
{
    int indice=-1;
    if(listaAutos!=NULL && tamAutos>0 && id>0)
    {
        for(int i=0; i<tamAutos; i++)
        {
            if(listaAutos[i].id== id && listaAutos[i].isEmpty==0)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int altaAuto(eAuto listaAutos[], int tamAutos, eMarca listaMarcas[], int tamMarcas, eColor listaColores[], int tamColores, eCliente listaClientes[], int tamClientes, int* idNext, int* idNextCliente)
{
    int retorno=0;
    if(listaAutos!=NULL && listaColores!=NULL && listaMarcas!=NULL
            && tamAutos>0 && tamColores >0 && tamMarcas >0)
    {
        int indice= buscarPrimerVacio(listaAutos, tamAutos);
        if(indice!=-1)
        {
            int auxIdMarca;
            int auxIdColor;
            char auxCaja;

            if(menuIngresarMarca(&auxIdMarca) &&
                    menuIngresarColor(&auxIdColor) &&
                    ingresarCaja(&auxCaja) &&
                    ingresarCliente(listaClientes, tamClientes, idNextCliente))
            {
                listaAutos[indice].idMarca=auxIdMarca;
                listaAutos[indice].idColor=auxIdColor;
                listaAutos[indice].idCliente=(*idNextCliente)-1;
                listaAutos[indice].caja=auxCaja;
                listaAutos[indice].id=*idNext;
                (*idNext)++;
                listaAutos[indice].isEmpty=0;
                retorno=1;
                printf("\nAlta de auto exitosa!\n");
            }
            else
            {
                system("cls");
                printf("\nAlta cancelada\n");
            }
        }
        else
        {
            system("cls");
            printf("\nLa lista de autos esta llena\n");
        }
    }
    system("pause");
    return retorno;
}

int listarAutos(eAuto listaAutos[], int tamAutos, eMarca listaMarcas[], eColor listaColores[], eCliente listaClientes[], int tamClientes, int tamColores, int tamMarcas)
{
    system("cls");
    int retorno=0;
    if(listaAutos!=NULL && tamAutos>0 && listaMarcas!=NULL && tamMarcas>0 && listaColores != NULL && tamColores>0)
    {
        printf("ID       MARCA       COLOR   CAJA    DUENIO\n");
        printf("-------------------------------------------\n\n");
        for(int i=0; i<tamAutos; i++)
        {
            if(listaAutos[i].isEmpty==0 && listaClientes[i].isEmpty==0)
            {
                mostrarAuto(listaAutos[i], listaMarcas, listaColores, listaClientes, tamClientes, tamColores, tamMarcas);
            }
        }
        retorno=1;
    }
    return retorno;
}

void mostrarAuto(eAuto vehiculo, eMarca listaMarcas[], eColor listaColores[], eCliente listaCliente[], int tamClientes, int tamColores, int tamMarcas)
{
    char color[20];
    char marca[20];
    char nombreDuenio[20];
    cargarDescripcionColorId(listaColores, tamColores, vehiculo.idColor, color);
    cargarDescripcionMarcaId(listaMarcas, tamMarcas, vehiculo.idMarca, marca);
    cargarNombreClienteId(listaCliente, tamClientes, vehiculo.idCliente, nombreDuenio);
    printf("%d %10s %10s %5c  %10s\n", vehiculo.id, marca, color, vehiculo.caja, nombreDuenio);
}

int eliminarAuto(eAuto listaAutos[], int tamAutos, eMarca listaMarcas[], int tamMarcas, eColor listaColores[], int tamColores, eCliente listaClientes[], int tamClientes)
{
    int retorno=0;
    int indice=-1;
    int seguir=1;
    int id;
    int opcion;
    if(listaAutos!=NULL && tamAutos>0)
    {
        do
        {
            listarAutos(listaAutos, tamAutos, listaMarcas, listaColores, listaClientes, tamClientes, tamColores, tamMarcas);
            printf("\ningrese id: ");
            scanf("%d", &id);
            indice=buscarAutoId(listaAutos, tamAutos, id);
            if(indice!=-1)
            {
                mostrarAuto(listaAutos[indice], listaMarcas, listaColores, listaClientes, tamClientes, tamColores, tamMarcas);
                opcion=confirmar("\n Eliminar el auto? (s o n): ");
                if(opcion==1)
                {
                    listaAutos[indice].isEmpty=1;
                    retorno=1;
                    system("cls");
                    printf("\n BAJA EXITOSA\n");
                    system("pause");
                    seguir=0;

                }
                else
                {
                    system("cls");
                    printf("\n Baja cancelada\n");
                    seguir=0;
                    system("pause");
                }
            }
            else
            {
                system("cls");
                seguir=confirmar("\n El ID ingresado no existe, desea volver a ingresar?(s o n): ");
            }
        }
        while(seguir==1);
    }
    else
    {
        system("cls");
        printf("\n no hay autos cargados");
        system("pause");
    }
    return retorno;
}


int modificarAuto(eAuto listaAutos[], eMarca listaMarcas[], eColor listaColores[], eCliente listaClientes[], int tamClientes, int tamAutos, int tamMarcas, int tamColores)
{
    int retorno=0;
    if(listaAutos!=NULL && listaMarcas!=NULL && listaColores!=NULL && tamAutos>0 && tamColores>0 && tamMarcas>0)
    {
        int idAuto;
        int indice=-1;
        int seguir=1;
        int opcion;
        char letra;
        int auxIdMarca;
        int auxIdColor;

        do
        {
            listarAutos(listaAutos, tamAutos, listaMarcas, listaColores, listaClientes, tamClientes, tamColores, tamMarcas);
            printf("\ningrese id: ");
            scanf("%d", &idAuto);
            indice=buscarAutoId(listaAutos, tamAutos, idAuto);
            if(indice!=-1)
            {
                mostrarAuto(listaAutos[indice], listaMarcas, listaColores,listaClientes,tamClientes, tamColores, tamMarcas);
                opcion=confirmar("\n Modificar auto? (s o n): ");
                if(opcion==1)
                {
                    seguir=0;
                    letra=mostrarMenuModificar();
                    if(letra=='a')
                    {
                        if(menuIngresarMarca(&auxIdMarca))
                        {
                            listaAutos[indice].idMarca=auxIdMarca;
                            system("cls");
                            printf("\n Modificacion Exitosa\n");
                            system("pause");
                        }
                    }
                    else if(letra =='b')
                    {
                        if(menuIngresarColor(&auxIdColor))
                        {
                            listaAutos[indice].idColor=auxIdColor;
                            system("cls");
                            printf("\n Modificacion exitosa\n");
                            system("pause");
                        }
                    }
                }
                else
                {
                    system("cls");
                    printf("\n Modificacion cancelada\n");
                    seguir=0;
                    system("pause");
                }
                retorno=1;
            }
            else
            {
                system("cls");
                seguir=confirmar("\n El ID ingresado no existe, desea volver a ingresar?(s o n): ");
            }
        }
        while(seguir==1);
    }
    return retorno;
}

int isNotEmpty( eAuto listaAutos[], int tamAutos)
{
    int retorno=0;
    if(listaAutos!=NULL && tamAutos>0)
    {
        for(int i=0; i<tamAutos; i++)
        {
            if(listaAutos[i].isEmpty==0)
            {
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}


int menuIngresarAuto(eAuto listaAutos[], int tamAutos, eColor listaColores[], int tamColores, eMarca listaMarcas[], int tamMarcas, eCliente listaClientes[], int tamClientes)
{
    int idAuto=0;
    int seguir =1;
    if(isNotEmpty(listaAutos, tamAutos))
    {
        listarAutos(listaAutos, tamAutos, listaMarcas, listaColores, listaClientes, tamClientes, tamColores, tamMarcas);
        do
        {
            printf("ingrese id auto: ");
            scanf("%d", &idAuto);
            if(buscarAutoId(listaAutos, tamAutos, idAuto)!=-1)
            {
                seguir=0;
            }
            else
            {
                idAuto=0;
                seguir=confirmar("\nId invalido, desea volver a ingresar? (s o n): ");
            }
        }
        while(seguir==1);
    }
    else
    {
        printf("\n no hay autos cargados en el sistema\n");
    }

    return idAuto;
}


