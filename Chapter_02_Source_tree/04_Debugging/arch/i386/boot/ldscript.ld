/*! linker script for memory layout */

/* Its parsed as C before used in linking! */

ENTRY(arch_startup)

SECTIONS {
	.code 0x0 :
	{
		kernel_code_addr = .;
		
		/* instructions */
		*?/boot/startup.asm.o ( .text* )
		*?/boot/premjesti.o ( .text* )
	}
	
	.instrukcije 0x200000 : AT(0x10000)
	{
		*( .text* ) 
		instrukcije_end = .;
	}
	size_i = SIZEOF(.instrukcije);
	xxxx = 0x10000;
	
	.rodata (instrukcije_end): AT(0x50000)
	{
		/* read only data (constants), initialized global variables */
 		* ( .rodata*)
 		. = ALIGN(4);
 		rodata_end = .;
	}
	size_rodata = SIZEOF(.rodata);
	
	.data (rodata_end): AT(0x50000 + SIZEOF(.rodata))
	{
    		* ( .data*)
    		. = ALIGN(4);
    		data_end = .;
	}
	size_data = SIZEOF(.data);
	
	.bss (data_end): AT(0x80000)
	{
		*( .bss* COMMON* )
		
		. = ALIGN (4096);
	}
	.= 0x800000 - STACK_SIZE;
	stog_start = .;
	.stog_u_slici (stog_start): AT(0x90000)
	{
		*( .stog )
		. = ALIGN (4096);
	}
#ifndef DEBUG
    /DISCARD/ : { *(.eh_frame) *(*) }
#else
    /DISCARD/ : { *(.eh_frame) }
#endif
    kernel_end_addr = .;
	
}
