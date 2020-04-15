/* Tablas Hash que guardan palabras */
#include<stdio.h>
#include<stdlib.h>

struct TablaHash{
	char *datos;
};

int FuncionHash(char*);
void AgregarElemento(struct TablaHash**,char*,int);
//void EliminarElemento(char*);

int main(void){
	struct TablaHash tabla;
	int numero = 0;
	numero = FuncionHash("Miguel");
	printf(" %d\n",numero);
	AgregarElemento(&tabla,"Miguel",numero);
	numero = FuncionHash("Angel");
	printf(" %d\n",numero);
	AgregarElemento(&tabla,"Angel",numero);

return 0;
}

int FuncionHash(char *palabra){
	int *numero = 0;
	for(int i = 0; *(palabra + i) != '\0' ; i++){
		printf("%c",*(palabra+i));
		numero =  numero + *(palabra);
	}
return (int)numero;
}

void AgregarElemento(struct TablaHash **tabla,char *palabra,int posicion){ // La tabla donde la agregaras y el dato
	int numero;
	if(tabla == NULL)
	return;
	if(*tabla == NULL){
		*tabla = (struct TablaHash*) malloc(sizeof(struct TablaHash));
		(*tabla)->datos = (char*) malloc(sizeof(char) * 50);
	}
	if(*((*tabla)->datos + (posicion-1)) != 0){ //SI esta ocupada la posicion
		if(posicion == 50){
			AgregarElemento(tabla,palabra,1);
			return;
		}
		AgregarElemento(tabla,palabra,posicion+1);
		return;
	}
	*((*tabla)->datos + (posicion-1)) = palabra;

}
