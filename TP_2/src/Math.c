//Juan Sebastian Amarilla 1k

#include "Math.h"

void acumular(float* acumulador, float valor)
{
	if(acumulador != NULL)
	{
		*acumulador = *acumulador + valor;
	}
}

float sacarPromedio(float total, int contador)
{
	float promedio;

	promedio = 0;

	if(total > 0 && contador > 0)
	{
		promedio = total / contador;
	}

	return promedio;
}

void contar(int* contador)
{
	if(contador != NULL)
	{
		*contador = *contador + 1;
	}
}

void inicializarAcumulador(float acumulador[], int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		acumulador[i] = 0;
	}
}

float buscarMayorFlotante(float numero[], int tam)
{
	float mayor;
	int i;

	for(i=0;i<tam;i++)
	{
		if(i == 0)
		{
		   mayor = numero[i];
		}

		else
		{
			if(numero[i] > mayor)
			{
				 mayor = numero[i];
			}
		}
	}

	return mayor;
}

int buscarMayorEntero(int numero[], int tam)
{
	int mayor;
	int i;

	for(i=0;i<tam;i++)
	{
		if(i == 0)
		{
			mayor = numero[i];
		}

		else
		{
			if(numero[i] > mayor)
			{
			    mayor = numero[i];
			}
		}
	}

	return mayor;
}


void inicializarContador(int contador[], int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		contador[i] = 0;
	}
}

void calcularPorcentajes(int contador[], int tam, int total, int porcentajes[])
{
	int i;

	for(i=0;i<tam;i++)
	{
		porcentajes[i] = contador[i] * 100 / total;
	}

}
