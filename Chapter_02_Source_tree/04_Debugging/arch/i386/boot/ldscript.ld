/*! Linker script for memory layout */

/* It's parsed as C before used in linking! */

ENTRY(arch_startup)

SECTIONS {
	.textrodata LOAD_ADDR :
	{
		kernel_code_addr = .; 
		*?/boot/startup.asm.o( .text* )
		*(.text*)
		*(.rodata*)

		. = ALIGN(4096);
	}
	.databss :
	{
		kernel_data_addr = .;  
		*(.data*)
		*(.bss*)
		*(COMMON)

		. = ALIGN(4096);
	}

	/*
	 * Handle other sections generated with gcc (various versions).
	 * For size optimization, discard them unless debugging:
	 * if optimizing for size discard them with: /DISCARD/ : { *(*) }
	 * if debugging with qemu/gdb they must be included.
	 */
#ifndef DEBUG
	/DISCARD/ : { *(*) }
#endif
	kernel_end_addr = .;  /* End of kernel */
}
