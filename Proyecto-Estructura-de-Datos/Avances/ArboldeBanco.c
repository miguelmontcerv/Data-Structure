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


struct arbolDeBanco
{
  struct cuentaHabiente persona;
  struct arbolDeBanco *izq;
  struct arbolDeBanco *der;
};

struct arbolDeBanco *insertarArbol (struct arbolDeBanco *raiz,
				    struct cuentaHabiente persona);
void mostrarArbol (struct arbolDeBanco *raiz);
struct arbolDeBanco *buscarArbol (struct arbolDeBanco *raiz,
				  struct cuentaHabiente persona);
void consultarArbol (struct arbolDeBanco *raiz,
		     struct cuentaHabiente persona);


int
main ()
{
  struct arbolDeBanco *unArbol = NULL;

  struct cuentaHabiente persona =
    { "UnaPersona", 5234567891234567, 1245, 8, 2 };
  struct cuentaHabiente persona1 =
    { "Una Persona1", 7234567891234567, 1234, 7, 1 };
  struct cuentaHabiente persona2 =
    { "Una Persona2", 1244567891234567, 1234, 7, 1 };
  struct cuentaHabiente persona3 =
    { "Una Persona3", 1234667891234567, 1234, 7, 1 };
  struct cuentaHabiente persona4 =
    { "Una PERSONA4", 6456824598745632, 1234, 6, 2 };
  struct cuentaHabiente persona5 =
    { "Una PERSONA5", 8456824598745632, 1234, 6, 2 };
  struct cuentaHabiente persona6 =
    { "Una PERSONA6", 9756824598745632, 1234, 6, 2 };
  struct cuentaHabiente persona7 =
    { "Una PERSONA7", 8356824598745632, 1234, 6, 2 };

  unArbol = insertarArbol (unArbol, persona);
  unArbol = insertarArbol (unArbol, persona1);
  unArbol = insertarArbol (unArbol, persona2);
  unArbol = insertarArbol (unArbol, persona3);
  unArbol = insertarArbol (unArbol, persona4);
  unArbol = insertarArbol (unArbol, persona5);
  unArbol = insertarArbol (unArbol, persona6);
  unArbol = insertarArbol (unArbol, persona7);
  mostrarArbol (unArbol);
  puts ("");
  consultarArbol (unArbol, persona3);

  return 0;
}


struct arbolDeBanco *
insertarArbol (struct arbolDeBanco *raiz, struct cuentaHabiente persona)
{
  if (raiz == NULL)
    {
      struct arbolDeBanco *nuevo =
	(struct arbolDeBanco *) malloc (sizeof (struct arbolDeBanco));
      nuevo->persona = persona;
      nuevo->izq = NULL;
      nuevo->der = NULL;
      return nuevo;
    }
  if (persona.No_Cuenta < raiz->persona.No_Cuenta)
    {
      struct arbolDeBanco *nuevo = insertarArbol (raiz->izq, persona);
      raiz->izq = nuevo;
      return raiz;
    }
  if (persona.No_Cuenta > raiz->persona.No_Cuenta)
    {
      struct arbolDeBanco *nuevo = insertarArbol (raiz->der, persona);
      raiz->der = nuevo;
      return raiz;
    }
}


void
mostrarArbol (struct arbolDeBanco *raiz)
{
  if (raiz == NULL)
    {
      return;
    }
  puts (raiz->persona.Nombre);
  mostrarArbol (raiz->izq);
  mostrarArbol (raiz->der);
}

struct arbolDeBanco *
buscarArbol (struct arbolDeBanco *raiz, struct cuentaHabiente persona)
{
  if (raiz == NULL)
    {
      return NULL;
    }
  if (raiz->persona.No_Cuenta == persona.No_Cuenta)
    {
      return raiz;
    }
  struct arbolDeBanco *buscado1 =
    (struct arbolDeBanco *) malloc (sizeof (struct arbolDeBanco));
  struct arbolDeBanco *buscado2 =
    (struct arbolDeBanco *) malloc (sizeof (struct arbolDeBanco));

  buscado1 = buscarArbol (raiz->izq, persona);
  buscado2 = buscarArbol (raiz->der, persona);

  if (buscado1 != NULL)
    {
      return buscado1;
    }
  if (buscado2 != NULL)
    {
      return buscado2;
    }
  return NULL;
}

void
consultarArbol (struct arbolDeBanco *raiz, struct cuentaHabiente persona)
{
  struct arbolDeBanco *buscado = buscarArbol (raiz, persona);
  printf ("No de Sucursal: %d\t\t", buscado->persona.Sucursal);
  printf ("Tipo de cuenta: %d\n", buscado->persona.T_Cuenta);

  printf ("Nombre del Titular: ");
  puts (buscado->persona.Nombre);

  printf ("No. de cuenta: %lld\n", buscado->persona.No_Cuenta);

}
