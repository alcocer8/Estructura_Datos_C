// struct nodo
typedef struct Nodo
{
	int i;
	struct Nodo *sig;
}Nodo;

typedef struct NodoDoble
{
	int i;
	struct NodoDoble *sig;
	struct NodoDoble *ant;
}NodoDoble;

typedef struct Cola
{
	Nodo *inicio;
	Nodo *final;
}Cola;

typedef struct ColaDoble
{
	NodoDoble *inicio;
	NodoDoble *final;
}ColaDoble;



Nodo* crear_nodo(int dato)
{
	Nodo *nodo = (Nodo*) malloc(sizeof(Nodo));

	if(!nodo)
		return NULL;

	nodo->i = dato;
	nodo->sig = NULL;

	return nodo;
}

NodoDoble* crear_nodo_doble(int dato)
{
	NodoDoble *nodo = (NodoDoble*) malloc(sizeof(NodoDoble));

	if(!nodo)
		return NULL;

	nodo->i = dato;
	nodo->sig = nodo->ant = NULL;

	return nodo;
}

Cola *crear_cola()
{
	Cola *cola = (Cola*) malloc(sizeof(Cola));

	if(!cola)
		return NULL;

	cola->final = cola->inicio = NULL;

	return cola;
}


ColaDoble* crear_cola_doble()
{
	ColaDoble *cola = (ColaDoble*) malloc(sizeof(ColaDoble));

	if(!cola)
		return NULL;

	cola->inicio = cola->final = NULL;

	return cola;
}