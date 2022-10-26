//Juan Sebastian Amarilla 1k

#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

#define TAM_CARATER 50
#define TAM_CONFEDERACION 6
#define OCUPADO 1
#define LIBRE 0
#include <stdio.h>
#include <string.h>
#include "Input.h"

typedef struct
{
	int id;
	char nombre[TAM_CARATER];
	char region[TAM_CARATER];
	int aniosCreacion;
	short isEmpty;

}eConfederacion;

/**
 * @fn void mostrarConfederaciones(eConfederacion[], int)
 * @brief su funcion es listar confederaciones
 *
 * @param eConfederacion confederaciones[]
 * @param int tamConfederacion
 */
void mostrarConfederaciones(eConfederacion confederaciones[], int tamConfederacion);

/**
 * @fn void mostrarConfederacion(eConfederacion)
 * @brief su funcion es mostrar una confederacion
 *
 * @param int confederacion
 */
void mostrarConfederacion(eConfederacion confederacion);

/**
 * @fn void mostrarMayoresConfederaciones(eConfederacion[], int, float, float[])
 * @brief su funcion es saber las confederaciones con mayores cantidades de anios de contrato
 *
 * @param eConfederacion confederaciones[]
 * @param int tamConfederacion
 * @param float mayor
 * @param float acumulador[]
 */
void mostrarMayoresConfederaciones(eConfederacion confederaciones[], int tamConfederacion, float mayor, float acumulador[]);

/**
 * @fn void mostrarMayorConfederacion(eConfederacion, float)
 * @brief su funcion es mostrar la confederacion con mayor cantidad de anio de contrato
 *
 * @param eConfederacion confederaciones
 * @param float valor
 */
void mostrarMayorConfederacion(eConfederacion confederaciones, float valor);

/**
 * @fn void mostrarPorcentajesConfederaciones(eConfederacion[], int, int[])
 * @brief su funcion es mostrar la cantidad de jugadores de cada confederacion en porcentaje
 *
 * @param eConfederacion confederaciones[]
 * @param int tamConfederacion
 * @param int porcentajes[]
 */
void mostrarPorcentajesConfederaciones(eConfederacion confederaciones[], int tamConfederacion, int porcentajes[]);

/**
 * @fn void mostrarPorcentajeConfederacion(eConfederacion, int)
 * @brief su funcion es mostrar el porcentaje de jugadores de la confederacion
 *
 * @param eConfederacion confederaciones
 * @param int porcentajes
 */
void mostrarPorcentajeConfederacion(eConfederacion confederaciones, int porcentajes);

/**
 * @fn int buscarIdDeConfederacion(eConfederacion[], int, int)
 * @brief su funcion es buscar id
 *
 * @param eConfederacion confederaciones[]
 * @param int tam
 * @param int id
 * @return retorna 1 si salio bien o 0 si salio mal
 */
int buscarIdDeConfederacion(eConfederacion confederaciones[], int tam, int id);

/**
 * @fn void inicializarConfederaciones(eConfederacion[], int)
 * @brief su funcion es inicializar confederaciones
 *
 * @param eConfederacion confederaciones[]
 * @param int tam
 */
void inicializarConfederaciones(eConfederacion confederaciones[], int tam);

/**
 * @fn int buscarLibreConfederacion(eConfederacion[], int)
 * @brief su funcion es buscar libre
 *
 * @param eConfederacion confederaciones[]
 * @param int tam
 * @return retorna el indice si salio bien o -1 si salio mal
 */
int buscarLibreConfederacion(eConfederacion confederaciones[], int tam);

/**
 * @fn int verificarLlenoDeConfederaciones(eConfederacion[], int)
 * @brief su funcion es verificar si hay uno de alta
 *
 * @param eConfederacion confederaciones[]
 * @param int tam
 * @return retorna 1 si salio bien o 0 si salio mal
 */
int verificarLlenoDeConfederaciones(eConfederacion confederaciones[], int tam);

/**
 * @fn void definirConfederaciones(eConfederacion[])
 * @brief su funcion es definir confederaciones
 *
 * @param eConfederacion confederaciones[]
 */
void definirConfederaciones(eConfederacion confederaciones[]);

/**
 * @fn int buscarNombreConfederacion(eConfederacion[], int, int, char[])
 * @brief su funcion es buscar el nombre de confederacion
 *
 * @param eConfederacion confederaciones[]
 * @param int tam
 * @param int id
 * @param char confederacion[]
 * @return retorna 1 si salio bien o 0 si salio mal
 */
int buscarNombreConfederacion(eConfederacion confederaciones[], int tam, int id, char confederacion[]);

/**
 * @fn int altaConfederacion(eConfederacion[], int, int*)
 * @brief su funcion es dar de alta
 *
 * @param eConfederacion confederaciones[]
 * @param int tamConfederacion
 * @param int* auxiliar
 * @return retorna 1 si salio bien o 0 si salio mal
 */
int altaConfederacion(eConfederacion confederaciones[], int tamConfederacion, int* auxiliar);

/**
 * @fn int verificarNombreDeConfederacion(eConfederacion[], int, char[])
 * @brief su funcion es verificar nombre de confederacion
 *
 * @param eConfederacion confederaciones[]
 * @param int tamConfederacion
 * @param char cadena[]
 * @return retorna 1 si salio bien o 0 si salio mal
 */
int verificarNombreDeConfederacion(eConfederacion confederaciones[], int tamConfederacion, char cadena[]);

/**
 * @fn int verificarRegionDeConfederacion(eConfederacion[], int, char[])
 * @brief su funcion es verificar la region de confederacion
 *
 * @param eConfederacion confederaciones[]
 * @param int tamConfederacion
 * @param char cadena[]
 * @return retorna 1 si salio bien o 0 si salio mal
 */
int verificarRegionDeConfederacion(eConfederacion confederaciones[], int tamConfederacion, char cadena[]);

/**
 * @fn int bajaConfederacion(eConfederacion[], int)
 * @brief su funcion es dar de baja una confederacion
 *
 * @param eConfederacion confederaciones[]
 * @param int tamConfederacion
 * @return retorna 1 si salio bien o 0 si salio mal
 */
int bajaConfederacion(eConfederacion confederaciones[], int tamConfederacion);

/**
 * @fn int buscarConfederacion(eConfederacion[], int, int)
 * @brief su funcion es buscar una confederacion
 *
 * @param eConfederacion confederaciones[]
 * @param int tamConfederacion
 * @param int confederacionElegido
 * @return retorna el indice si salio bien o -1 si salio mal
 */
int buscarConfederacion(eConfederacion confederaciones[], int tamConfederacion, int confederacionElegido);

#endif /* CONFEDERACION_H_ */
