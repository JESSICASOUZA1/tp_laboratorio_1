/*
 * arrayEmployee.c
 *
 *  Created on: May 8, 2021
 *      Author: jessi
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployee.h"
#include "persona.h"
#include "utn.h"

int generarId(void)
{
	static int contador = 0;
	contador++;
	return contador;
}

/**\brief pArray Array de empleados a ser inicializado
 * \param limite Limite del array de empleados
 * \return Retorna -1 (ERROR) y 0 (EXITO)
 */
int initEmployee(eEmployee* pArray,int limite)
{
	int retorno = -1;
	int i;

	if(pArray != NULL && limite > 0) {
		for(i = 0; i < limite; i++) {
			pArray[i].isEmpty = VACIO;
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Busca la primer ocurrencia de un espacio vacio en un array de empleados
 * \param Array es el array en el cual buscar
 * \param Limites indica la logitud del array
 * \param posicion es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay, la posición de la misma
 */
int findEmpty(eEmployee* pArray,int limite) //EncontrarVacio
{
	int retorno = -1;
    int i;

	if(pArray != NULL && limite > 0)
	{
		for(i = 0; i < limite; i++)
		{
			if(pArray[i].isEmpty == VACIO) {
				retorno = i;
				break;
			}
		}
	}

    return retorno;
}
/**\brief Funcion para dar de alta a un empleado
 * \param pArray Array de Empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \return Retorna -1 (ERROR) y 0 (EXITO)
 */
int addEmployee(eEmployee* pArray,int limite)
{
	int retorno = -1;
	int auxIndice = -1;
	float salario;
	int sector;
	eEmployee Buffer;

	if(pArray != NULL && limite > 0)
	{
		if(utn_getName(Buffer.name,LEN_NAME,"\nIngrese nombre: ","\nError,nombre invalido.\n",QTY_REINTENTOS) == 0 &&
		   utn_getLastName(Buffer.lastName,LEN_NAME,"\nIngrese apellido: ","\nError,apellido invalido.\n",QTY_REINTENTOS) == 0 &&
		   utn_getNumeroFlotante(&salario,"\nIngrese salario: ","\nError,salario invalido.\n",1,100000,QTY_REINTENTOS) == 0 &&
		   utn_getNumero(&sector,"\nIngrese sector: ","\nError,sector invalido.\n",1,100,QTY_REINTENTOS) == 0)

		{
			auxIndice = findEmpty(pArray,limite);
			if(auxIndice != -1){
				Buffer.id = generarId();
				Buffer.salary = salario;
				Buffer.sector = sector;
				Buffer.isEmpty = OCUPADO;
				strcpy(pArray[auxIndice].name, Buffer.name);
				strcpy(pArray[auxIndice].lastName, Buffer.lastName);
				retorno = 0;
			}
			printf("\nAlta de empleado com exito!\nID de empleado es: %d\n",pArray[auxIndice].id);
		}
		else{
			printf("\nNo hay lugar para mas empleados.\n");
		}
	}

	return retorno;
}

/**
 * \brief Buscar empleado por ID
 * \param Array es el array en el cual buscar
 * \param Limites indica la logitud del array
 * \param id es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay, la posición de la misma
 */
int findByID(eEmployee* pArray,int limite,int id)
{
	int retorno = -1;
    int i;

	if(pArray != NULL && limite > 0) {
		for(i = 0; i <= limite; i++) {
			if(pArray[i].id == id) {
				retorno = i;
				break;
			}
		}
	}
    return retorno;
}

/**
 * \brief Buscar empleado por ID
 * \param Array es el array en el cual buscar
 * \param Limites indica la logitud del array
 * \param id es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay, la posición de la misma
 */
int modifyEmployee(eEmployee* pArray,int limite)
{
	int retorno = -1;
	eEmployee Buffer;
	int id = -1;
	int indice = -1;
	int respuesta;
	float salario;
	int sector;

	printf("\nIngrese ID del empleado a modificar.\n"); utn_getInt(&id);
	indice = findByID(pArray,limite,id);

	if(indice != -1)
	{
		utn_getNumero(&respuesta,"\nIngrese numero de opcion a modificar\n"
				"1-Nombre\n"
				"2-Apellido\n"
				"3-Salario\n"
				"4-Sector\n","\nError,opcion invalida.\n",1,4,QTY_REINTENTOS);

		switch(respuesta)
		{
		case 1:
			if(utn_getName(Buffer.name,LEN_NAME,
					"\nIngrese nuevo nombre del empleado: ","\nError,Nombre invalido.\n",QTY_REINTENTOS)==0)
			{
				strcpy(pArray[indice].name, Buffer.name);
				retorno = 0;
				printf("\nNombre alterado con exito.\n");
			}
			break;

		case 2:
			if(utn_getLastName(Buffer.lastName,LEN_NAME,
					"\nIngrese nuevo apellido del empleado: ","\nError,Apellido invalido,\n",QTY_REINTENTOS)==0)
			{
				strcpy(pArray[indice].lastName, Buffer.lastName);
				retorno = 0;
				printf("\nApellido alterado con exito.\n");
			}
			break;

		case 3:
			if(utn_getNumeroFlotante(&salario,"\nIngrese nuevo salario: ",
					"\nError,salario invalido.\n",1,1000000,QTY_REINTENTOS)==0)
			{
				{
					pArray[indice].salary = salario;
					retorno = 0;
					printf("\nSalario alterado con exito.\n");
				}
			}
			break;

		case 4:
			printf("Ingrese nuevo sector: ");
			if(utn_getInt(&sector)==0)
			{
				pArray[indice].sector = sector;
				retorno = 0;
				printf("\nSector alterado con exito.\n");
			}
			break;

		}
	}else
	{
		printf("\nError,ID no encontrado.\n");
	}

	return retorno;
}

/**\brief Remueve empleado por ID (setea isEmpty Flag en 1)
 * \param pArray Array de Empleados en el que hace la busqueda
 * \param limite Limite del array de empleados
 * \param id ID que busca en el array
 * \return Retorna -1 (ERROR) y 0 (EXITO)
 */
int removeEmployee(eEmployee* pArray,int limite)
{
	int retorno = -1;
	//eEmployee Buffer;
	char BufferChar;
	int id = -1;
	int indice = -1;

	printf("\nIngrese ID del empleado a deletar.\n"); utn_getInt(&id);
	indice = findByID(pArray,limite,id);

	if(indice != -1)
	{
		if(utn_getCaracterSN(&BufferChar,LEN_CHAR,"\nEstas seguro que desea borrar empleado del sistema?\nIngrese [S/N]:\n",
				"\nError,solo puedes ingresar [S/N].\n",QTY_REINTENTOS) == 0)
		{
			switch(BufferChar)
			{
			case 'S':
			case 's':

				pArray[indice].isEmpty = VACIO;
				//printf("\nEmpleado deletado con exito.\n");
				printf("\n--->%10s    %10s    deletado con exito.<---\n",pArray[indice].name,pArray[indice].lastName);
				retorno = 0;
				break;

			case 'N':
			case 'n':
				break;
			}
		}
	}
	else{
		printf("\nNo se encontro el ID ingresado.\n");
	}

	return retorno;
}

/**
 * \brief Imprime um array de empleados
 * \param pArray puntero del array
 * \param limite define el tamano del array
 * \return return retorna 0(exito) y -1(Error)
*/
int printEmployee(eEmployee* pArray,int limite)
{
	int retorno = -1;
	int i;

	if(pArray != NULL && limite > 0){
		printf("ID:  Nombre:   Apellido:   Salario:  Sector: \n");
		for(i = 0; i <= limite; i++){
			if(pArray[i].isEmpty == OCUPADO)
			{
				printf("%d     %s        %s       $%.2f    %d\n",
					pArray[i].id, pArray[i].name,
					pArray[i].lastName, pArray[i].salary, pArray[i].sector);
				retorno = 0;
			}
		}

	}
	return retorno;
}

/**\brief Sortea los elementos en el array de empleados alfabeticamente por apellido
 *        y sector en forma ascendiente o descendiente, dependiendo del orden seleccionado
 * \param pArray Array de Empleados que se sortea
 * \param limite Limite del array de empleados
 * \param orden [1] sortear ascendiente - [0] sortear descendiente
 * \return Retorna -1 (ERROR) y 0 (EXITO)
 */
int sortEmployee(eEmployee* pArray,int limite,int order)
{
	int retorno = -1;
	eEmployee aux;
	int i = 0;
	int j = 0;

	if (pArray != NULL && limite > 0) {
		switch (order) {
		case 1: //ascendente
			for (i = 0; i < limite - 1; i++) {
				for (j = i + 1; j < limite; j++) {
					if (strcmp(pArray[i].lastName, pArray[j].lastName) > 0) {
						aux = pArray[j];
						pArray[j] = pArray[i];
						pArray[i] = aux;
					}

					else if (strcmp(pArray[j].lastName, pArray[i].lastName) == 0
							&& pArray[j].sector < pArray[i].sector) {
						aux = pArray[j];
						pArray[j] = pArray[i];
						pArray[i] = aux;
					}
				}
			}
			break;

		case 0: //descendente
			for (i = 0; i < limite - 1; i++) {
				for (j = i + 1; j < limite; j++) {
					if (strcmp(pArray[j].lastName, pArray[i].lastName) > 0) {
						aux = pArray[j];
						pArray[j] = pArray[i];
						pArray[i] = aux;
					}

					else if (strcmp(pArray[j].lastName, pArray[i].lastName) == 0
							&& pArray[j].sector > pArray[i].sector) {
						aux = pArray[j];
						pArray[j] = pArray[i];
						pArray[i] = aux;
					}
				}
			}
			break;
		}
		retorno = 0;
	}

	return retorno;
}

/** \brief Calcula el total y promedio de los salarios, y cuantos empleados
 * superan el salario promedio.
 * \param pArray Array de Empleados en el que se hace el calculo
 * \param limite Limite del array de empleados
 * \return Retorna -1 (ERROR) y 0 (EXITO)
 */
int salaryCalculator(eEmployee* pArray, int limite)
{
	int i;
	int retorno = -1;
	int activeEmployee = 0;
	float acumSalary = 0;
	float average;
	int employeeAverage = 0; //Promedio de empleado

	if (pArray != NULL && limite > 0) {
		for (i = 0; i < limite; i++) {
			if (pArray[i].isEmpty == OCUPADO) {
				activeEmployee++;
				acumSalary = acumSalary + pArray[i].salary;
			}
		}
		average = acumSalary / activeEmployee;

		for (i = 0; i < limite; i++) {
			if (pArray[i].salary > average && pArray[i].isEmpty == OCUPADO) {
				employeeAverage++;
			}
		}

		if (employeeAverage == 1) {
			printf("\nEl total de los salarios es: $%.2f"
					"\nEl promedio de los salarios es: $%.2f"
					"\n%d empleado supera el salario promedio.\n", acumSalary,
					average, employeeAverage);
		} else {
			printf("\nEl total de los salarios es: $%.2f"
					"\nEl promedio de los salarios es: $%.2f"
					"\n%d empleados superan el salario promedio.\n",
					acumSalary, average, employeeAverage);
		}
		retorno = 0;
	}
	return retorno;
}

///////////////MENU///////////////

/**\brief Muestra un menu principal y captura una opcion.
 * \return int opcion (opcion que eligio el usuario).
 */
int MENUPrincipal()
{
	int retorno = -1;
	int opcion;

	if(utn_getNumero(&opcion,"-----MENU-----\n\n"
					"Ingrese opcion\n"
					"1-Alta de empleado\n"
					"2-Modificar empleado\n"
					"3-Baja de empleado\n"
					"4-Informar listas\n"
					"5-Salir\n","Error,opcion invalida.\n",1,5,2) == -1)
	{
		printf("\nSe te acabaron los intentos.\n");
		system("pause");
	}
	else
	{
		retorno = opcion;
	}

	return retorno;
}

/**\brief Muestra un menu de informes y captura una opcion.
 * \return int opcion (opcion que eligio el usuario).
 */
int MENUInformar()
{
	int retorno = -1;
	int opcion;

	if(utn_getNumero(&opcion,"-----MENU INFORMES-----\n\n"
						"Ingrese opcion\n"
						"1-Listado de los empleados ordenados alfabeticamente por apellido y sector.\n"
						"2-Total y promedio de los salarios y cuantos empleados superan el salario promedio.\n"
						"3-Salir\n","Error,opcion invalida.\n",1,3,2) == -1)
		{
			printf("\nSe te acabaron los intentos.\n");
			system("pause");
		}
	else
	{
		retorno = opcion;
	}
	return retorno;
}
