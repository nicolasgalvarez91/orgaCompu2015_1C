#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main( int argc, char *argv[] )  {
	//argc = nro de argumentos, 2 significa 1, no se porque
	// argv contiene los argumentos en un array

   int c;

   char* help = "Uso:\n"
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


   if ((argc == 2)
         && ((strcmp(argv[1], "-h") == 0)
               || (strcmp(argv[1], "--help") == 0))) {
      printf("%s", help);
   } else if ((argc == 2)
         && ((strcmp(argv[1], "-V") == 0)
               || (strcmp(argv[1], "--version") == 0))) {
      printf("Conway - Version 1.0\n");
   } else if (argc == 5) {
   	int filas = atoi(argv[2]);
   	int columnas = atoi(argv[3]);	

   	printf("Filas: %d\n", filas);
   	printf("Columnas: %d\n", columnas);

   	int** celdas;
   	celdas = malloc( filas * sizeof(int*) );

   	for (int i = 0; i<filas; i++) {
   		celdas[i] = malloc( columnas * sizeof(int) );
   	}

   	for (int i = 0; i<filas; i++) {
   		for (int j = 0; j<columnas; j++) {
   			celdas[i][j] = 0;
   		}
   	}

  	   FILE *fp;
   	char fila[5];
   	char columna[5];

   	fp = fopen(argv[4], "r");
   	while (fscanf(fp, "%s %s", fila, columna) == 2) {
   		celdas[atoi(fila)][atoi(columna)] = 1;
   	}
   	fclose(fp);

   	for (int i = 0; i<filas; i++) {
   		for (int j = 0; j<columnas; j++) {
      		printf("%d ", celdas[i][j]);
      	}
      	printf("\n");
      }   	
   }
}