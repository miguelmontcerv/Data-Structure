#ifndef _PILA_H_
#define _PILA_H_

#include<stdio.h>
#include <stdlib.h>
struct Stack
{
  int data;
  struct Stack *next;
};

struct Stack *Push (struct Stack *, int);
struct Stack *Pop (struct Stack *);
struct Stack *PrintStack(struct Stack *);

#endif