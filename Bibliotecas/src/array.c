/*
 * array.c
 *
 *  Created on: Apr 29, 2021
 *      Author: jessi
 */

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

//////////Funciones////////////////////


void inicializarArrayPersonas(Persona arrayPersonas[],int cantidadElementos,int valor)
{
	int i;
	for(i=0;i<cantidadElementos;i++)
	{
		arrayPersonas[i].legajo = valor;
	}
}

int buscarPrimerOcurrencia(Persona arrayPersonas[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i<cantidadDeElementos;i++)
    {
        if(arrayPersonas[i].legajo == valor)
        {
            return i;
        }
    }
    return -1;
}


//arr_calcularMinInt(&arrayEdades[CANTIDAD_EDADES],CANTIDAD_EDADES,valorMin)
int printArrayInt(int* pArray,int limite)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite >= 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			printf("\nIndice: %d - Valor: %d",i,pArray[i]);
		}

	}
	return retorno;
}

int arr_calcularMinInt(int* array,int limite,int* pResultado)
{
	int retorno = -1;
	int min; //buffer

	if(array != NULL && pResultado != NULL && limite>0)
	{
		min = array[0];
		for(int i=0; i<limite;i++)
		{
			if(array[i]<min)
			{
				min = array[i];
			}
		}
		*pResultado = min;
		retorno = 0;
	}
	return retorno;
}

int arr_calcularMaxInt(int* array,int limite,int* pResultado)
{
	int retorno = -1;
	int max; //buffer
	if(array != NULL && limite>0 && pResultado != NULL)
	{
		max = array[0];                //es el maximo pq es el primero como maximo y minimo
		for(int i=0; i<limite;i++)
		{
			if(array[i]>max)
			{
				max = array[i];
			}
		}
		*pResultado = max;
		retorno = 0;
	}

	return retorno;
}


int arr_calcularPromedioInt(int* array,int limite,float* pResultado)
{
	int retorno = -1;
	int acumulador = 0;

		if(array != NULL && limite>0 && pResultado != NULL)
		{
			for(int i=0; i<limite;i++)
			{
					acumulador = acumulador / array[i];
			}
			*pResultado = acumulador;
			retorno = 0;
		}
		return retorno;
}

int arr_calcularSumaInt(int* array,int limite,float* pResultado)
{
	int retorno = -1;
	int acumulador = 0;
	if(array != NULL && limite>0 && pResultado != NULL)
	{
		for(int i=0; i<limite;i++)
		{
			acumulador = acumulador + array[i];
		}
		*pResultado = acumulador;
		retorno = 0;
	}
	return retorno;
}

//ordenamiento de arrays para proxima clase - Método de burbujeo


int indiceMin(int* array,int limite,int indiceMin,int* pResultado)
{
	int retorno = -1;
	//int i;
	int min; //buffer

		if(array != NULL && pResultado != NULL && limite>0)
		{
			min = array[0];
			for(int i=0; i<limite-1;i++)
			{
				if(array[i]<min)
				{
					min = array[i];
					array[i] = min;
				}
			}
			*pResultado = min;
			retorno = 0;
		}

	return retorno;

}

int ordenarArrayInt(int* pArray,int limite)
{
	int retorno = -1;
	int i;
	int flagSwap;
	int buffer;

	if(pArray != NULL && limite >= 0)
	{
		retorno = 0;
		do
		{
			flagSwap = 0;   //fica em zero se nao teve intercambio, que nao vai seguir interando
			limite--;
			for(i=0;i<limite;i++)
			{
				if(pArray[i]<pArray[i+1])
				{
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;
					flagSwap = 1;                   //para indicar que teve intercambio,ou seja, que nao estavam ordenados, em 1 sigf que vai seguir interando
					//retorno++;                       para indicar quantas vezes fez o swap
				}
			}

		}while(flagSwap);

	}

	return retorno;

}
//char array[] da no mesmo
void myPrintDeCadena(char* arrayTexto,int len)
{
	int i;
	for(i=0; i<len;i++)
		{
			printf("%c",arrayTexto[i]);           //printf("%d-%c\n",texto[i],texto[i]); para imprimir cada letra uma debaixo da outra
			                                //printf("%c",texto[i]);  para imprimir cada letra uma do lado da outra
		}
}


int inicializarArrayFloat(float* pArray,int longitud,int valorInicial)
{
	int i;
    int respuesta = -1;
    if(pArray != NULL && longitud > 0)
    {
    	respuesta = 0;
    	for(i=0;i<longitud;i++)
    	{
    		pArray[i] = valorInicial;
    	}
    }
    return respuesta;
}

int imprimirArrayFloat(float* pArray,int longitud)
{
	int i;
    int respuesta = -1;
    if(pArray != NULL && longitud > 0)
    {
    	respuesta = 0;
    	for(i=0;i<longitud;i++)
    	{
    		printf("\nIndice: [%d] - Valor: %.2f",i,pArray[i]);
    	}
    }
    return respuesta;
}
