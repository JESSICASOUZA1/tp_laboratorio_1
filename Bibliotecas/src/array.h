/*
 * array.h
 *
 *  Created on: Apr 29, 2021
 *      Author: jessi
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN_CHAR 2
#define QTY_REINTENTOS 2
#define LEN_STRING 4096
#define LEN_NAME 50
#define OCUPADO 1
#define VACIO 0
#define MAX_EMPLOYEE 1000


typedef struct
{
	int id;
	char name[LEN_NAME];
	char lastName[LEN_NAME];
	float salary;
	int sector;
	int isEmpty;

}eEmployee;

int initEmployee(eEmployee* pArray,int limite);
int addEmployee(eEmployee* pArray,int limite);
int findEmpty(eEmployee* pArray,int limite);
int modifyEmployee(eEmployee* pArray,int limite);
int findByID(eEmployee* pArray,int limite,int id);
int removeEmployee(eEmployee* pArray,int limite);
int printEmployee(eEmployee* pArray,int limite);
int sortEmployee(eEmployee* pArray,int limite,int order);
int salaryCalculator(eEmployee* pArray, int limite);


int printArrayInt(int* pArray,int limite);
int arr_calcularMaxInt(int* array,int limite,int* pResultado);
int arr_calcularMinInt(int* array,int limite,int* pResultado);
int arr_calcularPromedioInt(int* array,int limite,float* pResultado);
int arr_calcularSumaInt(int* array,int limite,float* pResultado);

int indiceMin(int* array,int limite,int indiceMin,int* pResultado);
int ordenarArrayInt(int* pArray,int limite);
int inicializarArrayFloat(float* pArray,int longitud,int valorInicial);
int imprimirArrayFloat(float* pArray,int longitud);

#endif /* ARRAY_H_ */
