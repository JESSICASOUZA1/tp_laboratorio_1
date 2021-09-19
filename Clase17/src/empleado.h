/*
 * empleado.h
 *
 *  Created on: May 11, 2021
 *      Author: jessi
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

typedef struct
{
	char name[50];
	char lastName[50];
	char dni[20];
	int idEmployee;

}eEmployee;

//constructor
eEmployee* employee_new(void);
eEmployee* employee_newParam(char* name,char* lastName,char* dni,int idEmployee);

//destructor
int employee_delete();

//las unicas funciones que pueden acceder a los campos
int employee_setName(eEmployee* this,char* name);
char* employee_getName(eEmployee* this,int* flagError);
int isValidName(char*);

int employee_setlastName(eEmployee* this,char* lastName);
char* employee_getlastName(eEmployee* this,int* flagError);
int isValidLastName(char*);

int employee_setDni(eEmployee* this,char* dni);
char* employee_getDni(eEmployee* this,int* flagError);
int isValidDni(char*);

int employee_setId(eEmployee* this,int idEmployee);
int employee_getId(eEmployee* this,int* flagError);
int isValidId(int);


#endif /* EMPLEADO_H_ */
