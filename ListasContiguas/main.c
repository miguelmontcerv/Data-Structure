#include"contiguas.h"
int main(void)
{
  struct Contiguas *lista = NULL;

  AgregarElemento(&lista,35);
  AgregarElemento(&lista,23);
  AgregarElemento(&lista,48);
  Imprimir(lista);
  printf("\n\n");
  AgregarElemento(&lista,35);
  AgregarElemento(&lista,23);
  AgregarElemento(&lista,48);
  Imprimir(lista);

  EliminarElemento(&lista,48);
  EliminarElemento(&lista,48);
  printf("\n\n");
  Imprimir(lista);

printf("\n");
return 0;
}