/*   start.S   */

.section .text.boot
.global _start
_start:
    la sp, stack_top
    j main
