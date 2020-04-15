#include"hash.h"

int
FuncionHash (char *palabra)	//Primo con un universo de 200
{
  int numero = 0, i;
  int const p = 9973, a = 509, b = 7372, m = 200;	//Constantes para Hasheo Primo

  for (i = 0; *(palabra + i) != '\0'; i++)
    {
      numero = numero + *(palabra);
    }

  return (((numero * a) + b) % p) % m;
}

void
AgregarDato (struct TablaHash **tabla, char *palabra)
{
  int posicion = 0, i = 0, band = 0;
  if (tabla == NULL)
    return;

  if (*tabla == NULL)
    {
      *tabla = (struct TablaHash *) malloc (sizeof (struct TablaHash));
      (*tabla)->datos = (char **) malloc (sizeof (char) * 200);	//Creamos un espacio de 200
    }
  	posicion = FuncionHash (palabra);

  	if(*((*tabla)->datos + posicion) == 0)
  	{
  	*((*tabla)->datos + posicion + i) = palabra;
  	}
  	else if(*((*tabla)->datos + posicion) != 0) //Agregamos a la lista
    {
     (*tabla)->lista = agregarElemento((*tabla)->lista, palabra);
    }

  return;
}

int
BuscarDato (struct TablaHash *tabla, char *palabra)
{
  int posicion, i = 0;
  if (tabla == NULL)
    return 0;

  posicion = FuncionHash (palabra);

  if (*(tabla->datos + posicion) != 0)	//Si la palabra tiene un dato
    {
      if (strcmp (*(tabla->datos + posicion), palabra) == 0)	//Si la palabra encontradad es igual a la buscada
	{
	  return 1;
	}
      else
	{
	 return buscarElemento(tabla->lista,palabra);
	}
    }
  else
	  return 0;
}

void
EliminarDato (struct TablaHash **tabla, char *palabra)
{
  printf ("eliminando...\n\t");
  int posicion, i = 0;
  if (tabla == NULL)
    return;

  posicion = FuncionHash (palabra);
  if (*((*tabla)->datos + posicion) != 0)	//Se encotro un dato en la memoria
    {
      if (strcmp (*((*tabla)->datos + posicion), palabra) == 0)
	{
	  *((*tabla)->datos + posicion) = 0;
	  printf ("HECHO\n");
	  return;
	}
      else
	{
	  if (posicion == 200)
	    {
	      for (i = 0; strcmp (*((*tabla)->datos + i), palabra) != 0; i++);	//Ya se encontro el dato
	      *((*tabla)->datos + i) = 0;
	      printf ("HECHO\n");
	    }
	  else
	    {
	      for (i = 0;
		   strcmp (*((*tabla)->datos + posicion + i), palabra) != 0;
		   i++);
	      *((*tabla)->datos + posicion + i) = 0;
	      printf ("HECHO\n");
	    }
	}
    }
  else
    printf ("La palabra no se encontro\n");
}

struct ListaLigada *
agregarElemento (struct ListaLigada *lista, char *dato)
{
  //Agrega elementos al inicio de la lista
  struct ListaLigada *nuevo = NULL;
  nuevo = (struct ListaLigada *) malloc (sizeof (struct ListaLigada));
  nuevo->dato = dato;
  nuevo->siguiente = lista;

  return nuevo;
}


int
buscarElemento (struct ListaLigada *lista, char *dato)
{
  struct ListaLigada *aux = NULL;
  int band = 0;
  aux = lista;
  while (aux != NULL)
    {
    if ( strcmp (lista->dato, dato) == 0)
	{
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