#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

//Juan Sebastian Amarilla 1k

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/// @fn int validarNumeroEntero(int*, char[])
/// @brief su funcion es validar si es un numero entero
///
/// @param int* numeroEntero
/// @param char numero[]
/// @return retorna 1 si salio bien o -1 si salio mal
int validarNumeroEntero(int* numeroEntero, char numero[]);

/**
 * @fn int validarNumeroCorto(short*, char[])
 * @brief su funcion es validar un short
 *
 * @param short* numeroCorto
 * @param char numero[]
 * @return retorna 1 si salio bien o 0 si salio mal
 */
int validarNumeroCorto(short* numeroCorto, char numero[]);

/// @fn int validarNumeroFlotante(float*, char[])
/// @brief su funcion es validar si el numero es flotante
///
/// @param float* numeroFlotante
/// @param char numero[]
/// @return retorna 1 si salio bien o 0 si salio mal
int validarNumeroFlotante(float* numeroFlotante, char numero[]);

/// @fn int validarLetras(char[], char[])
/// @brief su funcion es validar si la cadena son solamente letras
///
/// @param char letras[]
/// @param char caracter[]
/// @return retorna 1 si salio bien o 0 si salio mal
int validarLetras(char letras[], char caracter[]);

/**
 * @fn void mayusculasAutomaticos(char[], int)
 * @brief su funcion es hacer mayusculas automaticos de forma correcta
 *
 * @param char cadena[]
 * @param int tam
 */
void mayusculasAutomaticos(char cadena[], int tam);

#endif /* VALIDACIONES_H_ */
