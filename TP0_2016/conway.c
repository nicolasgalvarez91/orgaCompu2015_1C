#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "2016.Orga.Tp0.h"

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

int main( int argc, char *argv[] )  {
  if ((argc == 2)
      && ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0))) {
    printf("%s", help);
  } else if ((argc == 2)
      && ((strcmp(argv[1], "-V") == 0)
          || (strcmp(argv[1], "--version") == 0))) {
    printf("%s", version);
  } else if (argc == 5) {
    int filas = atoi(argv[2]);
    int columnas = atoi(argv[3]);

    printf("Filas: %d\n", filas);
    printf("Columnas: %d\n", columnas);

    unsigned char** celdas = inicializarCeldas(filas,columnas);

    leerDesdeArchivo(celdas, argv[4]);
      
    salidaPm(argv[0], filas, columnas, celdas);

    printMatriz(filas, columnas, celdas);

  }
  return EXIT_SUCCESS;    
}