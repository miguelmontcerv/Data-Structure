#include"arbol.h"
int
main ()
{
  struct arbolDeBanco *unArbol = NULL;
  puts ("");
  printf("\e[2J\e[H");
  printf ("\t\t.: S I S T E M A   B A N C A R I O   B B V A :.\n");
  printf ("\t\t\tCONTROL DE CLIENTES\n\t\t\tSucursal 2\n");


  int i = 0;
  i = menu ();
  struct cuentaHabiente aux;
  struct arbolDeBanco *auxi = NULL;
  long long No;
  int entero = 0;
  int band = 0;

  do
   {
      switch (i)
  {
  case 0:
    exit(1);
    break;

  case 1:
    printf("\e[2J\e[H");
    aux = crearCH ();
    unArbol = insertarArbol (unArbol, aux);
    printf ("Su numero de cuenta es: %lld\n", aux.No_Cuenta);
    band = preguntar ();
    puts ("");
    if (band)
      {
        printf("\e[2J\e[H");
        i = menu ();
      }
    break;
  case 2:
    printf("\e[2J\e[H");
    puts ("Consulta de usuario, introduzca No. de cuenta ");
    scanf ("%lld", &No);
    auxi = buscarArbol_No_Cuenta (unArbol, No);
    if(auxi != NULL)
    {
      consultarArbol (unArbol, auxi->persona);
    }else{
      printf("NO se encontro\n");
    }
    band = preguntar ();
    puts ("");
    if (band)
      {
        printf("\e[2J\e[H");
        i = menu ();
      }
    break;
  case 3:
    printf("\e[2J\e[H");
    puts ("Eliminacion de usuario, introduzca el No. de cuenta");
    scanf ("%lld", &No);
    auxi = buscarArbol_No_Cuenta (unArbol, No);
    if(auxi != NULL)
    {
      unArbol = eliminarDeArbol (unArbol, auxi->persona);
    } else{
      printf("NO se encontro\n");
    }
    band = preguntar ();
    puts ("");
    if (band)
      {
        printf("\e[2J\e[H");
        i = menu ();
      }
    break;
  case 4:
    printf("\e[2J\e[H");
    mostrarArbol (unArbol);
    band = preguntar ();
    puts ("");
    if (band)
      {
        printf("\e[2J\e[H");
        i = menu ();
      }
    break;
  }
    }
  while (band == 1);

  puts ("");

  return 0;
}