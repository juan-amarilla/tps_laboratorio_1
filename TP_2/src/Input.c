#include "Input.h"

//Juan Sebastian Amarilla 1k

void pedirEnteroValidado(char cadena[], char mensaje[], int* numero)
{
	int estado;

	if(numero != NULL && cadena != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		gets(cadena);

		estado = validarNumeroEntero(numero, cadena);

		while(estado == -1 || strlen(cadena) == 0 || strlen(cadena) > TAM_CARATER)
		{
			printf("Error: %s", mensaje);
			fflush(stdin);
			gets(cadena);
			estado = validarNumeroEntero(numero, cadena);
		}

	}
}

void pedirCortoValidado(char cadena[], char mensaje[], short* numero)
{
	int estado;

	if(numero != NULL && cadena != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		gets(cadena);

		estado = validarNumeroCorto(numero, cadena);

		while(estado == -1 || strlen(cadena) == 0 || strlen(cadena) > TAM_CARATER)
		{
			printf("Error: %s", mensaje);
			fflush(stdin);
			gets(cadena);
			estado = validarNumeroCorto(numero, cadena);
		}

	}
}

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

void pedirCadenaValidado(char cadena[], char mensaje[], char cadenaValidado[])
{
	int estado;

	printf("%s", mensaje);
	fflush(stdin);
	gets(cadena);

	estado = validarLetras(cadenaValidado, cadena);

	while(estado == 0 || strlen(cadena) == 0 || strlen(cadena) >= 51)
	{
	   printf("Error: %s", mensaje);
	   fflush(stdin);
	   gets(cadena);
	   estado = validarLetras(cadenaValidado, cadena);
	}

}
