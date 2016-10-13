/*
 ============================================================================
 Name        : Vecinos.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Conway Game.
 ============================================================================
 */

#include "Vecinos.h"

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