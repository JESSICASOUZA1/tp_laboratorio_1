/*
 * empleado.c
 *
 *  Created on: May 11, 2021
 *      Author: jessi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

eEmployee* employee_new(void)
{
	/*Empleado* auxEmpleado;
	auxEmpleado = (Empleado*) malloc(sizeof(Empleado));
	return auxEmpleado; */
	return (eEmployee*) malloc(sizeof(eEmployee));
}

eEmployee* employee_newParam(char* name,char* lastName,char* dni,int idEmployee)
{
	eEmployee* auxEmployee = employee_new();

	if(auxEmployee != NULL)
	{
		if  ( 	employee_setName(auxEmployee,name) < 0 ||
				employee_setlastName(auxEmployee,lastName) < 0 ||
				employee_setDni(auxEmployee,dni) < 0 ||
				employee_setId(auxEmployee,idEmployee) < 0 )
		{
			employee_delete(auxEmployee);
			auxEmployee = NULL;
		}
	}
	return auxEmployee;
}

int employee_delete(eEmployee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

int employee_setName(eEmployee* this,char* name)
{
	int retorno = -1;

	if(this != NULL && name != NULL && isValidName(name))
	{
		strcpy(this->name,name);
		retorno = 0;
	}
	return retorno;
}

char* employee_getName(eEmployee* this,int* flagError)
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

int employee_setlastName(eEmployee* this,char* lastName)
{
	int retorno = -1;

	if(this != NULL && lastName != NULL && isValidLastName(lastName))
	{
		strcpy(this->lastName,lastName);
		retorno = 0;
	}
	return retorno;
}

char* employee_getlastName(eEmployee* this,int* flagError)
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

int employee_setDni(eEmployee* this,char* dni)
{
	int retorno = -1;

	if(this != NULL && dni != NULL && isValidDni(dni))
	{
		strcpy(this->dni,dni);
		retorno = 0;
	}
	return retorno;
}

char* employee_getDni(eEmployee* this,int* flagError)
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

int employee_setId(eEmployee* this,int idEmployee)
{
	int retorno = -1;
	if(this != NULL && isValidId(idEmployee))
	{
		this->idEmployee = idEmployee;
		retorno = 0;
	}
	return retorno;
}

int employee_getId(eEmployee* this,int* flagError)
{
	*flagError = -1;
	int auxId = -1;

	if(this != NULL && flagError != NULL)
	{
		auxId=this->idEmployee;
		*flagError = 0;
	}
	return auxId;
}


/////////////////IsValid///////////////

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

int isValidLastName(char* cadena,int longitud)
{

	int i = 0;
	int retorno = 1;
	if (cadena != NULL && longitud > 0) {
		for (i = 0; cadena[i] != '\0' && i < longitud; i++) {
			if ((cadena[i] < 'A' || cadena[i] > 'Z')
					&& (cadena[i] < 'a' || cadena[i] > 'z')
					&& (cadena[i] != ' ')) {
				retorno = 0;
				printf("\nError de validacion, usted ingreso un caracter no permitido.\n");
				break;
			}
		}
	}
	return 1; //Ok
}

int isValidId(int idEmployee)
{
	return 1;
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
	return 1; //OK
}
