/*
 * 2016.Orga.Tp0.h
 *
 *  Created on: 28/09/2016
 *      Author: nf
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//#include <pnm.h>
#include <netpbm/pbm.h>

unsigned char ** inicializarCeldas(int, int);
void leerDesdeArchivo(unsigned char**, char*);
void salidaPm(char* progname, int filas, int columnas, unsigned char** celdas);
void printMatriz(int , int , unsigned char ** );

//Para instalar pnm usar sudo apt-get install libnetpbm10-dev


