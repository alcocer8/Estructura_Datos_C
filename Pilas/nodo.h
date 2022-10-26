#define MAX 5
int tam = 0;
typedef struct PilaE
{
	int i;
	int values[MAX];
}PilaE;

typedef struct Nodo{
	int i;
	struct Nodo *sig;
}Nodo;

PilaE* crear_pila(){
	PilaE *pila = (PilaE*) malloc(sizeof(PilaE));

	if(!pila)
		return NULL;
	pila->i = 0;
	return pila;
}

Nodo* crear_nodo(int i){
	Nodo *nodo = (Nodo*) malloc(sizeof(Nodo));

	if(!nodo)
		return NULL;

	nodo->i = i;
	nodo->sig = NULL;

	return nodo;
}

