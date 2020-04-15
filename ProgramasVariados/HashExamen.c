//Esta es una pruba de las tablas hash
#include<stdio.h>
#include<stdlib.h>
struct TablaHash
{
	int *datos;
};

int FuncionHash(int);
void AgregarElemento(struct TablaHash**,int,int); //Estructura, dato, posicion
void EliminarElemento(struct TablaHash**,int,int);
void BuscarElemento(struct TablaHash*,int,int);

int main(void){
	struct TablaHash *tabla = NULL;
	int posicion = 0;

	posicion = FuncionHash(102);
	AgregarElemento(&tabla,102,posicion);

	posicion = FuncionHash(6541);
	AgregarElemento(&tabla,6541,posicion);

	posicion = FuncionHash(566);
	AgregarElemento(&tabla,566,posicion);
	
	posicion = FuncionHash(557);
	AgregarElemento(&tabla,557,posicion);

	/////
	
	posicion = FuncionHash(102);
	BuscarElemento(tabla,102,posicion);

	posicion = FuncionHash(6541);
	BuscarElemento(tabla,6541,posicion);

	posicion = FuncionHash(566);
	BuscarElemento(tabla,566,posicion);

	posicion = FuncionHash(557);
	BuscarElemento(tabla,557,posicion);

	BuscarElemento(tabla,13,13);

	///
	posicion = FuncionHash(557);
	EliminarElemento(&tabla,557,posicion);

	posicion = FuncionHash(557);
	BuscarElemento(tabla,566,posicion);

return 0;
}

int FuncionHash(int dato){
	int const p = 157, a = 101, b =103, m = 100; //mod Primo, por, mas, modulo;  Son 100 datos max
	dato = ( ( (dato * a) + b ) % p ) % m;
	//printf(" hash: %d\n",dato);
	return dato;
}

void AgregarElemento(struct TablaHash** tabla,int dato,int posicion){ //Estructura, dato, posicion
	if(tabla == NULL)
		return;
	if(*tabla == NULL){
		*tabla = (struct TablaHash*) malloc(sizeof(struct TablaHash));
		(*tabla)->datos = (int*) malloc(sizeof(int)*200); //Son 100 datos
	}

	if(*((*tabla)->datos + posicion) != 0){
		if(posicion == 200){
			AgregarElemento(tabla,dato,1);
		}
		AgregarElemento(tabla,dato, posicion + 1);
	}
	*((*tabla)->datos + posicion) = dato; 
	return;
}

void BuscarElemento(struct TablaHash* tabla, int dato, int posicion){
	 int i = 0;
  if(tabla == NULL)
  {
    return;
  }
 if(*(tabla -> datos + posicion) != 0)
 	if(*(tabla -> datos + posicion) == dato)
 		printf("%d\n",*(tabla -> datos + posicion));
 	else{
 		if(posicion == 200)
 			BuscarElemento(tabla,dato,1);
 		else BuscarElemento(tabla,dato,posicion + 1);
 	}
 else
 	printf("No fue encontrado\n");
 return;
}

void EliminarElemento(struct TablaHash** tabla,int dato,int posicion){
	if(tabla == NULL)
		return;
	if(*tabla == NULL)
		return;

if(*((*tabla) -> datos + posicion) != 0)
	if(*((*tabla)->datos + posicion) == dato)
		*((*tabla)->datos + posicion) = 0;
	else{
 		if(posicion == 200)
 			EliminarElemento(tabla,dato,1);
 		else EliminarElemento(tabla,dato,posicion + 1);
 	}
else
 	printf("No fue encontrado\n");
return;
}