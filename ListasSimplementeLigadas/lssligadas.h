#ifndef __LSSLIGADAS_H__
#define __LSSLIGADAS_H__

#include<stdio.h>
#include <stdlib.h>

struct ListaSLigada
{

  int dato;

  struct ListaSLigada *siguiente;

  struct ListaSLigada *anterior;

};

struct ListaSLigada *agregarElemento (struct ListaSLigada *, int);
struct ListaSLigada *mezclarListas (struct ListaSLigada *,
				    struct ListaSLigada *);
void mostrarLista (struct ListaSLigada *);
void mostrarInversa (struct ListaSLigada *);
struct ListaSLigada *eliminarCola (struct ListaSLigada *);
struct ListaSLigada *eliminarCabeza (struct ListaSLigada *);
struct ListaSLigada *eliminarLista (struct ListaSLigada *);
int buscarElemento (struct ListaSLigada *, int);
struct ListaSLigada *buscarEliminar (struct ListaSLigada *, int);

#endif
