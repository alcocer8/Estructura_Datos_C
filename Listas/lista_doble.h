int longitud_lista_doble(NodoDoble *list)
{
	int i = 0;
	for(; list; list = list->sig, i++);
	return i;
}

// Insertar Elemento en la lista
int insertar_lista_doble(NodoDoble **list, int dato)
{
	NodoDoble *nodo = crear_nodo_doble(dato);

	if(!nodo)
		return 0;

	if(*list)
		(*list)->ant = nodo;

	nodo->sig = *list;
	*list = nodo;

	printf("insertar_lista_doble\n");
}

int insertar_final_doble(NodoDoble **list, int dato)
{
	if(!*list){
		insertar_lista_doble(&*list, dato);
		return 1;
	}

	NodoDoble *tmp = *list;
	NodoDoble *nodo = crear_nodo_doble(dato);
	for(; tmp->sig; tmp = tmp->sig);

	tmp->sig = nodo;
	nodo->ant = tmp;

	printf("insertar_final_doble\n");
	return 1;
}

int eliminar_lista_doble(NodoDoble **list)
{
	if(!*list)
		return 0;

	free((*list)->ant);
	*list = (*list)->sig;

	if(*list)
		(*list)->ant = NULL;

	printf("eliminar_lista_doble\n");
}

int eliminar_final_doble(NodoDoble **list)
{
	if(!*list)
		return 0;

	NodoDoble *tmp = *list;
	for(; tmp->sig->sig; tmp = tmp->sig);

	free(tmp->sig->sig);
	tmp->sig = NULL;
	printf("eliminar_final_doble\n");
}

void print_lista_doble(NodoDoble *list)
{
	for(; list; list = list->sig)
		printf("I: %i\n", list->i);
	printf("End.\n");
}

void print_lista_reverse(NodoDoble *list)
{
	if(!list)
		return;

	for(; list->sig; list = list->sig);

	for(; list; list = list->ant)
		printf("I: %i\n", list->i);
	printf("End.\n");
}

void liberar_lista_doble(NodoDoble **list)
{
	while(*list)
		eliminar_lista_doble(&*list);

	printf("Lista Liberada\n");
}