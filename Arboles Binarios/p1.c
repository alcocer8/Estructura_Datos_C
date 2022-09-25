#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
	int dato;
	struct Nodo *izq;
	struct Nodo *der;	
}Nodo;

Nodo* crear_nodo(int dato){
	Nodo *new = (Nodo*) malloc(sizeof(Nodo));
	new->dato = dato;
	new->izq = NULL;
	new->der = NULL;
	return new;
}

int insertar(Nodo *raiz, int dato){
	// Prefuntamos si el dato es menor al que tiene el nodo raiz
	if (dato < raiz->dato)
	{
		// Insertamos en la izquierda
		if (raiz->izq)
			insertar(raiz->izq, dato);
		else
			raiz->izq = crear_nodo(dato);
	}else{
		// Insertamos en la derecha
		if (raiz->der) // Si derecha Tiene algo, insertamos el dato
			insertar(raiz->der, dato);
		else
			raiz->der = crear_nodo(dato);
	}
}

void preorden(Nodo *raiz){
	printf("Dato: %i\n", raiz->dato);
	if (raiz->izq)
		preorden(raiz->izq);
	
	if (raiz->der)
		preorden(raiz->der);
}

int main(int argc, char const *argv[])
{
	Nodo *raiz = crear_nodo(10);

	insertar(raiz, 22);
	insertar(raiz, 1);
	insertar(raiz, 23);
	insertar(raiz, 12);
	insertar(raiz, 32);
	insertar(raiz, 4);
	


	preorden(raiz);
	
	return 0;
}