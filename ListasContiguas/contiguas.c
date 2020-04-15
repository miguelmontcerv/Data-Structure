#include "contiguas.h"

void AgregarElemento(struct Contiguas **lista, int dato){
  int *temporal = NULL;
  int i = 0;

  if(*lista == NULL){
    *lista = (struct Contiguas*) malloc(sizeof(struct Contiguas)); //Creamos el primer elemento
    (*lista)->datos = (int*) malloc(sizeof(int) * 8); //Creamos 8n espacios
    
    (*lista)->cuantos = 8;
    (*lista)->actual = 0;
    *((*lista)->datos) = dato;
    return;
  }

  //Si no esta vacia
  if((*lista)-> cuantos == (*lista)-> actual + 1){ //Si esta llena
    temporal = (int*) malloc(sizeof(int)* (*lista)->cuantos  *2);
    for(i = 0; i< (*lista)->cuantos; i++){
      *(temporal + i) = *((*lista)->datos + i);
    }
    free((*lista)->datos);
    (*lista)->datos = temporal;
    (*lista)->cuantos = (*lista)->cuantos * 2;
  }
  //Aunque no este llena
  (*lista)->actual = (*lista)->actual + 1;
  *((*lista)->datos + (*lista)-> actual) = dato;
}

void Imprimir(struct Contiguas*lista)
{

  int i = 0;
  if(lista == NULL)
  {
    return;
  }
  for(i = 0 ; i< lista->actual+1 ; i++)
  {
    printf("%d\n",*(lista->datos + i) );
  }
  //printf("%d\n",*(lista->datos + lista->actual) );
}
void EliminarElemento(struct Contiguas **lista, int dato)
{

  int *temporal;
  int i = 0;
  if(lista == NULL)
  {
    return;
  }
  for(i = 0 ; i< (*lista)->actual+1 ; i++)
  {
    if(*((*lista)->datos+i) == dato){
      (*lista)->actual--;
      break;
    }
  }

  for(/*Desde donde te quedaste*/; i < (*lista)->actual+1 ; i++ )
  {
    *((*lista)->datos +i) = *((*lista)->datos + i + 1);
  } //Recorre la lista

/* Aqui termina oficilamente el algoritmo, pero que tal y se desperdicia memoria :0? */

  if((*lista)->actual < (*lista)-> cuantos / 2)
  {
    temporal = (int*)malloc(sizeof(int)* (*lista)-> cuantos / 2);
    for(i = 0; i < (*lista)->actual+1; i++)
    {
      *(temporal + i) = *((*lista)-> datos + i);
    }
    free((*lista)->datos);
    (*lista)->datos = temporal;
    (*lista)->cuantos = (*lista)->cuantos / 2;
  }
}