/*
 * arrayEmployee.h
 *
 *  Created on: May 8, 2021
 *      Author: jessi
 */

#ifndef ARRAYEMPLOYEE_H_
#define ARRAYEMPLOYEE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN_CHAR 2
#define QTY_REINTENTOS 2
#define LEN_STRING 4096
#define LEN_NAME 51
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
int MENUPrincipal();
int MENUInformar();







#endif /* ARRAYEMPLOYEE_H_ */
