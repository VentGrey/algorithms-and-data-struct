	.file	"fract.c"
	.text
	.section	.rodata
.LC3:
	.string	"w"
.LC4:
	.string	"mandelbrot-fractal.pgm"
.LC5:
	.string	"P2 \n"
.LC6:
	.string	"%d %d \n"
.LC7:
	.string	"1 \n"
.LC8:
	.string	"%d "
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$168, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	movl	%edi, -180(%rbp)
	movq	%rsi, -192(%rbp)
	movq	%rsp, %rsi
	movq	%rsi, %r13
	movl	$50, -68(%rbp)
	movl	$50, -72(%rbp)
	movl	$50, -76(%rbp)
	movl	-68(%rbp), %esi
	movslq	%esi, %rsi
	subq	$1, %rsi
	movq	%rsi, -88(%rbp)
	movl	-68(%rbp), %esi
	movslq	%esi, %rsi
	movq	%rsi, %r14
	movl	$0, %r15d
	movl	-68(%rbp), %esi
	movslq	%esi, %rsi
	leaq	0(,%rsi,4), %r12
	movl	-72(%rbp), %esi
	movslq	%esi, %rsi
	subq	$1, %rsi
	movq	%rsi, -96(%rbp)
	movl	-68(%rbp), %esi
	movslq	%esi, %rsi
	movq	%rsi, %r10
	movl	$0, %r11d
	movl	-72(%rbp), %esi
	movslq	%esi, %rsi
	movq	%rsi, %rax
	movl	$0, %edx
	movq	%r11, %rdi
	imulq	%rax, %rdi
	movq	%rdx, %rsi
	imulq	%r10, %rsi
	addq	%rdi, %rsi
	mulq	%r10
	addq	%rdx, %rsi
	movq	%rsi, %rdx
	movl	-68(%rbp), %eax
	cltq
	movq	%rax, %r8
	movl	$0, %r9d
	movl	-72(%rbp), %eax
	cltq
	movq	%rax, %rcx
	movl	$0, %ebx
	movq	%r9, %rdx
	imulq	%rcx, %rdx
	movq	%rbx, %rax
	imulq	%r8, %rax
	leaq	(%rdx,%rax), %rsi
	movq	%r8, %rax
	mulq	%rcx
	leaq	(%rsi,%rdx), %rcx
	movq	%rcx, %rdx
	movl	-68(%rbp), %eax
	movslq	%eax, %rdx
	movl	-72(%rbp), %eax
	cltq
	imulq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ebx
	movl	$0, %edx
	divq	%rbx
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -104(%rbp)
	movsd	.LC0(%rip), %xmm0
	movsd	%xmm0, -112(%rbp)
	movsd	.LC1(%rip), %xmm0
	movsd	%xmm0, -120(%rbp)
	movsd	.LC0(%rip), %xmm0
	movsd	%xmm0, -128(%rbp)
	movsd	.LC1(%rip), %xmm0
	movsd	%xmm0, -136(%rbp)
	movsd	-112(%rbp), %xmm0
	subsd	-120(%rbp), %xmm0
	cvtsi2sd	-68(%rbp), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -144(%rbp)
	movsd	-128(%rbp), %xmm0
	subsd	-136(%rbp), %xmm0
	cvtsi2sd	-72(%rbp), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -152(%rbp)
	movl	$0, -64(%rbp)
	jmp	.L2
.L5:
	movl	$0, -60(%rbp)
	jmp	.L3
.L4:
	cvtsi2sd	-64(%rbp), %xmm0
	movapd	%xmm0, %xmm1
	mulsd	-152(%rbp), %xmm1
	movsd	-128(%rbp), %xmm0
	subsd	%xmm1, %xmm0
	cvtsi2sd	-60(%rbp), %xmm1
	mulsd	-144(%rbp), %xmm1
	movapd	%xmm1, %xmm2
	addsd	-120(%rbp), %xmm2
	pxor	%xmm1, %xmm1
	mulsd	%xmm0, %xmm1
	addsd	%xmm2, %xmm1
	movsd	%xmm1, -168(%rbp)
	movsd	%xmm0, -160(%rbp)
	movsd	-168(%rbp), %xmm2
	movsd	-160(%rbp), %xmm3
	movsd	-168(%rbp), %xmm0
	movsd	-160(%rbp), %xmm1
	movl	-76(%rbp), %eax
	movl	%eax, %edi
	call	mandelbrot
	movq	%xmm0, %rax
	movq	%rax, -200(%rbp)
	movsd	-200(%rbp), %xmm0
	movq	%r12, %rdi
	shrq	$2, %rdi
	cvttsd2si	%xmm0, %edx
	movq	-104(%rbp), %rax
	movl	-60(%rbp), %ecx
	movslq	%ecx, %rsi
	movl	-64(%rbp), %ecx
	movslq	%ecx, %rcx
	imulq	%rdi, %rcx
	addq	%rsi, %rcx
	movl	%edx, (%rax,%rcx,4)
	addl	$1, -60(%rbp)
.L3:
	movl	-60(%rbp), %eax
	cmpl	-68(%rbp), %eax
	jl	.L4
	addl	$1, -64(%rbp)
.L2:
	movl	-64(%rbp), %eax
	cmpl	-72(%rbp), %eax
	jl	.L5
	leaq	.LC3(%rip), %rsi
	leaq	.LC4(%rip), %rdi
	call	fopen@PLT
	movq	%rax, -176(%rbp)
	movq	-176(%rbp), %rax
	movq	%rax, %rcx
	movl	$4, %edx
	movl	$1, %esi
	leaq	.LC5(%rip), %rdi
	call	fwrite@PLT
	movl	-72(%rbp), %ecx
	movl	-68(%rbp), %edx
	movq	-176(%rbp), %rax
	leaq	.LC6(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movq	-176(%rbp), %rax
	movq	%rax, %rcx
	movl	$3, %edx
	movl	$1, %esi
	leaq	.LC7(%rip), %rdi
	call	fwrite@PLT
	movl	$0, -56(%rbp)
	jmp	.L6
.L9:
	movl	$0, -52(%rbp)
	jmp	.L7
.L8:
	movq	%r12, %rsi
	shrq	$2, %rsi
	movq	-104(%rbp), %rax
	movl	-52(%rbp), %edx
	movslq	%edx, %rcx
	movl	-56(%rbp), %edx
	movslq	%edx, %rdx
	imulq	%rsi, %rdx
	addq	%rcx, %rdx
	movl	(%rax,%rdx,4), %edx
	movq	-176(%rbp), %rax
	leaq	.LC8(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	addl	$1, -52(%rbp)
.L7:
	movl	-52(%rbp), %eax
	cmpl	-72(%rbp), %eax
	jl	.L8
	movq	-176(%rbp), %rax
	movq	%rax, %rsi
	movl	$10, %edi
	call	fputc@PLT
	addl	$1, -56(%rbp)
.L6:
	movl	-56(%rbp), %eax
	cmpl	-68(%rbp), %eax
	jl	.L9
	movl	$0, %eax
	movq	%r13, %rsp
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC9:
	.long	0
	.long	1073741824
	.long	0
	.long	0
	.text
	.globl	mandelbrot
	.type	mandelbrot, @function
mandelbrot:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movl	%edi, -36(%rbp)
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -80(%rbp)
	movsd	-80(%rbp), %xmm1
	movsd	%xmm1, -56(%rbp)
	movsd	%xmm0, -48(%rbp)
	movapd	%xmm2, %xmm1
	movapd	%xmm3, %xmm0
	movsd	%xmm1, -72(%rbp)
	movsd	%xmm0, -64(%rbp)
	movsd	-56(%rbp), %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-48(%rbp), %xmm0
	movsd	%xmm0, -16(%rbp)
	movsd	-72(%rbp), %xmm0
	movsd	%xmm0, -24(%rbp)
	movsd	-64(%rbp), %xmm0
	movsd	%xmm0, -32(%rbp)
	cmpl	$0, -36(%rbp)
	jle	.L12
	movsd	.LC9(%rip), %xmm2
	movsd	8+.LC9(%rip), %xmm3
	movsd	-56(%rbp), %xmm0
	movsd	-48(%rbp), %xmm1
	call	cpow@PLT
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -80(%rbp)
	movsd	-80(%rbp), %xmm1
	addsd	-24(%rbp), %xmm1
	addsd	-32(%rbp), %xmm0
	movapd	%xmm1, %xmm3
	movapd	%xmm0, %xmm2
	movl	-36(%rbp), %eax
	subl	$1, %eax
	movsd	-72(%rbp), %xmm1
	movsd	-64(%rbp), %xmm0
	movapd	%xmm3, %xmm4
	movapd	%xmm2, %xmm5
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm3
	movapd	%xmm4, %xmm0
	movapd	%xmm5, %xmm1
	movl	%eax, %edi
	call	mandelbrot
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -80(%rbp)
	movsd	-80(%rbp), %xmm1
	jmp	.L13
.L12:
	movsd	-56(%rbp), %xmm0
	movsd	-48(%rbp), %xmm1
	call	cabs@PLT
	comisd	.LC0(%rip), %xmm0
	jbe	.L17
	pxor	%xmm1, %xmm1
	pxor	%xmm0, %xmm0
	jmp	.L13
.L17:
	movsd	.LC10(%rip), %xmm1
	pxor	%xmm0, %xmm0
.L13:
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movapd	%xmm2, %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	mandelbrot, .-mandelbrot
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1073741824
	.align 8
.LC1:
	.long	0
	.long	-1073741824
	.align 8
.LC10:
	.long	0
	.long	1072693248
	.ident	"GCC: (Debian 8.2.0-20) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
