CCFLAGS = -mcmodel=medany -ffreestanding -Iinclude/ -nostdlib -nostartfiles -fno-stack-protector -fno-pic -fno-pie

all:
	@riscv64-unknown-elf-gcc -g $(CCFLAGS) -c main.c
	@riscv64-unknown-elf-as -g start.S -o start.o
	@riscv64-unknown-elf-ld -T linker.ld start.o main.o -o main.elf

run:
	@qemu-system-riscv64 -machine virt -serial stdio -display none -kernel main.elf

debug:
	@qemu-system-riscv64 -machine virt -serial stdio -display none -kernel main.elf -s -S

.PHONY: clean
clean:
	@rm -rf *.o *.elf
