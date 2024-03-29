#include "LosMensajes.h"

//Juan Sebastian Amarilla 1k

void mensaje(char* informacion)
{
	printf("%s", informacion);

}

void mensajeGasto(char* informacion, float gasto)
{
	printf("%s %.2f \n", informacion, gasto);
}

void mensajePosicion(char* informacion, int posicion)
{
	printf("%s %d \n", informacion, posicion);
}

void informeResultados(float promedio[], float costoMantenimiento, float aumento, float costoMantenimientoNuevo,  int tam)
{
	int i;
	char confederacion[6][31] = { {"-Porcentaje de AFC ->"},
                                  {"-Porcentaje de CAF ->"},
                                  {"-Porcentaje de CONCACAF ->"},
                                  {"-Porcentaje de CONMEBOL ->"},
                                  {"-Porcentaje de UEFA ->"},
                                  {"-Porcentaje de OFC ->"} };

	for(i=0;i<tam;i++)
	{
		mensajeGasto(confederacion[i], promedio[i]);
	}

	mensajeGasto("El costo de mantenimiento es ->", costoMantenimiento);
	mensajeGasto("El costo del aumento es ->", aumento);
	mensajeGasto("El costo del mantenimiento con aumento es ->", costoMantenimientoNuevo);

}
