#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "pila_dinamica.h"

int main(int argc, char const *argv[])
{
	Nodo *pila = NULL;

	push(&pila, 1);
	push(&pila, 2);
	push(&pila, 3);

	pop(&pila);
	pop(&pila);
	

	print_pila(pila);


	free(pila);
	return 0;
}