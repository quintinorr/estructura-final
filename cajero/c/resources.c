#include <stdlib.h>
#include <stdio.h>

// Grupo 5 estructura de datos.
// Archivo con funciones utilitarias para el uso del programa principal.

// Declaración de las estructuras de datos.

//****** Lista enlazada que almacenará los resultados del cálculo ******.
	typedef struct {
		float currency;
		int count;
	} CurrencyResult;
	
	typedef struct resultnode {
	    CurrencyResult data;
	    struct resultnode* next;
	} RESULTNODE;
	
	// Función que inicializa una nueva lista.
	void InitResult(RESULTNODE** head) {
		*head = NULL;
	}
	
	//Función para agregar un nuevo valor a la lista.
	RESULTNODE* AddResultNode(RESULTNODE* node, CurrencyResult data) {
		// Creamos un espacio en memoria para almacenar nuestro nuevo nodo.
	    RESULTNODE* temp = (RESULTNODE*) malloc(sizeof (RESULTNODE));
	    if (temp == NULL) {
	    	// Devuelve NULL si no hay espacio en memoria disponible para el nuevo nodo. 
			// Es díficil que esta situación se dé en equipos modernos pero es mejor prevenir.
	        exit(0);
	    }
	    // A nuestra variable temp (el espacio que creamos en memoria),
	    // le asignamos el dato que recibimos como parámetro de la función.
	    temp->data = data;
	    // Almacenamos el último nodo de la lista en next.
	    temp->next = node;
	    node = temp;
	    // Retornamos nuestra lista con el  nuevo nodo agregado.
	    return node;
	    
	}

	// Funciones auxiliares.
		
		RESULTNODE* RESULT = NULL;
		
		void AddToResult(float amount, int count) {
			CurrencyResult data = {amount, count};
			RESULT = AddResultNode(RESULT, data);
		}

		
		void PrintResult() {
		    RESULTNODE * temp;
	    	for (temp = RESULT; temp; temp = temp->next)
	        	printf("-%d billetes de %.2f \n", temp->data.count, temp->data.currency);
		}
		
		int GetResultLength() {
			int count = 0;
			RESULTNODE * temp;
	    	for (temp = RESULT; temp; temp = temp->next)
	        	count++;
	        return count;
		}
		
		// Limpiamos la lista.
		// Podemos limpiar la lista simplemente asignandole NULL a RESULT,
		// Pero el espacio en memoria quedaría en uso, por lo que es preferible que 
		// se limpie la lista por cada elemento y se libere ese espacio en memoria.
		void ClearResult() {
			RESULTNODE *tmpPtr = RESULT;
		    RESULTNODE *followPtr;
		    while (tmpPtr != NULL) {
		        followPtr = tmpPtr;
		        tmpPtr = tmpPtr->next;
		        free(followPtr);
		    }
		    RESULT = NULL;
		}
	//Fin Funciones Auxiliares.

// ********************************* FIN RESULT *********************************

//****** Lista enlazada que almacenará todas las monedas para el calculo ******.

	typedef struct {
	    float amount;
	} Currency;
	
	typedef struct stocknode {
		Currency data;
		struct stocknode* next;	
	} STOCKNODE;
	
	// Función que inicializa una nueva lista.
	void InitCurrency(STOCKNODE** head) {
		*head = NULL;
	}
	
	//Función para agregar un nuevo valor a la lista.
	STOCKNODE* AddCurrencyNode(STOCKNODE* node, Currency data) {
		STOCKNODE* temp = (STOCKNODE*) malloc(sizeof (STOCKNODE));
		
	    if (temp == NULL) {
	        exit(0);
	    }
	    
	    temp->data = data;
	    temp->next = node;
	    node = temp;
	    
	    return node;
	}
	
	STOCKNODE * ReverseCurrencyNode(STOCKNODE * node) {
	    STOCKNODE * temp;
	    STOCKNODE * previous = NULL;
	    while (node != NULL) {
	        temp = node->next;
	        node->next = previous;
	        previous = node;
	        node = temp;
	    }
	    return previous;
	}
	
	STOCKNODE * ClearCurrencyNode(STOCKNODE *head) {
	    STOCKNODE *tmpPtr = head;
	    STOCKNODE *followPtr;
	    while (tmpPtr != NULL) {
	        followPtr = tmpPtr;
	        tmpPtr = tmpPtr->next;
	        free(followPtr);
	    }
	    return NULL;
	}
	
	void RemoveCurrencyNode(STOCKNODE* head) {
	    STOCKNODE* temp = (STOCKNODE*) malloc(sizeof (STOCKNODE));
	    if (temp == NULL) {
	        exit(EXIT_FAILURE);
	    }
	    
	    /*
	    temp = head->next;
	    head->next = head->next->next;
	    */
		temp = head;
	    //head->next = head->next->next;
	    head = head->next;
	    
	    free(temp);
	}
	
	//Funciones Auxiliares
		STOCKNODE* CURRENCIES_LIST_NODE = NULL;
		
		void ClearCurrency() {
			CURRENCIES_LIST_NODE = ClearCurrencyNode(CURRENCIES_LIST_NODE);
		}
		
		void ReverseCurrency() {
			CURRENCIES_LIST_NODE = ReverseCurrencyNode(CURRENCIES_LIST_NODE);
		}
	
		int GetCurrencyLength() {
			int count = 0;
			STOCKNODE * temp;
	    	for (temp = CURRENCIES_LIST_NODE; temp; temp = temp->next)
	        	count++;
	        return count;
		}
		
		void PrintCurrency() {
		    STOCKNODE * temp;
	    	for (temp = CURRENCIES_LIST_NODE; temp; temp = temp->next)
	        	printf("%.2f\n", temp->data.amount);
		}
		
		void AddCurrency(Currency data){
			CURRENCIES_LIST_NODE = AddCurrencyNode(CURRENCIES_LIST_NODE, data);
		}
		
		void AddCurrencyFromArray(float array[], int size) {
			ClearCurrency();
			int i;
			for(i = 0; (i < size && array[i] > 0); i++){
				Currency currency = { array[i] };
				// currency.amount = array[i];
				AddCurrency(currency);
			}
			ReverseCurrency();
		}
		
		void RemoveFistCurrency() {
			RemoveCurrencyNode(CURRENCIES_LIST_NODE);
		}
	// Fin Funciones Auxiliares

// ********************************* FIN CURRENCY *********************************

