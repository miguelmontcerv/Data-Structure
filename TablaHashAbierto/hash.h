#ifndef _HASH_H_
#define _HASH_H_

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct TablaHash
{
	char **datos;
	int cuantos; //200
	struct ListaLigada *lista;
};

struct ListaLigada
{
	char *dato;
	struct ListaLigada *siguiente;	
};

int FuncionHash(char *);
void AgregarDato(struct TablaHash **, char *);
void EliminarDato(struct TablaHash **, char *);
void ImprimirTabla(struct TablaHash *);
int BuscarDato(struct TablaHash*, char *);

struct ListaLigada *agregarElemento (struct ListaLigada *, char *);
int buscarElemento (struct ListaLigada *, char *);

#endif
