#include "Output.h"

//Juan Sebastian Amarilla 1k

void mensaje(char* informacion)
{
	printf("%s", informacion);

}

void mensajeEstado(int estado, char valido[], char noValido[])
{
	if(estado == 1)
	{
	  printf("%s", valido);
	}

	else
	{
		printf("%s", noValido);
	}
}

void mostrarJugadores(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion)
{
	int i;
	int j;

	printf("=================================================================================================================================================================================================\n");
	printf("|ID\t|NOMBRE\t\t|POSICION\t\t|NUMERO DE CAMISETA\t\t|CONFEDERACION\t\t\t\t|SALARIO\t\t\t|ANIOS DE CONTRATO\t\t\t|\n");
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");


	for(i=0;i<tamJugador;i++)
	{
		if(jugadores[i].isEmpty == OCUPADO)
		{
			for(j=0;j<tamConfederacion;j++)
			{
				if(confederaciones[j].isEmpty == OCUPADO && jugadores[i].idConfederacion == confederaciones[j].id)
				{
					mostrarJugador(jugadores[i], confederaciones[j]);
				}

			}

		}

	}

	printf("=================================================================================================================================================================================================\n");

}

void mostrarJugador(eJugador jugador, eConfederacion confederacion)
{
	printf("|%5d\t|%10s\t|%15s\t|%20d\t\t|%25s\t\t|%30.2f\t|%35d\t|\n", jugador.id,
			                                                            jugador.nombre,
				                                                        jugador.posicion,
																        jugador.numeroCamiseta,
																	    confederacion.nombre,
																	    jugador.salario,
																	    jugador.aniosContrato);

}

void listarConfederacionesConSusJugadores(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion)
{
	int i;
	int j;
	int estado;

	for(i=0;i<tamConfederacion;i++)
	{
		estado = 0;

		if(confederaciones[i].isEmpty == OCUPADO)
		{
			for(j=0;j<tamJugador;j++)
			{
				if(jugadores[j].isEmpty == OCUPADO && jugadores[j].idConfederacion == confederaciones[i].id)
				{
					if(estado == 0)
					{
						printf("Listado de jugadores de la confederacion %s: \n\n", confederaciones[i].nombre);
						printf("=================================================================================================================================================================================================\n");
						printf("|ID\t|NOMBRE\t\t|POSICION\t\t|NUMERO DE CAMISETA\t\t|CONFEDERACION\t\t\t\t|SALARIO\t\t\t|ANIOS DE CONTRATO\t\t\t|\n");
						printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
					}

					mostrarJugador(jugadores[j], confederaciones[i]);
					estado = 1;
				}
			}

			if(estado == 1)
			{
			  printf("==================================================================================================================================================================================================\n");
			}

		}
	}

}

void mensajeFlotante(char* informacion, float flotante)
{
	printf("%s %.2f\n", informacion, flotante);
}

void mensajeEntero(char* informacion, int entero)
{
	printf("%s %d\n", informacion, entero);
}

void listarRegionesConMayorDeJugadores(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion, int contador[], int mayor)
{
	int i;
	int j;

	for(i=0;i<tamConfederacion;i++)
	{
		if(confederaciones[i].isEmpty == OCUPADO && contador[i] == mayor)
		{
			printf("Listado de jugadores de la region %s: \n", confederaciones[i].region);
			printf("=================================================================================================================================================================================================\n");
		    printf("|ID\t|NOMBRE\t\t|POSICION\t\t|NUMERO DE CAMISETA\t\t|CONFEDERACION\t\t\t\t|SALARIO\t\t\t|ANIOS DE CONTRATO\t\t\t|\n");
			printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

			for(j=0;j<tamJugador;j++)
			{
				if(jugadores[j].isEmpty == OCUPADO && jugadores[j].idConfederacion == confederaciones[i].id)
				{
					mostrarJugador(jugadores[j], confederaciones[i]);
				}
			}

			printf("==================================================================================================================================================================================================\n");
		}
	}
}
