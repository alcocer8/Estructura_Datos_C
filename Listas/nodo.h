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

Nodo* crear_nodo()
{
	Nodo *nodo = (Nodo*) malloc(sizeof(Nodo));

	if(!nodo)
		return 0;

	nodo->i = 0;
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

