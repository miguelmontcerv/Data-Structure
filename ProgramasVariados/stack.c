// Stack
#include<stdio.h>
#include <stdlib.h>
struct Stack
{
  int data;
  struct Stack *next;
};

struct Stack *Push (struct Stack *, int);
struct Stack *Pop (struct Stack *);

int
main (void)
{
  struct Stack *stack = NULL;
  int max, num;
  scanf ("%d", &max);
  for (int i = 0; i < max; ++i)
    {
      scanf ("%d", &num);
      stack = Push (stack, num);
    }
  printf ("\n\n");
  for (int i = 0; i < max; ++i)
    {
      stack = Pop (stack);
    }
  printf ("\n");
  return 0;
}

struct Stack *
Push (struct Stack *stack, int data)
{
  struct Stack *new = NULL;
  new = (struct Stack *) malloc (sizeof (struct Stack));
  new->data = data;
  new->next = stack;
  return new;
}

struct Stack *
Pop (struct Stack *stack)
{
  struct Stack *aux = stack;
  printf ("%d ", aux->data);
  stack = stack->next;
  free (aux);
  return stack;
}
