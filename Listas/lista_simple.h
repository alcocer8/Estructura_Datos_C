// Longitud de la lista
int longitud_lista(Nodo *list)
{
	int cont = 0;
	for(; list; list = list->sig, cont++);
	return cont;
}

Nodo* get_utlimo(Nodo **list)
{
	if(!*list)
		return NULL;

	Nodo *tmp = *list;
	for(; tmp->sig; tmp = tmp->sig);

	return tmp;
}

// Insertar un elemento en la lista
int insertar_lista_simple(Nodo **list, int dato)
{
	Nodo *nodo = crear_nodo();

	if(!nodo)
		return 0;

	nodo->i = dato;
	nodo->sig = *list;
	*list = nodo;

	printf("Dato insertado\n");
	return 1;
}

int insertar_final_simple(Nodo **list, int dato)
{
	Nodo *tmp = get_utlimo(&*list);

	if(!tmp)
		return insertar_lista_simple(&*list, dato);

	Nodo *nodo = crear_nodo();

	nodo->i = dato;
	tmp->sig = nodo;
	printf("Inserar Final\n");
	return 1;
}


// Insertar en posicion deseada
int insertar_pos_simple(Nodo **list, int pos, int dato)
{
	int n = longitud_lista(*list);

	if( pos > n)
		return insertar_final_simple(&*list, dato);
	else if(pos <= 1)
		return insertar_lista_simple(&*list, dato);

	Nodo *tmp = *list;
	Nodo *nodo = crear_nodo();
	nodo->i = dato;

	for(int i = 1; i < pos-1; ++i, tmp = tmp->sig);

	nodo->sig = tmp->sig;
	tmp->sig = nodo;
	printf("Insert pos\n");
}


// Eliminar primer elemento de la lista
int eliminar_lista_simple(Nodo **list)
{
	if(!*list)
		return 0;

	Nodo *aux = *list;
	*list = (*list)->sig;

	aux = NULL;
	free(aux);

	printf("Dato Eliminado\n");
	return 1;
}

// Eliminar el ultimo elemento
int eliminar_ultimo_simple(Nodo **list)
{
	if(!*list)
		return 0;

	Nodo *tmp = *list;
	for(; tmp->sig->sig; tmp = tmp->sig);

	free(tmp->sig->sig);
	tmp->sig = NULL;
}

// Eliminar posicion deseada
int eliminar_pos_simple(Nodo **list, int pos)
{
	
}

// Imprime el contenido de la lista
void print_lista_simple(Nodo *list)
{
	for(; list; list = list->sig)
		printf("I: %i\n", list->i);
	printf("End.\n");
}

// Vaciar la lista
int vaciar_lista_simple(Nodo **list)
{
	while(*list)
		eliminar_lista_simple(&*list);
	printf("Lista limpia\n");
}

void ordenar_lista(Nodo **list)
{
	int n = longitud_lista(*list);
	Nodo *tmp = *list;

	for (int i = 0; i < n; ++i, tmp = *list)
	{
		for (int j = 0; j < n-1; ++j, tmp = tmp->sig)
		{
			if(tmp->i > tmp->sig->i)
			{
				int aux = tmp->i;
				tmp->i = tmp->sig->i;
				tmp->sig->i = aux;
			}
		}
	}

}
