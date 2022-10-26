//Juan Sebastian Amarilla 1k

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include <stdio.h>
#include "Nexo.h"

/**
 * @fn void mensaje(char*)
 * @brief su funcion es mostrar un mensaje
 *
 * @param char* informacion
 */
void mensaje(char* informacion);

/**
 * @fn void mensajeEstado(int, char[], char[])
 * @brief su funcion es mostrar uno de los dos mensajes
 *
 * @param int estado
 * @param char valido[]
 * @param char noValido[]
 */
void mensajeEstado(int estado, char valido[], char noValido[]);

/**
 * @fn void mostrarJugadores(eJugador[], int, eConfederacion[], int)
 * @brief su funcion es mostrar jugadores
 *
 * @param eJugador jugadores[]
 * @param int tamJugador
 * @param eConfederacion confederaciones[]
 * @param int tamConfederacion
 */
void mostrarJugadores(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion);

/**
 * @fn void mostrarJugador(eJugador, eConfederacion)
 * @brief su funcion es mostrar un jugador
 *
 * @param eJugador jugador
 * @param eConfederacion confederacion
 */
void mostrarJugador(eJugador jugador, eConfederacion confederacion);

/**
 * @fn void listarConfederacionesConSusJugadores(eJugador[], int, eConfederacion[], int)
 * @brief su funcion es listar confederaciones con sus jugadores
 *
 * @param eJugador jugadores[]
 * @param int tamJugador
 * @param eConfederacion confederaciones[]
 * @param int tamConfederacion
 */
void listarConfederacionesConSusJugadores(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion);

/**
 * @fn void mensajeFlotante(char*, float)
 * @brief su funcion es mostrar un mensaje flotante
 *
 * @param char* informacion
 * @param float flotante
 */
void mensajeFlotante(char* informacion, float flotante);

/**
 * @fn void mensajeEntero(char*, int)
 * @brief su funcion es mostrar un mensaje entero
 *
 * @param char* informacion
 * @param int entero
 */
void mensajeEntero(char* informacion, int entero);

/**
 * @fn void listarRegionesConMayorDeJugadores(eJugador[], int, eConfederacion[], int, int[], int)
 * @brief su funcion es listar las regiones con los mayores de cantidad de jugadores
 *
 * @param eJugador jugadores[]
 * @param int tamJugador
 * @param eConfederacion confederaciones[]
 * @param int tamConfederacion
 * @param int contador[]
 * @param int mayor
 */
void listarRegionesConMayorDeJugadores(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion, int contador[], int mayor);


#endif /* OUTPUT_H_ */
