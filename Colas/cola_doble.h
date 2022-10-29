// Insertar elemento en cola doble
int insertar_cola_doble(ColaDoble *cola, int dato)
{
	NodoDoble *nodo = crear_nodo_doble(dato);

	if(!nodo)
		return 0;

	if(!cola->final)
		cola->final = cola->inicio = nodo;
	else
	{
		cola->final->sig = nodo;
		nodo->ant = cola->final;
		cola->final = nodo;
	}

	printf("Elemento Insertado\n");
	return 1;
}

int insertar_inicio_doble(ColaDoble *cola, int dato)
{
	if(!cola->inicio)
		return insertar_cola_doble(cola, dato);

	NodoDoble *nodo = crear_nodo_doble(dato);

	if(!nodo)
		return 0;

	nodo->sig = cola->inicio;
	cola->inicio->ant = nodo;
	cola->inicio = nodo;

	printf("Insertado final\n");
	return 1;
}

NodoDoble* eliminar_cola_doble(ColaDoble *cola)
{
	if(!cola->inicio) 
		return NULL;
	
	NodoDoble *tmp = cola->inicio;
	cola->inicio = cola->inicio->sig;
	
	if(cola->inicio){
		free(cola->inicio->ant->ant);
		cola->inicio->ant = NULL;
	}else
		cola->final = cola->inicio;
	

	tmp->sig = tmp->ant = NULL;

	return tmp;
}

NodoDoble* eliminar_final_doble(ColaDoble *cola)
{
	if(!cola->final)
		return NULL;

	if(cola->inicio == cola->final)
		return eliminar_cola_doble(cola);

	NodoDoble *tmp = cola->final;
	cola->final = cola->final->ant;

	if(cola->final)
	{
		free(cola->final->sig->sig);
		cola->final->sig = NULL;
	}
	tmp->sig = tmp->ant = NULL;

	return tmp;
}

void print_cola_doble(ColaDoble *cola)
{
	if(!cola)
		return;

	for(NodoDoble *inicio = cola->inicio; inicio; inicio = inicio->sig)
			printf("I: %i\n", inicio->i);
	printf("End\n");
}

void print_reversa_doble(ColaDoble *cola)
{
	for(NodoDoble *final = cola->final; final; final = final->ant)
		printf("I: %i\n", final->i);
	printf("End.\n");
}

void vaciar_cola_doble(ColaDoble *cola)
{
	while(cola->inicio)
		eliminar_cola_doble(cola);
	printf("Cola Limpia\n");
}