/*
 * persona.h
 *
 *  Created on: Apr 29, 2021
 *      Author: jessi
 */

#ifndef PERSONA_H_
#define PERSONA_H_

#define ARRAY_LEN_STRING 4096
#define ARRAY_LEN_INT 64
#define ARRAY_LEN_NOMBRE 222
#define ARRAY_LEN_APELLIDO 60
#define LEN_CHAR 2
#define ARRAY_LEN_DNI 11
#define ARRAY_LEN_CUIT 14
#define ARRAY_LEN_TEL 20

int utn_getNumero(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, float maximo, float reintentos);
int utn_getTexto(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getApellido(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getCaracter(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getDni(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getCuit(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getTelefono(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getCaracterSN(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);

typedef struct
{
	char nombre[50];
	char apellido[50];
	int legajo;

}Persona;

typedef struct
{
	char nombre[50];
	char apellido[50];
    float peso;
    float altura;
}Personaa;

void inicializarArrayPersonas(Persona arrayPersonas[],int cantidadElementos,int valor);
int buscarPrimerOcurrencia(Persona arrayPersonas[],int cantidadDeElementos,int valor);
int inicializarArrayFloat(float* pArray,int longitud,int valorInicial);
int imprimirArrayFloat(float* pArray,int longitud);


#endif /* PERSONA_H_ */
