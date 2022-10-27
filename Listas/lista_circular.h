// Longtitud de la lista
int longitud_lista_circular(Nodo *list)
{
	Nodo *tmp = list;
	int i = 0;
	do
	{
		tmp = tmp->sig;
		i++;
	}while(tmp != list);

	return i;
}

// Ingresar datos a la lista
int insertar_lista_circular(Nodo **list, Nodo **last, int dato)
{
	Nodo *nodo = crear_nodo();

	if(!nodo)
		return 0;

	nodo->i = dato;
	if(!*list)
		*last = *list = nodo;
	else{
		(*last)->sig = nodo;
		nodo->sig = *list;
		*list = nodo;
	}

	printf("insertar_lista_circular\n");
}

int insertar_final_circular(Nodo **list, Nodo **last, int dato)
{
	if(!*list)
	{
		insertar_lista_circular(&*list, &*last, dato);
		return 1;
	}

	Nodo *nodo = crear_nodo();
	nodo->i = dato;

	nodo->sig = (*last)->sig;
	(*last)->sig = nodo;
	*last = nodo;

	printf("Insertado al final\n");
	return 1;
}

int eliminar_lista_circular(Nodo **list, Nodo **last)
{
	if(!*list)
		return 0;
	
	Nodo *tmp = (*last)->sig;
	*list = (*last)->sig = (*list)->sig;

	if(*list == *last)
		*last = *list = NULL; 

	tmp = NULL;
	free(tmp);

	printf("Eliminado\n");
}

int eliminar_final_circular(Nodo **list, Nodo **last)
{
	if(!*list)
		return 0;

	if(*list == *last){
		*list = *last = NULL;
		return 1;
	}

	Nodo *tmp = *list;
	Nodo *tmp2 = *last;
	for(; tmp->sig != *last; tmp = tmp->sig);
	tmp->sig = (*last)->sig;
	*last = tmp;
	free(tmp2);
	printf("Dato eliminado final\n");
}

void print_lista_circular(Nodo *list)
{
	if(!list)
		return;

	Nodo *tmp = list;
	do{
		printf("I: %i\n", list->i);
		list = list->sig;
	}while(tmp != list);
	printf("End\n");
}

void liberar_lista_circular(Nodo **list, Nodo **last)
{
	while(*list)
		eliminar_lista_circular(&*list, &*last);
	printf("Lista Liberada\n");
}