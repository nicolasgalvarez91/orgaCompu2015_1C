/*
 * Vecinos.h
 *
 *  Created on: 28/09/2016
 *      Author: nf
 */
#ifndef VECINOS_H_
#define VECINOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

unsigned int verificarEstado(unsigned int ia, unsigned int ja,unsigned int N, unsigned char *a);
unsigned int RC(unsigned char *a, unsigned int ia, unsigned int j, unsigned int N, unsigned int flag);
unsigned int vecinos(unsigned char* a,unsigned int i, unsigned  int j, unsigned  int M, unsigned  int N);

#endif