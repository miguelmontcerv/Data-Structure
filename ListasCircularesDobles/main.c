#include"lscdoble.h"

int
main (void)
{
  struct ListaCDoble *lista1 = NULL;
  struct ListaCDoble *lista2 = NULL;
  struct ListaCDoble *lista3 = NULL;

  int max, numero, buscador = 0;
  //Ingresa el numero total de nodos en la lista

  scanf ("%d", &max);
  for (int i = 0; i < max; i++)
    {
      scanf ("%d", &numero);
      lista1 = agregarElemento (lista1, numero);
    }
//lista2
  scanf ("%d", &max);
  for (int i = 0; i < max; i++)
    {
      scanf ("%d", &numero);
      lista2 = agregarElemento (lista2, numero);
    }
  printf ("\n");

  mostrarLista (lista1);
  printf ("\n");
  mostrarInversa (lista1);
  printf ("\n\n");

  mostrarLista (lista2);
  printf ("\n");
  mostrarInversa (lista2);

  printf ("\n\n");

  lista3 = mezclarListas (lista1, lista2);
  mostrarLista (lista3);
  printf ("\n");
  mostrarInversa (lista3);
  printf ("\n\n");

  lista3 = eliminarCola (lista3);
  mostrarLista (lista3);
  printf ("\n\n");

  lista3 = eliminarCabeza (lista3);
  mostrarLista (lista3);
  printf ("\n\n");

//Buscamos Un Dato:
  scanf ("%d", &max);
  buscador = buscarElemento (lista3, max);
  printf("Si es 1 se encontro, si es 0, no se pudo encontrar: %d\n\n",buscador);
  printf ("\n\n");

//Eliminamos un elemento
  mostrarLista (lista3);
  printf ("\n");
  scanf ("%d", &max);
  lista3 = buscarEliminar (lista3, max);
  mostrarLista (lista3);
  printf ("\n\n");

  lista3 = eliminarLista (lista3);
  mostrarLista (lista3);

  printf ("\n");
  return 0;
}
