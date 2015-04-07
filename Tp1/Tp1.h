/*
 * Tp1.h
 */

#ifndef TP1_H_
#define TP1_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_TAM 100


/*Imprime la ayuda de parámetros para el trabajo práctico*/
void printHelp();
/*Se chequean los argumentos y en base a eso se imprime lo necesario */
int  checkArguments(int,char*[]);
/*Manejo global de los archivos, por cada uno se llama al método individual*/
int  manejoArchivos();
/*Método para procesamiento de cada archivo, recibe un File Descripto, los argumentos y número de archivo*/
int procesarArchivo(FILE*,char*[],int);
/*Método que procesa la salida de las líneas de los archivos*/
void procesarSalidaArchivo(char**, int,int );

#endif /* TP1_H_ */
