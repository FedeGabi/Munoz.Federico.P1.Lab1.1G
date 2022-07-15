#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "trabajo.h"
#include "servicio.h"
#include "cliente.h"
#include "marca.h"
#include "color.h"
#include "auto.h"
int mostrarTrabajosFecha(eTrabajo listaTrabajos[], int tamTrabajos, eServicio listaServicios[], int tamServicios);

int marcaMasElegidaCliente(eAuto listaAutos[], int tamAutos, eMarca listaMarcas[], int tamMarcas);

int contarAutosColorMarca(eAuto listaAutos[], eColor listaColores[], eMarca listaMarcas[], eCliente listaClientes[], int tamClientes, int tamAutos, int tamColores, int tamMarcas);

int mostrarListaOrdenadaPorCaja(eAuto listaAutos[], int tamAutos, eMarca listaMarcas[], eColor listaColores[], eCliente listaClientes[], int tamClientes, int tamMarca, int tamColor);

int calcularPorcentajeCajas(eAuto listaAutos[], int tamAutos);

int mostrarAutosColor(eAuto listaAutos[], int tamAutos, eColor listaColores[], eMarca listaMarcas[], eCliente listaClientes[], int tamClientes, int tamColor, int tamMarca);

int mostrarAutosMarca(eAuto listaAutos[], int tamAutos, eColor listaColores[], eMarca listaMarcas[], eCliente listaClientes[], int tamClientes, int tamColor, int tamMarca);

int mostrarServicios(eTrabajo listaTrabajos[], int tamTrabajos, eServicio listaServicios[], int tamServicios);

#endif // INFORMES_H_INCLUDED
