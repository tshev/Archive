	.file	"app.cc"
	.text
	.globl	_Z1fi
	.type	_Z1fi, @function
_Z1fi:
.LFB971:
	.cfi_startproc
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	%edi, %esi
	movl	$_ZSt4cout, %edi
	call	_ZNSolsEi
	popq	%rdx
	.cfi_def_cfa_offset 8
	movq	%rax, %rdi
	jmp	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.cfi_endproc
.LFE971:
	.size	_Z1fi, .-_Z1fi
	.section	.text.startup,"ax",@progbits
	.globl	main
	.type	main, @function
main:
.LFB972:
	.cfi_startproc
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$10, %edi
	call	_Z1fi
	xorl	%eax, %eax
	popq	%rdx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE972:
	.size	main, .-main
	.type	_GLOBAL__sub_I__Z1fi, @function
_GLOBAL__sub_I__Z1fi:
.LFB979:
	.cfi_startproc
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	popq	%rcx
	.cfi_def_cfa_offset 8
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	jmp	__cxa_atexit
	.cfi_endproc
.LFE979:
	.size	_GLOBAL__sub_I__Z1fi, .-_GLOBAL__sub_I__Z1fi
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z1fi
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 4.8.3 20140624 (Red Hat 4.8.3-1)"
	.section	.note.GNU-stack,"",@progbits
