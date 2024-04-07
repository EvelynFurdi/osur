#include <types/basic.h>

void premjesti()
{
	extern char size_data;
	extern size_t size_i;
	size_t size_d = (size_t) &size_i;
	size_t i;
	char *od = (char *) 0x100000;
	char *kamo = (char *) 0x200000;
	
	for ( i = 0; i< size_d; i++ )
		*kamo++ = *od++;

	
	size_d = (size_t) &size_data;

	for ( i = 0; i< size_d; i++ )
		*kamo++ = *od++;
}