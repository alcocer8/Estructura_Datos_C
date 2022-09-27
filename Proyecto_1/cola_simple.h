int insertar_cola_simple(Cola *cola){
	Nodo *new = crear_nodo();

	if (!cola->inicio)
	{
		cola->inicio = cola->final = new;
	}else{
		cola->final->sig = new;
		cola->final = cola->final->sig;
	}

	printf("Dato insertado\n");
	return 1;
}

// Para Eliminar ordenar y buscar podemos usar las funciones de lista_simple.h