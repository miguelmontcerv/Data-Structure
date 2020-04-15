#include "avl.h"

int main(void) {

   struct AVL *raiz = NULL;

	raiz = insertar(raiz, 1);
	raiz = insertar(raiz, 2);
	raiz = insertar(raiz, 3);
	raiz = insertar(raiz, 4);
	raiz = insertar(raiz, 5);
	raiz = insertar(raiz, 10);
	raiz = insertar(raiz, 90);

	mostrar(raiz);

	printf("\nSi es 1 se encontro, si es 0, no se pudo encontrar: %d\n", buscar(raiz, 1));
	printf("Si es 1 se encontro, si es 0, no se pudo encontrar: %d\n", buscar(raiz, 15));

	return 0;
}