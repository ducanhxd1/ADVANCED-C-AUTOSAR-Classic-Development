	.file	"Ex2.c"
	.text
	.globl	data
	.data
	.align 4
data:
	.long	23
	.align 4
static_global:
	.long	10
	.globl	str1
	.section .rdata,"dr"
.LC0:
	.ascii "this is str1\0"
	.data
	.align 8
str1:
	.quad	.LC0
	.globl	str2
	.section .rdata,"dr"
.LC1:
	.ascii "this is str2\0"
	.data
	.align 8
str2:
	.quad	.LC1
	.globl	str3
	.section .rdata,"dr"
	.align 8
str3:
	.ascii "this is str3\0"
	.globl	str4
	.data
	.align 8
str4:
	.ascii "this is str4\0"
	.section .rdata,"dr"
.LC2:
	.ascii "Test\0"
	.text
	.globl	test
	.def	test;	.scl	2;	.type	32;	.endef
	.seh_proc	test
test:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	puts
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	call	test
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.data
	.align 4
static_local.0:
	.long	5
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev2, Built by MSYS2 project) 14.2.0"
	.def	puts;	.scl	2;	.type	32;	.endef
