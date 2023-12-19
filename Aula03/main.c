#define uart_base 0x10000000

static void putc(char c)
{
  volatile char *reg = (char *)uart_base;
  *reg = c;
}

void puts(char *str)
{
  while (*str != 0)
  {
    putc(*str++);
    /* O mesmo que
    putc(*str);
    */
  }
}

void entry()
{
  puts("Hello World! <Disse o Kernel> \n");

}