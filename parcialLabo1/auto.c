#include "auto.h"

int marcas[20]= {1000,1000,1001,1000,1002,1000,1000,1003,1000,1001,1003,1001,1003,1000,1000,1002,1002,1003,1002,1003};
int colores[20]= {5000,5000,5001,5003,5002,5001,5000,5002,5004,5001,5001,5001,5003,5000,5004,5002,5000,5000,5002,5002};
char cajas[20]= {'m', 'm','a','a','a','a','a','a','a','a','a','m','m','a','a','a','m','a','m','a'};
char nombres[20][20]= {"roberta", "pablito", "noemi", "marcos", "ruben", "facundo", "melisa", "carla", "hector", "silvana",
"estefania", "pedrito", "noelia", "marcos", "ruben", "facundo", "melisa", "carla", "hector", "silvana"};

char sexos[20]= {'f','m','f','m','m','m','f','f','m','f','f','m','f','m','m','m','f','f','m','f'};

int hardcodearAutos(eAuto autos[], int tamAutos, eCliente clientes[], int tamClientes, int* pidNext, int* idNextCliente, int cant)
{
    int retorno=0;
    if(autos!= NULL && tamAutos>0 && cant<= tamAutos)
    {
        for(int i=0; i<cant; i++)
        {
            autos[i].idMarca=marcas[i];
            autos[i].idColor=colores[i];
            strcpy(clientes[i].nombre, nombres[i]);
            clientes[i].sexo=sexos[i];
            clientes[i].id=*idNextCliente;
            autos[i].idCliente=*idNextCliente;
            autos[i].caja=cajas[i];
            autos[i].id=*pidNext;
            autos[i].isEmpty=0;
            (*idNextCliente)++;
            (*pidNext)++;
        }
        retorno=1;
    }
    return retorno;
}

int menuModificarAutos()
{
    system("cls");
    int opcion=0;
    printf("1. MODIFICAR COLOR\n");
    printf("2. MODIFICAR CAJA\n");
    printf("3. MENU PRINCIPAL\n");
    scanf("%d", &opcion);
    fflush(stdin);
    return opcion;
}

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
        retorno=1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty==0  && vec[i].id == id)
            {
                *indice = i;
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

int buscarPrimerLleno(eAuto vec[], int tam)
{
    int retorno = 0;
    if( vec != NULL && tam > 0 )
    {
        for(int i=0; i < tam; i++)
        {
            if(!vec[i].isEmpty)
            {
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}


int menuIngresarAuto(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], eCliente clientes[], int tamColores, int tamClientes)
{
    int opcion=0;
    int seguir=0;
    do
    {
        system("cls");
        if(listarAutos(autos, marcas, colores, clientes, tamAutos, tamMarcas, tamColores, tamClientes))
        {
            printf("\nIngrese ID Micro: ");
            scanf("%d", &opcion);
            if(validarAutoId(autos, tamAutos, opcion))
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

int altaAuto(eAuto vec[], int tam, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamCLientes,  int* pIdNext, int* idNextCliente)
{
    int retorno=0;
    if(vec != NULL && tam>0 && marcas != NULL && tamMarcas>0 && colores != NULL && tamColores>0 && pIdNext!= NULL)
    {
        eAuto auxAuto;
        eCliente auxCliente;
        int contadorIngresos=0;
        int indice;
        int auxInt=0;
        char auxChar;
        indice=buscarPrimerVacio(vec, tam);
        if(indice>=0)
        {
            if(menuIngresarCliente(auxCliente, tamCLientes))
            {
                contadorIngresos++;
                auxAuto.idMarca=menuIngresarMarca(marcas,tamMarcas);
                if(auxAuto.idMarca)
                {
                    contadorIngresos++;
                    auxAuto.idColor=menuIngresarColor(colores, tamColores);
                    if(auxAuto.idColor)
                    {
                        contadorIngresos++;
                        if(ingresarValidarCaracter("\nIngrese caja (m o a): ", "\n Error, valor invalido...", 'a', 'm', &auxChar))
                        {
                            contadorIngresos++;
                            auxAuto.caja=auxInt;
                            auxAuto.caja=auxChar;
                            auxAuto.isEmpty=0;
                        }
                    }
                }

            }
            if(contadorIngresos==4)
            {
                vec[indice]=auxAuto;
                clientes[indice]=auxCliente;
                clientes[indice].id= *idNextCliente;
                vec[indice].id=*pIdNext;
                (*idNextCliente)++;
                (*pIdNext)++;
                system("cls");
                printf("\nALTA DE AUTO EXITOSA!\n");
                retorno=1;
            }
            else
            {
                system("cls");
                printf("\nCARGA DE AUTO CANCELADA...\n");
            }
        }
        else
        {
            system("cls");
            printf("\nNO HAY LUGAR...");
        }
    }
    system("pause");
    return retorno;
}

int bajaAuto(eAuto autos[], eMarca marcas[], eColor colores[], eCliente clientes[], int tamAutos, int tamMarcas, int tamColores, int tamClientes)
{
    int retorno = 0;
    int indice;
    int id;
    char confirma;
    if( autos != NULL && tamAutos > 0 && marcas != NULL && tamMarcas > 0 && colores != NULL && tamColores >0)
    {
        if(listarAutos(autos, marcas, colores, clientes, tamAutos, tamMarcas, tamColores, tamClientes))
        {
            ingresarInt(&id, "\nINGRESE ID: ", "\nNO SE ADMITEN CARACTERES O NUMEROS NEGATIVOS\n");
            if( buscarAutoId(autos, tamAutos, id, &indice))
            {
                if(indice == -1)
                {
                    system("cls");
                    printf("NO EXISTE AUTO CON ID: %d EN EL SISTEMA\n", id);
                    system("pause");
                }
                else
                {
                    system("cls");
                    mostrarAuto(autos[indice], marcas, colores, clientes, tamMarcas, tamColores, tamClientes);
                    printf("Confirma baja?: ");
                    fflush(stdin);
                    scanf("%c", &confirma);

                    if(confirma == 's' || confirma == 'S')
                    {
                        autos[indice].isEmpty = 1;
                        system("cls");
                        printf("Baja exitosa!!!\n");
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        printf("Baja cancelada por el usuario\n");
                        system("pause");
                    }
                }
                retorno = 1;
            }
        }
        else
        {
            system("cls");
            printf("\nNO HAY AUTOS CARGADOS EN EL SISTEMA\n");
            system("pause");
        }
    }
    return retorno;
}

int modificarAuto(eAuto autos[], eMarca marcas[], eColor colores[], eCliente clientes[], int tamAutos, int tamMarcas, int tamColores, int tamClientes)
{
    int retorno = 0;
    int indice;
    int id;
    int auxInt;
    char confirma;
    if( autos != NULL && tamAutos > 0 && marcas != NULL && tamMarcas > 0 && colores != NULL && tamColores >0)
    {
        if(listarAutos(autos,marcas, colores, clientes, tamAutos, tamMarcas,tamColores, tamClientes))
        {
            ingresarInt(&id, "Ingrese ID: ", "\nError, no se admiten caracteres y numeros negativos\n");
            if(buscarAutoId(autos, tamAutos, id, &indice))
            {
                if(indice == -1)
                {
                    system("cls");
                    printf("\nNO EXISTE AUTO CON ID %d EN EL SISTEMA\n", id);
                }
                else
                {
                    system("cls");
                    mostrarAuto(autos[indice],marcas, colores, clientes, tamMarcas, tamColores, tamClientes);
                    printf("\nmodificar?: \n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    if(tolower(confirma) == 's')
                    {
                        do
                        {
                            switch(menuModificarAutos())
                            {
                            case 1:
                                auxInt=menuIngresarColor(colores, tamColores);
                                if(auxInt)
                                {
                                    autos[indice].idColor=auxInt;
                                    auxInt=0;
                                    system("cls");
                                    printf("\nMODIFICACION EXITOSA\n");
                                    system("pause");
                                }
                                break;
                            case 2:
                                auxInt=menuIngresarMarca(marcas, tamMarcas);
                                if(auxInt)
                                {
                                    autos[indice].idMarca=auxInt;
                                    auxInt=0;
                                    system("cls");
                                    printf("\nMODIFICACION EXITOSA\n");
                                    system("pause");
                                }
                                break;
                            case 3:
                                confirma='n';
                                break;
                            default:
                                printf("\nOPCION INVALIDA\n");
                                system("pause");
                            }
                        }
                        while(confirma=='s');
                    }
                    else
                    {
                        system("cls");
                        printf("\nModificacion cancelada por el usuario\n");
                        system("pause");
                    }
                }
            }

        }
        else
        {
            system("cls");
            printf("\nNO HAY AUTOS CARGADOS EN EL SISTEMA\n");
            system("pause");
        }
        retorno = 1;
    }
    return retorno;
}







int listarAutos(eAuto autos[], eMarca marcas[], eColor colores[], eCliente clientes[], int tam, int tamMarcas, int tamColores, int tamClientes)
{
    int retorno=0;
    int flag=1;
    if(autos != NULL && marcas != NULL && colores != NULL && tam>0 && tamMarcas >0 && tamColores>0)
    {
        system("cls");
       printf("------------------------------------------------------------------\n");
        printf("--------------    LISTA AUTOS     -------------------------------\n");
        printf("-----------------------------------------------------------------\n");
        printf("ID          MARCA         COLOR          CAJA         CLIENTE     SEXO\n");
        printf("--------------------------------------------------------------------\n\n");
        for(int i=0 ; i<tam ; i++)
        {
            if(autos[i].isEmpty==0)
            {
                mostrarAuto(autos[i], marcas, colores,clientes, tamMarcas, tamColores, tamClientes);
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

int listarAutosXColor(eAuto autos[], eMarca marcas[], eColor colores[], eCliente clientes[], int tam, int tamMarcas, int tamColores, int tamClientes, int idColor)
{
    int retorno=0;
    int flag=1;
    if(autos != NULL && marcas != NULL && colores != NULL && tam>0 && tamMarcas >0 && tamColores>0)
    {
        char auxCadena[20];
        system("cls");
        printf("------------------------------------------------------------------\n");
        printf("--------------    LISTA AUTOS     -------------------------------\n");
        printf("-----------------------------------------------------------------\n");
        printf("ID          MARCA         COLOR          CAJA         CLIENTE     SEXO\n");
        printf("--------------------------------------------------------------------\n\n");
        for(int i=0 ; i<tam ; i++)
        {
            if(autos[i].isEmpty==0 && autos[i].idColor ==idColor)
            {
                mostrarAuto(autos[i], marcas, colores, clientes, tamMarcas, tamColores, tamClientes);
                flag=0;
                retorno=1;
            }
        }
        if(flag)
        {
            retorno=0;
            cargarDescripcionMarca(marcas, auxCadena, idColor, tamColores);
            printf("NO HAY AUTOS DEL COLOR %s CARGADOS EN EL SISTEMA\n", auxCadena );
        }
    }
    return retorno;
}

int listarAutosXMarca(eAuto autos[], eMarca marcas[], eColor colores[], eCliente clientes[], int tam, int tamMarcas, int tamColores,int tamClientes, int idMarca)
{
    int retorno=0;
    int flag=1;
    if(autos != NULL && marcas != NULL && colores != NULL && tam>0 && tamMarcas >0 && tamColores>0)
    {
        char auxCadena[20];
        system("cls");
        printf("------------------------------------------------------------------\n");
        printf("--------------    LISTA AUTOS     -------------------------------\n");
        printf("-----------------------------------------------------------------\n");
        printf("ID          MARCA         COLOR          CAJA         CLIENTE     SEXO\n");
        printf("--------------------------------------------------------------------\n\n");
        for(int i=0 ; i<tam ; i++)
        {
            if(autos[i].isEmpty==0 && autos[i].idMarca ==idMarca)
            {
                mostrarAuto(autos[i], marcas, colores, clientes, tamMarcas, tamColores, tamClientes);
                flag=0;
                retorno=1;
            }
        }
        if(flag)
        {
            retorno=0;
            cargarDescripcionMarca(marcas, auxCadena, idMarca, tamMarcas);
            printf("NO HAY AUTOS DE LA MARCA %s CARGADOs EN EL SISTEMA\n", auxCadena);
        }
    }
    return retorno;
}


void mostrarAuto(eAuto autos, eMarca marcas[], eColor colores[], eCliente clientes[], int tamMarcas, int tamColores, int tamClientes)
{
    char descMarca[20];
    char descColor[20];
    char cliente[20];
    cargarDescripcionCliente(clientes, cliente, autos.idCliente, tamClientes);
    cargarDescripcionMarca(marcas, descMarca, autos.idMarca, tamMarcas);
    cargarDescripcionColor(colores, descColor, autos.idColor, tamColores);
    printf("%d  |   %10s   |   %10s   |   %c  |   %10s   |   %c  \n", autos.id, descMarca, descColor, toupper(autos.caja), cliente, toupper(clientes->sexo));
}

int ordenarAutosXmarcaYCajaDescripcion(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas)
{
    int retorno=0;
    if(autos!= NULL && tamAutos>0 && marcas!= NULL && tamMarcas >0)
    {
        char descripcionI[20];
        char descripcionJ[20];
        if(buscarPrimerLleno(autos, tamAutos))
        {
            eAuto auxAuto;
            for(int i=0; i<tamAutos-1; i++)
            {
                for(int j=i+1; j<tamAutos; j++)
                {
                    cargarDescripcionMarca(marcas, descripcionI, autos[i].idMarca, tamMarcas);
                    cargarDescripcionMarca(marcas, descripcionJ, autos[j].idMarca, tamMarcas);
                    if(strcmp(descripcionI, descripcionJ)>0 ||
                            (strcmp(descripcionI, descripcionJ)==0 &&
                             tolower(autos[i].caja) > tolower(autos[j].caja)))
                    {
                        auxAuto=autos[i];
                        autos[i]= autos[j];
                        autos[j]=auxAuto;
                    }
                }
            }
        }
        retorno=1;
    }
    return retorno;
}

int buscarLleno(eAuto autos[], int tamAutos)
{
    int retorno=0;
    if(autos!=NULL && tamAutos>0)
    {
        for(int i=0; i<tamAutos; i++)
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

int informarPromediosAutosXCaja(eAuto autos[], int tamAutos)
{
    int retorno=0;
    if(autos!= NULL && tamAutos>0)
    {
        int contadorManual=0;
        int contadorAutomatico=0;
        int total=0;

        for(int i=0; i<tamAutos; i++)
        {
            if(autos[i].isEmpty==0 && autos[i].caja=='m')
            {
                contadorManual++;
                total++;
                retorno=1;
            }
            else if(autos[i].isEmpty==0 && autos[i].caja=='a')
            {
                contadorAutomatico++;
                total++;
                retorno=1;
            }
            retorno=0;
        }
        system("cls");
        printf("\nEL TOTAL DE LOS AUTOS ES: %d", total);
        printf("\nEL PROMEDIO DE LOS MANUAL ES: %.2f", (contadorManual*100/(float)total));
        printf("\nEL PROMEDIO DE LOS AUTOMATICCOS ES: %.2f\n", (contadorAutomatico*100/(float)total));
        system("pause");

    }
    return retorno;
}

int ordenarAutosXCajaDescripcion(eAuto autos[], int tamAutos)
{
    int retorno=0;
    if(autos!= NULL && tamAutos >0)
    {
        if(buscarPrimerLleno(autos, tamAutos))
        {
            eAuto auxAuto;
            for(int i=0; i<tamAutos-1; i++)
            {
                for(int j=i+1; j<tamAutos; j++)
                {
                    if(tolower(autos[i].caja) < tolower(autos[j].caja))
                    {
                        auxAuto=autos[i];
                        autos[i]= autos[j];
                        autos[j]=auxAuto;
                    }
                }
            }
        }
        retorno=1;
    }
    return retorno;
}

int contarColorYMarca(eAuto autos[], eColor colores[], eMarca marcas[],int tamAutos,int tamColores,int tamMarcas)
{
    int retorno=0;
    if(autos!=NULL && colores!=NULL && marcas!=NULL && tamAutos>0 && tamColores>0 && tamMarcas>0)
    {
        int idMarca;
        int idColor;
        char cadenaMarca[20];
        char cadenaColor[20];
        int contador=0;
        idColor=menuIngresarColor(colores, tamColores);
        idMarca=menuIngresarMarca(marcas, tamMarcas);
        if(idColor>0 && idMarca>0)
        {
            for(int i=0; i<tamAutos; i++)
            {

                if(autos[i].isEmpty ==0 &&
                   autos[i].idColor ==idColor &&
                   autos[i].idMarca ==idMarca )
                {
                    contador++;
                    retorno=1;
                }

            }
            cargarDescripcionColor(colores, cadenaColor, idColor, tamColores );
            cargarDescripcionMarca(marcas, cadenaMarca, idMarca, tamMarcas);
            printf("\nCANTIDAD DE AUTOS DE COLOR %s Y MARCA %s ES: %d\n", cadenaColor, cadenaMarca,contador );
            system("pause");
        }

    }
    return retorno;
}



int marcaMasElegida(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca)
{
    int todoOk = 0;
    int cantMarca[tamMarca];
    int flag = 1;
    int mayor;

    if( autos != NULL && tamAuto > 0 && marcas != NULL && tamMarca > 0)
    {
        for(int i=0; i < tamMarca; i++)
        {
            cantMarca[i] = 0;
        }

        for(int i=0; i < tamMarca; i++)
        {
            totalMarcas(autos, tamAuto, marcas, tamMarca, marcas[i].id, &cantMarca[i]);

        }

        for(int i=0; i < tamMarca; i++)
        {
            if(flag || cantMarca[i] > mayor)
            {
                mayor = cantMarca[i];
                flag = 0;
            }
        }

        system("cls");
        system("\n");
        printf("Marca mas elegidas con %d unidades es: ", mayor);

        for(int i=0; i < tamMarca; i++)
        {

            if(cantMarca[i] == mayor)
            {
                printf("%s\n", marcas[i].descripcion);
            }
        }
        system("pause");
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}






int totalMarcas(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, int idMarca, int* pTotal)
{

    int retorno = 0;
    int contMarcas = 0;

    if( autos != NULL && tamAutos > 0 && tamMarcas > 0 && pTotal != NULL)
    {
        for(int i=0; i < tamAutos; i++)
        {
            if( !autos[i].isEmpty && autos[i].idMarca == idMarca)
            {
                contMarcas++;
            }
        }

        *pTotal = contMarcas;

        retorno = 1;
    }
    return retorno;

}
