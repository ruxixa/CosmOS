;
; kernel.asm
;	
; This file is the entry point for the kernel. 
; It sets up the stack and calling kernel
;
; Author: ruxixa
;

bits 32							; we are in 32 bit mode

section .text
	align 4						; align at 4 bytes
	dd 0x1BADB002				; magic number
	dd 0x00						; flags
	dd - (0x1BADB002 + 0x00)	; magic + flags checksum (should be zero)

global start					; make entry point visible to linker
extern main 					; main is defined in the kernel.c file

start:
	cli  						; disable interrupts
	call main					; call the kernel
	hlt 						; halt the CPU
