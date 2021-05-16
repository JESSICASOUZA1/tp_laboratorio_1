/*
 * utn.h
 *
 *  Created on: Apr 29, 2021
 *      Author: jessi
 */

#ifndef UTN_H_
#define UTN_H_

int getNum(int* numero,char* pMensaje);
int getNumEntre(int* pNumero,char* pMensaje,int min,int max);
char getNumeroAleatorio(int desde ,int hasta,int iniciar);
int factorial(int numero);
int getString(char* input,char* mensaje,char* mensajeError,int min,int max,int reintentos);
int getNumeroCompleto(int* pResultado,char* pMensaje,char* pMensajeError,int min, int max,int reintentos);
int getNumeroFloat(float* pResultado,char* pMensaje,char* pMensajeError,float min,float max,int reintentos);
void getSString(char mensaje[], char input[]);
int esSoloLetras(char str[]);
int esAlfaNumerico(char str[]);
int getStringLetras(char mensaje[], char input[]);
int getStringNumeros(char mensaje[], char input[]);
int getAlfaNumerico(char mensaje[], char input[]);
int isValidEdad(char* nombre);
int isValidMail(char* nombre);
int isValidDireccion(char* nombre);
int isValidCreditCard(char* nombre);
int getEdad(int* pResultado,char* mensaje,char* mensajeError,int reintentos);
int valCharacter(char* string,int max);
char get_Char(char mensaje[]);
float getFloatt(char mensaje[]);


#endif /* UTN_H_ */
