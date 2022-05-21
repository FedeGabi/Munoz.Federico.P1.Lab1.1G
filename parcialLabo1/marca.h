#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "input.h"
typedef struct{
    int id;
    char descripcion[20];
}eMarca;


/** \brief menu de opciones q mmuestra las marcas existentes e el array
 *
 * \param vec[] eMarca
 * \param tamMarcas int
 * \return int devuelve la opcion seleccionada
 *
 */
int menuIngresarMarca(eMarca vec[], int tamMarcas);


/** \brief busca el id ingresado, si lo encuentra devuelve el indice en el que se encuentra
 *
 * \param vec[] eMarca
 * \param tamMarcas int
 * \param id int
 * \param pIndice int*
 * \return int
 *
 */
int buscarMarcaId(eMarca vec[], int tamMarcas, int id, int* pIndice);

/** \brief
 *
 * \param vec[] eMarca
 * \param tamMarcas int
 * \param id int
 * \return int
 *
 */
int validarMarcaId(eMarca vec[], int tamMarcas, int id);

int cargarDescripcionMarca(eMarca marcas[], char descripcion[], int id, int tamMarcas);

int listarMarcas(eMarca marcas[],int tamMarcas);

void mostrarMarca(eMarca marca);
#endif // MARCA_H_INCLUDED
