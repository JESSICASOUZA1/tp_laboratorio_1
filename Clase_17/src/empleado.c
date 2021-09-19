/*
 * empleado.c
 *
 *  Created on: May 11, 2021
 *      Author: jessi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "persona.h"
#include "utn.h"

static int isValidDni(char* cadena,int longitud);
static int isValidId(int idEmployee);
static int isValidLastName(char* cadena,int longitud);
static int isValidName(char* cadena,int longitud);
static int getInt(int* pResultado);

/////////sets and gets/////////

eEmployee* employee_new(void)
{
	return (eEmployee*) malloc(sizeof(eEmployee));
}

eEmployee* employee_newParam(char* name,char* lastName,char* dni,int idEmployee)
{
	eEmployee* auxEmployee = employee_new();

	if(auxEmployee != NULL)
	{
		if  ( 	employee_setName(auxEmployee,name) < 0 ||
				employee_setlastName(auxEmployee,lastName) < 0 ||
				employee_setDni(auxEmployee,dni) < 0 ||
				employee_setId(auxEmployee,idEmployee) < 0 )
		{
			employee_delete(auxEmployee);
			auxEmployee = NULL;
		}
	}
	return auxEmployee;
}

int employee_delete(eEmployee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

int employee_setName(eEmployee* this,char* name)
{
	int retorno = -1;

	if(this != NULL && name != NULL && isValidName(name,LENGTH_NAME) == 1)
	{
		strcpy(this->name,name);
		retorno = 0;
	}
	return retorno;
}

char* employee_getName(eEmployee* this,int* flagError)
{
	*flagError = -1;
	char* auxName= NULL;

	if(this != NULL && flagError != NULL )
	{
		auxName = this->name;   //Devuelve la direccion de memoria del campo de empleado, no devuelve una copia.
		*flagError = 0;
	}
	return auxName;
}

int employee_setlastName(eEmployee* this,char* lastName)
{
	int retorno = -1;

	if(this != NULL && lastName != NULL && isValidLastName(lastName,LENGTH_NAME))
	{
		strcpy(this->lastName,lastName);
		retorno = 0;
	}
	return retorno;
}

char* employee_getlastName(eEmployee* this,int* flagError)
{
	*flagError = -1;
	char* aux = NULL;

	if(this != NULL && flagError != NULL)
	{
		aux = this->lastName;
		*flagError = 0;
	}
	return aux;
}

int employee_setDni(eEmployee* this,char* dni)
{
	int retorno = -1;

	if(this != NULL && dni != NULL && isValidDni(dni,LENGTH_DNI))
	{
		strcpy(this->dni,dni);
		retorno = 0;
	}
	return retorno;
}

char* employee_getDni(eEmployee* this,int* flagError)
{
	*flagError = -1;
	char* aux = NULL;

	if(this != NULL && flagError != NULL)
	{
		aux = this->dni;
		*flagError = 0;
	}
	return aux;
}

int employee_setId(eEmployee* this,int idEmployee)
{
	int retorno = -1;
	if(this != NULL && isValidId(idEmployee))
	{
		this->idEmployee = idEmployee;
		retorno = 0;
	}
	return retorno;
}

int employee_getId(eEmployee* this,int* flagError)
{
	*flagError = -1;
	int auxId = -1;

	if(this != NULL && flagError != NULL)
	{
		auxId=this->idEmployee;
		*flagError = 0;
	}
	return auxId;
}

//////////////////Arrays Dinamicos///////////////////////

//Array de puntero a empleado
int emp_initArray(eEmployee* empleados[],int len)
{
	int i;
	for(i=0; i<len; i++)
	{
		empleados[i] = NULL; // 0
	}
	return 0; // OK
}

int emp_buscarIndiceVacio(eEmployee* empleados[],int len)
{
	int retorno = -1;
	int i;
	for(i=0; i<len; i++)
	{
		if(empleados[i]==NULL) //se es null es porque encontro uno vacio, una posicion vacia
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

static int contador=0;

void emp_setearValorInicialDeID(int id)
{
	contador = id;
}

int emp_generarId(void)
{
	//static int contador=0; // NO ES LOCAL DE LA FUNCION, cuando sale la variable sigue teniendo el valor que tenia
	contador++;
	return contador;
}

int emp_add(eEmployee* empleados[],int len)
{
	char auxName[LENGTH_NAME];
	char auxLastName[LENGTH_NAME];
	char auxDni[LENGTH_DNI];
	int indiceLibre;
	int idEmployee;
	eEmployee* pEmployee; //puntero
	int retorno = -1;

	indiceLibre = emp_buscarIndiceVacio(empleados,len); //primero buscamos un indice libre
	if(indiceLibre>=0)
	{
		if(utn_getName(auxName,LENGTH_NAME,"\nIngrese nombre: ","\nError,nombre invalido.\n",QTY_ATTEMPTS) == 0)
		{
			if(utn_getLastName(auxLastName,LENGTH_NAME,"\nIngrese apellido: ","\nError,apellido invalido.\n",QTY_ATTEMPTS) == 0)
			{
				if(utn_getDni(auxDni,LENGTH_DNI,"\nIngrese apellido: ","\nError,apellido invalido.\n",QTY_ATTEMPTS) == 0)
				{
					// genero el ID
					idEmployee = emp_generarId();

					// construyo espacio de memoria
					pEmployee = employee_newParam(auxName,auxLastName,auxDni,idEmployee); //devuele la direccion de memoria, osea, el espacio de memoria que tiene lugar para guardar todos los campos que estan en la estructura

					if(pEmployee!=NULL)
					{
						// lo cargo en el array
						empleados[indiceLibre] = pEmployee;
						retorno = 0;
					}
				}
			}
		}
	}
	else
	{
		printf("No hay mas lugar.\n");
	}
	return retorno;
}

int emp_printLista(eEmployee* empleados[],int len)
{
	int retorno = -1;
	int i;
	int flagError;
	char* pName;
	char* pLastName;
	char* pDni;
	int id;

	for(i=0; i<len; i++)
	{
		if(empleados[i]!=NULL)
		{
			// lo imprimo
			pName = employee_getName(empleados[i],&flagError);
			pLastName = employee_getlastName(empleados[i],&flagError);
			pDni = employee_getDni(empleados[i],&flagError);
			id = employee_getId(empleados[i],&flagError);
			printf("Nombre:%s Apellido:%s DNI:%s id:%d\n",pName,pLastName,pDni,id);
		}
	}
	return retorno;
}

//devuelve el empleado
eEmployee* emp_buscarPorId(eEmployee* empleados[],int len, int id)
{
	eEmployee* retorno = NULL;
	int i;
	int flagError;
	int idItem;
	for(i=0; i<len; i++)
	{
		if(empleados[i]!=NULL)
		{
			idItem = employee_getId(empleados[i],&flagError);
			if(flagError==0)
			{
				if(idItem==id)
				{
					// Lo encontre, sino NULL
					retorno = empleados[i];
					break;
				}
			}
		}
	}
	return retorno;
}

//devuelve el indicedel array donde esta el empleado
int emp_buscarPorId2(eEmployee* empleados[],int len, int id)
{
	int retorno = -1;
	int i;
	int flagError;
	int idItem;
	for(i=0; i<len; i++)
	{
		if(empleados[i]!=NULL)
		{
			idItem = employee_getId(empleados[i],&flagError);
			if(flagError==0)
			{
				if(idItem==id)
				{
					// Lo encontre!
					retorno = i;
					break;
				}
			}
		}
	}
	return retorno;
}

void emp_altaForzada(eEmployee* empleados[],int len)
{
	eEmployee* pEmp;
	int idEmpleado;
	int i;
	char cadenaName[LENGTH_NAME];

	for(i=0; i<10; i++)
	{
		idEmpleado = emp_generarId();

		snprintf(cadenaName,LENGTH_NAME,"Flaquito-%d",idEmpleado); //snprintf no muestra en la consola, solo en mete en la cadena

		pEmp = employee_newParam(cadenaName,"Perez","33221122",idEmpleado);
		empleados[i] = pEmp;
	}
}

//alta forzada con nombres
//array de 10 punteros
char* names[10]={"Ernesto","Maria","Jose","gabriel","Stefano","Patricio","Lucia","Lorenzo","Flaquito","Ludmila"};

void emp_altaForzadaName(eEmployee* empleados[],int len)
{
	eEmployee* pEmp;
	int idEmpleado;
	int i;
	char cadenaName[LENGTH_NAME];

	for(i=0; i<10; i++)
	{
		idEmpleado = emp_generarId();

		//snprintf(cadenaNombre,50,"%s",nombres[i]);
		strcpy(cadenaName,names[i]);

		pEmp = employee_newParam(cadenaName,"Perez","33221122",idEmpleado);
		empleados[i] = pEmp;
	}
	return;
}

int emp_modificar(eEmployee* empleados[],int len)
{
	int indiceDeEmpleadoEncontrado;
	int idAModificar;
	char auxLastName[LENGTH_NAME];
	int retorno = -1;

	printf("Ingresate un ID: ");
	if(utn_getInt(&idAModificar)==0)
	{
		indiceDeEmpleadoEncontrado = emp_buscarPorId2(empleados,len,idAModificar);
		if(indiceDeEmpleadoEncontrado>=0)
		{
			// lo encontro
			if(utn_getLastName(auxLastName,LENGTH_NAME,"\nIngrese apellido: ","\nError,apellido invalido.\n",QTY_ATTEMPTS) == 0)
			{
				// modifico apellido actual por apellido ingresado
				if(employee_setlastName(empleados[indiceDeEmpleadoEncontrado],auxLastName)==0)
				{
					retorno = 0;
				}
			}
		}
		else
		{
			printf("Ese id no es valido\n");
		}
	}
	return retorno;
}

int emp_borrar(eEmployee* empleados[],int len)
{
	int indiceDeEmpleadoEncontrado;
	int idAModificar;
	int retorno = -1;

	printf("Ingresate un ID: ");
	if(utn_getInt(&idAModificar)==0)
	{
		indiceDeEmpleadoEncontrado = emp_buscarPorId2(empleados,len,idAModificar);
		if(indiceDeEmpleadoEncontrado>=0)
		{
			// lo encontro
			employee_delete(empleados[indiceDeEmpleadoEncontrado]);
			empleados[indiceDeEmpleadoEncontrado] = NULL; //borra la direccion de memoria que tenia
		}
		else
		{
			printf("Ese id no es valido\n");
		}
	}
	return retorno;
}

int emp_parser(char nombreArchivo[],eEmployee* empleados[],int len)
{
	FILE *pFile;
	char nombreAux[LENGTH_NAME];
	char apeAux[LENGTH_NAME];
	char dniAux[LENGTH_DNI];
	char idAux[256];
	int flagOnce = 0;
	int idEmp;
	eEmployee *pE;
	int indice = -1;

	pFile = fopen(nombreArchivo, "r");
	if (pFile != NULL) {
		indice = 0;
		do {
			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", nombreAux, apeAux,
					dniAux, idAux) == 4) {
				if (flagOnce != 0) {
					//printf("%s %s %s %s\n",nombreAux,apeAux,dniAux,idAux);
					if (getInt(idAux) == 0)
					{
						idEmp = atoi(idAux);
						pE = empleado_newParam(nombreAux, apeAux, dniAux,idEmp);
						empleados[indice] = pE;
						indice++;
					}

				}
			} else
			{

			}
			flagOnce = 1;
		} while (feof(pFile) == 0 && indice < 100);
		fclose(pFile);
	}

	return indice;
}

int emp_parserMAX(char nombreArchivo[],eEmployee* empleados[],int len,int* pIdMaxEncontrado)
{
	FILE* pFile;
	char nombreAux[256];
	char apeAux[256];
	char dniAux[256];
	char idAux[256];
	int flagOnce=0;
	int idEmp;
	eEmployee* pE;
	int indice=-1;
	int idMax;

	pFile = fopen(nombreArchivo,"r");
	if(pFile!=NULL)
	{
		indice=0;
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",nombreAux,apeAux,dniAux,idAux)==4)
			{
				if(flagOnce!=0)
				{
					//printf("%s %s %s %s\n",nombreAux,apeAux,dniAux,idAux);
					if(utn_isNumeric(idAux)==1)
					{
						idEmp = atoi(idAux);
						pE = empleado_newParam(nombreAux,apeAux,dniAux,idEmp);

						empleados[indice] = pE;

						// busco maximo
						if(indice==0)
							idMax = idEmp; // me guardo el 1ero como MAX
						else
						{
							if(idEmp>idMax)
								idMax = idEmp;
						}

						indice++;
					}

				}
			}
			else
			{

			}
			flagOnce=1;
		}
		while(feof(pFile)==0 && indice<100);
		fclose(pFile);

		*pIdMaxEncontrado = idMax; // lo escribo en la var externa
	}

	return indice; // devuelve cantidad leidos
}

int emp_dump(char nombreArchivo[],eEmployee* empleados[],int len)
{
	// serializer
	int retorno=-1;
	int i;
	int flagError;
	char* pNombre;
	char* pApellido;
	char* pDni;
	int id;
	FILE* pFile;

	pFile = fopen(nombreArchivo,"w");
	if(pFile!=NULL)
	{
		fprintf(pFile,"Nombre,Apellido,DNI,idEmpleado\n");
		for(i=0; i<len; i++)
		{
			if(empleados[i]!=NULL)
			{
				// lo imprimo
				pNombre = empleado_getNombre(empleados[i],&flagError);
				pApellido = empleado_getApellido(empleados[i],&flagError);
				pDni = empleado_getDni(empleados[i],&flagError);
				id = empleado_getId(empleados[i],&flagError);

				fprintf(pFile,"%s,%s,%s,%d\n",pNombre,pApellido,pDni,id);
			}
		}
		fclose(pFile);
	}

	return retorno;

}


/////////////////IsValid////////////////

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena char de caracteres a ser analizada
 * \param longitud entero que marca la longitud de la cadena ingresada.
 * \return Retorna 1 (verdadero) si la cadena es un nombre valido, 0 (falso) si no lo es.
 **/
static int isValidName(char* cadena,int longitud)
{
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && longitud > 0) {
		for (i = 0; cadena[i] != '\0' && i < longitud; i++) {
			if ((cadena[i] < 'A' || cadena[i] > 'Z')
					&& (cadena[i] < 'a' || cadena[i] > 'z')) {
				retorno = 0;
				printf("\nError de validacion, usted ingreso un caracter no permitido.\n");
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un apellido valido
 * \param cadena char de caracteres a ser analizada
 * \param longitud entero que marca la longitud de la cadena ingresada.
 * \return Retorna 1 (verdadero) si la cadena es un nombre valido, 0 (falso) si no lo es.
 **/
static int isValidLastName(char* cadena,int longitud)
{

	int i = 0;
	int retorno = 1;
	if (cadena != NULL && longitud > 0) {
		for (i = 0; cadena[i] != '\0' && i < longitud; i++) {
			if ((cadena[i] < 'A' || cadena[i] > 'Z')
					&& (cadena[i] < 'a' || cadena[i] > 'z')
					&& (cadena[i] != ' ')) {
				retorno = 0;
				printf("\nError de validacion, usted ingreso un caracter no permitido.\n");
				break;
			}
		}
	}
	return retorno; //Ok
}

/*
 * \brief valida un DNI
 * \param pResultado: puntero a char donde se guarda el valor a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
static int isValidDni(char* cadena,int longitud)
{
	int i = 0;
	int retorno = 1;
	long lengthCadena = strlen(cadena);
	int contadorPuntos = 0;

	if (cadena != NULL && longitud > 0) {
		for (i = 0; cadena[i] != '\0'; i++) {
			//Menos de 6 numeros->ERROR
			if (lengthCadena < 6) {
				retorno = 0;
				if ((cadena[i] < '0' || cadena[i] > '9')) {
					printf("El DNI no puede contener letras\n");
					break;
				} else {
					printf("El DNI no puede tener menos de 6 numeros\n");
					break;
				}
			}
			//Contador de puntos
			if (cadena[i] == '.') {
				contadorPuntos++;
			}
			//Si comienza con un punto ERROR
			if (i == 0 && cadena[i] == '.') {
				retorno = 0;
				printf("El DNI no puede empezar con un punto\n");
				break;
			}
			//Si contiene letras->ERROR
			if ((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '.')) {
				retorno = 0;
				printf("El DNI no puede contener letras\n");
				break;
			}
		}
	}
	if (contadorPuntos == 0) {
		retorno = 0;
		printf("El DNI debe contener puntos\n");
	} else if (contadorPuntos == 1) {
		retorno = 0;
		printf("El DNI debe contener mas de un punto\n");
	} else if (contadorPuntos > 2) {
		retorno = 0;
		printf("El DNI no puede contener mas de dos puntos\n");
	}
	return retorno; //OK
}

static int isValidId(int idEmployee)
{
	return 1;
}

/**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 **/
static int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[ARRAY_LEN_INT];
    if(pResultado!=NULL &&
    	!getString(bufferString,sizeof(bufferString)) &&
    	esNumerica(bufferString,sizeof(bufferString)))
	{
		*pResultado = atoi(bufferString);
		retorno=0;

	}
    return retorno;
}
