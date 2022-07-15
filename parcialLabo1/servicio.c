#include "servicio.h"


int idServicios[4]= {20000,20001,20002,20003};
char servicios[4][20]= {"Lavado", "Pulido", "Encerado", "Completo"};
float precios[4]= {450, 500, 600, 900};

int hardcodearServicios(eServicio listaServicios[], int tamServicio)
{
    int retorno=0;
    if(listaServicios!=NULL && tamServicio >0)
    {
        for(int i=0; i<tamServicio; i++)
        {
            listaServicios[i].id=idServicios[i];
            strcpy(listaServicios[i].descripcion, servicios[i]);
            listaServicios[i].precio=precios[i];
        }
        retorno=1;
    }
    return retorno;
}


int menuIngresarServicios(int* id)
{
    int seguir=1;
    int auxId;
    int retorno=0;
    do
    {
        system("cls");
        printf("\n                      ****************************                      \n");
        printf("                      ****** SERVICIOS ******                     \n");
        printf("                      ****************************                     \n\n");
        printf("1. LAVADO - $450\n");
        printf("2. PULIDO - $500\n");
        printf("3. ENCERADO - $600\n");
        printf("4. COMPLETO - $900\n");
        printf("INGRESE OPCION: ");
        scanf("%d", &auxId);
        fflush(stdin);
        if(auxId==1)
        {
            *id=20000;
            seguir=0;
            retorno=1;
        }
        else if(auxId ==2)
        {
            *id=20001;
            seguir=0;
            retorno=1;
        }
        else if(auxId ==3)
        {
            *id=20002;
            seguir=0;
            retorno=1;
        }
        else if(auxId==4)
        {
            *id=20003;
            seguir=0;
            retorno=1;
        }
        else if(auxId==5)
        {
            *id=20004;
            seguir=0;
            retorno=1;
        }
        else
        {
            seguir=confirmar("\n Opcion incorrecta. Volver a ingresar? (s o n): ");
        }
    }
    while(seguir==1);
    return retorno;
}

int cargarDescripcionServicioId(eServicio listaServicios[], int tamServicio,int id, char descripcion[])
{
    int retorno=0;
    if(listaServicios!=NULL && tamServicio>0 && descripcion!=NULL)
    {
        for(int i=0; i<tamServicio; i++)
        {
            if(listaServicios[i].id== id)
            {
                strcpy(descripcion, listaServicios[i].descripcion);
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
