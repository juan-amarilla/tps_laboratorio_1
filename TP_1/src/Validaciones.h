#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

//Juan Sebastian Amarilla 1k

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/// @fn int validarNumeroFlotante(float*, char[])
/// @brief su funcion es validar si el numero es flotante
///
/// @param float* numeroFlotante
/// @param char numero[]
/// @return retorna 1 si salio bien o 0 si salio mal
int validarNumeroFlotante(float* numeroFlotante, char numero[]);

#endif /* VALIDACIONES_H_ */
