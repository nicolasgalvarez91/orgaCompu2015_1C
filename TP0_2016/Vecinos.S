#	Tp0 2do cuatrimestre 2016
#	Funcion:
#	unsigned int vecinos (unsigned char *a, unsigned int i, unsigned int j, unsigned int M, unsigned int N);
#
# Stack frame: #
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
#	S0
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
#
#define SF_SIZE 	48
#define RA		40
#define FP		36
#define GP		32
#define S0		20
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
		
		.globl vecinos 	#funcion publica
		.ent vecinos		#punto de entrada de la funcion

vecinos:
		subu 	sp, sp, SF_SIZE		# creo stack frame
		sw 	$fp, FP(sp)		# guardo valor de fp
		sw 	gp, GP(sp)		# guardo valor de gp
		sw 	ra, RA(sp)		# guardo valor de ra
		sw	s0,	S0(sp)
		move 	$fp, sp

							#Preparo el stack para llamar a RC(a,i,j,N,1)
		lw 	a0, 48(sp)		#Cargo a
		lw 	a1, 52(sp)		#Cargo i
		lw 	a2, 56(sp)		#Cargo j
		lw 	a3, 64(sp)		#Cargo N
		addiu t1, zero,1

		sw 	a0, A0(sp)		
		sw 	a1, A1(sp)		
		sw 	a2, A2(sp)	
		sw 	a3, A3(sp)
		sw 	t1, A4(sp)
				

		addiu s0,zero,0
		

		la t0, RC

		jal t0

		addu s0,s0,v0		#Agrego el resultado al valor de retorno
		lw t0, 52(sp) 		#Cargo i para hacer la verificacion

		beq t0,zero,primeraFila 	#Si se esta calculando el vecino de la primera fila

		lw t1, 60(sp)
		addiu t2,zero,1
		subu t1,t1,t2		#Guardo en t1 M-1

		beq t0,t1,ultimaFila	#Si se esta calculando el vecino de la ultima fila

#Es una fila intermedia

		lw 	a0, 48(sp)

		lw 	a1, 52(sp)
		addiu t2,zero,1
		addu a1,a1,t2 		#Guardo en a1 i+1
		lw 	a2, 56(sp)		#Cargo en a2 j
		lw 	a3, 64(sp)		#Cargo en a3 N
							#IMPORTANTE VER DE DONDE VIENE EL QUINTO PARAMETRO
		addiu t1,zero,0     #Cargo en a4 el flag 0	

		sw 	a0, A0(sp)		#Preparo el stack para llamar a RC
		sw 	a1, A1(sp)		
		sw 	a2, A2(sp)	
		sw 	a3, A3(sp)
		sw 	t1, A4(sp)

		la t0, RC

		jal t0

		addu s0,s0,v0		#Sumo el resultado que va a ser retornado

		lw 	a0, 48(sp)

		lw 	a1, 52(sp)
		addiu t2,zero,1
		sub a1,a1,t2 		#Guardo en a1 i-1
		lw 	a2, 56(sp)		#Cargo en a2 j
		lw 	a3, 64(sp)		#Cargo en a3 N
							#IMPORTANTE VER DE DONDE VIENE EL QUINTO PARAMETRO
		addiu t1,zero,0     #Cargo en a4 el flag 0

		sw 	a0, A0(sp)		#Preparo el stack para llamar a RC
		sw 	a1, A1(sp)		
		sw 	a2, A2(sp)	
		sw 	a3, A3(sp)
		sw 	t1, A4(sp)

		la t0, RC

		jal t0

		addu s0,s0,v0

fin:

		move v0,s0		#Cargo en v0 el valor a retornar
						#Restauro el stack y termino la funcion vecinos

		lw $fp,FP(sp)
		lw gp,GP(sp)
		lw ra,RA(sp)
		lw s0,S0(sp)
		addu sp,sp,SF_SIZE

		jr ra

.end vecinos


primeraFila:

		lw 	a0, 48(sp)

		lw 	a1, 60(sp)
		addiu t2,zero,1
		subu a1,a1,t2 		#Guardo en a1 M-1
		lw 	a2, 56(sp)		#Cargo en a2 j
		lw 	a3, 64(sp)		#Cargo en a3 N
							
		addiu t1,zero,0     #Cargo en a4 el flag 0	

		sw 	a0, A0(sp)		#Preparo el stack para llamar a RC
		sw 	a1, A1(sp)		
		sw 	a2, A2(sp)	
		sw 	a3, A3(sp)
		sw 	t1, A4(sp)

		la t0, RC

		jal t0

		addu s0,s0,v0		#Sumo el resultado que va a ser retornado

		lw 	a0, 48(sp)

		lw 	a1, 52(sp)
		addiu t2,zero,1
		addu a1,a1,t2 		#Guardo en a1 i+1
		lw 	a2, 56(sp)		#Cargo en a2 j
		lw 	a3, 64(sp)		#Cargo en a3 N
							
		addiu t1,zero,0     #Cargo en a4 el flag 0

		sw 	a0, A0(sp)		#Preparo el stack para llamar a RC
		sw 	a1, A1(sp)		
		sw 	a2, A2(sp)	
		sw 	a3, A3(sp)
		sw 	t1, A4(sp)

		la t0, RC

		jal t0

		addu s0,s0,v0

		b fin

ultimaFila:

		lw 	a0, 48(sp)
		addiu a1,zero,0		#Guardo en a1 0
		lw 	a2, 56(sp)		#Cargo en a2 j
		lw 	a3, 64(sp)		#Cargo en a3 N
		addiu t1,zero,0     #Cargo en a4 el flag 0	

		sw 	a0, A0(sp)		#Preparo el stack para llamar a RC
		sw 	a1, A1(sp)		
		sw 	a2, A2(sp)	
		sw 	a3, A3(sp)
		sw 	t1, A4(sp)

		la t0, RC

		jal t0

		addu s0,s0,v0		#Sumo el resultado que va a ser retornado

		lw 	a0, 48(sp)
		lw 	a1, 52(sp)
		addiu t2,zero,1
		sub a1,a1,t2 		#Guardo en a1 i-1
		lw 	a2, 56(sp)		#Cargo en a2 j
		lw 	a3, 64(sp)		#Cargo en a3 N
		addiu t1,zero,0     #Cargo en a4 el flag 0

		sw 	a0, A0(sp)		#Preparo el stack para llamar a RC
		sw 	a1, A1(sp)		
		sw 	a2, A2(sp)	
		sw 	a3, A3(sp)
		sw 	t1, A4(sp)

		la t0, RC

		jal t0

		addu s0,s0,v0

		b fin
		


#	Funcion:
#	unsigned int RC (unsigned char *a, unsigned int ia, unsigned int j, unsigned int N, unsigned int flag)
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

RC:
		subu sp, sp, SF_SIZE		# creo stack frame
		sw $fp, FP(sp)		# guardo valor de fp
		sw gp, GP(sp)		# guardo valor de gp
		sw ra, RA(sp)		# guardo valor de ra
		sw	s0,	S0(sp)
		move $fp, sp

		move s0,zero 		#Uso s0 para el valor de retorno
		lw t0, 64(sp)		#Cargo el flag en t0 para hacer la verificacion

		beqz t0, flag_es_cero

continuacion_chequeo_flag:
		lw t0, 56(sp)		#Cargo j en t0

		beqz t0, j_es_cero

		lw t1, 60(sp)		#Cargo N en t1
		subu t1, t1, 1		#Resto 1 a t1

		beq t0, t1, j_N_menos_uno

							#Si no cumple ninguno de los casos

							#Preparo para verificarEstado(ia, j+1, N, a)
		lw a0, 52(sp)
		lw a1, 56(sp)
		addiu a1, a1, 1
		lw a2, 60(sp)
		lw a3, 48(sp)		

		la t0, verificarEstado

		jal t0

		addu s0, s0, v0

							#Preparo para verificarEstado(ia, j-1, N, a)
		lw a0, 52(sp)
		lw a1, 56(sp)
		subu a1, a1, 1
		lw a2, 60(sp)
		lw a3, 48(sp)

		la t0, verificarEstado

		jal t0

		addu s0, s0, v0

		b fin_RC

flag_es_cero:
							#Preparo para verificarEstado(ia, j, N, a)
		lw a0, 52(sp)
		lw a1, 56(sp)
		lw a2, 60(sp)
		lw a3, 48(sp)

		la t0, verificarEstado

		jal t0

		addu s0, s0, v0

		b continuacion_chequeo_flag

j_es_cero:
		
							#Preparo para verificarEstado(ia, j + 1, N, a)
		lw a0, 52(sp)
		lw a1, 56(sp)
		addiu a1, a1, 1
		lw a2, 60(sp)
		lw a3, 48(sp)

		la t0, verificarEstado

		jal t0

		addu s0, s0, v0

							#Preparo para verificarEstado(ia, N - 1, N, a)
		lw a0, 52(sp)
		lw a1, 60(sp)
		subu a1, a1, 1
		lw a2, 60(sp)
		lw a3, 48(sp)

		la t0, verificarEstado

		jal t0

		addu s0, s0, v0

		b fin_RC

j_N_menos_uno:

							#Preparo para verificarEstado(ia, 0, N, a)
		lw a0, 52(sp)
		move a1,zero
		lw a2, 60(sp)
		lw a3, 48(sp)

		la t0, verificarEstado

		jal t0

		addu s0, s0, v0

							#Preparo para verificarEstado(ia, j - 1, N, a)
		lw a0, 52(sp)
		lw a1, 56(sp)
		subu a1, a1, 1
		lw a2, 60(sp)
		lw a3, 48(sp)

		la t0, verificarEstado

		jal t0

		addu s0, s0, v0

		b fin_RC

fin_RC:
		move v0,s0		#Cargo en v0 el valor a retornar
						#Restauro el stack y termino la funcion vecinos

		lw $fp,FP(sp)
		lw gp,GP(sp)
		lw ra,RA(sp)
		lw s0,S0(sp)
		addu sp,sp,SF_SIZE

		jr ra


#	Funcion:
#	unsigned int verificarEstado(unsigned int ia, unsigned int ja,unsigned int N, unsigned char *a)

################
# Stack frame: #
################
# 16 ------------
#	PADDING
# 12 ------------
#	ra
# 8 ------------
#	fp
# 4 ------------
#	gp
# 0 ------------

verificarEstado:
		subu sp, sp, 16		# creo stack frame
		sw $fp, 4(sp)		# guardo valor de fp
		sw gp, 0(sp)		# guardo valor de gp
		sw ra, 8(sp)		# guardo valor de ra
		move $fp, sp

							#Calculo (ia*N) + ja
		mulou t0, a0, a2
		addu t0, t0, a1
		mulou t0, t0, 4
							#Traigo el valor a[(ia*N) + ja]
		addu t2, t0, a3
		lb t1, 0(t2)

		beq t1,1,valor_uno
		move t0, zero

fin_verificarEstado:
		move v0,t0

		lw $fp,4(sp)
		lw gp,0(sp)
		lw ra,8(sp)
		addu sp,sp,16

		jr ra

valor_uno:
		addiu t0,zero,1
		b fin_verificarEstado


