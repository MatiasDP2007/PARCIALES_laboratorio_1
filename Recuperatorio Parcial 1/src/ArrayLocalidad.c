#include "ArrayLocalidad.h"
#include "ArrayPedidos.h"
#include "Biblioteca.h"
#include "ArrayClientes.h"
#include "ArrayEnvios.h"

void MostrarListaLocalidaes(eLocalidad listaLocalidades[], int tam)
{
	printf("Localidades\n\n");
	for(int i=0; i < tam; i ++)
	{
		printf("%d-%s\n",listaLocalidades[i].id, listaLocalidades[i].descripcion);
	}
}
