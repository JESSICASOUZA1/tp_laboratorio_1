/*
 * producto.h
 *
 *  Created on: May 13, 2021
 *      Author: jessi
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

typedef struct
{
	char name[50];
	char lastName[50];
	char dni[20];
	int idProduct;

}eProduct;

eProduct* product_new(void);
eProduct* product_newParam(char* name,char* lastName,char* dni,int idProduct);
int product_delete(eProduct* this);

int product_setName(eProduct* this,char* name);
char* product_getName(eProduct* this,int* flagError);
int isValidName(char* cadena,int longitud);

int product_setlastName(eProduct* this,char* lastName);
char* product_getlastName(eProduct* this,int* flagError);
int isValidLastName(char* cadena,int longitud);

int product_setDni(eProduct* this,char* dni);
char* product_getDni(eProduct* this,int* flagError);
int isValidDni(char* cadena,int longitud);

int product_setId(eProduct* this,int idProduct);
int product_getId(eProduct* this,int* flagError);
int isValidId(int idProduct);


#endif /* PRODUCTO_H_ */
