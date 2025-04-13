AS = nasm
AS_FLAGS = -f elf32
CC = gcc
CFLAGS = -m32 -c
LD = ld -m elf_i386 -T link.ld -o kernel kasm.o kc.o
QEMU = qemu-system-i386 -kernel kernel

asm:
	$(AS) $(AS_FLAGS) kernel.asm -o kasm.o
cc:
		
	$(CC) $(CFLAGS) kernel.c -o kc.o
link:
	$(LD)

qemu:
	$(QEMU)

clean:
	rm -rf kc.o kasm.o kernel