
#ifndef ARRAYLOCALIDAD_H_
#define ARRAYLOCALIDAD_H_


typedef struct
{
	int id;
	char descripcion[51];

} eLocalidad;

void MostrarListaLocalidaes(eLocalidad listaLocalidades [], int tam);

#endif /* ARRAYLOCALIDAD_H_ */
