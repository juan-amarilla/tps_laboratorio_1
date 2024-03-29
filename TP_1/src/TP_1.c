/*
 ============================================================================

 Juan Sebastian Amarilla 1k

 Debemos conformar un equipo para competir en el próximo mundial.
 La formación del equipo titular será 1-4-4-2 (arquero, defensores, mediocampistas y
 delanteros).

 Hay que tener presente que no podemos superar la cantidad máxima de 22 jugadores y
 no más de dos por posición, es decir, en total deberíamos tener 2 arqueros, 8 defensores,
 8 mediocampistas y 4 delanteros (teniendo en cuenta titulares y suplentes).

 Dicho plantel contara con un costo de mantenimiento, que va a estar compuesto por:
 Gastos de Transporte, Hospedaje y Comida. El usuario deberá cargar todos los gastos.
 Nota: de estos 3 valores surge el gasto de mantenimiento.

 Los jugadores pueden desarrollar sus actividades en cualquiera de las 6 confederaciones:
 AFC en Asia; CAF en África; CONCACAF en zona del Norte; CONMEBOL en Sudamérica;
 UEFA en Europa; OFC en Oceanía;

 La composición del menú será:
 1. Ingreso de los costos de Mantenimiento.
 Nota: El usuario podrá elegir qué gasto desea ingresar.
 El programa deberá informar el monto de cada gasto que se haya cargado hasta el momento:
 - Costo de hospedaje -> $0
 - Costo de comida -> $0
 - Costo de transporte -> $0

 2. Carga de jugadores:
 Nota: Al momento de la carga de datos debemos ingresar número de camiseta, posición,
 confederación en la que está jugando.
 El usuario podrá elegir qué posición desea ingresar.
 El programa deberá informar la cantidad de jugadores en cada posición que se haya cargado hasta
 el momento:
 - Arqueros -> 0
 - Defensores -> 0
 - Mediocampistas -> 0
 - Delanteros -> 0

 3. Realizar todos los cálculos.
 Nota: en esta sección solo se calcularan los valores de los datos solicitados, NO se deberán
 imprimir, solo informar que se realizaron correctamente los siguientes calculos:
 a. Calcular el promedio de jugadores de cada mercado.
 b. Calcular el costo de mantenimiento.
 c. Si la mayoría del plantel está compuesta por jugadores de la confederación europea el costo
 de mantenimiento recibe un aumento del 35%.

 4. Informar todos los resultados.
 Nota: Se deberá imprimir todos los datos calculados en el punto anterior y si el costo de
 mantenimiento recibió un aumento se debe informar el valor original, el valor del aumento
 y el valor actualizado con el aumento agregado.

 5. Salir.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Utn.h"
#include "LosMensajes.h"
#include "Futbol.h"
#define MIN 1
#define MAX 5
#define INTENTOS 100
#define TAM_CONFEDERACION 6
#define TAM_JUGADORES 22

int main(void)
{
	int opcion;
	int estado[4];

	int numeroCamiseta[TAM_JUGADORES];
	int arquero;
	int defensor;
	int mediocampista;
	int delantero;
	int confederacion[TAM_CONFEDERACION];

	float gastoHospedaje;
	float gastoComida;
	float gastoTransporte;
	float costoMantenimiento;
	float aumento;
	float costoMantenimientoNuevo;
	float promedio[TAM_CONFEDERACION];

	gastoHospedaje = 0;
	gastoComida = 0;
	gastoTransporte = 0;
	costoMantenimiento = 0;
	aumento = 0;
	costoMantenimientoNuevo = 0;

	arquero = 0;
	defensor = 0;
	mediocampista = 0;
	delantero = 0;

	inicializarConfederacion(confederacion, TAM_CONFEDERACION);
	inicializarCamiseta(numeroCamiseta, TAM_JUGADORES);

	setbuf(stdout, NULL);

	do
	{
		      mensaje("\n1-Ingreso de los costos de mantenimiento. \n");
		 mensajeGasto("Gasto de hospedaje ->", gastoHospedaje);
		 mensajeGasto("Gasto de comida ->", gastoComida);
		 mensajeGasto("Gasto de transporte ->", gastoTransporte);

		      mensaje("2-Carga de jugadores. \n");
      mensajePosicion("Cantidad de arqueros ->", arquero);
	  mensajePosicion("Cantidad de defensores ->", defensor);
	  mensajePosicion("Cantidad de mediocampistas ->", mediocampista);
	  mensajePosicion("Cantidad de delanteros ->", delantero);

             mensaje("3-Realizar todos los calculos. \n"
				     "4-Informar todos los resultados. \n"
				     "5-Salir. \n");

		estado[0] = utn_getNumero(&opcion, "Ingrese una opcion: \n", "Error, ingrese una opcion valida: \n", MIN, MAX, INTENTOS);

		if (estado[0] == 0)
		{
			switch (opcion)
			{

			 case 1:
			 estado[1] = ingresarGasto(&gastoHospedaje, &gastoComida, &gastoTransporte);
			 break;

			 case 2:
			 estado[2] = ingresarJugador(numeroCamiseta, &arquero, &defensor, &mediocampista, &delantero, confederacion, TAM_CONFEDERACION, TAM_JUGADORES);
			 break;

			 case 3:
			 if(estado[1] == 1 && estado[2] == 1)
			 {
				estado[3] = calculos(confederacion, promedio, &gastoHospedaje, &gastoComida, &gastoTransporte, &costoMantenimiento, &aumento, &costoMantenimientoNuevo, TAM_CONFEDERACION);
			 }

			 else
			 {
				 mensaje("\nFaltan datos, por favor ingrese los datos restantes. \n");
			 }
			 break;

			 case 4:
			 if(estado[3] == 0 || estado[3] == 1)
			 {
			    informeResultados(promedio, costoMantenimiento, aumento, costoMantenimientoNuevo, TAM_CONFEDERACION);
			 }

			 else
			 {
			 	mensaje("\nFalta realizar el calculo, por favor realize el calculo. \n");
			 }
			 break;

			 case 5:
			 mensaje("Salio del programa de forma exitosa. \n");
			 break;

			}
		}

		else
		{
			mensaje( "Se detecto muchos intentos fallidos, se cerrara el programa. \n");
			break;
		}

	}while (opcion != 5);

	return 0;
}
