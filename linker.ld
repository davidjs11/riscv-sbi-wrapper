/*   linker.ld   */

ENTRY(_start);

PHDRS
{
    text   PT_LOAD FLAGS(0x5); /* r + x = 0x4 | 0x1 = 0x5 */
    rodata PT_LOAD FLAGS(0x4); /* r   = 0x4               */
    data   PT_LOAD FLAGS(0x6); /* r + w = 0x4 | 0x2 = 0x6 */
}

SECTIONS
{
    . = 0x80200000;

    .text : {
        *(.text.boot)
        *(.text)
        *(.text.*)
    } :text

    .rodata : {
        *(.rodata)
        *(.rodata.*)
    } :rodata

    .data : {
        *(.data)
        *(.data.*)
    } :data

    .bss (NOLOAD) : {
        *(.bss)
        *(.bss.*)
    } :data

    . = ALIGN(16);
    .stack (NOLOAD) : {
        . += 4K;
        stack_top = .;
    } :data
}
