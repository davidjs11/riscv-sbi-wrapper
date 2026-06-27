CCFLAGS = -mcmodel=medany -ffreestanding -Iinclude/ -nostdlib -nostartfiles -fno-stack-protector -fno-pic -fno-pie -g -Wall
CC   = riscv64-unknown-elf-gcc
AS   = riscv64-unknown-elf-as
LD   = riscv64-unknown-elf-ld
OBJCOPY = riscv64-unknown-elf-objcopy
QEMU = qemu-system-riscv64

SRC  = ./src
INC  = ./include

C_SOURCE = $(wildcard $(SRC)/*.c)
S_SOURCE = $(wildcard $(SRC)/*.S)

C_OBJ = $(C_SOURCE:.c=.o)
S_OBJ = $(S_SOURCE:.S=.o)
OBJS  = $(C_OBJ) $(S_OBJ)

LINKER = linker.ld
TARGET = main.elf

.PHONY: all run debug clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@printf "LD - $^ -> "
	@$(LD) -T $(LINKER) $(OBJS) -o $(TARGET)
	@echo "$@"

$(SRC)/%.o: $(SRC)/%.c
	@printf "CC - $< -> "
	@$(CC) $(CCFLAGS) -c $< -o $@
	@echo "$@"

$(SRC)/%.o: $(SRC)/%.S
	@printf "AS - $< -> "
	@$(AS) -g $< -o $@
	@echo "$@"

run: $(TARGET)
	@$(QEMU) -machine virt -serial stdio -display none -kernel $(TARGET)

debug: $(TARGET)
	@$(QEMU) -machine virt -serial stdio -display none -kernel $(TARGET) -s -S &
	gdb-multiarch $(TARGET)

clean:
	@rm -rf $(SRC)/*.o $(TARGET)
