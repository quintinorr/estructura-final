/*
Grupo 5 Estructura de datos.
Encontrar el mínimo número de Billetes y/o monedas para representar una cantidad de dinero dada.
Creado por Javier Mercedes.
*/
#include <stdio.h>

int main()
{
	//Primero, creamos un array con los billetes que vamos a utilizar 	
	int MONEDAS[9] = {1000, 2000, 200, 100, 50, 20, 10, 5, 1};

	// Creamos la variables a utilizar para ordenar los valores
	// del array de mayor a menor y para contar la cantidad de 
	// elementos en MONEDAS[]
	int i, pos, aux, countArray;
	
	// Contamos los elementos en MONEDA[]
	countArray = sizeof(MONEDAS) / sizeof(MONEDAS[0]);

	//creamos un bucle para ordenar los numeros por el 
	// metodo de insercion
	for (i = 0; i < countArray; i++)
	{
		pos = i;
		aux = MONEDAS[i];
		while ((pos > 0) && (aux < MONEDAS[pos-1]))
		{
			MONEDAS[pos] = MONEDAS[pos-1];
			pos--;
		}
		MONEDAS[pos] = aux;
	}
	
	
	
    return 0;
}
