#ifndef ARRAYPEDIDOS_H_
#define ARRAYPEDIDOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#include "ArrayClientes.h"
#include "ArrayLocalidad.h"
#include "ArrayEnvios.h"

#define CARGADO 1
#define VACIO 0
#define PENDIENTE 0
#define COMPLETADO 1


typedef struct
{
    int idPedido;
    int idCliente;
    float kilosTotales;
    float kilosHDPE;
    float kilosLDPE;
    float kilosPP;
    float basura;
    int estadoPedido;
    char descripcion[51];
    int estado;
} ePedido;

void InicializarListaDePedidos (ePedido listaPedidos[], int tam); // inicializa la lista de pedidos en VACIO = 0
int VerificarElEstadoDeLaListaDePedidos(ePedido listaPedidos[], int tam); // verifica que el estado de la lista de pedidos este en VACIO = 0, sirve para pasar un estado de bandera
int VerificarElEstadoDeLaListaDePedidosPendientes(ePedido listaPedidos[], int tam); //verifica que el estado de la lista de pedidos este en VACIO = 0 y en estado PENDIENTE , sirve para pasar un estado de bandera
int VerificarElEstadoDeLaListaDePedidosCompletados(ePedido listaPedidos[], int tam);//verifica que el estado de la lista de pedidos este en VACIO = 0 Y en estado COMPLETADO, sirve para pasar un estado de bandera
int CrearPedidoRecoleccion(eCliente listaClientes[], int tam, int idCliente, ePedido listaPedidos[], int tamPedidos, int* idPedido, int idPedidoAux,int* idEnvio, int idEnvioAux, eEnvios listaEnviados[], int tamEnviados, eLocalidad listaLocalidades[], int tamLocalidades);//Le permite al usuario generar un pedido de recoleccion y poner el estado en PENDIENTE
int ProcesarResiduos(eCliente listaClientes[],int tam, ePedido listaPedidos[], int tamPedidos,int idPedidosAux, eLocalidad listaLocalidades[], int tamLocalidades);//permite que el usuario fraccione los tipos de plastico ingresados y pase el pedido a estado COMPLETADO
int MostrarListaPendientes(eCliente listaClientes[],int tam, ePedido listaPedidos[], int tamPedidos);//Muestra una lista de los pedidos que solo se encuentren en estado PENDIENTE
int BuscarPedidosPendientesPorId(eCliente listaClientes[], int tam,ePedido listaPedidos[], int tamPedidos,  eLocalidad listaLocalidades[], int tamLocalidades);//Le permite al usuario ingresar un id y buscar pedidos mediante el
void ImprimirListaDeClientesConSusPendientes(eCliente listaClientes[],int tam, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidades);// con suerte termine el codigo profe aprobame porfa
void MostrarListaProcesados(eCliente listaClientes[],int tam, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidades);
int MostrarPedidosPorLocalidad(eCliente listaClientes[], int tam, ePedido listaPedidos[],int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidades);
int PromedioPolipropileno(eCliente listaClientes[], int tam, ePedido listaPedidos[],int tamPedidos);
int MaximoPedidosPendientesCliente(eCliente listaClientes[], int tamClientes);
int MaximoPedidosProcesadosCliente(eCliente listaClientes[], int tamClientes);
#endif
