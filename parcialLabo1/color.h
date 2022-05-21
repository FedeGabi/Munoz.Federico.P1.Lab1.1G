#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int id;
    char nombreColor[20];
}eColor;

/** \brief muestra un menu de opciones de colores
 *
 * \param vec[] eColor
 * \param tamColores int
 * \return int retorna el color seleccionado
 *
 */
int menuIngresarColor(eColor vec[], int tamColores);

/** \brief busca el color po id y retorna el indice en el q se encuentra
 *
 * \param vec[] eColor
 * \param tamColores int
 * \param id int
 * \param pIndice int*
 * \return int retorna numero de indice
 *
 */
int buscarColorId(eColor vec[], int tamColores, int id, int* pIndice);


/** \brief recibe el id de una estructura y carga su descripcion en una variable cadena de caracteres
 *
 * \param colores[] eColor
 * \param descripcion[] char
 * \param id int
 * \param tamColores int
 * \return int
 *
 */
int cargarDescripcionColor(eColor colores[], char descripcion[], int id, int tamColores);

/** \brief muestra lista de colores
 *
 * \param Colors[] eColor array de colores
 * \param tamColores int tamaño array
 * \return int
 *
 */
int listarColores(eColor Colors[],int tamColores);

/** \brief muestra un color
 *
 * \param color eColor
 * \return void
 *
 */
void mostrarColor(eColor color);


#endif // COLOR_H_INCLUDED
