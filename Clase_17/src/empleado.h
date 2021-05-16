/*
 * empleado.h
 *
 *  Created on: May 11, 2021
 *      Author: jessi
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_
#define LENGTH_NAME 50
#define LENGTH_DNI 11
#define QTY_ATTEMPTS 2


typedef struct
{
	int idEmployee;
	char name[LENGTH_NAME];
	char lastName[LENGTH_NAME];
	char dni[LENGTH_DNI];

}eEmployee;

//constructor
eEmployee* employee_new(void);
eEmployee* employee_newParam(char* name,char* lastName,char* dni,int idEmployee);

//destructor
int employee_delete();

//las unicas funciones que pueden acceder a los campos
int employee_setName(eEmployee* this,char* name);
char* employee_getName(eEmployee* this,int* flagError);
int isValidName(char* cadena,int longitud);

int employee_setlastName(eEmployee* this,char* lastName);
char* employee_getlastName(eEmployee* this,int* flagError);
int isValidLastName(char* cadena,int longitud);

int employee_setDni(eEmployee* this,char* dni);
char* employee_getDni(eEmployee* this,int* flagError);
int isValidDni(char* cadena,int longitud);

int employee_setId(eEmployee* this,int idEmployee);
int employee_getId(eEmployee* this,int* flagError);
int isValidId(int);


#endif /* EMPLEADO_H_ */
