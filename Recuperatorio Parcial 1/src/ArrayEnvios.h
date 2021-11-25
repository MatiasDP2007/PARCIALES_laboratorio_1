#ifndef ARRAYENVIOS_H_
#define ARRAYENVIOS_H_


#include "ArrayPedidos.h"
#include "ArrayClientes.h"
#include "ArrayLocalidad.h"

#define ENVIADO 1
#define PENDIENTE 0
#define INACTIVO 2




typedef struct
{
	int id;
	int estado;
	char descripcion[51];
	char direccion[51];
	int  numeracion;
	int localidad;
}eEnvios;

void MostrarUnSoloEnvio(eEnvios unEnvio, ePedido unPedido,eCliente cliente, eLocalidad listaLocalidades[], int tamLocalidades);

void MostrarListaEnviados(eEnvios listaEnviados[], int tamEnviados, ePedido listaPedidos[],int tamPedidos, eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamLocalidades);

#endif /* ARRAYENVIOS_H_ */
