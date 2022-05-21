#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/** \brief muestra menu con opciones
 *
 * \return int retorna la opcion seleccionada
 *
 */
int mostrarMenuPrincipal();
/** \brief menu de opciones
 *
 * \return int
 *
 */
int menuModificarAutos();
/** \brief valida el ingreso de numero flotante
 *
 * \param pFloat float*
 * \param [] char msj
 * \param msjError[] char
 * \param intentos int
 * \return int
 *
 */
int ingresarFloat(float *pFloat, char msj [], char msjError[], int intentos);
/** \brief valida el ingreso de un entero
 *
 * \param pInt int*
 * \param [] char msj
 * \param msjError[] char
 * \return int
 *
 */
int ingresarInt(int *pInt, char msj [], char msjError[]);
/** \brief valida cadena de caracteres
 *
 * \param cadena[] char
 * \param tamMin int
 * \param tamMax int
 * \param msj[] char
 * \param msjError[] char
 * \param intentos int
 * \return int
 *
 */
int ingresarValidarCadena(char cadena[],int tamMin ,int tamMax, char msj[], char msjError[], int intentos);
/** \brief valida dos caracteres de referencia
 *
 * \param msj[] char
 * \param msjError[] char
 * \param char1 char
 * \param char2 char
 * \param pResultado char*
 * \return int retorna 1 si pudo validar, de lo contrario 0
 *
 */

 int ingresarValidarNombre(char cadena[],int tamMin ,int tamMax, char msj[], char msjError[]);


 int validarLetras(char cadena[]);


int ingresarValidarCaracter(char msj[], char msjError[], char char1, char char2, char* pResultado);
/** \brief pide confirmacion de nuevo ingreso
 *
 * \param msj[] char
 * \return int 1 si selecciona volver a ingresar, de lo contrario 0
 *
 */
int confirmar(char msj[]);


#endif // INPUT_H_INCLUDED
