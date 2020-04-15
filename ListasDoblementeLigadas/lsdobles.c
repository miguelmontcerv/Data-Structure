#include"lsdobles.h"

struct ListaDoble *
agregarElemento (struct ListaDoble *lista, int dato)
{

  //Agrega elementos al final de la lista
  struct ListaDoble *aux;
  struct ListaDoble *nuevo = NULL;
  
  nuevo = (struct ListaDoble *) malloc (sizeof (struct ListaDoble));
  nuevo->dato = dato;
  nuevo->siguiente = NULL;

  if (lista == NULL)
  {
    nuevo->anterior = NULL;
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
  nuevo->anterior = aux;

 }
  return lista;
}

/*struct ListaDoble *
agregarElemento (struct ListaDoble *lista, int dato) 
{
  
    //Agrega elementos al inicio de la lista
  struct ListaDoble *nuevo = NULL;
  
nuevo = (struct ListaDoble *) malloc (sizeof (struct ListaDoble));
  
if (nuevo == NULL)
    {
      
return NULL;
    
}
  
nuevo->dato = dato;
  
nuevo->siguiente = lista;
  
nuevo->anterior = NULL;
  
if (lista == NULL)
    {
      
return nuevo;
    
}
  
  else
    {
      
lista->anterior = nuevo;
    
}
  
return nuevo;
} */



void
mostrarLista (struct ListaDoble *lista)
{
  while (lista != NULL)
  {
    printf ("%d ", lista->dato);
    lista = lista->siguiente;
  }
}


struct ListaDoble *
mezclarListas (struct ListaDoble *lista1, struct ListaDoble *lista2)
{
  struct ListaDoble *ListaMezclada = NULL;

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
mostrarInversa (struct ListaDoble *lista)
{

  struct ListaDoble *aux = NULL;
  aux = lista;
  while (aux->siguiente != NULL)
  {
    aux = aux->siguiente;
  }

  while (aux != NULL)
  {
    printf ("%d ", aux->dato);
    aux = aux->anterior;
  }
}


struct ListaDoble *
eliminarCola (struct ListaDoble *lista)
{

  struct ListaDoble *aux = NULL;
  struct ListaDoble *aux2 = NULL;
  struct ListaDoble *aux3 = NULL;

  aux3 = lista;
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

  while (aux3->siguiente != aux2)
  {
    aux3 = aux3->siguiente;
  }

  aux2->siguiente = NULL;
  aux2->anterior = aux3;
  aux3->siguiente = aux2;

  free (aux);

  return lista;
}


struct ListaDoble *
eliminarCabeza (struct ListaDoble *lista)
{
  struct ListaDoble *aux = NULL;

  aux = lista;
  lista = lista->siguiente;
  lista->anterior = NULL;

  free (aux);

  return lista;
}


struct ListaDoble *
eliminarLista (struct ListaDoble *lista)
{

  struct ListaDoble *aux = NULL;
  aux = lista;

  while (lista != NULL)
  {
    lista = lista->siguiente;
    free (aux);
  }

return lista;
}


int
buscarElemento (struct ListaDoble *lista, int dato)
{

  struct ListaDoble *aux = NULL;
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


struct ListaDoble *
buscarEliminar (struct ListaDoble *lista, int dato)
{

  struct ListaDoble *aux = NULL;
  struct ListaDoble *aux2 = NULL;

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
	  printf ("%d Eliminado!! \n", dato);

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
