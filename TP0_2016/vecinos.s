#	Tp1 2do cuatrimestre 2016
#	Funcion:
#	int vecinos (unsigned char *a, unsigned int i, unsigned int j, unsigned int M, unsigned int N);
#
################
# Stack frame: #
################
# 48 ------------
#	PADDING
# 44 ------------
#	ra
# 40 ------------
#	fp
# 36 ------------
#	gp
# 32 ------------
#	PADDING
# 28 ------------
#	PADDING
# 24 ------------
#	PADDING
# 20 ------------
#	A4
# 16 ------------
#	A3
# 12 ------------
#	A2
# 8 ------------
#	A1
# 4 ------------
#	A0
# 0 ------------
#
#
################################
# Detalle de registros usados: #
################################
#	a0: parametro unsigned char *a
#	a1: parametro unsigned int i
#	a2: parametro unsigned int j
#	a3: parametro unsigned int M
#	a4: parametro unsigned int N
#	t0: variable local s
#	t1: 
#	t2: 
#	t3: 
#
#	t6: temporal usada para calculos
#	t7: temporal usada para calculos
#	t8: temporal usada para calculos
#	t9: temporal usada para calculos
#
#define SF_SIZE 	48
#define RA		40
#define FP		36
#define GP		32
#define A4 		16
#define A3 		12
#define A2 		8
#define A1		4
#define A0		0
#
#include <mips/regdef.h>
#include <sys/syscall.h>
#
		.text   		#comienzo del código
		.align 2		#alineacion 2^2
		
		.set noreorder
		.cpload t9
		.set reorder
		
		.globl validate 	#funcion publica
		.ent validate		#punto de entrada de la funcion

vecinos:
		subu 	sp, sp, SF_SIZE		# creo stack frame
		sw 	$fp, FP(sp)		# guardo valor de fp
		sw 	gp, GP(sp)		# guardo valor de gp
		sw 	ra, RA(sp)		# guardo valor de ra
		move 	$fp, sp

		sw 	a0, A0(sp)		
		sw 	a1, A1(sp)		
		sw 	a2, A2(sp)	
		sw 	a3, A3(sp)
		sw 	a4, A4(sp)		#IMPORTANTE VER DE DONDE VIENE EL QUINTO PARAMETRO

		addiu s0,zero,0

		lw 	a0, A0(sp)		
		lw 	a1, A1(sp)		
		lw 	a2, A2(sp)	
		lw 	a3, A3(sp)
		addiu 	a4, zero,1		#IMPORTANTE VER DE DONDE VIENE EL QUINTO PARAMETRO

		la t0, RC

		jal t0

		addiu s0,s0,v0		#Agrego el resultado al valor de retorno
		lw t0, A1(sp) 		#Cargo i para hacer la verificacion

		beq t0,zero,primeraFila 	#Si se esta calculando el vecino de la primera fila

		lw t1, A3(sp)
		addiu t2,zero,1
		subu t1,t1,t2		#Guardo en t1 M-1

		beq t0,t1,ultimaFila	#Si se esta calculando el vecino de la ultima fila

#Es una fila intermedia

		lw 	a0, A0(sp)

		lw 	a1, A1(sp)
		addiu t2,zero,1
		addiu a1,a1,t2 		#Guardo en a1 i+1
		lw 	a2, A2(sp)		#Cargo en a2 j
		lw 	a3, A5(sp)		#Cargo en a3 N
							#IMPORTANTE VER DE DONDE VIENE EL QUINTO PARAMETRO
		addiu a4,zero,0     #Cargo en a4 el flag 0	

		la t0, RC

		jal t0

		addiu s0,s0,v0		#Sumo el resultado que va a ser retornado

		lw 	a0, A0(sp)

		lw 	a1, A1(sp)
		addiu t2,zero,1
		sub a1,a1,t2 		#Guardo en a1 i-1
		lw 	a2, A2(sp)		#Cargo en a2 j
		lw 	a3, A5(sp)		#Cargo en a3 N
							#IMPORTANTE VER DE DONDE VIENE EL QUINTO PARAMETRO
		addiu a4,zero,0     #Cargo en a4 el flag 0

		la t0, RC

		jal t0

		addiu s0,s0,v0

fin:

		mov v0,s0		#Cargo en v0 el valor a retornar
						#Restauro el stack y termino la funcion vecinos

		lw $fp,FP(sp)
		lw gp,GP(sp)
		lw ra,RA(sp)
						#Ver si hay que cargar los parametros de nuevo
		jr ra


primeraFila:

		lw 	a0, A0(sp)

		lw 	a1, A3(sp)
		addiu t2,zero,1
		subu a1,a1,t2 		#Guardo en a1 M-1
		lw 	a2, A2(sp)		#Cargo en a2 j
		lw 	a3, A5(sp)		#Cargo en a3 N
							#IMPORTANTE VER DE DONDE VIENE EL QUINTO PARAMETRO
		addiu a4,zero,0     #Cargo en a4 el flag 0	

		la t0, RC

		jal t0

		addiu s0,s0,v0		#Sumo el resultado que va a ser retornado

		lw 	a0, A0(sp)

		lw 	a1, A1(sp)
		addiu t2,zero,1
		addiu a1,a1,t2 		#Guardo en a1 i+1
		lw 	a2, A2(sp)		#Cargo en a2 j
		lw 	a3, A5(sp)		#Cargo en a3 N
							#IMPORTANTE VER DE DONDE VIENE EL QUINTO PARAMETRO
		addiu a4,zero,0     #Cargo en a4 el flag 0

		la t0, RC

		jal t0

		addiu s0,s0,v0

		b fin

ultimaFila:

		lw 	a0, A0(sp)

		lw 	a1, A1(sp)
		addiu a1,zero,0		#Guardo en a1 0
		lw 	a2, A2(sp)		#Cargo en a2 j
		lw 	a3, A5(sp)		#Cargo en a3 N
							#IMPORTANTE VER DE DONDE VIENE EL QUINTO PARAMETRO
		addiu a4,zero,0     #Cargo en a4 el flag 0	

		la t0, RC

		jal t0

		addiu s0,s0,v0		#Sumo el resultado que va a ser retornado

		lw 	a0, A0(sp)

		lw 	a1, A1(sp)
		addiu t2,zero,1
		sub a1,a1,t2 		#Guardo en a1 i-1
		lw 	a2, A2(sp)		#Cargo en a2 j
		lw 	a3, A5(sp)		#Cargo en a3 N
							#IMPORTANTE VER DE DONDE VIENE EL QUINTO PARAMETRO
		addiu a4,zero,0     #Cargo en a4 el flag 0

		la t0, RC

		jal t0

		addiu s0,s0,v0

		b fin
		

RC:

