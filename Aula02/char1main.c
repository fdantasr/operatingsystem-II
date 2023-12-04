#include <stdio.h>

char secondChar(char *);
char anyChar(char *);

int main() {
    char *str = "yout shall not pass";
   printf("First char: %c\n", secondChar(str));
   printf("Any char: %c\n", anyChar(str));
    return 0;
}
