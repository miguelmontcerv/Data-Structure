#include"proyecto.h"
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
    { "Manuel Aguirre Nuñez", 1234667891234567, 1234, 7, 1 };
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

  puts("");
  printf("\t\tSISTEMA BANCARIO DE CEFIN SA DE CV\n");
  printf("\t\t\tCONTROL DE CLIENTES\n");    


  int i = 0;
  i = menu();
  struct cuentaHabiente aux;
  struct arbolDeBanco *auxi = NULL;
  long long No;
  int entero = 0;
  int band = 0;

  do{
  switch(i){
    case 1: aux = crearCH();
            unArbol = insertarArbol(unArbol, aux);
            printf("Su numero de cuenta es: %lld\n", aux.No_Cuenta);
            band = preguntar();
            puts("");
            if(band)
            {
              i = menu();
            }
            break;
    case 2:
            puts ("Consulta de usuario, introduzca No. de cuenta ");
            scanf("%lld", &No);
            auxi = buscarArbol_No_Cuenta(unArbol, No);
            consultarArbol (unArbol, auxi->persona);
            band = preguntar(); 
            puts("");
            if(band)
            {
              i = menu();
            }                     
            break;
    case 3: puts("Eliminacion de usuario, introduzca el No. de cuenta");
            scanf("%lld", &No);
            auxi = buscarArbol_No_Cuenta(unArbol, No);
            unArbol = eliminarDeArbol(unArbol, auxi->persona); 
            band = preguntar();            
            puts("");
            if(band)
            {
              i = menu();
            }
            break;
    case 4: mostrarArbol(unArbol);
            band = preguntar();    
            puts("");
            if(band)
            {
              i = menu();
            }
            break;
  }
  }while(band == 1);








  puts ("");

  return 0;
}
