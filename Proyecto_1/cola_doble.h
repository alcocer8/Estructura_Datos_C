int insert_cola_doble(ColaDoble *cola){
	if (!cola)
	{
		printf("Cola NULL\n");
		return 0;
	}

	NodoDoble *new = crear_nodo_doble();

	if (!cola->final)
	{
		cola->inicio = cola->final = new;
	}else{
		cola->final->sig = new;
		new->ant = cola->final;
		cola->final = new;
	}
}

void print_cola_doble_reverse(NodoDoble *final){
	if (!final)
	{
		printf("Cola NULL\n");
		return;
	}

	for(NodoDoble *aux = final; final; final = final->ant)
		printf("Dato: %i\n", final->i);

	printf("Fin\n");
}