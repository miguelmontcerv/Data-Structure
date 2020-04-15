#include"abb.h"

int EsHoja(struct ArbolBB *raiz)
{
	return !raiz -> izq && !raiz -> der;
}
int Vacio(struct ArbolBB *raiz)
{
	return raiz == NULL;
}


struct ArbolBB *AgregarElemento(struct ArbolBB *raiz, int dato)
{
	if(raiz == NULL) // Caso base
	{
		struct ArbolBB *nuevo = NULL;
		nuevo = (struct ArbolBB *) malloc(sizeof(struct ArbolBB));
		nuevo -> dato = dato;
		nuevo -> izq = NULL;
		nuevo -> der = NULL;
		return nuevo;
	}

	if(dato < raiz -> dato){
		raiz -> izq = AgregarElemento(raiz -> izq, dato);
	}
	else
	{
		raiz -> der = AgregarElemento(raiz -> der, dato);
	}

	return raiz;
}

void PreOrden(struct ArbolBB *arbol)
{
	if(arbol == NULL)
		return;

	printf("%d ",arbol -> dato);
	PreOrden(arbol -> izq);
	PreOrden(arbol -> der);
}

void InOrden(struct ArbolBB *arbol)
{
	if(arbol == NULL)
		return;

	InOrden(arbol -> izq);
	printf("%d ",arbol -> dato);
	InOrden(arbol -> der);
}

void PostOrden(struct ArbolBB *arbol)
{
	if(arbol == NULL)
		return;

	PostOrden(arbol -> izq);
	PostOrden(arbol -> der);
	printf("%d ",arbol -> dato);
}

void BuscarElemento(struct ArbolBB *raiz, int dato)
{
	if(raiz == NULL){
		return;
	}
	printf("\nBuscando... ");
	if(dato == raiz -> dato)
		printf("\n\t%d encontrado\n",raiz->dato);
	else{
		if(dato < raiz -> dato){
			BuscarElemento(raiz->izq,dato);
		}
		else if(dato > raiz -> dato){
			BuscarElemento(raiz->der,dato);
		}
		else{
			printf("No se encontro el dato\n");
		}
	}
}

struct ArbolBB *EliminarElemento(struct ArbolBB *raiz, int dato)
{
	struct ArbolBB *nodo = NULL;
	struct ArbolBB *padre = NULL;
	struct ArbolBB *actual = NULL;
	int aux = 0;

	actual = raiz;
	while(!Vacio(actual)) //Mientras la raiz no este vacia
	{
		if(dato == actual -> dato) //Se encontro el dato
		{
			if(EsHoja(actual)) //Si es hoja, solo se elimina
			{
				if(padre) //Si el pare existe, es decir, si no es raiz
				{
					//Eliminamos los punteros que señalan al actual
					if(padre -> izq == actual)
						padre -> izq = NULL;
					else if(padre -> der == actual)
						padre -> der = NULL;
				}
				//Si no existe el padre, y tampoco tiene hijos, solo es un nodo, asi que lo elimino
				free(actual);
				actual = NULL;
			}
			else{
			//Si el nodo tiene hijos
			padre = actual;
			//A quien le dejamos los hijos? Al menor de los mayores (al más izquierdo de la rama derecha)
			if(actual -> der) //Existe
			{
				nodo = actual -> der;
				while(nodo -> izq){
					padre = nodo;
					nodo = nodo -> izq;
				} //Llegammos el menor de los mayores
			}
			//Si no tiene mayores, se lo damos al mayor de los menores
			else
			{
				nodo = actual -> izq;
				while(nodo -> der){
					padre = nodo;
					nodo = nodo -> der;
				}
			}
			//Hacemos cambio de posicion para asegurarnos que lo que se elimine es un nodo hoja
			aux = actual -> dato;
			actual -> dato = nodo -> dato;
			nodo -> dato = aux;
			actual = nodo;
			}
		}	
		else //No se encontro, hay que seguir buscando
		{
			padre = actual;
			if(dato > actual -> dato)
				actual = actual -> der;
			else if(dato < actual -> dato)
				actual = actual -> izq;
		}
	//return raiz;

	}
}
