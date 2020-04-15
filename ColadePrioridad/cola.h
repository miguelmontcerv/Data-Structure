#ifndef __COLA_H__
#define __COLA_H__

#include<stdio.h>
#include <stdlib.h>
struct Nodo
{
  int dato;
  int prioridad;
  struct Nodo *sig;
};

struct ColaP
{
  struct Nodo *sal;
  struct Nodo *ent;
};

struct ColaP *nuevaP ();
int esnuevaP (struct ColaP *p);
struct ColaP *formarP (struct ColaP *p, int e);
int primeroP (struct ColaP *p);
struct ColaP *desformarP (struct ColaP *p);
struct ColaP *ImpColaP (struct ColaP *p);
void Impint (int e);
int esMoI (int e1, int e2);
int esMenor (int e1, int e2);
int esIgual (int e1, int e2);
int establecarPrioridad (int e);

#endif
