#include"hash.h"

int
main(void)
{
	int busqueda;
	struct TablaHash *tabla = NULL;

	AgregarDato(&tabla,"Hola");
	AgregarDato(&tabla,"Mundo");
	AgregarDato(&tabla,"Progra");
	AgregarDato(&tabla,"argorP");

	busqueda = BuscarDato(tabla,"argorP");
	printf("Si es 1 se encontro, si es 0 no se pudo encontrar: %d\n",busqueda);

	EliminarDato(&tabla,"argorP");
	
	busqueda = BuscarDato(tabla,"argorP");
	printf("Si es 1 se encontro, si es 0 no se pudo encontrar: %d\n",busqueda);

return 0;
}
