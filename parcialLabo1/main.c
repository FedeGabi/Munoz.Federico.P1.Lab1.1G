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

#define TAM_AUTOS 10
#define TAM_TRABAJOS 10

int main()
{
    eAuto autos[TAM_AUTOS];
    eTrabajo trabajos[TAM_TRABAJOS];
    int idNextAuto=30000;
    int idNextTrabajo=50000;
    inicializarAutos(autos, TAM_AUTOS);
    inicializarTrabajos(trabajos, TAM_TRABAJOS);

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
    char seguir='s';
    do
    {
        switch(mostrarMenuPrincipal())
        {
        case 'a':
            altaAuto(autos, TAM_AUTOS, marcas,TAM_MARCAS,colores,TAM_COLORES,&idNextAuto);
            break;
        case 'b':
            break;
        case 'c':
                bajaAuto(autos,marcas, colores, TAM_AUTOS, TAM_MARCAS, TAM_COLORES);
            break;
        case 'd':
            if(!listarAutos(autos, marcas, colores, TAM_AUTOS, TAM_MARCAS, TAM_COLORES))
            {
                printf("\nNO EXISTEN AUTOS EN EL SISTEMA\n");
            }
            system("pause");
            break;
        case 'e':
            listarMarcas(marcas, TAM_MARCAS);
            system("pause");
            break;
        case 'f':
            listarColores(colores, TAM_COLORES);
            system("pause");
            break;
        case 'g':
            break;
        case 'h':
            altaTrabajo(trabajos, TAM_TRABAJOS, autos, TAM_AUTOS, servicios, TAM_SERVICIO, marcas, TAM_MARCAS, colores, TAM_COLORES, &idNextTrabajo);
            break;
        case 'i':
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
