//Juan Sebastian Amarilla 1k

#ifndef NEXO_H_
#define NEXO_H_

#define TAM_CARATER 50
#define TAM_JUGADOR 3000
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Confederacion.h"
#include "Jugador.h"
#include "Output.h"
#include "Input.h"

/**
 * @fn int altaJugador(eJugador[], int, eConfederacion[], int, int*)
 * @brief su funcion es dar de alta un jugador
 *
 * @param eJugador jugadores[]
 * @param int tamJugador
 * @param eConfederacion confederaciones[]
 * @param int tamConfederacion
 * @param int* auxiliar
 * @return retorna 1 si salio bien o 0 si salio mal
 */
int altaJugador(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion, int* auxiliar);

/**
 * @fn int bajaJugador(eJugador[], int, eConfederacion[], int)
 * @brief su funcion es dar de baja un jugador
 *
 * @param eJugador jugadores[]
 * @param int tamJugador
 * @param eConfederacion confederaciones[]
 * @param int tamConfederacion
 * @return retorna 1 si salio bien o 0 si salio mal
 */
int bajaJugador(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion);

/**
 * @fn int modificarJugador(eJugador[], int, eConfederacion[], int)
 * @brief su funcion es modificar un jugador
 *
 * @param eJugador jugadores[]
 * @param int tamJugador
 * @param eConfederacion confederaciones[]
 * @param int tamConfederacion
 * @return retorna 1 si salio bien o 0 si salio mal
 */
int modificarJugador(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion);

/**
 * @fn int informes(eJugador[], int, eConfederacion[], int)
 * @brief su funcion es realizar informes
 *
 * @param eJugador jugadores[]
 * @param int tamJugador
 * @param eConfederacion confederaciones[]
 * @param int tamConfederacion
 * @return retorna 1 si salio bien o 0 si salio mal
 */
int informes(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion);

/**
 * @fn void ordenarJugadores(eJugador[], int, eConfederacion[], int)
 * @brief su funcion es ordenar jugadores por doble criterio
 *
 * @param eJugador jugadores[]
 * @param int tamJugador
 * @param eConfederacion confederaciones[]
 * @param int tamConfederacion
 */
void ordenarJugadores(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion);

/**
 * @fn void buscarConfederacionMayor(eJugador[], int, eConfederacion[], int)
 * @brief su funcion es buscar la confederacion mayor cantidad de anio de contrato
 *
 * @param eJugador jugadores[]
 * @param int tamJugador
 * @param eConfederacion confederaciones[]
 * @param int tamConfederacion
 */
void buscarConfederacionMayor(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion);

/**
 * @fn void jugadoresDeCadaConfederacion(eJugador[], int, eConfederacion[], int, int[])
 * @brief su funcion es saber la cantidad de jugadores de cada confederacion
 *
 * @param eJugador jugadores[]
 * @param int tamJugador
 * @param eConfederacion confederaciones[]
 * @param int tamConfederacion
 * @param int contador[]
 */
void jugadoresDeCadaConfederacion(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion, int contador[]);

/**
 * @fn void porcentajeCadaConfederacion(eJugador[], int, eConfederacion[], int)
 * @brief su funcion es saber el porcentaje de jugadores de cada confederacion
 *
 * @param eJugador jugadores[]
 * @param int tamJugador
 * @param eConfederacion confederaciones[]
 * @param int tamConfederacion
 */
void porcentajeCadaConfederacion(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion);

/**
 * @fn void regionConMasJugadores(eJugador[], int, eConfederacion[], int)
 * @brief su funcion es saber la region con mas jugadores
 *
 * @param eJugador jugadores[]
 * @param int tamJugador
 * @param eConfederacion confederaciones[]
 * @param int tamConfederacion
 */
void regionConMasJugadores(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion);

#endif /* NEXO_H_ */
