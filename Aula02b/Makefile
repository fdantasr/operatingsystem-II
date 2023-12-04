CC = riscv64-linux-gnu-gcc
LD = riscv64-linux-gnu-ld
CFLAGS = -nostartfiles -nostdlib
LDFLAGS = -static

all: run

olamundo.x: olamundo.s
	$(CC) $(CFLAGS) $< -o $@

run: olamundo.x
	qemu-riscv64-static $<

clean:
	rm -f olamundo.x
