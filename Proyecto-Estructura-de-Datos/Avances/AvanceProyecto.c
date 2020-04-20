/*
Avance del 10 / 11 / 19
Implementacion de eliminacion de usuario, problema al compara un usuario con otro
*/

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
int esHoja (struct arbolDeBanco *raiz);
struct arbolDeBanco *padreDe (struct arbolDeBanco *raiz,
			      struct cuentaHabiente persona);
void consultarArbol (struct arbolDeBanco *raiz,
		     struct cuentaHabiente persona);
struct arbolDeBanco *ElimiarCuenta(struct arbolDeBanco *raiz,
            struct cuentaHabiente persona);
int Vacio(struct arbolDeBanco *raiz)
{
  return raiz == NULL;
}

int
main ()
{
  struct arbolDeBanco *unArbol = NULL;

  struct cuentaHabiente personaRaiz =
    { "Ana Morales G", 5234567891234567, 1245, 8, 2 };
  struct cuentaHabiente persona1 =
    { "Juan Perez Martinez", 7234567891234567, 1234, 7, 1 };
  struct cuentaHabiente persona2 =
    { "Sofia Maldonado Herrera", 1244567891234567, 1234, 7, 1 };
  struct cuentaHabiente persona3 =
    { "Menuel Aguirre Nuñez", 1234667891234567, 1234, 7, 1 };
  struct cuentaHabiente persona4 =
    { "Paulina Mora Carranza", 6456824598745632, 1234, 6, 2 };
  struct cuentaHabiente persona5 =
    { "Joseph Santos Alatorre", 8456824598745632, 1234, 6, 2 };
  struct cuentaHabiente persona6 =
    { "Karla Juarez Acosta", 9756824598745632, 1234, 6, 2 };
  struct cuentaHabiente persona7 =
    { "Salvador Montoya", 8356824598745632, 1234, 6, 2 };

  unArbol = insertarArbol (unArbol, personaRaiz);
  unArbol = insertarArbol (unArbol, persona1);
  unArbol = insertarArbol (unArbol, persona2);
  unArbol = insertarArbol (unArbol, persona3);
  unArbol = insertarArbol (unArbol, persona4);
  unArbol = insertarArbol (unArbol, persona5);
  unArbol = insertarArbol (unArbol, persona6);
  unArbol = insertarArbol (unArbol, persona7);

  printf("Todos los cuenta habientes son...\n");
  mostrarArbol (unArbol);
  puts ("");

  puts ("Consulta de usuario: ");
  consultarArbol (unArbol, persona3);
  puts ("");
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
  printf("\t%s\n",raiz->persona.Nombre);// puts(raiz->persona.Nombre);
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

  struct arbolDeBanco *buscado;

  if (raiz->persona.No_Cuenta > persona.No_Cuenta)
    {
      buscado = buscarArbol (raiz->izq, persona);
    }
  else
    {
      buscado = buscarArbol (raiz->der, persona);
    }
  if (buscado != NULL)
    {
      return buscado;
    }
  if (buscado == NULL)
    {
      return NULL;
    }
}


void
consultarArbol (struct arbolDeBanco *raiz, struct cuentaHabiente persona)
{
  struct arbolDeBanco *buscado = buscarArbol (raiz, persona);
  printf ("\tNombre del Titular: ");
  puts (buscado->persona.Nombre);
  printf ("\tNo de Sucursal: %d\t\t", buscado->persona.Sucursal);
  printf ("\tTipo de cuenta: %d\n", buscado->persona.T_Cuenta);
  printf ("\tNo. de cuenta: %lld\n", buscado->persona.No_Cuenta);

}

int
esHoja (struct arbolDeBanco *raiz)
{
  if (raiz->der == NULL && raiz->izq == NULL)
    {
      return 1;
    }
  else
    {
      return 0;
    }

}

struct arbolDeBanco *
padreDe (struct arbolDeBanco *raiz, struct cuentaHabiente persona)
{
  if (raiz == NULL)
    {
      return NULL;
    }

  struct arbolDeBanco *buscado = NULL;
  buscado = buscarArbol (raiz, persona);
  if (buscado == NULL)
    {
      return NULL;
    }

  if ((raiz->izq != NULL && raiz->izq->persona.No_Cuenta == persona.No_Cuenta)
      || (raiz->der != NULL
	  && raiz->der->persona.No_Cuenta == persona.No_Cuenta))
    {
      return raiz;
    }

  struct arbolDeBanco *padre = NULL;
  struct arbolDeBanco *padre2 = NULL;

  if (persona.No_Cuenta < raiz->persona.No_Cuenta)
    {
      padre = padreDe (raiz->izq, persona);
    }
  if (persona.No_Cuenta > raiz->persona.No_Cuenta)
    {
      padre2 = padreDe (raiz->der, persona);
    }
  if (padre != NULL)
    {
      return padre;
    }
  if (padre2 != NULL)
    {
      return padre2;
    }
  return NULL;

}
//// Implementacion de eliminacion de persona
/*
struct arbolDeBanco *ElimiarCuenta(struct arbolDeBanco *raiz,struct cuentaHabiente persona){
  struct arbolDeBanco *nodo = NULL;
  struct arbolDeBanco *padre = NULL;
  struct arbolDeBanco *actual = NULL;
  int aux = 0;

  actual = raiz;
  while(!Vacio(actual)) //Mientras la raiz no este vacia
  {
    if(persona == actual -> persona) //Se encontro el dato
    {
      if(esHoja(actual)) //Si es hoja, solo se elimina
      {
        if(padre) //Si el pare existe, es decir, si no es raiz
        {
          //Eliminamos los punteros que señalan al actual
          if(padre -> izq == actual)
            padre -> izq = NULL;
          else if(padre -> der == actual)
            padre -> der = NULL;
        }
        //Si no existe el padre, y tampoco tiene hijos, solo es un nodo, asi que lo elimino
        free(actual);
        actual = NULL;
      }
      else
      { //Si el nodo tiene hijos
        padre = actual;
        //A quien le dejamos los hijos? Al menor de los mayores (al más izquierdo de la rama derecha)
        if(actual -> der) //Existe
        {
          nodo = actual -> der;
          while(nodo -> izq){
            padre = nodo;
            nodo = nodo -> izq;
          } //Llegammos el menor de los mayores
        }
        else //Si no tiene mayores, se lo damos al mayor de los menores
        {
          nodo = actual -> izq;
          while(nodo -> der){
            padre = nodo;
            nodo = nodo -> der;
          }
        }
      
        //Hacemos cambio de posicion para asegurarnos que lo que se elimine es un nodo hoja
        aux = actual -> persona;
        actual -> persona = nodo -> persona;
        nodo -> persona = aux;
        actual = nodo;
      }
    } 
    else //No se encontro, hay que seguir buscando
    {
      padre = actual;
      if(persona > actual -> persona)
        actual = actual -> der;
      else if(persona < actual -> persona)
        actual = actual -> izq;
    }

  }
} */
