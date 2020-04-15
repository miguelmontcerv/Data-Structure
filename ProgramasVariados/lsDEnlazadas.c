/* Listas Doblemente Ligadas */
#include<stdio.h>
#include <stdlib.h>
struct Lista
{


  int dato;


  struct Lista *siguiente;


  struct Lista *anterior;


};

struct Lista *agregarElemento (struct Lista *, int);	//Hecho
struct Lista *mezclarListas (struct Lista *, struct Lista *);
void mostrarLista (struct Lista *);	//Hecho
void mostrarInversa (struct Lista *);	//Hecho
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

  buscarElemento (lista3, numero);

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



/*struct Lista *
agregarElemento (struct Lista *lista, int dato) 
{
  
    //Agrega elementos al inicio de la lista
  struct Lista *nuevo = NULL;
  
nuevo = (struct Lista *) malloc (sizeof (struct Lista));
  
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


struct Lista *
agregarElemento (struct Lista *lista, int dato)
{

  //Agrega elementos al final de la lista
  struct Lista *aux;

  struct Lista *nuevo = NULL;

  nuevo = (struct Lista *) malloc (sizeof (struct Lista));

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


void
mostrarLista (struct Lista *lista)
{


  while (lista != NULL)

    {


      printf ("%d ", lista->dato);


      lista = lista->siguiente;


    }
}


struct Lista *
mezclarListas (struct Lista *lista1, struct Lista *lista2)
{


  struct Lista *ListaMezclada = NULL;



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
mostrarInversa (struct Lista *lista)
{

  struct Lista *aux = NULL;

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


struct Lista *
eliminarCola (struct Lista *lista)
{

  struct Lista *aux = NULL;

  struct Lista *aux2 = NULL;

  struct Lista *aux3 = NULL;

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


struct Lista *
eliminarCabeza (struct Lista *lista)
{

  struct Lista *aux = NULL;

  aux = lista;

  lista = lista->siguiente;
  lista->anterior = NULL;

  free (aux);

  return lista;
}


struct Lista *
eliminarLista (struct Lista *lista)
{

  struct Lista *aux = NULL;

  aux = lista;

  while (lista != NULL)

    {

      lista = lista->siguiente;

      free (aux);

    }

  return lista;
}


void
buscarElemento (struct Lista *lista, int dato)
{

  struct Lista *aux = NULL;

  int band = 0;

  aux = lista;

  while (aux != NULL)

    {

      if (aux->dato == dato)

	{

	  printf (" %d :)! \n", aux->dato);

	  band = 1;

	  break;

	}

      aux = aux->siguiente;

    }

  if (band == 0)

    {

      printf ("¡%d :(!! \n", dato);

    }

}


struct Lista *
buscarEliminar (struct Lista *lista, int dato)
{

  struct Lista *aux = NULL;

  struct Lista *aux2 = NULL;

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
