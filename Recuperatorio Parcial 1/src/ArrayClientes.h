#ifndef ARRAYCLIENTES_H_
#define ARRAYCLIENTES_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Biblioteca.h"
#include "ArrayLocalidad.h"



#define CARGADO 1
#define VACIO 0

typedef struct
{
    int id;
    char nombre[51];
    int cuit;
    char direccion[51];
    int altura;
    int localidad;
	int estado;
} eCliente;



void InicializarListaDeClientes (eCliente listaClientes[], int tam);
int VerificarElEstadoDeLaLista(eCliente listaClientes[], int tam);
int AgregarCliente(eCliente listaClientes[], int tam, int* valorId, int idAux, eLocalidad listaLocalidades[], int tamLocalidades);
void MostrarUnCliente(eCliente cliente, eLocalidad localidad [], int tamLocalidades);
void MostrarListaClientes(eCliente listaClientes[],int tam, eLocalidad localidad [], int tamLocalidades);
int BuscarClientesPorId(eCliente listaClientes[], int tam, eLocalidad localidad [], int tamLocalidades);
int ModificarListaClientes(eCliente listaClientes[], int tam, int idIngresado, int idAux, eLocalidad localidades[], int tamLocalidades);
int BajaDelCliente(eCliente listaClientes[], int tam, int idIngresado, int idAux, eLocalidad localidad[], int tamLocalidades);

#endif
