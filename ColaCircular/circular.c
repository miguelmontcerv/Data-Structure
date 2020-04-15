#include"circular.h"

 struct CCircular *
nuevaC ()
{
  
return NULL;
}

 
void
ImpElem (int e)
{
  
printf ("%d\n", e);
} 
 
int

EsMoI (int e1, int e2)
{
  
return e1 <= e2;
}

 
int
esIgual (int e1, int e2)
{
  
return e1 == e2;
}

 
 
void
carrusel (struct CCircular *c)
{
  
while (!esnuevaC (c))
    {
      
ImpElem (primeroC (c));
      
c = desformarC (c);
      
	//getchar();
    }
}

 
int
esnuevaC (struct CCircular *c)
{
  
return c == nuevaC ();
}

 
struct CCircular *
formarC (struct CCircular *c, int e)
{
  
struct CCircular *t =
    (struct CCircular *) malloc (sizeof (struct CCircular));
  
t->dato = e;
  
if (esnuevaC (c))
    {
      
c = t;
      
c->sig = c;
    
}
  else
    {
      
t->sig = c->sig;
      
c->sig = t;
    
}
  
return t;
}

 
int
primeroC (struct CCircular *c)
{
  
return c->sig->dato;
}

 
struct CCircular *
desformarC (struct CCircular *c)
{
  
struct CCircular *t;
  
t = c->sig;
  
if (c == c->sig)
    {
      
free (t);
      
return nuevaC ();
    
}
  else
    {
      
c->sig = c->sig->sig;
      
free (t);
      
return c;
    
}
}

 
//Especial de struct CCircular*
struct CCircular *
rotaC (struct CCircular *c)
{
  
return c->sig;
}
