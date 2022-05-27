#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "input.h"
#include "auto.h"
#include "trabajo.h"
#include "color.h"
#include "servicio.h"

#define TAM_MARCAS 5
#define TAM_COLORES 5
#define TAM_SERVICIO 4

#define TAM_AUTOS 30
#define TAM_TRABAJOS 30
#define TAM_CLIENTES 30

int main()
{
    eAuto autos[TAM_AUTOS];
    eTrabajo trabajos[TAM_TRABAJOS];
    eCliente clientes[TAM_CLIENTES];
    int idNextAuto=30000;
    int idNextTrabajo=50000;
    int idNextCLiente=80000;
    inicializarAutos(autos, TAM_AUTOS);
    inicializarTrabajos(trabajos, TAM_TRABAJOS);
    inicializarClientes(clientes, TAM_CLIENTES);
    hardcodearAutos(autos, TAM_AUTOS, clientes, TAM_CLIENTES, &idNextAuto, &idNextCLiente, 20);
    hardcodearTrabajos(trabajos, TAM_TRABAJOS, &idNextTrabajo, 20);
    int auxOpcion;

    system("pause");

    eMarca marcas[TAM_MARCAS]=
    {
        {1000, "Ford"},
        {1001, "Peugeot"},
        {1002, "Renault"},
        {1003, "Fiat"},
        {1004, "Chevrolet"}
    };
    eColor colores[TAM_COLORES]=
    {
        {5000, "Verde"},
        {5001, "Rojo"},
        {5002, "Azul"},
        {5003, "Blanco"},
        {5004, "Negro"}
    };
    eServicio servicios[TAM_SERVICIO]=
    {
        {20000, "Lavado", 450},
        {20001, "Pulido", 500},
        {20002, "Encerado", 600},
        {20003, "Completo", 900}
    };



    for(int i=0; i<TAM_AUTOS; i++)
    {
        if(autos[i].isEmpty==0)
        {
            char auxNombre[20];
            char auxColor[20];
            char auxMarca[20];
            cargarDescripcionCliente(clientes, auxNombre, autos[i].idCliente, TAM_CLIENTES);
            cargarDescripcionColor(colores, auxColor, autos[i].idColor, TAM_COLORES);
            cargarDescripcionMarca(marcas, auxMarca, autos[i].idMarca, TAM_MARCAS);
            printf("%d,  %d,  %d, %d, %10s, %10s, %10s,  %c\n", autos[i].id, autos[i].idMarca, autos[i].idColor, autos[i].idCliente,
                                                    auxMarca, auxColor,
                                                    clientes[i].nombre, clientes[i].sexo);
        }
    }
    system("pause");





    char seguir='s';
    do
    {
        switch(mostrarMenuPrincipal())
        {
        case 'a':
            altaAuto(autos, TAM_AUTOS, marcas, TAM_MARCAS, colores, TAM_COLORES, clientes, TAM_CLIENTES, &idNextAuto, &idNextCLiente);
            break;
        case 'b':
            modificarAuto(autos, marcas, colores, clientes, TAM_AUTOS, TAM_MARCAS, TAM_COLORES, TAM_CLIENTES);
            break;
        case 'c':
            bajaAuto(autos,marcas, colores,clientes, TAM_AUTOS, TAM_MARCAS, TAM_COLORES, TAM_CLIENTES);
            break;
        case 'd':

            ordenarAutosXmarcaYCajaDescripcion(autos, TAM_AUTOS, marcas, TAM_MARCAS);
            if(!listarAutos(autos, marcas, colores, clientes, TAM_AUTOS, TAM_MARCAS, TAM_COLORES, TAM_CLIENTES))
            {
                printf("\nNO EXISTEN AUTOS EN EL SISTEMA\n");
            }
            system("pause");
            break;
        case 'e':
            auxOpcion=menuIngresarMarca(marcas, TAM_MARCAS);
            if(auxOpcion)
            {
                listarAutosXMarca(autos, marcas, colores, clientes, TAM_AUTOS, TAM_MARCAS, TAM_COLORES, TAM_CLIENTES, auxOpcion);
                system("pause");
                auxOpcion=0;
            }
            break;
        case 'f':
            auxOpcion=menuIngresarColor(colores, TAM_COLORES);
            if(auxOpcion)
            {
                listarAutosXColor(autos, marcas, colores, clientes, TAM_AUTOS, TAM_MARCAS, TAM_COLORES, TAM_CLIENTES, auxOpcion);
                system("pause");
                auxOpcion=0;
            }
            break;
        case 'g':
            listarServicios(servicios, TAM_SERVICIO);
            system("pause");
            break;
        case 'h':
            altaTrabajo(trabajos, TAM_TRABAJOS, autos, TAM_AUTOS, servicios, TAM_SERVICIO, marcas, TAM_MARCAS, colores, TAM_COLORES,clientes, TAM_CLIENTES, &idNextTrabajo);
            break;
        case 'i':
            auxOpcion=menuIngresarServicio(servicios, TAM_SERVICIO);
            if(auxOpcion)
            {
                listarTrabajosxServicios(trabajos, servicios, TAM_TRABAJOS, TAM_SERVICIO, auxOpcion);
                system("pause");
                auxOpcion=0;
            }
            break;
         case 'j':
            if(informarPromediosAutosXCaja(autos, TAM_AUTOS))
            {

            }
            ordenarAutosXCajaDescripcion(autos, TAM_AUTOS);
            break;
        case 'k':
                ordenarAutosXCajaDescripcion(autos, TAM_AUTOS);
                listarAutos(autos, marcas, colores, clientes, TAM_AUTOS, TAM_MARCAS,TAM_COLORES, TAM_CLIENTES);
                system("pause");
            break;
            case 'l':
                if(!contarColorYMarca(autos,colores,marcas, TAM_AUTOS, TAM_COLORES, TAM_MARCAS))
                {
                    printf("\n No hay autos de esa marca y color\n");
                    system("pause");
                }
            break;
            case 'm':
                marcaMasElegida(autos, TAM_AUTOS, marcas, TAM_MARCAS);
            break;
        default:
            printf("OPCION INVALIDA\n");
            system("pause");
            break;
        }
    }
    while(seguir=='s');
    return 0;
}
