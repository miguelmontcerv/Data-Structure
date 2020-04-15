/* Esta es la prueba 4 del hash bancario 
	Nombre del proyecto:
		Sistema de Tarjetas de Banco
	Integrantes:
		Monteros Cervantes Miguel Angel
		Garcia Osorio Hector Manuel
	Materia y Grupo:
		Estructura de datos; 1CV10
	Avance: 4 Implementacion 2

	numero = Funcion_Hash_Primo("",,,,);
	printf("\n");

*/ 
#include <stdio.h>
#include <stdlib.h>
struct Contiguas
{
	int *datos;
	int actual;
	int cuantos;
};

int Funcion_Hash_Primo(char *, long, int, int, int);
void AgregarElemento(struct Contiguas**,int,int);
void Imprimir(struct Contiguas*);

int main(void)
{
	struct Contiguas *lista = NULL;
	//La base de datos es unicamente para 50 usuarios

	char *Nombres;
	int NIP, Sucursal, T_Cuenta; /* 16 digitos, 4 digitos, 1-15 sucursales, 1-4 tipos de cueta */
	long No_Cuenta;
	int numero;

	numero = Funcion_Hash_Primo("Miguel Angel Monteros Cervantes",7894545632124598,8932,7,4);
	AgregarElemento(&lista,numero,8932);
	printf("\n");
	numero = Funcion_Hash_Primo("Garcia Osorio Hector Manuel",6512459327894548,9382,3,1);
	AgregarElemento(&lista,numero,1657);
	printf("\n");

  	//Implementacion
	
	numero = Funcion_Hash_Primo("Agudelo Echeverry Rubiel Alberto",9442360649637971 ,5697,3,1);
	AgregarElemento(&lista,numero,1);
	printf("\n");
	numero = Funcion_Hash_Primo("Alvarez Puerta Jhon Alexander",2284384382643845,9124,15,3);
	AgregarElemento(&lista,numero,103);
	printf("\n");
	numero = Funcion_Hash_Primo("Betancur Pineda Mauro Albeiro",8872965180129165,7310,8,2);
	AgregarElemento(&lista,numero,354);
	printf("\n");
	numero = Funcion_Hash_Primo("Cardona Loaiza Daniel",8481259161322969,7446,4,2);
	AgregarElemento(&lista,numero,82);
	printf("\n");
	numero = Funcion_Hash_Primo("Castaño Piedrahita Jeisson Alejandro",4295993144759894,4925,11,1);
	AgregarElemento(&lista,numero,56562);
	printf("\n");
	numero = Funcion_Hash_Primo("Grisales Ortiz Lina Marcela",3367426665382934,3982,9,4);
	AgregarElemento(&lista,numero,13);
	printf("\n");
	numero = Funcion_Hash_Primo("García Moreno María Maryory",5469695795758363,3200,1,3);
	AgregarElemento(&lista,numero,52);
	printf("\n");
	numero = Funcion_Hash_Primo("Henao Zapata Martha Elena",3130508141453867,1651,12,1);
	AgregarElemento(&lista,numero,56964);
	printf("\n");
	numero = Funcion_Hash_Primo("Hernandez Villa Marisol",2772305759959506,2849,2,3);
	AgregarElemento(&lista,numero,3564);
	printf("\n");
	numero = Funcion_Hash_Primo("Mendoza Montoya Monica Patricia",6895226933185803,1251,4,1);
	AgregarElemento(&lista,numero,772);
	printf("\n");
	numero = Funcion_Hash_Primo("Munera Parra Jhon William", 6408911217146510,5918,14,2);
	AgregarElemento(&lista,numero,12575);
	printf("\n");
	numero = Funcion_Hash_Primo("Pareja Arango Fernando de Jesus",4371217461518075,1079,10,1);
	AgregarElemento(&lista,numero,101);
	printf("\n");
	numero = Funcion_Hash_Primo("Restrepo Prisco Hernan Dario",8958652485097497,9536,4,2);
	AgregarElemento(&lista,numero,102);
	printf("\n");

	Imprimir(lista);

return 0;
}

int Funcion_Hash_Primo(char *Nombres, long No_Cuenta, int NIP, int Sucursal, int T_Cuenta){
	long long numero = 0;
	int const p = 9973, a = 509, b =7372, m = 100; //100 Cajas disponibles

	if(Nombres == NULL /*|| No_Cuenta == NULL || NIP == NULL || Sucursal == NULL || T_Cuenta == NULL */)
	{
		return 0;
	}
	printf("Nombre: ");
	for (int i = 0; *(Nombres + i) != '\0'; ++i) //Sumas cada valor del nombre
	{
		printf("%c",*(Nombres + i));
		numero = numero + *(Nombres);
	}

	numero = No_Cuenta + NIP + Sucursal + T_Cuenta; //Sumas todos los datos numericos
	numero = numero % 9000; //Dado que el universo es muy grande (más de 16 digitos), lo delimitamos unicamente a que el numero más grande sea 9000 (nueve mill

	numero = (((a*numero)+b) % p) % m; // Aplicamos el Hash primo

	printf("\tCaja: %lld",numero );

	return (int)numero;
}
void AgregarElemento(struct Contiguas **lista,int posicion,int dato)
{
	if(lista == NULL){
		return;
	}

	if(*lista == NULL){
		*lista = (struct Contiguas*) malloc(sizeof(struct Contiguas));
		(*lista)-> datos = (int*) malloc(sizeof(int)*99); //Creamos las 20 unidades de memoria
		//*((*lista)->datos) = dato;
		(*lista)->cuantos = 99;
	}
	if(*((*lista)->datos + (posicion-1)) != 0)
	{
		if(posicion == 100){
			AgregarElemento(lista,1,dato);
		}

		AgregarElemento(lista,posicion+1,dato);
		//*((*lista)->datos + (posicion)) = dato; //+1
		return;
	}

	*((*lista)->datos + (posicion-1)) = dato;
}

void Imprimir(struct Contiguas*lista)
{

  int i = 0;
  if(lista == NULL)
  {
    return;
  }
  for(i = 0 ; i<= lista->cuantos ; i++)
  {
    printf("%d: %d\n",i+1,*(lista->datos + i) );
  }
  //printf("%d\n",*(lista->datos + lista->actual) );
}
