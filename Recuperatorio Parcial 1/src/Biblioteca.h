#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int IngresarNumeroEnteroDeMaximoAMinimo(char mensaje[], int max, int min);
void IngresarCadena (char mensaje[], char cadenaIngresada[]);
float IngresarNumeroFlotante (char mensaje[]);
int ValidarNumeroEntero(char numeroIngresado[]);
int ValidarCadena(char cadenaIngresada[]);
int ValidarNumeroFlotante(char numeroIngresado[]);
void NormalizarCadena(char cadenaIngresada[]);

#endif
