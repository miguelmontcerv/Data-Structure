#include"lscdoble.h"

struct ListaCDoble *
agregarElemento (struct ListaCDoble *lista, int dato)
{

  //Agrega elementos al final de la lista

  struct ListaCDoble *aux;
  struct ListaCDoble *fin;

  struct ListaCDoble *nuevo = NULL;

  nuevo = (struct ListaCDoble *) malloc (sizeof (struct ListaCDoble));

  nuevo->dato = dato;

  nuevo->siguiente = NULL;
  nuevo->anterior = NULL;

  if (lista == NULL)
    {
      lista = nuevo;
      lista->siguiente = lista;
      lista->anterior = lista;
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
      lista->anterior = nuevo;
      nuevo->siguiente = lista;
      nuevo->anterior = fin;
    }

  return lista;
}

void
mostrarLista (struct ListaCDoble *lista)
{
  struct ListaCDoble *aux;
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
mostrarInversa (struct ListaCDoble *lista)
{
  struct ListaCDoble *aux;
  aux = lista;

  if (aux == NULL)
    {
      printf ("La lista esta vacia...\n");
      return;
    }
  aux = aux->anterior;
  while (aux != lista)
    {

      printf ("%d ", aux->dato);

      aux = aux->anterior;

    }
  printf ("%d ", aux->dato);
}

struct ListaCDoble *
mezclarListas (struct ListaCDoble *lista1, struct ListaCDoble *lista2)
{

  struct ListaCDoble *ListaMezclada = NULL;
  struct ListaCDoble *fin1;
  struct ListaCDoble *fin2;
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


struct ListaCDoble *
eliminarCola (struct ListaCDoble *lista)
{
  struct ListaCDoble *aux;
  struct ListaCDoble *fin;
  fin = lista;
  fin = fin->siguiente;
  while (fin->siguiente != lista)
    {
      fin = fin->siguiente;
    }
  //Fin ya esta en el final de la lista
  aux = fin->anterior;
  aux->siguiente = lista;
  lista->anterior = aux;
  free (fin);
  return lista;
}

struct ListaCDoble *
eliminarCabeza (struct ListaCDoble *lista)
{
  struct ListaCDoble *aux;

  struct ListaCDoble *fin;
  fin = lista;
  fin = fin->siguiente;
  while (fin->siguiente != lista)
    {
      fin = fin->siguiente;
    }
  //Llegamos el final de la lista
  aux = lista;
  lista = lista->siguiente;
  lista->anterior = fin;
  fin->siguiente = lista;
  free (aux);
  return lista;
}

int
buscarElemento (struct ListaCDoble *lista, int dato)
{
  struct ListaCDoble *fin;
  fin = lista;
  if (fin->dato == dato)
    {
      //printf ("%d :)!\n", fin->dato);
      return 1;
    }
  fin = fin->siguiente;
  while (fin != lista)
    {
      if (fin->dato == dato)
	{
	  //printf ("%d :)!\n", fin->dato);
	  return 1;
	}
      fin = fin->siguiente;
    }
  //printf ("¡¡%d :(!\n", dato);
  return 0;
}

struct ListaCDoble *
buscarEliminar (struct ListaCDoble *lista, int dato)
{
  struct ListaCDoble *fin;
  struct ListaCDoble *aux;
  struct ListaCDoble *aux2;
  aux2 = lista;
  fin = lista;
  if (lista->dato == dato)
    {

      while (fin->siguiente != lista)
	{
	  fin = fin->siguiente;
	}
      printf ("%d :)! Eliminado...\n", lista->dato);
      aux = lista;
      lista = lista->siguiente;
      lista->anterior = fin;
      fin->siguiente = lista;
      return lista;
    }
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
	  aux->anterior = aux2;
	  free (fin);
	  return lista;
	}
      fin = fin->siguiente;
    }
  printf ("¡¡%d :(!\n", dato);
  return lista;
}

struct ListaCDoble *
eliminarLista (struct ListaCDoble *lista)
{
  struct ListaCDoble *fin;
  struct ListaCDoble *aux;
  struct ListaCDoble *aux2;
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
