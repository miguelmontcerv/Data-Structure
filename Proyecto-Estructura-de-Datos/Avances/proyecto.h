#ifndef __PROYECTO_H__
#define __PROYECTO_H__
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct cuentaHabiente
{
  char Nombre[100];
  long long No_Cuenta;
  int NIP;
  int Sucursal;
  int T_Cuenta;
};


struct arbolDeBanco
{
  struct cuentaHabiente persona;
  struct arbolDeBanco *izq;
  struct arbolDeBanco *der;
};

struct arbolDeBanco *insertarArbol (struct arbolDeBanco *,struct cuentaHabiente);
void mostrarArbol (struct arbolDeBanco *);
struct arbolDeBanco *buscarArbol (struct arbolDeBanco *,struct cuentaHabiente persona);
int esHoja (struct arbolDeBanco *);
struct arbolDeBanco *padreDe (struct arbolDeBanco *,struct cuentaHabiente);
void consultarArbol (struct arbolDeBanco *,struct cuentaHabiente);
struct arbolDeBanco *mayorDe (struct arbolDeBanco *);
struct arbolDeBanco *menorDe (struct arbolDeBanco *);
struct arbolDeBanco *eliminarRaizDeArbol (struct arbolDeBanco *);
struct arbolDeBanco *eliminarDeArbol (struct arbolDeBanco *, struct cuentaHabiente);
int menu ();
struct cuentaHabiente crearCH();
long long generarNumValido();
struct arbolDeBanco *buscarArbol_No_Cuenta (struct arbolDeBanco *,long long No);
int preguntar ();

#endif
