//Programa Tablas Hash
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct TablaHash
{
	char **datos;
};

int FuncionHash(char *);
void AgregarDato(struct TablaHash **, char *);
void EliminarDato(struct TablaHash **, char *);
void ImprimirTabla(struct TablaHash *); //Error
void BuscarDato(struct TablaHash*, char *);

int main(void)
{
	struct TablaHash *tabla = NULL;

	AgregarDato(&tabla,"Hola");
	AgregarDato(&tabla,"Mundo");
	AgregarDato(&tabla,"Progra");
	AgregarDato(&tabla,"argorP");

	//ImprimirTabla(tabla);

	BuscarDato(tabla,"argorP");

	EliminarDato(&tabla,"Progra");
	BuscarDato(tabla,"Progra");

return 0;
}

int FuncionHash(char *palabra) //Primo con un universo de 200
{
	int numero = 0,i;
	int const p = 9973, a = 509, b = 7372 , m = 200;//Constantes para Hasheo Primo

	for(i = 0 ; *(palabra + i ) != '\0' ; i++)
	{
		numero =  numero + *(palabra);
	}

	return ( ( (numero * a) + b ) % p ) % m ;
}

void AgregarDato(struct TablaHash **tabla, char *palabra)
{
	int posicion = 0, i = 0;
	if(tabla == NULL)
		return;

	if(*tabla == NULL)
	{
		*tabla = (struct TablaHash *) malloc(sizeof(struct TablaHash));
		(*tabla) -> datos = (char **) malloc (sizeof(char) * 200); //Creamos un espacio de 200
	}
	posicion = FuncionHash(palabra);

	if( *((*tabla) -> datos + posicion) != 0)
	{
		if(posicion == 200)
			for (i = 0; *((*tabla) -> datos + i) != 0 ; ++i);
		else
			for (i = 0; *((*tabla) -> datos + posicion + i) != 0 ; ++i);
	}
	
	*((*tabla) -> datos + posicion + i) = palabra;

return;
}

void ImprimirTabla(struct TablaHash *tabla) 
{
	/* No se puede imprimir toda la lista, aún verificando si el espacio al que se 
	apunta tiene algo o no, ya que la memoria tiene datos que no se pueden imprimir
	y nos marca el error Segmentation Fault */
	int i;
	if(tabla == NULL)
		return;
	for(i = 0; i <= 200 ; i++)
	{
		if(*(tabla -> datos + i) != 0){
			//printf("%s\n",*(tabla -> datos + i));
			printf("Dato\n");
		}
	}
}

void BuscarDato(struct TablaHash *tabla, char *palabra)
{
	int posicion,i = 0;
	if(tabla == NULL)
		return;
	
	posicion = FuncionHash(palabra);

	if( *(tabla -> datos + posicion) != 0 ) //Si la palabra tiene un dato
	{
		if( strcmp(*(tabla -> datos + posicion),palabra) == 0 ) //Si la palabra encontradad es igual a la buscada
		{
			printf("%s\n",*(tabla -> datos + posicion));
		}
		else
		{
			if(posicion == 200){
				for(i = 0; strcmp( *(tabla -> datos + i),palabra) != 0 ; i++); //Aumentar el contador mientras la palabra encontrada sea distinta de la buscada
				printf("%s\n",*(tabla -> datos + i));
				return;
			}
			
			for(i = 0; strcmp( *(tabla -> datos + posicion + i),palabra) != 0 ; i++); //Aumentar el contador mientras la palabra encontrada sea distinta de la buscada
			printf("%s\n",*(tabla -> datos +posicion + i));
		}
	}
	else
		printf("La palabra no se encontro\n");
}

void EliminarDato(struct TablaHash **tabla, char *palabra)
{
	printf("eliminando...\n\t");
	int posicion,i = 0;
	if(tabla == NULL)
		return;
	
	posicion = FuncionHash(palabra);
	if( *((*tabla) -> datos + posicion) != 0 ) //Se encotro un dato en la memoria
	{
		if( strcmp(*((*tabla) -> datos + posicion),palabra) == 0)
		{
			*((*tabla)->datos + posicion) = 0;
			printf("HECHO\n");
			return;
		}
		else
		{
			if(posicion == 200)
			{
				for(i = 0; strcmp(*((*tabla) -> datos + i), palabra) != 0 ; i++); //Ya se encontro el dato
				*((*tabla)->datos + i) = 0;
				printf("HECHO\n");
			}
			else
			{
				for(i = 0; strcmp(*((*tabla) -> datos + posicion + i), palabra) != 0 ; i++);
				*((*tabla)->datos + posicion + i) = 0;
				printf("HECHO\n");
			}
		}
	}
	else
		printf("La palabra no se encontro\n");
}
