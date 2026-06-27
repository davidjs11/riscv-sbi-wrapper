/*   main.c   */

#include <sbi.h>
#include <sbi_base.h>
#include <sbi_legacy.h>

void putstring(const char *s) {
    while (*s) sbi_console_putchar(*s++);
}

int main(void)
{
    putstring("hello there!\n");

    unsigned char ch;
    do {
        ch = sbi_console_getchar();
        if ((ch | 0x20) >= 'a' && (ch | 0x20) <= 'z') sbi_console_putchar(ch);
    } while (ch != ' ');
    sbi_console_putchar('\n');

    sbi_shutdown();
    for (;;);
}
