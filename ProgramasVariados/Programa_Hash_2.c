/* Esta es la prueba uno del hash bancario 
	Nombre del proyecto:
		Sistema de Tarjetas de Banco
	Integrantes:
		Monteros Cervantes Miguel Angel
		Garcia Osorio Hector Manuel
	Materia y Grupo:
		Estructura de datos; 1CV10
	Avance: 2
*/
int Funcion_Hash_Primo(char *, long, int, int, int); 

#include <stdio.h>
int main (void){
	//La base de datos es unicamente para 50 usuarios

	char *Nombres;
	int NIP, Sucursal, T_Cuenta; /* 16 digitos, 4 digitos, 1-15 sucursales, 1-4 tipos de cueta */
	long No_Cuenta;
	int numero;

	numero = Funcion_Hash_Primo("Miguel Angel Monteros Cervantes",7894545632124598,8932,7,4);
	printf("\n");
	numero = Funcion_Hash_Primo("Garcia Osorio Hector Manuel",6512459327894548,9382,3,1);
	printf("\n");
	

	numero = Funcion_Hash_Primo("zzzzzzzzz zzzzzzzzz zzzzzzzzzz zzzzzzzzzz zzzzzzzzzz",9999999999999999,9999,15,4);
	/*Universo 10000000000010017 */

return 0;
}

int Funcion_Hash_Primo(char *Nombres, long No_Cuenta, int NIP, int Sucursal, int T_Cuenta){
	long long numero = 0;
	int const p = 9973, a = 509, b =7372, m = 100;

	if(Nombres == NULL /*|| No_Cuenta == NULL || NIP == NULL || Sucursal == NULL || T_Cuenta == NULL */)
	{
		return 0;
	}

	for (int i = 0; *(Nombres + i) != '\0'; ++i) //Sumas cada valor del nombre
	{
		printf("%c",*(Nombres + i));
		numero = numero + *(Nombres);
	}

	numero = No_Cuenta + NIP + Sucursal + T_Cuenta; //Sumas todos los datos numericos
	numero = numero % 9000; //Dado que el universo es muy grande (más de 16 digitos), lo delimitamos unicamente a que el numero más grande sea 9000 (nueve mill

	numero = (((a*numero)+b) % p) % m; // Aplicamos el Hash primo

	printf("\n%lld\n",numero );

	return (int)numero;
}
