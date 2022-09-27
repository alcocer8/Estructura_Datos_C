// longitud de la lista
int length_lista_simple(Nodo *list){
	if (!list)
		return 0;

	return 1 + length_lista_simple(list->sig);
}

// Insertar en la lista
int insertar_lista_simple(Nodo **list){
	Nodo *new = crear_nodo();
	
	is_null(new);

	//insertando en la lista
	new->sig = *list;
	*list = new;

	printf("Dato insertado. \n");
	return 1;
}

// Eliminado el primer elemento de la lista
int delete_lista_simple(Nodo **list){
	if (is_null(*list))
		return 0;

	Nodo *aux = *list;
	*list = (*list)->sig;

	aux = NULL;
	free(aux);

	printf("Dato Eliminado\n");
	return 1;
}

// Buscando un elemento de la lista
int search_lista_simple(Nodo *list){
	if (!list)
	{
		return 0;
	}
	int n = 0;
	printf("Ingresa el valor buscado: "); scanf("%i", &n);

	for(; list && (list->i != n); list = list->sig){}

	if (!list)
	{
		printf("Valor no encontrado\n");
		return 0;
	}

	printf("Dato encontrado\n");
	return 1;
}


// Ordena los elementos de menor a mayor
void sort_lista_simple(Nodo **list){
	Nodo *new = *list;
	int n = length_lista_simple(*list);
	int values[n];
	

	for(int i = 0; new; new = new->sig, i++)
		values[i] = new->i;
	new = *list;
	bubble_sort(values, n);

	for(int i = 0; new; new = new->sig, i++)
		 new->i = values[i];
}

// Imprimw todos los elementos de la lista
void print_lista_simple(Nodo *list){
	for(; list; list = list->sig)
		printf("Dato: %i\n", list->i);
	printf("Fin\n");
}


// Vacia la lista y libera de la memoria
void empty_lista_simple(Nodo **list){
	if (is_null(*list))
		return;
	
	for(; *list; *list = (*list)->sig){
		Nodo *aux = *list;
		aux = NULL;
		free(aux);
	}
	printf("Empty List\n");

}