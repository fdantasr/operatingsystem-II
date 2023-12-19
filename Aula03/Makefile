PRE = riscv64-linux-gnu-
CC = $(PRE)gcc
LD = $(PRE)ld # Linker
QUEMU = qemu-system-riscv64

CFLAGS = -ffreestanding # COMPILAÇÃO SEM SUPORTE DO SISTEMA OPERACIONAL
CFLAGS += -march=rv64g -mabi=lp64 # Arquitetura RISCV
CFLAGS += -Wall # Queremos todos os warnings!
CFLAGS += -c -g -O0 # compilação sem otimização e com debug

LDFLAGS = -nostdlib # não usar bibliotecas padrão
LDFLAGS += -Ttext=0x80000000 # endereço do início do programa

OBJ = \
	boot.o \
	main.o \
	uart.o

	kernel: $(OBJ)
	$(LD) $(LDFLAGS) -o kernel $(OBJ)

kernel: boot.o main.o
	$(LD) $(LDFLAGS) -o kernel boot.o main.o

boot.o: boot.s
	$(CC) $(CFLAGS) boot.s

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm -f *.o kernel 

run:
	$(QUEMU) -append 'console=ttyS0'  -nographic -serial mon:stdio -smp 4 -machine virt -bios none -kernel kernel