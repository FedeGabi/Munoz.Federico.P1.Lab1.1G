#include "marca.h"

int idMarcas[5]= {1000,1001,1002,1003,1004};
char marcas[5][20]= {"Fiat",
                     "Renault",
                     "Peugeot",
                     "Ford",
                     "chevrolet"
                    };

int hardcodearMarcas(eMarca listaMarcas[], int tamMarcas)
{
    int retorno=0;
    if(listaMarcas!=NULL && tamMarcas >0)
    {
        for(int i=0; i<tamMarcas; i++)
        {
            listaMarcas[i].id=idMarcas[i];
            strcpy(listaMarcas[i].descripcion, marcas[i]);
        }
        retorno=1;
    }
    return retorno;
}


int menuIngresarMarca(int* id)
{
    int seguir=1;
    int retorno=0;
    int auxId;
    do
    {
        system("cls");
        printf("\n                      ****************************                      \n");
        printf("                      ****** MARCAS ******                     \n");
        printf("                      ****************************                     \n\n");
        printf("1. FIAT\n");
        printf("2. RENAULT\n");
        printf("3. PEUGEOT\n");
        printf("4. FORD\n");
        printf("5. CHEVROLET\n\n");
        printf("INGRESE OPCION: ");
        scanf("%d", &auxId);
        fflush(stdin);
        if(auxId==1)
        {
            *id=1000;
            seguir=0;
            retorno=1;
        }
        else if(auxId ==2)
        {
            *id=1001;
            seguir=0;
            retorno=1;
        }
        else if(auxId ==3)
        {
            *id=1002;
            seguir=0;
            retorno=1;
        }
        else if(auxId==4)
        {
            *id=1003;
            seguir=0;
            retorno=1;
        }
        else if(auxId==5)
        {
            *id=1004;
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

int cargarDescripcionMarcaId(eMarca listaMarcas[], int tamMarcas,int id, char descripcion[])
{
    int retorno=0;
    if(listaMarcas!=NULL && tamMarcas>0 && descripcion!=NULL)
    {
        for(int i=0; i<tamMarcas; i++)
        {
            if(listaMarcas[i].id== id)
            {
                strcpy(descripcion, listaMarcas[i].descripcion);
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
