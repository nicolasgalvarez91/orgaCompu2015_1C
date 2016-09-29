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
    FILE *fp = NULL;
    char fila[5];
    char columna[5];
    
    fp = fopen(filename, "r");
    
    if (fp != NULL) {
        while (fscanf(fp, "%s %s", fila, columna) == 2) {
            celdas[atoi(fila)][atoi(columna)] = 1;
        }
    } else {
        fprintf(stderr, "Error al abrir el archivo.\n");
    }
    fclose(fp);
}

void salidaPm(char* nroIteracion, char* progname, int filas, int columnas, unsigned char** celdas) {
    pm_init(progname, 0);
    
    /*char* filename = malloc(100 * sizeof(char));
    filename = "estado_";
    strcat(filename, nroIteracion);
    strcat(filename, ".pbm");
    */
    FILE* fp1 = NULL;
    fp1 = fopen("hola.pbm", "w");
    
    if (fp1 != NULL) {
        pbm_writepbm(fp1, celdas, columnas, filas, 1);
    } else {
        fprintf(stderr, "Error al abrir el archivo.\n");
    }
    
    fclose(fp1);
    //free(filename);
}



void printMatriz(int nroIteracion, int filas, int columnas, unsigned char ** celdas) {
    int i,j;
    printf("Iteracion numero: %d\n", nroIteracion);
    for (i = 0; i < filas; i++) {
        for ( j = 0; j < columnas; j++) {
            printf("%u ", celdas[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//Verifica el estado de una posición dada de la matriz.
unsigned int verificarEstado(unsigned int ia, unsigned int ja,unsigned int N, unsigned char *a) {
    
    // Cambie esta linea, Nico, pero igual no logro que salga bien el offset.
    // Me base en info de esta pagina: http://eli.thegreenplace.net/2015/memory-layout-of-multi-dimensional-arrays/
    unsigned char valor = *(a + ia*N + ja);
    //unsigned char valor = *(a + ia + ja*N);
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

void conwayStep(unsigned char** celdas, int filas, int columnas) {
    
    // Creo matriz auxiliar de celdas, ya que todas deben actualizarse al mismo tiempo.
    unsigned char ** celdasAux;
    celdasAux = malloc(filas * sizeof(unsigned char*));
    
    for (int m = 0; m < filas; m++) {
        celdasAux[m] = malloc(columnas * sizeof(unsigned char));
    }
    
    // Hago las modificaciones necesarias celda por celda y guardo el resultante en la matriz auxiliar de celdas.
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            vecinos(&celdas[0][0], i, j, filas, columnas);
            printf("Pos: %d,%d = %d\n", i, j,vecinos(celdas[0], i, j, filas, columnas));
            if (vecinos(celdas[0], i, j, filas, columnas) < 2 || vecinos(celdas[0], i, j, filas, columnas) > 3) {
                celdasAux[i][j] = 0;
            } else if (celdas[i][j] == 1 && (vecinos(celdas[0], i, j, filas, columnas) == 2 || vecinos(celdas[0], i, j, filas, columnas) == 3 )) {
                celdasAux[i][j] = 1;
            } else if (celdas[i][j] == 0 && vecinos(celdas[0], i, j, filas, columnas) == 3) {
                celdasAux[i][j] = 1;
            } else {
                celdasAux[i][j] = celdas[i][j];
            }
        }
    }
    
    // Por ultimo, asigno todos los valores de la auxiliar a la original.
    for (int m = 0; m < filas; m++) {
        for (int n = 0; n < columnas; n++) {
            celdas[m][n] = celdasAux[m][n];
        }
    }
    
    // Y libero la memoria de la matriz auxiliar de celdas.
    for (int m = 0; m < filas; m++) {
        free(celdasAux[m]);
    }
    free(celdasAux);
}





