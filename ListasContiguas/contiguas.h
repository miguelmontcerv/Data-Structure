#ifndef __CONTIGUAS_H__
#define __CONTIGUAS_H__

#include<stdio.h>
#include<stdlib.h>
struct Contiguas
{
	int *datos;
	int actual;
	int cuantos;
};

void AgregarElemento(struct Contiguas **,int);
void EliminarElemento(struct Contiguas **,int);
void Imprimir(struct Contiguas*);

#endif
