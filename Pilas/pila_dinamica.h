int push(Nodo **pila, int dato){
	Nodo *nodo = crear_nodo(dato);

	if(!nodo)
		return 0;

	nodo->sig = *pila;
	*pila = nodo;

	tam++;
	printf("Dato insertado\n");

	return 1;
}

int pop(Nodo **pila){
	if(!*pila)
		return 0;

	Nodo *aux = *pila;
	*pila = (*pila)->sig;

	return aux->i;
}

void print_pila(Nodo *pila){
	for(; pila; pila = pila->sig)
		printf("I: %i\n", pila->i);
	printf("End\n");
}

