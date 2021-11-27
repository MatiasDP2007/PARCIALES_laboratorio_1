#include "ArrayEnvios.h"
#include "ArrayClientes.h"
#include "ArrayPedidos.h"
#include "ArrayLocalidad.h"
void InicializarListaEnvios(eEnvios listaEnviados[], int tamEnviados)
{
	for(int i = 0; i< tamEnviados; i++)
	{
		listaEnviados[i].estado = INACTIVO;
	}
}
int VerificarListaDeEnvios(eEnvios listaEnviados[], int tamEnviados)
{
	int flagRetorno = -1;
	for (int i = 0; i < tamEnviados; i++)
	{
		if(listaEnviados[i].estado == PENDIENTE || listaEnviados[i].estado == FINALIZADO)
		{
			flagRetorno = 0;
		}
	}
	return flagRetorno;
}

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
		if(listaEnviados[i].estado == FINALIZADO || listaEnviados[i].estado == PENDIENTE)
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
}

int BuscarEnviosPorSuId(eEnvios listaEnviados[], int tamEnviados, ePedido listaPedidos[],int tamPedidos, eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades)
{
	int idIngresado;
	system("cls");
	MostrarListaEnviados(listaEnviados,tamEnviados,listaPedidos,tamPedidos,listaClientes,tamClientes,listaLocalidades,tamLocalidades);
	idIngresado = IngresarNumeroEnteroDeMaximoAMinimo("Ingrese el ID de seguimiento del ENVIO: ", 9999999, 0);
	return idIngresado;
}

int CambiarElEstadoDelEnvio(eEnvios listaEnviados[],int tamEnviados, int idIngresado)
{
	int flagRetorno = -1;
	int opcion;
	for(int i= 0; i< tamEnviados; i++)
	{
		if(idIngresado == listaEnviados[i].id)
		{
			opcion = IngresarNumeroEnteroDeMaximoAMinimo("1-PENDIENTE\n2-FINALIZADO\n3-INACTIVO\nIngrese Una opcion: ", 3, 1);
			switch(opcion)
			{
				case 1:
					listaEnviados[i].estado = PENDIENTE;
					strcpy(listaEnviados[i].descripcion, "PENDIENTE");
					break;
				case 2:
					listaEnviados[i].estado = FINALIZADO;
					strcpy(listaEnviados[i].descripcion, "FINALIZADO");
					break;
				case 3:
					listaEnviados[i].estado = INACTIVO;
					strcpy(listaEnviados[i].descripcion, "INACTIVO");
					break;
			}
			flagRetorno = 0;
			break;
		}
	}
return flagRetorno;
}

int FiltarEnviosGratuitos(eEnvios listaEnviados[],int tamEnviados, ePedido listaPedidos[],int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidades, eCliente listaClientes[], int tamClientes )
{
	int flagRetorno = -1;
	printf("El pedidos sin costo de envio son: ");
	printf("ID EMPRESA             EMPRESA           ID PEDIDO              DOMICILIO           LOCALIDAD    ID ENVIO\n");

	for(int i =0; i< tamEnviados ; i++)
	{
		if(listaEnviados[i].estado == PENDIENTE)
		{
			for(int j= 0 ; j<tamPedidos; j++)
			{
				if(listaPedidos[j].estado == COMPLETADO && (listaPedidos[j].kilosHDPE > 1000 || listaPedidos[j].kilosLDPE > 1000 || listaPedidos[j].kilosPP > 1000))
				{
					for(int k = 0 ; k < tamLocalidades ; k ++)
					{
						if(listaLocalidades[k].id == listaEnviados[i].localidad)
						{

							for(int l = 0; l< tamClientes ; l ++)
							{
								 printf("%10d,%20s,%20d,%23s,%5d,%20s,%12d\n",listaClientes[l].id,listaClientes[l].nombre,listaPedidos[j].idPedido,listaEnviados[i].direccion,listaEnviados[i].numeracion
									 ,listaLocalidades[i].descripcion, listaEnviados[i].id);
								 flagRetorno = 0;
							}

						}
					}

				}
			}
		}
	}
return flagRetorno;
}
