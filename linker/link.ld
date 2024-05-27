/*
 * link.ld
 *
 * This file defines the entry point
 * of our kernel and the placement of 
 * ASM sections
 */
OUTPUT_FORMAT(elf32-i386) 
ENTRY(start)
SECTIONS
{
	. = 0x100000;
	.text : {*(.text)}
	.data : {*(.data)}
	.bss  : {*(.bss)}
}
