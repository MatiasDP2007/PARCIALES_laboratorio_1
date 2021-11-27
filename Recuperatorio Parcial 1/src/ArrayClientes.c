#include "ArrayClientes.h"
#include "ArrayPedidos.h"
#include "Biblioteca.h"
#include "ArrayEnvios.h"
#include "ArrayLocalidad.h"


void InicializarListaDeClientes (eCliente listaClientes[], int tam)
{
    for(int i=0; i<tam; i++)
    {
    listaClientes[i].estado = VACIO;
    }
}

int VerificarElEstadoDeLaLista(eCliente listaClientes[], int tam)
{
    int flagRetorno = -1;
    for(int i= 0; i < tam; i++)
    {
        if(listaClientes[i].estado == CARGADO)
        {
            flagRetorno = 0;
        }
    }

    return flagRetorno;
}
int AgregarCliente(eCliente listaClientes[], int tam, int* valorId, int idAux, eLocalidad listaLocalidades[], int tamLocalidades)
{

    int flagRetorno = -1;

    for(int i=0; i<tam;i++)
    {

            if(listaClientes[i].estado == VACIO)
            {
				flagRetorno = 0;
				idAux ++;
				listaClientes[i].id = idAux;
				IngresarCadena("\nIngrese el nombre de la empresa: ", listaClientes[i].nombre);
				listaClientes[i].cuit = IngresarNumeroEnteroDeMaximoAMinimo("\nIngrese el CUIT: ",9999999,1);
				IngresarCadena("\nIngrese la direccion: ",listaClientes[i].direccion);
				listaClientes[i].altura = IngresarNumeroEnteroDeMaximoAMinimo("\nIngrese la altura: ",999999,0);
				MostrarListaLocalidaes(listaLocalidades, tamLocalidades);
				listaClientes[i].localidad = IngresarNumeroEnteroDeMaximoAMinimo("\nIngresar localidad: ",tamLocalidades, 1);
				listaClientes[i].estado = CARGADO;
				break;
            }

    }
    *valorId = idAux;
    return flagRetorno;

}

void MostrarUnCliente(eCliente cliente, eLocalidad localidad[], int tamLocalidades)
{
	for(int i = 0; i < tamLocalidades; i++)
	{
		if(cliente.localidad == localidad[i].id)
		{
			printf("%d  %20s %15d     %17s %5d %26s\n",cliente.id, cliente.nombre, cliente.cuit, cliente.direccion, cliente.altura, localidad[i].descripcion);
		}
	}
}

void MostrarListaClientes(eCliente listaClientes[],int tam, eLocalidad localidad[], int tamLocalidades)
{
    printf("ID              NOMBRE            CUIT                   DIRECCION                  LOCALIDAD\n");
    for(int i=0 ; i<tam ; i++)
    {
        if (listaClientes[i].estado==CARGADO)
        {
            MostrarUnCliente(listaClientes[i], localidad, tamLocalidades);
        }
    }
}



int BuscarClientesPorId(eCliente listaClientes[], int tam, eLocalidad localidad [], int tamLocalidades)
{
    system("cls");
    int idIngresado;
    MostrarListaClientes(listaClientes, tam, localidad, tamLocalidades );
    idIngresado = IngresarNumeroEnteroDeMaximoAMinimo("Ingrese el ID del cliente:\n ",9999, 1);
    return idIngresado;
}

int ModificarListaClientes(eCliente listaClientes[], int tam, int idIngresado,int idAux, eLocalidad localidades[], int tamLocalidades)
{
    int flagRetorno = -1 ;
    int opcion;
     system("cls");

    for(int i=0; i<tam ; i++)
    {
        if(idIngresado > idAux)
        {
            flagRetorno= -1;
            break;
        }
            else if(listaClientes[i].estado == CARGADO && listaClientes[i].id == idIngresado)
            {
                flagRetorno = 0;
                printf("\n0-CANCELAR\n1-DIRECCION\n2-ALTURA\n3-LOCALIDAD\n");
                opcion = IngresarNumeroEnteroDeMaximoAMinimo("Seleccione el campo a modificar: ",3,0);

                   system("cls");
                switch(opcion)
                {

                    case 1:
                    IngresarCadena("\nIngrese la direccion: ",listaClientes[i].direccion);
                    break;

                    case 2:
                    listaClientes[i].altura = IngresarNumeroEnteroDeMaximoAMinimo("\nIngrese la altura: ",999999,0);
                    break;


                    case 3:
                    MostrarListaLocalidaes(localidades, tamLocalidades);
                    listaClientes[i].localidad= IngresarNumeroEnteroDeMaximoAMinimo("\nIngrese la localidad: ", tamLocalidades, 1);

                    break;

                    case 0:
                    flagRetorno = 1;
                    break;
                }
            }
        }
    return flagRetorno;
}

int BajaDelCliente(eCliente listaClientes[], int tam, int idIngresado, int idAux, eLocalidad localidad[], int tamLocalidades)
{
    int flagRetorno = -1;
    int opcion;
 //   system("clear");
    for (int i=0; i<tam ; i++)
    {
        if(idIngresado > idAux)
        {
            flagRetorno = -1;
            break;
        }

        else if(listaClientes[i].estado == CARGADO && listaClientes[i].id == idIngresado)
        {
            printf("ID              NOMBRE            CUIT         DIRECCION          LOCALIDAD\n");
            MostrarUnCliente(listaClientes[i], localidad, tamLocalidades);
            opcion = IngresarNumeroEnteroDeMaximoAMinimo("Estas seguro que deseas eliminar al cliente?\n 1-SI\n 2-NO\n",2,1);
            switch(opcion)
            {
            case 1:
            listaClientes[i].estado = VACIO;
            flagRetorno = 0;
            break;

            case 2:
            flagRetorno = 1;
            break;

            }
        }

    }

return flagRetorno;
}












