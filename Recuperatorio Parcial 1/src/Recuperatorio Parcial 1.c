#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Biblioteca.h"
#include "ArrayClientes.h"
#include "ArrayPedidos.h"
#include "ArrayLocalidad.h"
#include "ArrayEnvios.h"


#define TAM_CLIENTES 1000
#define TAM_PEDIDOS 100
#define TAM_LOCALIDADES 4
#define TAM_ENVIOS 1000
#define OPCIONES 10



int main()
{
	setbuf(stdout,NULL);
    eCliente  listaClientes[TAM_CLIENTES]={{1,"Bridgestone",2000,"Jose maria moreno", 788, 1,CARGADO},
                                           {2,"Firestone",2594,"Lavallol", 4530, 2,CARGADO},
                                           {3,"PlasMEC",2817,"Udaondo",988,3,CARGADO},
                                            {4,"Pirelli",1150,"Larralde", 220, 4,CARGADO}};

    ePedido listaPedidos[TAM_PEDIDOS]=            {{1,1,230,0,0,0,0,PENDIENTE,"PENDIENTE",CARGADO},
                                                   {2,2,250,0,0,0,0,PENDIENTE,"PENDIENTE",CARGADO},
                                                   {3,3,159,0,0,0,0,PENDIENTE,"PENDIENTE",CARGADO},
                                                   {4,1,1200,0,0,0,0,PENDIENTE,"PENDIENTE",CARGADO},
                                                   {5,2,500,0,0,0,0,PENDIENTE,"PENDIENTE",CARGADO},
                                                   {6,3,245,0,0,0,0,PENDIENTE,"PENDIENTE",CARGADO},
                                                   {7,4,220,0,0,0,0,PENDIENTE,"PENDIENTE",CARGADO},
                                                   {8,4,990,0,0,0,0,PENDIENTE,"PENDIENTE",CARGADO}};

    eLocalidad listaLocalidades[TAM_LOCALIDADES]={{1,"CABA"},{2,"AVELLANEDA"},{3,"LANUS"},{4,"LOMAS DE ZAMORA"}};

    eEnvios listaEnvios[TAM_ENVIOS];
    int opcion;
    int verificarListaCargada;
    int verificarListaPedidosCargada;
    int verificarListaPedidosPendientes;
    int verificarListaPedidosCompletados;
    int clienteCargado = 0;
    int valorId = 4;
    int idAux = 4;
    int idIngresado;
    int flagModificacion;
    int idPedido = 8;
    int idAuxPedido = 8;
    int idEnvio = 0;
    int idEnvioAux = 0;

   // InicializarListaDeClientes (listaClientes, TAM_CLIENTES);
  //  InicializarListaDePedidos(listaPedidos, TAM_PEDIDOS);
    do
    {
    idAux=valorId;
    idAuxPedido=idPedido;
    printf("MENU PRINCIPAL\n");
    printf("1-Alta del cliente\n");
    printf("2-Modificar datos del cliente\n");
    printf("3-Baja del cliente\n");
    printf("4-Crear pedido de recoleccion\n");
    printf("5-Procesar residuos\n");
    printf("6-Imprimir clientes\n");
    printf("7-Imprimir pedidos pendientes\n");
    printf("8-Imprimir pedidos procesados\n");
    printf("9-Pendientes por localidad\n");
    printf("10-Promedio de polipropileno reciclado\n");
    printf("0-Salir\n");
    opcion = IngresarNumeroEnteroDeMaximoAMinimo ("Seleccione una opcion: ",OPCIONES, 0);
    verificarListaCargada = VerificarElEstadoDeLaLista(listaClientes, TAM_CLIENTES);
    verificarListaPedidosCargada = VerificarElEstadoDeLaListaDePedidos(listaPedidos, TAM_PEDIDOS);
    verificarListaPedidosPendientes = VerificarElEstadoDeLaListaDePedidosPendientes(listaPedidos, TAM_PEDIDOS);
    verificarListaPedidosCompletados =VerificarElEstadoDeLaListaDePedidosCompletados(listaPedidos, TAM_PEDIDOS);
    while((opcion != 0 && opcion != 1) && verificarListaCargada == -1)
    {
       opcion = IngresarNumeroEnteroDeMaximoAMinimo("Debera dar el alta a almenos un cliente. Seleccione una opcion: ",OPCIONES, 0);
    }


    switch (opcion)
    {
        case 1:
            clienteCargado = AgregarCliente(listaClientes, TAM_CLIENTES, &valorId, idAux, listaLocalidades, TAM_LOCALIDADES);
              system("cls");
            if(clienteCargado == 0)
            {
                printf("Se ha cargado el cliente de manera correcta.\n\n");
            }
            else
            {
                printf("La memoria se encuentra llena.\n\n");
            }
            break;

        case 2:

            idIngresado = BuscarClientesPorId(listaClientes, TAM_CLIENTES, listaLocalidades, TAM_LOCALIDADES);
            flagModificacion = ModificarListaClientes (listaClientes, TAM_CLIENTES, idIngresado, idAux, listaLocalidades, TAM_LOCALIDADES);
              system("cls");
                if(flagModificacion == 0)
                {
                    printf("El cliente se modifico correctamente\n\n");

                }
                else if (flagModificacion == -1)
                {
                    printf("No se encontro al cliente\n\n");

                }
                else
                {
                    printf("Se ha cancelado la operacion\n\n");

                }
           break;

        case 3:
        idIngresado = BuscarClientesPorId(listaClientes, TAM_CLIENTES, listaLocalidades, TAM_LOCALIDADES);
           system("cls");
        flagModificacion = BajaDelCliente(listaClientes, TAM_CLIENTES, idIngresado, idAux, listaLocalidades, TAM_LOCALIDADES);
            system("cls");
            if(flagModificacion == 0)
                {
                    printf("El cliente se elimino correctamente.\n\n");
                }
             else if(flagModificacion == 1)
                 {
                    printf("Se cancelo la operacion.\n\n");
                 }
                else
                {
                    printf("No se encontro al cliente. \n\n");
                }
        break;
        case 4:
        idIngresado = BuscarClientesPorId(listaClientes, TAM_CLIENTES, listaLocalidades, TAM_LOCALIDADES);
           system("cls");
        flagModificacion = CrearPedidoRecoleccion(listaClientes, TAM_CLIENTES, idIngresado, listaPedidos, TAM_PEDIDOS, &idPedido, idAuxPedido, &idEnvio, idEnvioAux, listaEnvios, TAM_ENVIOS, listaLocalidades, TAM_LOCALIDADES);
          system("cls");
            if(flagModificacion == 0)
            {
                printf("Se cargo correctamente el pedido.\n\n");
            }
            else
            {
                printf("No se encontro al cliente.\n\n");
            }
        break;

        case 5:
         system("cls");
        if(verificarListaPedidosCargada == -1)
        {
            printf("No se encuentran pedidos para procesar.\n\n");
            break;
        }
        flagModificacion=ProcesarResiduos(listaClientes, TAM_CLIENTES, listaPedidos, TAM_PEDIDOS, idAuxPedido, listaLocalidades, TAM_LOCALIDADES);
           system("cls");
        if(flagModificacion == 0)
        {
            printf("Se procesaron los residuos correctamente.\n\n");
        }
        else if(flagModificacion == 1)
        {
            printf("No se encontro el pedido.\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion.\n\n");
        }
        break;

        case 6:
        	  system("cls");
        if(verificarListaCargada == -1)
        {
            printf("La lista se encuntra vacia\n\n");
            break;
        }

        ImprimirListaDeClientesConSusPendientes(listaClientes, TAM_CLIENTES, listaPedidos, TAM_PEDIDOS, listaLocalidades, TAM_LOCALIDADES);
        break;

        case 7:
        	   system("cls");
        if(verificarListaPedidosPendientes == -1)
        {
            printf("No hay pedidos pendientes\n\n");
            break;
        }

        MostrarListaPendientes(listaClientes, TAM_CLIENTES, listaPedidos, TAM_PEDIDOS);
        fflush(stdin);
        break;

        case 8:
         system("cls");
        if(verificarListaPedidosCompletados == -1)
        {
          printf("No hay pedidos completados.\n\n");
            break;
        }
        MostrarListaProcesados(listaClientes, TAM_CLIENTES, listaPedidos, TAM_PEDIDOS, listaLocalidades, TAM_LOCALIDADES);
        fflush(stdin);
        break;

        case 9:
        system("cls");
        if(verificarListaPedidosPendientes == -1)
        {
            printf("No hay pedidos pendientes cargados.\n\n");
            break;
        }
         system("cls");
        flagModificacion= MostrarPedidosPorLocalidad(listaClientes, TAM_CLIENTES, listaPedidos,TAM_PEDIDOS, listaLocalidades, TAM_LOCALIDADES);
        if(flagModificacion == -1)
        {
            printf("No hay pedidos pendientes en esa localidad.\n\n");
        }
        break;

        case 10:
        system("cls");
        flagModificacion = PromedioPolipropileno(listaClientes,TAM_CLIENTES,listaPedidos,TAM_PEDIDOS);
        if(flagModificacion== -1)
        {

            printf("No se encontro pedidos con polipropileno(PP).\n\n");
        }

        break;

        case 11:
        	system("cls");
        	MostrarListaEnviados(listaEnvios, TAM_ENVIOS, listaPedidos, TAM_PEDIDOS, listaClientes, TAM_CLIENTES, listaLocalidades, TAM_LOCALIDADES);
    }

    }while (opcion != 0);

}
