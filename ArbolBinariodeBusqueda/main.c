#include"abb.h"
int main(void)
{
	struct ArbolBB *arbol = NULL;

	arbol = AgregarElemento(arbol,12);
	arbol = AgregarElemento(arbol,6);
	arbol = AgregarElemento(arbol,46);
	arbol = AgregarElemento(arbol,62);
	arbol = AgregarElemento(arbol,235);
	arbol = AgregarElemento(arbol,2);

	InOrden(arbol);

	BuscarElemento(arbol,12);

	EliminarElemento(arbol,46);
	InOrden(arbol);

printf("\n");
return 0;
}