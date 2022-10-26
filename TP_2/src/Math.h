//Juan Sebastian Amarilla 1k

#ifndef MATH_H_
#define MATH_H_

#include <stdlib.h>
#include <stdio.h>

/**
 * @fn void acumular(float*, float)
 * @brief su funcion es acumular
 *
 * @param float* acumulador
 * @param float valor
 */
void acumular(float* acumulador, float valor);

/**
 * @fn float sacarPromedio(float, int)
 * @brief su funcion es sacar promedio
 *
 * @param float total
 * @param int contador
 * @return retorna el promedio 0 si no se logro o distinto a 0 si se logro
 */
float sacarPromedio(float total, int contador);

/**
 * @fn void contar(int*)
 * @brief su funcion es contar
 *
 * @param int* contador
 */
void contar(int* contador);

/**
 * @fn void inicializarAcumulador(float[], int)
 * @brief su funcion es inicializar acumuladores
 *
 * @param float acumulador[]
 * @param int tam
 */
void inicializarAcumulador(float acumulador[], int tam);

/**
 * @fn float buscarMayorFlotante(float[], int)
 * @brief su funcion es buscar el mayor flotante
 *
 * @param float numero[]
 * @param int tam
 * @return retorna el mayor
 */
float buscarMayorFlotante(float numero[], int tam);

/**
 * @fn int buscarMayorEntero(int[], int)
 * @brief su funcion es buscar el mayor entero
 *
 * @param int numero[]
 * @param int tam
 * @return retorna el mayor
 */
int buscarMayorEntero(int numero[], int tam);

/**
 * @fn void inicializarContador(int[], int)
 * @brief su funcion es inicializar contadores
 *
 * @param int contador[]
 * @param int tam
 */
void inicializarContador(int contador[], int tam);

/**
 * @fn void calcularPorcentajes(int[], int, int, int[])
 * @brief su funcion es calcular porcentajes
 *
 * @param int contador[]
 * @param int tam
 * @param int total
 * @param int porcentajes[]
 */
void calcularPorcentajes(int contador[], int tam, int total, int porcentajes[]);

#endif /* MATH_H_ */
