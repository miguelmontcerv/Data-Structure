// Listas Circulares

#include<stdio.h>
#include <stdlib.h>
struct Lista
{

  int dato;

  struct Lista *siguiente;

};

struct Lista *agregarElemento (struct Lista *, int);
void mostrarLista (struct Lista *);
void mostrarInversa (struct Lista *);
struct Lista *mezclarListas (struct Lista *, struct Lista *);
struct Lista *eliminarCola (struct Lista *);
struct Lista *eliminarCabeza (struct Lista *);
struct Lista *eliminarLista (struct Lista *);
void buscarElemento (struct Lista *, int);
struct Lista *buscarEliminar (struct Lista *, int);

int
main (void)
{


  struct Lista *lista1 = NULL;

  struct Lista *lista2 = NULL;

  struct Lista *lista3 = NULL;

  int max, numero;
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
  printf ("\n\n");

  lista3 = eliminarCola (lista3);
  mostrarLista (lista3);
  printf ("\n\n");

  lista3 = eliminarCabeza (lista3);
  mostrarLista (lista3);
  printf ("\n\n");

//Buscamos Un Dato:
  scanf ("%d", &max);
  buscarElemento (lista3, max);
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

struct Lista *
agregarElemento (struct Lista *lista, int dato)
{

  //Agrega elementos al final de la lista

  struct Lista *aux;
  struct Lista *fin;

  struct Lista *nuevo = NULL;

  nuevo = (struct Lista *) malloc (sizeof (struct Lista));

  nuevo->dato = dato;

  nuevo->siguiente = NULL;

  if (lista == NULL)
    {
      lista = nuevo;
      lista->siguiente = lista;
    }
  else
    {
      fin = lista;
      fin = fin->siguiente;
      while (fin->siguiente != lista)
	{
	  fin = fin->siguiente;
	}
      fin->siguiente = nuevo;
      nuevo->siguiente = lista;
    }

  return lista;
}

void
mostrarLista (struct Lista *lista)
{
  struct Lista *aux;
  aux = lista;

  if (aux == NULL)
    {
      printf ("La lista esta vacia...\n");
      return;
    }

  printf ("%d ", aux->dato);
  aux = aux->siguiente;

  while (aux != lista)
    {

      printf ("%d ", aux->dato);

      aux = aux->siguiente;

    }
}

void
mostrarInversa (struct Lista *lista)
{
  struct Lista *aux;
  struct Lista *fin;
  fin = lista;
  fin = fin->siguiente;
  while (fin->siguiente != lista)
    {
      fin = fin->siguiente;
    }
  //Fin ya esta en el final de la lista
  printf ("%d ", fin->dato);
  while (fin != lista)
    {
      aux = lista;
      while (aux->siguiente != fin)
	{
	  aux = aux->siguiente;
	}
      fin = aux;
      printf ("%d ", aux->dato);
    }
}

struct Lista *
mezclarListas (struct Lista *lista1, struct Lista *lista2)
{

  struct Lista *ListaMezclada = NULL;
  struct Lista *fin1;
  struct Lista *fin2;
  int band = 1;
  int band2 = 1;
  int count1 = 0, count2 = 0;
  fin1 = lista1;
  fin2 = lista2;

  while (fin1->siguiente != lista1)
    {
      fin1 = fin1->siguiente;
      count1++;
    }
  while (fin2->siguiente != lista2)
    {
      fin2 = fin2->siguiente;
      count2++;
    }

  while (lista1 != fin1 || lista2 != fin2)
    {

      if (lista1 != fin1)
	{

	  ListaMezclada = agregarElemento (ListaMezclada, lista1->dato);

	  lista1 = lista1->siguiente;

	}
      ////  Problema ////
      else if (band == 1)
	{
	  band = 0;
	  agregarElemento (ListaMezclada, lista1->dato);
	}

      if (lista2 != fin2)
	{

	  ListaMezclada = agregarElemento (ListaMezclada, lista2->dato);

	  lista2 = lista2->siguiente;
	}
      else if (band2 == 1)
	{
	  band2 = 0;
	  agregarElemento (ListaMezclada, lista2->dato);
	}
    }
  ////// Imprimir Ultimos Datos ///////

  if (count1 > count2)
    {
      ListaMezclada = agregarElemento (ListaMezclada, lista1->dato);
    }
  else if (count2 > count1)
    {
      ListaMezclada = agregarElemento (ListaMezclada, lista2->dato);
    }
  else
    {
      ListaMezclada = agregarElemento (ListaMezclada, lista1->dato);
      ListaMezclada = agregarElemento (ListaMezclada, lista2->dato);
    }


  return ListaMezclada;
}

struct Lista *
eliminarCola (struct Lista *lista)
{
  struct Lista *aux;
  struct Lista *fin;
  fin = lista;
  fin = fin->siguiente;
  while (fin->siguiente != lista)
    {
      fin = fin->siguiente;
    }
  //Fin ya esta en el final de la lista
  aux = lista;
  while (aux->siguiente != fin)
    {
      aux = aux->siguiente;
    }
  //Aux esta una antes del final
  aux->siguiente = lista;
  free (fin);
  return lista;
}

struct Lista *
eliminarCabeza (struct Lista *lista)
{
  struct Lista *aux;

  struct Lista *fin;
  fin = lista;
  fin = fin->siguiente;
  while (fin->siguiente != lista)
    {
      fin = fin->siguiente;
    }
  aux = lista;
  lista = lista->siguiente;
  fin->siguiente = lista;
  free (aux);
  return lista;
}

void
buscarElemento (struct Lista *lista, int dato)
{
  struct Lista *fin;
  fin = lista;
  fin = fin->siguiente;
  while (fin != lista)
    {
      if (fin->dato == dato)
	{
	  printf ("%d :)!\n", fin->dato);
	  return;
	}
      fin = fin->siguiente;
    }
  printf ("¡¡%d :(!\n", dato);
  return;
}

struct Lista *
buscarEliminar (struct Lista *lista, int dato)
{
  struct Lista *fin;
  struct Lista *aux;
  struct Lista *aux2;
  aux2 = lista;
  fin = lista;
  fin = fin->siguiente;
  while (fin != lista)
    {
      if (fin->dato == dato)
	{
	  printf ("%d :)! Eliminado...\n", fin->dato);
	  aux = fin->siguiente;
	  while (aux2->siguiente != fin)
	    {
	      aux2 = aux2->siguiente;
	    }
	  aux2->siguiente = aux;
	  free (fin);
	  return lista;
	}
      fin = fin->siguiente;
    }
  printf ("¡¡%d :(!\n", dato);
  return lista;
}

struct Lista *
eliminarLista (struct Lista *lista)
{
  struct Lista *fin;
  struct Lista *aux;
  struct Lista *aux2;
  aux = lista;
  fin = lista;
  while (fin->siguiente != lista)
    {
      fin = fin->siguiente;
    }
  fin->siguiente = NULL;
  while (aux != NULL)
    {				//o  aux -> siguiente !=  NULL???
      aux2 = aux;
      aux = aux->siguiente;
      free (aux2);
    }

}
