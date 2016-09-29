/*
 ============================================================================
 Name        : Tp0.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Conway Game.
 ============================================================================
 */

#include "funciones.h"

unsigned char** inicializarCeldas(int cantFilas, int cantColumnas) {

	unsigned char ** celdas;
	celdas = malloc(cantFilas * sizeof(unsigned char*));

	int i = 0, j = 0;
	for (i = 0; i < cantFilas; i++) {
		celdas[i] = malloc(cantColumnas * sizeof(unsigned char));
	}

	for (i = 0; i < cantFilas; i++) {
		for (j = 0; j < cantFilas; j++) {
			celdas[i][j] = 0;
		}
	}

	return celdas;
}

void leerDesdeArchivo(unsigned char** celdas, char* filename) {
	  FILE *fp;
	  char fila[5];
	  char columna[5];

	  fp = fopen(filename, "r");
	  while (fscanf(fp, "%s %s", fila, columna) == 2) {
	    celdas[atoi(fila)][atoi(columna)] = 1;
	  }
	  fclose(fp);
}

void salidaPm(char* progname, int filas, int columnas, unsigned char** celdas) {
    pm_init(progname, 0);

    FILE* fp1;
    fp1 = fopen("hola.pbm", "w");

    pbm_writepbm(fp1, celdas, columnas, filas, 1);

    fclose(fp1);
}

void printMatriz(int filas, int columnas, unsigned char ** celdas) {
	int i,j;
	for (i = 0; i < filas; i++) {
		for ( j = 0; j < columnas; j++) {
			printf("%u ", celdas[i][j]);
		}
		printf("\n");
	}
}