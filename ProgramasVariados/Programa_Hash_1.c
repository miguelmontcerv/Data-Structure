/* Prorama no.1 de funciones hash
Objetivo: Obtener el numero de los caracteres ingresados */
#include <stdio.h>

int Hash_Uno(char *,int); //Cadena, numero de casillas en la tabla
int Hash_Primo(char *,int);

int main(void){
	int numero;

	numero = Hash_Uno("ESCOM",10);
	numero = Hash_Primo("ESCOM",10);
	printf("\n");

	numero = Hash_Uno("UPIITA",10);
	numero = Hash_Primo("UPIITA",10);
	printf("\n");

	numero = Hash_Uno("ESIME",10);
	numero = Hash_Primo("ESIME",10);
	printf("\n");

	numero = Hash_Uno("ESIQIE",10);
	numero = Hash_Primo("ESIQIE",10);
	printf("\n");

	numero = Hash_Uno("UPIICSA",10);
	numero = Hash_Primo("UPIICSA",10);
	printf("\n");

	numero = Hash_Uno("ESIA",10);
	numero = Hash_Primo("ESIA",10);
	printf("\n");

	numero = Hash_Uno("UPIBI",10);
	numero = Hash_Primo("UPIBI",10);
	printf("\n");

	numero = Hash_Uno("ESCA",10);
	numero = Hash_Primo("ESCA",10);
	printf("\n");

	numero = Hash_Uno("ESIT",10);
	numero = Hash_Primo("ESIT",10);
	printf("\n");

	numero = Hash_Uno("EST",10);
	numero = Hash_Primo("EST",10);
	printf("\n");


printf("\n");
return 0;
}

int Hash_Uno(char *dato, int m){
	printf("\n");
	int numero = 0;
	
	if(dato == NULL)
	{
		return 0;
	}

	for (int i = 0; *(dato + i) != '\0'; ++i)
	{
		printf("%c",*(dato + i));
		numero = numero + *(dato);
	}
	printf("\nNumero: %d",numero);
	numero = numero % m;
	printf("\nHash: %d",numero);

	return numero;
}

int Hash_Primo(char *dato, int m){
	// P= 157, a = 101, b = 103
	printf("\n");
	int numero = 0;
	int const p = 157, a = 101, b =103;
	
	if(dato == NULL)
	{
		return 0;
	}

	for (int i = 0; *(dato + i) != '\0'; ++i)
	{
		printf("%c",*(dato + i));
		numero = numero + *(dato);
	}
	printf("\nNumero: %d",numero);

	numero = (((a*numero)+b) % p) % m;
	printf("\nHash: %d",numero);

	return numero;
}
