/*
 ============================================================================
 Name        : Clase_17.c
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
#include "persona.h"

int main(void)
{
	////// Ejemplo escritura de array binaria //////
	FILE* pFile;
	int i;

	eEmployee* empleados[100];
	emp_initArray(empleados,100);
	emp_altaForzada(empleados,100);
	em_parser("archivo.txt",empleados,100);
	//MENU ABM

	//pE = employee_newParam("Jessica,Souza,77892256,1");

	pFile = fopen("archivo.txt","w+"); //w+ lectura y escrictura

	if(pFile != NULL)
	{
		for(i=0;i<10;i++)
		{
			if(empleados[i]!=NULL)
			{
				fwrite(empleados[i],sizeof(empleados),1,pFile);
			}
		}

		fclose(pFile);
	}
	return EXIT_SUCCESS;
}


