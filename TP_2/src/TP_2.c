/*
============================================================================

Juan Sebastian Amarilla 1k

1. ALTA DE JUGADOR: Se debe permitir ingresar un jugador calculando automáticamente
el número de Id. El resto de los campos se le pedirá al usuario, al momento de ingresar
la confederación se deberá mostrar la lista completa de confederaciones disponibles y
su elección será mediante número de id.
*Nota: el id del jugador debe ser autoincremental , único y autónomo, es decir, no
debe depender de la posición de un array ni calcularse en base a buscar el mayor id
que tenga un jugador dentro del array.

2. BAJA DE JUGADOR: Se deberá mostrar la lista completa de jugadores (ordenada por
ID) con todos sus datos y se podrá elegir uno ingresando el Número de Id y se
eliminará el jugador del sistema.

3. MODIFICACIÓN DE JUGADOR: Se deberá mostrar la lista completa de jugadores
(ordenada por ID) con todos sus datos y se podrá elegir uno ingresando el Número de
Id, permitiendo modificar: nombre, posicion, numero de camiseta, confederación,
salario,años de contrato.
Este proceso debe contar con menú propio permitiendo elegir qué campo se desea
modificar.

4. INFORMES:
1-Listado de los jugadores ordenados alfabéticamente por nombre de
confederación y nombre de jugador. (Es ordenamiento por doble criterio, se
ordena por nombre de la confederación y en caso de igualdad se ordena por
nombre del jugador).
2-Listado de confederaciones con sus jugadores.
3-Total y promedio de todos los salarios y cuántos jugadores cobran más del
salario promedio.
4-Informar la confederación con mayor cantidad de años de contratos total.
5-Informar porcentaje de jugadores por cada confederación.
6-Informar cual es la región con más jugadores y el listado de los mismos.
Este proceso debe contar con menú propio permitiendo elegir qué informe se desea ver.

5. SALIR: Se deberá pedir confirmación al usuario antes de cerrar el programa.

============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "Nexo.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	int salida;
	int retorno;
	int idAuxiliar;
	char cadena[TAM_CARATER];
	eJugador jugadores[TAM_JUGADOR];
	eConfederacion confederaciones[TAM_CONFEDERACION];
	//int idAuxiliarConfederacion;

	idAuxiliar = 0;
	//idAuxiliarConfederacion = 105;

	inicializarJugadores(jugadores, TAM_JUGADOR);
	//inicializarConfederaciones(confederaciones, TAM_CONFEDERACION);

	definirConfederaciones(confederaciones);

	do
	{
			mensaje("\n1-Alta jugador. \n"
					"2-Baja jugador. \n"
					"3-Modificar jugador. \n"
					"4-Informes. \n"
					"5-Salir. \n");

			pedirEnteroValidado(cadena, "Ingrese una opcion: \n", &opcion);

			switch (opcion)
			{
				case 1:
				if(verificarLlenoDeConfederaciones(confederaciones, TAM_CONFEDERACION) == 1)
				{
					retorno = altaJugador(jugadores, TAM_JUGADOR, confederaciones, TAM_CONFEDERACION, &idAuxiliar);
					mensajeEstado(retorno, "Alta con exito.", "Alta sin exito.");
				}

				else
				{
					mensaje("No hay confederaciones de alta.\n");
				}
				break;

			    case 2:
				if(verificarLlenoDeJugadores(jugadores, TAM_JUGADOR) == 1 && verificarLlenoDeConfederaciones(confederaciones, TAM_CONFEDERACION) == 1)
				{
				   retorno = bajaJugador(jugadores, TAM_JUGADOR, confederaciones, TAM_CONFEDERACION);
				   mensajeEstado(retorno, "Baja con exito.", "Baja sin exito.");
				}

				else
				{
				   mensaje("No hay jugadores de alta, confederaciones de alta o los dos no hay ningun de alta.\n");
				}
			    break;

				case 3:
				if(verificarLlenoDeJugadores(jugadores, TAM_JUGADOR) == 1 && verificarLlenoDeConfederaciones(confederaciones, TAM_CONFEDERACION) == 1)
				{
					retorno = modificarJugador(jugadores, TAM_JUGADOR, confederaciones, TAM_CONFEDERACION);
					mensajeEstado(retorno, "Modificacion con exito.", "Modificacion sin exito.");
				}

				else
				{
				    mensaje("No hay jugadores de alta, confederaciones de alta o los dos no hay ningun de alta.\n");
				}
				break;

			    case 4:
			    if(verificarLlenoDeJugadores(jugadores, TAM_JUGADOR) == 1 && verificarLlenoDeConfederaciones(confederaciones, TAM_CONFEDERACION) == 1)
				{
					retorno = informes(jugadores, TAM_JUGADOR, confederaciones, TAM_CONFEDERACION);
                    mensajeEstado(retorno, "Informe con exito.", "Informe sin exito.");
				}

				else
				{
				    mensaje("No hay jugadores de alta, confederaciones de alta o los dos no hay ningun de alta.\n");
				}
				break;

				case 5:
				pedirEnteroValidado(cadena, "¿Estas seguro de salir? Pulse 1 que si o caso contrario otro numero. \n", &salida);
				if(opcion == 5 && salida == 1)
				{
					mensaje("\nSalio del programa de forma exitosa. \n");
				}

				else
				{
					opcion = 0;
					mensaje("\nNo salio del programa. \n");
				}
				break;
			}

	} while(opcion != 5);

	return 0;
}
