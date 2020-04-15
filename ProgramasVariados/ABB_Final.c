//Programa de Arbol Binario de Busqueda
#include <stdio.h>
#include <stdlib.h>

struct Arbol{
	int dato;
	struct Arbol *izq;
	struct Arbol *der;
};

struct Arbol *AgregarElemento(struct Arbol *, int dato);
struct Arbol *EliminarElemento(struct Arbol *, int dato);
void BuscarElemento(struct Arbol *,int dato);
void PreOrden(struct Arbol *);
void InOrden(struct Arbol *);
void PostOrden(struct Arbol *);

int EsHoja(struct Arbol *raiz)
{
	return !raiz -> izq && !raiz -> der;
}
int Vacio(struct Arbol *raiz)
{
	return raiz == NULL;
}



int main(void)
{
	struct Arbol *arbol = NULL;

	arbol = AgregarElemento(arbol,12);
	arbol = AgregarElemento(arbol,6);
	arbol = AgregarElemento(arbol,46);
	arbol = AgregarElemento(arbol,62);
	arbol = AgregarElemento(arbol,235);
	arbol = AgregarElemento(arbol,2);

	IN(arbol);

	BuscarElemento(arbol,12);

	EliminarElemento(arbol,46);
	IN(arbol);

printf("\n");
return 0;
}

struct Arbol *AgregarElemento(struct Arbol *raiz, int dato)
{
	if(raiz == NULL) // Caso base
	{
		struct Arbol *nuevo = NULL;
		nuevo = (struct Arbol *) malloc(sizeof(struct Arbol));
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

void PRE(struct Arbol *arbol)
{
	if(arbol == NULL)
		return;

	printf("%d ",arbol -> dato);
	PRE(arbol -> izq);
	PRE(arbol -> der);
}

void IN(struct Arbol *arbol)
{
	if(arbol == NULL)
		return;

	IN(arbol -> izq);
	printf("%d ",arbol -> dato);
	IN(arbol -> der);
}

void POST(struct Arbol *arbol)
{
	if(arbol == NULL)
		return;

	POST(arbol -> izq);
	POST(arbol -> der);
	printf("%d ",arbol -> dato);
}

void BuscarElemento(struct Arbol *raiz, int dato)
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

struct Arbol *EliminarElemento(struct Arbol *raiz, int dato)
{
	struct Arbol *nodo = NULL;
	struct Arbol *padre = NULL;
	struct Arbol *actual = NULL;
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
