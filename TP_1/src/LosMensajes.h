#ifndef LOSMENSAJES_H_
#define LOSMENSAJES_H_

//Juan Sebastian Amarilla 1k

#include <stdio.h>

/**
 * @fn void mensaje(char*)
 * @brief muestra un mensaje
 *
 * @param char* informacion
 */
void mensaje(char* informacion);

/**
 * @fn void mensajeGasto(char*, float)
 * @brief su funcion es mostrar un mensaje junto con un flotante
 *
 * @param char* informacion
 * @param float gasto
 */
void mensajeGasto(char* informacion, float gasto);

/**
 * @fn void mensajePosiocion(char*, int)
 * @brief su funcion es mostrar un mensaje junto con un entero
 *
 * @param char* informacion
 * @param int posicion
 */
void mensajePosicion(char* informacion, int posicion);

/**
 * @fn void informeResultados(float[], float, float, float, int)
 * @brief su funcion es realizar un informe de resultados
 *
 * @param float promedio[]
 * @param float costoMantenimiento
 * @param float aumento
 * @param float costoMantenimientoNuevo
 * @param int tam
 */
void informeResultados(float promedio[], float costoMantenimiento, float aumento, float costoMantenimientoNuevo,  int tam);

#endif /* LOSMENSAJES_H_ */
