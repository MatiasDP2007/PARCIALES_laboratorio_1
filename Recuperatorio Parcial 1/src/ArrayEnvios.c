#include "ArrayPedidos.h"
#include "ArrayClientes.h"
#include "ArrayLocalidad.h"

void MostrarUnSoloEnvio(eEnvios unEnvio, ePedido unPedido,eCliente cliente, eLocalidad listaLocalidades[], int tamLocalidades )
{
	 printf("LISTA DE ENVIOS\n");
	 printf("ID EMPRESA             EMPRESA           ID PEDIDO              DOMICILIO           LOCALIDAD    ID ENVIO          ESTADO\n");
	 for(int i = 0; i < tamLocalidades; i ++)
	 {
		 if(unEnvio.localidad == listaLocalidades[i].id)
		 {
		 printf("%10d,%20s,%20d,%23s,%5d,%20s,%12d,%16s",cliente.id,cliente.nombre,unPedido.idPedido,unEnvio.direccion,unEnvio.numeracion
				 ,listaLocalidades[i].descripcion, unEnvio.id, unEnvio.descripcion);
		 }
	 }

}
void MostrarListaEnviados(eEnvios listaEnviados[], int tamEnviados, ePedido listaPedidos[],int tamPedidos, eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades )
{
	for(int i = 0; i< tamEnviados; i++)
	{
		for(int j =0 ; j< tamClientes; j++)
		{
			for(int k=0; k< tamPedidos; k++)
			{
				MostrarUnSoloEnvio(listaEnviados[i], listaPedidos[k], listaClientes[j], listaLocalidades, tamLocalidades);
			}
		}
	}
}
