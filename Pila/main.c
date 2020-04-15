#include"pila.h"

int
main (void)
{
  struct Stack *stack = NULL;
  
  stack = Push(stack,1);
  stack = Push(stack,2);
  stack = Push(stack,3);
  stack = Push(stack,4);
  stack = Push(stack,5);

  stack = PrintStack(stack);  
  
  stack = Pop(stack);
  stack = Pop(stack);
  
  stack = PrintStack(stack);

  return 0;
}
