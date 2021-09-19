/*
 * persona.c
 *
 *  Created on: Apr 29, 2021
 *      Author: jessi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "array.h"

static int getString(char* array, int len);
static int getName(char* pResultado, int longitud);
static int isName(char* cadena,int longitud);
static int getLastName(char* pResultado, int longitud);
static int isSurname(char* cadena,int longitud);
static int getDni(char* pResultado, int longitud);
static int isDNI(char* cadena, int longitud);
static int getPhone(char* pResultado, int longitud);
static int isPhone(char* cadena,int longitud);
static int getTexto(char* pResultado, int longitud);
static int esTexto(char* cadena,int longitud);

/*
 * \brief Lee de stdin hasta que encuentra un \n o hasta que haya copiado en cadena un maximo de len-1 caracteres.
 * 	\param array puntero al array donde se copiara la cadena obtenida
 * 	\param len es un entero que define el tamaño de la cadena
 * 	\return retorna 0 en caso de Exito y -1 en caso de ERROR
 * */
static int getString(char* array, int len)
{
	int retorno = -1;
	char bufferString[LEN_STRING];
	if(array!=NULL && len>0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin)!=NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString))<=len)
			{
				strncpy(array,bufferString,len);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/**
 * \brief Obtiene un nombre
 * \param pResultado Puntero char al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud entrero que marca la longitud de la cadena a ingresar.
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR)
 **/
static int getName(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[LEN_NAME];
    if(pResultado!=NULL && longitud>0)
    {
    	if(!getString(buffer,sizeof(buffer)) &&
    		isName(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}
/**
 * \brief Obtiene un Apellido
 * \param pResultado Puntero char al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud entrero que marca la longitud de la cadena a ingresar.
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR)
 **/
static int getLastName(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[LEN_NAME];
    if(pResultado!=NULL && longitud>0)
    {
    	if(!getString(buffer,sizeof(buffer)) &&
    		isSurname(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno=0;
		}
    }
    return retorno;
}

static int getDni(char* pResultado, int longitud)
{
	int res = -1;
	char bufferString[LEN_DNI];
	if( pResultado != NULL && longitud > 0 &&
	    !getString(bufferString, sizeof(bufferString)) &&
	    isDNI(bufferString, sizeof(bufferString)))
	{
		strncpy(pResultado, bufferString, longitud);
		res = 0;
	}
	return res;
}
/**
 * \brief Obtiene un Telefono
 * \param pResultado Puntero char al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud entrero que marca la longitud de la cadena a ingresar.
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR)
 **/
static int getPhone(char* pResultado, int longitud)
{
	int retorno = -1;
	char bufferString[LEN_TEL];
	if(pResultado != NULL && longitud > 0 &&
	    !getString(bufferString, sizeof(bufferString)) &&
	    isPhone(bufferString,sizeof(bufferString)))
	{
		retorno = 0;
		strncpy(pResultado,bufferString,longitud);
	}
	return retorno;
}

/**
 * \brief Obtiene un texto
 * \param pResultado Puntero char al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud entrero que marca la longitud de la cadena a ingresar.
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR)
 **/
static int getTexto(char* pResultado, int longitud)
{
	int retorno = -1;
	char bufferString[LEN_STRING];
	if(pResultado!=NULL && longitud>0)
	{
		if( !getString(bufferString,sizeof(bufferString)) &&
		    esTexto(bufferString, sizeof(bufferString)))
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena char de caracteres a ser analizada
 * \param longitud entero que marca la longitud de la cadena ingresada.
 * \return Retorna 1 (verdadero) si la cadena es un nombre valido, 0 (falso) si no lo es.
 **/
static int isName(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;
	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z'))
			{
				retorno = 0;
				printf("Error de validacion, usted ingreso un caracter no permitido.\n");
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es un apellido valido
 * \param cadena char de caracteres a ser analizada
 * \param longitud entero que marca la longitud de la cadena ingresada.
 * \return Retorna 1 (verdadero) si la cadena es un nombre valido, 0 (falso) si no lo es.
 **/
static int isSurname(char* cadena,int longitud)
{
	int i=0;
	int retorno=1;
	if(cadena!=NULL && longitud>0)
	{
		for(i=0;cadena[i]!='\0' && i<longitud;i++)
		{
			if((cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z') &&
			   (cadena[i]!=' '))
			{
				retorno = 0;
				printf("Error de validacion, usted ingreso un caracter no permitido.\n");
				break;
			}
		}
	}
	return retorno;
}

/*
 * \brief valida un DNI
 * \param pResultado: puntero a char donde se guarda el valor a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
static int isDNI(char* cadena, int longitud)
{
	int i=0;
	int retorno = 1;
	long lengthCadena = strlen(cadena);
	int contadorPuntos = 0;
	if(cadena != NULL && longitud > 0)
	{
		for(i=0;cadena[i]!='\0'; i++)
		{
			//Menos de 6 numeros->ERROR
			if(lengthCadena < 6)
			{
				retorno = 0;
				if((cadena[i] < '0' || cadena[i] > '9'))
				{
					printf("El DNI no puede contener letras\n");
					break;
				}
				else
				{
					printf("El DNI no puede tener menos de 6 numeros\n");
					break;
				}
			}
			//Contador de puntos
			if(cadena[i]=='.')
			{
				contadorPuntos++;
			}
			//Si comienza con un punto ERROR
			if(i==0 && cadena[i]=='.')
			{
				retorno = 0;
				printf("El DNI no puede empezar con un punto\n");
				break;
			}
			//Si contiene letras->ERROR
			if((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '.'))
			{
				retorno = 0;
				printf("El DNI no puede contener letras\n");
				break;
			}
		}
	}
	if(contadorPuntos == 0)
	{
		retorno = 0;
		printf("El DNI debe contener puntos\n");
	}
	else if(contadorPuntos == 1)
	{
		retorno = 0;
		printf("El DNI debe contener mas de un punto\n");
	}
	else if(contadorPuntos > 2)
	{
		retorno = 0;
		printf("El DNI no puede contener mas de dos puntos\n");
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un TELEFONO valido
 * \param cadena char de caracteres a ser analizada
 * \param longitud entero que marca la longitud de la cadena ingresada.
 * \return Retorna 1 (verdadero) si la cadena es un nombre valido, 0 (falso) si no lo es.
 **/
static int isPhone(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;
	long lengthCadena = strlen(cadena);
	if(cadena != NULL && longitud > 0) {
		for(i = 0; cadena[i] != '\0' && i < longitud; i++) {
			if(lengthCadena <= 7) {
				retorno = 0;
				printf("El telefono no puede contener menos de 8 numeros\n");
				break;
			}
			if((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != ' ')
					&& (cadena[i] != '-')) {
				retorno = 0;
				printf(
						"Error de validacion, los telefonos solo contienen numeros, espacios y guiones medios.\n");
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un texto valido
 * \param cadena char de caracteres a ser analizada
 * \param longitud entero que marca la longitud de la cadena ingresada.
 * \return Retorna 1 (verdadero) si la cadena es un texto valido, 0 (falso) si no lo es.
 **/
static int esTexto(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;
	if(cadena!=NULL && longitud>0)
	{
		for(i=0;cadena[i]!='\0' && i<longitud;i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) &&
			   (cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != ' ') &&
			   (cadena[i] != ',') && (cadena[i] != '.') &&
			   (cadena[i] != '+') && (cadena[i] != '-') &&
			   (cadena[i] != '?'))
			{
				retorno = 0;
				printf("Error de validacion, usted ingreso un caracter no permitido.\n");
				break;
			}
		}
	}
	return retorno;
}

/*
 * \brief Pide un Nombre al usuario.
 * \param pResultado: puntero a char donde se guarda el valor a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int utn_getName(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	char bufferString[LEN_NAME];
	int retorno=-1;
	int i=0;
	if(pResultado != NULL && longitud > 0 && pMensaje != NULL
			&& pMensajeError != NULL && reintentos > 0) {
		for(i = 0; i <= reintentos; i++) {
			printf("%s", pMensaje);
			if(!getName(bufferString, sizeof(bufferString))
					&& strnlen(bufferString, sizeof(bufferString)) < longitud)
			{
				strncpy(pResultado, bufferString, longitud);
				retorno = 0;
				break;
			}
			printf("%s", pMensajeError);
		}
	}
	return retorno;
}
/*
 * \brief Pide un Apellido al usuario.
 * \param pResultado: puntero a char donde se guarda el valor a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int utn_getLastName(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	char bufferString[LEN_NAME];
	int retorno=-1;
	int i=0;
	if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL
			&& reintentos > 0) {
		for(i = 0; i <= reintentos; i++) {
			printf("%s", pMensaje);
			if(!getLastName(bufferString, sizeof(bufferString))
					&& strnlen(bufferString, sizeof(bufferString)) < longitud)
			{
				strncpy(pResultado, bufferString, longitud);
				retorno = 0;
				break;
			}
			printf("%s", pMensajeError);
		}
	}
	return retorno;
}

/*
 * \brief Pide un DNI al usuario.
 * \param pResultado: puntero a char donde se guarda el valor a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int utn_getDni(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[LEN_DNI];
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",pMensaje);
		if(!getDni( bufferString,sizeof(bufferString)) &&
				    strnlen(bufferString,sizeof(bufferString))<longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",pMensajeError);
	}
	return retorno;
}

/*
 * \brief Pide un Telefono al usuario.
 * \param pResultado: puntero a char donde se guarda el valor a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int utn_getPhone(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[LEN_TEL];
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",pMensaje);
		if(!getPhone( bufferString,sizeof(bufferString)) &&
				         strnlen(bufferString,sizeof(bufferString))<longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",pMensajeError);
	}
	return retorno;
}

/*
 * \brief Pide un texto al usuario.
 * \param pResultado: puntero a char donde se guarda el dato a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int utn_getTexto(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	char bufferString[LEN_STRING];
	int retorno = -1;
	while(reintentos >= 0) {
		reintentos--;
		printf("%s", pMensaje);
		if(!getTexto(bufferString, sizeof(bufferString))
				&& strnlen(bufferString, sizeof(bufferString)) < longitud)
		{
			strncpy(pResultado, bufferString, longitud);
			retorno = 0;
			break;
		} else {
			printf("%s", pMensajeError);
		}
	}
	return retorno;
}



