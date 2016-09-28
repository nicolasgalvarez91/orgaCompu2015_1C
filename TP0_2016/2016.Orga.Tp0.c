/*
 ============================================================================
 Name        : Tp0.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Conway Game.
 ============================================================================
 */

#include "2016.Orga.Tp0.h"

int main(int argc, char *argv[]) {
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

		//unsigned char** celdas= inicializarCeldas(filas,columnas);

	}
	return EXIT_SUCCESS;
}
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
void leerDesdeArchivo(unsigned char** celdas, FILE * fp) {
//	FILE *fp;
//	    char fila[5];
//	    char columna[5];
//
//	    fp = fopen(argv[4], "r");
//	    while (fscanf(fp, "%s %s", fila, columna) == 2) {
//	      celdas[atoi(fila)][atoi(columna)] = 1;
//	    }
//	    fclose(fp);

}
void salidaPm() {
//pm_init(argv[0], 0);
//
//    FILE* fp1;
//    fp1 = fopen("hola.pbm", "w");
//
//    pbm_writepbm(fp1, celdas, columnas, filas, 1);
//
//    fclose(fp1);
}
void printMatriz(int filas, int columnas, unsigned char ** celdas) {
	int i,j;
	for (i = 0; i < filas; i++) {
		for ( j = 0; j < columnas; j++) {
			printf("%c ", celdas[i][j]);
		}
		printf("\n");
	}
}

