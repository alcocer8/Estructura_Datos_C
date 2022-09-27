int length_cola_cicular(Nodo *inicio){
	if (!inicio)
		return 0;

	Nodo *aux = inicio;
	int i = 0;
	do{
		aux = aux->sig;
		i++;
	}while(aux != inicio);

	return i;
}

int insert_cola_circular(Cola *cola){
	Nodo *new = crear_nodo();

	if (!cola->final)
	{
		cola->final = cola->inicio = new;
		
	}else{
		cola->final->sig = new;
		cola->final = cola->final->sig;
	}
	cola->final->sig = cola->inicio;
}

void print_colar_circular(Cola *cola){
	if (!cola || !cola->inicio)
	{
		printf("Cola NULL\n");
		return;
	}

	Nodo *aux = cola->inicio;
	do{
		printf("Dato: %i\n", aux->i);
		aux = aux->sig;
	}while(aux != cola->inicio);

	printf("End.\n");
}

int delete_cola_circular(Cola *cola){
	if (!cola->inicio)
	{
		printf("Cola Vacia.\n");
		return 0;
	}

	// Almacenamos la direccion de memoria
	Nodo *aux = cola->inicio;

	// Verificamos que el inicio y final sean el mismo
	if (cola->inicio == cola->final)
		cola->inicio = cola->final = NULL;
	else{
		cola->inicio = cola->inicio->sig;
		cola->final->sig = cola->inicio;
	}
	
	// Anulamos el dato y liberamos la memoria
	aux = NULL;
	free(aux);

	printf("Dato eliminado\n");
	return 1;
}

int sort_cola_circular(Cola *cola){
	if (!cola || !cola->inicio)
	{
		printf("La cola es NULL\n");
		return 0;
	}

	
	int n = length_cola_cicular(cola->inicio);
	int values[n];
	Nodo *aux = cola->inicio;

	for (int i = 0; i < n; ++i, aux = aux->sig)
		values[i] = aux->i;
	aux = cola->inicio;
	bubble_sort(values, n);

	
	for (int i = 0; i < n; ++i, aux = aux->sig)
		aux->i = values[i];

	printf("Cola ordenada\n");
}

void empty_cola_circular(Cola *cola){
	cola->final->sig = NULL;
	for(; cola->inicio; cola->inicio = cola->inicio->sig){
		Nodo *aux = cola->inicio;
		aux = NULL;
		free(aux);
	}

	printf("Empty Cola.\n");

}

int search_cola_circular(Cola *cola){
	if (!cola || !cola->inicio)
	{
		printf("La cola es NULL\n");
		return 0;
	}

	int n = 0;
	Nodo *aux = cola->inicio;

	printf("Ingresa el dato por buscar: "); scanf("%i", &n);
	
	do{
		if (aux->i == n){
			printf("Se encontro el dato\n"); 
			return 1;
		}
		aux = aux->sig;
	}while(aux != cola->inicio);

	printf("No se encontro el dato\n");
	return 0;
}