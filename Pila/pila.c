#include"pila.h"
struct Stack *
Push (struct Stack *stack, int data)
{
  struct Stack *new = NULL;
  new = (struct Stack *) malloc (sizeof (struct Stack));
  new->data = data;

  if(stack == NULL)
  {
    new -> next = NULL;
  }
  else
  {
    new -> next = stack; 
  }
  return new;
}

struct Stack *
Pop (struct Stack *stack)
{
  struct Stack *aux = stack;
  stack = stack->next;
  free (aux);
  return stack;
}

struct Stack *PrintStack(struct Stack *stack)
{
  struct Stack *new_stack = NULL;
  struct Stack *aux = stack;
  while(aux != NULL)
  {
    printf("%d\n",aux -> data);
    new_stack = Push(new_stack,aux -> data);
    aux = Pop(aux);
  }

  while(new_stack != NULL)
  {
    aux = Push(aux,new_stack -> data);
    new_stack = Pop(new_stack);
  }
  
  return aux;
}