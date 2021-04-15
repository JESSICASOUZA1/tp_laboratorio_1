/*
 * Input.c
 *
 *  Created on: Apr 11, 2021
 *      Author: jessi
 */
#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

/**
 *\brief: Solicita un numero y mostra una mensaje
 *\param: pMensaje mostra una mensaje
 *\return: retorna el resultado
 */
int getNum(int* numero,char* pMensaje)
{
	int ret = -1;
	int num;
	printf(pMensaje); fflush(stdin);
	if( scanf("%d",&num) == 1)
	{
	*numero = num;
	ret = 0;
	}
	return ret;
}

/**
 *\brief: Solicita un numero entre minimo y maximo y devuelve resultado
 *\param: pMnesaje mostra un mensaje,
 *\param: min valida el numero entre minimo
 *\param: max valida el numero entre maximo
 *\return: Retorna el resultado.
 */
int getNumEntre(int* pNumero, char* pMensaje,int min, int max)
{
	int ret = -1;
	int num;

	printf(pMensaje); fflush(stdin);
	if(scanf("%d",&num)==1)
	{
		if(num>=min && num<=max)
			{
				*pNumero = num;
				ret = 0;
			}
	}
	return ret;
}
