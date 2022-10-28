

void menu()
{
	printf("Seleccione una opcion: \n\t 1.Ingrese un elemento. \n\t 2.Ingrese un elemento al inicio. \n\t 3.Elimine el primer elemento. \n\t 4.Elimine el ultimo elemento. \n\t 5.Busque un elemento. \n\t 6.Modifique elemento. \n\t 7.Imprima todo el contenido.\n\t 8.Salir. \nOpcion: ");
}

void set_valor(int *n)
{
	printf("Ingrese el valor: "); scanf("%i", n);
}

void menu_ciclo()
{
	int opc = 1, x = 0;
	Cola *cola = crear_cola();

	while(opc)
	{
		printf("\n\n\n");
		menu();
		scanf("%i", &opc);
		switch(opc)
		{
			case 1: 
				set_valor(&x);
				insertar_cola_simple(cola, x);
				break;
			case 2:
				set_valor(&x);
				insertar_cola_final(cola, x);
				break;
			case 3:
				eliminar_cola_simple(cola);
				break;
			case 4:
				eliminar_cola_final(cola);
				break;
			case 5:
				set_valor(&x);
				buscar_cola_simple(cola, x);
				break;
			case 6:
				set_valor(&x);
				modificar_cola_simple(cola, x);
			case 7:
				print_cola_simple(cola);
				break;
			case 8:
				opc = 0;
				printf("Adios\n");
				break;
			default: 
				printf("Valor desconocido, vuelva intentarlo\n");
				break;
		}
	} 
	vaciar_cola_simple(cola);
}