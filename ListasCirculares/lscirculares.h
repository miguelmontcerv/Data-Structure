#ifndef _LSCIRCULARES_H_
#define _LSCIRCULARES_H_

#include<stdio.h>
#include <stdlib.h>
struct ListaCircular
{
  int dato;
  struct ListaCircular *siguiente;
};

struct ListaCircular *agregarElemento (struct ListaCircular *, int);
void mostrarLista (struct ListaCircular *);
void mostrarInversa (struct ListaCircular *);
struct ListaCircular *mezclarListas (struct ListaCircular *, struct ListaCircular *);
struct ListaCircular *eliminarCola (struct ListaCircular *);
struct ListaCircular *eliminarCabeza (struct ListaCircular *);
struct ListaCircular *eliminarLista (struct ListaCircular *);
int buscarElemento (struct ListaCircular *, int);
struct ListaCircular *buscarEliminar (struct ListaCircular *, int);

#endif