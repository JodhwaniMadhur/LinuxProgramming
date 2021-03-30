	.file	"gc.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"I am the orignal process and my PPID=>%d and my PID=>%d\n"
	.align 8
.LC1:
	.string	"I am parent process with PPID=>%d and my PID=>%d\n"
.LC2:
	.string	"My child's PID=> %d\n"
	.align 8
.LC3:
	.string	" I am the child process with PPID=>%d and my PID=>%d\n"
.LC4:
	.string	"pid %d terminates\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movl	$11, -24(%rbp)
	call	fork@PLT
	movl	%eax, -20(%rbp)
	movl	$0, %eax
	call	getpid@PLT
	movl	%eax, %ebx
	movl	$0, %eax
	call	getppid@PLT
	movl	%ebx, %edx
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	cmpl	$0, -20(%rbp)
	je	.L2
	movl	$0, %eax
	call	getpid@PLT
	movl	%eax, %ebx
	movl	$0, %eax
	call	getppid@PLT
	movl	%ebx, %edx
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-20(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L3
.L2:
	movl	$0, %eax
	call	getpid@PLT
	movl	%eax, %ebx
	movl	$0, %eax
	call	getppid@PLT
	movl	%ebx, %edx
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L3:
	movl	$0, %eax
	call	getpid@PLT
	movl	%eax, %esi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-10ubuntu2) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
