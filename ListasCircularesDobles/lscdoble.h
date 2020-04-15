#ifndef _LSCDOBLE_H_
#define _LSCDOBLE_H_

#include<stdio.h>
#include <stdlib.h>
struct ListaCDoble
{
  int dato;
  struct ListaCDoble *siguiente;
  struct ListaCDoble *anterior;
};

struct ListaCDoble *agregarElemento (struct ListaCDoble *, int);
void mostrarLista (struct ListaCDoble *);
void mostrarInversa (struct ListaCDoble *);
struct ListaCDoble *mezclarListas (struct ListaCDoble *, struct ListaCDoble *);
struct ListaCDoble *eliminarCola (struct ListaCDoble *);
struct ListaCDoble *eliminarCabeza (struct ListaCDoble *);
struct ListaCDoble *eliminarLista (struct ListaCDoble *);
int buscarElemento (struct ListaCDoble *, int);
struct ListaCDoble *buscarEliminar (struct ListaCDoble *, int);

#endif