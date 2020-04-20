#include<stdio.h>
#include<stdlib.h>

struct cuentaHabiente
{
  char Nombre[100];
  long long No_Cuenta;
  int NIP;
  int Sucursal;
  int T_Cuenta;
};


struct FilaDeBanco
{

  struct cuentaHabiente persona;
  struct FilaDeBanco *siguiente;
  struct FilaDeBanco *anterior;
};


struct FilaDeBanco *formarFila (struct FilaDeBanco *Fila,
				struct cuentaHabiente persona);
void mostrarFilaDeBanco (struct FilaDeBanco *Fila);
struct FilaDeBanco *atenderFila (struct FilaDeBanco *Fila);

int
main ()
{
  struct FilaDeBanco *unaFila = NULL;

  struct cuentaHabiente persona =
    { "UnaPersona", 1234567891234567, 1245, 8, 2 };
  struct cuentaHabiente persona1 =
    { "Una Persona1", 2234567891234567, 1234, 7, 1 };
  struct cuentaHabiente persona2 =
    { "Una Persona2", 1244567891234567, 1234, 7, 1 };
  struct cuentaHabiente persona3 =
    { "Una Persona3", 1234667891234567, 1234, 7, 1 };

  unaFila = formarFila (unaFila, persona);
  unaFila = formarFila (unaFila, persona1);
  unaFila = formarFila (unaFila, persona2);
  unaFila = formarFila (unaFila, persona3);

  mostrarFilaDeBanco (unaFila);

  unaFila = atenderFila (unaFila);
  unaFila = atenderFila (unaFila);


  mostrarFilaDeBanco (unaFila);


  return 0;
}

struct FilaDeBanco *
formarFila (struct FilaDeBanco *Fila, struct cuentaHabiente persona)
{
  if (Fila == NULL)
    {

      struct FilaDeBanco *nuevo = (struct FilaDeBanco *) malloc (sizeof (struct FilaDeBanco));	//crea nodo inicial
      nuevo->persona = persona;
      nuevo->siguiente = nuevo;
      nuevo->anterior = nuevo;
      return nuevo;
    }


  struct FilaDeBanco *nuevo = (struct FilaDeBanco *) malloc (sizeof (struct FilaDeBanco));	//crea nodo
  nuevo->persona = persona;

  nuevo->siguiente = Fila;

  struct FilaDeBanco *ultimo = Fila->anterior;

  nuevo->anterior = ultimo;
  Fila->anterior->siguiente = nuevo;
  Fila->anterior = nuevo;

  return Fila;

}


void
mostrarFilaDeBanco (struct FilaDeBanco *Fila)
{
  if (Fila == NULL)
    {
      printf ("La fila esta vacia");
    }
  else
    {
      puts ("en la fila hay:");
      struct FilaDeBanco *aux = Fila;

      do
	{
	  puts (aux->persona.Nombre);
	  aux = aux->siguiente;
	}
      while (aux != Fila);

    }
}


struct FilaDeBanco *
atenderFila (struct FilaDeBanco *Fila)
{

  struct FilaDeBanco *segundo = Fila->siguiente;
  struct FilaDeBanco *ultimo = Fila->anterior;
  struct FilaDeBanco *aux = Fila;

  segundo->anterior = ultimo;
  ultimo->siguiente = segundo;

  Fila = Fila->siguiente;
  free (aux);
  return Fila;
}
