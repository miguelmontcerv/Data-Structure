#include "circular.h"
int
main ()
{
  struct CCircular *c = nuevaC ();
  int i;
  c = formarC (c, 1);
  c = formarC (c, 2);
  c = formarC (c, 3);
  c = formarC (c, 4);
  c = formarC (c, 5);
  c = formarC (c, 10);
  carrusel (c);
  return 0;
}


