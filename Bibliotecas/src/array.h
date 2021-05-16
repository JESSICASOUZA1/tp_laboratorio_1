/*
 * array.h
 *
 *  Created on: Apr 29, 2021
 *      Author: jessi
 */

#ifndef ARRAY_H_
#define ARRAY_H_

typedef struct
{
	char nombre[50];
	char apellido[50];
	int legajo;

}Persona;

/**
 * \brief Inicializa un array de Personas con el valor recibido
 * \param array Es el array a ser inicializado
 * \param cantidadDeElementos Indica la logitud del array
 * \param valor Es el valor que sera cargado en cada posición
 * \return void
*/
void inicializarArrayPersonas(Persona arrayPersonas[],int cantidadElementos,int valor);

/**
 * \brief Busca la primer ocurrencia de un valor en un array de Personas
 * \param array Es el array en el cual buscar
 * \param cantidadDeElementos Indica la logitud del array
 * \param valor Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay, la posición de la misma
 */
int buscarPrimerOcurrencia(Persona arrayPersonas[],int cantidadDeElementos,int valor);


int printArrayInt(int* pArray,int limite);

int arr_calcularMaxInt(int* array,int limite,int* pResultado);
int arr_calcularMinInt(int* array,int limite,int* pResultado);
int arr_calcularPromedioInt(int* array,int limite,float* pResultado);
int arr_calcularSumaInt(int* array,int limite,float* pResultado);

int indiceMin(int* array,int limite,int indiceMin,int* pResultado);
int ordenarArrayInt(int* pArray,int limite);

/**
 * \brief Imprime um array de flotantes
 * \param pArray puntero del array
 * \param logitud define el tamano del array
 * \param valorInicial es el valor a ser cargado en todas las posiciones del array
 * \return return retorna 0(exito) y -1(Error)
*/

int inicializarArrayFloat(float* pArray,int longitud,int valorInicial);
/**
 * \brief Imprime um array de flotantes
 * \param pArray puntero del array
 * \param logitud define el tamano del array
 * \return return retorna 0(exito) y -1(Error)
*/
int imprimirArrayFloat(float* pArray,int longitud);


#endif /* ARRAY_H_ */
