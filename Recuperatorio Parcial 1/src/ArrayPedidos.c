#include "ArrayPedidos.h"
#include "Biblioteca.h"
#include "ArrayClientes.h"
#include "ArrayLocalidad.h"
#include "ArrayEnvios.h"


void InicializarListaDePedidos (ePedido listaPedidos[], int tam)
{
    for(int i=0; i<tam;i++)
    {
        listaPedidos[i].estado = VACIO;
    }
}


int VerificarElEstadoDeLaListaDePedidos(ePedido listaPedidos[], int tam)
{
    int flagRetorno = -1;
    for(int i= 0; i < tam; i++)
    {
        if(listaPedidos[i].estado == CARGADO)
        {
            flagRetorno = 0;
        }
    }

    return flagRetorno;
}
int VerificarElEstadoDeLaListaDePedidosPendientes(ePedido listaPedidos[], int tam)
{
    int flagRetorno = -1;
    for(int i= 0; i < tam; i++)
    {
        if(listaPedidos[i].estadoPedido == PENDIENTE && listaPedidos[i].estado == CARGADO)
        {
            flagRetorno = 0;
        }
    }

    return flagRetorno;
}

int VerificarElEstadoDeLaListaDePedidosCompletados(ePedido listaPedidos[], int tam)
{
    int flagRetorno = -1;
    for(int i= 0; i < tam; i++)
    {
        if(listaPedidos[i].estadoPedido == COMPLETADO && listaPedidos[i].estado == CARGADO)
        {
            flagRetorno = 0;
        }
    }

    return flagRetorno;
}

int CrearPedidoRecoleccion(eCliente listaClientes[], int tam, int idCliente, ePedido listaPedidos[], int tamPedidos, int* idPedido, int idPedidoAux,int* idEnvio, int idEnvioAux, eEnvios listaEnviados[], int tamEnviados, eLocalidad listaLocalidades[], int tamLocalidades)
{
 int flagRetorno = -1;
 int opcion;
    for (int i=0; i< tam; i++)
    {
        if(listaClientes[i].estado == CARGADO && listaClientes[i].id == idCliente)
        {
            for(int j=0 ; j < tamPedidos ; j ++)
            {

                if(listaPedidos[j].estado == VACIO)
                {

                    idPedidoAux++;
                    listaPedidos[j].idPedido = idPedidoAux;
                    listaPedidos[j].idCliente = idCliente;
                    listaPedidos[j].kilosTotales = IngresarNumeroFlotante("Ingrese la cantidad de kilos totales a reciclar: ");
                    listaPedidos[j].estadoPedido = PENDIENTE;
                    listaPedidos[j].estado = CARGADO;
                    strcpy(listaPedidos[j].descripcion,"PENDIENTE");
                    printf("¿A donde desea enviar el pedido?\n\n");
                    opcion = IngresarNumeroEnteroDeMaximoAMinimo("1-Misma direccion\n2-Cambiar Direccion\n", 2, 1);
                    for(int k=0; k < tamEnviados; k++)
                    {
                    	idEnvioAux++;
						switch(opcion)
						{

						case 1:
							listaEnviados[k].id = idEnvioAux;
							listaEnviados[k].estado = listaPedidos[j].estadoPedido;
							strcpy(listaEnviados[k].descripcion,"PENDIENTE");
							strcpy (listaEnviados[k].direccion,listaClientes[i].direccion);
							listaEnviados[k].numeracion = listaClientes[i].altura;
							listaEnviados[k].localidad = listaClientes[i].localidad;
							break;

						case 2:
							listaEnviados[k].id = idEnvioAux;
							listaEnviados[k].estado= PENDIENTE;
							strcpy(listaEnviados[k].descripcion,"PENDIENTE");
							IngresarCadena("Ingrese la direccion del envio: ", listaEnviados[k].direccion);
							listaEnviados[k].numeracion = IngresarNumeroEnteroDeMaximoAMinimo("Ingrese la altura: ", 9999999, 0);
							MostrarListaLocalidaes(listaLocalidades, tamLocalidades);
						    listaClientes[i].localidad = IngresarNumeroEnteroDeMaximoAMinimo("\nIngresar localidad: ",tamLocalidades, 1);

						    break;
						    flagRetorno = 0;
						}
                    }
                    break;
                }
            }
        break;
        }
    }



    *idEnvio = idEnvioAux;
    *idPedido = idPedidoAux;
    return flagRetorno;
}

int ProcesarResiduos(eCliente listaClientes[],int tam, ePedido listaPedidos[], int tamPedidos,int idPedidosAux, eLocalidad listaLocalidades[], int tamLocalidades)
{
    int flagRetorno = -1;
    float kilosAux;
    int idIngresado;
    int opcion;

    idIngresado = BuscarPedidosPendientesPorId(listaClientes,tam,listaPedidos,tamPedidos, listaLocalidades, tamLocalidades);


    for(int i = 0; i < tamPedidos; i++)
    {
         if (idIngresado > idPedidosAux)
        {
            flagRetorno = 1;
            break;
        }
        else if(listaPedidos[i].idPedido==idIngresado)
        {
            kilosAux=listaPedidos[i].kilosTotales;
            listaPedidos[i].kilosHDPE = 0;
            listaPedidos[i].kilosLDPE = 0;
            listaPedidos[i].kilosPP = 0;
            do
            {
            	//  system("clear");
                if(kilosAux < 0)
                {
                    printf("No es posible procesar el plastico. Revise los datos ingresados\n\n");
                }
                printf("Ingrese el tipo de plastico (Total=%.2f KG -> Faltan= %.2f KG):  \n",listaPedidos[i].kilosTotales,kilosAux);
                printf("Polietileno de alta densidad(HDPE):%6.2f KG\n",listaPedidos[i].kilosHDPE);
                printf("Polietileno de baja densidad(LDPE):%6.2f KG\n",listaPedidos[i].kilosLDPE);
                printf("Polipropileno(PP):%6.2f KG\n",listaPedidos[i].kilosPP);
                printf("Basura:%6.2f KG\n",listaPedidos[i].basura);
                printf("\nIngrese el la cantidad de plastico a reciclar\n");
                printf("0-CANELAR OPERACION\n1-HDPE\n2-LDPE\n3-PP\n4-PROCESAR RESIDUOS\n5-BORRAR DATOS INGRESADOS\n");
                opcion = IngresarNumeroEnteroDeMaximoAMinimo("Opcion: ",5,0);
                switch (opcion)
                {
                    case 0:
                        listaPedidos[i].kilosHDPE = 0;
                        listaPedidos[i].kilosLDPE = 0;
                        listaPedidos[i].kilosPP = 0;
                        flagRetorno = -1;
                    break;

                    case 1:
                        listaPedidos[i].kilosHDPE = IngresarNumeroFlotante("Ingrese KG de HDPE: ");
                    break;

                    case 2:
                        listaPedidos[i].kilosLDPE = IngresarNumeroFlotante("Ingrese KG de LDPE: ");
                    break;

                    case 3:
                        listaPedidos[i].kilosPP = IngresarNumeroFlotante("Ingrese KG de PP: ");
                    break;

                    case 4:
                        listaPedidos[i].estadoPedido = COMPLETADO;
                        strcpy(listaPedidos[i].descripcion,"COMPLETADO");
                        flagRetorno = 0;
                    break;

                    case 5:
                        listaPedidos[i].kilosHDPE = 0;
                        listaPedidos[i].kilosLDPE = 0;
                        listaPedidos[i].kilosPP = 0;
                    break;
                }
                kilosAux=listaPedidos[i].kilosTotales - listaPedidos[i].kilosHDPE - listaPedidos[i].kilosLDPE - listaPedidos[i].kilosPP;
                listaPedidos[i].basura = listaPedidos[i].kilosTotales - listaPedidos[i].kilosHDPE - listaPedidos[i].kilosLDPE - listaPedidos[i].kilosPP;
            }while((opcion != 0 && opcion != 4) || kilosAux < 0);
        }

    }
    return flagRetorno;
}

int MostrarListaPendientes(eCliente listaClientes[],int tam, ePedido listaPedidos[], int tamPedidos)
{
    int flagRetorno = -1;
    printf("LISTA DE PEDIDOS\n");
    printf("ID CLIENTE         EMPRESA       CUIT       ID PEDIDO       TOTAL A RECICLAR          ESTADO\n");

    for(int i = 0 ; i<tamPedidos;i++)
    {
        if(listaPedidos[i].estado == CARGADO && listaPedidos[i].estadoPedido == PENDIENTE)
        {
            for(int j=0 ; j<tam; j++)
            {
            	if(listaClientes[j].estado == CARGADO && listaClientes[j].id == listaPedidos[i].idCliente)
				{
				   flagRetorno = 0;
				   printf("%10d  %14s  %9d  %14d  %15.2f KG    %15s \n",listaClientes[j].id,listaClientes[j].nombre,
				   listaClientes[j].cuit, listaPedidos[i].idPedido,
				   listaPedidos[i].kilosTotales, listaPedidos[i].descripcion);
				}
			}
		}
	}


    return flagRetorno;
}
int BuscarPedidosPendientesPorId(eCliente listaClientes[], int tam,ePedido listaPedidos[], int tamPedidos,  eLocalidad listaLocalidades[], int tamLocalidades)
{
	// system("clear");
    int idIngresado;
    MostrarListaPendientes(listaClientes,tam,listaPedidos,tamPedidos);
    idIngresado = IngresarNumeroEnteroDeMaximoAMinimo("Ingrese el ID del pedido:\n ",1000, 1);
    return idIngresado;
}

void ImprimirListaDeClientesConSusPendientes(eCliente listaClientes[],int tam, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidades)
{

    int contadorPedidos = 0;

    printf("   ID             EMPRESA     CUIT                 DIRECCION            LOCALIDAD   TOTAL PENDIENTES\n");
    for(int i = 0 ; i < tam ; i ++)
    {
        if(listaClientes[i].estado == CARGADO)
        {
            for(int j = 0 ; j< tamPedidos; j++)
            {
                if(listaPedidos[j].estado == CARGADO && listaPedidos[j].estadoPedido == PENDIENTE && listaClientes[i].id == listaPedidos[j].idCliente )
                {
                    contadorPedidos ++;
                }

            }
          if (contadorPedidos >= 0)
           {
				 for(int j= 0; j < tamLocalidades;j ++)
				 {
					 if(listaClientes[i].localidad == listaLocalidades[j].id)
					 {
						printf("%4d %20s     %5d %20s %4d %20s        %4d\n",listaClientes[i].id, listaClientes[i].nombre, listaClientes[i].cuit, listaClientes[i].direccion, listaClientes[i].altura, listaLocalidades[j].descripcion, contadorPedidos);
						contadorPedidos = 0;
					 }
				 }
           }
        }
    }

}

void MostrarListaProcesados(eCliente listaClientes[],int tam, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidades)
{

    printf("LISTA DE PEDIDOS\n");
    printf("ID CLIENTE    EMPRESA       LOCALIDAD       ID PEDIDO      HDPE      LDPE      PP     BASURA        ESTADO\n");
    for(int i = 0 ; i<tamPedidos;i++)
    {
        if(listaPedidos[i].estado == CARGADO && listaPedidos[i].estadoPedido == COMPLETADO)
        {
            for(int j=0 ; j<tam; j++)
            {
                if(listaClientes[j].estado == CARGADO && listaClientes[j].id == listaPedidos[i].idCliente)
                {
                	for(int k = 0; k < tamLocalidades; k ++)
                	{
                		if(listaClientes[j].localidad == listaLocalidades[k].id)
                		{
						   printf(" %4d   %15s    %14s     %4d      %5.2fkg   %5.2fkg   %5.2fkg  %5.2fkg   %14s \n",listaClientes[j].id,listaClientes[j].nombre,
						   listaLocalidades[k].descripcion,listaPedidos[i].idPedido,listaPedidos[i].kilosHDPE,listaPedidos[i].kilosLDPE,listaPedidos[i].kilosPP,listaPedidos[i].basura,
						   listaPedidos[i].descripcion);
                		}
                	}
                }
            }
        }
    }
}

int MostrarPedidosPorLocalidad(eCliente listaClientes[], int tam, ePedido listaPedidos[],int tamPedidos, eLocalidad listaLocalidades[], int tamLocalidades)
{
    int flagRetorno=-1;
    int contadorPedidosPorLocalidad = 0;
    int localidadIngresada;


    for(int i=0; i<tam; i++)
    {
        if(listaClientes[i].estado==CARGADO)
        {
        	 MostrarListaLocalidaes(listaLocalidades, tamLocalidades);
        	 localidadIngresada=IngresarNumeroEnteroDeMaximoAMinimo("Ingrese la localidad: ", tamLocalidades, 1);
        	for(int k = 0; k< tamLocalidades; k ++)
        	{
				if(listaLocalidades[k].id==localidadIngresada)
				{
					for(int j=0; j<tamPedidos; j++)
					{
						if(listaPedidos[j].estado == CARGADO && listaPedidos[j].estadoPedido==PENDIENTE && listaPedidos[j].idCliente==listaClientes[i].id){
						contadorPedidosPorLocalidad++;
						flagRetorno=0;
						}
					}
				}

				if(flagRetorno==0){
				printf("Se encontraron %d pedidos en la localidad de %s.\n\n",contadorPedidosPorLocalidad,listaLocalidades[k].descripcion);
				}
				break;
        	}
        }
        break;
    }
    return flagRetorno;
}


int PromedioPolipropileno(eCliente listaClientes[], int tam, ePedido listaPedidos[],int tamPedidos)
{
    int flagRetorno = -1;
    int contador=0;
    float acumuladorPP = 0;
    float promedio;


    for(int i=0; i < tam; i++)
    {
        if(listaClientes[i].estado==CARGADO)
        {
            for(int j=0; j < tamPedidos ; j++)
            {
                if(listaClientes[i].id==listaPedidos[j].idPedido && listaPedidos[j].estado == CARGADO && listaPedidos[j].estadoPedido==COMPLETADO && listaPedidos[j].kilosPP!=0)
                {
                    acumuladorPP +=  listaPedidos[j].kilosPP;
                    contador++;
                    flagRetorno=0;
                }
            }
        }
    }
    if(flagRetorno==0)
    {
    promedio = acumuladorPP/contador;
    printf("El promedio de kilos de PP por cliente es de %.2f kilos.\n", promedio);
    printf("Total: %.2f KG\n",acumuladorPP);
    printf("Clientes que se les proceso PP: %d. \n", contador);
    }
    return flagRetorno;
}
