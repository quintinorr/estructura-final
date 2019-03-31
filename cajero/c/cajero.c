/*
Grupo 5 Estructura de datos.
Encontrar el mínimo número de Billetes y/o monedas para representar una cantidad de dinero dada.
Creado por Javier Mercedes.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//Primero, creamos un array con los billetes que vamos a utilizar
   	int denominacion[] = {2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};
   	// creamos las variables a utilizar durante el proceso
   	int cantidad;
   	int resultado;
   	int i;
   
   	//Pedimos al usuario que ingrese la cantidad a calcular
   	printf("Introduce la cantidad a calcular: ");
   	fflush(stdout);
   	if (scanf("%d", &cantidad) != 1 || cantidad < 1)
      	return EXIT_FAILURE;
   
   	for (i = 0; cantidad > 0; i++)
   	{
   		if ((resultado = cantidad / denominacion[i]) > 0)
		{
         	printf("Billetes de %3d: %d\n", denominacion[i], resultado);
         	cantidad %= denominacion[i];
    	}	
	}
      	
   
   return EXIT_SUCCESS;
}
