/*
 ============================================================================
 Name        : Archivos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
/*
int main(void)
{

	FILE *pFile;
	char bufferString[4444];
	int respuesta;
////////////////////////////////////////////////////
	int i;
	char bufferName[55];
	char bufferLastName[55];
	char bufferLegajo[555];
///////////////////////////////////////////////////

	//ejemplo 1
	pFile = fopen("texto.txt","r");

	if(pFile != NULL)
	{
		for(i=0;i<4;i++)
		{
			respuesta = fprint(pFile,"%s","ABC\n");
		}
	}
	fclose(pFile);

	pFile = fopen("texto.txt","r");

	if(pFile != NULL)
	{
		do{

		respuesta = fscanf(pFile,"%s",bufferString);
		if(respuesta == 1)
		{
			printf("El texto es: \n %\ns",bufferString);
		}
		else
		{
			break;
		}
		}while(1);
	}
	fclose(pFile);

//////////////////////////////////////////////////////////////////////////

	//ejemplo 2
	pFile = fopen("texto.txt","r");

	if(pFile != NULL)
	{
		for (i = 0; i < 4; i++)
		{
			respuesta = fprint(pFile, "%s,%s,%d\n", "AMY","JUAN",i*100);
		}
	}
	fclose(pFile);

	pFile = fopen("texto.txt","r");

	if (pFile != NULL)
	{
		do {

			respuesta = fscanf(pFile, "%[^,],%[^,],%[^\n]\n", bufferName,bufferLastName,bufferLegajo);

			if (respuesta == 3)
			{
				printf("%s - %s - %s\n", bufferName, bufferLastName,bufferLegajo);
			} else {
				break;
			}
		} while (1);
	}
	fclose(pFile);
*/
/////////////////Ernesto
/*
	FILE* pArchivo = fopen("C:\\carpeta\\archivo.txt"); //WINDOWS
	if(pArchivo != NULL)
	{
		//Funciones para leer y escribir

		                        //pasa el puntero a estructura que representa el archivo ---- (pArchivo)
		fclose(pArchivo);      //libera lo que me contruyo de forma dinamica el fopen
	}
*/


	return EXIT_SUCCESS;
}

/////////////////////////////// FUNCIONES ERNESTO - CLASE DIA 5/20/2021////////////////////////////////////

//// Ejemplo lectura binaria de array de empleados /// 1
/*
	FILE* pFile;
	eEmployee* empleados[100];
	eEmployee* pE;
	int i;

	emp_initArray(empleados,100);

	pFile = fopen("archivo.txt","rb");
		if(pFile!=NULL)
		{
			i=0;
			do{
				pE = empleado_new();
				if(fread(pE,sizeof(Empleados),1,pFile)==1)
				{
					empleados[i] = pE;
					i++;
				}
				else
				{
					empleado_delete(pE);
				}
			}while(feof(pFile)==0 && i<100);

		fclose(pFile);

			emp_imprimirLista(empleados,100);
		}
	return EXIT_SUCCESS;
}

//////////////////////////////////// Ejemplo parser (modo texto) /////////////////////////////////////////

int main(void)
{
    FILE* pFile;
	char nombreAux[256];
	char apeAux[256];
	char dniAux[256];
	char idAux[256];
	int flagOnce=0;
	int idEmp;
	Empleado* pE;
	Empleado* empleados[100];
	int indice;
​
	emp_initArray(empleados,100);
​
	pFile = fopen("archivo.txt","r");
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
​
						empleados[indice] = pE;
						indice++;
					}
​
				}
			}
			else
			{
​
			}
			flagOnce=1;
		}
		while(feof(pFile)==0 && indice<100);
​
		fclose(pFile);
​
		emp_imprimirLista(empleados,100);
	}
		return EXIT_SUCCESS;
}

/////////////////////////////////////////////// PARSERS ///////////////////////////////////////////////////////

int main(void)
{
    eEmployee* empleados[100];
	emp_initArray(empleados,100);
	emp_altaForzada(empleados,100);
	em_parser("archivo.txt",empleados,100);
	//MENU ABM

	return EXIT_SUCCESS;

}

//int emp_parser(char nombreArchivo[],Empleado* empleados[],int len) ///////PARSAER FUNCION A PARTE
{
	FILE* pFile;
	char nombreAux[256];
	char apeAux[256];
	char dniAux[256];
	char idAux[256];
	int flagOnce=0;
	int idEmp;
	Empleado* pE;
	int indice=-1;
​
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
​
						empleados[indice] = pE;
						indice++;
					}
​
				}
			}
			else
			{
​
			}
			flagOnce=1;
		}
		while(feof(pFile)==0 && indice<100);
		fclose(pFile);
	}
​
	return indice;
}

///////////////////////////////////// PARSER con buscador de maximo ////////////////////////////////////////////////////

int main(void)
{
    eEmployee* empleados[100];
	int idMaxEncontrado;
	int cant;
	emp_initArray(empleados,100);

	cant = em_parser("archivo.txt",empleados,100,&idMaxEncontrado);
	emp_setearValorInicialDeID(idMaxEncontrado);
    printf("lei %d empleado, idMax:%d\n",cant,idMaxEncontrado);

    //MENU ABM
    SIMULAMOS UN ALTA

    printf("llamo a getId, devolvio:%d",emp_generarId());

	return EXIT_SUCCESS;

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
​
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
​
						empleados[indice] = pE;
​
						// busco maximo
						if(indice==0)
							idMax = idEmp; // me guardo el 1ero como MAX
						else
						{
							if(idEmp>idMax)
								idMax = idEmp;
						}
​
						indice++;
					}
​
				}
			}
			else
			{
​
			}
			flagOnce=1;
		}
		while(feof(pFile)==0 && indice<100);
		fclose(pFile);
​
		*pIdMaxEncontrado = idMax; // lo escribo en la var externa
	}
​
	return indice; // devuelve cantidad leidos
}


///////////////////////////// Serializer (opuesto al parser) modo texto ///////////////////////////////////////////////

int main(void)
{
    eEmployee* empleados[100];
	int idMaxEncontrado;
	int cant;
	emp_initArray(empleados,100);

	cant = em_parser("archivo.txt",empleados,100,&idMaxEncontrado);
	emp_setearValorInicialDeID(idMaxEncontrado);

    printf("lei %d empleado, idMax:%d\n",cant,idMaxEncontrado);

    //MENU ABM

    emp_dump("archivo2.csv",empleados,100);

    emp_printLista(empleados,100);

	return EXIT_SUCCESS;

}
int emp_dump(char nombreArchivo[],Empleado* empleados[], int len)
{
	// serializer
	int ret=-1;
	int i;
	int flagError;
	char* pNombre;
	char* pApellido;
	char* pDni;
	int id;
	FILE* pFile;
​
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
​
				fprintf(pFile,"%s,%s,%s,%d\n",pNombre,pApellido,pDni,id);
			}
		}
		fclose(pFile);
	}
​
	return ret;
​
}







/////////////////////////////////////////

    eEmployee *auxEmployee;
	int flagError;
	auxEmployee = employee_new();

	employee_setName(auxEmployee, "JESS");
	printf("El nombre es: %s", employee_getName(auxEmployee, &flagError));

	eEmployee* empleados[100];

	emp_initArray(empleados,100);
	emp_add(empleados,100);
	emp_printLista(empleados,100);
	emp_altaForzada(empleados,100);
	emp_modificar(empleados,100);
	emp_borrar(empleados,100);


		fprintf(pFile,"%d",i); //imprime texto
		fwrite(&i,sizeof(i),1,pFile); //Crea un archivo vacío para lectura y escritura
		fwrite(emp_printLista,sizeof(eEmployee),5,pFile); //escribe un array

		le en memoria y lo escribe en el archivo
		fwrite(pE,sizeof(eEmployee),1,pFile); //escribe solo 1, pq son independientes no son contiguas,cada una esta en una direccion diferente

		pE = employee_newParam();
	    le en el archivo y lo escribe en memoria
		fread(pE,sizeof(eEmployee),1,pFile);
		printf("%s,%s,%d\n",pE->name,pE->lastName,pE->idEmployee);
