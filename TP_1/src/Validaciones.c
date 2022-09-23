#include "Validaciones.h"

//Juan Sebastian Amarilla 1k

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
