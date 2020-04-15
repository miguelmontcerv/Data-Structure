/* Este programa incluye una coleccion de funciones hash, es un intento de HASH UNIVERSAL
	quiero tener una revicion del codigo, asi que comentare parte de esté
 */

/* Errores:
	Cada que inicia el programa, ¿siempre hace el mismo numero random ??
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct TablaHash{
	char **datos; //Vamos a guardar palabras, por eso es doble apuntador
	int maximos; //La cantidad maxima de memiria
	int Tipo_de_Hash; //Guardamos el tipo de hash que hace
};

void AgregarElemento(struct TablaHash**, char*); //Toma como parametro la tabla donde se desea argar el elemento y el dato que se quiere guardar
void BuscarElemento(struct TablaHash*, char*);
void EliminarElemento(struct TablaHash**, char *);
int Nrandom(int); //te regresa un numero random entre 0 y el parametro agregado
//Hare 5 funciones hash diferentes
int HashUniversal(char *,int); //La palabra a hashear y el tipo de hash
int FunHash1(char*,int);
int FunHash2(char*,int); //Hashea la palabra y le hace modulo m (el maximo en la memoria)
int FunHash3(char*,int);
int FunHash4(char*,int);
int FunHash5(char*,int);

int main (void)
{
	struct TablaHash *tabla = NULL;

	AgregarElemento(&tabla,"Hola");
	AgregarElemento(&tabla,"Mundo");
	AgregarElemento(&tabla,"Estructuras");
	AgregarElemento(&tabla,"Instituto");
	AgregarElemento(&tabla,"Politecnico");
	AgregarElemento(&tabla,"Nacional");

	BuscarElemento(tabla,"Hola");
	BuscarElemento(tabla,"Estructuras");
	//BuscarElemento(tabla,"Politecnico");

	EliminarElemento(&tabla,"Estructuras");
	BuscarElemento(tabla,"Estructuras");
	//BuscarElemento(tabla,"hol");	

return 0;
}

int Nrandom(int maximo){ //entre 1 y maximo
	int numero;
	srand(time(NULL));
	numero = rand() % (maximo);
	return numero;
} 

int FunHash1(char *palabra, int memoria){
	int numero = 0;
	for(int i = 0; *(palabra + i) != '\0' ; i++)
	{
		numero =  numero + *(palabra);
	}
	return numero % memoria;
}

int FunHash2(char *palabra, int memoria){ //Un hash famoso visto en clase
	int numero = 0;
	float const a = 0.6133;

	for(int i = 0; *(palabra + i) != '\0' ; i++)
	{
		numero =  numero + *(palabra);
	}
	return (int)(numero * a ) % memoria;
}

int FunHash3(char *palabra, int memoria){ //Hash Primo
	int numero = 0;
	int const p = 211, a = 192, b = 125;

	for(int i = 0; *(palabra + i) != '\0' ; i++)
	{
		numero =  numero + *(palabra);
	}
	return (((numero * a) + b) % p ) % memoria;
}

int FunHash4(char *palabra, int memoria){ //El hash por 3 para dispersar más los datos
	int numero = 0;
	for(int i = 0; *(palabra + i) != '\0' ; i++)
	{
		numero =  numero + *(palabra);
	}
	return (numero * 3) % memoria;
}

int FunHash5(char *palabra, int memoria){ //Lo multiplicamos por si mismo para dispersar los datos
	int numero = 0;
	for(int i = 0; *(palabra + i) != '\0' ; i++)
	{
		numero =  numero + *(palabra);
	}
	return (numero * numero) % memoria;
}

void AgregarElemento(struct TablaHash **tabla, char *palabra)
{
	int Tipo_de_Hash, posicion, i = 0;
	if(tabla == NULL)
		return;
	if(*tabla == NULL)
	{
		*tabla = (struct TablaHash*) malloc(sizeof(struct TablaHash));
		(*tabla) -> datos = (char **) malloc(sizeof(char) * 200);
		(*tabla) -> maximos = 200;
	}
	Tipo_de_Hash = Nrandom(5);

	posicion = HashUniversal(palabra,Tipo_de_Hash);

	if( *((*tabla) -> datos + posicion) != 0)
	{
		if(posicion == 200)
			for(i = 0; *((*tabla) -> datos + i) != 0 ; i++);
		else
			for(i = 1; *((*tabla) -> datos + posicion + i) != 0 ; i++);
	}
	
	(*tabla) -> Tipo_de_Hash = Tipo_de_Hash;

	*((*tabla) -> datos + posicion + i) = palabra;

return;
}

int HashUniversal(char *palabra, int Tipo_de_Hash){
	if(Tipo_de_Hash == 0)
		return FunHash1(palabra,200);
	else if (Tipo_de_Hash == 1)
		return FunHash2(palabra,200);
	else if (Tipo_de_Hash == 2)
		return FunHash3(palabra,200);
	else if (Tipo_de_Hash == 3)
		return FunHash4(palabra,200);
	else if (Tipo_de_Hash == 4)
		return FunHash5(palabra,200);
		else{
			printf("Error hash no disponible\n");
			return 0;
		}
}

void BuscarElemento(struct TablaHash *tabla, char *palabra){
	int posicion, i = 0;
	if(tabla == NULL)
		return;

	printf("buscando...\n\t");
	posicion = HashUniversal(palabra,tabla -> Tipo_de_Hash);

	if(*(tabla -> datos + posicion) != 0)
	{
		if(strcmp(*(tabla -> datos + posicion),palabra) == 0) //Si se encontro esa palabra
			printf("%s\n",*(tabla -> datos + posicion) ); 
		else{
			if(posicion == 200)
				for(i = 0; *(tabla -> datos + i) != 0 ; i++)
					if( strcmp(*(tabla -> datos + i),palabra) == 0 )
						printf("%s\n",*(tabla -> datos + i));
			else
				for(i = 1; *(tabla -> datos + posicion + i) != 0 ; i++)
					if( strcmp(*(tabla -> datos + posicion + i),palabra) == 0 )
						printf("%s\n",*(tabla -> datos + posicion + i));
		}
	}	
	else
		printf("No se encontro\n");
}	

void EliminarElemento(struct TablaHash **tabla, char *palabra){
	int posicion, i = 0;
	if(tabla == NULL)
		return;
	if(*tabla == NULL)
		return

	posicion = HashUniversal(palabra,*((*tabla) -> Tipo_de_Hash)); //Warning, no se por que, ya que le paso un entero

	if(*((*tabla) -> datos + posicion) != 0)
	{
		if(strcmp(*((*tabla) -> datos + posicion),palabra) == 0) {//Si se encontro esa palabra
			printf("eliminando...Hecho\n\n");
			*((*tabla) -> datos + posicion) = 0; 
		}
		else{
			if(posicion == 200)
				for(i = 0; *((*tabla) -> datos + i) != 0 ; i++)
					if( strcmp(*((*tabla) -> datos + i),palabra) == 0 ){
						printf("eliminando... Hecho\n\n");
						*((*tabla) -> datos + i) = 0;
					}
			else
				for(i = 1; *((*tabla) -> datos + posicion + i) != 0 ; i++)
					if( strcmp(*((*tabla) -> datos + posicion + i),palabra) == 0 ){
						printf("eliminando...Hecho\n\n");
						*((*tabla) -> datos + posicion + i) = 0;
					}
		}
	}	
	else
		printf("No se encontro\n");
}	
