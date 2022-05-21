#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "marca.h"
#include "color.h"
#include "cliente.h"
typedef struct{
    int id;
    int idMarca;
    int idColor;
    int idCliente;
    char caja;
    int isEmpty;
}eAuto;

/** \brief muetra menu de opciones
 *
 * \return int retorna la opcion seleccionada
 *
 */
int menuModificarAutos();
/** \brief carga valores de manera automatica para realizar pruebas
 *
 * \param autos[] eAuto
 * \param tamAutos int
 * \param pidNext int*
 * \param cant int
 * \return int
 *
 */
int hardcodearAutos(eAuto autos[], int tamAutos, eCliente clientes[], int tamClientes, int* pidNext, int* idNextCliente, int cant);
/** \brief recibe un array de autos e inicializa los campos isEmpty en 1
 *
 * \param vec[] eAuto
 * \param tam int
 * \return int
 *
 */
int inicializarAutos(eAuto vec[], int tam);
/** \brief da de baja un auto de manera logica (cambia el campo isEmpty a 1)
 *
 * \param autos[] eAuto
 * \param marcas[] eMarca
 * \param colores[] eColor
 * \param tamAutos int
 * \param tamMarcas int
 * \param tamColores int
 * \return int
 *
 */
int bajaAuto(eAuto autos[], eMarca marcas[], eColor colores[], eCliente clientes[], int tamAutos, int tamMarcas, int tamColores, int tamClientes);
/** \brief valida la existencia de un id
 *
 * \param vec[] eAuto
 * \param tamAutos int
 * \param id int
 * \return int
 *
 */
int validarAutosId(eAuto vec[], int tamAutos, int id);
/** \brief busca un auto por id y devuelve el indice del array en el que se encuentra
 *
 * \param vec[] eAuto
 * \param tam int
 * \param id int
 * \param indice int*
 * \return int
 *
 */
int buscarAutoId(eAuto vec[], int tam, int id, int* indice);
/** \brief modifica los campos de un auto
 *
 * \param autos[] eAuto
 * \param marcas[] eMarca
 * \param colores[] eColor
 * \param tamAutos int
 * \param tamMarcas int
 * \param tamColores int
 * \return int
 *
 */
int modificarAuto(eAuto autos[], eMarca marcas[], eColor colores[], eCliente clientes[], int tamAutos, int tamMarcas, int tamColores, int tamClientes);
/** \brief busca el primer espacio vacio de un array y devuelve su indice
 *
 * \param vec[] eAuto
 * \param tam int
 * \return int
 *
 */
int buscarPrimerVacio(eAuto vec[], int tam);
/** \brief valida la existencia de al menos un campo ocupado
 *
 * \param autos[] eAuto
 * \param tamAutos int
 * \return int
 *
 */
int buscarLleno(eAuto autos[], int tamAutos);
/** \brief muestra una lista con autos existentes en el sistema
 *
 * \param vec[] eAuto
 * \param tamAutos int
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param colores[] eColor
 * \param tamColores int
 * \return int retorna la opcion seleccionada
 *
 */
int menuIngresarAuto(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], eCliente clientes[], int tamColores, int tamClientes);
/** \brief solicita los datos y da de alta un nuevo auto
 *
 * \param vec[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param colores[] eColor
 * \param tamColores int
 * \param pIdNext int*
 * \return int
 *
 */
int altaAuto(eAuto vec[], int tam, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamCLientes,  int* pIdNext, int* idNextCliente);
/** \brief muestra lista de autos
 *
 * \param autos[] eAuto
 * \param marcas[] eMarca
 * \param colores[] eColor
 * \param tam int
 * \param tamMarcas int
 * \param tamColores int
 * \return int
 *
 */
int listarAutos(eAuto autos[], eMarca marcas[], eColor colores[], eCliente clientes[], int tam, int tamMarcas, int tamColores, int tamClientes);
/** \brief muestra un solo auto
 *
 * \param autos eAuto
 * \param empresa[] eMarca
 * \param tipo[] eColor
 * \param tamMarcas int
 * \param tamColores int
 * \return void
 *
 */
void mostrarAuto(eAuto autos, eMarca marcas[], eColor colores[], eCliente clientes[20], int tamMarcas, int tamColores, int tamClientes);
/** \brief ordena el array por marca y por tipo de caja j
 *
 * \param autos[] eAuto
 * \param tamAutos int
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \return int
 *
 */
int ordenarAutosXmarcaYCajaDescripcion(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas);
/** \brief ordena array por color ingresado
 *
 * \param autos[] eAuto
 * \param marcas[] eMarca
 * \param colores[] eColor
 * \param tam int
 * \param tamMarcas int
 * \param tamColores int
 * \param idColor int
 * \return int
 *
 */
int listarAutosXColor(eAuto autos[], eMarca marcas[], eColor colores[], eCliente clientes[], int tam, int tamMarcas, int tamColores, int tamClientes, int idColor);
/** \brief ordena array por marca ingresada
 *
 * \param autos[] eAuto
 * \param marcas[] eMarca
 * \param colores[] eColor
 * \param tam int
 * \param tamMarcas int
 * \param tamColores int
 * \param idMarca int
 * \return int
 *
 */
int listarAutosXMarca(eAuto autos[], eMarca marcas[], eColor colores[], eCliente clientes[], int tam, int tamMarcas, int tamColores,int tamClientes, int idMarca);

int informarPromediosAutosXCaja(eAuto autos[], int tamAutos);

int ordenarAutosXCajaDescripcion(eAuto autos[], int tamAutos);

int contarColorYMarca(eAuto autos[], eColor colores[], eMarca marcas[],int tamAutos,int tamColores,int tamMarcas);

int marcaMasElegida(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca);

int totalMarcas(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, int idMarca, int* pTotal);


#endif // AUTO_H_INCLUDED
