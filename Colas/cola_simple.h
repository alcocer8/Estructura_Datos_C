// Insertar elemento en la cola
int insertar_cola_simple(Cola *cola, int dato)
{
	Nodo *nodo = crear_nodo(dato);

	if(!nodo)
		return 0;

	if(!cola->final)
		cola->final = cola->inicio = nodo;
	else
	{
		cola->final->sig = nodo;
		cola->final = nodo;
	}

	printf("Cola Insertada\n");
}

int insertar_cola_final(Cola *cola, int dato)
{
	if(!cola)
		return 0;

	if(!cola->final)
		return insertar_cola_simple(cola, dato);

	Nodo *nodo = crear_nodo(dato);

	if(!nodo)
		return 0;

	cola->final->sig = nodo;
	cola->final = nodo;
	printf("Insertado final\n");
}

Nodo* eliminar_cola_simple(Cola *cola)
{
	if(!cola)
		return NULL;

	Nodo *tmp = cola->inicio;
	cola->inicio = cola->inicio->sig;

	return tmp;
}

Nodo* eliminar_cola_final(Cola *cola)
{
	if(!cola || !cola->final)
		return NULL;

	Nodo *tmp = cola->inicio;
	for(; tmp->sig != cola->final; tmp = tmp->sig);
	
	// Asignamos el nuevo final
	cola->final = tmp;

	// Guardamos el nodo que devolveremos
	tmp = tmp->sig;

	// Asigamos que el siguiente del final sea nulo
	cola->final->sig = NULL;
	return tmp;
}

void print_cola_simple(Cola *cola)
{
	for(Nodo *inicio = cola->inicio; inicio; inicio = inicio->sig)
		printf("I: %i\n", inicio->i);
	printf("End.\n");
}

Nodo* buscar_cola_simple(Cola *cola, int dato)
{
	Nodo *inicio = cola->inicio;
	for(; inicio; inicio = inicio->sig)
		if(inicio->i == dato)
			break;


	if(!inicio)
		printf("No se encontro el dato. \n");
	else
		printf("Dato encontrado, devuelto\n");

	return inicio;
}

void modificar_cola_simple(Cola *cola, int dato)
{
	Nodo *tmp = buscar_cola_simple(cola, dato);
	if(!tmp)
		return;

	printf("Ingresa el nuevo valor: "); scanf("%i", &tmp->i);
}

void vaciar_cola_simple(Cola *cola)
{
	while(cola->inicio)
		eliminar_cola_simple(cola);
	printf("Cola limpia\n");
}