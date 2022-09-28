#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "lista_simple.h"
#include "lista_doble.h"
#include "lista_circular.h"
#include "cola_simple.h"
#include "cola_doble.h"
#include "cola_circular.h"


int main(int argc, char const *argv[])
{
	Nodo *list = NULL;	

	insertar_lista_circular(&list);
	insertar_lista_circular(&list);
	insertar_lista_circular(&list);

	sort_lista_circular(&list);
	
	print_lista_circular(list);

	return 0;
}