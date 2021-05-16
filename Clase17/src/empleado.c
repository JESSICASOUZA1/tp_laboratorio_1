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

eEmployee* new(void)
{
	return malloc(sizeof(eEmployee));
}

eEmployee* newParam(char* name,char* lastName,char* dni,int id)
{
	eEmployee* auxEmployee = new();

	if(auxEmployee != NULL)
	{
		if(set_Name(auxEmployee,name) ||
				set_lastName(auxEmployee,lastName) ||
				set_Dni(auxEmployee,dni) ||
				set_ID(auxEmployee,id))
		{
			delete(auxEmployee);
			auxEmployee = NULL;
		}

	}

	return auxEmployee;
}

int delete(eEmployee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

int set_Name(eEmployee* this,char* name)
{

	int retorno = -1;

	if (this != NULL && name != NULL && isValidName != NULL) {

		retorno = 0;
	}

	return retorno;

}


char* get_Name(eEmployee* this,int* flagError)
{
	*flagError = -1;
	char* auxName;

	if (this != NULL && flagError != NULL)
	{

		auxName = this->name;
		*flagError = 0;
	}


	return auxName;
}

//strcpy(auxName[500],getName)

int set_lastName(eEmployee* this,char* lastName);

char* get_lastName(eEmployee* this,int* flagError)
{
	*flagError = -1;
	char *auxlastName;

	if (this != NULL && flagError != NULL)
	{

		auxlastName = this->lastName;
		*flagError = 0;
	}

	return auxlastName;
}

int set_Dni(eEmployee* this,char* dni)
{

}

char* get_Dni(eEmployee* this,int* flagError)
{
	*flagError = -1;
	char* auxDni = NULL;

	if (this != NULL && flagError != NULL) {

		auxDni = this->dni;
		*flagError = 0;
	}
	return auxDni; //devuelvo el contenido del puntero
}

int set_Id(eEmployee* this,int id)
{
	*flagError = -1;
	char *auxDni = NULL;

	if (this != NULL && flagError != NULL) {

		auxDni = this->dni;
		*flagError = 0;
	}
	return auxDni; //devuelvo el contenido del puntero

}
int get_Id(eEmployee* this,int* flagError);
