#include "Confederacion.h"

//Juan Sebastian Amarilla 1k

void mostrarConfederaciones(eConfederacion confederaciones[], int tamConfederacion)
{
	int i;

	printf("========================================================================================================================\n");
	printf("|ID\t\t|NOMBRE\t\t\t\t|REGION\t\t\t\t|ANIOS DE CREACION\t\t\t|\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");


	for(i=0;i<tamConfederacion;i++)
	{
		if(confederaciones[i].isEmpty == OCUPADO)
		{
      		mostrarConfederacion(confederaciones[i]);
		}
	}

	printf("========================================================================================================================\n");

}

void mostrarConfederacion(eConfederacion confederacion)
{
	printf("|%5d\t\t|%15s\t\t|%20s\t\t|%25d\t\t|\n", confederacion.id,
			                                    confederacion.nombre,
			                                    confederacion.region,
			                                    confederacion.aniosCreacion);
}

void mostrarMayoresConfederaciones(eConfederacion confederaciones[], int tamConfederacion, float mayor, float acumulador[])
{
	int i;

	for(i=0;i<tamConfederacion;i++)
	{
		if(confederaciones[i].isEmpty == OCUPADO && mayor == acumulador[i])
		{
			 mostrarMayorConfederacion(confederaciones[i], acumulador[i]);
		}
	}
}

void mostrarMayorConfederacion(eConfederacion confederaciones, float valor)
{
	printf("%s y sus anios de contrato fue -> %.0f\n", confederaciones.nombre, valor);

}

void mostrarPorcentajesConfederaciones(eConfederacion confederaciones[], int tamConfederacion, int porcentajes[])
{
	int i;

	for(i=0;i<tamConfederacion;i++)
	{
		if(confederaciones[i].isEmpty == OCUPADO)
		{
			mostrarPorcentajeConfederacion(confederaciones[i], porcentajes[i]);
		}
	}
}

void mostrarPorcentajeConfederacion(eConfederacion confederaciones, int porcentajes)
{
	printf("%s y su porcentajes de jugadores es -> %d\n", confederaciones.nombre, porcentajes);

}

int buscarIdDeConfederacion(eConfederacion confederaciones[], int tam, int id)
{
	int i;
	int retorno;

	retorno = 0;

	for(i=0;i<tam;i++)
	{
		if(confederaciones[i].isEmpty == OCUPADO && id == confederaciones[i].id)
		{
			retorno = 1;
			break;
		}
	}

	return retorno;

}

void inicializarConfederaciones(eConfederacion confederaciones[], int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		confederaciones[i].isEmpty = LIBRE;
	}
}

int buscarLibreConfederacion(eConfederacion confederaciones[], int tam)
{
	int indice;
    int i;

    indice = -1;

    for(i=0;i<tam;i++)
    {
    	if(confederaciones[i].isEmpty == LIBRE)
    	{
    		indice = i;
    		break;
    	}
    }

	return indice;

}

int verificarLlenoDeConfederaciones(eConfederacion confederaciones[], int tam)
{
	int i;
	int retorno;

	retorno = 0;

	for(i=0;i<tam;i++)
	{
		if(confederaciones[i].isEmpty == OCUPADO)
		{
			 retorno = 1;
             break;
		}
	}

	return retorno;
}

void definirConfederaciones(eConfederacion confederaciones[])
{
	eConfederacion auxiliar[TAM_CONFEDERACION] =  { {100,"CONMEBOL", "SUDAMERICA",1916, OCUPADO},
			                                        {101,"UEFA", "EUROPA",1954, OCUPADO},
			                                        {102,"AFC", "ASIA",1954, OCUPADO},
			                                        {103,"CAF", "AFRICA",1957, OCUPADO},
			                                        {104,"CONCACAF", "NORTE Y CENTRO AMERICA",1961, OCUPADO},
			                                        {105,"OFC", "OCEANIA",1966, OCUPADO} };

	confederaciones[0] = auxiliar[0];
	confederaciones[1] = auxiliar[1];
	confederaciones[2] = auxiliar[2];
	confederaciones[3] = auxiliar[3];
	confederaciones[4] = auxiliar[4];
	confederaciones[5] = auxiliar[5];
}

int buscarNombreConfederacion(eConfederacion confederaciones[], int tam, int id, char confederacion[])
{
	int retorno;
	int i;

	retorno = 0;

	for(i=0;i<tam;i++)
	{
		if(id == confederaciones[i].id)
		{
			strcpy(confederacion, confederaciones[i].nombre);
			retorno = 1;
			break;
		}

	}

	return retorno;

}

int altaConfederacion(eConfederacion confederaciones[], int tamConfederacion, int* auxiliar)
{
	int retorno;
	int indice;
	char cadena[TAM_CARATER];
	char cadenaValidado[TAM_CARATER];

	retorno = 0;

	indice = buscarLibreConfederacion(confederaciones, tamConfederacion);

	if(indice > -1 && auxiliar != NULL)
	{
		*auxiliar = *auxiliar + 1;
		confederaciones[indice].id = *auxiliar;

		pedirCadenaValidado(cadena, "Ingrese un nombre de confederacion: \n", cadenaValidado);
		mayusculasAutomaticos(cadenaValidado, TAM_CARATER);
		while(verificarNombreDeConfederacion(confederaciones, tamConfederacion, cadenaValidado) == 1)
		{
			pedirCadenaValidado(cadena, "Ingrese un nombre de confederacion que no exista por favor: \n", cadenaValidado);
			mayusculasAutomaticos(cadenaValidado, TAM_CARATER);
		}
		strcpy(confederaciones[indice].nombre, cadenaValidado);

		pedirCadenaValidado(cadena, "Ingrese una region de una confederacion: \n", cadenaValidado);
		mayusculasAutomaticos(cadenaValidado, TAM_CARATER);
		while(verificarRegionDeConfederacion(confederaciones, tamConfederacion, cadenaValidado) == 1)
		{
			pedirCadenaValidado(cadena, "Ingrese una region de confederacion que no exista por favor: \n", cadenaValidado);
			mayusculasAutomaticos(cadenaValidado, TAM_CARATER);
		}
		strcpy(confederaciones[indice].region, cadenaValidado);

		pedirEnteroValidado(cadena, "Ingrese el anio de creacion: \n", &confederaciones[indice].aniosCreacion);
		while(confederaciones[indice].aniosCreacion < 1800)
		{
			pedirEnteroValidado(cadena, "Ingrese el anio de creacion mayor a 1800: \n", &confederaciones[indice].aniosCreacion);
		}

		confederaciones[indice].isEmpty = OCUPADO;

		retorno = 1;
	}

	return retorno;

}

int verificarNombreDeConfederacion(eConfederacion confederaciones[], int tamConfederacion, char cadena[])
{
	int retorno;
	int i;

	retorno = 0;

	for(i=0;i<tamConfederacion;i++)
	{
		if(confederaciones[i].isEmpty == OCUPADO && strcmp(cadena, confederaciones[i].nombre) == 0)
		{
			retorno = 1;
			break;
		}
	}

	return retorno;
}

int verificarRegionDeConfederacion(eConfederacion confederaciones[], int tamConfederacion, char cadena[])
{
	int retorno;
	int i;

	retorno = 0;

	for(i=0;i<tamConfederacion;i++)
	{
		if(confederaciones[i].isEmpty == OCUPADO && strcmp(cadena, confederaciones[i].region) == 0)
		{
			retorno = 1;
			break;
		}
	}

	return retorno;
}

int bajaConfederacion(eConfederacion confederaciones[], int tamConfederacion)
{
	int retorno;
	int indice;
	int confederacion;
	char cadena[TAM_CARATER];

	retorno = 0;

	mostrarConfederaciones(confederaciones, tamConfederacion);
    pedirEnteroValidado(cadena, "Ingrese el id de la confederacion a realizar la baja: \n", &confederacion);
	indice = buscarConfederacion(confederaciones, tamConfederacion, confederacion);

	if(indice > -1)
	{
		confederaciones[indice].isEmpty = LIBRE;
		retorno = 1;
	}

	return retorno;

}

int buscarConfederacion(eConfederacion confederaciones[], int tamConfederacion, int confederacionElegido)
{
	int i;
	int indice;

	indice = -1;

	for(i=0;i<tamConfederacion;i++)
	{
	    if(confederaciones[i].isEmpty == OCUPADO && confederaciones[i].id == confederacionElegido)
	    {
	    	indice = i;
	    	break;
	    }
	}

    return indice;
}

int modificarConfederacion(eConfederacion confederaciones[], int tamConfederacion)
{
	int retorno;
	int opcion;
	int confederacion;
	int indice;
	char cadena[TAM_CARATER];
	char cadenaValidado[TAM_CARATER];

	retorno = 0;

	mostrarConfederaciones(confederaciones, tamConfederacion);
	pedirEnteroValidado(cadena, "Ingrese el id de la confederacion a modificar: \n", &confederacion);
	indice = buscarConfederacion(confederaciones, tamConfederacion, confederacion);

	if(indice > -1)
	{
		do
		{
			printf("\n1-Modificar nombre. \n"
					"2-Modificar region. \n"
					"3-Modificar anio de creacion. \n"
					"4-Salir. \n");

			pedirEnteroValidado(cadena, "Ingrese una opcion: \n", &opcion);

			switch(opcion)
			{
			   case 1:
			   pedirCadenaValidado(cadena, "Ingrese un nombre de confederacion: \n", cadenaValidado);
			   mayusculasAutomaticos(cadenaValidado, TAM_CARATER);
			   while(verificarNombreDeConfederacion(confederaciones, tamConfederacion, cadenaValidado) == 1)
			   {
				   			pedirCadenaValidado(cadena, "Ingrese un nombre de confederacion que no exista por favor: \n", cadenaValidado);
				   			mayusculasAutomaticos(cadenaValidado, TAM_CARATER);
			   }
			   strcpy(confederaciones[indice].nombre, cadenaValidado);
			   retorno = 1;
			   break;

			   case 2:
			   pedirCadenaValidado(cadena, "Ingrese una region de una confederacion: \n", cadenaValidado);
			   mayusculasAutomaticos(cadenaValidado, TAM_CARATER);
			   while(verificarRegionDeConfederacion(confederaciones, tamConfederacion, cadenaValidado) == 1)
			   {
				   pedirCadenaValidado(cadena, "Ingrese una region de confederacion que no exista por favor: \n", cadenaValidado);
				   mayusculasAutomaticos(cadenaValidado, TAM_CARATER);
			   }
			   strcpy(confederaciones[indice].region, cadenaValidado);
			   retorno = 1;
			   break;

			   case 3:
               pedirEnteroValidado(cadena, "Ingrese el anio de creacion: \n", &confederaciones[indice].aniosCreacion);
			   while(confederaciones[indice].aniosCreacion < 1800)
			   {
				  pedirEnteroValidado(cadena, "Ingrese el anio de creacion mayor a 1800: \n", &confederaciones[indice].aniosCreacion);
			   }
			   break;

			   case 4:
			   printf("\nSalio del menu de forma exitosa. \n");
			   retorno = 1;
			   break;
			}

		} while (opcion != 4);

	}

	return retorno;

}
