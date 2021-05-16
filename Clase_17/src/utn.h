/*
 * utn.h
 *
 *  Created on: May 8, 2021
 *      Author: jessi
 */

#ifndef UTN_H_
#define UTN_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARRAY_LEN_INT 64
#define ARRAY_LEN_STRING 4096
#define LEN_CHAR 2

int utn_getNumero(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, float maximo, float reintentos);
int utn_getInt(int* pResultado);
int utn_getCaracterSN(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);

#endif /* UTN_H_ */
