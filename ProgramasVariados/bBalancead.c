// Bien Balanceado
#include <stdio.h>
#include <stdlib.h>
struct Stack
{
  char data;
  struct Stack *next;
};

struct Stack *push (struct Stack *, char);
struct Stack *pop (struct Stack *);
int isEmpyt (struct Stack *);

int
main (void)
{
  struct Stack *stack = NULL;
  char cad[100];
  int flag;

  fgets (cad, 100, stdin);

  for (int i = 0; cad[i] != '\0'; i++)
    {
      if (cad[i] == '(')
	{
	  stack = push (stack, '(');
	}
      else if (cad[i] == ')')
	{
	  flag = isEmpyt (stack);
	  if (flag == 1)
	    {
	      printf ("Esta Mal Balanceado :(\n");
	      return 0;
	    }
	  else if (flag == 0)
	    {
	      stack = pop (stack);
	    }

	}
    }
  flag = isEmpyt (stack);
  if (flag == 1)
    {
      printf ("Esta Bien Balanceado :)\n");
    }
  else if (flag == 0)
    {
      printf ("Esta Mal Balanceado :(\n");
    }


  printf ("\n");
  return 0;
}

struct Stack *
push (struct Stack *stack, char car)
{
  struct Stack *new = NULL;
  new = (struct Stack *) malloc (sizeof (struct Stack));
  new->data = car;
  new->next = stack;
  return new;
}

struct Stack *
pop (struct Stack *stack)
{
  struct Stack *aux = stack;
  if (stack == NULL)
    {
      return stack;
    }
  stack = stack->next;
  free (aux);
  return stack;
}

int
isEmpyt (struct Stack *stack)
{
  if (stack == NULL)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}
