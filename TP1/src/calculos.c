/*
 * T1.c
 *
 *  Created on: Apr 10, 2021
 *      Author: jessi
 */
#include "calculos.h"

#include <stdio.h>
#include <stdlib.h>

/**
 *\brief: Solicita un numero al usuario y devuelve el resultado
 *\param: numero sera reemplazado por el numero ingresado por el usuario.
 *\return: retorna el resultado del factorial.
 */
int factorial(int numero)
{
	int resultado;
	if(numero >= 1)
	{
		resultado = (numero * factorial(numero-1));
		return resultado;
	}
	else
	{
		return 1;
	}
}

/**
 *\brief: Solicita dos numeros al usuario y devuelve el resultado
 *\param: numeroA y numeroB seran reemplazado por los numeros ingresados.
 *\return: 0 si la suma se realiza con exito, -1 si hubo algun error y el resultado de la suma en la variable pResultado.
 */
int sumar(int numeroA, int numeroB, float* pResultado)
{
	int retorno = -1;
	if(pResultado != NULL)
	{
		*pResultado = numeroA+numeroB;
		retorno = 0;
	}

	return retorno;
}

/**
 *\brief: Solicita dos numeros al usuario y devuelve el resultado
 *\param: numeroA y numeroB seran reemplazado por los numeros ingresados.
 *\return: 0 si la resta se realiza con exito, -1 si hubo algun error y el resultado de la resta en la variable pResultado.
 */
int restar(int numeroA, int numeroB, float* pResultado)
{
	int retorno = -1;
	if(pResultado != NULL)
	{
		*pResultado = numeroA-numeroB;
		retorno = 0;

	}
	return retorno;
}

/**
 *\brief: Solicita dos numeros al usuario y devuelve el resultado
 *\param: numeroA y numeroB seran reemplazado por los numeros ingresados.
 *\return: 0 si la multiplicacion se realiza con exito, -1 si hubo algun error y el resultado de la multiplicacion en la variable pResultado.
 */
int multiplicar(int numeroA, int numeroB, float* pResultado)
{
	int retorno = -1;
	if(numeroA != 0 && numeroB != 0 && pResultado != NULL)
	{
		*pResultado = numeroA*numeroB;
		retorno = 0;
	}

	return retorno;
}

/**
 *\brief: Solicita dos numeros al usuario y devuelve el resultado
 *\param: numeroA y numeroB seran reemplazado por los numeros ingresados.
 *\return: 0 si la division se realiza con exito, -1 si hubo algun error y el resultado de la division en la variable pResultado.
 */
int dividir(int numeroA,int numeroB, float* pResultado)
{
	int retorno = -1;

	if (numeroB != 0 && pResultado != NULL)
	{
		*pResultado = numeroA / numeroB;
		retorno = 0;
	}

	return retorno;
}
