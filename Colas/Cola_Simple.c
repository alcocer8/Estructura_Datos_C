#include <stdio.h>
#include <stdlib.h>

//Struct Nodo
typedef struct Nodo
{
	int i;
	struct Nodo *sig;
}Nodo;

//Struct Cola
typedef struct Cola
{
	Nodo *inicio;
	Nodo *final;
}Cola;

//Verifica si la cola esta vacia
int is_clear(Nodo* inicio){
	if (!inicio){
		printf("La cola esta vacia\n");
		return 1;
	}
	return 0;
}

//Reserva Memoria
Nodo* reservar_nodo(){
	Nodo *new = (Nodo*) malloc(sizeof(Nodo));

	if (!new)
		return NULL;

	printf("Ingrese un valor: "); scanf("%i", &new->i);
	new->sig = NULL;
	return new;
}

//Insertar datos en la cola
int insert(Cola **cola){
	Nodo *new = reservar_nodo();
	if (is_clear(new))
		return 0;

	if (!(*cola)->inicio)
		(*cola)->inicio = (*cola)->final = new;
	else{
		(*cola)->final->sig = new;
		(*cola)->final = (*cola)->final->sig;
	}
	printf("Insert value.\n");
	return 1;
}

//inserta el valor al principio de la cola
int insert_begin(Cola **cola){
	Nodo *new = reservar_nodo();

	if (is_clear(new))
		return 0;

	new->sig = (*cola)->inicio;
	(*cola)->inicio = new;

	printf("Insert value\n");
	return 1;
}

// Elimina el primer valor de la cola
int delete(Cola **cola){
	if (is_clear((*cola)->inicio))
		return 0;

	Nodo *aux = (*cola)->inicio;
	(*cola)->inicio = (*cola)->inicio->sig;
	aux = NULL;
	free(aux);
	printf("Valor Eliminado. \n");
}

void update(Nodo **inicio){
	if (is_clear(*inicio))
		return;
	
	int n = 0;
	Nodo *aux = *inicio;

	printf("Ingrese el valor a buscar: "); scanf("%i", &n);

	while(aux && (aux->i != n))
		aux = aux->sig;

	if (!aux){
		printf("El valor no se encontro\n");
		return;
	}

	printf("Ingrese el nuevo valor: "); scanf("%i", &n);

	aux->i = n;

	printf("Valor Modificado\n");
}

//Imprimir datos desde el inicio de la cola
void print_cola(Nodo *inicio){
	for(; inicio; inicio = inicio->sig)
		printf("I: %i\n", inicio->i);

	printf("Fin de cola\n");
}


//Limpiar toda la cola
void clear_cola(Nodo **inicio){
	for(; *inicio; *inicio = (*inicio)->sig){
		Nodo *aux = *inicio;
		aux = NULL;
		free(aux);
	}
	printf("Cola limpia\n");
}

int main(int argc, char const *argv[])
{
	Cola *cola = (Cola*) malloc(sizeof(Cola));

	
	clear_cola(&cola->inicio);
	cola = NULL;
	free(cola);	
	return 0;
}