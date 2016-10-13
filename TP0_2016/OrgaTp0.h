/*
 * 2016.Orga.Tp0.h
 *
 *  Created on: 28/09/2016
 *      Author: nf
 */
#ifndef ORGATP0_H_
#define ORGATP0_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pbm.h>
#include "Vecinos.h"

static const char* help = "Uso:\n"
    "\tconway -h\n"
    "\tconway -V\n"
    "\tconway i M N inputfile [-o outputprefix]\n"
    "Opciones:\n"
    "\t-h, --help\tImprime este mensaje.\n"
    "\t-V, --version\tDa la version del programa.\n"
    "\t-o Prefijo de los archivos de salida.\n"
    "Ejemplos:\n"
    "\tconway 10 20 20 glider -o estado\n"
    "\tRepresenta 10 iteraciones del Juego de la Vida en una matriz de 20x20,\n"
    "\tcon un estado inicial tomado del archivo glider.\n"
    "\tLos archivos de salida se llamaran estado_n.pbm.\n"
    "\tSi no se da un prefijo para los archivos de salida,\n"
    "\tel prefijo sera el nombre del archivo de entrada.\n";

static const char* version= "Conway - Version 1.0\n";

unsigned char * inicializarCeldas(int, int);
void leerDesdeArchivo(unsigned char*, char*, int);
void salidaPm(char* nroIteracion, char* progname, int filas, int columnas, unsigned char* celdas, char* prefix);
void printMatriz(int nroIteracion, int , int , unsigned char * );
void conwayStep(unsigned char* celdas, int filas, int columnas);

#endif

