#ifndef ARRAYENVIOS_H_
#define ARRAYENVIOS_H_


#include "ArrayPedidos.h"
#include "ArrayClientes.h"
#include "ArrayLocalidad.h"


#define PENDIENTE 0
#define FINALIZADO 1
#define INACTIVO 2
#define COMPLETADO 1




typedef struct
{
	int id;
	int estado;
	char descripcion[51];
	char direccion[51];
	int  numeracion;
	int localidad;
} eEnvios;

void InicializarListaEnvios(eEnvios listaEnviados[], int tamEnviados);

int VerificarListaDeEnvios(eEnvios listaEnviados[], int tamEnviados);

void MostrarUnSoloEnvio(eEnvios unEnvio, ePedido unPedido, eCliente cliente, eLocalidad listaLocalidades[], int tamLocalidades);

void MostrarListaEnviados(eEnvios listaEnviados[], int tamEnviados, ePedido listaPedidos[],int tamPedidos, eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades);

int BuscarEnviosPorSuId(eEnvios listaEnviados[], int tamEnviados, ePedido listaPedidos[],int tamPedidos, eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades);

int CambiarElEstadoDelEnvio(eEnvios listaEnviados[],int tamEnviados, int idIngresado);

int FiltarEnviosGratuitos(eEnvios listaEnviados[],int tamEnviados, ePedido listaPedidos[],int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidades, eCliente listaClientes[], int tamClientes);
#endif /* ARRAYENVIOS_H_ */
