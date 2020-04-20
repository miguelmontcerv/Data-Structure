#include "proyecto.h"

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
  if (buscado == NULL)
  {
    puts("No se encontro elemento");
    return;
  }
  printf ("No de Sucursal: %d\t\t", buscado->persona.Sucursal);
  printf ("Tipo de cuenta: %d\n", buscado->persona.T_Cuenta);

  printf ("Nombre del Titular: ");
  puts (buscado->persona.Nombre);

  printf ("No. de cuenta: %lld\n", buscado->persona.No_Cuenta);

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

struct arbolDeBanco *
mayorDe (struct arbolDeBanco *raiz)
{
  if (raiz == NULL)
    {
      return NULL;
    }

  struct arbolDeBanco *mayor = NULL;

  if (raiz->der != NULL)
    {
      mayor = mayorDe (raiz->der);
    }
  else
    {
      return raiz;
    }
  return mayor;
}

struct arbolDeBanco *
menorDe (struct arbolDeBanco *raiz)
{
  if (raiz == NULL)
    {
      return NULL;
    }

  struct arbolDeBanco *menor = NULL;

  if (raiz->izq != NULL)
    {
      menor = menorDe (raiz->izq);
    }
  else
    {
      return raiz;
    }
  return menor;
}

struct arbolDeBanco *
eliminarRaizDeArbol (struct arbolDeBanco *raiz)
{
  if (raiz == NULL)
    {
      return NULL;
    }

  if (esHoja (raiz))
    {
      free (raiz);
      return NULL;
    }

  struct arbolDeBanco *mayor = NULL;
  mayor = mayorDe (raiz->izq);

  if (mayor != NULL)
    {

      struct arbolDeBanco *padreDeMayor = NULL;
      padreDeMayor = padreDe (raiz, mayor->persona);

      if (esHoja (mayor))
  {
    if (raiz->izq->persona.No_Cuenta == mayor->persona.No_Cuenta)
      {
        mayor->der = raiz->der;
        free (raiz);
        return mayor;
      }
    else
      {
        padreDeMayor->der = mayor->izq;
        mayor->izq = raiz->izq;
        mayor->der = raiz->der;
        free (raiz);
        return mayor;
      }
  }
      else
  {
    if (raiz->izq->persona.No_Cuenta == mayor->persona.No_Cuenta)
      {
        mayor->der = raiz->der;
        free (raiz);
        return mayor;
      }
    else
      {
        padreDeMayor->der = mayor->izq;
        mayor->der = raiz->der;
        mayor->izq = raiz->izq;
        free (raiz);
        return mayor;
      }
  }
    }

  struct arbolDeBanco *menor = NULL;
  menor = menorDe (raiz->der);

  if (menor != NULL)
    {
      struct arbolDeBanco *padreDeMenor = NULL;
      padreDeMenor = padreDe (raiz, menor->persona);

      if (esHoja (menor))
  {
    if (raiz->der->persona.No_Cuenta == menor->persona.No_Cuenta)
      {
        menor->izq = raiz->izq;
        free (raiz);
        return menor;
      }
    else
      {
        padreDeMenor->izq = menor->der;
        menor->izq = raiz->izq;
        menor->der = raiz->der;
        free (raiz);
        return menor;
      }
  }
      else
  {
    if (raiz->der->persona.No_Cuenta == menor->persona.No_Cuenta)
      {
        menor->izq = raiz->izq;
        free (raiz);
        return menor;
      }
    else
      {
        padreDeMenor->izq = menor->der;
        menor->izq = raiz->izq;
        menor->der = raiz->der;
        free (raiz);
        return menor;
      }
  }
    }
  return raiz;
}


struct arbolDeBanco *
eliminarDeArbol (struct arbolDeBanco *raiz, struct cuentaHabiente persona)
{
  if (raiz == NULL)
    {
      return NULL;
    }

  if (raiz->persona.No_Cuenta == persona.No_Cuenta)
    {
     return eliminarRaizDeArbol(raiz);
    }

  struct arbolDeBanco *buscado = NULL;
  buscado = buscarArbol (raiz, persona);
  if (buscado == NULL)
    return NULL;

  struct arbolDeBanco *padreDeBuscado = NULL;
  padreDeBuscado = padreDe (raiz, buscado->persona);
  if(padreDeBuscado == NULL)
    return NULL;
  
  if (padreDeBuscado->persona.No_Cuenta > buscado->persona.No_Cuenta)
    {
      padreDeBuscado->izq = eliminarRaizDeArbol(buscado);
      return raiz;
    }

  if (padreDeBuscado->persona.No_Cuenta < buscado->persona.No_Cuenta)
    {
      padreDeBuscado->der = eliminarRaizDeArbol(buscado);
      return raiz;
    }
}

int menu ()
{
  int identifica = 0; 
   printf("\tIntroduza el numero para la accion que desea realizar\n");
   printf("1) Registrar nuevo cliente\n");
   printf("2) Consultar cliente\n");
   printf("3) Eliminar cliente\n");
   printf("4) Mostrar todos los usuarios\n");
   printf("0) Salir\n");

  scanf("%d", &identifica);
  
  return identifica;
  
}


struct cuentaHabiente crearCH(){
  char cad[100] = "";
  int NIP = 0;	
  int T_C = 0;  
  struct cuentaHabiente nuevo;

  long long largo = generarNumValido();

    puts("Introduzca el Nombre");
    fflush(stdin);
    scanf("%s", nuevo.Nombre);
    fflush(stdin);

    puts("Introduzca NIP");
    scanf("%d", &nuevo.NIP);

    puts("Introduzca el tipo de cuenta");
    scanf("%d", &nuevo.T_Cuenta);

    nuevo.No_Cuenta = largo;
    nuevo.Sucursal = 2;
    //struct cuentaHabiente nuevo = {cad, largo,NIP, 2, T_C };


    return nuevo;

}

long long generarNumValido()
{
	long long num = 0;
	srand(time(NULL));
	num = (long long)rand();
    num = num*305185094758;
    num = llabs(num);

     if (num == 0)
     {
     	return generarNumValido();
     }
    return num%9999999999999999;

}

struct arbolDeBanco *buscarArbol_No_Cuenta (struct arbolDeBanco *raiz,long long No){
  if (raiz == NULL)
    {
      return NULL;
    }
  if (raiz->persona.No_Cuenta == No)
    {
      return raiz;
    }

  struct arbolDeBanco *buscado;

  if (raiz->persona.No_Cuenta > No)
    {
      buscado = buscarArbol_No_Cuenta (raiz->izq, No);
    }
  else
    {
      buscado = buscarArbol_No_Cuenta (raiz->der, No);
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

int preguntar()
{
  int entero;
  puts("¿Desea hacer otra accion? (SI pon [1] / NO pon [0])");
  scanf("%d", &entero);
  return entero;
}

