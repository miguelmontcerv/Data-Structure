#include"cola.h"
 int 
main () 
{
  puts ("Cola Original:");
  struct ColaP *p = formarP (formarP (formarP (nuevaP (), 3), 2), 1);
  p = ImpColaP (p);
  puts ("\nAgregando 4 a la Cola:");
  p = formarP (p, 4);
  p = ImpColaP (p);
  puts ("\nAgregando 2 a la Cola:");
  p = formarP (p, 2);
  p = ImpColaP (p);
  puts ("\nAgregando 0 a la Cola:");
  p = formarP (p, 0);
  p = ImpColaP (p);
  return 0;
}


