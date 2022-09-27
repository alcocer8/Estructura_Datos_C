int length_lista_doble(NodoDoble *list){
	if (!list)
		return 0;
	return 1 + length_lista_doble(list->sig);
}

int insertar_lista_doble(NodoDoble **list){
	NodoDoble *new = crear_nodo_doble();
	
	if (*list)
	{
		new->sig = *list;
		(*list)->ant = new;	
	}
	*list = new;

	printf("Valor Insertado\n");
}

void print_lista_doble(NodoDoble *list){
	for(; list; list = list->sig)
		printf("Dato: %i\n", list->i);
	printf("Fin\n");
}

void print_lista_doble_reverse(NodoDoble *list){
	for(; list->sig; list = list->sig){}
	
	for(; list; list = list->ant)
		printf("Dato: %i\n", list->i);
}

int delete_lista_doble(NodoDoble **list){
	if (!*list)
		return 0;

	*list = (*list)->sig;
	(*list)->ant = NULL;
	free((*list)->ant);

	printf("Dato Eliminado\n");
	return 1;
}

int search_lista_doble(NodoDoble *list){
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

void sort_lista_doble(NodoDoble **list){
	NodoDoble *new = *list;
	int n = length_lista_doble(*list);
	int values[n];

	for(int i = 0; new; new = new->sig, i++)
		values[i] = new->i;
	new = *list;
	bubble_sort(values, n);

	for(int i = 0; new; new = new->sig, i++)
		 new->i = values[i];
}

void empty_lista_doble(NodoDoble **list){
	if (!*list)
		return;
	
	for(; *list; *list = (*list)->sig){
		NodoDoble *aux = *list;
		aux = NULL;
		free(aux);
	}
	printf("Empty List\n");

}