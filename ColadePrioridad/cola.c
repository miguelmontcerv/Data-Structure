#include"cola.h"
 struct ColaP *
nuevaP () 
{
   struct ColaP *p = (struct ColaP *) malloc (sizeof (struct ColaP));
   p->sal = NULL;
  p->ent = NULL;
   return p;
}

  int 
esnuevaP (struct ColaP *p) 
{
   return ((p->ent == NULL) && (p->sal == NULL));
}

  struct ColaP *
formarP (struct ColaP *p, int e) 
{
   struct Nodo *t = (struct Nodo *) malloc (sizeof (struct Nodo));
   t->dato = e;
   t->sig = NULL;
   t->prioridad = establecarPrioridad (e);
   if (esnuevaP (p))
    
    {
       p->sal = p->ent = t;
     }
  
  else
    
    {
       if (t->prioridad >= p->sal->prioridad)
	
	{			//Caso nuevo nodo MAYOR a nodo saliente
	  t->sig = p->sal;
	  p->sal = t;
	}
      
      else if (t->prioridad < p->ent->prioridad)
	
	{			//Caso nuevo nodo MENOR a nodo entrante
	  p->ent->sig = t;
	  p->ent = t;
	 }
      
      else
	
	{			//Caso nuevo nodo esta en medio de la cola
	  struct Nodo *aux = p->sal;
	   int i = 1;
	   while (i)
	    
	    {
	       if ((t->prioridad < aux->prioridad) 
		     &&(t->prioridad >= aux->sig->prioridad))
		
		{
		   t->sig = aux->sig;
		   aux->sig = t;
		   i = 0;
		 }
	      
	      else
		
		{
		   aux = aux->sig;
		 }
	     }
	 }
     }
   return p;
}

  int 
primeroP (struct ColaP *p) 
{
   return p->sal->dato;
}

  struct ColaP *
desformarP (struct ColaP *p) 
{
   struct Nodo *t = p->sal;
   if (p->sal == p->ent)
     p = nuevaP ();
   
  else
     p->sal = p->sal->sig;
  free (t);
   return p;
}

  struct ColaP *
ImpColaP (struct ColaP *p) 
{
   struct ColaP *c = nuevaP ();
   while (!esnuevaP (p))
    
    {
       c = formarP (c, primeroP (p));
       Impint (primeroP (p));
       p = desformarP (p);
    }
   free (p);
   return c;
}

  void 
Impint (int e) 
{
   printf ("%d\n", e);
}  int 

esMoI (int e1, int e2) 
{
   return e1 >= e2;
}

  int 
esMenor (int e1, int e2) 
{
   return e1 < e2;
}

  int 
esIgual (int e1, int e2) 
{
   return e1 == e2;
}

  int 
establecarPrioridad (int e) 
{
   return e;
}


