/*
 ============================================================================
 Name        : TP1.c
 Author      : Da silva de souza, Jessica - TP 1 - Division 1H

 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular la suma (A+B)
4. Calcular la resta (A-B)
5. Calcular la division (A/B)
6. Calcular la multiplicacion (A*B)
7. Calcular el factorial (A!)
8. Calcular todas las operaciones
9. Salir

Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las 4 operaciones.

En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)

Deberán contemplarse los casos de error (división por cero, etc)

Documentar todas las funciones
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "Input.h"

int main(void)
{
	setbuf(stdout, NULL); //windows

	int opcion = 0;
	int numero1 = 0;
	int numero2 = 0;
	char salir = 'n';
	int bandera1 = 0;
	int bandera2 = 0;

	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;

	do{
		printf(
		"\n Seleccione su opcion:\n"
		"1. Ingresar primero operando (A=%d)\n"
		"2. Ingresar segundo operando (B=%d)\n"
		"3. Calcula la Suma (%d+%d)\n"
		"4. Calcula la Resta (%d-%d)\n"
		"5. Calcula la Multiplicacion(%d*%d)\n"
		"6. Calcula la Division(%d/%d)\n"
		"7. Calcula el Factorial(!%d)\n"
		"8. Calcula todas las operaciones\n"
		"9. Salir\n\n",numero1, numero2, numero1, numero2, numero1, numero2, numero1, numero2, numero1, numero2, numero1);

		if(getNumEntre(&opcion,"Ingrese opcion: ",1,9) == -1)
		{
			printf("\nError, opcion invalida. ");
		}

	switch(opcion)
	{

	    case 1:
	    	if(getNum(&numero1,"\nIngrese primero numero: ")==0)
	    	{
	    		bandera1 = 1;
	    	}
	    	break;

	    case 2:
	    	if(getNum(&numero2,"\nIngrese segundo numero: ")==0)
	    	{
	    		bandera2 = 1;
	    	}
	    	break;

	    case 3:
	    	if(bandera1 == 1 && bandera2 == 1)
	    	{
	    		if(sumar(numero1,numero2,&resultadoSuma) == -1)
	    		{
	    			printf("\nError en la suma\n");
	    			system("pause");
	    		}
	    		else
	    		{
	    			printf("\nEl resultado de la suma es: %.2f\n",resultadoSuma);
	    			system("pause");
	    		}
	    	}
	    	else
	    	{
	    		printf("\nDebe ingresar ambos numeros antes de realizar la operacion. \n");
	    		system("pause");
	    	}
	    	break;

	    case 4:
	    	if(bandera1 == 1 && bandera2 == 1)
	    	{
	    		if(restar(numero1,numero2,&resultadoResta) == -1)
	    		{
	    			printf("\nError en la resta\n");
	    			system("pause");
	    		}
	    		else
	    		{
	    			printf("\nEl resultado de la resta es: %.2f\n",resultadoResta);
	    			system("pause");
	    		}
	    	}
	    	else
	    	{
	    		  printf("\nDebe ingresar ambos numeros antes de realizar la operacion. \n");
	    		  system("pause");
	    	}
	    	break;

	    case 5:
	    	if(bandera1 == 1 && bandera2 == 1)
	    	{

	    		if(multiplicar(numero1,numero2,&resultadoMultiplicacion) == -1)
	    		{
	    			printf("\nError en la multiplicacion\n");
	    			system("pause");
	    		}
	    		else
	    		{
	    			printf("\nEl resultado de la multiplicacion es: %.2f\n",resultadoMultiplicacion);
	    			system("pause");
	    		}
	    	}
	    	else
	    	{
	    		    printf("\nDebe ingresar ambos numeros antes de realizar la operacion. \n");
	    		    system("pause");
	    	}
	    	break;

	    case 6:
	    	if(bandera1 == 1 && bandera2 == 1)
	    	{
	    		if(dividir(numero1,numero2,&resultadoDivision) == -1)
	    		{
	    			printf("\nError, no se puede dividir por 0\n");
	    			system("pause");
	    		}
	    		else
	    		{
	    			printf("\nEl resultado de la dividion es: %.2f\n",resultadoDivision);
	    			system("pause");
	    		}
	    	}
	        else
	    	{
	    		  printf("\nDebe ingresar ambos numeros antes de realizar la operacion. \n");
	    		  system("pause");
	    	}
	    	break;

	    case 7:
	    	if(bandera1 == 1)
	    	{
	    		printf("\nEl resultado del factorial es: %d\n",factorial(numero1));
	    		system("pause");
	    	}
	    	else
	    	{
	    		printf("\nDebe ingresar numero antes de realizar la operacion. \n");
	    		system("pause");
	    	}
	    	break;

	    case 8:
	    	if(bandera1 == 1 && bandera2 == 1)
	    	{
	    	if(sumar(numero1,numero2,&resultadoSuma) == -1)
	        {
	    		 printf("\nError en la suma\n");
	    		 system("pause");
	    	}
	    	else
	    	{
	    		 printf("\nEl resultado de la suma es: %.2f\n",resultadoSuma);
	    	}

	    	if(restar(numero1,numero2,&resultadoResta) == -1)
	    	{
	    		 printf("\nError en la resta\n");
	    		 system("pause");
	    	}
	    	else
	    	{
	    		 printf("\nEl resultado de la resta es: %.2f\n",resultadoResta);
	    	}
	    	if(multiplicar(numero1,numero2,&resultadoMultiplicacion) == -1)
	    	{
	    		 printf("\nError en la multiplicacion\n");
	    		 system("pause");
	    	}
	    	else
	    	{
	    		 printf("\nEl resultado de la multiplicacion es: %.2f\n",resultadoMultiplicacion);
	    	}
	    	if(dividir(numero1,numero2,&resultadoDivision) == -1)
	    	{
			     printf("\nError, no se puede dividir por 0\n");
	    		 system("pause");
	    	}
	    	else
	    	{
	    		 printf("\nEl resultado de la dividion es: %.2f\n",resultadoDivision);
	    	}

	    	printf("\nEl resultado del factorial es: %d\n",factorial(numero1));
	    	system("pause");
	    	}
	    	else
	    	{
	    		  printf("\nDebe ingresar ambos numeros antes de realizar la operacion. \n");
	    		  system("pause");
	    	}
	    	break;

	    case 9:
	    	printf("\nDesea salir? S/N\n");
	    	fflush(stdin); scanf("%c",&salir);
	    	break;

	}
	}while(salir != 's');

	return EXIT_SUCCESS;

}

