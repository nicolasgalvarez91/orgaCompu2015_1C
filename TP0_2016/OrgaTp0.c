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

unsigned char* inicializarCeldas(int cantFilas, int cantColumnas) {
    
    int tamanioTotal = cantFilas * cantColumnas;
    
    unsigned char * celdas;
    celdas = malloc(tamanioTotal * sizeof(unsigned char));
    int i;
    for (i = 0; i < tamanioTotal; i++) {
        celdas[i] = 0;
    }
    
    return celdas;
}

void leerDesdeArchivo(unsigned char* celdas, char* filename, int cantColumnas) {
    FILE *fp = NULL;
    char fila[5];
    char columna[5];
    
    fp = fopen(filename, "r");
    
    if (fp != NULL) {
        while (fscanf(fp, "%s %s", fila, columna) == 2) {
            celdas[(atoi(fila)*cantColumnas)+atoi(columna)] = 1;
        }
    } else {
        fprintf(stderr, "Error al abrir el archivo.\n");
    }
    fclose(fp);
}

void salidaPm(char* nroIteracion, char* progname, int filas, int columnas, unsigned char* celdas, char* prefix) {
    char** celdasAux = malloc(filas* sizeof(unsigned char*));
    int i;
    for (i = 0; i < filas; i++) {
        celdasAux[i] = malloc(columnas*sizeof(char));
    }
    
    for (i = 0; i < filas; i++) {
	int j;
        for (j = 0; j < columnas; j++) {
            if (((int)celdas[(i*columnas)+j]) == 1) {
                celdasAux[i][j] = '0';
            } else {
                celdasAux[i][j] = '1';
            }
        }
    }
    
    //pm_init(progname, 0);
    
    char* filename = malloc(1000*sizeof(char));
    strcat(filename, prefix);
    strcat(filename, "_");
    strcat(filename, nroIteracion);
    strcat(filename, ".pbm");
    
    FILE* fp1 = NULL;
    fp1 = fopen(filename, "w");
    
    if (fp1 != NULL) {
        //pbm_writepbm(fp1, celdasAux, columnas, filas, 1);
        fprintf(fp1, "P1\n");
        fprintf(fp1, "%d %d\n", filas, columnas);
	    int i;
        for (i = 0; i < filas; i++) {
            fprintf(fp1, "%s\n", celdasAux[i]);
        }
    } else {
        fprintf(stderr, "Error al abrir el archivo.\n");
    }
    
    fclose(fp1);
    for (i = 0; i < filas; i++) {
        free(celdasAux[i]);
    }
    free(celdasAux);
    free(filename);
}

void printMatriz(int nroIteracion, int filas, int columnas, unsigned char* celdas) {
    int i,j;
    printf("Iteracion numero: %d\n", nroIteracion);
    for (i = 0; i < filas; i++) {
        for ( j = 0; j < columnas; j++) {
            printf("%u ", celdas[(i*columnas)+j]);
        }
        printf("\n");
    }
    printf("\n");
}


void conwayStep(unsigned char* celdas, int filas, int columnas) {
    
    // Creo matriz auxiliar de celdas, ya que todas deben actualizarse al mismo tiempo.
    unsigned char* celdasAux;
    celdasAux = malloc((filas*columnas) * sizeof(unsigned char));
    
    // Hago las modificaciones necesarias celda por celda y guardo el resultante en la matriz auxiliar de celdas.
    int i,j;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            //printf("Pos: %d,%d = %d\n", i, j,vecinos(celdas, i, j, filas, columnas));
            if (vecinos(celdas, i, j, filas, columnas) < 2 || vecinos(celdas, i, j, filas, columnas) > 3) {
                celdasAux[(i*columnas)+j] = 0;
            } else if (celdas[(i*columnas)+j] == 1 && (vecinos(celdas, i, j, filas, columnas) == 2 || vecinos(celdas, i, j, filas, columnas) == 3 )) {
                celdasAux[(i*columnas)+j] = 1;
            } else if (celdas[(i*columnas)+j] == 0 && vecinos(celdas, i, j, filas, columnas) == 3) {
                celdasAux[(i*columnas)+j] = 1;
            } else {
                celdasAux[(i*columnas)+j] = celdas[(i*columnas)+j];
            }
        }
    }
    
    // Por ultimo, asigno todos los valores de la auxiliar a la original.
    int m,n;
    for (m = 0; m < filas; m++) {
        for (n = 0; n < columnas; n++) {
            celdas[(m*columnas)+n] = celdasAux[(m*columnas)+n];
        }
    }
    
    // Y libero la memoria de la matriz auxiliar de celdas.
    free(celdasAux);
}





