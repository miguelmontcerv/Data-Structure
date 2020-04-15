/* Especificaciones del programa:
	El maximo de datos posibles en la tabla es de 100, por lo tanto tiene 200 localidades de memoria
*/
#include<stdio.h>
#include<stdlib.h>

struct TablaHash
{	
	char **datos;
};

int FuncionHash(char*);
void AgregarElemento(struct TablaHash **,char*);
void BuscarElemento(struct TablaHash *,char*);
void EliminarElemento(struct TablaHash **,char*);


int main(void)
{
	struct TablaHash *tabla = NULL;

	AgregarElemento(&tabla,"Hola");
	AgregarElemento(&tabla,"Mundo");
	
	BuscarElemento(tabla,"Mundo");

	return 0;
}

int FuncionHash(char *palabra)
{
	int numero = 0;
	int const p = 211, a = 192, b = 125;

	for(int i = 0; *(palabra + i) != '\0'; i++){
		numero = numero + *(palabra);
	}

	numero = ( ( (numero * a) + b ) % p ) % 200;

	return numero;
}

void AgregarElemento(struct TablaHash **tabla, char*palabra)
{
	int posicion = 0, i = 0;

	if(tabla == NULL)
		return;
	if(*tabla == NULL)
	{
		*tabla = (struct TablaHash*) malloc(sizeof(struct TablaHash));
		(*tabla)->datos = (char**) malloc (sizeof(char) * 200);
	}

	posicion = FuncionHash(palabra);
	if(*((*tabla)->datos + posicion) != 0)
	{
		if(posicion == 200)
		{
		for(i = 0; *((*tabla)->datos + i) != 0 ; i++);
		}
		else
		{
		for(i = 1; *((*tabla)->datos + posicion + i) != 0 ; i++); //Saldra del bucle apuntando a una posicion libre
		}
	}

	*((*tabla)->datos + posicion + i) = palabra;

return;
}

void BuscarElemento(struct TablaHash *tabla,char *palabra)
{
	int posicion;

	if(tabla == NULL)
		return;

	posicion = FuncionHash(palabra);

	if(*(tabla->datos + posicion) != 0){
		//Comparador cadenas para ver si es esa
		printf("%s\n",*(tabla->datos + posicion));
	}
	else
		printf("No se encontro\n");
}