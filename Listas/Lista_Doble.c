//Lista doble
#include <stdio.h>
#include <stdlib.h>

//Struct Nodo
typedef struct Nodo
{
	int i;
	struct Nodo *sig;
	struct Nodo *ant;
}Nodo;

//Reservar Memoria
Nodo* reservar_memoria(){
	Nodo *new = (Nodo*) malloc(sizeof(Nodo));
	if (!new)
		return NULL;

	printf("Ingresa un valor: "); scanf("%i", &new->i);
	new->ant = new->sig = NULL;

	return new;
}


// Insertando valores a la lista
int insert(Nodo **list){
	Nodo* new = reservar_memoria();

	if(!*list)
		*list = new;
	else{
		new->sig = *list;
		(*list)->ant = new;
		*list = new;
	}

	printf("Value insert\n");
}

//Insertando valores al final de la lista
int insert_end(Nodo **list){
	Nodo *new = reservar_memoria();
	Nodo *aux = *list;

	for(; aux->sig; aux = aux->sig){}

	new->ant = aux;
	aux->sig = new;

	printf("Value Insert\n");
}

// Eliminando el primer elemento de la lista
int delete(Nodo **list){
	if (!*list)
		return 0;

	Nodo *aux = *list;
	*list = (*list)->sig;

	aux = NULL;
	free(aux);

	printf("Value delete.\n");
}

Nodo * search_value(Nodo **list){
	if (!*list)
		return NULL;

	int n = 0;
	Nodo *aux = *list;

	printf("Insera el valor buscado: "); scanf("%i", &n);

	for(; aux && (aux->i != n); aux = aux->sig){}

	if (!aux)
		return NULL;

	return aux;
}

// Modificando un valor especificado
void update(Nodo **list){
	Nodo *aux = search_value(list);
	
	if(!aux)
		printf("Valor no encontrado\n");

	printf("inserta el nuevo valor: "); scanf("%i", &aux->i);
	printf("Update Value\n");
}


// Imprimiendo todos los datos de la lista
void print_list(Nodo* list){
	for(; list; list = list->sig)
		printf("I: %i\n", list->i);
	printf("End List.\n");
}

// Limiando todos los datos de la lista
void clear_list(Nodo **list){
	for(; *list; *list = (*list)->sig){
		Nodo *aux = *list;
		aux = NULL;
		free(aux);
	}
	printf("Clear List.\n");
}

int main(int argc, char const *argv[])
{
	Nodo *list = NULL;

	insert(&list);
	insert(&list);
	insert(&list);
	insert(&list);
	update(&list);	

	print_list(list);
	clear_list(&list);
	print_list(list);

	return 0;
}