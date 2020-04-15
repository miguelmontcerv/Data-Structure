#include"lssligadas.h"

int
main (void)
{

  struct ListaSLigada *lista1 = NULL;
  struct ListaSLigada *lista2 = NULL;
  struct ListaSLigada *lista3 = NULL;

  int max, numero, busqueda = 0;

  //Ingresa el numero total de nodos en la lista
  scanf ("%d", &max);
  for (int i = 0; i < max; i++)
    {
      scanf ("%d", &numero);
      lista1 = agregarElemento (lista1, numero);
    }
  //Ingresa el numero total de nodos en la lista2
  scanf ("%d", &max);
  for (int i = 0; i < max; i++)
    {
      scanf ("%d", &numero);
      lista2 = agregarElemento (lista2, numero);
    }

  mostrarLista (lista1);
  printf ("\n\n");

  mostrarLista (lista2);
  printf ("\n\n");;

  lista3 = mezclarListas (lista1, lista2);

  mostrarLista (lista3);
  printf ("\n\n");

  mostrarInversa (lista3);
  printf ("\n\n");

  //Eliminamos el ultimo elemento de la Lista 3
  lista3 = eliminarCola (lista3);

  mostrarLista (lista3);
  printf ("\n\n");

  //Eliminamos el primer elemento de lista 3
  lista3 = eliminarCabeza (lista3);

  mostrarLista (lista3);
  printf ("\n\n");

  //Buscamos un Elemento ingresado en la lista3 
  scanf ("%d", &numero);
  busqueda = buscarElemento (lista3, numero);
  printf ("Si es 1 se encontro, si es 0, no se pudo encontrar: %d\n\n",
	  busqueda);

  mostrarLista (lista3);
  printf ("\n\n");

  //Buscamos un Elemento y lo ELIMINAMOS de la lista3 
  scanf ("%d", &numero);
  lista3 = buscarEliminar (lista3, numero);

  mostrarLista (lista3);
  printf ("\n\n");

  //Eliminamos toda la lista
  lista3 = eliminarLista (lista3);
  printf ("Lista Eliminada: ");
  mostrarLista (lista3);
  printf ("\n");

  return 0;
}
