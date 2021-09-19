/*
 * producto.c
 *
 *  Created on: May 13, 2021
 *      Author: jessi
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"

eProduct* product_new(void)
{
	return (eProduct*) malloc(sizeof(eProduct));
}

eProduct* product_newParam(char* name,char* lastName,char* dni,int idProduct)
{
	eProduct* auxProduct = product_new();

	if(auxProduct != NULL)
	{
		if  ( 	product_setName(auxProduct,name) < 0 ||
				product_setlastName(auxProduct,lastName) < 0 ||
				product_setDni(auxProduct,dni) < 0 ||
				product_setId(auxProduct,idProduct) < 0 )
		{
			product_delete(auxProduct);
			auxProduct = NULL;
		}
	}
	return auxProduct;;
}

int product_delete(eProduct* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

int product_setName(eProduct* this,char* name)
{
	int retorno = -1;

	if(this != NULL && name != NULL && isValidName(name))
	{
		strcpy(this->name,name);
		retorno = 0;
	}
	return retorno;
}

char* product_getName(eProduct* this,int* flagError)
{
	*flagError = -1;
	char* auxName= NULL;

	if(this != NULL && flagError != NULL )
	{
		auxName = this->name;
		*flagError = 0;
	}
	return auxName;
}

int isValidName(char* cadena,int longitud)
{
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && longitud > 0) {
		for (i = 0; cadena[i] != '\0' && i < longitud; i++) {
			if ((cadena[i] < 'A' || cadena[i] > 'Z')
					&& (cadena[i] < 'a' || cadena[i] > 'z')) {
				retorno = 0;
				printf("\nError de validacion, usted ingreso un caracter no permitido.\n");
				break;
			}
		}
	}
	return 1;
}

int product_setlastName(eProduct* this,char* lastName)
{
	int retorno = -1;

	if(this != NULL && lastName != NULL && isValidLastName(lastName))
	{
		strcpy(this->lastName,lastName);
		retorno = 0;
	}
	return retorno;
}

char* product_getlastName(eProduct* this,int* flagError)
{
	*flagError = -1;
	char* aux = NULL;

	if(this != NULL && flagError != NULL)
	{
		aux = this->lastName;
		*flagError = 0;
	}
	return aux;
}

/**
 * \brief Verifica si la cadena ingresada es un apellido valido
 * \param cadena char de caracteres a ser analizada
 * \param longitud entero que marca la longitud de la cadena ingresada.
 * \return Retorna 1 (verdadero) si la cadena es un nombre valido, 0 (falso) si no lo es.
 **/
int isValidLastName(char* cadena,int longitud)
{
	int i;
	int retorno = 1;

	if (cadena != NULL && longitud > 0) {
		for (i = 0; cadena[i] != '\0' && i < longitud; i++) {
			if ((cadena[i] < 'A' || cadena[i] > 'Z')
					&& (cadena[i] < 'a' || cadena[i] > 'z')
					&& (cadena[i] != ' ')) {
				retorno = 0;
				printf("Error de validacion, usted ingreso un caracter no permitido.\n");
				break;
			}
		}
	}
	return retorno;
}

int product_setDni(eProduct* this,char* dni)
{
	int retorno = -1;

	if(this != NULL && dni != NULL && isValidDni(dni))
	{
		strcpy(this->dni,dni);
		retorno = 0;
	}
	return retorno;
}

char* product_getDni(eProduct* this,int* flagError)
{
	*flagError = -1;
	char* aux = NULL;

	if(this != NULL && flagError != NULL)
	{
		aux = this->dni;
		*flagError = 0;
	}
	return aux;
}

int isValidDni(char* cadena,int longitud)
{
	int i = 0;
	int retorno = 1;
	long lengthCadena = strlen(cadena);
	int contadorPuntos = 0;

	if (cadena != NULL && longitud > 0) {
		for (i = 0; cadena[i] != '\0'; i++) {
			//Menos de 6 numeros->ERROR
			if (lengthCadena < 6) {
				retorno = 0;
				if ((cadena[i] < '0' || cadena[i] > '9')) {
					printf("El DNI no puede contener letras\n");
					break;
				} else {
					printf("El DNI no puede tener menos de 6 numeros\n");
					break;
				}
			}
			//Contador de puntos
			if (cadena[i] == '.') {
				contadorPuntos++;
			}
			//Si comienza con un punto ERROR
			if (i == 0 && cadena[i] == '.') {
				retorno = 0;
				printf("El DNI no puede empezar con un punto\n");
				break;
			}
			//Si contiene letras->ERROR
			if ((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '.')) {
				retorno = 0;
				printf("El DNI no puede contener letras\n");
				break;
			}
		}
	}
	if (contadorPuntos == 0) {
		retorno = 0;
		printf("El DNI debe contener puntos\n");
	} else if (contadorPuntos == 1) {
		retorno = 0;
		printf("El DNI debe contener mas de un punto\n");
	} else if (contadorPuntos > 2) {
		retorno = 0;
		printf("El DNI no puede contener mas de dos puntos\n");
	}

	return retorno;
}

int product_setId(eProduct* this,int idProduct)
{
	int retorno = -1;
	if(this != NULL && isValidId(idProduct))
	{
		this->idProduct = idProduct;
		retorno = 0;
	}
	return retorno;
}

int product_getId(eProduct* this,int* flagError)
{
	*flagError = -1;
	int auxId = -1;

	if(this != NULL && flagError != NULL)
	{
		auxId=this->idProduct;
		*flagError = 0;
	}
	return auxId;
}

int isValidId(int idProduct)
{
	return 1;
}
