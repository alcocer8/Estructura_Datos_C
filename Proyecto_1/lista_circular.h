int length_lista_cicular(Nodo *list){
	if (!list)
		return 0;
	
	Nodo *aux = list;
	int i = 0;
	do{
		i++;
		aux = aux->sig;
	}while(aux != list);

	return i;
}

int insertar_lista_circular(Nodo **list){
	Nodo *new = crear_nodo();

	if (!*list)
	{
		new->sig = new;
		*list = new;
	}else{
		Nodo *aux = *list;
		for(; aux->sig != *list; aux = aux->sig){}		
		new->sig = *list;
		aux->sig = new;
	}

	printf("Dato insertado\n");
	return 1;
}


int delete_lista_circular(Nodo **list){
	if (!*list)
	{
		printf("La lista esta vacia.\n");
		return 0;
	}

	
	if ((*list)->sig == *list)
		*list = NULL;
	else{
		// Busco el ultimo elemento
		Nodo *final = *list;

		do{
			final = final->sig;
		}while(final->sig != *list);

		// Matengo la referencia
		Nodo *inicio = *list;

		// Muevo el puntero a la sig. posicion
		*list = (*list)->sig;
		final->sig = *list;

		// Anulo y libero el valor retendio
		inicio = NULL;
		free(inicio);

		// Anulo y libero la posicion mantenida
		inicio = NULL;
		free(inicio);
	}
	printf("Dato eliminado. \n");
	return 1;
}

void print_lista_circular(Nodo *list){
	if (!list)
	{
		printf("Lista vacia.\n");
		return;
	}

	Nodo *aux = list;

	do{
		printf("Dato: %i\n", aux->i);
		aux = aux->sig;
	}while(aux != list);

	printf("Fin de lista\n");
}

int sort_lista_circular(Nodo **list){
	if (!*list)
	{
		printf("Es NULL\n");
		return 0;
	}

	
	int n = length_lista_cicular(*list);
	int values[n];
	Nodo *aux = *list;

	for (int i = 0; i < n; ++i, aux = aux->sig)
		values[i] = aux->i;
	aux = *list;
	bubble_sort(values, n);

	
	for (int i = 0; i < n; ++i, aux = aux->sig)
		aux->i = values[i];

	printf("Cola ordenada\n");
}