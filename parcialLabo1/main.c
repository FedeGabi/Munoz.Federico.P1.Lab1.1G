/*
ENTIDADES:
Fecha:
• dia
• mes
• año
Marca:
• id (comienza en 1000)
• descripción (máx 20 caracteres)
Color:
• id (comienza en 5000)
• nombreColor(máx 20 caracteres)
Auto:
• id
• idMarca Validar
• idColor Validar
• caja( “m” manual, “a” automática)
Servicio:
• id(comienza en 20000)
• descripción (máximo 25 caracteres)
• precio
Trabajo:
• id (autoincremental)
• idAuto (debe existir) Validar
• idServicio (debe existir) Validar
• fecha ( Validar día, mes y año )
DATOS PREVIOS:
Los arrays de marca, color y lavado deberán ser hardcodeados.
Marcas (Renault, Ford, Fiat, Chevrolet, Peugeot)
Colores (Negro, Blanco, Rojo, Verde, Azul)
Lavados (Lavado: $450, Pulido: $500, Encerado: $600, Completo: $900)
*/

#define TAM_AUTOS 20
#define TAM_TRABAJOS 20
#define TAM_CLIENTES 20
#define TAM_MARCAS 5
#define TAM_COLORES 5
#define TAM_SERVICIOS 4

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "marca.h"
#include "color.h"
#include "trabajo.h"
#include "auto.h"
#include "servicio.h"
#include "cliente.h"
#include "informes.h"

int main()
{
    int seguir=1;
    int idNextautos=1000;
    int idNextTrabajos=50000;
    int idNextClientes=100000;

    eAuto listaAutos[TAM_AUTOS];
    eColor listaColores[TAM_COLORES];
    eMarca listaMarcas[TAM_MARCAS];
    eTrabajo listaTrabajos[TAM_TRABAJOS];
    eServicio listaServicios[TAM_SERVICIOS];
    eCliente listaClientes[TAM_CLIENTES];

    hardcodearColores(listaColores, TAM_COLORES);
    hardcodearMarcas(listaMarcas, TAM_MARCAS);
    hardcodearServicios(listaServicios, TAM_SERVICIOS);

    inicializarListaAutos(listaAutos, TAM_AUTOS);
    inicializarListaTrabajos(listaTrabajos, TAM_TRABAJOS);
    inicializarListaCLientes(listaClientes, TAM_CLIENTES);

    hardcodearClientes(listaClientes, TAM_CLIENTES, 15, &idNextClientes);
    hardcodearAutos(listaAutos, TAM_AUTOS,listaClientes, TAM_CLIENTES, 15, &idNextautos);
    hardcodearTrabajos(listaTrabajos, listaAutos, TAM_TRABAJOS, TAM_AUTOS,15, &idNextTrabajos);

    do
    {
        switch(mostrarMenuPrincipal())
        {
        case 'a':
            altaAuto(listaAutos, TAM_AUTOS, listaMarcas, TAM_MARCAS, listaColores, TAM_COLORES,listaClientes,TAM_CLIENTES, &idNextautos, &idNextClientes);
            break;
        case 'b':
            if(isNotEmpty(listaAutos, TAM_AUTOS))
            {
                modificarAuto(listaAutos, listaMarcas, listaColores,listaClientes, TAM_CLIENTES, TAM_AUTOS, TAM_MARCAS, TAM_COLORES);
            }
            else
            {
                printf("\n No hay autos cargados en el sistema\n");
                system("pause");
            }
            break;
        case 'c':
            if(isNotEmpty(listaAutos, TAM_AUTOS))
            {
                eliminarAuto(listaAutos, TAM_AUTOS, listaMarcas, TAM_MARCAS, listaColores, TAM_COLORES, listaClientes, TAM_CLIENTES);
            }
            else
            {
                printf("\n No hay autos cargados en el sistema\n");
                system("pause");
            }
            break;
        case 'd':
            if(isNotEmpty(listaAutos, TAM_AUTOS))
            {
                listarAutos(listaAutos, TAM_AUTOS, listaMarcas, listaColores,listaClientes, TAM_CLIENTES, TAM_COLORES, TAM_MARCAS);
            }
            else
            {
                printf("\n No hay autos cargados en el sistema\n");
            }
            system("pause");
            break;
        case 'e':
            mostrarAutosMarca(listaAutos, TAM_AUTOS, listaColores, listaMarcas,listaClientes,TAM_CLIENTES, TAM_COLORES, TAM_MARCAS);
            system("pause");
            break;
        case 'f':
            mostrarAutosColor(listaAutos, TAM_AUTOS, listaColores, listaMarcas,listaClientes, TAM_CLIENTES, TAM_COLORES, TAM_MARCAS);
            system("pause");
            break;
        case 'g':
            mostrarServicios(listaTrabajos, TAM_TRABAJOS, listaServicios, TAM_SERVICIOS);
            system("pause");
            break;
        case 'h':
            altaTrabajo(listaTrabajos, listaServicios, listaAutos, listaColores, listaMarcas,listaClientes, TAM_TRABAJOS,TAM_SERVICIOS,TAM_AUTOS,TAM_COLORES,TAM_MARCAS,TAM_CLIENTES,&idNextTrabajos);
            break;
        case 'i':
            if(isNotEmptyTrabajo(listaTrabajos, TAM_TRABAJOS))
            {
                listarTrabajos(listaTrabajos, listaServicios, TAM_TRABAJOS, TAM_SERVICIOS);
            }
            else{
                printf("\nNo hay trabajos cargados en el sistema\n");
            }
            system("pause");
            break;
        case 'j':
            calcularPorcentajeCajas(listaAutos, TAM_AUTOS);
            break;
        case 'k':
                mostrarListaOrdenadaPorCaja(listaAutos, TAM_AUTOS, listaMarcas, listaColores, listaClientes, TAM_CLIENTES, TAM_MARCAS, TAM_COLORES);
                system("pause");
            break;
        case 'l':
            contarAutosColorMarca(listaAutos, listaColores, listaMarcas, listaClientes, TAM_CLIENTES, TAM_AUTOS, TAM_COLORES, TAM_MARCAS);
            break;
        case 'm':
            mostrarTrabajosFecha(listaTrabajos, TAM_TRABAJOS, listaServicios, TAM_SERVICIOS);
            break;
        case 'n':
            marcaMasElegidaCliente(listaAutos, TAM_AUTOS, listaMarcas, TAM_MARCAS);
            break;
        default:
            break;
        }
    }
    while(seguir==1);
    return 0;
}
