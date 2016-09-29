/*
 ============================================================================
 Name        : Tp0.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Conway Game.
 ============================================================================
 */

#include "OrgaTp0.h"

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

//Verifica el estado de una posición dada de la matriz.
unsigned int verificarEstado(unsigned int ia, unsigned int ja,unsigned int N, unsigned char *a) {

    unsigned char valor = *(a + ia + ja*N);
    if (valor  == 1)
        return 1;
    return 0;
}

//Recorre por columna los valores de la fila ia
unsigned int RC(unsigned char *a, unsigned int ia, unsigned int j, unsigned int N){
    int s = 0;
    s += verificarEstado(ia, j, N, a);
    if (j == 0)
        s += verificarEstado(ia, j + 1, N, a) + verificarEstado(ia, N - 1, N, a);
    else if (j == N - 1)
        s += verificarEstado(ia, 0, N, a) + verificarEstado(ia, j - 1, N, a);
    else
        s += verificarEstado(ia, j+1, N, a) + verificarEstado(ia, j - 1, N, a);

    return s;
}

unsigned int vecinos(unsigned char *a,unsigned int i, unsigned  int j, unsigned  int M, unsigned  int N) {
    unsigned int s = 0;
    s += RC(a,i, j, N);
    if (i == 0)
        s += RC(a, M - 1, j, N) + RC(a, i + 1, j, N);
    else if (i==M-1)
        s += RC(a, 0, j, N) + RC(a, i - 1, j, N);
    else
        s += RC(a, i+1, j, N) + RC(a, i - 1, j, N);

    return s;
}

