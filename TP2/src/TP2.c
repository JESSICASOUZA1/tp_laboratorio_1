/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "persona.h"
#include "arrayEmployee.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	int respuesta;

	eEmployee arrayEmployee[MAX_EMPLOYEE];
	initEmployee(arrayEmployee,MAX_EMPLOYEE);

	do
	{

	opcion = MENUPrincipal();

	switch(opcion)
	{
	case 1:
		if(addEmployee(arrayEmployee,MAX_EMPLOYEE) == -1)
		{
			printf("\nError dando de alta a empleado.\n");
		}
		system("pause");
		break;

	case 2:
		if(modifyEmployee(arrayEmployee,MAX_EMPLOYEE) == -1){
			printf("\nError modificando empleado.\n");
		}
		system("pause");
		break;

	case 3:
		if(removeEmployee(arrayEmployee,MAX_EMPLOYEE) == -1)
		{
			printf("\nError deletando el empleado.\n");
		}
		system("pause");
		break;

	case 4:

		  do
		  {
				respuesta = MENUInformar();
				switch(respuesta){

				case 1:

					if (sortEmployee(arrayEmployee, MAX_EMPLOYEE, 1) == -1) {
						printf("\nError en el sorteo el empleado.\n");
					}
					if (printEmployee(arrayEmployee, MAX_EMPLOYEE) == -1) {
						printf("\nError imprimindo empleado.\n");
					}
					system("pause");
					break;

				case 2:
					if(salaryCalculator(arrayEmployee,MAX_EMPLOYEE) == -1)
					{
						printf("\nError calculando salarios.\n");
					}
					system("pause");
					break;
				}
			}while(respuesta != 3);
			system("pause");
			break;
	}
	}while(opcion != 5);

	return EXIT_SUCCESS;
}
