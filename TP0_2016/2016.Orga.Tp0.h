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

#include <pnm.h>

const char* help = "Uso:\n"
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

 const char* version= "Conway - Version 1.0\n";

 unsigned char ** inicializarCeldas(int, int);
 void leerDesdeArchivo(unsigned char**, FILE *);
 void printMatriz(int , int , unsigned char ** );

 //Para instalar pnm usar sudo apt-get install libnetpbm10-dev


