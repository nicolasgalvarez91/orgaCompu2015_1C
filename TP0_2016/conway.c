#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[] )  {
	//argc = nro de argumentos, 2 significa 1, no se porque
	// argv contiene los argumentos en un array

   if( argc == 5 ) {
   	//printf("The argument supplied is %s\n", argv[1]);
   	//Opcion valida -> 4 argumentos: i, M, N, NombreArchivo

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
   else if( argc > 5 ) {
      printf("Sobran argumentos.\n");
   }
   else {
      printf("Faltan argumentos.\n");
   }
}