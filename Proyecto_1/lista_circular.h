int insertar_lista_circular(Nodo **list){
	Nodo *new = crear_nodo();

	if (!*list)
		new->sig = *list;
	else{

		Nodo *aux = *list;
		while(aux->sig != *list){
			aux = aux->sig;
		}
		aux->sig = new;	
	}


	*list = new;

	printf("Dato insertado\n");
}

void print_lista_circular(Nodo *list){
	for(Nodo *aux = list; aux->sig != list; aux = aux->sig){
		printf("Dato: %i\n", aux->i);
	}

	printf("Fin de lista\n");
}