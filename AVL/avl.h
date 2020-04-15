#ifndef __AVL_H__
#define __AVL_H__

#include <stdio.h>
#include <stdlib.h>

struct AVL{

	int dato;
	int fe;
	struct AVL *hijoDerecho;
	struct AVL *hijoIzquierdo;
};

struct AVL *insertar(struct AVL*, int);
struct AVL *rotacionDerecha(struct AVL *);
struct AVL *rotacionIzquierda(struct AVL *);
int calcularAltura(struct AVL *);
int calcularFB(struct AVL *);
int buscar(struct AVL *, int);
void mostrar (struct AVL *);

#endif