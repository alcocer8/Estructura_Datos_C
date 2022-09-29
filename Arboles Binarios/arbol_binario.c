#include <stdio.h>
#include <stdlib.h>

// Struct de un nodo
typedef struct Nodo
{
	int i;
	struct Nodo *izq;
	struct Nodo *der;
}Nodo;

typedef struct NodoCola{
	Nodo *nodo;
	struct NodoCola *sig;
}NodoCola;

typedef struct Cola{
	NodoCola *inicio;
	NodoCola *final;
}Cola;

/*
	Crear nodo y insertar el dato
	1. Se creal el espacio en memoria, con la funcion mallloc se reserva la cantidad en bytes de lo que equivale
		el tipo de dato Nodo
	2. Se asigna el dato pasado como argumento
	3. Se anulan los datos izq y der
	4. Retornaos el dato
*/
Nodo* crear_nodo(int i){
	Nodo *new = (Nodo*) malloc(sizeof(Nodo)); // 1
	new->i = i; // 2
	new->izq = new->der = NULL; // 3
	return new; // 4
}

NodoCola* crear_nodo_cola(Nodo *nodo){
	NodoCola *new = (NodoCola*) malloc(sizeof(NodoCola));
	new->nodo = crear_nodo(nodo->i);
	new->sig = NULL;
	return new;
}

Cola* crear_cola(){
	Cola *new = (Cola*) malloc(sizeof(Cola));
	new->inicio = new->final = NULL;
	return new;
}

/*
	Insertar en un arbol binario
	1. Verificamos si el dato tiene que ir del lado derecho o izquiero
	2. Comprobamos que no exista el espacio donde se va almacenar el dato
		{
			1. Si no existe, se crea el espacio y se alamcena
			2. Si existe solo se inserta el dato
		}
*/
void insert_binario(Nodo *raiz, int i){
	if (i < raiz->i)
	{
		!raiz->izq ? raiz->izq = crear_nodo(i) : insert_binario(raiz->izq, i);
		return;
	}

	!raiz->der ? raiz->der = crear_nodo(i) : insert_binario(raiz->der, i);
}

void insert_binario_2(Nodo **raiz, int i){
	if (!*raiz)
		*raiz = crear_nodo(i); return;

	i < (*raiz)->i ? insert_binario_2(&(*raiz)->izq, i): insert_binario_2(&(*raiz)->der, i);
}

int insert_cola(Cola *cola, Nodo *raiz){
	NodoCola *new = crear_nodo_cola(raiz);

	if (!cola->inicio)
	{
		cola->inicio = cola->final = new;
	}else{
		cola->final->sig = new;
		cola->final = new;
	}
	printf("Encolado\n");
}

Nodo* pop_cola(Cola *cola){
	if (!cola->inicio)
	{
		return NULL;
	}

	NodoCola *aux = cola->inicio;
	cola->inicio = cola->inicio->sig;
	return aux->nodo;
}


int search_binario(Nodo *raiz, int i){
	if (!raiz)
		return 0;

	if (raiz->i == i)
		return 1;

	return (i < raiz->i) ?  search_binario(raiz->izq, i) :  search_binario(raiz->der, i);	
}

int print_anchura(Nodo *raiz){
	Cola *cola = crear_cola();
	insert_cola(cola, raiz);
	int n;
	while(cola->inicio != NULL){
		Nodo *aux = pop_cola(cola);
		
		if (!aux)
		{
			return 0;
		}
		printf("I: %i\n", aux->i);
		insert_cola(cola, aux->izq);
		insert_cola(cola, aux->der);
	}
}

/*
	Imprimir el contenido del arbol, modo preorden
	1. Evaluamos si el arbol o nodo es nulo
		{
			1. Si la evalucion es cierta, se retorna
		}

	2. Si es falso, se imprime el dato actual del nodo
	3. Se llama recursivamente a la funcion evaluando de nuevo si los lados son nulo
*/
void print_preorden(Nodo *raiz){
	if (!raiz){
		printf(" - "); 
		return;
	}

	printf("( %i ", raiz->i);
	print_preorden(raiz->izq);
	print_preorden(raiz->der);
	printf(" )");

}


void print_inorden(Nodo *raiz){
	if (!raiz)
		return;

	print_preorden(raiz->izq);
	printf("I: %i\n", raiz->i);
	print_preorden(raiz->der);
}

void print_postorden(Nodo *raiz){
	if (!raiz)
		return;

	print_preorden(raiz->izq);
	print_preorden(raiz->der);
	printf("I: %i\n", raiz->i);
}

int main(int argc, char const *argv[])
{
	Nodo *raiz = NULL;
	
	insert_binario_2(&raiz, 10);
	insert_binario(raiz, 1);
	insert_binario(raiz, 20);
	insert_binario_2(&raiz, 2);
	insert_binario_2(&raiz, 19);
	insert_binario(raiz, 21);
	insert_binario(raiz, 11);
	
	print_anchura(raiz);

	return 0;
}