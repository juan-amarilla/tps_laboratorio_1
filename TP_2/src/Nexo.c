//Juan Sebastian Amarilla 1k

#include "Nexo.h"

int altaJugador(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion, int* auxiliar)
{
	int retorno;
	int indice;
	char cadena[TAM_CARATER];
	char cadenaValidado[TAM_CARATER];

	retorno = 0;

	indice = buscarLibreJugador(jugadores, tamJugador);

	if(indice > -1 && auxiliar != NULL)
	{
		*auxiliar = *auxiliar + 1;
		jugadores[indice].id = *auxiliar;

		pedirCadenaValidado(cadena, "Ingrese un nombre: \n", cadenaValidado);
		mayusculasAutomaticos(cadenaValidado, TAM_CARATER);
		strcpy(jugadores[indice].nombre, cadenaValidado);

		pedirCadenaValidado(cadena, "Ingrese una posicion como arquero, defensor, mediocampista o delantero: \n", cadenaValidado);
		mayusculasAutomaticos(cadenaValidado, TAM_CARATER);
		while( (strcmp(cadenaValidado, "Arquero") != 0 && strcmp(cadenaValidado, "Defensor") != 0 && strcmp(cadenaValidado, "Mediocampista") != 0 && strcmp(cadenaValidado, "Delantero") != 0) )
		{
			pedirCadenaValidado(cadena, "Ingrese una posicion correcta como arquero, defensor, mediocampista o delantero: \n", cadenaValidado);
			mayusculasAutomaticos(cadenaValidado, TAM_CARATER);
		}
		strcpy(jugadores[indice].posicion, cadenaValidado);

		pedirCortoValidado(cadena, "Ingrese un numero de camiseta por favor: \n", &jugadores[indice].numeroCamiseta);
		while(jugadores[indice].numeroCamiseta < 0 || jugadores[indice].numeroCamiseta > 22)
		{
			pedirCortoValidado(cadena, "Ingrese un numero de camiseta entre 1 a 22 por favor: \n", &jugadores[indice].numeroCamiseta);
		}

		mostrarConfederaciones(confederaciones, tamConfederacion);
		pedirEnteroValidado(cadena, "Ingrese una id: \n", &jugadores[indice].idConfederacion);
		while(buscarIdDeConfederacion(confederaciones, tamConfederacion, jugadores[indice].idConfederacion) != 1)
		{
			pedirEnteroValidado(cadena, "Ingrese una id valido: \n", &jugadores[indice].idConfederacion);
		}

	    pedirFlotanteValidado(cadena, "Ingrese un salario por favor: \n", &jugadores[indice].salario);
	    while(jugadores[indice].salario < 0)
	    {
	    	pedirFlotanteValidado(cadena, "Ingrese un salario mayor a 0 por favor: \n", &jugadores[indice].salario);
	    }

	    pedirCortoValidado(cadena, "Ingrese los anios de contrato por favor: \n", &jugadores[indice].aniosContrato);
	    while(jugadores[indice].aniosContrato < 0 )
	    {
	    	pedirCortoValidado(cadena, "Ingrese los anios de contrato mayor a 0 por favor: \n", &jugadores[indice].aniosContrato);
	    }

		jugadores[indice].isEmpty = OCUPADO;

		retorno = 1;
	}

	return retorno;

}

int bajaJugador(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion)
{
	int retorno;
	int indice;
	int jugador;
	char cadena[TAM_CARATER];

	retorno = 0;

	ordenarJugadoresPorId(jugadores, tamJugador);
	mostrarJugadores(jugadores, tamJugador, confederaciones, tamConfederacion);
	pedirEnteroValidado(cadena, "Ingrese el id del jugador a realizar la baja: \n", &jugador);
	indice = buscarJugador(jugadores, tamJugador, jugador);

	if(indice > -1)
	{
		jugadores[indice].isEmpty = LIBRE;
		retorno = 1;
	}

	return retorno;

}

int modificarJugador(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion)
{
	int retorno;
	int opcion;
	int jugador;
	int indice;
	char cadena[TAM_CARATER];
	char cadenaValidado[TAM_CARATER];

	retorno = 0;

	ordenarJugadoresPorId(jugadores, tamJugador);
	mostrarJugadores(jugadores, tamJugador, confederaciones, tamConfederacion);
	pedirEnteroValidado(cadena, "Ingrese la id del jugador a realizar la modificacion: \n", &jugador);
	indice = buscarJugador(jugadores, tamJugador, jugador);

	if(indice > -1)
	{
		do
		{
			printf("\n1-Modificar nombre. \n"
					"2-Modificar posicion. \n"
					"3-Modificar numero de camiseta. \n"
					"4-Modificar confederacion. \n"
					"5-Modificar salario. \n"
					"6-Modificar anios de contrato. \n"
					"7-Salir. \n");

			pedirEnteroValidado(cadena, "Ingrese una opcion: \n", &opcion);

			switch(opcion)
			{
			   case 1:
			   pedirCadenaValidado(cadena, "Ingrese un nombre: \n", cadenaValidado);
		       mayusculasAutomaticos(cadenaValidado, TAM_CARATER);
		       strcpy(jugadores[indice].nombre, cadenaValidado);
			   retorno = 1;
			   break;

			   case 2:
			   pedirCadenaValidado(cadena, "Ingrese una posicion como arquero, defensor, mediocampista o delantero: \n", cadenaValidado);
			   mayusculasAutomaticos(cadenaValidado, TAM_CARATER);
			   while( (strcmp(cadenaValidado, "Arquero") != 0 && strcmp(cadenaValidado, "Defensor") != 0 && strcmp(cadenaValidado, "Mediocampista") != 0 && strcmp(cadenaValidado, "Delantero") != 0) )
			   {
				   pedirCadenaValidado(cadena, "Ingrese una posicion correcta como arquero, defensor, mediocampista o delantero: \n", cadenaValidado);
				   mayusculasAutomaticos(cadenaValidado, TAM_CARATER);
			   }
			   strcpy(jugadores[indice].posicion, cadenaValidado);
			   retorno = 1;
			   break;

			   case 3:
			   pedirCortoValidado(cadena, "Ingrese un numero de camiseta por favor: \n", &jugadores[indice].numeroCamiseta);
			   while(jugadores[indice].numeroCamiseta < 0 || jugadores[indice].numeroCamiseta > 22)
			   {
				  pedirCortoValidado(cadena, "Ingrese un numero de camiseta entre 1 a 22 por favor: \n", &jugadores[indice].numeroCamiseta);
			   }
			   retorno = 1;
			   break;

			   case 4:
			   mostrarConfederaciones(confederaciones, tamConfederacion);
			   pedirEnteroValidado(cadena, "Ingrese una id: \n", &jugadores[indice].idConfederacion);
			   while(buscarIdDeConfederacion(confederaciones, tamConfederacion, jugadores[indice].idConfederacion) != 1)
			   {
				   pedirEnteroValidado(cadena, "Ingrese una id valido: \n", &jugadores[indice].idConfederacion);
			   }
			   retorno = 1;
			   break;

			   case 5:
			   pedirFlotanteValidado(cadena, "Ingrese un salario por favor: \n", &jugadores[indice].salario);
			   while(jugadores[indice].salario < 0)
			   {
				   pedirFlotanteValidado(cadena, "Ingrese un salario mayor a 0 por favor: \n", &jugadores[indice].salario);
			   }
			   retorno = 1;
			   break;

			   case 6:
			   pedirCortoValidado(cadena, "Ingrese los anios de contrato por favor: \n", &jugadores[indice].aniosContrato);
			   while(jugadores[indice].aniosContrato < 0 )
			   {
				  pedirCortoValidado(cadena, "Ingrese los anios de contrato mayor a 0 por favor: \n", &jugadores[indice].aniosContrato);
			   }
			   retorno = 1;
			   break;

			   case 7:
			   printf("\nSalio del menu de forma exitosa. \n");
			   break;
			}

		} while (opcion != 7);

	}

	return retorno;

}

int informes(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion)
{
	int retorno;
	int opcion;
	float total;
	float promedio;
	int contadorMayor;
	char cadena[TAM_CARATER];

	retorno = 0;

	do
	{
		total = 0;
		promedio = 0;
		contadorMayor = 0;

		printf("\n1-Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador. \n"
				"2-Listado de confederaciones con sus jugadores. \n"
				"3-Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio. \n"
				"4-Informar la confederación con mayor cantidad de años de contratos total. \n"
				"5-Informar porcentaje de jugadores por cada confederación. \n"
				"6-Informar cual es la región con más jugadores y el listado de los mismos.. \n"
				"7-Salir. \n");

		pedirEnteroValidado(cadena, "Ingrese una opcion: \n", &opcion);

		switch (opcion)
		{
			case 1:
			ordenarJugadores(jugadores, tamJugador, confederaciones, tamConfederacion);
			mostrarJugadores(jugadores, tamJugador, confederaciones, tamConfederacion);
			retorno = 1;
			break;

		    case 2:
			listarConfederacionesConSusJugadores(jugadores, tamJugador, confederaciones, tamConfederacion);
			retorno = 1;
		    break;

		    case 3:
			calcularSalarios(jugadores, tamJugador, &total, &promedio, &contadorMayor);
			mensajeFlotante("El total de salario de los jugadores es -> ", total);
			mensajeFlotante("El promedio de salario de los jugadores es -> ", promedio);
			mensajeEntero("La cantidad de jugadores que superan el salario promedio es -> ", contadorMayor);
			retorno = 1;
			break;

			case 4:
			buscarConfederacionMayor(jugadores, tamJugador, confederaciones, tamConfederacion);
			retorno = 1;
			break;

			case 5:
			porcentajeCadaConfederacion(jugadores, tamJugador, confederaciones, tamConfederacion);
            retorno = 1;
			break;

		    case 6:
			regionConMasJugadores(jugadores, tamJugador, confederaciones, tamConfederacion);
			retorno = 1;
			break;

			case 7:
			printf("\nSalio del menu de forma exitosa. \n");
			break;
		}

	} while (opcion != 7);

	return retorno;
}

void ordenarJugadores(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion)
{
	int i;
	int j;
	char cadenaUno[TAM_CARATER];
	char cadenaDos[TAM_CARATER];
	eJugador auxiliar;

	for(i=0;i<tamJugador-1;i++)
	{
		if(jugadores[i].isEmpty == OCUPADO && buscarNombreConfederacion(confederaciones, tamConfederacion, jugadores[i].idConfederacion, cadenaUno) == 1)
		{
			for(j=i+1;j<tamJugador;j++)
			{
				if(jugadores[j].isEmpty == OCUPADO && buscarNombreConfederacion(confederaciones, tamConfederacion, jugadores[j].idConfederacion, cadenaDos) == 1)
				{
					if(strcmp(cadenaUno, cadenaDos) > 0)
					{
						auxiliar = jugadores[i];
						jugadores[i] = jugadores[j];
						jugadores[j] = auxiliar;
					}

					else
					{
						if(strcmp(cadenaUno, cadenaDos) == 0 && strcmp(jugadores[i].nombre, jugadores[j].nombre) > 0)
						{
							auxiliar = jugadores[i];
							jugadores[i] = jugadores[j];
						    jugadores[j] = auxiliar;
						}
					}

				}
			}

		}
	}
}

void buscarConfederacionMayor(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion)
{
	int i;
	int j;
	float acumulador[TAM_CONFEDERACION];
	float mayor;

	inicializarAcumulador(acumulador, TAM_CONFEDERACION);

	for(i=0;i<tamConfederacion;i++)
	{
		if(confederaciones[i].isEmpty == OCUPADO)
		{
			for(j=0;j<tamJugador;j++)
			{
				if(jugadores[j].isEmpty == OCUPADO && jugadores[j].idConfederacion == confederaciones[i].id)
				{
					acumular(&acumulador[i], jugadores[j].aniosContrato);
				}
			}
		}
	}

	mayor = buscarMayorFlotante(acumulador, TAM_CONFEDERACION);

    mostrarMayoresConfederaciones(confederaciones, tamConfederacion, mayor, acumulador);
}

void jugadoresDeCadaConfederacion(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion, int contador[])
{
	int i;
	int j;

	for(i=0;i<tamConfederacion;i++)
	{
		if(confederaciones[i].isEmpty == OCUPADO)
		{
			for(j=0;j<tamJugador;j++)
			{
				if(jugadores[j].isEmpty == OCUPADO && jugadores[j].idConfederacion == confederaciones[i].id)
				{
				   contar(&contador[i]);
				}
			}
		}
	}
}

void porcentajeCadaConfederacion(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion)
{
	int i;
	int contadorTotal;
	int contador[TAM_CONFEDERACION];
	int porcentajes[TAM_CONFEDERACION];

	contadorTotal = 0;
	inicializarContador(contador, tamConfederacion);

	for(i=0;i<tamJugador;i++)
	{
		if(jugadores[i].isEmpty == OCUPADO)
		{
			contar(&contadorTotal);
		}
	}

	jugadoresDeCadaConfederacion(jugadores, tamJugador, confederaciones, tamConfederacion, contador);
	calcularPorcentajes(contador, tamConfederacion, contadorTotal, porcentajes);
	mostrarPorcentajesConfederaciones(confederaciones, tamConfederacion, porcentajes);

}

void regionConMasJugadores(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion)
{
	int contador[TAM_CONFEDERACION];
	int mayor;

	inicializarContador(contador, tamConfederacion);

	jugadoresDeCadaConfederacion(jugadores, tamJugador, confederaciones, tamConfederacion, contador);

	mayor = buscarMayorEntero(contador, TAM_CONFEDERACION);

	listarRegionesConMayorDeJugadores(jugadores, tamJugador, confederaciones, tamConfederacion, contador, mayor);

}
