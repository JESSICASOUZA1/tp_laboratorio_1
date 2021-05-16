/*
 * persona.h
 *
 *  Created on: May 8, 2021
 *      Author: jessi
 */

#ifndef PERSONA_H_
#define PERSONA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QTY_ATTEMPTS 2
#define ARRAY_LEN_STRING 4096
#define ARRAY_LEN_NAME 51
#define ARRAY_LEN_LASTNAME 51
#define ARRAY_LEN_DNI 11


int utn_getName(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getLastName(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getDni(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);













#endif /* PERSONA_H_ */
