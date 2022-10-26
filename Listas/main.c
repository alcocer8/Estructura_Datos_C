#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "lista_simple.h"
#include "lista_doble.h"

int main(int argc, char const *argv[])
{
	NodoDoble *list = NULL;

	insertar_lista_doble(&list, 1);
	insertar_lista_doble(&list, 2);
	insertar_lista_doble(&list, 3);
	insertar_lista_doble(&list, 4);
	insertar_final_doble(&list, 5);
	eliminar_final_doble(&list);


	print_lista_doble(list);
	print_lista_reverse(list);

	liberar_lista_doble(&list);

	print_lista_doble(list);


	return 0;
}