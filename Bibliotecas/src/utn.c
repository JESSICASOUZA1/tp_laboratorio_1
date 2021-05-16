/*
 * utn.c
 *
 *  Created on: Apr 29, 2021
 *      Author: jessi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
//#include "arrayProducto.h"
//#include "persona.h"

/////////Funciones Estaticas////////////

static int getFloat(float* pResultado);
static int esFlotante(char* pCadena);
static int esNumerico(char* pCadena);
static int myGets(char* cadena,int longitud);
static int getIntCompleta(int* pResultado);

static int getFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[64];

    if(pResultado != NULL)
    {
    	if(myGets(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
    		*pResultado = atof(buffer);
    		 retorno = 0;
    	}

    }
	return retorno;
}

static int esFlotante(char* pCadena)
{
	int i =0;
	int retorno = 1;
	int contadorPuntos = 0;

	if (pCadena != NULL && strlen(pCadena) > 0) {
		for (i = 0; pCadena[i] != '\0'; i++)
		{
			if (i == 0 && (pCadena[i] == '-' || pCadena[i] == '+'))
			{
				continue;
			}
			if (pCadena[i] < '0' || pCadena[i] > '9') {
				if (pCadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;                                           //se entra es porque estaria contanto por primera vez 1 punto.
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

static int esNumerico(char* pCadena)
{
	int i =0;
	int retorno = 1;                                                                                              //error

	if(pCadena[0] == '-')
	{
		i = 1;
	}
	for (; pCadena[i] != '\0'; i++)
	{
		if (pCadena[i] > '9' || pCadena[i] < '0')                                                            //validar que sean solo numeros
		{
			retorno = 0;
			break;                                                                                         //si no es break
		}
	}

	return retorno;
}

static int myGets(char* cadena,int longitud)
{
	int retorno = -1;
	char bufferString[53464];   ////Melhorar

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);

		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
		    {
		    	bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
		    }
		    if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
		    {
		    	strncpy(cadena,bufferString,longitud);
		    	retorno = 0;                                                                    //devuelve cero se esta todo bien, si no -1
		    }
	    }
	}

	return retorno;
}

static int getIntCompleta(int* pResultado)
{
	int retorno = -1;
	char bufferString[5647];

	//fflush(stdin);

	if(pResultado != NULL && myGets(bufferString,sizeof(bufferString)) == 0 && esNumerico(bufferString))
		{
			*pResultado = atoi(bufferString);
			retorno = 0;
		}
	return retorno;
}

/////////////GET////////////

/**
 * \brief Solicita un numero flotante al usuario y luego de verificarlo devuelve el resultado
 * \param pResultado puntero al espacio de memoria donde se dejara el resultado
 * \param pMensaje Es el mensaje a ser mostrado,
 * \param pMensaje error se hubo algun error
 * \param minimo es el numero minimo a ser aceptado
 * \param maximo es el numero maximo a ser aceptado
 * \param reintentos a ser aceptado
 * \return retorna 0 si se obtuvo el numero flotante y -1 si no
 */
int getNumeroFloat(float* pResultado,char* pMensaje,char* pMensajeError,float min,float max,int reintentos)
{
	int retorno = -1;
	float buffer;

	if (pResultado != NULL && pMensaje != NULL && pMensajeError != NULL) {
		while (reintentos >= 0) {
			printf(pMensaje);

			if (getFloat(&buffer) == 0) {
				if (buffer >= min && buffer <= max)
				{
					*pResultado = buffer;
					retorno = 0;
					break;
				}

				fflush(stdin);
				printf(pMensajeError);
				reintentos--;

			}
		}
	}

	return retorno;
}

/**
 * \brief Solicita numero al usuario y lo devuelve
 * \param pMensaje es el mensaje a ser mostrado
 * \return retorna el numero
 */
int getNum(int* numero,char* pMensaje)
{
	int ret = -1;
	int num;
	printf(pMensaje); fflush(stdin);
	if( scanf("%d",&num) == 1)
	{
	*numero = num;
	ret = 0;
	}
	return ret;
}


int getNumeroCompleto(int* pResultado,char* pMensaje,char* pMensajeError,int min, int max,int reintentos)
{
	int retorno = -1;
	int buffer;

	if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && min <= max && reintentos >= 0)
	{
		do
		{
			printf("%s",pMensaje);
			if(getIntCompleta(&buffer) == 0 && buffer >= min && buffer <= max)
			{
				retorno = 0;
				*pResultado = buffer;
				break;
		     }
			reintentos--;
			printf("%s", pMensajeError);
		} while (reintentos >= 0);
	}
	return retorno;
}


char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}



int getString(char* input,char* mensaje,char* mensajeError,int min,int max,int reintentos)
{
    char nombre[51];
    char aux[2565];
    int retorno=-1;
    int contReintentos=0;

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        gets(aux);
        if(valCharacter(aux,256) == -1)
        {
        	contReintentos++;
            printf("%s",mensajeError);
        }
        else
        {
            if(strlen(aux) < min || strlen(aux) > max)
            {
                printf("%s",mensajeError);
                contReintentos++;
            }
            else
            {
                strcpy(nombre,aux);
                strcpy(input,nombre);
                retorno=0;
                break;
            }
        }

        if(contReintentos==reintentos)
        {
        	retorno=-1;
            printf("\nMaxima cantidad de intentos alcanzada.\n");
            system("pause");
        }

    }while(contReintentos!=reintentos);

    return retorno;

}

int valCharacter(char* string,int max)
{
    int retorno=-1;

    if(string != NULL && max > 0 )
    {

        for(int i=0; i<max && string[i]!='\0'; i++)
        {
            if((string[i]<'a' || string[i]>'z') && (string[i]<' '|| string[i]>' ') && (string[i]<'A' || string[i]>'Z') )
            {
                break;
            }
            else
            {
                retorno=0;
            }
        }
    }

    return retorno;
}


float getFloatt(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        return 0;
        i++;
    }
    return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y numeros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y n�meros, y 0 si no lo es
 */
int esAlfaNumerico(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
        return 0;
        i++;
    }
    return 1;
}

/*
void stringToUpper(char caracter[])
{
    int i;
    int largo;
    caracter[0]=toupper(caracter[0]);
    largo=strlen(caracter);
    for(i=0;i<largo;i++)
    {
        if(caracter[i]==' ')
        {
            i=i+1;
            caracter[i]=toupper(caracter[i]);
        }
    }
    return caracter;
}

///////
 *
 *
 *
 *
 *
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar el texto ingresado
 * \return 1 si el texto contiene solo letras
 *
 * int getStringLetras(char mensaje[], char input[])
{
    char auxiliar[256];
    getSString(mensaje, auxiliar);
    if(esSoloLetras(auxiliar))
    {
        strcpy(input, auxiliar);
        return 1;
    }

    return 0;
}


 * \brief Solicita un texto numerico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar el texto ingresado
 * \return 1 si el texto contiene solo numeros
 *
int getStringNumeros(char mensaje[], char input[])
{
    char auxiliar[256];
    getSString(mensaje, auxiliar);
    if(esNumerico(auxiliar))
    {
        strcpy(input, auxiliar);
        return 1;
    }

    return 0;
}



 * \brief Solicita un texto numerico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar el texto ingresado
 * \return 1 si el texto contiene solo numeros
 *
int getAlfaNumerico(char mensaje[], char input[])
{
    char auxiliar[256];
    getSString(mensaje, auxiliar);
    if(esAlfaNumerico(auxiliar))
    {
        strcpy(input,auxiliar);
        return 1;
    }
    return 0;
}


*/

