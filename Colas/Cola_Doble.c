#include <stdio.h>
#include <stdlib.h>

// Struct Nodo
typedef struct Nodo{
	int i;
	struct Nodo *sig;
	struct Nodo *ant;
}Nodo;

// Struct Cola
typedef struct Cola{
	Nodo *inicio;
	Nodo *final;
}Cola;

// Crear espacio en memoria para crear la cola

Nodo* crear_nodo(int valor){
	Nodo *new = (Nodo*) malloc(sizeof(Nodo));
	new->i = valor;
	new->sig = new->ant = NULL;
	return new;
}

Cola* crear_cola(){
	Cola *new = (Cola*) malloc(sizeof(Cola));
	new->inicio = new->final = NULL;
	return new;
}

// Longitud de la lista
int length_cola(Cola *cola){
	if (!cola->inicio)
		return 0;
	Nodo *aux = cola->inicio;
	return 1 + length_cola()
}


// Insertar valores en la cola
int insertar_cola_doble(Cola *cola, int dato){
	Nodo *new = crear_nodo(dato);

	if (!cola->inicio)
		cola->inicio = cola->final = new;
	else{
		cola->final->sig = new;
		new->ant = cola->final;
		cola->final = new; 
	}

	printf("Insert Value\n");
	return 0;
}

int delete_value(Cola *cola){
	if (!cola->inicio)
	{
		printf("Cola vacia\n");
		return 0;
	}

	Nodo *aux = cola->inicio;
	cola->inicio = cola->inicio->sig;

	aux = NULL;
	free(aux);

	printf("Delete cola\n");
	return 1;
}

void print_cola(Cola *cola){
	for(Nodo *aux = cola->inicio; aux; aux = aux->sig)
		printf("I: %i\n", aux->i);
	printf("End.\n");
}

void liberar_cola(Cola *cola){
	if (!cola->inicio || !cola){
		printf("Cola liberada\n"); 
		return;
	}

	while(cola->inicio){
		Nodo *aux = cola->inicio;
		cola->inicio = cola->inicio->sig;

		aux = NULL;
		free(aux);
	}

	printf("End\n");
}

void sort_values(Cola *cola){
	if (!cola->inicio)
	{
		printf("Empty Cola\n");
		return;
	}

	Nodo *aux = cola->inicio;
	for(; aux; aux = aux->sig){
		a
	}

}

int main(int argc, char const *argv[])
{
	Cola *cola = crear_cola();

	insertar_cola_doble(cola, 1);
	insertar_cola_doble(cola, 2);
	insertar_cola_doble(cola, 3);

	delete_value(cola);

	print_cola(cola);

	return 0;
}