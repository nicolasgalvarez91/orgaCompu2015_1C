	.file	1 "Tp0.c"
	.section .mdebug.abi32
	.previous
	.abicalls
	.rdata
	.align	2
$LC0:
	.ascii	"Usage:\ttp0 -h \n"
	.ascii	"\ttp0 -V \n"
	.ascii	"\ttp0 [file...] \n"
	.ascii	"Options: \n"
	.ascii	" -V, --version \n"
	.ascii	"\t Print version and quit. \n"
	.ascii	" -h, --help \n"
	.ascii	"\t Print this information and quit.\n"
	.ascii	" Examples: \n"
	.ascii	"  tp0 foo.txt bar.txt \n"
	.ascii	"  tp0 gz.txt \n\000"
	.align	2
$LC1:
	.ascii	"%s\000"
	.text
	.align	2
	.globl	printHelp
	.ent	printHelp
printHelp:
	.frame	$fp,48,$ra		# vars= 8, regs= 3/0, args= 16, extra= 8
	.mask	0xd0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$t9
	.set	reorder
	subu	$sp,$sp,48
	.cprestore 16
	sw	$ra,40($sp)
	sw	$fp,36($sp)
	sw	$gp,32($sp)
	move	$fp,$sp
	la	$v0,$LC0
	sw	$v0,24($fp)
	la	$a0,$LC1
	lw	$a1,24($fp)
	la	$t9,printf
	jal	$ra,$t9
	move	$sp,$fp
	lw	$ra,40($sp)
	lw	$fp,36($sp)
	addu	$sp,$sp,48
	j	$ra
	.end	printHelp
	.size	printHelp, .-printHelp
	.rdata
	.align	2
$LC2:
	.ascii	"-h\000"
	.align	2
$LC3:
	.ascii	"--help\000"
	.align	2
$LC4:
	.ascii	"-V\000"
	.align	2
$LC5:
	.ascii	"--version\000"
	.align	2
$LC6:
	.ascii	"Version 1.0\n\000"
	.text
	.align	2
	.globl	checkArguments
	.ent	checkArguments
checkArguments:
	.frame	$fp,48,$ra		# vars= 8, regs= 3/0, args= 16, extra= 8
	.mask	0xd0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$t9
	.set	reorder
	subu	$sp,$sp,48
	.cprestore 16
	sw	$ra,40($sp)
	sw	$fp,36($sp)
	sw	$gp,32($sp)
	move	$fp,$sp
	sw	$a0,48($fp)
	sw	$a1,52($fp)
	li	$v0,1			# 0x1
	sw	$v0,24($fp)
	lw	$v1,48($fp)
	li	$v0,2			# 0x2
	bne	$v1,$v0,$L19
	lw	$v0,52($fp)
	addu	$v0,$v0,4
	lw	$a0,0($v0)
	la	$a1,$LC2
	la	$t9,strcmp
	jal	$ra,$t9
	beq	$v0,$zero,$L20
	lw	$v0,52($fp)
	addu	$v0,$v0,4
	lw	$a0,0($v0)
	la	$a1,$LC3
	la	$t9,strcmp
	jal	$ra,$t9
	bne	$v0,$zero,$L19
$L20:
	la	$t9,printHelp
	jal	$ra,$t9
	sw	$zero,24($fp)
	b	$L21
$L19:
	lw	$v1,48($fp)
	li	$v0,2			# 0x2
	bne	$v1,$v0,$L21
	lw	$v0,52($fp)
	addu	$v0,$v0,4
	lw	$a0,0($v0)
	la	$a1,$LC4
	la	$t9,strcmp
	jal	$ra,$t9
	beq	$v0,$zero,$L23
	lw	$v0,52($fp)
	addu	$v0,$v0,4
	lw	$a0,0($v0)
	la	$a1,$LC5
	la	$t9,strcmp
	jal	$ra,$t9
	bne	$v0,$zero,$L21
$L23:
	la	$a0,$LC6
	la	$t9,printf
	jal	$ra,$t9
	sw	$zero,24($fp)
$L21:
	lw	$v0,24($fp)
	move	$sp,$fp
	lw	$ra,40($sp)
	lw	$fp,36($sp)
	addu	$sp,$sp,48
	j	$ra
	.end	checkArguments
	.size	checkArguments, .-checkArguments
	.rdata
	.align	2
$LC7:
	.ascii	"Imposible abrir %s\n\000"
	.align	2
$LC8:
	.ascii	"Error al leer de Stdin\n\000"
	.text
	.align	2
	.globl	procesarArchivo
	.ent	procesarArchivo
procesarArchivo:
	.frame	$fp,80,$ra		# vars= 40, regs= 3/0, args= 16, extra= 8
	.mask	0xd0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$t9
	.set	reorder
	subu	$sp,$sp,80
	.cprestore 16
	sw	$ra,72($sp)
	sw	$fp,68($sp)
	sw	$gp,64($sp)
	move	$fp,$sp
	sw	$a0,80($fp)
	sw	$a1,84($fp)
	sw	$a2,88($fp)
	sw	$zero,28($fp)
	li	$v0,100			# 0x64
	sw	$v0,36($fp)
	lw	$v0,80($fp)
	bne	$v0,$zero,$L25
	lw	$v1,88($fp)
	li	$v0,-1			# 0xffffffffffffffff
	beq	$v1,$v0,$L26
	lw	$v0,88($fp)
	sll	$v1,$v0,2
	lw	$v0,84($fp)
	addu	$v0,$v1,$v0
	addu	$v0,$v0,4
	la	$a0,__sF+176
	la	$a1,$LC7
	lw	$a2,0($v0)
	la	$t9,fprintf
	jal	$ra,$t9
	b	$L27
$L26:
	la	$a0,__sF+176
	la	$a1,$LC8
	la	$t9,fprintf
	jal	$ra,$t9
$L27:
	li	$v0,1			# 0x1
	sw	$v0,56($fp)
	b	$L24
$L25:
	sw	$zero,44($fp)
	sw	$zero,48($fp)
	addu	$v0,$fp,32
	move	$a0,$v0
	li	$a1,1			# 0x1
	li	$a2,1			# 0x1
	lw	$a3,80($fp)
	la	$t9,fread
	jal	$ra,$t9
	sw	$v0,28($fp)
$L28:
	lw	$v0,28($fp)
	bgtz	$v0,$L30
	b	$L29
$L30:
	sw	$zero,24($fp)
	lw	$a0,36($fp)
	la	$t9,malloc
	jal	$ra,$t9
	sw	$v0,52($fp)
$L31:
	lw	$v0,28($fp)
	blez	$v0,$L32
	lb	$v1,32($fp)
	li	$v0,10			# 0xa
	bne	$v1,$v0,$L33
	b	$L32
$L33:
	lw	$v0,24($fp)
	lw	$v1,36($fp)
	slt	$v0,$v1,$v0
	beq	$v0,$zero,$L35
	lw	$v0,36($fp)
	addu	$v0,$v0,100
	sw	$v0,36($fp)
	lw	$a0,52($fp)
	lw	$a1,36($fp)
	la	$t9,realloc
	jal	$ra,$t9
	sw	$v0,52($fp)
$L35:
	lw	$v1,52($fp)
	lw	$v0,24($fp)
	addu	$v1,$v1,$v0
	lbu	$v0,32($fp)
	sb	$v0,0($v1)
	lw	$v0,24($fp)
	addu	$v0,$v0,1
	sw	$v0,24($fp)
	addu	$v0,$fp,32
	move	$a0,$v0
	li	$a1,1			# 0x1
	li	$a2,1			# 0x1
	lw	$a3,80($fp)
	la	$t9,fread
	jal	$ra,$t9
	sw	$v0,28($fp)
	b	$L31
$L32:
	lb	$v1,32($fp)
	li	$v0,10			# 0xa
	beq	$v1,$v0,$L37
	lw	$v0,28($fp)
	bne	$v0,$zero,$L36
$L37:
	lw	$v0,44($fp)
	bne	$v0,$zero,$L38
	li	$a0,4			# 0x4
	la	$t9,malloc
	jal	$ra,$t9
	sw	$v0,40($fp)
	b	$L39
$L38:
	lw	$v0,44($fp)
	sll	$v0,$v0,2
	addu	$v0,$v0,4
	lw	$a0,40($fp)
	move	$a1,$v0
	la	$t9,realloc
	jal	$ra,$t9
	sw	$v0,40($fp)
$L39:
	lw	$v1,52($fp)
	lw	$v0,24($fp)
	addu	$v0,$v1,$v0
	sb	$zero,0($v0)
	lw	$v0,44($fp)
	sll	$v1,$v0,2
	lw	$v0,40($fp)
	addu	$v1,$v1,$v0
	lw	$v0,52($fp)
	sw	$v0,0($v1)
	lw	$v0,44($fp)
	addu	$v0,$v0,1
	sw	$v0,44($fp)
	b	$L40
$L36:
	lb	$v1,32($fp)
	li	$v0,10			# 0xa
	beq	$v1,$v0,$L41
	lw	$v0,28($fp)
	bne	$v0,$zero,$L41
	li	$v0,1			# 0x1
	sw	$v0,48($fp)
	b	$L40
$L41:
	lw	$a0,52($fp)
	la	$t9,free
	jal	$ra,$t9
$L40:
	addu	$v0,$fp,32
	move	$a0,$v0
	li	$a1,1			# 0x1
	li	$a2,1			# 0x1
	lw	$a3,80($fp)
	la	$t9,fread
	jal	$ra,$t9
	sw	$v0,28($fp)
	b	$L28
$L29:
	lw	$a0,80($fp)
	la	$t9,fclose
	jal	$ra,$t9
	lw	$a0,40($fp)
	lw	$a1,44($fp)
	lw	$a2,48($fp)
	la	$t9,procesarSalidaArchivo
	jal	$ra,$t9
	sw	$zero,56($fp)
$L24:
	lw	$v0,56($fp)
	move	$sp,$fp
	lw	$ra,72($sp)
	lw	$fp,68($sp)
	addu	$sp,$sp,80
	j	$ra
	.end	procesarArchivo
	.size	procesarArchivo, .-procesarArchivo
	.rdata
	.align	2
$LC9:
	.ascii	"%s\n\000"
	.text
	.align	2
	.globl	procesarSalidaArchivo
	.ent	procesarSalidaArchivo
procesarSalidaArchivo:
	.frame	$fp,48,$ra		# vars= 8, regs= 3/0, args= 16, extra= 8
	.mask	0xd0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$t9
	.set	reorder
	subu	$sp,$sp,48
	.cprestore 16
	sw	$ra,40($sp)
	sw	$fp,36($sp)
	sw	$gp,32($sp)
	move	$fp,$sp
	sw	$a0,48($fp)
	sw	$a1,52($fp)
	sw	$a2,56($fp)
	lw	$v0,52($fp)
	addu	$v0,$v0,-1
	sw	$v0,24($fp)
$L44:
	lw	$v0,24($fp)
	bgez	$v0,$L47
	b	$L45
$L47:
	lw	$v0,24($fp)
	bne	$v0,$zero,$L48
	lw	$v0,56($fp)
	beq	$v0,$zero,$L48
	lw	$v0,24($fp)
	sll	$v1,$v0,2
	lw	$v0,48($fp)
	addu	$v0,$v1,$v0
	la	$a0,$LC1
	lw	$a1,0($v0)
	la	$t9,printf
	jal	$ra,$t9
	b	$L49
$L48:
	lw	$v0,24($fp)
	sll	$v1,$v0,2
	lw	$v0,48($fp)
	addu	$v0,$v1,$v0
	la	$a0,$LC9
	lw	$a1,0($v0)
	la	$t9,printf
	jal	$ra,$t9
$L49:
	lw	$v0,24($fp)
	sll	$v1,$v0,2
	lw	$v0,48($fp)
	addu	$v0,$v1,$v0
	lw	$a0,0($v0)
	la	$t9,free
	jal	$ra,$t9
	lw	$v0,24($fp)
	addu	$v0,$v0,-1
	sw	$v0,24($fp)
	b	$L44
$L45:
	lw	$v0,52($fp)
	beq	$v0,$zero,$L43
	lw	$a0,48($fp)
	la	$t9,free
	jal	$ra,$t9
$L43:
	move	$sp,$fp
	lw	$ra,40($sp)
	lw	$fp,36($sp)
	addu	$sp,$sp,48
	j	$ra
	.end	procesarSalidaArchivo
	.size	procesarSalidaArchivo, .-procesarSalidaArchivo
	.rdata
	.align	2
$LC10:
	.ascii	"r\000"
	.text
	.align	2
	.globl	manejoArchivos
	.ent	manejoArchivos
manejoArchivos:
	.frame	$fp,56,$ra		# vars= 16, regs= 3/0, args= 16, extra= 8
	.mask	0xd0000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$t9
	.set	reorder
	subu	$sp,$sp,56
	.cprestore 16
	sw	$ra,48($sp)
	sw	$fp,44($sp)
	sw	$gp,40($sp)
	move	$fp,$sp
	sw	$a0,56($fp)
	sw	$a1,60($fp)
	sw	$zero,24($fp)
	sw	$zero,32($fp)
	lw	$v1,56($fp)
	li	$v0,1			# 0x1
	bne	$v1,$v0,$L52
	la	$v0,__sF
	sw	$v0,24($fp)
	lw	$a0,24($fp)
	lw	$a1,60($fp)
	li	$a2,-1			# 0xffffffffffffffff
	la	$t9,procesarArchivo
	jal	$ra,$t9
	sw	$v0,32($fp)
	b	$L53
$L52:
	lw	$v0,56($fp)
	addu	$v0,$v0,-1
	sw	$v0,56($fp)
	sw	$zero,28($fp)
$L54:
	lw	$v0,28($fp)
	lw	$v1,56($fp)
	slt	$v0,$v0,$v1
	beq	$v0,$zero,$L53
	lw	$v0,32($fp)
	bne	$v0,$zero,$L53
	lw	$v0,28($fp)
	sll	$v1,$v0,2
	lw	$v0,60($fp)
	addu	$v0,$v1,$v0
	addu	$v0,$v0,4
	lw	$a0,0($v0)
	la	$a1,$LC10
	la	$t9,fopen
	jal	$ra,$t9
	sw	$v0,24($fp)
	lw	$a0,24($fp)
	lw	$a1,60($fp)
	lw	$a2,28($fp)
	la	$t9,procesarArchivo
	jal	$ra,$t9
	sw	$v0,32($fp)
	lw	$v0,28($fp)
	addu	$v0,$v0,1
	sw	$v0,28($fp)
	b	$L54
$L53:
	lw	$v0,32($fp)
	move	$sp,$fp
	lw	$ra,48($sp)
	lw	$fp,44($sp)
	addu	$sp,$sp,56
	j	$ra
	.end	manejoArchivos
	.size	manejoArchivos, .-manejoArchivos
	.ident	"GCC: (GNU) 3.3.3 (NetBSD nb3 20040520)"
