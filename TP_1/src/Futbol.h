#ifndef FUTBOL_H_
#define FUTBOL_H_

//Juan Sebastian Amarilla 1k

#include "LosMensajes.h"
#include "Utn.h"
#include "IngresarDatos.h"
#define INTENTOS_FUTBOL 100
#define MIN_JUGADOR 1
#define MAX_JUGADOR 22
#define MIN_FUTBOL 1
#define MAX_FUTBOL 4
#define MIN_CONFEDERACION 1
#define MAX_CONFEDERACION 6

/**
 * @fn int ingresarGasto(float*, float*, float*)
 * @brief su funcion es ingresar un gasto
 *
 * @param float* gastoHospedaje
 * @param float* gastoComida
 * @param float* gastoTransporte
 * @return retorna 1 si se ingreso el gasto o 0 si no se pudo ingresar
 */
int ingresarGasto(float* gastoHospedaje, float* gastoComida, float* gastoTransporte);

/**
 * @fn int ingresarJugador(int[], int*, int*, int*, int*, int[], int, int)
 * @brief su funcion es ingresar un jugador
 *
 * @param int numeroCamiseta[]
 * @param int* arquero
 * @param int* defensor
 * @param int* mediocampista
 * @param int* delantero
 * @param int confederacion[]
 * @param int tamConfederacion
 * @param int tamCamiseta
 * @return retorna 1 si salio bien o 0 si salio mal
 */
int ingresarJugador(int numeroCamiseta[], int* arquero, int* defensor, int* mediocampista, int* delantero, int confederacion[], int tamConfederacion, int tamCamiseta);

/**
 * @fn void inicializarConfederacion(int[], int)
 * @brief su funcion es inicializar las confederaciones
 *
 * @param int confederacion[]
 * @param int tam
 */
void inicializarConfederacion(int confederacion[], int tam);

/**
 * @fn void inicializarCamiseta(int[], int)
 * @brief su funcion es inicializar las camisetas
 *
 * @param int numeroCamiseta[]
 * @param int tam
 */
void inicializarCamiseta(int numeroCamiseta[], int tam);

/**
 * @fn int menuConfederacion(int[], int)
 * @brief su funcion es crear un menu de confederacion
 *
 * @param int confederacion[]
 * @param int tam
 * @return retorna 1 si salio bien o 0 si salio mal
 */
int menuConfederacion(int confederacion[], int tam);

/**
 * @fn int calculos(int[], float[], float*, float*, float*, float*, float*, float*, int)
 * @brief su funcion es realizar calculos
 *
 * @param int confederacion[]
 * @param float promedio[]
 * @param float* gastoHospedaje
 * @param float* gastoComida
 * @param float* gastoTransporte
 * @param float* costoMantenimiento
 * @param float* aumento
 * @param float* costoMantenimientoNuevo
 * @param int tam
 * @return retorna -1 si solo se realizo unas operaciones, 0 si logro realizar la mitad de operacion o 1 si logro por completo todos los calculos
 */
int calculos(int confederacion[], float promedio[], float* gastoHospedaje, float* gastoComida, float* gastoTransporte, float* costoMantenimiento, float* aumento, float* costoMantenimientoNuevo, int tam);

/**
 * @fn int validarCamiseta(int[], int, int)
 * @brief su funcion es validar una camiseta existente
 *
 * @param int camisetas[]
 * @param int tam
 * @param int elegido
 * @return retorna la camiseta elegida
 */
int validarCamiseta(int camisetas[], int tam, int elegido);

#endif /* FUTBOL_H_ */
