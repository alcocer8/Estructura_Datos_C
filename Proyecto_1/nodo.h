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

typedef struct Cola{
	Nodo *inicio;
	Nodo *final;
}Cola;

typedef struct ColaDoble{
	NodoDoble *inicio;
	NodoDoble *final;
}ColaDoble;

Nodo* crear_nodo(){
	Nodo *new = (Nodo*) malloc(sizeof(Nodo));

	printf("Ingresa el valor: "); scanf("%i", &new->i);
	new->sig = NULL;
	return new;
}

NodoDoble* crear_nodo_doble(){
	NodoDoble *new = (NodoDoble*) malloc(sizeof(NodoDoble));

	printf("Ingresa el valor: "); scanf("%i", &new->i);
	new->sig = NULL;
	new->ant = NULL;
	return new;
}

Cola* crear_cola(){
	Cola *new = (Cola*) malloc(sizeof(Cola));
	new->inicio = new->final = NULL;
	return new;
}

ColaDoble* crear_cola_doble(){
	ColaDoble *new = (ColaDoble*) malloc(sizeof(ColaDoble));
	new->inicio = NULL;
	new->final = NULL;
	return new;
}

int is_null(Nodo *nodo){
	if (!nodo)
	{
		printf("is NULL\n");
		return 1;
	}
	return 0;
}

void bubble_sort(int *values, int n){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n-1; ++j)
		{
			if (values[j] < values[j+1])
			{
				int aux = values[j];
				values[j] = values[j+1];
				values[j+1] = aux;
			}
		}
	}
}