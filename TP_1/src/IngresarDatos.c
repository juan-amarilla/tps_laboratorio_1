#include "IngresarDatos.h"

//Juan Sebastian Amarilla 1k

void pedirFlotanteValidado(char cadena[], char mensaje[], float* numero)
{
	int estado;

	printf("%s", mensaje);
	fflush(stdin);
	gets(cadena);

	estado = validarNumeroFlotante(numero, cadena);

	while(estado == 0 || strlen(cadena) == 0 || strlen(cadena) >= 51)
	{
		printf("Error: %s", mensaje);
		fflush(stdin);
		gets(cadena);
		estado = validarNumeroFlotante(numero, cadena);
	}
}
