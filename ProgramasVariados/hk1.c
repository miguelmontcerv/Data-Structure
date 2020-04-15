//Codigo por Miguel Angel Monteros Cervantes
#include<stdio.h>
#include<stdlib.h>
struct Nodo{
	int dato;
	struct Nodo *Siguiente;
};
struct Nodo *AgregarLista(struct Nodo *Lista, int dato);
int main(int argc, char const *argv[])
{
	struct Nodo *Lista;
	Lista = NULL;
	int max, add;
	scanf("%d",&max);

	for(int i = 0; i< max; i++){
		scanf("%d",&add);
		Lista = AgregarLista(Lista,add);
	}
	for (int i = 0; i < max; ++i){
		printf("%d\n",Lista->dato);
		Lista = Lista ->Siguiente;
	}
	return 0;
}
struct Nodo *AgregarLista(struct Nodo *Lista, int dato){
	struct Nodo *NewNodo, *aux;
	NewNodo = (struct Nodo *) malloc(sizeof(struct Nodo));

	NewNodo -> dato = dato;
	NewNodo -> Siguiente = NULL;

	if(Lista == NULL)
		Lista = NewNodo;
	else{
		aux = Lista;
		while(Lista->Siguiente != NULL){
			Lista = Lista -> Siguiente;
		}
		Lista -> Siguiente = NewNodo;
		NewNodo -> Siguiente = NULL;
		Lista = aux;
	}
}