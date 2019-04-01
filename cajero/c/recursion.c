#include <stdlib.h>
#include <stdio.h>
#include "resources.c"

float CURRENCIES[] = { 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1 };

// Creamos una lista enlazada tomando en cuenta nuestro arreglo de monedas.
void CreateCurrencyList() {
	int len = sizeof(CURRENCIES) / sizeof(float);
	AddCurrencyFromArray(CURRENCIES, len);
}


void CalculateCash() {
	
}


void main() {
	CreateCurrencyList();
	RemoveFistCurrency();
	PrintCurrency();
	/*
	float cash = 1300;
	AddToResult(16.8, 13);
	PrintResult();
	*/
}
