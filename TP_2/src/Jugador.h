//Juan Sebastian Amarilla 1k

#ifndef JUGADOR_H_
#define JUGADOR_H_

#define TAM_CARATER 50
#define TAM_JUGADOR 3000
#define OCUPADO 1
#define LIBRE 0
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Input.h"
#include "Math.h"

typedef struct
{
	int id;
	char nombre[TAM_CARATER];
	char posicion[TAM_CARATER];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;

}eJugador;

/**
 * @fn void inicializarJugadores(eJugador[], int)
 * @brief su funcion es inicializar
 *
 * @param eJugador jugadores[]
 * @param int tamJugador
 */
void inicializarJugadores(eJugador jugadores[], int tamJugador);

/**
 * @fn int buscarLibreJugador(eJugador[], int)
 * @brief su funcion es buscar uno libre
 *
 * @param eJugador jugadores[]
 * @param int tamJugador
 * @return retorna el indice si salio bien o -1 si salio mal
 */
int buscarLibreJugador(eJugador jugadores[], int tamJugador);

/**
 * @fn int buscarJugador(eJugador[], int, int)
 * @brief su funcion es buscar un jugador
 *
 * @param eJugador jugadores[]
 * @param int tamJugador
 * @param int jugadorElegido
 * @return retorna el indice si salio bien o -1 si salio mal
 */
int buscarJugador(eJugador jugadores[], int tamJugador, int jugadorElegido);

/**
 * @fn int verificarLlenoDeJugadores(eJugador[], int)
 * @brief su funcion es verificar si esta lleno
 *
 * @param eJugador jugadores[]
 * @param int tamJugador
 * @return retorna 1 si salio bien o 0 si salio mal
 */
int verificarLlenoDeJugadores(eJugador jugadores[], int tamJugador);

/**
 * @fn void calcularSalarios(eJugador[], int, float*, float*, int*)
 * @brief su funcion es calcular salarios
 *
 * @param eJugador jugadores[]
 * @param int tamJugador
 * @param float* total
 * @param float* promedio
 * @param int* contadorMayor
 */
void calcularSalarios(eJugador jugadores[], int tamJugador, float* total, float* promedio, int* contadorMayor);

/**
 * @fn void ordenarJugadoresPorId(eJugador[], int)
 * @brief su funcion es ordenar jugadores por id
 *
 * @param eJugador jugadores[]
 * @param int tamJugador
 */
void ordenarJugadoresPorId(eJugador jugadores[], int tamJugador);

#endif /* JUGADOR_H_ */
