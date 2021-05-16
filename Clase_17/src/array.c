/*
 * array.c
 *
 *  Created on: May 13, 2021
 *      Author: jessi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "array.h"
#include "persona.h"
#include "utn.h"


int emp_initArray(eEmployee* empleados[],int len)
//int emp_initArray(Empleado** empleados)
{
	int i;
	for(i=0; i<len; i++)
	{
		empleados[i] = NULL; // 0
	}
	return 0; // OK
}

int emp_buscarIniceVacio(eEmployee* empleados[],int len)
{
	int ret=-1;
	int i;
	for(i=0; i<len; i++)
	{
		if(empleados[i]==NULL)
		{
			ret =  i;
			break;
		}
	}
	return ret;
}


int generarId(void)
{
	static int contador = 0; // NO ES LOCAL DE LA FUNCION
	contador++;
	return contador;
}


int emp_alta(eEmployee* empleados[],int len)
{
	char nombreAux[LENGTH_NAME];
	char apellidoAux[LENGTH_NAME];
	char dniAux[LENGTH_DNI];
	int indiceLibre;
	int idEmployee;
	eEmployee* pEmp;
	int retorno = -1;

	indiceLibre = emp_buscarIniceVacio(empleados,len);
	if(indiceLibre>=0)
	{
		if(utn_getName("Nombre:","nahhh",nombreAux,LENGTH_NAME,QTY_ATTEMPTS)==0)
		{
			if(utn_getName("Apellido:","nahhh",apellidoAux,LENGTH_NAME,QTY_ATTEMPTS)==0)
			{
				if(utn_getDni("DNI:","nahhh",dniAux,LENGTH_DNI,QTY_ATTEMPTS)==0)
				{
					// genero el ID
					idEmployee = generarId();
					// construyo espacio de memoria
					pEmp = empleado_newParam(nombreAux,apellidoAux,dniAux,idEmployee);
					if(pEmp!=NULL)
					{
						// lo cargo en el array
						empleados[indiceLibre] = pEmp;
						retorno = 0;
					}
				}
			}
		}
	}
	else
	{
		printf("No hay mas lugar\n");
	}
	return retorno;
}

int emp_imprimirLista(eEmployee* empleados[],int len)
{
	int retorno = -1;
	int i;
	int flagError;
	char* pName;
	char* pLastName;
	char* pDni;
	int id;
	for(i=0; i<len; i++)
	{
		if(empleados[i]!=NULL)
		{
			// lo imprimo
			pName = employee_getName(empleados[i],&flagError);
			pLastName = employee_getlastName(empleados[i],&flagError);
			pDni = employee_getDni(empleados[i],&flagError);
			id = employee_getId(empleados[i],&flagError);
			printf("Nombre:%s Apellido:%s DNI:%s id:%d\n",pName,pLastName,pDni,id);
		}
	}
	return retorno;
}

int emp_buscarPorId(eEmployee* empleados[],int len, int id)
{
	eEmployee *retorno = NULL;
	int i;
	int flagError;
	int idItem;
	for (i = 0; i < len; i++) {
		if (empleados[i] != NULL) {
			idItem = employee_getId(empleados[i], &flagError);
			if (flagError == 0) {
				if (idItem == id) {
					// Lo encontre!
					retorno = empleados[i];
					break;
				}
			}
		}
	}
	return retorno;
}

int emp_buscarPorId2(eEmployee* empleados[],int len, int id)
{
	int retorno = -1;
	int i;
	int flagError;
	int idItem;
	for (i = 0; i < len; i++) {
		if (empleados[i] != NULL) {
			idItem = employee_getId(empleados[i], &flagError);
			if (flagError == 0) {
				if (idItem == id) {
					// Lo encontre!
					retorno = i;
					break;
				}
			}
		}
	}
	return retorno;
}

char* name[10]={"Ernesto","Maria","Jose","gabriel","Stefano","Patricio","Lucia","Lorenzo","Flaquito","Ludmila"};

void emp_altaForzada(eEmployee* empleados[],int len)
{
	eEmployee* pEmp;
	int idEmployee;
	int i;
	char cadenaName[LENGTH_NAME];

	for(i=0; i<10; i++)
	{
		idEmployee = emp_generarId();

		//snprintf(cadenaNombre,50,"%s",nombres[i]);
		strcpy(cadenaName,name[i]);

		pEmp = employee_newParam(cadenaName,"Perez","33221122",idEmployee);
		empleados[i] = pEmp;
	}
}

int emp_modificar(eEmployee* empleados[],int Length)
{
	int indiceDeEmpleadoEncontrado;
	int idAModificar;
	char auxLastName[LENGTH_NAME];
	int retorno = -1;

	if (utn_getInt("Ingresate un ID:", "nooo", &idAModificar) == 0) {
		indiceDeEmpleadoEncontrado = emp_buscarPorId2(empleados, Length,
				idAModificar);
		if (indiceDeEmpleadoEncontrado >= 0) {
			// lo encontro
			if (utn_getLastName("Nuevo apellido:", "no!", auxLastName, LENGTH_NAME,
					QTY_ATTEMPTS) == 0) {
				// modifico apellido actual por apellido ingresado
				if (employee_setlastName(empleados[indiceDeEmpleadoEncontrado],
						auxLastName) == 0) {
					retorno = 0;
				}
			}
		} else {
			printf("\nEse id no es valido\n");
		}
	}
	return retorno;
}

int emp_borrar(eEmployee* empleados[],int len)
{
	int indiceDeEmpleadoEncontrado;
	int idAModificar;
	int retorno = -1;


	if(utn_getInt("Ingresate un ID:","nooo",&idAModificar)==0)
	{
		indiceDeEmpleadoEncontrado = emp_buscarPorId2(empleados,len,idAModificar);
		if(indiceDeEmpleadoEncontrado>=0)
		{
			// lo encontro
			employee_delete(empleados[indiceDeEmpleadoEncontrado]);
			empleados[indiceDeEmpleadoEncontrado] = NULL;
		}
		else
		{
			printf("Ese id no es valido\n");
		}
	}
	return retorno;
}
