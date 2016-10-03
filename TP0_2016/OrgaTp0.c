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
    
    for (int i = 0; i < tamanioTotal; i++) {
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

void salidaPm(char* nroIteracion, char* progname, int filas, int columnas, unsigned char* celdas) {
    unsigned char** celdasAux = malloc(filas* sizeof(unsigned char*));
    
    for (int i = 0; i < filas; i++) {
        celdasAux[i] = malloc(columnas*sizeof(unsigned char));
    }
    
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            celdasAux[i][j] = celdas[(i*columnas)+j];
        }
    }
    
    pm_init(progname, 0);
    
    /*char* filename = malloc(100 * sizeof(char));
    filename = "estado_";
    strcat(filename, nroIteracion);
    strcat(filename, ".pbm");
    */
    FILE* fp1 = NULL;
    fp1 = fopen("hola.pbm", "w");
    
    if (fp1 != NULL) {
        pbm_writepbm(fp1, celdasAux, columnas, filas, 1);
    } else {
        fprintf(stderr, "Error al abrir el archivo.\n");
    }
    
    fclose(fp1);
    //free(filename);
    for (int i = 0; i < filas; i++) {
        free(celdasAux[i]);
    }
    free(celdasAux);
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

//Verifica el estado de una posición dada de la matriz.
unsigned int verificarEstado(unsigned int ia, unsigned int ja,unsigned int N, unsigned char *a) {
    
    // Cambie esta linea, Nico, pero igual no logro que salga bien el offset.
    // Me base en info de esta pagina: http://eli.thegreenplace.net/2015/memory-layout-of-multi-dimensional-arrays/
    unsigned char valor = a[(ia*N) + ja];
    //unsigned char valor = *(a + ia + ja*N);
    if (valor  == 1)
        return 1;
    return 0;
}

//Recorre por columna los valores de la fila ia
//Flag: 1 si esta en la fila de la celda original, 0 sino. Esto es para evitar que se cuente a si misma en caso de esa celda tener valor 1.
unsigned int RC(unsigned char *a, unsigned int ia, unsigned int j, unsigned int N, unsigned int flag){
    int s = 0;
    if (flag == 0) {
        s += verificarEstado(ia, j, N, a);
    }
    if (j == 0)
        s += verificarEstado(ia, j + 1, N, a) + verificarEstado(ia, N - 1, N, a);
    else if (j == N - 1)
        s += verificarEstado(ia, 0, N, a) + verificarEstado(ia, j - 1, N, a);
    else
        s += verificarEstado(ia, j+1, N, a) + verificarEstado(ia, j - 1, N, a);
    
    return s;
}

unsigned int vecinos(unsigned char* a,unsigned int i, unsigned  int j, unsigned  int M, unsigned  int N) {
    unsigned int s = 0;
    s += RC(a,i, j, N, 1);
    if (i == 0)
        s += RC(a, M - 1, j, N, 0) + RC(a, i + 1, j, N, 0);
    else if (i==M-1)
        s += RC(a, 0, j, N, 0) + RC(a, i - 1, j, N, 0);
    else
        s += RC(a, i+1, j, N, 0) + RC(a, i - 1, j, N, 0);
    
    return s;
}

void conwayStep(unsigned char* celdas, int filas, int columnas) {
    
    // Creo matriz auxiliar de celdas, ya que todas deben actualizarse al mismo tiempo.
    unsigned char* celdasAux;
    celdasAux = malloc((filas*columnas) * sizeof(unsigned char));
    
    // Hago las modificaciones necesarias celda por celda y guardo el resultante en la matriz auxiliar de celdas.
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
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
    for (int m = 0; m < filas; m++) {
        for (int n = 0; n < columnas; n++) {
            celdas[(m*columnas)+n] = celdasAux[(m*columnas)+n];
        }
    }
    
    // Y libero la memoria de la matriz auxiliar de celdas.
    free(celdasAux);
}





