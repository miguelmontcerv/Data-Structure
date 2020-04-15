#ifndef __CIRCULAR_H_
#define __CIRCULAR_H_

#include<stdio.h>
#include<stdlib.h>
  struct CCircular
{
  int dato;
   struct CCircular *sig;
 };
void ImpElem (int e);
int EsMoI (int e1, int e2);
int esIgual (int e1, int e2);
void carrusel (struct CCircular *c);
int esnuevaC (struct CCircular *c);
struct CCircular *formarC (struct CCircular *c, int e);
int primeroC (struct CCircular *c);
struct CCircular *desformarC (struct CCircular *c);
struct CCircular *rotaC (struct CCircular *c);
struct CCircular *nuevaC ();
 
#endif
