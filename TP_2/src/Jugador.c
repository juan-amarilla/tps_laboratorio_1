#include "Jugador.h"

//Juan Sebastian Amarilla 1k

void inicializarJugadores(eJugador jugadores[], int tamJugador)
{
	int i;

	for(i=0;i<tamJugador;i++)
	{
		jugadores[i].isEmpty = LIBRE;
	}
}

int buscarLibreJugador(eJugador jugadores[], int tamJugador)
{
	int indice;
    int i;

    indice = -1;

    for(i=0;i<tamJugador;i++)
    {
    	if(jugadores[i].isEmpty == LIBRE)
    	{
    		indice = i;
    		break;
    	}
    }

	return indice;

}

int buscarJugador(eJugador jugadores[], int tamJugador, int jugadorElegido)
{
	int i;
	int indice;

	indice = -1;

	for(i=0;i<tamJugador;i++)
	{
	    if(jugadores[i].isEmpty == OCUPADO && jugadores[i].id == jugadorElegido)
	    {
	    	indice = i;
	    	break;
	    }
	}

    return indice;

}

int verificarLlenoDeJugadores(eJugador jugadores[], int tamJugador)
{
	int i;
	int retorno;

	retorno = 0;

	for(i=0;i<tamJugador;i++)
	{
		if(jugadores[i].isEmpty == OCUPADO)
		{
			 retorno = 1;
             break;
		}
	}

	return retorno;
}

void calcularSalarios(eJugador jugadores[], int tamJugador, float* total, float* promedio, int* contadorMayor)
{
	int i;
	int contador;

	contador = 0;

	if(total != NULL && promedio != NULL && contadorMayor != NULL)
	{
		for(i=0;i<tamJugador;i++)
		{
			if(jugadores[i].isEmpty == OCUPADO)
			{
				acumular(total, jugadores[i].salario);
				contar(&contador);
			}
		}

		*promedio = sacarPromedio(*total, contador);

		for(i=0;i<tamJugador;i++)
		{
			if(jugadores[i].salario > *promedio && jugadores[i].isEmpty == OCUPADO)
			{
				contar(contadorMayor);
			}
		}
	}
}

void ordenarJugadoresPorId(eJugador jugadores[], int tamJugador)
{
	int i;
	int j;
	eJugador auxiliar;

	for(i=0;i<tamJugador-1;i++)
	{
		if(jugadores[i].isEmpty == OCUPADO)
		{
			for(j=i+1;j<tamJugador;j++)
			{
				if(jugadores[j].isEmpty == OCUPADO)
				{
					if(jugadores[i].id < jugadores[j].id)
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
