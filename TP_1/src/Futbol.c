#include "Futbol.h"

//Juan Sebastian Amarilla 1k

int ingresarGasto(float* gastoHospedaje, float* gastoComida, float* gastoTransporte)
{
	int opcion;
	int retorno;
	int estado;
	char cadena[51];

	retorno = 0;

	do
	{
		  mensaje("1-Gasto de hospedaje. \n"
				  "2-Gasto de comida. \n"
				  "3-Gasto de transporte. \n"
				  "4-Salir. \n");

		  mensajeGasto("Gasto de hospedaje ->", *gastoHospedaje);
		  mensajeGasto("Gasto de comida ->", *gastoComida);
		  mensajeGasto("Gasto de transporte ->", *gastoTransporte);

		  estado = utn_getNumero(&opcion, "Ingrese una opcion: \n", "Error, ingrese una opcion valida: \n", MIN_FUTBOL, MAX_FUTBOL, INTENTOS_FUTBOL);

		  if (estado == 0 && gastoHospedaje != NULL && gastoComida != NULL && gastoTransporte != NULL)
		  {
			 switch (opcion)
			 {

					 case 1:
				     pedirFlotanteValidado(cadena,"Ingrese un valor: \n" , gastoHospedaje);
				     while(*gastoHospedaje <= 0)
				     {
				    	 pedirFlotanteValidado(cadena,"Ingrese un valor mayor a 0: \n" , gastoHospedaje);
				     }
				     retorno = 1;
					 break;

					 case 2:
					 pedirFlotanteValidado(cadena,"Ingrese un valor: \n" , gastoComida);
					 while(*gastoComida <= 0)
					 {
		                pedirFlotanteValidado(cadena,"Ingrese un valor mayor a 0: \n" , gastoComida);
					 }
					 retorno = 1;
					 break;

					 case 3:
					 pedirFlotanteValidado(cadena,"Ingrese un valor: \n" , gastoTransporte);
					 while(*gastoTransporte <= 0)
					 {
			            pedirFlotanteValidado(cadena,"Ingrese un valor mayor a 0: \n" , gastoTransporte);
					 }
					 retorno = 1;
					 break;

					 case 4:
					 mensaje("Salio del menu de forma exitosa. \n");
					 break;

			  }
			}

			else
			{
				mensaje( "Se detecto muchos intentos fallidos, se cerrara el menu. \n");
				break;
			}


	}while (opcion != 4);

	return retorno;

}

int ingresarJugador(int numeroCamiseta[], int* arquero, int* defensor, int* mediocampista, int* delantero, int confederacion[], int tamConfederacion, int tamCamiseta)
{
	int opcion;
	int retorno;
	int estado;
	int i;
	int elegir;

	estado = 1;

	for(i=0;i<tamCamiseta;i++)
	{
		if(numeroCamiseta[i] == 0)
		{
			estado = utn_getNumero(&elegir, "Ingrese el numero de camiseta entre 1 hasta 22: \n", "Error, ingrese un numero valido de camiseta entre 1 hasta 22: \n", MIN_JUGADOR, MAX_JUGADOR, INTENTOS_FUTBOL);
			elegir = validarCamiseta(numeroCamiseta, tamCamiseta, elegir);
			numeroCamiseta[i] = elegir;
			break;
		}

	}

	if(estado == 0 && arquero != NULL && defensor != NULL && mediocampista != NULL && delantero != NULL)
	{
		mensaje("\n1-Arquero. \n"
				"2-Defensor. \n"
				"3-MedioCampista. \n"
				"4-Delantero. \n");

		mensajePosicion("Cantidad de arqueros ->", *arquero);
		mensajePosicion("Cantidad de defensores ->", *defensor);
		mensajePosicion("Cantidad de mediocampistas ->", *mediocampista);
		mensajePosicion("Cantidad de delanteros ->", *delantero);

	    estado = utn_getNumero(&opcion, "Ingrese una posicion: \n", "Error, ingrese una posicion valida: \n", MIN_FUTBOL, MAX_FUTBOL, INTENTOS_FUTBOL);

	    if(estado == 0)
	    {
	    	switch(opcion)
	    	{
	    		case 1:
	    		if(*arquero != 2)
	    		{
	    		  *arquero+=1;
	    		  retorno = menuConfederacion(confederacion, tamConfederacion);
	    		}
	    	    break;

	    		case 2:
	    		if(*defensor != 8)
	    		{
	    		   *defensor+=1;
	    		   retorno = menuConfederacion(confederacion, tamConfederacion);
	    		}
	    		break;

	    		case 3:
	    		if(*mediocampista != 8)
	    		{
	    		   *mediocampista+=1;
	    		   retorno = menuConfederacion(confederacion, tamConfederacion);
	    		}
	    		break;

	    		case 4:
	    		if(*delantero != 4)
	    		{
	    			*delantero+=1;
	    			retorno = menuConfederacion(confederacion, tamConfederacion);
	    		}
	    		break;
	       }

	    }

	    else
	    {
	    	mensaje("\nNo se pudo ingresar la posicion.\n");
	    }

	}

	else
	{
		mensaje("\nNo se pudo ingresar el numero de camiseta, volvera al menu. \n");
	}

	return retorno;

}

int validarCamiseta(int camisetas[], int tam, int elegido)
{
	int i;
	int estado;

	estado = 1;

	for(i=0;i<tam;i++)
	{
		while(camisetas[i] == elegido)
		{
			estado = utn_getNumero(&elegido, "Ingrese el numero de camiseta entre 1 hasta 22 no existente: \n", "Error, ingrese un numero valido de camiseta entre 1 hasta 22: \n", MIN_JUGADOR, MAX_JUGADOR, INTENTOS_FUTBOL);
		}

	}

	if(estado == 0)
	{
      mensaje("\nDato ingresado con exito. \n");
	}

	return elegido;

}

void inicializarConfederacion(int confederacion[], int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		confederacion[i] = 0;
	}
}

void inicializarCamiseta(int numeroCamiseta[], int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
	   numeroCamiseta[i] = 0;
	}
}

int menuConfederacion(int confederacion[], int tam)
{
	int retorno;
	int opcion;
	int estado;
	int i;

	retorno = 0;

	mensaje("1-AFC. \n"
			"2-CAF. \n"
			"3-CONCACAF. \n"
			"4-CONMEBOL. \n"
			"5-UEFA. \n"
			"6-OFC. \n");

	estado = utn_getNumero(&opcion, "Ingrese una opcion: \n", "Error, ingrese una opcion valida: \n", MIN_CONFEDERACION, MAX_CONFEDERACION, INTENTOS_FUTBOL);

	for(i=0;i<tam;i++)
	{
		if( (i == opcion-1) && (estado == 0) )
		{
			switch(opcion)
			{
				case 1:
				confederacion[i]++;
				retorno = 1;
				break;

				case 2:
				confederacion[i]++;
				retorno = 1;
				break;

				case 3:
				confederacion[i]++;
				retorno = 1;
				break;

				case 4:
				confederacion[i]++;
				retorno = 1;
				break;

				case 5:
				confederacion[i]++;
				retorno = 1;
				break;

				case 6:
				confederacion[i]++;
				retorno = 1;
				break;
			 }

			 break;

		}

	}

	return retorno;

}


int calculos(int confederacion[], float promedio[], float* gastoHospedaje, float* gastoComida, float* gastoTransporte, float* costoMantenimiento, float* aumento, float* costoMantenimientoNuevo, int tam)
{
	int retorno;
	int i;
	int total;
	int mayor;

	total = 0;
    retorno = -1;

	for(i=0;i<tam;i++)
	{
		if(i == 0)
		{
			mayor = confederacion[i];
		}

		else
		{
			if(mayor < confederacion[i])
			{
				mayor = confederacion[i];
			}
		}

		total = total + confederacion[i];
	}

	for(i=0;i<tam;i++)
	{
		promedio[i] =  (float) confederacion[i] * 100 / total;

		if(i == tam-1)
		{
			mensaje("\nSe logro calcular el promedio de jugadores de cada mercado. \n");
		}
	}

	if(gastoHospedaje != NULL && gastoComida != NULL && gastoTransporte != NULL && costoMantenimiento != NULL)
	{
		*costoMantenimiento = *gastoHospedaje + *gastoComida + *gastoTransporte;
		retorno = 0;
		mensaje("\nSe logro calcular el costo de mantenimiento. \n");
	}

	if(mayor == confederacion[4] && confederacion[4] > confederacion[0] && confederacion[4] > confederacion[1] && confederacion[4] > confederacion[2] && confederacion[4] > confederacion[3] && confederacion[4] > confederacion[5] && costoMantenimiento != NULL && aumento != NULL && costoMantenimientoNuevo != NULL)
	{
		*aumento = 35 * (*costoMantenimiento) / 100;
		*costoMantenimientoNuevo = *costoMantenimiento + *aumento;
		retorno = 1;
		mensaje("\nSe logro calcular el aumento del costo de mantenimiento. \n");
	}

	return retorno;

}
