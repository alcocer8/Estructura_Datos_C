typedef struct Nodo
{
	int i;
	struct Nodo *izq;
	struct Nodo *der;
}Nodo;

Nodo *crear_nodo(int dato)
{
	Nodo *nodo = (Nodo*) malloc(sizeof(Nodo));

	if(!nodo)
		return NULL;

	nodo->i = dato;
	nodo->izq = nodo->der = NULL;

	return nodo;
}

int mayor(int n1, int n2)
{
	return n1 > n2 ? n1 : n2;
}

int altura(Nodo *raiz)
{
	if(!raiz)
		return 0;
	return 1 + mayor(altura(raiz->izq), altura(raiz->der));
}

int balance(Nodo *raiz)
{
	return altura(raiz->der) - altura(raiz->izq);
}

void rotacion_simple_derecha(Nodo **raiz)
{
	Nodo *tmp = (*raiz)->izq;
	tmp->der = *raiz;
	tmp->der->izq = tmp->der->der = NULL;
	*raiz = tmp;
}

void rotacion_simple_izquierda(Nodo **raiz)
{
	Nodo *tmp = (*raiz)->der;
	tmp->izq = *raiz;
	tmp->izq->izq = tmp->izq->der = NULL;
	*raiz = tmp;
}

void insertar(Nodo *raiz, int dato)
{
	if(dato < raiz->i)
		!raiz->izq ? raiz->izq = crear_nodo(dato) : insertar(raiz->izq, dato);
	else
		!raiz->der ? raiz->der = crear_nodo(dato) : insertar(raiz->der, dato);
}

void insertar2(Nodo **raiz, int dato)
{
	if(!*raiz)
	{
		*raiz = crear_nodo(dato);
		return;
	}
	dato < (*raiz)->i ? insertar2(&(*raiz)->izq, dato) : insertar2(&(*raiz)->der, dato);

	int b = balance(*raiz);
	
	if(b >= -1 && b <= 1)
		return;

	b < 0 ? rotacion_simple_derecha(&*raiz) : rotacion_simple_izquierda(&*raiz);
}

void preorden(Nodo *raiz)
{
	if(!raiz)
		return;
	
	printf("I: %i\n", raiz->i);
	preorden(raiz->izq);
	preorden(raiz->der);
}


void inorden(Nodo *raiz)
{
	if(!raiz)
		return;
	
	inorden(raiz->izq);
	printf("I: %i\n", raiz->i);
	inorden(raiz->der);
}
