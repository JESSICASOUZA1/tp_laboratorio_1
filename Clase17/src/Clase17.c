/*
 ============================================================================
 Name        : Clase17.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

int main(void)
{

	eEmployee* auxEmployee;
	int flagError;
	auxEmployee = employee_new();

	employee_setName(auxEmployee,"JESS");
	printf("El nombre es: %s",employee_getName(auxEmployee,&flagError));








	return EXIT_SUCCESS;
}
