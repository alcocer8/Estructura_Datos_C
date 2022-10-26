int llena(int i){
	return i >= MAX ? 1 : 0; 
}

int vacia(int i){
	return i < 0 ? 1 : 0;
}

int push(PilaE **pila, int i){
	if( llena( (*pila)->i ) )
		return 0;

	(*pila)->values[(*pila)->i] = i;
	(*pila)->i++;
	printf("Dato insertado\n");
	return 1;
}

int pop(PilaE **pila){
	if( vacia((*pila)->i))
		return 0;

	int aux = (*pila)->values[(*pila)->i-1];
	(*pila)->values[(*pila)->i] = 0;
	(*pila)->i--;

	printf("Dato Eliminado\n");
	return aux;
}

int print_pila(PilaE *pila){
	for(int i = pila->i-1; i > -1; i--)
		printf("I: %i\n", pila->values[i]);
	printf("End. \n");
}

void vaciar_pila(PilaE **pila){
	while((*pila)->i >= 0)
		printf("I: %i\n", pop(&*pila));
	
}

void sort_pila(PilaE **pila){
	int x = (*pila)->i;
	for (int i = 0; i < x; ++i)
	{
		for (int j = i; j < x-1; ++j)
		{
			if((*pila)->values[j] < (*pila)->values[j+1]){
				int aux = (*pila)->values[j];
				(*pila)->values[j] = (*pila)->values[j+1];
				(*pila)->values[j+1] = aux;
			}
		}
	}
}