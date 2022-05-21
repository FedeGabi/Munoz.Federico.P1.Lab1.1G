#include "input.h"

int mostrarMenuPrincipal()
{
    system("cls");
    int opcion=0;
    printf("\n                      ****************************                      \n");
    printf("                      ******** ABM LAVADERO ********                     \n");
    printf("                      ****************************                     \n\n");
    printf("A. ALTA AUTO\n");
    printf("B. MODIFICAR AUTO\n");
    printf("C. BAJA AUTO\n");
    printf("D. LISTAR AUTOS\n");
    printf("E. LISTAR MARCAS\n");
    printf("F. LISTAR COLORES\n");
    printf("G. LISTAR SERVICIOS\n");
    printf("H. ALTA TRABAJO\n");
    printf("I. LISTAR TRABAJOS\n");
    printf("J. PEOMEDIO POR CAJA\n");
    printf("K. LISTAR POR CAJA\n");
    printf("L. CONTAR POR COLOR Y MARCA\n");
    fflush(stdin);
    opcion=getchar();
    opcion=tolower(opcion);
    return opcion;
}


int ingresarFloat(float *pFloat, char msj [], char msjError[], int intentos)
{
    int retorno = -1;
    if (pFloat != NULL && msj !=NULL && msjError != NULL && intentos>0)
    {
        float numero;
        int esNum;
        int i=0;
        do
        {
            printf("%s", msj);
            esNum = scanf("%f", &numero);
            fflush(stdin);
            if (numero < 0 || !esNum)
            {
                system("cls");
                printf("%s", msjError);
                system("pause");
                *pFloat = 0;
                retorno = -1;
            }
            else if (!numero)
            {
                *pFloat = 0;
                retorno = 0;
            }
            else
            {
                *pFloat = numero;
                retorno = 1;
                i=intentos;
            }
            i++;
        }
        while(i<intentos);
    }
    return retorno;
}

int ingresarInt(int *pInt, char msj [], char msjError[])
{
    int retorno = -1;
    if (pInt != NULL && msj !=NULL && msjError != NULL)
    {
        int numero;
        int esNum;
        int seguir=1;
        do
        {
            printf("%s", msj);
            esNum = scanf("%d", &numero);
            fflush(stdin);
            if (numero < 0 || !esNum)
            {
                system("cls");
                printf("%s", msjError);
                seguir=confirmar("Volver a intentar?...");
                *pInt = 0;
                retorno = -1;
            }
            else if (!numero)
            {
                *pInt = 0;
                retorno = 0;
            }
            else
            {
                *pInt = numero;
                retorno = 1;
                seguir=0;
            }
        }
        while(seguir==1);
    }
    return retorno;
}

int ingresarValidarCadena(char cadena[],int tamMin,int tamMax, char msj[], char msjError[], int intentos)
{
    int retorno=0;
    char aux[400];
    int i=0;
    if(cadena != NULL && tamMin >0 && tamMax >0 && msj != NULL && msjError != NULL && intentos >0)
    {
        do
        {
            printf("%s", msj);
            fflush(stdin);
            gets(aux);
            if(strlen(aux)>tamMax || strlen(aux)<tamMin)
            {
                printf("%s", msjError);
                system("pause");
                retorno=0;
            }
            else
            {
                strcpy(cadena, aux);
                retorno=1;
                break;
            }
            i++;
        }
        while(i<intentos);
    }
    return retorno;
}


int ingresarValidarNombre(char cadena[],int tamMin ,int tamMax, char msj[], char msjError[])
{
    int retorno=0;
    char aux[400];
    int seguir=1;
    if(cadena != NULL && tamMin >0 && tamMax >0 && msj != NULL && msjError != NULL)
    {
        do
        { system("cls");
            printf("%s", msj);
            fflush(stdin);
            gets(aux);
            if(validarLetras(aux)==0)
            {
                system("cls");
                printf("\nNO SE ADMITEN VALORES NUMERICOS\n");
                seguir=confirmar("\nDESEA VOLVER A INGRESAR? (S o N): ");
                retorno=0;
            }
            else if(strlen(aux)>tamMax || strlen(aux)<tamMin)
            {
                printf("\nDEBE TENER UNA EXTENCION MAYOR A %d Y MENOR A %d LETRAS", tamMin, tamMax);
                seguir=confirmar("\nDESEA VOLVER A INGRESAR? (S o N): ");
                retorno=0;
            }
            else{
                strcpy(cadena, aux);
                retorno=1;
                seguir=0;
                break;
            }
        }
        while(seguir);
    }
    return retorno;
}



int ingresarValidarCaracter(char msj[], char msjError[], char char1, char char2, char* pResultado)
{
    int retorno=0;
    char caracter;
    int seguir=1;
    if(msj != NULL && msjError != NULL)
    {
        do
        {
            system("cls");
            printf("%s",msj);
            fflush(stdin);
            caracter=getchar();
            if(tolower(caracter)==tolower(char1) || tolower(caracter)==tolower(char2))
            {

                *pResultado=caracter;
                seguir=0;
                retorno=1;
            }
            else
            {
                system("cls");
                printf("%s\n", msjError);
                seguir=confirmar("intentar nuevamente? (s o n)\n");
            }
        }
        while(seguir);
    }
    return retorno;
}


int validarLetras(char cadena[])
{
    int retorno=-1;
    if(cadena!= NULL)
    {
        retorno=1;
        for(int i=0; i<strlen(cadena); i++)
        {
            if(tolower(cadena[i]) < 97 || tolower(cadena[i]) >122)
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int confirmar(char msj[])
{
    int respuesta;
    char opcion;
    printf("%s", msj);
    fflush(stdin);
    opcion=getchar();
    if(tolower(opcion)=='s')
    {
        respuesta=1;
    }
    else
    {
        respuesta=0;
    }
    return respuesta;
}
