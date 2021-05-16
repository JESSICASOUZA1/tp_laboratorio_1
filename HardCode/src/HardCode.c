/*
 ============================================================================
 Name        : HardCode.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMITE 200

void hardCode(LALA *array, int limite)
{
	char nombreAux[][51] = { "Amy", "Darwin", "Fredo", "Naruto", "Sasuke" , "Hinata" , "Sakura", "Minato", "Itachi", "Kushina" };
    char sexoAux[][1] = { "F" , "M","F" , "M","F" , "M","F" , "M","F" , "M"};
    char tipoAux[][5] = { "  " ,"  ", "  ","  " ,"  ", "  ","  " ,"  ", "  ","  "};
    int edadAux[10] = {5,6,7,8,9,10,22,11,22,2};


    for(int i=0;i<10;++i)
    	{
    		strcpy(array[i].nombre, nombreAux[i]);
    		array[i].edad = edadAux[i];
    		strcpy(array[i].sexo, sexoAux[i]);
    		strcpy(array[i].tipo, tipoAux[i]);
    		array[i].isEmpty = 0;
    	}
}


void inicArrayLALA(LALA* array,int limite)
{
	int i;

	for(i=0;i<limite;i++)
	{
		array[i].isEmpty = 1;
	}
}


int encontrarVacio(LALA *pArray, int limite, int *pos)     //findEmpty
{
	int retorno = -1;
	int i;

	if (pArray != NULL && limite > 0 && pos != NULL) {
		for (i = 0; i < limite; i++) {
			if (pArray[i].isEmpty == 1) {
				retorno = 0;
				*pos = i;
				break;
			}
		}
	}

	return retorno;
}

int addLALA(LALA *pArray, int limite) {
	int retorno = -1;
	int i;


	if (encontrarVacio(pArray, limite, &i) == 0) {



/*
		strncpy(pArray[i].name, name, sizeof(pArray[i].name));
		strncpy(pArray[i].lastName, lastName, sizeof(pArray[i].lastName));
		pArray[i].salary = salary;
		pArray[i].sector = sector;
*/
		pArray[i].isEmpty = 0;
		retorno = 0;

	} else {
		retorno = -1;
		printf("\nNo hay espacio para mas mascotas.");
	}

	return retorno;
}


int getById(LALA* array,int id)
{

	return 0;
}






















	return EXIT_SUCCESS;
}
