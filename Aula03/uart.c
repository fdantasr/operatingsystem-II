#include "memlayout.h"
#include "types.h"

// REGISTRADOR UART
#define RBR 0 // Receiver Buffer Register
#define THR 0 // Transmitter Holding Register
#define IER 1 // Interrupt Enable Register
#define IIR 2 // Interrupt Identification Register
#define LCR 3 // Line Control Register
#define LSR 5 // Line Status Register

char read_reg(uint8 reg)
{
  char c;
  volatile char *base = (char *)UART_BASE;
  c = *(base + reg);
  return c;
}

void 
auart_init(){
  //Habilita Fifo
  whire_reg(FRC, 1); // 0x80 = 1000 0000
  whire_reg(LCR, 3); // 0x80 = 1000 0000
  whire_reg(IER, 1); // 0x80 = 1000 0000
}

int 
uart_getc(){
  char c;
  while((read_reg(LSR) & 1) == 0){
  return -1;
  }
  c = read_reg(RBR);
  return c;

}
// imprime caractere
void uart_putc(char c) {
    // livre para escrever?
    while((read_reg(LSR) & (1 << 5)) == 0)
    ;
    write_reg(THR, c);
}
 
