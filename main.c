/*   main.c   */

#include <sbi.h>
#include <sbi_base.h>
#include <sbi_legacy.h>

void putstring(unsigned char *s) {
    while (*s) sbi_console_putchar(*s++);
}

int main(void)
{
    uint32_t x, y;
    struct sbiret ret;

    putstring("hello there!\n");

    // unsigned char ch;
    // do {
    //     ch = sbi_console_getchar();
    //     if (ch >= 'a' && ch <= 'z') sbi_console_putchar(ch);
    //     if (ch >= 'A' && ch <= 'Z') sbi_console_putchar(ch);
    // } while (ch != ' ');

    sbi_shutdown();

    for (;;);
}
