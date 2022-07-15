#include "color.h"


int idColores[5]= {5000,5001,5002,5003,5004};
char colores[5][20]= {"Negro",
                      "Rojo",
                      "verde",
                      "Blanco",
                      "Azul"
                     };

int hardcodearColores(eColor listaColores[], int tamColores)
{
    int retorno=0;
    if(listaColores!=NULL && tamColores >0)
    {
        for(int i=0; i<tamColores; i++)
        {
            listaColores[i].id=idColores[i];
            strcpy(listaColores[i].descripcion, colores[i]);
        }
        retorno=1;
    }
    return retorno;
}


int menuIngresarColor(int* id)
{
    int seguir=1;
    int retorno=0;
    int auxId;
    do
    {
        system("cls");
        printf("\n                      ****************************                      \n");
        printf("                      ****** COLORES ******                     \n");
        printf("                      ****************************                     \n\n");
        printf("1. NEGRO\n");
        printf("2. ROJO\n");
        printf("3. VERDE\n");
        printf("4. BLANCO\n");
        printf("5. AZUL\n\n");
        printf("INGRESE OPCION: ");
        scanf("%d", &auxId);
        fflush(stdin);
        if(auxId==1)
        {
            *id=5000;
            seguir=0;
            retorno=1;
        }
        else if(auxId ==2)
        {
            *id=5001;
            seguir=0;
            retorno=1;
        }
        else if(auxId ==3)
        {
            *id=5002;
            seguir=0;
            retorno=1;
        }
        else if(auxId==4)
        {
            *id=5003;
            seguir=0;
            retorno=1;
        }
        else if(auxId==5)
        {
            *id=5004;
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

int cargarDescripcionColorId(eColor listaColores[], int tamColores,int id, char descripcion[])
{
    int retorno=0;
    if(listaColores!=NULL && tamColores>0 && descripcion!=NULL)
    {
        for(int i=0; i<tamColores; i++)
        {
            if(listaColores[i].id== id)
            {
                strcpy(descripcion, listaColores[i].descripcion);
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
