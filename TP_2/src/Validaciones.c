#include "Validaciones.h"

//Juan Sebastian Amarilla 1k

int validarNumeroEntero(int* numeroEntero, char numero[])
{
	int i;
	int retorno;
	int entero;

	i = 0;
	retorno = 1;

	while (numero[i] != '\0')
	{
		if(isdigit(numero[i]) != 1)
		{
			retorno=-1;
			break;
		}

		i++;

	}

	if(retorno==1)
	{
		entero=atoi(numero);
		*numeroEntero=entero;

	}


	return retorno;
}

int validarNumeroCorto(short* numeroCorto, char numero[])
{
	int i;
	int retorno;
	short corto;

	i = 0;
	retorno = 1;

	while (numero[i] != '\0')
	{
		if(isdigit(numero[i]) != 1)
		{
			retorno=-1;
			break;
		}

		i++;

	}

	if(retorno==1)
	{
		corto=atoi(numero);
		*numeroCorto=corto;
	}


	return retorno;
}

int validarNumeroFlotante(float* numeroFlotante, char numero[])
{
	int validacion;
	int i;
	int flag;
	float flotante;

	validacion = 1;
	i = 0;
	flag = 0;

	while(numero[i] != '\0')
	{
		   if (numero[i] == '.' && flag == 0)
		   {
		    	  flag = 1;
		          i++;
		          continue;

		   }

		   if(isdigit(numero[i]) != 1)
		   {
		    	  validacion=0;
		          break;
		   }

		   i++;
	}

	if(validacion==1)
	{
			flotante=atof(numero);
			*numeroFlotante=flotante;

	}

	return validacion;

}

int validarLetras(char letras[], char caracter[])
{
	int validacion;
	int i;

	validacion = 1;
	i = 0;

	while(caracter[i]!='\0')
	{

	     if(isalpha(caracter[i]) == 0)
	     {
	    	if(isspace(caracter[i]) == 1 && i == 0)
	    	{
	    		validacion=0;
	    	    break;
	    	}

	    	else
	    	{
	    		validacion=0;
	    		break;
	    	}
	     }

	     i++;
	}

	if(validacion==1)
	{
	   strcpy(letras, caracter);

	}

	return validacion;
}

void mayusculasAutomaticos(char cadena[], int tam)
{
	  int i;

	  strlwr(cadena);

	  for(i=0;i<tam;i++)
	  {
		  if(isspace(cadena[i]) != 0)
		  {
			  cadena[i+1]= toupper(cadena[i+1]);

		  }

		  if(i == 0)
		  {
			  cadena[i] = toupper(cadena[i]);

		  }

	  }


}
