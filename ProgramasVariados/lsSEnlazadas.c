/* Listas Simplemente Ligadas */
#include<stdio.h>
#include <stdlib.h>
struct ListaSLigada
{

  int dato;

  struct ListaSLigada *siguiente;

  struct ListaSLigada *anterior;

};

struct ListaSLigada *agregarElemento (struct ListaSLigada *, int);
struct ListaSLigada *mezclarListas (struct ListaSLigada *, struct ListaSLigada *);
void mostrarLista (struct ListaSLigada *);
void mostrarInversa (struct ListaSLigada *);
struct ListaSLigada *eliminarCola (struct ListaSLigada *);
struct ListaSLigada *eliminarCabeza (struct ListaSLigada *);
struct ListaSLigada *eliminarLista (struct ListaSLigada *);
int buscarElemento (struct ListaSLigada *, int);
struct ListaSLigada *buscarEliminar (struct ListaSLigada *, int);

int
main (void)
{

  struct ListaSLigada *lista1 = NULL;
  struct ListaSLigada *lista2 = NULL;
  struct ListaSLigada *lista3 = NULL;

  int max, numero,busqueda = 0;

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
  printf("Si es 1 se encontro, si es 0, no se pudo encontrar: %d\n\n",busqueda);

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


struct ListaSLigada *
agregarElemento (struct ListaSLigada *lista, int dato)
{
  //Agrega elementos al inicio de la lista
  struct ListaSLigada *nuevo = NULL;
  nuevo = (struct ListaSLigada *) malloc (sizeof (struct ListaSLigada));
  nuevo->dato = dato;
  nuevo->siguiente = lista;

  return nuevo;
}

/*struct ListaSLigada *
agregarElemento (struct ListaSLigada *lista, int dato)
{

  //Agrega elementos al final de la lista
  struct ListaSLigada *aux;

  struct ListaSLigada *nuevo = NULL;

  nuevo = (struct ListaSLigada *) malloc (sizeof (struct ListaSLigada));

  nuevo->dato = dato;

  nuevo->siguiente = NULL;

  if (lista == NULL)
    {

      lista = nuevo;

    }

  else
    {

      aux = lista;

      while (aux->siguiente != NULL)
	{

	  aux = aux->siguiente;

	}

      aux->siguiente = nuevo;

    }

  return lista;
} */


void
mostrarLista (struct ListaSLigada *lista)
{

  while (lista != NULL)
    {

      printf ("%d ", lista->dato);

      lista = lista->siguiente;

    }
}

struct ListaSLigada *
mezclarListas (struct ListaSLigada *lista1, struct ListaSLigada *lista2)
{

  struct ListaSLigada *ListaMezclada = NULL;


  while (lista1 != NULL || lista2 != NULL)
    {

      if (lista1 != NULL)
	{

	  ListaMezclada = agregarElemento (ListaMezclada, lista1->dato);

	  lista1 = lista1->siguiente;

	}

      if (lista2 != NULL)
	{

	  ListaMezclada = agregarElemento (ListaMezclada, lista2->dato);

	  lista2 = lista2->siguiente;

	}

    }

  return ListaMezclada;
}

void
mostrarInversa (struct ListaSLigada *lista)
{
  if (lista)
    {
      mostrarInversa (lista->siguiente);
      printf ("%d ", lista->dato);
    }
}

struct ListaSLigada *
eliminarCola (struct ListaSLigada *lista)
{
  struct ListaSLigada *aux = NULL;
  struct ListaSLigada *aux2 = NULL;
  aux2 = lista;
  aux = lista;
  while (aux->siguiente != NULL)
    {
      aux = aux->siguiente;
    }
  while (aux2->siguiente != aux)
    {
      aux2 = aux2->siguiente;
    }
  aux2->siguiente = NULL;
  free (aux);
  return lista;
}

struct ListaSLigada *
eliminarCabeza (struct ListaSLigada *lista)
{
  struct ListaSLigada *aux = NULL;
  aux = lista;
  lista = lista->siguiente;
  free (aux);
  return lista;
}

struct ListaSLigada *
eliminarLista (struct ListaSLigada *lista)
{
  struct ListaSLigada *aux = NULL;
  aux = lista;
  while (lista != NULL)
    {
      lista = lista->siguiente;
      free (aux);
    }
  return lista;
}

int
buscarElemento (struct ListaSLigada *lista, int dato)
{
  struct ListaSLigada *aux = NULL;
  int band = 0;
  aux = lista;
  while (aux != NULL)
    {
      if (aux->dato == dato)
	{
	  //printf (" %d :)! \n", aux->dato);
    band = 1;
	  return 1;
    break;
	}
      aux = aux->siguiente;
    }
  if (band == 0)
    {
      //printf ("¡%d :(!! \n", dato);
      return 0;
    }

}

struct ListaSLigada *
buscarEliminar (struct ListaSLigada *lista, int dato)
{
  struct ListaSLigada *aux = NULL;
  struct ListaSLigada *aux2 = NULL;
  int band = 0;
  aux = lista;
  aux2 = lista;
  while (aux != NULL)
    {
      if (aux->dato == dato)
	{
	  while (aux2->siguiente != aux)
	    {
	      aux2 = aux2->siguiente;
	    }
	  aux2->siguiente = aux->siguiente;
	  free (aux);
	  band = 1;
	  break;
	}
      aux = aux->siguiente;
    }
  if (band == 0)
    {
      printf ("¡%d :(!! \n", dato);
    }

  return lista;

}
