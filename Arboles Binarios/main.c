#include <stdio.h>
#include <stdlib.h>
#include "binario.h"

int main(int argc, char const *argv[])
{
	Nodo *raiz = NULL;

	insertar2(&raiz, 1);
	insertar2(&raiz, 2);
	insertar2(&raiz, 3);
	insertar2(&raiz, 4);
	insertar2(&raiz, 5);
	

	
	printf("izq I: %i\n", raiz->izq->i);
	printf("I: %i\n", raiz->i);
	printf("der I: %i\n", raiz->der->i);
	printf("der izq I: %i\n", raiz->der->izq->i);
	printf("der der I: %i\n", raiz->der->der->i);





	printf("Balance: %i\n", balance(raiz));



	return 0;
}