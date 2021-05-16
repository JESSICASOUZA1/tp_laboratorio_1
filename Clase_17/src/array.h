/*
 * array.h
 *
 *  Created on: May 13, 2021
 *      Author: jessi
 */

#ifndef ARRAY_H_
#define ARRAY_H_

int generarId(void);
int emp_initArray(eEmployee* empleados[],int len);
int emp_buscarIniceVacio(eEmployee* empleados[],int len);
int emp_alta(eEmployee* empleados[],int len);
int emp_imprimirLista(eEmployee* empleados[],int len);

eEmployee* emp_buscarPorId(eEmployee* empleados[],int len, int id);
int emp_buscarPorId2(eEmployee* empleados[],int len, int id);
void emp_altaForzada(eEmployee* empleados[],int len);
int emp_modificar(eEmployee* empleados[],int len);
int emp_borrar(eEmployee* empleados[],int len);







#endif /* ARRAY_H_ */
