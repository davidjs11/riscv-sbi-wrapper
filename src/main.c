/*   main.c   */

#include <sbi.h>
#include <sbi_base.h>
#include <sbi_timer.h>
#include <sbi_rfence.h>
#include <sbi_hsm.h>
#include <sbi_ipi.h>
#include <sbi_reset.h>


// void putstring(const char *s) {
//     while (*s) sbi_console_putchar(*s++);
// }

int main(void)
{
    // putstring("hello there!\n");
    // unsigned char ch;
    // do {
    //     ch = sbi_console_getchar();
    //     if ((ch | 0x20) >= 'a' && (ch | 0x20) <= 'z') sbi_console_putchar(ch);
    // } while (ch != ' ');
    // sbi_console_putchar('\n');

    sbi_set_timer(10);
    sbi_remote_hfence_gvma(0, 0, 0, 0);

    // sbi_shutdown();
    for (;;);
}
