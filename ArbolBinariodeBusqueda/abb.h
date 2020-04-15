#ifndef _ABB_H_
#define _ABB_H_

#include <stdio.h>
#include <stdlib.h>

struct ArbolBB{
	int dato;
	struct ArbolBB *izq;
	struct ArbolBB *der;
};

struct ArbolBB *AgregarElemento(struct ArbolBB *, int dato);
struct ArbolBB *EliminarElemento(struct ArbolBB *, int dato);
void BuscarElemento(struct ArbolBB *,int dato);
void PreOrden(struct ArbolBB *);
void InOrden(struct ArbolBB *);
void PostOrden(struct ArbolBB *);
int EsHoja(struct ArbolBB *);
int Vacio(struct ArbolBB *);

#endif