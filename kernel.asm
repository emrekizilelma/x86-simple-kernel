;; kernel.asm
;; version 0.0.1

bits 32		;nasm directive
section .text
	
	align 4
	dd 0x1BADB002			
	dd 0x00				
	dd - (0x1BADB002 + 0x00)	

global start
extern kernel_main

start:
	cli  ; stop interrupts

	call kernel_main

	hlt ; halt the CPU
